
#include <iostream>
#include <stdio.h>
#include <string>
#include <fstream>

#include "Cparser.h"
#include "CGraphe.h"



Cparser::Cparser(const char* cNomfichier)
{
	this->cNomfichier = cNomfichier;
}

void Cparser::PARLireFichier(Cgraphe* pGRAArg)
{


	std::ifstream MonFichier(this->cNomfichier);

	int iNumLigne = 0;
	int iNBSommets = 0;
	int iNBArcs = 0;


	if (MonFichier) {
		std::string ligne;
		while (std::getline(MonFichier, ligne))
		{
			iNumLigne++;

			size_t size = ligne.size() + 1;
			char* buffer = new char[size];
			strncpy_s(buffer, size, ligne.c_str(), size);

			//on enleve de notre buffer la partie 'variable = '
			if (iNumLigne <= 3) {
				while (*buffer != '=') {
					buffer++;
				}
				buffer++;
			}
			//on assigne la valeur
			switch (iNumLigne) {
			case 1: //nombre de sommet

				iNBSommets = atoi(buffer);

				break;
			case 2: //nombre d'arc

				iNBArcs = atoi(buffer);

				break;
			case 3: //création des sommets avec leur numero

				std::getline(MonFichier, ligne);

				size = ligne.size() + 1;
				buffer = new char[size];

				strncpy_s(buffer, size, ligne.c_str(), size);

				for (int iBoucle = 0; iBoucle < iNBSommets; iBoucle++) {
					//on enleve de notre buffer la partie 'variable = '
					while (*buffer != '=') {
						buffer++;
					}
					buffer++;

					pGRAArg->GRACreerSommet(atoi(buffer));


					//on va a la ligne suivante i+1 fois
					std::getline(MonFichier, ligne);

					size = ligne.size() + 1;
					buffer = new char[size];

					strncpy_s(buffer, size, ligne.c_str(), size);
					if (*buffer != ']' && iBoucle == iNBSommets - 1) {

						std::cout << "il y a trop de sommets renseigne comparer a NBSommet" << std::endl;
						CException EXCObj;
						EXCObj.EXCset(tropDeSommets);
						throw(EXCObj);

					}
					else if (*buffer == ']' && iBoucle < iNBSommets - 1) {

						std::cout << "il y a trop de sommets renseigne comparer a NBSommet" << std::endl;
						CException EXCObj;
						EXCObj.EXCset(peuDeSommets);
						throw(EXCObj);

					}
				}

				break;


			case 4: //création des arcs entre les sommets

				//ligne suivante
				std::getline(MonFichier, ligne);

				size = ligne.size() + 1;
				buffer = new char[size];


				strncpy_s(buffer, size, ligne.c_str(), size);

				for (int iBoucle2 = 0; iBoucle2 < iNBArcs; iBoucle2++) {


					//on enleve de notre buffer la partie 'variable = '
					while (*buffer != '=') {
						buffer++;
					}
					buffer++;

					//on recupere le premier numero dans buffer2

					char* buffer2 = new char[10];
					int indiceNumero = 0;



					while (*buffer != ',') {
						buffer2[indiceNumero] = *buffer;
						indiceNumero++;
						buffer++;
					}
					int iNumSommet1 = atoi(buffer2);


					//on enleve de notre buffer la partie ', variable = '
					while (*buffer != '=') {
						buffer++;
					}
					buffer++;

					int iNumSommet2 = atoi(buffer);

					//on link les 2 sommets
					try {
						Csommet* pSOMsommet1 = pGRAArg->GRATrouverSommet(iNumSommet1);
						Csommet* pSOMsommet2 = pGRAArg->GRATrouverSommet(iNumSommet2);


						pSOMsommet1->SOMLink(pSOMsommet2);
					}
					catch (CException EXCLevee) {
						std::cout << "une exception a ete levee, numero " << EXCLevee.EXCget() << "\n" << std::endl;
					}


					//on va a la ligne suivante i+1 fois
					std::getline(MonFichier, ligne);

					size = ligne.size() + 1;
					buffer = new char[size];

					strncpy_s(buffer, size, ligne.c_str(), size);
					if (*buffer != ']' && iBoucle2 == iNBArcs - 1) {

						std::cout << "il y a trop d'arc renseigne comparer a NBArcs" << std::endl;
						CException EXCObj;
						EXCObj.EXCset(tropDArc);
						throw(EXCObj);

					}
					else if (*buffer == ']' && iBoucle2 < iNBArcs - 1) {

						std::cout << "il y a trop peu d'arc renseigne comparer a NBArcs" << std::endl;
						CException EXCObj;
						EXCObj.EXCset(peuDArc);
						throw(EXCObj);

					}
				}

				break;

			case 5: //sommets clique ?

				//ligne suivante
				std::getline(MonFichier, ligne);
				size = ligne.size() + 1;
				buffer = new char[size];
				strncpy_s(buffer, size, ligne.c_str(), size);

				//on enleve de notre buffer la partie 'variable = '
				while (*buffer != '=') {
					buffer++;
				}
				buffer++;


				//on recupere les numeros des sommets de la potentiel clique

				unsigned int piListeSommets[20];
				size_t iNbrSommetsClique = 0;

				while (*buffer != '\0')
				{

					char* buffer2 = new char[10];
					int indiceNumero = 0;

					//on capture chaque numero separé par un espace
					while (*buffer != ' ' && *buffer != '\0') {
						buffer2[indiceNumero] = *buffer;
						indiceNumero++;
						buffer++;
					}
					int num = atoi(buffer2);
					piListeSommets[iNbrSommetsClique] = num;
					iNbrSommetsClique++;

					if (*buffer != '\0') {
						buffer++;
					}
				}
				try {
					if (pGRAArg->GRAIsClique(piListeSommets, iNbrSommetsClique)) { //le sous graphe est une clique 
						std::cout << "Le sous graphe";
						for (int i = 0; i < iNbrSommetsClique; i++) {
							std::cout << " " << piListeSommets[i];
						}
						std::cout << " est une clique \n" << std::endl;
					}
					else
					{
						std::cout << "Le sous graphe";
						for (int i = 0; i < iNbrSommetsClique; i++) {
							std::cout << " " << piListeSommets[i];
						}
						std::cout << " n'est pas une clique \n" << std::endl;
					}
				}
				catch (CException EXCLevee) {
					std::cout << "une exception a ete levee, numero " << EXCLevee.EXCget() << "\n" << std::endl;
				}
				break;
			}
		}
	}
	else
	{
		CException EXCObj;
		EXCObj.EXCset(ouvertureFichier);
		throw(EXCObj);
	}
}

