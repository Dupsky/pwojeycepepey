#include "Cgraphe.h"
#include "Cexception.h"
#include <iostream>



Cgraphe::Cgraphe()
{
	this->pGRATab = nullptr;
	this->stTailleTab = 0;
}

void Cgraphe::addSommet(Csommet sommet)
{
	for (int i = 0; i < this->stTailleTab; i++)
	{
		if (this->pGRATab[i].AfficherNum()==sommet.AfficherNum())
		{
			CException EXCObj;
			EXCObj.EXCset(sommetPresent);
			throw(EXCObj);
		}
	}

	Csommet* temp = (Csommet*)realloc(this->pGRATab, (size_t)sizeof(this->pGRATab) + (size_t)sizeof(sommet));
	if (temp != nullptr)
	{
		CException EXCObj;
		EXCObj.EXCset(reallocImpo);
		throw(EXCObj);
	}
	else {
		this->pGRATab = temp;
	}
	
	if (this->pGRATab != nullptr) this->pGRATab[this->stTailleTab] = sommet;
	stTailleTab++;
}

void Cgraphe::AfficherGraph()
{
	int pos=0;
	std::cout << "Liste des sommets du graphique et leurs arcs partant" << std::endl;
	for (pos; pos < this->stTailleTab; pos++) {
		std::cout << "Sommet " << this->pGRATab->AfficherNum() << ": ";
		this->pGRATab->AfficherArcsPartant();
		std::cout << std::endl;
		++this->pGRATab;
	}
}

void Cgraphe::InverserGraph()
{
	for (int i = 0; i < this->stTailleTab; i++)
	{
		for (int j = 0; j < this->stTailleTab; j++)
		{
			if (j > i) {
				this->pGRATab[i].SwitchLink(this->pGRATab[j]);
			}
		}
	}
}

size_t Cgraphe::tailleTab()
{
	return this->stTailleTab;
}

void Cgraphe::SuppSommetIndex(int iArg)
{

}

void Cgraphe::SuppSommetNum(int iArg)
{
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

}