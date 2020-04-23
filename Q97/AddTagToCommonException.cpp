#include "AddTagToCommonException.h"



AddTagToCommonException::AddTagToCommonException(string id)
{
	_id = id;
}

string AddTagToCommonException::report()
{
	return "AddTagToCommonException: can not add tag to common tag, " + _id;
}



