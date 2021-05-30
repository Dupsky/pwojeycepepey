#pragma once
#include "Csommet.h"
#include "Carc.h"

class Cgraphe
{
private:
	Csommet** psGRATab;
	size_t stTailleTab;
public:
	Cgraphe();
	~Cgraphe();
	void GRAAjouterSommet(Csommet * pSOMArg);
	void GRACreerSommet(unsigned int uiArg);
	size_t GRATailleTab();
	void GRAAfficherGraph();
	void GRAInverserGraph();
	void GRASuppSommetIndex(unsigned int iArg);
	void GRASuppSommetNum(unsigned int iArg);
	Csommet* GRATrouverSommet(unsigned int iArg);
};

///////////erreurs///////////////

#define reallocImpo 1
#define sommetPresent 2
#define sommetNonPresent 3
#define argHorsLimite 4