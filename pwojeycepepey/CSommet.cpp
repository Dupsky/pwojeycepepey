#include "CSommet.h"
#include <malloc.h>
#include <cstdlib>
#include <iostream>
#include <iterator>

using std::size;



Csommet::Csommet()
{
	this->uiSOMNumSom=0;
	this->SOMPartant=nullptr;
	this->SOMArrivant=nullptr;
	this->iSOMArrivant = 0;
	this->iSOMPartant = 0;
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

unsigned int Csommet::AfficherNum()
{
	return this->uiSOMNumSom;
}

/*******************************************************************
*
********************************************************************
*Entrée :
*Sortie :
*Entraîne :
********************************************************************/

void Csommet::AfficherArcsPartant()
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
	this->iSOMArrivant = 0;
	this->iSOMPartant = 0;
}

/*******************************************************************
*
********************************************************************
*Entrée :
*Sortie :
*Entraîne :
********************************************************************/
void Csommet::link(Csommet sommet, Carc &arc1, Carc &arc2)
{
	std::cout << "lien entre le sommet " << this->AfficherNum() << " et le sommet " << sommet.AfficherNum() << std::endl;

	arc1.ARCModifDest(sommet.AfficherNum());

	this->SOMArcPartant(&arc1);
	sommet.SOMArcArrivant(&arc1);

	arc2.ARCModifDest(this->AfficherNum());

	sommet.SOMArcPartant(&arc2);
	this->SOMArcArrivant(&arc2);
	
	
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
	while(i < this->iSOMArrivant)
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
void Csommet::SOMArcArrivant(Carc *ARCArg)
{
		//Carc ** tmp = (Carc**)realloc(this->SOMArrivant, ((size_t)this->tailleArrivant() + 1) * (size_t)sizeof(ARCArg));


		Carc** tmp = (Carc**) realloc (this->SOMArrivant, ((size_t)this->taillePartant() + 1) * (size_t)sizeof(ARCArg));
		if (tmp != nullptr) {
			this->SOMArrivant = tmp;
		}
	
	this->SOMArrivant[this->tailleArrivant()] = ARCArg;
	this->iSOMArrivant++;
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
void Csommet::SOMArcPartant(Carc *ARCArg)
{

	
		Carc** tmp = (Carc**)realloc(this->SOMPartant, ((size_t)this->taillePartant() + 1) * (size_t)sizeof(ARCArg));
		if (tmp != nullptr)
		{
			this->SOMPartant = tmp;
		}
	
	this->SOMPartant[this->taillePartant()] = ARCArg;
	this->iSOMPartant++;
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
	return this->iSOMArrivant;
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
	return this->iSOMPartant;
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
	Carc** temp = this->SOMPartant;
	int i = 0;
	int temp_taille = this->iSOMPartant;

	while (this->SOMPartant[i] != ARCArg || i <= temp_taille) {
		i++;
	}

	while (i < temp_taille) {
		this->SOMPartant[i] = this->SOMPartant[i + 1];
	}

	if (realloc(this->SOMPartant, sizeof(this->SOMPartant) - sizeof(ARCArg))) {
		std::cout << "realloc réussi" << std::endl;
	}
	else {
		std::cout << "realloc non réussi" << std::endl;
	}
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
	int temp_taille = this->iSOMPartant;

	while (this->SOMPartant[i] != ARCArg || i <= temp_taille) {
		i++;
	}

	while (i < temp_taille) {
		this->SOMPartant[i] = this->SOMPartant[i+1];
	}

	if (realloc(this->SOMPartant, sizeof(this->SOMPartant) - sizeof(ARCArg))) {
		std::cout << "realloc réussi" << std::endl;
	}
	else {
		std::cout << "realloc non réussi" << std::endl;
	}
}

/*******************************************************************
*  Affichage des 2 tableaux
********************************************************************
*Entrée : L'objet pointé est de la classe Csommet
*		  Un objet de la classe Carc
*Sortie : void
*Entraîne : Affichages des valeurs des 2 tableaux du Csommet
********************************************************************/

void Csommet::AfficherTabs() {
	int i = 0;

	std::cout << "Tableau partant :" << std::endl;

	while (i < this->iSOMPartant)
	{
		std::cout << "T[" << i << "] = " << this->SOMPartant[i]->getDest() << std::endl;
		i++;
	}

	i = 0;

	std::cout << "Tableau arrivant :" << std::endl;

	while (i < this->iSOMArrivant)
	{
		std::cout << "T[" << i << "] = " << this->SOMArrivant[i]->getDest() << std::endl;
		i++;
	}
}