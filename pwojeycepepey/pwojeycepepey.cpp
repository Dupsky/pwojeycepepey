
#include <iostream>
#include "Carc.h"
#include "CSommet.h"
#include "Cgraphe.h"
#include "Cparser.h"

int main(int argc, char* argv[])
{
    if (argc == 1) {
        std::cout << "aucun fichier en argument" << std::endl;
        return 0;
    }

    Cparser Fichier(argv[1]);
    Cgraphe* graphe1 = new Cgraphe();

    Fichier.LireFichier(graphe1);

    std::cout << "\ngraphique a partir du fichier :\n" << std::endl;
    graphe1->AfficherGraph();

    graphe1->InverserGraph();

    std::cout << "\ngraphique apres l'inversion :\n" << std::endl;
    graphe1->AfficherGraph();

    return 1;
}

