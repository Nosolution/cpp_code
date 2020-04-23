#pragma once
#include <string>
#include <iostream>
using std::string;

class AddTagToCommonException
{
	string _id;
public:
	AddTagToCommonException(string);
	string report();
};

