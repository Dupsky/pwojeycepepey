
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
    try {
        Fichier.PARLireFichier(graphe1);
    }
    catch (CException EXCLevee) {
        std::cout << "une exception a ete levee, numero " << EXCLevee.EXCget() << "\n" << std::endl;
    }
    graphe1->GRAAfficherGraph();


    /*Cgraphe* graphe1 = new Cgraphe();

    graphe1->GRACreerSommet(1);
    graphe1->GRACreerSommet(2);
    graphe1->GRACreerSommet(3);

    graphe1->GRATrouverSommet(1)->SOMLink(graphe1->GRATrouverSommet(2));
    graphe1->GRATrouverSommet(2)->SOMLink(graphe1->GRATrouverSommet(3));
    graphe1->GRATrouverSommet(1)->SOMLink(graphe1->GRATrouverSommet(3));

    std::cout << "voici le premier graphe sur lequel nous allons faire un test" << std::endl;
    graphe1->GRAAfficherGraph();

    std::cout << "voici le premier graphe sur lequel nous allons faire un test" << std::endl;
    unsigned int TAB[3] = {1,2,3};
    try {
        std::cout << graphe1->GRAIsClique(TAB, (sizeof(TAB) / sizeof(TAB[0]))) << std::endl;
    }
    catch (CException EXCLevee) {
        std::cout << "une exception a ete levee, numero " << EXCLevee.EXCget() << "\n" << std::endl;
    }
    */

}

