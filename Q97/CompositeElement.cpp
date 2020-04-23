#include "CompositeElement.h"
#include <iostream>

using std::cout;
using std::endl;


CompositeElement::CompositeElement(string tagId, string tag, string tagName, string tagClass, string tagValue, string tagContent)
{
	_id = tagId;
	_tag = tag;
	_name = tagName;
	_class = tagClass;
	_value = tagValue;
	_content = tagContent;
	_children.clear();
}


Element* CompositeElement::find(const string& id)
{
	if (id.compare(_id) != 0)
	{
		auto itr = _children.begin();
		Element* res;
		while (itr != _children.end())
		{
			res = (*itr)->find(id);
			if (res != nullptr)
				return res;
			else
				itr++;
		}
		return nullptr;
	}
	else
		return this;

}

void CompositeElement::addElement(Element* element)
{
	_children.push_back(element);
}

void CompositeElement::output(ostream& out)
{
	out << "<" << _tag << " id=" << _id;
	if (_name.compare(ENULL) != 0)
		out << " name=" << _name;
	if (_class.compare(ENULL) != 0)
		out << " class=" << _class;
	if (_value.compare(ENULL) != 0)
		out << " value=" << _value;
	out << ">";
	out << "</" << _tag << ">" << endl;
	auto itr = _children.begin();
	while (itr != _children.end())
	{
		(*itr)->output(out);
		itr++;
	}
}
