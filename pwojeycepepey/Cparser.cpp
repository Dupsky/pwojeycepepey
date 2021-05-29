
#include <iostream>
#include <stdio.h>
#include <string>
#include <fstream>

#include "Cparser.h"
#include "CGraphe.h"


void Cparser::LireFichier(const char* cNomfichier)
{
	std::ifstream MonFichier(cNomfichier);

	int num_ligne = 0;
	int NBSommets = 0;
	int NBArcs = 0;


	if (MonFichier) {
		std::string ligne;
		while (std::getline(MonFichier, ligne))
		{
			num_ligne++;

			size_t size = ligne.size() + 1;
			char* buffer = new char[size];
			strncpy_s(buffer, size, ligne.c_str(), size);

			//on enleve de notre buffer la partie 'variable = '
			if (num_ligne <= 3) {
				while (*buffer != '=') {
					buffer++;
				}
				buffer++;
			}
			//on assigne la valeur
			switch (num_ligne) {
			case 1: //nombre de sommet

				NBSommets = atoi(buffer);
				
				break;
			case 2: //nombre d'arc

				NBArcs = atoi(buffer);

				break;
			case 3: //numero des sommets

				std::getline(MonFichier, ligne);
				num_ligne++;

				for (int i = 0; i < NBSommets; i++) {

					//on enleve de notre buffer la partie 'variable = '
					if (num_ligne <= 3) {
						while (*buffer != '=') {
							buffer++;
						}
						buffer++;
					}





					//on va a la ligne suivante i+1 fois
					std::getline(MonFichier, ligne);
					num_ligne++;


				}

				break;
			case 4: //debut et fin des arcs

				while (MonFichier >> buffer) {
					if (sTempColonne == this->sMATNbColonnes) { //derniere valeur de la ligne, il faut passer a la ligne suivante
						sTempColonne = 0;
						sTempLigne++;
					}
					if (sTempLigne < this->sMATNbLignes) {
						dTempValeur = std::atof(buffer);
						this->mMatrice[sTempLigne][sTempColonne] = dTempValeur;
						sTempColonne++;
					}
				}
				break;
			}
		}
	}
}