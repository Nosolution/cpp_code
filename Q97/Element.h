#pragma once
#include <string>
#include <iostream>

using std::string;
using std::ostream;


const string ENULL = "NULL";

class Element
{
protected:
	string _id;
	string _name;
	string _class;
	string _value;
	string _content;
	string _tag;

public:
	virtual Element* find(const string&) = 0;
	virtual void addElement(Element*) = 0;
	virtual void output(ostream&) = 0;
};

