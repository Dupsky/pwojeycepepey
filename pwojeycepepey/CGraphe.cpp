#include "Cgraphe.h"
#include "Cexception.h"
#include <iostream>



Cgraphe::Cgraphe()
{
	this->pGRATab = nullptr;
	this->stTailleTab = 0;
}

Cgraphe::~Cgraphe()
{
	delete[] this->pGRATab;
}

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

	Csommet** temp = (Csommet**)realloc(this->pGRATab, (size_t)sizeof(this->pGRATab) + (size_t)sizeof(sommet));
	if (temp == nullptr)
	{
		CException EXCObj;
		EXCObj.EXCset(reallocImpo);
		throw(EXCObj);
	}
	else {
		this->pGRATab = temp;
	}
	
	if (this->pGRATab != nullptr) this->pGRATab[this->tailleTab()] = sommet;
	stTailleTab++;
}

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

void Cgraphe::InverserGraph()
{
	for (int i = 0; i < this->stTailleTab; i++)
	{
		for (int j = 0; j < this->stTailleTab; j++)
		{
			if (j > i) {
				this->pGRATab[i]->SwitchLink(*this->pGRATab[j]);
			}
		}
	}
}

size_t Cgraphe::tailleTab()
{
	return this->stTailleTab;
}

void Cgraphe::SuppSommetIndex(unsigned int iArg)
{

}

void Cgraphe::SuppSommetNum(unsigned int iArg)
{/*
	int iTemp = 0;
	for (int i = 0; i < this->stTailleTab; i++)
	{
		if (this->pGRATab[i].AfficherNum() == iArg)
		{
			iTemp++;
		}
	}
	if (iTemp == 0) {
		CException EXCObj;
		EXCObj.EXCset(sommetNonPresent);
		throw(EXCObj);
	}
	for (int i = 0; i < this->stTailleTab; i++)
	{

		if (this->pGRATab[i].AfficherNum() == iArg) {
			for (int j = i+1; j < this->stTailleTab; j++)
			{
				this->pGRATab[i] = this->pGRATab[j];
				i++;
			}
		}
	}
	
	Csommet* temp = (Csommet*)realloc(this->pGRATab, (size_t)sizeof(this->pGRATab) - (size_t)sizeof(Csommet));
	if (temp != nullptr || this->stTailleTab == 1)
	{
		CException EXCObj;
		EXCObj.EXCset(reallocImpo);
		throw(EXCObj);
	}
	else {
		this->pGRATab = temp;
	}
*/
}

void Cgraphe::createSommet(unsigned int uiArg)
{
	Csommet * sommet =new Csommet(uiArg);

	this->addSommet(sommet);
}

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




size_t Cgraphe::sizeofgraph()
{
	return sizeof(this->pGRATab);
}