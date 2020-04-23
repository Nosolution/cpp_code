#pragma once
#include "Element.h"
#include "IDNotFoundException.h"
#include "AddTagToCommonException.h"

class BaseElement :
	public Element
{
public:
	BaseElement(string tagId, string tag, string tagName, string tagClass, string tagValue, string tagContent);
	virtual Element* find(const string&);
	virtual void addElement(Element*);
	virtual void output(ostream&);
};

