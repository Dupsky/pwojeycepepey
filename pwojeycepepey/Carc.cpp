#include "Carc.h"

/*******************************************************************
* Constructeur par d�faut
********************************************************************
*Entr�e : 
*Sortie :void
*Entra�ne : Cr�e un objet de la classe Carc
********************************************************************/
Carc::Carc() {
	this->destination = 0;
}
/*******************************************************************
* Constructeur de la classe Carc
********************************************************************
*Entr�e : num�ro de l'arc � cr�er
*Sortie :void
*Entra�ne : Cr�e un objet de la classe Carc avec comme destination uiDest
********************************************************************/
Carc::Carc(unsigned int uiDest) {
	this->destination = uiDest;
}
/*******************************************************************
* Destructeur par d�faut
********************************************************************
*Entr�e :
*Sortie :void
*Entra�ne : D�truit un objet de la classe Carc
********************************************************************/
Carc::~Carc() {
}
/*******************************************************************
* Modifier la destination d'un arc
********************************************************************
*Entr�e : uiArg la destination � prendre
*Sortie :void
*Entra�ne : Modifie la destination d'un arc
********************************************************************/
void Carc::ARCModifDest(unsigned int uiArg) {
	this->destination = uiArg;
}
/*******************************************************************
* R�cuperer la destination d'un arc
********************************************************************
*Entr�e :
*Sortie : unsigned int 
*Entra�ne : Return la destination d'un arc
********************************************************************/
unsigned int Carc::getDest()
{
	return this->destination;
}