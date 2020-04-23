#pragma once
#include "Element.h"
#include <vector>
using std::vector;

class CompositeElement :
	public Element
{
protected:
	vector<Element*> _children;
public:
	CompositeElement(string tagId, string tag, string tagName, string tagClass, string tagValue, string tagContent);
	virtual Element* find(const string&);
	virtual void addElement(Element*);
	virtual void output(ostream&);
};

