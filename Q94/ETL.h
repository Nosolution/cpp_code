#pragma once
#include "Task.h"
class ETL :
	public Task
{
public:
	ETL(int id, string name, string type, int priority, int arrive_time, int execute_time);
	virtual void execute();
};

