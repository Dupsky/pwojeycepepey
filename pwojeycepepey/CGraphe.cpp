#include "Cgraphe.h"
#include <iostream>

Cgraphe::Cgraphe()
{
	this->pGRATab = nullptr;
	this->stTailleTab = 0;
}

void Cgraphe::addSommet(Csommet sommet)
{
	this->pGRATab = (Csommet*)realloc(this->pGRATab, sizeof(this->pGRATab) * sizeof(sommet));
	this->pGRATab[this->stTailleTab] = sommet;
	stTailleTab++;
}

void Cgraphe::AfficherGraph()
{
	//int pos=0;
	std::cout << "Liste des sommets du graphique et leurs arcs partant" << std::endl;
	while (this->pGRATab != nullptr) {
		std::cout << "Sommet " << this->pGRATab->AfficherNum() << ":";
		this->pGRATab->AfficherArcsPartant();
		std::cout << std::endl;
		++this->pGRATab;
	}
}

/*size_t Cgraphe::tailleTab()
{
	return (sizeof(this->pGRATab) / sizeof(Csommet));
}
*/