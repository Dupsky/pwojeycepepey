
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

					Csommet* pSOMsommet1 = pGRAArg->GRATrouverSommet(iNumSommet1);
					Csommet* pSOMsommet2 = pGRAArg->GRATrouverSommet(iNumSommet2);


					pSOMsommet1->SOMLink(pSOMsommet2);

					

					//on va a la ligne suivante i+1 fois
					std::getline(MonFichier, ligne);

					size = ligne.size() + 1;
					buffer = new char[size];

					strncpy_s(buffer, size, ligne.c_str(), size);
				}

				break;
			}
		}
	}
	else
	{
	std::cout << "erreur ouverture fichier" << std::endl;
	}
}

