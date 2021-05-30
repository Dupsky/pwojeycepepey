#include "CSommet.h"
#include <malloc.h>
#include <cstdlib>
#include <iostream>
#include <iterator>

using std::size;

/*******************************************************************
* Constructeur par défaut
********************************************************************
*Entrée :
*Sortie :void
*Entraîne : Crée un objet de la classe Csommet
********************************************************************/

Csommet::Csommet()
{
	this->uiSOMNumSom=0;
	this->paSOMPartant=nullptr;
	this->paSOMArrivant=nullptr;
	this->iSOMNbArrivant = 0;
	this->iSOMNbPartant = 0;
}

/*******************************************************************
* Destructeur par défaut
********************************************************************
*Entrée :
*Sortie :void
*Entraîne : Détruit un objet de la classe Csommet
********************************************************************/
Csommet::~Csommet()
{

	delete[] this->paSOMPartant;
	delete[] this->paSOMArrivant;
}
/*******************************************************************
* Récupérer le numéro du sommet
********************************************************************
*Entrée :
*Sortie :unsigned int le numéro du sommet
*Entraîne : Return le numéro du sommet pointé
********************************************************************/
unsigned int Csommet::SOMNumSommet()
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

void Csommet::SOMAfficherArcsPartant()
{
	int iBoucle = 0;

	while (iBoucle < this->iSOMNbPartant)
	{
		std::cout << this->uiSOMNumSom << "->" << this->paSOMPartant[iBoucle]->ARCDest() << " ; ";
		iBoucle++;
	}

}


/*******************************************************************
* Constructeur avec numéro du sommet 
********************************************************************
*Entrée : unsigned int le numéro de sommet voulu
*Sortie :void
*Entraîne : Créer un objet de la classe Csommet avec comme numéro de 
*			sommet uiArg
********************************************************************/
Csommet::Csommet(unsigned int uiArg)
{
	this->uiSOMNumSom = uiArg;
	this->paSOMPartant = nullptr;
	this->paSOMArrivant = nullptr;
	this->iSOMNbArrivant = 0;
	this->iSOMNbPartant = 0;
}

/*******************************************************************
* Lier deux sommets
********************************************************************
*Entrée : Csommet * sommet le sommet à l'arrivée
*Sortie : void
*Entraîne : Lie deux sommet avec des arcs, l'objet pointé sera le départ
*			et l'objet en argument sera l'arrivée
********************************************************************/
void Csommet::SOMLink(Csommet * pSOMArg)
{
	if (this == nullptr) {
		CException EXCObj;
		EXCObj.EXCset(sommetNull);
		throw(EXCObj);
	}
	Carc* arc1 = new Carc(pSOMArg->SOMNumSommet());
	Carc* arc2 = new Carc(this->SOMNumSommet());

	this->SOMArcPartant(arc1);

	pSOMArg->SOMArcArrivant(arc2);

}

/*******************************************************************
* délier deux sommet
********************************************************************
*Entrée : Csommet * sommet le sommet à l'arrivée
*Sortie : void
*Entraîne : délie deux sommets 
********************************************************************/

