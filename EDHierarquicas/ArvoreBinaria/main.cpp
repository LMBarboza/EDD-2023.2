#include <iostream>
#include <math.h> //usei na potencia
#include "ArvoreBinariadeBusca.h"
#include "Dados.h"


using namespace std;




int main()
{
    //TESTE FALHO
     
    ArvBB<personC> ARVC;
    ArvBB<personD> ARVD;

    for (int i = 1; i < 26; i++) {
        dadosC[i] = personC(Alfabeto[i],
            (98765000 + i * 100 + i * (10 * pow(-1, i)) + 15 + i),
            (22000 + i * 100 + i * (i*pow(-1,i))));
        ARVC.add(dadosC[i]);
    };

    for (int i = 0; i < 26; i++) {
        dadosD[i] = personD(Alfabeto[i],
            (98765000 + i * 100 + i * ( 10* pow(-1,i)) + 15 + i),
            (22000 + i * 100 + i * (i * pow(-1, i))));
        ARVD.add(dadosD[i]);
    };
    
    cout << "Print IN Ordem ARV C" << endl;
    ARVC.printOrd();
    
    cout << "Print IN Ordem ARV D" << endl;

    ARVD.printOrd(); 

    ArvBB<int> ARV;

    for (int i = 0; i <= 25; i++) {
        ARV.add((100 + 7 + (i * i) + (pow(-1, i) * 15)));
    }

    cout << "Print in Ordem" << endl;
    ARV.printOrd();

    cout << "Print Pre Ordem" << endl;
    ARV.printPreord();

    cout << "Print Pos  Ordem" << endl;
    ARV.printPosOrd();



    
    std::cout << "Hello World!\n";
}