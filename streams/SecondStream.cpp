#include "SecondStream.h"
#include <fstream>
#include <iostream>

void SecondStream::SetStr(std::string str)
{
	this->str = str;
}

std::string SecondStream::GetStr()
{
	return this->str;
}


void SecondStream::LoadFromBuffer()
{

	std::ifstream in;
	in.open("..//buffer.txt", std::ofstream::out || std::ofstream::trunc);
	in >> this->str;
	in.close();
}

void SecondStream::ShowStr()
{
	std::cout << this->str << std::endl;
}

int SecondStream::GetSum()
{
	int sum = 0;
	int size = this->str.size();
	for(int index = 0; index < size; index++)
	{
		if((this->str[index] <= '9') && (this->str[index] >= '0'))
		{
			sum += (int)this->str[index] - 48;
		}
	}

	return sum;
}

void SecondStream::Interface()
{
	LoadFromBuffer();
	ShowStr();
	std::cout << GetSum() << std::endl;
}


