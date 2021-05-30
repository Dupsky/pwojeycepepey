#pragma once
#include "CGraphe.h"

class Cparser
{
private:
	const char* cNomfichier;

public:
	Cparser(const char* cNomfichier);
	void PARLireFichier(Cgraphe* pGRAArg);

};



