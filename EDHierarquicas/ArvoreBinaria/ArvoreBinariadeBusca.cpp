/*
#include <iostream>
#include<stdio.h>
#include<stdlib.h>


template <typename TAB>
class NoArv {
public:
    NoArv(TAB i = NULL) { TAB valor = i; }
    NoArv* right;
    NoArv* left;
};


template <typename TABa>
class ArvBB {
public:
    ArvBB() {NoArv<TABa> rad;}
    ArvBB(TABa no1) { NoArv<TABa> rad(no1); }

    void add(TABa obj) {
        No_Arv<TABa> new_no(obj);
        No_Arv<TABa> Itr = rad;
        while (true) {
            cout << "loop infinito" << endl;
            if (new_no < Itr) {
                cout << "new_no é menor que Itr=" << Itr.valor << endl;
                if (Itr->left != NULL) { Itr = Itr->left; }

                else { Itr->left = &new_no; break; };
            }
            else if (new_no > Itr) {
                cout << "new_no é maior que Itr=" << Itr.valor << endl;
                if (Itr->right != NULL) { Itr = Itr->right; }
                else { Itr->right = &new_no; break; };
            }
        }

    }


};

//kk ta

/*
template <typename TABp>
void printArv(ArvBB<TABp> arv) {
    NoArv<TABp> Itr = arv.rad;
    stack<NoArv> PArv;
    PArv.push(Itr);
    /*
    while (true) {
        cout << "looping infinito" << edl;
        if (Itr->left != NULL) {
            cout << "lp no if" << endl;
            Itr = Itr->left;
        }
        else (Itr->right != NULL) {
            cout << Itr.valor << endl;
            cout << "lp no else" << endl;
            Itr 
        }
    }
    while ((Itr->left != NULL) || (Itr->right != NULL)) {
        
        if (Itr->left != NULL) { Itr = Itr->left; PArv.push(Itr); break; }
        else { cout << (PArv.pop()).valor << endl; Itr  = PArv.top() }

        if(Itr->right != NULL) {Itr = Itr->}        
    }
}*/



