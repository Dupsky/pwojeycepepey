
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

