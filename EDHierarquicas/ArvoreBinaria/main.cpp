#include <iostream>
#include "ArvoreBinariadeBusca.h"

using namespace std;


int main()
{
    NoArv<int> n1(50);
    NoArv<int> n2(1);
    NoArv<int> n3(90);
    NoArv<int> n4(0);
    NoArv<int> n5(65);

    ArvBB<int> ARV(50);
    ARV.add(1);
    ARV.add(90);
    ARV.add(0);
    ARV.add(65);

    std::cout << "Hello World!\n";
}