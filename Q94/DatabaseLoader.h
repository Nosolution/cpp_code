#pragma once
#include "Task.h"
class DatabaseLoader :
	public Task
{
public:
	DatabaseLoader(int id, string name, string type, int priority, int arrive_time, int execute_time);
	virtual void execute();
};

