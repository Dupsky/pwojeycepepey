
#include <iostream>
#include "Carc.h"
#include "CSommet.h"
#include "CGraphe.h"

int main()
{

    Csommet sommet1(1);
    Csommet sommet2(2);
    Csommet sommet3(3);
    Csommet sommet4(4);

    //sommet1.AfficherTabs();

    sommet1.link(sommet2);
    //sommet1.link(sommet3);
    //sommet1.link(sommet4);
 
    sommet1.AfficherTabs();
    //sommet1.SOMModifierNum(5);


    //tab[0] = &arc1;
    //tab[1] = &arc2;
    //tab[2] = &arc3;
    //std::cout << "taille tab : " << sizeof(tab)/sizeof(Carc*) << std::endl;
    /*std::cout << "dest arc 1 : " << arc1.getDest()  << std::endl;
    std::cout << "dest arc 2 : " << arc2.getDest() << std::endl;
    std::cout << "dest arc 3 : " << arc3.getDest() << std::endl;*/
}

