#pragma once
class TradeException
{
	const char* _msg;

public:
	TradeException(const char* msg);
	const char* get_msg();
};

