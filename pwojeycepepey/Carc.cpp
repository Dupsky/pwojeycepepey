#include "Carc.h"

/*******************************************************************
* Constructeur par d�faut
********************************************************************
*Entr�e : 
*Sortie :void
*Entra�ne : Cr�e un objet de la classe Carc
********************************************************************/
Carc::Carc() {
	this->uiDest = 0;
}
/*******************************************************************
* Constructeur de la classe Carc
********************************************************************
*Entr�e : num�ro de l'arc � cr�er
*Sortie :void
*Entra�ne : Cr�e un objet de la classe Carc avec comme destination uiDest
********************************************************************/
Carc::Carc(unsigned int uiDest) {
	this->uiDest = uiDest;
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
* Modifier la uiDest d'un arc
********************************************************************
*Entr�e : uiArg la uiDest � prendre
*Sortie :void
*Entra�ne : Modifie la uiDest d'un arc
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
* R�cuperer la uiDest d'un arc
********************************************************************
*Entr�e :
*Sortie : unsigned int 
*Entra�ne : Return la destination d'un arc
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