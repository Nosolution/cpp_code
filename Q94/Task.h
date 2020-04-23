#pragma once
#include <string>
#include <iostream>

using std::cout;
using std::endl;
using std::string;
using std::to_string;

class Task {
protected:
	int _id;
	string _name;
	string _type;
	int _priority;
	int _start_time;
	int _execute_time;
	int _rest_time;
	int _arrive_time;
	int _core_id;
protected:
	virtual void execute() = 0;
public:
	virtual void load(int time, int core_id)
	{
		_start_time = time;
		_core_id = core_id;
		cout << "task " << _id << " load: time " << time << " coreId " << core_id << " name " << _name << " type " << _type << " priority " << _priority << endl;
		execute();
	}
	virtual void tick()
	{
		if (_rest_time > 0)
			_rest_time--;
		
	}

	virtual bool finishable()
	{
		return _rest_time == 0;
	}
	virtual void finish()
	{
		if (_rest_time == 0)
			cout << "task " + to_string(_id) + " finish: time " + to_string(_start_time) + " coreId " + to_string(_core_id) << endl;
	}
	int get_id()
	{
		return _id;
	}
	int get_arrive_time()
	{
		return _arrive_time;
	}
	int get_execute_time()
	{
		return _execute_time;
	}
	int get_priority()
	{
		return _priority;
	}
	int is_ready(int time)
	{
		return _arrive_time <= time;
	}
};
