#include "CSommet.h"
#include <malloc.h>
#include <cstdlib>
#include <iostream>
#include <iterator>

using std::size;

/*******************************************************************
* Constructeur par d�faut
********************************************************************
*Entr�e :
*Sortie :void
*Entra�ne : Cr�e un objet de la classe Csommet
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
* Destructeur par d�faut
********************************************************************
*Entr�e :
*Sortie :void
*Entra�ne : D�truit un objet de la classe Csommet
********************************************************************/
Csommet::~Csommet()
{

	delete[] this->paSOMPartant;
	delete[] this->paSOMArrivant;
}
/*******************************************************************
* R�cup�rer le num�ro du sommet
********************************************************************
*Entr�e :
*Sortie :unsigned int le num�ro du sommet
*Entra�ne : Return le num�ro du sommet point�
********************************************************************/
unsigned int Csommet::SOMNumSommet()
{
	if (this == nullptr) {
		CException EXCObj;
		EXCObj.EXCset(sommetNull);
		throw(EXCObj);
	}
	return this->uiSOMNumSom;
}


/*******************************************************************
*  Affichage des arcs partant du sommet
********************************************************************
*Entr�e : L'objet point� est de la classe Csommet
*Sortie : void
*Entra�ne : Affichages des arcs partant du sommet
********************************************************************/

void Csommet::SOMAfficherArcsPartant()
{
	int iBoucle = 0;

	while (iBoucle < this->iSOMNbPartant)
	{
		try {
			std::cout << this->uiSOMNumSom << "->" << this->paSOMPartant[iBoucle]->ARCDest() << " ; ";
			iBoucle++;
		}
		catch (CException EXCLevee) {
			std::cout << "une exception a ete levee, numero " << EXCLevee.EXCget() << "\n" << std::endl;
		}
	}

}


/*******************************************************************
* Constructeur avec num�ro du sommet 
********************************************************************
*Entr�e : unsigned int le num�ro de sommet voulu
*Sortie :void
*Entra�ne : Cr�er un objet de la classe Csommet avec comme num�ro de 
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
*Entr�e : Csommet * sommet le sommet � l'arriv�e
*Sortie : void
*Entra�ne : Lie deux sommet avec des arcs, l'objet point� sera le d�part
*			et l'objet en argument sera l'arriv�e
********************************************************************/
void Csommet::SOMLink(Csommet * pSOMArg)
{
	if (this == nullptr || pSOMArg == nullptr) {
		CException EXCObj;
		EXCObj.EXCset(sommetNull);
		throw(EXCObj);
	}
	if (this->SOMIsLink(pSOMArg)!=0)
	{
		std::cout << "L'arc est deja present dans le sommet " << this->SOMNumSommet() << " impossible de l'ajouter" << std::endl;
		CException EXCObj;
		EXCObj.EXCset(arcDejaPresent);
		throw(EXCObj);
	}
	try {
		Carc* arc1 = new Carc(pSOMArg->SOMNumSommet());
		Carc* arc2 = new Carc(this->SOMNumSommet());

		this->SOMArcPartant(arc1);



		pSOMArg->SOMArcArrivant(arc2);
	}
	catch (CException EXCLevee) {
		std::cout << "une exception a ete levee, numero " << EXCLevee.EXCget() << "\n" << std::endl;
	}
}

/*******************************************************************
* d�lier deux sommet
********************************************************************
*Entr�e : Csommet * sommet le sommet � l'arriv�e
*Sortie : void
*Entra�ne : d�lie deux sommets 
********************************************************************/

void Csommet::SOMUnlink(Csommet* pSOMArg)
{

	if(this->SOMIsLink(pSOMArg)) { //il y a un lien de 1 vers 2

		//suppression arc dans le sommet 1 (partant avec destination = 2)
		try {
			this->SOMSuppArcPartant(this->SOMTrouverArcPartant(pSOMArg->SOMNumSommet()));
		}
		catch (CException EXCLevee) {
			std::cout << "une exception a ete levee, numero " << EXCLevee.EXCget() << "\n" << std::endl;
		}
		//suppression arc dans le sommet 2 (arrivant avec destination = 1)
		try {
			pSOMArg->SOMSuppArcArrivant(pSOMArg->SOMTrouverArcArrivant(this->SOMNumSommet()));
		}
		catch (CException EXCLevee) {
			std::cout << "une exception a ete levee, numero " << EXCLevee.EXCget() << "\n" << std::endl;
		}
	}
	else {
		try {
			std::cout << "Aucun lien entre le sommet " << this->uiSOMNumSom << " et le sommet" << pSOMArg->SOMNumSommet();
		}
		catch (CException EXCLevee) {
			std::cout << "une exception a ete levee, numero " << EXCLevee.EXCget() << "\n" << std::endl;
		}
	}


}

/*******************************************************************
*  Inverse 2 sommets
********************************************************************
*Entr�e : L'objet point� est de la classe Csommet
*		  Un objet de la classe CSommet
*Sortie : void
*Entra�ne : L'inversion des deux arcs reliant les sommets
*			(uniquement l'arc partant de l'objet point�)
********************************************************************/

