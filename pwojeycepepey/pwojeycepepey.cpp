
#include <iostream>
#include "Carc.h"
#include "CSommet.h"
#include "Cgraphe.h"
#include "Cparser.h"

int main()
{
    Cgraphe * graphe = new Cgraphe();

    graphe->createSommet(1);
    graphe->createSommet(2);
    graphe->createSommet(3);
   

    graphe->TrouverSommet(1)->link(graphe->TrouverSommet(2));
    graphe->TrouverSommet(2)->link(graphe->TrouverSommet(3));
    graphe->TrouverSommet(3)->link(graphe->TrouverSommet(2));
    graphe->TrouverSommet(1)->link(graphe->TrouverSommet(3));
    graphe->AfficherGraph();

    graphe->InverserGraph();

    graphe->AfficherGraph();

}

