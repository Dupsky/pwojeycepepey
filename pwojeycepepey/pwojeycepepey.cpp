
#include <iostream>
#include "Carc.h"
#include "CSommet.h"
#include "Cgraphe.h"
#include "Cparser.h"
#include "Cexception.h"

int main(int argc, char* argv[])
{
    /*
    if (argc == 1) {
        std::cout << "aucun fichier en argument" << std::endl;
        return 0;
    }

    Cparser Fichier(argv[1]);
    Cgraphe* graphe1 = new Cgraphe();

    Fichier.PARLireFichier(graphe1);

    std::cout << "\ngraphique a partir du fichier :\n" << std::endl;
    graphe1->GRAAfficherGraph();

    graphe1->GRAInverserGraph();

    std::cout << "\ngraphique apres l'inversion :\n" << std::endl;
    graphe1->GRAAfficherGraph();

    return 1;
    */
    Csommet* sommet1 = new Csommet(1);
    Csommet* sommet2 = new Csommet(2);
    try {
        sommet1->SOMTrouverArcArrivant(1);
    }
    catch (CException EXCLevee) {
        std::cout << "une exception a ete levee, numero " << EXCLevee.EXCget() << std::endl;
    }
}

