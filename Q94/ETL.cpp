#include "ETL.h"



ETL::ETL(int id, string name, string type, int priority, int arrive_time, int execute_time)
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

void ETL::execute()
{
	cout << "task " << _id << " --- Read data from a file" << endl;
	cout << "task " << _id << " ---	Data transform" << endl;
	cout << "task " << _id << " ---	Load data into the database" << endl;
}


