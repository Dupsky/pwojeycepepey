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
///////////erreurs///////////////

#define ouvertureFichier 31
#define tropDeSommets 32
#define tropDArc 33
#define peuDeSommets 34
#define peuDArc 35



