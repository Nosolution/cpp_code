#include "TradeException.h"



TradeException::TradeException(const char* msg)
{
	_msg = msg;
}

const char* TradeException::get_msg()
{
	return _msg;
}


