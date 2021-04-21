#include "CException.h"
#include <iostream>

using namespace std;

void CException::EXCset(unsigned int uiArg) 
{
	this->uiEXCValeur = uiArg;
}



int CException::EXCget()
{
	return this->uiEXCValeur;
}




