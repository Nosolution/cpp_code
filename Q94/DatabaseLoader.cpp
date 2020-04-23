#include "DatabaseLoader.h"

DatabaseLoader::DatabaseLoader(int id, string name, string type, int priority, int arrive_time, int execute_time)
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

void DatabaseLoader::execute()
{
	cout << "task " << _id << " --- Load driver" << endl;
	cout << "task " << _id << " ---	Establish a database connection" << endl;
	cout << "task " << _id << " ---	Create a Statement object" << endl;
	cout << "task " << _id << " ---	Execute SQL" << endl;
	cout << "task " << _id << " ---	Close the database" << endl;
}



