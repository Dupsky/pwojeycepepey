#pragma once
#include <string>
#include <iostream>
#include  <exception>

using namespace std;
class CException : public exception
{
private:

	unsigned int uiEXCValeur;

public:
	
	void EXCset(unsigned int uiArg);
	int EXCget();
};

