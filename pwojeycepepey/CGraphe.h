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
};

///////////erreurs///////////////

#define reallocImpo 1
#define sommetPresent 2