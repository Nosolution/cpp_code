#pragma once
#include "Task.h"
class DataAnalyzer :
	public Task
{
public:
	DataAnalyzer(int id, string name, string type, int priority, int arrive_time, int execute_time);
	virtual void execute();

};

