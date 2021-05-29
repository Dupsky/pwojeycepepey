
#include <iostream>
#include "Carc.h"
#include "CSommet.h"
#include "Cgraphe.h"
#include "Cparser.h"

int main()
{
    
    Cparser Fichier("test.txt");
    Cgraphe* graphe1 = new Cgraphe();

    Fichier.LireFichier(graphe1);

    graphe1->AfficherGraph();
    /*
    Cgraphe * graphe = new Cgraphe();

    graphe->createSommet(1);
    graphe->createSommet(2);
    graphe->createSommet(3);
    graphe->createSommet(4);
    graphe->createSommet(5);
   

    graphe->TrouverSommet(1)->link(graphe->TrouverSommet(2));
    graphe->TrouverSommet(2)->link(graphe->TrouverSommet(3));
    graphe->TrouverSommet(3)->link(graphe->TrouverSommet(2));
    graphe->TrouverSommet(1)->link(graphe->TrouverSommet(3));
    graphe->AfficherGraph();

    graphe->InverserGraph();

    graphe->AfficherGraph();
   */
}

