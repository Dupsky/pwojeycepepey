#include "Cgraphe.h"
#include "Cexception.h"
#include <iostream>


/*******************************************************************
*  Constructeur par défaut 
********************************************************************
*Entrée : 
*Sortie :
*Entraîne : Crée un objet de la classe Cgraphe
********************************************************************/
Cgraphe::Cgraphe()
{
	this->pGRATab = nullptr;
	this->stTailleTab = 0;
}
/*******************************************************************
*  Destructeur par défaut
********************************************************************
*Entrée :
*Sortie :
*Entraîne : Détruit un objet de la classe Cgraphe
********************************************************************/
Cgraphe::~Cgraphe()
{
	free(this->pGRATab);
}

/*******************************************************************
*  Ajouter un sommet au graphe
********************************************************************
*Entrée : L'objet pointé est de classe Cgraphe
*		  Csommet * sommet le sommet à ajouter au graph
*Sortie : void
*Entraîne : Ajoute un sommet au graphe
********************************************************************/
void Cgraphe::addSommet(Csommet * sommet)
{
	//this->AfficherGraph();

	for (int i = 0; i < this->stTailleTab; i++)
	{
		if (this->pGRATab[i]->AfficherNum()==sommet->AfficherNum())
		{
			CException EXCObj;
			EXCObj.EXCset(sommetPresent);
			throw(EXCObj);
		}
	}
	stTailleTab++;
	Csommet** temp = (Csommet**)realloc(this->pGRATab, (size_t)this->stTailleTab * (size_t)sizeof(sommet));
	if (temp == nullptr)
	{
		CException EXCObj;
		EXCObj.EXCset(reallocImpo);
		throw(EXCObj);
		stTailleTab--;
	}
	else {
		this->pGRATab = temp;
	}
	
	if (this->pGRATab != nullptr) this->pGRATab[this->stTailleTab-1] = sommet;
	
}

/*******************************************************************
*  Afficher le graphe
********************************************************************
*Entrée :
*Sortie : void
*Entraîne : Affiche le graphe 
********************************************************************/
void Cgraphe::AfficherGraph()
{
	int pos=0;
	std::cout << "Liste des sommets du graphique et leurs arcs partant" << std::endl;
	for (pos; pos < this->stTailleTab; pos++) {
		std::cout << "Sommet " << this->pGRATab[pos]->AfficherNum() << ": ";
		this->pGRATab[pos]->AfficherArcsPartant();
		std::cout << std::endl;
	}
}
/*******************************************************************
*  Inverser le graphe
********************************************************************
*Entrée :
*Sortie : void
*Entraîne : inverse les arcs entre chaque sommet du graphe
********************************************************************/
void Cgraphe::InverserGraph()
{
	for (int i = 0; i < this->stTailleTab; i++)
	{
		for (int j = 0; j < this->stTailleTab; j++)
		{
			if (j > i) {
				this->pGRATab[i]->SwitchLink(this->pGRATab[j]);
			}
		}
	}
}

/*******************************************************************
*  Récupère la taille du graphe (du tableau de Csommet)
********************************************************************
*Entrée :
*Sortie : void
*Entraîne : Return la taille du tableau de Csommet du graphe
********************************************************************/
size_t Cgraphe::tailleTab()
{
	return this->stTailleTab;
}
/*******************************************************************
*  Supprime un sommet à partir de son index
********************************************************************
*Entrée : Le numéro du sommet
*Sortie : void
*Entraîne : La suppression du sommet this->pGRATab[iArg]
********************************************************************/
void Cgraphe::SuppSommetIndex(unsigned int iArg)
{
	int iBoucle = 0;
	
	if (iArg > this->stTailleTab-1) {
		CException EXCObj;
		EXCObj.EXCset(argHorsLimite);
		throw(EXCObj);
	}
	for (iBoucle = iArg; iBoucle < this->stTailleTab; iBoucle++)
	{
		this->pGRATab[iBoucle] = this->pGRATab[iBoucle + 1];


	}
	this->stTailleTab--;
	Csommet** temp = (Csommet**)realloc(this->pGRATab, (size_t)this->stTailleTab * (size_t)sizeof(Csommet));
	if (temp != nullptr || this->stTailleTab == 1)
	{
		this->pGRATab = temp;
	}
	else {

		CException EXCObj;
		EXCObj.EXCset(reallocImpo);
		throw(EXCObj);
	}
}
/*******************************************************************
* Suppression du sommet à partir de son numéro 
********************************************************************
*Entrée : Le numéro du sommet à supprimer
*Sortie :void
*Entraîne : Supprime le sommet numéro iArg
********************************************************************/
void Cgraphe::SuppSommetNum(unsigned int iArg)
{
	int iBoucle = 0;
	int iIndice = -1;
	for (int i = 0; i < this->stTailleTab; i++)
	{
		if (this->pGRATab[i]->AfficherNum() == iArg)
		{
			iIndice = i;
		}
	}
	if (iIndice == -1) {
		CException EXCObj;
		EXCObj.EXCset(sommetNonPresent);
		throw(EXCObj);
	}
	for (iBoucle = iIndice; iBoucle < this->stTailleTab; iBoucle++)
	{
		this->pGRATab[iBoucle] = this->pGRATab[iBoucle + 1];

		
	}
	this->stTailleTab--;
	Csommet** temp = (Csommet**)realloc(this->pGRATab, (size_t)this->stTailleTab * (size_t)sizeof(Csommet));
	if (temp != nullptr || this->stTailleTab == 1)
	{
		this->pGRATab = temp;
	}
	else {
		
		CException EXCObj;
		EXCObj.EXCset(reallocImpo);
		throw(EXCObj);
	}

}
/*******************************************************************
* Création d'un nouveau sommet et ajout de ce dernier au graphe
********************************************************************
*Entrée : Le numéro du sommet à créer
*Sortie :void
*Entraîne : Ajoute le nouveau sommet numéro iArg au graphe
********************************************************************/
void Cgraphe::createSommet(unsigned int uiArg)
{
	Csommet * sommet =new Csommet(uiArg);

	this->addSommet(sommet);
	//this->pGRATab[uiArg - 1];
}
/*******************************************************************
* Trouver un sommet dans le graphe
********************************************************************
*Entrée : Le numéro du sommet à trouver
*Sortie : Csommet * 
*Entraîne : Return le sommet à trouver dans le graphe
********************************************************************/
Csommet* Cgraphe::TrouverSommet(unsigned int uiArg)
{
	int i = 0;
	int indice = -1;
	//cherche dans le tableau le sommet avec le bon numero

	while (i < this->stTailleTab)
	{
		if (this->pGRATab[i]->AfficherNum() == uiArg) {
			indice = i;
		}
		i++;
	}

	if (indice != -1 && this->pGRATab[indice]->AfficherNum() == uiArg)
	{
		return this->pGRATab[indice];
	}
	else
	{
		return nullptr;
	}
}



/*******************************************************************
* Récuperer la taille du graphique
********************************************************************
*Entrée : 
*Sortie : size_t la taille du graphe
*Entraîne : Return la taille du Graphe (nombre de sommets)
********************************************************************/
size_t Cgraphe::sizeofgraph()
{
	return sizeof(this->pGRATab);
}