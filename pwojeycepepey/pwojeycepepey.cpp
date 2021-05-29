
#include <iostream>
#include "Carc.h"
#include "CSommet.h"
#include "Cgraphe.h"

int main()
{

    Cgraphe graphe= Cgraphe();


    graphe.createSommet(1);

    graphe.createSommet(2);

    graphe.createSommet(3);

    graphe.TrouverSommet(1)->link(*graphe.TrouverSommet(2));
    graphe.TrouverSommet(2)->link(*graphe.TrouverSommet(3));
    graphe.TrouverSommet(3)->link(*graphe.TrouverSommet(2));
    graphe.TrouverSommet(1)->link(*graphe.TrouverSommet(3));
    graphe.AfficherGraph();

    graphe.InverserGraph();

    //graphe.TrouverSommet(2)->AfficherArcsPartant();
   // graphe.TrouverSommet(3)->AfficherArcsPartant();
    graphe.AfficherGraph();



    /*
    Csommet sommet1(1);
    Csommet sommet2(2);
    Csommet sommet3(3);
    Csommet sommet4(4);

    sommet1.link(sommet2);
    sommet1.link(sommet3);
    sommet1.link(sommet4);


    

    
    sommet1.AfficherTabs();
    sommet2.AfficherTabs();

    sommet1.unlink(sommet2);

    sommet1.AfficherTabs();
    sommet2.AfficherTabs();
    
    //sommet1.suppArcArrivant(&arc1);

    //sommet1.AfficherTabs();

    //sommet1.SOMModifierNum(3);

    */

      
            



}