void Csommet::SOMUnlink(Csommet* pSOMArg)
{

	if(this->SOMIsLink(pSOMArg)) { //il y a un lien de 1 vers 2

		//suppression arc dans le sommet 1 (partant avec destination = 2)
		this->SOMSuppArcPartant(this->SOMTrouverArcPartant(pSOMArg->SOMNumSommet()));

		//suppression arc dans le sommet 2 (arrivant avec destination = 1)
		pSOMArg->SOMSuppArcArrivant(pSOMArg->SOMTrouverArcArrivant(this->SOMNumSommet()));
	}
	else {
		std::cout << "Aucun lien entre le sommet " << this->uiSOMNumSom << " et le sommet" << pSOMArg->SOMNumSommet();
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

void Csommet::SOMSwitchLink(Csommet * pSOMArg)
{


	if (!pSOMArg->SOMIsLink(this) && this->SOMIsLink(pSOMArg)) {
		this->SOMUnlink(pSOMArg);
		pSOMArg->SOMLink(this);
	}
}



/*******************************************************************
* Trouver arc partant
********************************************************************
*Entrée : unsigned int la destination de l'arc à trouver
*Sortie : Carc * l'objet trouvé
*Entraîne : Return l'arc avec uiDest comme destination dans la liste 
*			des arcs partant
********************************************************************/

Carc* Csommet::SOMTrouverArcPartant(unsigned int uiDest)
{
	int iBoucle = 0;
	int iIndice = -1;
	//cherche dans le tableau arc partant l'arc avec la bonne destination

	while (iBoucle < this->iSOMNbPartant)
	{
		if (this->paSOMPartant[iBoucle]->ARCDest() == uiDest) {
			iIndice = iBoucle;
		}
		iBoucle++;
	}

	if (iIndice != -1 && this->paSOMPartant[iIndice]->ARCDest() == uiDest)
	{
		return this->paSOMPartant[iIndice];
	}
	else
	{
		CException EXCObj;
		EXCObj.EXCset(arcNonPresent);
		throw(EXCObj);
	}
}

/*******************************************************************
* Trouver arc Arrivant
********************************************************************
*Entrée : unsigned int la destination de l'arc à trouver
*Sortie : Carc * l'objet trouvé
*Entraîne : Return l'arc avec uiDest comme destination dans la liste
*			des arcs arrivants
********************************************************************/

Carc* Csommet::SOMTrouverArcArrivant(unsigned int uiDest)
{
	int iBoucle = 0;
	int iIndice = -1;
	//cherche dans le tableau arc partant l'arc avec la bonne destination

	while (iBoucle < this->iSOMNbArrivant)
	{
		if (this->paSOMArrivant[iBoucle]->ARCDest() == uiDest) {
			iIndice = iBoucle;
		}
		iBoucle++;
	}

	if (iIndice != -1 && this->paSOMArrivant[iIndice]->ARCDest() == uiDest)
	{
		return this->paSOMArrivant[iIndice];
	}
	else
	{
		CException EXCObj;
		EXCObj.EXCset(arcNonPresent);
		throw(EXCObj);
	}
}

/*******************************************************************
* Deux sommet sont ils liés
********************************************************************
*Entrée : Csommet * sommet le sommet à l'arrivée
*Sortie : int 1 si les sommets sont lié 0 sinon
*Entraîne : la recherche d'un lien entre 2 sommets
********************************************************************/

int Csommet::SOMIsLink(Csommet * pSOMArg)
{
	try {
		if (this->SOMTrouverArcPartant(pSOMArg->SOMNumSommet()) != nullptr) {
			return 1;
		}
		else
		{
			return 0;
		}
	}
	catch (CException EXCLevee) {
		std::cout << "une exception a ete levee, numero " << EXCLevee.EXCget() << std::endl;
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
	int iBoucle = 0;
	while(iBoucle < this->iSOMNbArrivant)
	{
		this->paSOMArrivant[iBoucle]->ARCModifDest(uiArg);
		iBoucle++;
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
void Csommet::SOMArcArrivant(Carc *pARCArg)
{

	Carc** pARCtmp = (Carc**) realloc (this->paSOMArrivant, ((size_t)this->SOMTailleArrivant() + 1) * (size_t)sizeof(pARCArg));
	if (pARCtmp != nullptr) {
		this->paSOMArrivant = pARCtmp;
	}
	
	this->paSOMArrivant[this->SOMTailleArrivant()] = pARCArg;
	this->iSOMNbArrivant++;
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
void Csommet::SOMArcPartant(Carc *pARCArg)
{

	
		Carc** pARCtmp = (Carc**)realloc(this->paSOMPartant, ((size_t)this->SOMTaillePartant() + 1) * (size_t)sizeof(pARCArg));
		if (pARCtmp != nullptr)
		{
			this->paSOMPartant = pARCtmp;
		}
	
	this->paSOMPartant[this->SOMTaillePartant()] = pARCArg;
	this->iSOMNbPartant++;
}

/*******************************************************************
* Récupération de la taille du tableau Arrivant
********************************************************************
*Entrée : L'objet pointé est de la classe Csommet
*Sortie : int La taille du tableau arrivant
*Entraîne : La récuperation de la taille du tableau de arrivant de
*			l'objet pointé
********************************************************************/
int Csommet::SOMTailleArrivant()
{
	return this->iSOMNbArrivant;
}

/*******************************************************************
* Récupération de la taille du tableau Partant
********************************************************************
*Entrée : L'objet pointé est de la classe Csommet
*Sortie : int La taille du tableau partant
*Entraîne : La récuperation de las taille du tableau de partant de
*			l'objet pointé
********************************************************************/
int Csommet::SOMTaillePartant()
{
	return this->iSOMNbPartant;
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
void Csommet::SOMSuppArcArrivant(Carc * pARCArg)
{
	Carc** pARCtmp = this->paSOMArrivant;
	int iBoucle = 0;
	int iIndice = -1;
	int temp_taille = this->iSOMNbArrivant;

	while (iBoucle < temp_taille) {
		if (this->paSOMArrivant[iBoucle] == pARCArg) {
			iIndice = iBoucle;
		}
		iBoucle++;
	}

	if (iIndice != -1) { //element bien présent 

		while (iIndice < temp_taille) {
			pARCtmp[iIndice] = pARCtmp[iIndice + 1];
			iIndice++;
		}

		pARCtmp = (Carc**)realloc(this->paSOMArrivant, ((size_t)this->SOMTailleArrivant() - 1) * (size_t)sizeof(pARCArg));


		if (pARCtmp != nullptr || this->iSOMNbArrivant == 1) {
			this->paSOMArrivant = pARCtmp;
			this->iSOMNbArrivant--;
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
void Csommet::SOMSuppArcPartant(Carc* pARCArg)
{
	Carc** pARCtmp = this->paSOMPartant;
	int iBoucle = 0;
	int iIndice = -1;
	int temp_taille = this->iSOMNbPartant;

	while (iBoucle < temp_taille) {
		if (this->paSOMPartant[iBoucle] == pARCArg) {
			iIndice = iBoucle;
		}
		iBoucle++;
	}

	if (iIndice != -1) { //element bien présent 

		while (iIndice < temp_taille) {
			pARCtmp[iIndice] = pARCtmp[iIndice + 1];
			iIndice++;
		}

		pARCtmp = (Carc**)realloc(this->paSOMPartant, ((size_t)this->SOMTaillePartant()-1) * (size_t)sizeof(pARCArg));
		if (pARCtmp != nullptr || this->iSOMNbPartant == 1) {
			this->paSOMPartant = pARCtmp;
			this->iSOMNbPartant--;
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

void Csommet::SOMAfficherTabs() {
	int iBoucle = 0;
	
	std::cout << "Sommet n = " << this->SOMNumSommet() << " :\n-> :" << std::endl;

	while (iBoucle < this->iSOMNbPartant)
	{
		std::cout << "T[" << iBoucle << "] = " << this->paSOMPartant[iBoucle]->ARCDest() << std::endl;
		iBoucle++;
	}

	iBoucle = 0;

	std::cout << "\n<- :" << std::endl;

	while (iBoucle < this->iSOMNbArrivant)
	{
		std::cout << "T[" << iBoucle << "] = " << this->paSOMArrivant[iBoucle]->ARCDest() << std::endl;
		iBoucle++;
	}
	std::cout << std::endl;
}



