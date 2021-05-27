
#include <iostream>
#include "Carc.h"
#include "CSommet.h"
#include "Cgraphe.h"

int main()
{
    std::cout << "début test" << std::endl;
    //Carc arc1(1);
    //Carc arc2(2);
    //Carc arc3(1);
    //Carc* tab[3];
    //Csommet sommet1(1);
    //Csommet sommet2(2);
    //sommet1.SOMArcArrivant(&arc1);
    //sommet1.SOMArcArrivant(&arc3);
    //sommet2.SOMArcArrivant(&arc2);

    //sommet1.SOMModifierNum(3);


    //tab[0] = &arc1;
    //tab[1] = &arc2;
    //tab[2] = &arc3;
    //std::cout << "taille tab : " << sizeof(tab)/sizeof(Carc*) << std::endl;
    //std::cout << "dest arc 1 : " << arc1.getDest()  << std::endl;
    //std::cout << "dest arc 2 : " << arc2.getDest() << std::endl;
    // std::cout << "dest arc 3 : " << arc3.getDest() << std::endl;
    
    Csommet som1(1);
    Csommet som2(2);
    Csommet som3(3);

    Carc arc1(1);
    Carc arc2(2);
    Carc arc3(3);

    som1.SOMArcArrivant(&arc1);
    som3.SOMArcArrivant(&arc3);
    som2.SOMArcArrivant(&arc2);
    som2.SOMArcPartant(&arc1);
    som2.SOMArcPartant(&arc3);
    som1.SOMArcPartant(&arc2);

    Cgraphe graphe;
    graphe.addSommet(som1);
    graphe.addSommet(som2);

    graphe.AfficherGraph();
    
    /*
    Csommet som1= Csommet(1);
    Csommet som2(2);


    Carc arc1(1);
    Carc arc2(2);
    Carc arc3(1);

    som1.SOMArcArrivant(&arc1);
    som1.SOMArcArrivant(&arc3);
    som2.SOMArcArrivant(&arc2);
    som2.SOMArcPartant(&arc1);
    som2.SOMArcPartant(&arc3);
    som1.SOMArcPartant(&arc2);


    */
            



}

