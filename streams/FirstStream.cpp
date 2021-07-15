#include "FirstStream.h"
#include <string>
//#include <algorithm> //for sorting
#include <fstream>
#include <iostream>

void FirstStream::SetStr(std::string str)
{
	if(str.size() > 64)
	{
		throw("size more 64 symbols.");
	}
	for(int index = 0; index < str.size(); index++)
	{
		if((str[index] < '0') || (str[index] > '9'))
		{
			throw("symbol must be number");
		}
	}
	this->str = str;
}

std::string FirstStream::GetStr()
{
	return this->str;
}

//quicksort
std::string FirstStream::SortStr(std::string str)
{
	std::string firstPart = "";
	std::string secondPart = "";
	std::string pivotPart = "";
	
	int size = str.size();
	char mainSymbol = str[size - 1];
	
	for(int index = 0; index < size; index++)
	{
		if(mainSymbol > str[index])
		{
			secondPart += str[index];
		}
		else if(mainSymbol < str[index])
		{
			firstPart += str[index];
		}
		else
		{
			pivotPart += str[index];
		}
	}

	if(secondPart.size() > 1)
	{
		secondPart = this->SortStr(secondPart);
	}
	
	if (firstPart.size() > 1)
	{
		firstPart = this->SortStr(firstPart);
	}
	
	return firstPart + pivotPart + secondPart;
	/*std::sort(str.begin(), str.end());
	return str;*/
}

void FirstStream::ChangeStr()
{
	std::string newStr = "";

	for(int index = 0; index < str.size(); index++)
	{
		int num = (int)str[index];
		if(num % 2 == 0)
		{
			newStr += "KB";
		}
		else
		{
			newStr += str[index];
		}
	}

	this->str = newStr;
}

void FirstStream::SaveToBuffer()
{
	std::ofstream out;
	out.open("..//buffer.txt");
	out << this->str;
	out.close();
}

void FirstStream::Interface()
{
	std::string str = "";
	std::cin >> str;
	this->SetStr(str);
	str = this->SortStr(this->GetStr());
	this->SetStr(str);
	this->ChangeStr();
	this->SaveToBuffer();
}









