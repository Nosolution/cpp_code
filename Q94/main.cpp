#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include "Task.h"
#include "DatabaseLoader.h"
#include "ETL.h"
#include "DataAnalyzer.h"

using namespace std;

Task* produce(int id, string name, int type, int priority, int arrive_time, int execute_time);
void split(const string& line, const string token, vector<string>& words);
void schedule(vector<Task*>& cores, vector<Task*>& waiting_list, void(*sort_func)(vector<Task*>& tasks, int time));
void psa_sort(vector<Task*>& tasks, int time);
void hrrf_sort(vector<Task*>& tasks, int time);
double resp_ratio(Task* task, int time);
bool compare_id(Task* t1, Task* t2);

int main()
{
	string line;
	getline(cin, line);
	vector<string> words;
	split(line, " ", words);
	int n = stoi(words[0]);
	string algo = words[1];
	int m = stoi(words[2]);

	vector<Task*> cores;
	for (int i = 0; i < n; i++)
		cores.push_back(nullptr);
	vector<Task*> waiting_list;
	for (int i = 0; i < m; i++)
	{
		getline(cin, line);
		split(line, " ", words);
		waiting_list.push_back(produce(stoi(words[0]), words[1], stoi(words[2]), stoi(words[3]), stoi(words[4]), stoi(words[5])));
	}
	void(*sort_func)(vector<Task*>& tasks, int time) = words[1] == "PSA" ? psa_sort : hrrf_sort;

	schedule(cores, waiting_list, sort_func);
	//system("pause");
	return 0;

}

void schedule(vector<Task*>& cores, vector<Task*>& waiting_list, void(*sort_func)(vector<Task*>& tasks, int time))
{
	int task_cnt = waiting_list.size();
	int time = 0;
	int spare_cnt = cores.size();
	vector<Task*> to_start;
	while (!((waiting_list.size() == 0) && (spare_cnt == cores.size())))
	{
		for (int i = 0; i < cores.size(); i++)
		{
			if (cores[i] == nullptr)
				continue;
			if (cores[i]->finishable())
			{
				cores[i]->finish();
				delete cores[i];
				cores[i] = nullptr;
				spare_cnt++;
			}
		}

		if (waiting_list.size() != 0 && spare_cnt > 0)
		{
			to_start.clear();
			sort_func(waiting_list, time);
			int task_idx = 0;

			for (int i = 0; i < spare_cnt; i++)
			{
				for (int j = task_idx; j < waiting_list.size(); j++)
				{
					if (waiting_list[j]->is_ready(time))
					{
						to_start.push_back(waiting_list[i]);
						waiting_list[j] = nullptr;
					}
				}
			}

			std::sort(to_start.begin(), to_start.end(), compare_id);
			int to_start_idx = 0;
			for (int i = 0; i < cores.size() && to_start_idx < to_start.size(); i++)
			{
				if (cores[i] == nullptr)
				{
					cores[i] = to_start[to_start_idx++];
					spare_cnt--;
					cores[i]->load(time, i);
				}
			}
		
		}
		for (int i = 0; i < cores.size(); i++)
		{
			if (cores[i] != nullptr)
				cores[i]->tick();
		}
		time++;
	}
}

bool compare_id(Task* t1, Task* t2)
{
	return t1->get_id() < t2->get_id();
}

void psa_sort(vector<Task*>& tasks, int time)
{
	auto it = remove_if(tasks.begin(), tasks.end(), [](Task* task) {return task == nullptr; });
	sort(tasks.begin(), it, [](Task* t1, Task*t2)
	{
		return t1->get_priority() < t2->get_priority() ||
			((t1->get_priority() == t2->get_priority()) && compare_id(t1,t2));
	});
	while (tasks.size() > 0 && (*(tasks.end() - 1) == nullptr))
		tasks.pop_back();
}

void hrrf_sort(vector<Task*>& tasks, int time)
{
	auto it = remove_if(tasks.begin(), tasks.end(), [](Task* task) {return task == nullptr; });
	sort(tasks.begin(), it, [time](Task* t1, Task*t2)
	{
		return resp_ratio(t1, time) > resp_ratio(t1, time) ||
			((resp_ratio(t1, time) == resp_ratio(t1, time)) && compare_id(t1, t2));
	});
	while (tasks.size() > 0 && (*(tasks.end() -1) == nullptr))
		tasks.pop_back();
}

double resp_ratio(Task* task, int time)
{
	return ((double)time - task->get_arrive_time()) / task->get_execute_time() + 1;
}


Task* produce(int id, string name, int type, int priority, int arrive_time, int execute_time)
{
	switch (type)
	{
	case 0:
		return new DatabaseLoader(id, name, "LoadDatabase", priority, arrive_time, execute_time);
		break;
	case 1:
		return new ETL(id, name, "ETL", priority, arrive_time, execute_time);
		break;
	case 2:
		return new DataAnalyzer(id, name, "DataAnalyzer", priority, arrive_time, execute_time);
		break;
	default:
		return 0;
		break;
	}
}

void split(const string& line, const string token, vector<string>& words)
{
	words.clear();

	size_t cur, prev = 0;
	cur = line.find(token, prev);
	while (cur != string::npos)
	{
		if (cur > prev)
		{
			words.push_back(line.substr(prev, cur - prev));
		}
		prev = cur + 1;
		if (prev == line.length())
			break;
		cur = line.find(token, prev);
	}

	if (prev != line.length())
	{
		words.push_back(line.substr(prev, line.length() - prev));
	}

}