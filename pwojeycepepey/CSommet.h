#pragma once
#include "Carc.h"
#include "Cexception.h"
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

	void link(Csommet * sommet);
	void unlink(Csommet * sommet);

	Carc* TrouverArcPartant(unsigned int destination);
	Carc* TrouverArcArrivant(unsigned int destination);

	int islink(Csommet * sommet);

	void SOMModifierNum(unsigned int uiArg);

	void SOMArcArrivant(Carc * ARCArg);
	void SOMArcPartant(Carc * ARCArg);

	void suppArcPartant(Carc* ARCArg);
	void suppArcArrivant(Carc* ARCArg);

	int tailleArrivant();
	int taillePartant();

	void AfficherTabs();
	void SwitchLink(Csommet * sommet);
};

///////////erreurs///////////////

#define sommetNull 10 

