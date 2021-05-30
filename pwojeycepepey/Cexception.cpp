#include "CException.h"
#include <iostream>

using namespace std;
CException::CException()
{
	this->uiEXCValeur = 0;
}

void CException::EXCset(unsigned int uiArg) 
{
	this->uiEXCValeur = uiArg;
}



int CException::EXCget()
{
	return this->uiEXCValeur;
}




