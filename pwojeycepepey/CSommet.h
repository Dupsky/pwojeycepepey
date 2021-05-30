#pragma once
#include "Carc.h"
#include "Cexception.h"
class Csommet
{
private:
	unsigned int uiSOMNumSom;
	Carc ** paSOMArrivant;
	Carc ** paSOMPartant;
	int iSOMNbArrivant;
	int iSOMNbPartant;
public:
	Csommet();
	Csommet(unsigned int uiArg);
	~Csommet();
	unsigned int SOMNumSommet();

	void SOMAfficherArcsPartant();

	void SOMLink(Csommet * pSOMArg);
	void SOMUnlink(Csommet * pSOMArg);

	Carc* SOMTrouverArcPartant(unsigned int uiDest);
	Carc* SOMTrouverArcArrivant(unsigned int uiDest);

	int SOMIsLink(Csommet * pSOMArg);

	void SOMModifierNum(unsigned int uiArg);

	void SOMArcArrivant(Carc * pARCArg);
	void SOMArcPartant(Carc * pARCArg);

	void SOMSuppArcPartant(Carc* pARCArg);
	void SOMSuppArcArrivant(Carc* pARCArg);

	int SOMTailleArrivant();
	int SOMTaillePartant();

	void SOMAfficherTabs();
	void SOMSwitchLink(Csommet * pSOMArg);
};

///////////erreurs///////////////

#define sommetNull 10 
#define SOMarcNull 11
#define arcNonPresent 12
#define reallocSommet 13
#define arcDejaPresent 14