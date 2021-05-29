
#include <iostream>
#include "Carc.h"
#include "CSommet.h"
#include "Cgraphe.h"
#include "Cparser.h"

int main()
{
    /*Cparser Fichier("test.txt");
    Cgraphe* graphe1 = new Cgraphe();

    Fichier.LireFichier(graphe1);

    graphe1->AfficherGraph();*/
    
    Cgraphe graphe1 = Cgraphe();
    graphe1.createSommet(1);
    graphe1.createSommet(2);
    graphe1.createSommet(3);
    graphe1.createSommet(4);

    graphe1.AfficherGraph();

}