void Csommet::SOMSwitchLink(Csommet * pSOMArg)
{

	try {
		if (!pSOMArg->SOMIsLink(this) && this->SOMIsLink(pSOMArg)) {
			this->SOMUnlink(pSOMArg);
			pSOMArg->SOMLink(this);
		}
	}
	catch (CException EXCLevee) {
		std::cout << "une exception a ete levee, numero " << EXCLevee.EXCget() << "\n" << std::endl;
	}
}



/*******************************************************************
* Trouver arc partant
********************************************************************
*Entr�e : unsigned int la destination de l'arc � trouver
*Sortie : Carc * l'objet trouv�
*Entra�ne : Return l'arc avec uiDest comme destination dans la liste 
*			des arcs partant
*			Retourne nullptr si l'arc n'est pas pr�sent
********************************************************************/

Carc* Csommet::SOMTrouverArcPartant(unsigned int uiDest)
{
	int iBoucle = 0;
	int iIndice = -1;
	//cherche dans le tableau arc partant l'arc avec la bonne destination

	while (iBoucle < this->iSOMNbPartant)
	{
		try {
			if (this->paSOMPartant[iBoucle]->ARCDest() == uiDest) {
				iIndice = iBoucle;
			}
			iBoucle++;
		}
		catch (CException EXCLevee) {
			std::cout << "une exception a ete levee, numero " << EXCLevee.EXCget() << "\n" << std::endl;
		}
	}
	try {
		if (iIndice != -1 && this->paSOMPartant[iIndice]->ARCDest() == uiDest)
		{
			return this->paSOMPartant[iIndice];
		}
		else
		{
			return nullptr;
		}
	}
	catch (CException EXCLevee) {
		std::cout << "une exception a ete levee, numero " << EXCLevee.EXCget() << "\n" << std::endl;
	}
	return nullptr;
}

/*******************************************************************
* Trouver arc Arrivant
********************************************************************
*Entr�e : unsigned int la destination de l'arc � trouver
*Sortie : Carc * l'objet trouv�
*Entra�ne : Return l'arc avec uiDest comme destination dans la liste
*			des arcs arrivants
********************************************************************/

Carc* Csommet::SOMTrouverArcArrivant(unsigned int uiDest)
{
	int iBoucle = 0;
	int iIndice = -1;
	//cherche dans le tableau arc partant l'arc avec la bonne destination

	while (iBoucle < this->iSOMNbArrivant)
	{
		try {
			if (this->paSOMArrivant[iBoucle]->ARCDest() == uiDest) {
				iIndice = iBoucle;
			}
			iBoucle++;
		}
		catch (CException EXCLevee) {
			std::cout << "une exception a ete levee, numero " << EXCLevee.EXCget() << "\n" << std::endl;
		}
	}
	try {
		if (iIndice != -1 && this->paSOMArrivant[iIndice]->ARCDest() == uiDest)
		{
			return this->paSOMArrivant[iIndice];
		}
		else
		{
			return nullptr;
		}
	}
	catch (CException EXCLevee) {
		std::cout << "une exception a ete levee, numero " << EXCLevee.EXCget() << "\n" << std::endl;
	}
	return nullptr;
}

