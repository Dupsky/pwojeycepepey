#include "Cgraphe.h"
#include "Cexception.h"
#include <iostream>


/*******************************************************************
*  Constructeur par d�faut 
********************************************************************
*Entr�e : 
*Sortie :
*Entra�ne : Cr�e un objet de la classe Cgraphe
********************************************************************/
Cgraphe::Cgraphe()
{
	this->pGRATab = nullptr;
	this->stTailleTab = 0;
}
/*******************************************************************
*  Destructeur par d�faut
********************************************************************
*Entr�e :
*Sortie :
*Entra�ne : D�truit un objet de la classe Cgraphe
********************************************************************/
Cgraphe::~Cgraphe()
{
	free(this->pGRATab);
}

/*******************************************************************
*  Ajouter un sommet au graphe
********************************************************************
*Entr�e : L'objet point� est de classe Cgraphe
*		  Csommet * sommet le sommet � ajouter au graph
*Sortie : void
*Entra�ne : Ajoute un sommet au graphe
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
*Entr�e :
*Sortie : void
*Entra�ne : Affiche le graphe 
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
*Entr�e :
*Sortie : void
*Entra�ne : inverse les arcs entre chaque sommet du graphe
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
*  R�cup�re la taille du graphe (du tableau de Csommet)
********************************************************************
*Entr�e :
*Sortie : void
*Entra�ne : Return la taille du tableau de Csommet du graphe
********************************************************************/
size_t Cgraphe::tailleTab()
{
	return this->stTailleTab;
}
/*******************************************************************
*  Supprime un sommet � partir de son index
********************************************************************
*Entr�e : Le num�ro du sommet
*Sortie : void
*Entra�ne : La suppression du sommet this->pGRATab[iArg]
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
* Suppression du sommet � partir de son num�ro 
********************************************************************
*Entr�e : Le num�ro du sommet � supprimer
*Sortie :void
*Entra�ne : Supprime le sommet num�ro iArg
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
* Cr�ation d'un nouveau sommet et ajout de ce dernier au graphe
********************************************************************
*Entr�e : Le num�ro du sommet � cr�er
*Sortie :void
*Entra�ne : Ajoute le nouveau sommet num�ro iArg au graphe
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
*Entr�e : Le num�ro du sommet � trouver
*Sortie : Csommet * 
*Entra�ne : Return le sommet � trouver dans le graphe
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
* R�cuperer la taille du graphique
********************************************************************
*Entr�e : 
*Sortie : size_t la taille du graphe
*Entra�ne : Return la taille du Graphe (nombre de sommets)
********************************************************************/
size_t Cgraphe::sizeofgraph()
{
	return sizeof(this->pGRATab);
}