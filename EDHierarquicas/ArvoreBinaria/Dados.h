#include <iostream>

using namespace std;


class personC {
public:
    char name;
    unsigned int CPF;
    unsigned int DRE;

    personC(char name_p = ' ', int CPF_p = 0, int DRE_p = 0) {
        name = name_p;
        CPF = CPF_p;
        DRE = DRE_p;

    }

    bool operator< (const personC& other) {
        return this->CPF < other.CPF;
    }
    bool operator> (const personC& other) {
        return this->CPF > other.CPF;
    }
    bool operator== (const personC& other) {
        return this->CPF == other.CPF;
    }

    friend ostream& operator<<(ostream& os, personC& valor){
        os << "Nome: " << valor.name << " CPF: " << valor.CPF << " DRE: " << valor.DRE;
        return os;
    }
};


class personD {
public:
    char name;
    unsigned int CPF;
    unsigned int DRE;

    personD(char name_p = ' ', int CPF_p = 0, int DRE_p = 0) {
        name = name_p;
        CPF = CPF_p;
        DRE = DRE_p;

    }

    bool operator< (const personD& other) {
        return this->DRE < other.DRE;
    }
    bool operator> (const personD& other) {
        return this->DRE > other.DRE;
    }
    bool operator == (const personD& other) {
        return this->DRE == other.DRE;
    }

    friend ostream& operator<<(ostream& os, personD& valor) {
        os << "Nome: " << valor.name << " CPF: " << valor.CPF << " DRE: " << valor.DRE;
        return os;
    }
};

char Alfabeto[26] = { 'A','B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
'N','O','P','Q','R','S','T','U','V','W','X','Y','Z' };

personC dadosC[26];
personD dadosD[26];
