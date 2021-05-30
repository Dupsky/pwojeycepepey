#include "Carc.h"

/*******************************************************************
* Constructeur par défaut
********************************************************************
*Entrée : 
*Sortie :void
*Entraîne : Crée un objet de la classe Carc
********************************************************************/
Carc::Carc() {
	this->uiDest = 0;
}
/*******************************************************************
* Constructeur de la classe Carc
********************************************************************
*Entrée : numéro de l'arc à créer
*Sortie :void
*Entraîne : Crée un objet de la classe Carc avec comme destination uiDest
********************************************************************/
Carc::Carc(unsigned int uiDest) {
	this->uiDest = uiDest;
}
/*******************************************************************
* Destructeur par défaut
********************************************************************
*Entrée :
*Sortie :void
*Entraîne : Détruit un objet de la classe Carc
********************************************************************/
Carc::~Carc() {
}
/*******************************************************************
* Modifier la uiDest d'un arc
********************************************************************
*Entrée : uiArg la uiDest à prendre
*Sortie :void
*Entraîne : Modifie la uiDest d'un arc
********************************************************************/
void Carc::ARCModifDest(unsigned int uiArg) {
	try {
		this->ARCDest();
	}
	catch (CException EXCLevee) {
		std::cout << "une exception a ete levee, numero " << EXCLevee.EXCget() << "\n" << std::endl;
	}
	this->uiDest = uiArg;
}
/*******************************************************************
* Récuperer la uiDest d'un arc
********************************************************************
*Entrée :
*Sortie : unsigned int 
*Entraîne : Return la destination d'un arc
********************************************************************/
unsigned int Carc::ARCDest()
{
	if (this == nullptr)
	{
		CException EXCObj;
		EXCObj.EXCset(arcNull);
		throw(EXCObj);
	}
	return this->uiDest;
}