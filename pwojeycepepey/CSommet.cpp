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
*Entrée :
*Sortie :
*Entraîne :
********************************************************************/
Csommet::~Csommet()
{

}

/*******************************************************************
*
********************************************************************
*Entrée :
*Sortie :
*Entraîne :
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
*Entrée :
*Sortie :
*Entraîne :
********************************************************************/
void Csommet::link(Csommet sommet)
{
	Carc arc1(sommet.uiSOMNumSom); 
	Carc arc2(this->uiSOMNumSom);
	

}

/*******************************************************************
*
********************************************************************
*Entrée :
*Sortie :
*Entraîne :
********************************************************************/
void Csommet::SOMModifierNum(unsigned int uiArg)
{

}

/*******************************************************************
*
********************************************************************
*Entrée :
*Sortie :
*Entraîne :
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
*Entrée :
*Sortie :
*Entraîne :
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
*Entrée :
*Sortie :
*Entraîne :
********************************************************************/
int Csommet::tailleArrivant()
{
	return sizeof(this->SOMArrivant) / sizeof(Carc*);
}

/*******************************************************************
* Récupération de la taille du tableau Partant
********************************************************************
*Entrée : L'objet pointé est de la classe Csommet
*Sortie : int La taille du tableau
*Entraîne : La récuperation de la taille du tableau de 
********************************************************************/
int Csommet::taillePartant()
{
	return sizeof(this->SOMPartant) / sizeof(Carc*);
}

/*******************************************************************
*  Supression d'un arc arrivant
********************************************************************
*Entrée : L'objet pointé est de la classe Csommet
*		  Un objet de la classe Carc
*Sortie : void
*Entraîne : La suppression de l'arc contenu dans la liste des
*			arc arrivant de l'objet pointé
********************************************************************/
void Csommet::suppArcArrivant(Carc * ARCArg)
{

}

/*******************************************************************
*  Supression d'un arc partant
********************************************************************
*Entrée : L'objet pointé est de la classe Csommet
*		  Un objet de la classe Carc
*Sortie : void
*Entraîne : La suppression de l'arc contenu dans la liste des
*			arc partant de l'objet pointé
********************************************************************/
void Csommet::suppArcPartant(Carc* ARCArg)
{

}
