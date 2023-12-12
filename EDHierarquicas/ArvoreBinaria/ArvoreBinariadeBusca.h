#include <iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

template <typename TAB>
class NoArv {
public:
    TAB valor;
    NoArv(TAB i = NULL) { valor = i; }
    NoArv* right;
    NoArv* left;
};


template <typename TABa>
class ArvBB {
public:
    NoArv<TABa> rad;
    ArvBB() { rad = NoArv<TABa>; }
    ArvBB(TABa no1) { rad = NoArv<TABa>(no1); }

    void add(TABa obj) {
        if (rad.valor == NULL) {
            cout << "adicionou " << obj << endl;
            rad.valor = obj;
            return;
        }

        NoArv<TABa> new_no(obj);


        NoArv<TABa>* Itr = &rad;
        while (Itr->left != NULL && Itr->right != NULL) {
            cout << "loop infinito" << endl;
            if (new_no.valor < Itr->valor) {
                cout << "new_no " << obj << "é menor que Itr=" << Itr->valor << endl;
                if (Itr->left != NULL) { Itr = Itr->left; cout << "entrei aqui" << endl; }

                else { Itr->left = &new_no; cout << new_no.left->valor << " left valor and no valor " << new_no.valor << endl; };
            }
            else if (new_no.valor > Itr->valor) {
                cout << "new_no " << obj << "é maior que Itr=" << Itr->valor << endl;

                if (Itr->right != NULL) { Itr = Itr->right; }

                else { Itr->right = &new_no; };
            }
            //cout << "radL " << rad.left->valor << endl;
            //cout << "radR" << rad->right->valor << endl;
        }

        cout << "alo" << endl;
        if (obj < Itr->valor) {
            Itr->left = &new_no;
        }
        else {
            Itr->right = &new_no;
        }
    }

};




