
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

void Cparser::LireFichier(Cgraphe* graphe)
{


	std::ifstream MonFichier(this->cNomfichier);

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
			case 3: //cr�ation des sommets avec leur numero

				std::getline(MonFichier, ligne);

				size = ligne.size() + 1;
				buffer = new char[size];

				strncpy_s(buffer, size, ligne.c_str(), size);

				for (int i = 0; i < NBSommets; i++) {

					if (i == 4) {
						std::cout << "coucou" << std::endl;
					}

					//on enleve de notre buffer la partie 'variable = '
					while (*buffer != '=') {
						buffer++;
					}
					buffer++;

					if (i == 3) {
						std::cout << "sizeof tabgraph" << std::endl;
					}
					

					graphe->createSommet(atoi(buffer));



					graphe->AfficherGraph();

					//on va a la ligne suivante i+1 fois
					std::getline(MonFichier, ligne);

					size = ligne.size() + 1;
					buffer = new char[size];

					strncpy_s(buffer, size, ligne.c_str(), size);
					std::cout << " buffer : " << buffer << std::endl;
				}

				break;


			case 4: //cr�ation des arcs entre les sommets

				std::cout << buffer << std::endl;

				//ligne suivante
				std::getline(MonFichier, ligne);

				size = ligne.size() + 1;
				buffer = new char[size];


				strncpy_s(buffer, size, ligne.c_str(), size);

				for (int j = 0; j < NBArcs; j++) {

					std::cout  << " buffer : " << buffer << std::endl;

					//on enleve de notre buffer la partie 'variable = '
					while (*buffer != '=') {
						buffer++;
					}
					buffer++;

					//on recupere le premier numero dans buffer2

					char* buffer2 = new char[10];
					int indiceNumero = 0;



					while (*buffer != ',') {
						std::cout << "incide : " << indiceNumero << " et buffer : " << buffer << std::endl;
						buffer2[indiceNumero] = *buffer;
						indiceNumero++;
						buffer++;
					}
					int numsommet1 = atoi(buffer2);
		

					//on enleve de notre buffer la partie ', variable = '
					while (*buffer != '=') {
						buffer++;
					}
					buffer++;

					int numsommet2 = atoi(buffer);

					//on link les 2 sommets

					Csommet* sommet1 = graphe->TrouverSommet(numsommet1);
					Csommet* sommet2 = graphe->TrouverSommet(numsommet2);

					std::cout << "lien entre sommet " << numsommet1 << " et sommet " << numsommet2 << std::endl;

					sommet1->link(*sommet2);

					

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
}
