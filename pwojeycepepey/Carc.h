#pragma once
#include "Cexception.h"
class Carc
{
private:
	unsigned int uiDest;
public:
	Carc();
	Carc(unsigned int uiDest);
	~Carc();
	void ARCModifDest(unsigned int uiArg);
	unsigned int ARCDest();
};
///////////erreurs///////////////

#define arcNull 21

