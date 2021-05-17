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
	Carc arc1(sommet.uiSOMNumSom); //arc en direction du sommet 2
	Carc arc2(this->uiSOMNumSom); //arc en direction du sommet 1

	this->SOMArcPartant(&arc1);
	this->SOMArcArrivant(&arc2);

	sommet.SOMArcPartant(&arc2);
	sommet.SOMArcArrivant(&arc1);
}

/*******************************************************************
* Modifier le numéro d'un sommet
********************************************************************
*Entrée : uiArg le numéro à entrer
*		  l'objet pointé est de la classe Csommet
*Sortie : void
*Entraîne : Modifie le numéro du sommet et change la destination de
*			tout les arcs arrivant
********************************************************************/
void Csommet::SOMModifierNum(unsigned int uiArg)
{
	this->uiSOMNumSom = uiArg;
	int i = 0;
	while(this->SOMArrivant[i] != nullptr)
	{
		this->SOMArrivant[i]->ARCModifDest(uiArg);
		i++;
	}
}

/*******************************************************************
* Ajouter un arc arrivant
********************************************************************
*Entrée : L'objet pointé est de type Csommet
*		  Un objet de la classe Carc
*Sortie : void
*Entraîne : L'ajout de l'arc en argument dans la liste de arrivant de
*			l'objet pointé
********************************************************************/
void Csommet::SOMArcArrivant(Carc * ARCArg)
{
	if (realloc(this->SOMArrivant, sizeof(this->SOMArrivant) + sizeof(ARCArg))) {
		this->SOMArrivant[this->tailleArrivant()] = ARCArg;
	}
}

/*******************************************************************
* Ajouter un arc partant
********************************************************************
*Entrée : L'objet pointé est de type Csommet
*		  Un objet de la classe Carc
*Sortie : void
*Entraîne : L'ajout de l'arc en argument dans la liste de partant de 
*			l'objet pointé
********************************************************************/
void Csommet::SOMArcPartant(Carc * ARCArg)
{
	if (realloc(this->SOMPartant, sizeof(this->SOMPartant) + sizeof(ARCArg))) {
		this->SOMPartant[this->taillePartant()] = ARCArg;
	}
}

/*******************************************************************
* Récupération de la taille du tableau Arrivant
********************************************************************
*Entrée : L'objet pointé est de la classe Csommet
*Sortie : int La taille du tableau arrivant
*Entraîne : La récuperation de la taille du tableau de arrivant de
*			l'objet pointé
********************************************************************/
int Csommet::tailleArrivant()
{
	return (sizeof(this->SOMArrivant) / sizeof(Carc*));
}

/*******************************************************************
* Récupération de la taille du tableau Partant
********************************************************************
*Entrée : L'objet pointé est de la classe Csommet
*Sortie : int La taille du tableau partant
*Entraîne : La récuperation de las taille du tableau de partant de
*			l'objet pointé
********************************************************************/
int Csommet::taillePartant()
{
	return (sizeof(this->SOMPartant) / sizeof(Carc*));
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
	Carc** temp = this->SOMPartant;
	int i = 0;
	int temp_taille = this->taillePartant();

	while (this->SOMPartant[i] != ARCArg || i <= temp_taille) {
		i++;
	}

	while (i < temp_taille) {
		this->SOMPartant[i] = this->SOMPartant[i+1];
	}

	realloc(this->SOMPartant, sizeof(this->SOMPartant) - sizeof(ARCArg));
}
