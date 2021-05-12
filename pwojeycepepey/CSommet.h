#pragma once
#include "Carc.h"
class Csommet
{
private:
	unsigned int uiSOMNumSom;
	Carc ** SOMArrivant;
	Carc ** SOMPartant;
public:
	Csommet();
	Csommet(unsigned int uiArg);
	~Csommet();
	void link(Csommet sommet);
	void SOMModifierNum(unsigned int uiArg);
	void SOMArcArrivant(Carc * ARCArg);
	void SOMArcPartant(Carc * ARCArg);
};

