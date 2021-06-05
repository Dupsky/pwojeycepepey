
#include <iostream>
#include "Carc.h"
#include "CSommet.h"
#include "Cgraphe.h"
#include "Cparser.h"
#include "Cexception.h"

int main(int argc, char* argv[])
{

    Cparser Fichier("test.txt");
    Cgraphe* graphe1 = new Cgraphe();
  
    Fichier.PARLireFichier(graphe1);
    graphe1->GRAAfficherGraph();

    unsigned int TAB[3] = { 1,2,3};

    std::cout << graphe1->clique(TAB,3) << std::endl;


    /*if (argc == 1) {
        std::cout << "aucun fichier en argument" << std::endl;
        return 0;
    }
    else if (argc > 2) {
        std::cout << "le programme ne prend qu'un seul argument" << std::endl;
        return 0;
    }

    Cparser Fichier(argv[1]);
    Cgraphe* graphe1 = new Cgraphe();
    try {
        Fichier.PARLireFichier(graphe1);

    std::cout << "\ngraphique a partir du fichier :\n" << std::endl;
    graphe1->GRAAfficherGraph();

    graphe1->GRAInverserGraph();

    std::cout << "\ngraphique apres l'inversion :\n" << std::endl;
    graphe1->GRAAfficherGraph();

    return 1;
    }
    catch (CException EXCLevee) {
        std::cout << "une exception a ete levee, numero " << EXCLevee.EXCget() << "\n" << std::endl;
    }*/

}

