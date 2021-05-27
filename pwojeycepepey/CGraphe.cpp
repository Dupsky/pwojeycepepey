#include "Cgraphe.h"
#include <iostream>

Cgraphe::Cgraphe()
{
	this->pGRATab = nullptr;
	this->stTailleTab = 0;
}

void Cgraphe::addSommet(Csommet sommet)
{
	Csommet* temp = (Csommet*)realloc(this->pGRATab, (size_t)sizeof(this->pGRATab) + (size_t)sizeof(sommet));
	if (temp != nullptr)
	{
		this->pGRATab = temp;
		
	}
	else {
		std::cerr << "erreur de réallocation" << std::endl;
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

/*size_t Cgraphe::tailleTab()
{
	return (sizeof(this->pGRATab) / sizeof(Csommet));
}
*/