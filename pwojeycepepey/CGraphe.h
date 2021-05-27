#pragma once
#include "Csommet.h"
#include "Carc.h"

class Cgraphe
{
private:
	Csommet* pGRATab;
	size_t stTailleTab;
public:
	Cgraphe();
	void addSommet(Csommet sommet);
	size_t tailleTab();
	void AfficherGraph();
	void InverserGraph();
	void SuppSommetIndex(int iArg);
	void SuppSommetNum(int iArg);
};

///////////erreurs///////////////

#define reallocImpo 1
#define sommetPresent 2
#define sommetNonPresent 3