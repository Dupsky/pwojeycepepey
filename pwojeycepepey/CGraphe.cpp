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
	this->psGRATab = nullptr;
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
	free(this->psGRATab);
}

/*******************************************************************
*  Ajouter un sommet au graphe
********************************************************************
*Entrée : L'objet pointé est de classe Cgraphe
*		  Csommet * sommet le sommet à ajouter au graph
*Sortie : void
*Entraîne : Ajoute un sommet au graphe
********************************************************************/
void Cgraphe::GRAAjouterSommet(Csommet * pSOMArg)
{
	//this->GRAAfficherGraph();
	if (pSOMArg == nullptr)
	{
		CException EXCObj;
		EXCObj.EXCset(sommetNull);
		throw(EXCObj);
	}
	for (int iBoucle = 0; iBoucle < this->stTailleTab; iBoucle++)
	{
		if (this->psGRATab[iBoucle]->SOMNumSommet()== pSOMArg->SOMNumSommet())
		{
			std::cout << "Le sommet "<< pSOMArg->SOMNumSommet() <<" deja present de le graphe, impossible d'ajouter le sommet" << std::endl;
			CException EXCObj;
			EXCObj.EXCset(sommetPresent);
			throw(EXCObj);
		}
	}
	stTailleTab++;
	Csommet** pSOMtemp = (Csommet**)realloc(this->psGRATab, (size_t)this->stTailleTab * (size_t)sizeof(pSOMArg));
	if (pSOMtemp == nullptr)
	{
		CException EXCObj;
		EXCObj.EXCset(reallocImpo);
		throw(EXCObj);
	}
	else {
		this->psGRATab = pSOMtemp;
	}
	
	if (this->psGRATab != nullptr) this->psGRATab[this->stTailleTab-1] = pSOMArg;
	
}

/*******************************************************************
*  Afficher le graphe
********************************************************************
*Entrée :
*Sortie : void
*Entraîne : Affiche le graphe 
********************************************************************/
void Cgraphe::GRAAfficherGraph()
{
	try {
		int iPos = 0;
		std::cout << "Liste des sommets du graphique et leurs arcs partant" << std::endl;
		for (iPos; iPos < this->stTailleTab; iPos++) {
			std::cout << "Sommet " << this->psGRATab[iPos]->SOMNumSommet() << ": ";
			this->psGRATab[iPos]->SOMAfficherArcsPartant();
			std::cout << std::endl;
		}
	}
	catch (CException EXCLevee) {
		std::cout << "une exception a ete levee, numero " << EXCLevee.EXCget() << "\n" << std::endl;
	}
}
/*******************************************************************
*  Inverser le graphe
********************************************************************
*Entrée :
*Sortie : void
*Entraîne : inverse les arcs entre chaque sommet du graphe
********************************************************************/
void Cgraphe::GRAInverserGraph()
{
	for (int iBoucle = 0; iBoucle < this->stTailleTab; iBoucle++)
	{
		for (int iBoucle2 = 0; iBoucle2 < this->stTailleTab; iBoucle2++)
		{
			if (iBoucle2 > iBoucle) {
				this->psGRATab[iBoucle]->SOMSwitchLink(this->psGRATab[iBoucle2]);
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
size_t Cgraphe::GRATailleTab()
{
	return this->stTailleTab;
}
/*******************************************************************
*  Supprime un sommet à partir de son index
********************************************************************
*Entrée : Le numéro du sommet
*Sortie : void
*Entraîne : La suppression du sommet this->psGRATab[iArg]
********************************************************************/
void Cgraphe::GRASuppSommetIndex(unsigned int iArg)
{
	int iBoucle = 0;
	
	if (iArg > this->stTailleTab-1) {
		CException EXCObj;
		EXCObj.EXCset(argHorsLimite);
		throw(EXCObj);
	}
	for (iBoucle = iArg; iBoucle < this->stTailleTab; iBoucle++)
	{
		this->psGRATab[iBoucle] = this->psGRATab[iBoucle + 1];


	}
	this->stTailleTab--;
	Csommet** pSOMtemp = (Csommet**)realloc(this->psGRATab, (size_t)this->stTailleTab * (size_t)sizeof(Csommet));
	if (pSOMtemp != nullptr || this->stTailleTab == 1)
	{
		this->psGRATab = pSOMtemp;
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
void Cgraphe::GRASuppSommetNum(unsigned int iArg)
{
	int iBoucle = 0;
	int iIndice = -1;
	for (int iBoucle = 0; iBoucle < this->stTailleTab; iBoucle++)
	{
		if (this->psGRATab[iBoucle]->SOMNumSommet() == iArg)
		{
			iIndice = iBoucle;
		}
	}
	if (iIndice == -1) {
		std::cout << "Le sommet" << iArg<< "n'est pas present de le graphe, impossible de supprimer" << std::endl;
		CException EXCObj;
		EXCObj.EXCset(sommetNonPresent);
		throw(EXCObj);
	}
	for (int iBoucle2 = iIndice; iBoucle2 < this->stTailleTab; iBoucle2++)
	{
		this->psGRATab[iBoucle2] = this->psGRATab[iBoucle2 + 1];

		
	}
	this->stTailleTab--;
	Csommet** pSOMtemp = (Csommet**)realloc(this->psGRATab, (size_t)this->stTailleTab * (size_t)sizeof(Csommet));
	if (pSOMtemp != nullptr || this->stTailleTab == 1)
	{
		this->psGRATab = pSOMtemp;
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
void Cgraphe::GRACreerSommet(unsigned int uiArg)
{
	Csommet * pSOMArg =new Csommet(uiArg);
	try {
		this->GRAAjouterSommet(pSOMArg);
	}
	catch (CException EXCLevee) {
		std::cout << "une exception a ete levee, numero " << EXCLevee.EXCget() << "\n" << std::endl;
	}
	//this->psGRATab[uiArg - 1];
}
/*******************************************************************
* Trouver un sommet dans le graphe
********************************************************************
*Entrée : Le numéro du sommet à trouver
*Sortie : Csommet * 
*Entraîne : Return le sommet à trouver dans le graphe
********************************************************************/
Csommet* Cgraphe::GRATrouverSommet(unsigned int uiArg)
{
	int iBoucle = 0;
	int indice = -1;
	//cherche dans le tableau le sommet avec le bon numero

	while (iBoucle < this->stTailleTab)
	{
		if (this->psGRATab[iBoucle]->SOMNumSommet() == uiArg) {
			indice = iBoucle;
		}
		iBoucle++;
	}

	if (indice != -1 && this->psGRATab[indice]->SOMNumSommet() == uiArg)
	{
		return this->psGRATab[indice];
	}
	else
	{
		return nullptr;
	}
}