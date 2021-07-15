#pragma once

#include <string>

class FirstStream
{
private:
	std::string str;
public:
	void		SetStr(std::string str);
	std::string GetStr();
	std::string SortStr(std::string str);
	void		ChangeStr();
	void		SaveToBuffer();
	void		Interface();
};