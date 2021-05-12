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
	Csommet(unsigned int uiArg,Carc ** Lis1,Carc ** Lis2);
	~Csommet();
	void SOMModifierNum(unsigned int uiArg);
	void SOMArcArrivant(Carc** ARCArg);
	void SOMArcPartant(Carc** ARCArg);
};

