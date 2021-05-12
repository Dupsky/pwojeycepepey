#include "CSommet.h"


Csommet::Csommet()
{
	this->uiSOMNumSom=0;
	this->SOMPartant=nullptr;
	this->SOMArrivant=nullptr;
}
Csommet::~Csommet()
{

}
Csommet::Csommet(unsigned int uiArg)
{
	this->uiSOMNumSom = uiArg;
	this->SOMPartant = nullptr;
	this->SOMArrivant = nullptr;
}
void Csommet::link(Csommet sommet)
{
	Carc arc1(sommet.uiSOMNumSom); 
	Carc arc2(this->uiSOMNumSom);
	

}
void Csommet::SOMModifierNum(unsigned int uiArg)
{

}
void Csommet::SOMArcArrivant(Carc * ARCArg)
{

}
void Csommet::SOMArcPartant(Carc * ARCArg)
{

}

int Csommet::tailleArrivant()
{
	int i = 0;
	while (this->SOMArrivant != nullptr)
	{
		i++;
		this->SOMArrivant++;
	}
	return i;
}

int Csommet::taillePartant()
{

}

void Csommet::suppArcArrivant(Carc * ARCArg)
{

}

void Csommet::suppArcPartant(Carc* ARCArg)
{

}
