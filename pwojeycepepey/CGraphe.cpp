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
	this->psGRATab = nullptr;
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
	free(this->psGRATab);
}

/*******************************************************************
*  Ajouter un sommet au graphe
********************************************************************
*Entr�e : L'objet point� est de classe Cgraphe
*		  Csommet * sommet le sommet � ajouter au graph
*Sortie : void
*Entra�ne : Ajoute un sommet au graphe
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
*Entr�e :
*Sortie : void
*Entra�ne : Affiche le graphe 
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
*Entr�e :
*Sortie : void
*Entra�ne : inverse les arcs entre chaque sommet du graphe
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
*  R�cup�re la taille du graphe (du tableau de Csommet)
********************************************************************
*Entr�e :
*Sortie : void
*Entra�ne : Return la taille du tableau de Csommet du graphe
********************************************************************/
size_t Cgraphe::GRATailleTab()
{
	return this->stTailleTab;
}
/*******************************************************************
*  Supprime un sommet � partir de son index
********************************************************************
*Entr�e : Le num�ro du sommet
*Sortie : void
*Entra�ne : La suppression du sommet this->psGRATab[iArg]
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
* Suppression du sommet � partir de son num�ro 
********************************************************************
*Entr�e : Le num�ro du sommet � supprimer
*Sortie :void
*Entra�ne : Supprime le sommet num�ro iArg
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
* Cr�ation d'un nouveau sommet et ajout de ce dernier au graphe
********************************************************************
*Entr�e : Le num�ro du sommet � cr�er
*Sortie :void
*Entra�ne : Ajoute le nouveau sommet num�ro iArg au graphe
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
*Entr�e : Le num�ro du sommet � trouver
*Sortie : Csommet * 
*Entra�ne : Return le sommet � trouver dans le graphe
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