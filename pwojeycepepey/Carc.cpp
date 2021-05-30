#include "Carc.h"

/*******************************************************************
* Constructeur par défaut
********************************************************************
*Entrée : 
*Sortie :void
*Entraîne : Crée un objet de la classe Carc
********************************************************************/
Carc::Carc() {
	this->destination = 0;
}
/*******************************************************************
* Constructeur de la classe Carc
********************************************************************
*Entrée : numéro de l'arc à créer
*Sortie :void
*Entraîne : Crée un objet de la classe Carc avec comme destination uiDest
********************************************************************/
Carc::Carc(unsigned int uiDest) {
	this->destination = uiDest;
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
* Modifier la destination d'un arc
********************************************************************
*Entrée : uiArg la destination à prendre
*Sortie :void
*Entraîne : Modifie la destination d'un arc
********************************************************************/
void Carc::ARCModifDest(unsigned int uiArg) {
	this->destination = uiArg;
}
/*******************************************************************
* Récuperer la destination d'un arc
********************************************************************
*Entrée :
*Sortie : unsigned int 
*Entraîne : Return la destination d'un arc
********************************************************************/
unsigned int Carc::getDest()
{
	return this->destination;
}