/*******************************************************************
* Deux sommet sont ils li�s
********************************************************************
*Entr�e : Csommet * sommet le sommet � l'arriv�e
*Sortie : int 1 si les sommets sont li� 0 sinon
*Entra�ne : la recherche d'un lien entre 2 sommets
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
		std::cout << "une exception a ete levee, numero " << EXCLevee.EXCget() << "\n" << std::endl;
	}
	return 0;

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
*Entr�e : L'objet point� est de type Csommet
*		  Un objet de la classe Carc
*Sortie : void
*Entra�ne : L'ajout de l'arc en argument dans la liste de arrivant de
*			l'objet point�
********************************************************************/
void Csommet::SOMArcArrivant(Carc *pARCArg)
{

	Carc** pARCtmp = (Carc**) realloc (this->paSOMArrivant, ((size_t)this->SOMTailleArrivant() + 1) * (size_t)sizeof(pARCArg));
	if (pARCtmp != nullptr) {
		this->paSOMArrivant = pARCtmp;
	}
	else
	{
		CException EXCObj;
		EXCObj.EXCset(reallocSommet);
		throw(EXCObj);
	}
	
	this->paSOMArrivant[this->SOMTailleArrivant()] = pARCArg;
	this->iSOMNbArrivant++;
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
void Csommet::SOMArcPartant(Carc *pARCArg)
{

	
		Carc** pARCtmp = (Carc**)realloc(this->paSOMPartant, ((size_t)this->SOMTaillePartant() + 1) * (size_t)sizeof(pARCArg));
		if (pARCtmp != nullptr)
		{
			this->paSOMPartant = pARCtmp;
		}
		else
		{
			CException EXCObj;
			EXCObj.EXCset(reallocSommet);
			throw(EXCObj);
		}
	
	this->paSOMPartant[this->SOMTaillePartant()] = pARCArg;
	this->iSOMNbPartant++;
}

/*******************************************************************
* R�cup�ration de la taille du tableau Arrivant
********************************************************************
*Entr�e : L'objet point� est de la classe Csommet
*Sortie : int La taille du tableau arrivant
*Entra�ne : La r�cuperation de la taille du tableau de arrivant de
*			l'objet point�
********************************************************************/
int Csommet::SOMTailleArrivant()
{
	return this->iSOMNbArrivant;
}

/*******************************************************************
* R�cup�ration de la taille du tableau Partant
********************************************************************
*Entr�e : L'objet point� est de la classe Csommet
*Sortie : int La taille du tableau partant
*Entra�ne : La r�cuperation de las taille du tableau de partant de
*			l'objet point�
********************************************************************/
int Csommet::SOMTaillePartant()
{
	return this->iSOMNbPartant;
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
void Csommet::SOMSuppArcArrivant(Carc * pARCArg)
{
	if (pARCArg == nullptr)
	{
		CException EXCObj;
		EXCObj.EXCset(SOMarcNull);
		throw(EXCObj);
	}
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

	if (iIndice != -1) { //element bien pr�sent 

		while (iIndice < temp_taille) {
			pARCtmp[iIndice] = pARCtmp[iIndice + 1];
			iIndice++;
		}

		pARCtmp = (Carc**)realloc(this->paSOMArrivant, ((size_t)this->SOMTailleArrivant() - 1) * (size_t)sizeof(pARCArg));


		if (pARCtmp != nullptr || this->iSOMNbArrivant == 1) {
			this->paSOMArrivant = pARCtmp;
			this->iSOMNbArrivant--;
		}
		else
		{
			CException EXCObj;
			EXCObj.EXCset(reallocSommet);
			throw(EXCObj);
		}
	}
	else {
		std::cout << "L'arc n'est pas present dans le sommet " << this->SOMNumSommet() << " impossible de le supprimer"<<std::endl;
		CException EXCObj;
		EXCObj.EXCset(arcNonPresent);
		throw(EXCObj);
	}

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
void Csommet::SOMSuppArcPartant(Carc* pARCArg)
{
	if (pARCArg == nullptr)
	{
		CException EXCObj;
		EXCObj.EXCset(SOMarcNull);
		throw(EXCObj);
	}
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

	if (iIndice != -1) { //element bien pr�sent 

		while (iIndice < temp_taille) {
			pARCtmp[iIndice] = pARCtmp[iIndice + 1];
			iIndice++;
		}

		pARCtmp = (Carc**)realloc(this->paSOMPartant, ((size_t)this->SOMTaillePartant()-1) * (size_t)sizeof(pARCArg));
		if (pARCtmp != nullptr || this->iSOMNbPartant == 1) {
			this->paSOMPartant = pARCtmp;
			this->iSOMNbPartant--;
		}
		else
		{
			CException EXCObj;
			EXCObj.EXCset(reallocSommet);
			throw(EXCObj);
		}
	}
	else {
		std::cout << "L'arc n'est pas present dans le sommet " << this->SOMNumSommet() << " impossible de le supprimer" << std::endl;
		CException EXCObj;
		EXCObj.EXCset(arcNonPresent);
		throw(EXCObj);
	}
}

/*******************************************************************
*  Affichage des 2 tableaux
********************************************************************
*Entr�e : L'objet point� est de la classe Csommet
*		  Un objet de la classe Carc
*Sortie : void
*Entra�ne : Affichages des valeurs des 2 tableaux du Csommet
********************************************************************/

void Csommet::SOMAfficherTabs() {
	int iBoucle = 0;
	try {
		std::cout << "Sommet n = " << this->SOMNumSommet() << " :\n-> :" << std::endl;
	}
	catch (CException EXCLevee) {
		std::cout << "une exception a ete levee, numero " << EXCLevee.EXCget() << "\n" << std::endl;
	}
	while (iBoucle < this->iSOMNbPartant)
	{
		try {
			std::cout << "T[" << iBoucle << "] = " << this->paSOMPartant[iBoucle]->ARCDest() << std::endl;
			iBoucle++;
		}
		catch (CException EXCLevee) {
			std::cout << "une exception a ete levee, numero " << EXCLevee.EXCget() << "\n" << std::endl;
		}
	}

	iBoucle = 0;

	std::cout << "\n<- :" << std::endl;

	while (iBoucle < this->iSOMNbArrivant)
	{
		try {
			std::cout << "T[" << iBoucle << "] = " << this->paSOMArrivant[iBoucle]->ARCDest() << std::endl;
			iBoucle++;
		}
		catch (CException EXCLevee) {
			std::cout << "une exception a ete levee, numero " << EXCLevee.EXCget() << "\n" << std::endl;
		}
	}
	std::cout << std::endl;
}



