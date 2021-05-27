
#include <iostream>
#include "Carc.h"
#include "CSommet.h"
#include "Cgraphe.h"

int main()
{
    std::cout << "debut test" << std::endl;

    Csommet sommet1(1);
    Csommet sommet2(2);
    Csommet sommet3(3);
    Csommet sommet4(4);
    
    Carc arc1 = Carc();
    Carc arc2 = Carc();
    Carc arc3 = Carc();
    Carc arc4 = Carc();
    Carc arc5 = Carc();
    Carc arc6 = Carc();


    sommet1.link(sommet2, arc1, arc2);
    sommet1.link(sommet3, arc3, arc4);
    sommet1.link(sommet4, arc5, arc6);

    sommet1.AfficherTabs();
  


    std::cout << "debut fin" << std::endl;

    //sommet1.SOMModifierNum(3);



            



}

