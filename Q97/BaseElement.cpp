#include "BaseElement.h"
#include <iostream>

using std::cout;
using std::endl;
using std::ostream;


BaseElement::BaseElement(string tagId, string tag, string tagName, string tagClass, string tagValue, string tagContent)
{
	_id = tagId;
	_tag = tag;
	_name = tagName;
	_class = tagClass;
	_value = tagValue;
	_content = tagContent;
}


Element* BaseElement::find(const string& id)
{
	if (id.compare(_id) != 0)
		return nullptr;
	else
		return this;
}

void BaseElement::addElement(Element*  element)
{
	throw AddTagToCommonException(_id);
}

void BaseElement::output(ostream& out)
{
	out << "<" << _tag << " id=" << _id;
	if (_name.compare(ENULL) != 0)
		out << " name=" << _name;
	if (_class.compare(ENULL) != 0)
		out << " class=" << _class;
	if (_value.compare(ENULL) != 0)
		out << " value=" << _value;
	out << ">";
	if (_content.compare(ENULL) != 0)
		out << _content;
	out << "</" << _tag << ">" << endl;
}
