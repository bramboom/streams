#pragma once

#include <string>

class SecondStream
{
private:
	std::string str = "";
public:
	void		SetStr(std::string str);
	std::string GetStr();
	void		LoadFromBuffer();
	void		ShowStr();
	int 		GetSum();
	void		Interface();
};
