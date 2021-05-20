#include "CSommet.h"
#include <cstdlib>
#include <iostream>


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

unsigned int Csommet::AfficherNum()
{
	return this->uiSOMNumSom;
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
	Carc arc1(sommet.uiSOMNumSom); //arc en direction du sommet 2
	Carc arc2(this->uiSOMNumSom); //arc en direction du sommet 1

	this->SOMArcPartant(&arc1);
	this->SOMArcArrivant(&arc2);

	sommet.SOMArcPartant(&arc2);
	sommet.SOMArcArrivant(&arc1);
}

/*******************************************************************
* Modifier le num�ro d'un sommet
********************************************************************
*Entr�e : uiArg le num�ro � entrer
*		  l'objet point� est de la classe Csommet
*Sortie : void
*Entra�ne : Modifie le num�ro du sommet et change la destination de
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
*Entr�e : L'objet point� est de type Csommet
*		  Un objet de la classe Carc
*Sortie : void
*Entra�ne : L'ajout de l'arc en argument dans la liste de arrivant de
*			l'objet point�
********************************************************************/
void Csommet::SOMArcArrivant(Carc *ARCArg)
{
	if (this->SOMArrivant = (Carc**)realloc(this->SOMPartant, (this->taillePartant() + 1) * sizeof(ARCArg))) {
		this->SOMArrivant[this->tailleArrivant()] = ARCArg;
	}
}

/*******************************************************************
* Ajouter un arc partant
********************************************************************
*Entr�e : L'objet point� est de type Csommet
*		  Un objet de la classe Carc
*Sortie : void
*Entra�ne : L'ajout de l'arc en argument dans la liste de partant de 
*			l'objet point�
********************************************************************/
void Csommet::SOMArcPartant(Carc *ARCArg)
{
	if (this->SOMPartant = (Carc**)realloc(this->SOMPartant, (this->taillePartant() + 1) * sizeof(ARCArg))) {
		this->SOMPartant[this->taillePartant()] = ARCArg;
	}
}

/*******************************************************************
* R�cup�ration de la taille du tableau Arrivant
********************************************************************
*Entr�e : L'objet point� est de la classe Csommet
*Sortie : int La taille du tableau arrivant
*Entra�ne : La r�cuperation de la taille du tableau de arrivant de
*			l'objet point�
********************************************************************/
int Csommet::tailleArrivant()
{
	return (sizeof(this->SOMArrivant) / sizeof(Carc*));
}

/*******************************************************************
* R�cup�ration de la taille du tableau Partant
********************************************************************
*Entr�e : L'objet point� est de la classe Csommet
*Sortie : int La taille du tableau partant
*Entra�ne : La r�cuperation de las taille du tableau de partant de
*			l'objet point�
********************************************************************/
int Csommet::taillePartant()
{
	return (sizeof(this->SOMPartant) / sizeof(Carc*));
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
	Carc** temp = this->SOMPartant;
	int i = 0;
	int temp_taille = this->taillePartant();

	while (this->SOMPartant[i] != ARCArg || i <= temp_taille) {
		i++;
	}

	while (i < temp_taille) {
		this->SOMPartant[i] = this->SOMPartant[i+1];
	}

	if (realloc(this->SOMPartant, sizeof(this->SOMPartant) - sizeof(ARCArg))) {
		std::cout << "realloc r�ussi" << std::endl;
	}
	else {
		std::cout << "realloc non r�ussi" << std::endl;
	}
}
/*******************************************************************
* Afficher les arcs partant d'un sommet
********************************************************************
*Entr�e : L'objet point� est de la classe Csommet
*		
*Sortie : void
*Entra�ne :Affiche la liste des arcs partant et leurs destination
********************************************************************/
void Csommet::AfficherArcsPartant()
{
	int i = 0;
	while (this->SOMPartant[i] != nullptr)
	{
		std::cout << " " << this->AfficherNum() << "-->" << this->SOMPartant[i]->getDest() << " ;";
		i++;
	}
}