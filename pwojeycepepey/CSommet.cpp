#include "CSommet.h"
#include <cstdlib>


Csommet::Csommet()
{
	this->uiSOMNumSom=0;
	this->SOMPartant=nullptr;
	this->SOMArrivant=nullptr;
}

/*******************************************************************
*
********************************************************************
*Entr�e :
*Sortie :
*Entra�ne :
********************************************************************/
Csommet::~Csommet()
{

}

/*******************************************************************
*
********************************************************************
*Entr�e :
*Sortie :
*Entra�ne :
********************************************************************/
Csommet::Csommet(unsigned int uiArg)
{
	this->uiSOMNumSom = uiArg;
	this->SOMPartant = nullptr;
	this->SOMArrivant = nullptr;
}

/*******************************************************************
*
********************************************************************
*Entr�e :
*Sortie :
*Entra�ne :
********************************************************************/
void Csommet::link(Csommet sommet)
{
	Carc arc1(sommet.uiSOMNumSom); 
	Carc arc2(this->uiSOMNumSom);
	

}

/*******************************************************************
*
********************************************************************
*Entr�e :
*Sortie :
*Entra�ne :
********************************************************************/
void Csommet::SOMModifierNum(unsigned int uiArg)
{

}

/*******************************************************************
*
********************************************************************
*Entr�e :
*Sortie :
*Entra�ne :
********************************************************************/
void Csommet::SOMArcArrivant(Carc * ARCArg)
{
	if (realloc(this->SOMArrivant, sizeof(this->SOMArrivant) + sizeof(ARCArg))) {
		this->SOMArrivant[this->tailleArrivant()] = ARCArg;
	}
}

/*******************************************************************
*
********************************************************************
*Entr�e :
*Sortie :
*Entra�ne :
********************************************************************/
void Csommet::SOMArcPartant(Carc * ARCArg)
{
	if (realloc(this->SOMPartant, sizeof(this->SOMPartant) + sizeof(ARCArg))) {
		this->SOMPartant[this->taillePartant()] = ARCArg;
	}
}

/*******************************************************************
*
********************************************************************
*Entr�e :
*Sortie :
*Entra�ne :
********************************************************************/
int Csommet::tailleArrivant()
{
	return sizeof(this->SOMArrivant) / sizeof(Carc*);
}

/*******************************************************************
* R�cup�ration de la taille du tableau Partant
********************************************************************
*Entr�e : L'objet point� est de la classe Csommet
*Sortie : int La taille du tableau
*Entra�ne : La r�cuperation de la taille du tableau de 
********************************************************************/
int Csommet::taillePartant()
{
	return sizeof(this->SOMPartant) / sizeof(Carc*);
}

/*******************************************************************
*  Supression d'un arc arrivant
********************************************************************
*Entr�e : L'objet point� est de la classe Csommet
*		  Un objet de la classe Carc
*Sortie : void
*Entra�ne : La suppression de l'arc contenu dans la liste des
*			arc arrivant de l'objet point�
********************************************************************/
void Csommet::suppArcArrivant(Carc * ARCArg)
{

}

/*******************************************************************
*  Supression d'un arc partant
********************************************************************
*Entr�e : L'objet point� est de la classe Csommet
*		  Un objet de la classe Carc
*Sortie : void
*Entra�ne : La suppression de l'arc contenu dans la liste des
*			arc partant de l'objet point�
********************************************************************/
void Csommet::suppArcPartant(Carc* ARCArg)
{

}
