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
*  Affichage des arcs partant du sommet
********************************************************************
*Entrée : L'objet pointé est de la classe Csommet
*Sortie : void
*Entraîne : Affichages des arcs partant du sommet
********************************************************************/

void Csommet::AfficherArcsPartant()
{
	int i = 0;

	while (i < this->iSOMPartant)
	{
		std::cout << this->uiSOMNumSom << "->" << this->SOMPartant[i]->getDest() << " ; ";
		i++;
	}

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
void Csommet::link(Csommet &sommet)
{
	//std::cout << "creation du lien du sommet " << this->AfficherNum() << " vers le sommet " << sommet.AfficherNum() << "\n" << std::endl;

	Carc* arc1 = new Carc(sommet.AfficherNum());
	Carc* arc2 = new Carc(this->AfficherNum());


	//arc1.ARCModifDest(sommet.AfficherNum());

	this->SOMArcPartant(arc1);

	//arc2.ARCModifDest(this->AfficherNum());

	sommet.SOMArcArrivant(arc2);

	
	
}

/*******************************************************************
*
********************************************************************
*Entrée :
*Sortie :
*Entraîne :
********************************************************************/

void Csommet::unlink(Csommet& sommet)
{
	//std::cout << "suppression du lien du sommet " << this->AfficherNum() << " vers le sommet " << sommet.AfficherNum() << "\n" << std::endl;

	if(this->islink(sommet)) { //il y a un lien de 1 vers 2

		//suppression arc dans le sommet 1 (partant avec destination = 2)
		this->suppArcPartant(this->TrouverArcPartant(sommet.AfficherNum()));

		//suppression arc dans le sommet 2 (arrivant avec destination = 1)
		sommet.suppArcArrivant(sommet.TrouverArcArrivant(this->AfficherNum()));
	}


}

/*******************************************************************
*  Inverse 2 sommets
********************************************************************
*Entrée : L'objet pointé est de la classe Csommet
*		  Un objet de la classe CSommet
*Sortie : void
*Entraîne : L'inversion des deux arcs reliant les sommets
*			(uniquement l'arc partant de l'objet pointé)
********************************************************************/

void Csommet::SwitchLink(Csommet sommet)
{
	Carc  arc1 = Carc();
	Carc arc2 = Carc();

	if (!sommet.islink(*this) && this->islink(sommet)) {
		this->unlink(sommet);
		sommet.link(*this);
	}
}



/*******************************************************************
*
********************************************************************
*Entrée :
*Sortie :
*Entraîne :
********************************************************************/

Carc* Csommet::TrouverArcPartant(unsigned int destination)
{
	int i = 0;
	int indice = -1;
	//cherche dans le tableau arc partant l'arc avec la bonne destination

	while (i < this->iSOMPartant)
	{
		if (this->SOMPartant[i]->getDest() == destination) {
			indice = i;
		}
		i++;
	}

	if (indice != -1 && this->SOMPartant[indice]->getDest() == destination)
	{
		return this->SOMPartant[indice];
	}
	else
	{
		return nullptr;
	}
}

/*******************************************************************
*
********************************************************************
*Entrée :
*Sortie :
*Entraîne :
********************************************************************/

Carc* Csommet::TrouverArcArrivant(unsigned int destination)
{
	int i = 0;
	int indice = -1;
	//cherche dans le tableau arc partant l'arc avec la bonne destination

	while (i < this->iSOMArrivant)
	{
		if (this->SOMArrivant[i]->getDest() == destination) {
			indice = i;
		}
		i++;
	}

	if (indice != -1 && this->SOMArrivant[indice]->getDest() == destination)
	{
		return this->SOMArrivant[indice];
	}
	else
	{
		return nullptr;
	}
}

/*******************************************************************
*
********************************************************************
*Entrée :
*Sortie :
*Entraîne :
********************************************************************/

int Csommet::islink(Csommet sommet)
{
	if (this->TrouverArcPartant(sommet.AfficherNum()) != nullptr) {
		return 1;
	}
	else
	{
		return 0;
	}
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
	Carc** tmp = this->SOMArrivant;
	int i = 0;
	int indice = -1;
	int temp_taille = this->iSOMArrivant;

	while (i < temp_taille) {
		if (this->SOMArrivant[i] == ARCArg) {
			indice = i;
		}
		i++;
	}

	if (indice != -1) { //element bien présent 

		while (indice < temp_taille) {
			tmp[indice] = tmp[indice + 1];
			indice++;
		}

		tmp = (Carc**)realloc(this->SOMArrivant, ((size_t)this->tailleArrivant() - 1) * (size_t)sizeof(ARCArg));


		if (tmp != nullptr || this->iSOMArrivant == 1) {
			this->SOMArrivant = tmp;
			this->iSOMArrivant--;
		}
		else {
			std::cout << "realloc non réussi" << std::endl;
		}
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
	Carc** tmp = this->SOMPartant;
	int i = 0;
	int indice = -1;
	int temp_taille = this->iSOMPartant;

	while (i < temp_taille) {
		if (this->SOMPartant[i] == ARCArg) {
			indice = i;
		}
		i++;
	}

	if (indice != -1) { //element bien présent 

		while (indice < temp_taille) {
			tmp[indice] = tmp[indice + 1];
			indice++;
		}

		tmp = (Carc**)realloc(this->SOMPartant, ((size_t)this->taillePartant() - 1) * (size_t)sizeof(ARCArg));
		if (tmp != nullptr || this->iSOMArrivant == 1) {
			this->SOMPartant = tmp;
			this->iSOMPartant--;
		}
		else {
			std::cout << "realloc non réussi" << std::endl;
		}
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
	
	std::cout << "Sommet n = " << this->AfficherNum() << " :\n-> :" << std::endl;

	while (i < this->iSOMPartant)
	{
		std::cout << "T[" << i << "] = " << this->SOMPartant[i]->getDest() << std::endl;
		i++;
	}

	i = 0;

	std::cout << "\n<- :" << std::endl;

	while (i < this->iSOMArrivant)
	{
		std::cout << "T[" << i << "] = " << this->SOMArrivant[i]->getDest() << std::endl;
		i++;
	}
	std::cout << std::endl;
}



