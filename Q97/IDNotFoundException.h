#pragma once
#include <string>

using std::string;
class IDNotFoundException
{
	string _id;
public:
	IDNotFoundException(string);
	string report();
};

