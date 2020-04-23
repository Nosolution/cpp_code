#include "IDNotFoundException.h"



IDNotFoundException::IDNotFoundException(string id)
{
	_id = id;
}


string IDNotFoundException::report()
{
	return "IDNotFoundException: ID not found, " + _id;
}
