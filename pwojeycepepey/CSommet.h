#pragma once
#include "Carc.h"
class Csommet
{
private:
	unsigned int uiSOMNumSom;
	Carc ** SOMArrivant;
	Carc ** SOMPartant;
	int iSOMArrivant;
	int iSOMPartant;
public:
	Csommet();
	Csommet(unsigned int uiArg);
	~Csommet();
	unsigned int AfficherNum();
	void AfficherArcsPartant();
	void link(Csommet sommet, Carc &arc1, Carc &arc2);
	void SOMModifierNum(unsigned int uiArg);
	void SOMArcArrivant(Carc * ARCArg);
	void SOMArcPartant(Carc * ARCArg);
	void suppArcPartant(Carc* ARCArg);
	void suppArcArrivant(Carc* ARCArg);
	int tailleArrivant();
	int taillePartant();
	void AfficherTabs();
};

