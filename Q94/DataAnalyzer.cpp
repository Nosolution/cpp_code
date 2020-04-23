#include "DataAnalyzer.h"



DataAnalyzer::DataAnalyzer(int id, string name, string type, int priority, int arrive_time, int execute_time)
{
	_id = id;
	_name = name;
	_type = type;
	_priority = priority;
	_arrive_time = arrive_time;
	_execute_time = execute_time;
	_rest_time = _execute_time;
	_start_time = 0;
	_core_id = 0;
}

void DataAnalyzer::execute()
{
	cout << "task " << _id << "execute: time" << _start_time << "coreId" << _core_id << endl;
	cout << "task " << _id << " --- Finding the center point" << endl;
	cout << "task " << _id << " ---	Data Classification" << endl;
	cout << "task " << _id << " ---	Data comparison" << endl;
	cout << "task " << _id << " ---	Data Display" << endl;

}


