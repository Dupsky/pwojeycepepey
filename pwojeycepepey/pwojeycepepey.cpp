
#include <iostream>
#include "Carc.h"
#include "CSommet.h"
#include "Cgraphe.h"

int main()
{
    std::cout << "début test" << std::endl;
    Carc arc1(1);
    Carc arc2(2);
    Carc arc3(1);
    Carc* tab[3];
    Csommet sommet1(1);
    Csommet sommet2(2);
    sommet1.SOMArcArrivant(&arc1);
    sommet1.SOMArcArrivant(&arc3);
    sommet2.SOMArcArrivant(&arc2);

    sommet1.SOMModifierNum(3);


    tab[0] = &arc1;
    tab[1] = &arc2;
    tab[2] = &arc3;
    std::cout << "taille tab : " << sizeof(tab)/sizeof(Carc*) << std::endl;
    std::cout << "dest arc 1 : " << arc1.getDest()  << std::endl;
    std::cout << "dest arc 2 : " << arc2.getDest() << std::endl;
    std::cout << "dest arc 3 : " << arc3.getDest() << std::endl;
    



            



}

