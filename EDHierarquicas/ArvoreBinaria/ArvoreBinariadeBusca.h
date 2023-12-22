#include <iostream>
#include<stdio.h>
#include<stdlib.h>

#include "stack.h"

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
    ArvBB() { }
    ArvBB(TABa no1) { rad = NoArv<TABa>(no1); rad.left = nullptr; rad.right = nullptr; }

    NoArv<TABa>* search(TABa obj) {
        NoArv<TABa>* Itr = &rad;

        while (Itr->valor != obj) {
            if (obj < Itr->valor && Itr->left != NULL){

                Itr = Itr->left;
            }
            else if (obj > Itr->valor && Itr->right != NULL) {
                Itr = Itr->right;
            }
            else {
                cout << "Endereço nao encontrado" << endl;
                break;
            }
        }
        return Itr;

    }

    void add(TABa obj) {
        if (rad.valor == NULL) {
            cout << "adicionou " << obj << endl;
            rad.valor = obj;
            return;
        }

        NoArv<TABa>* new_no;
        new_no = new NoArv<TABa>(obj);
        new_no->left = nullptr;
        new_no->right = nullptr;


        NoArv<TABa>* Itr = &rad;
        
        while (Itr->left != nullptr || Itr->right != nullptr) {

            if (new_no->valor < Itr->valor) {
                    if (Itr->left != nullptr) {
                    Itr = Itr->left;                 }

                else {
                   
                    Itr->left = &(*new_no);  
                    return;
                };
            }
            else if (new_no->valor > Itr->valor) {
                

                if (Itr->right != nullptr) {Itr = Itr->right; }

                else {
                    Itr->right = &(*new_no); 
                    return;
                };
            }
        }

        if (obj < Itr->valor) {

            Itr->left = &(*new_no);
            return;
        }
        else {
            
            Itr->right = &(*new_no);
            return;
        }

    }

    void remove(TABa obj) {
        if (search(obj) == NULL) { return; }

        NoArv<TABa>* Itr = &rad;
        NoArv<TABa>* Itr2 = &rad;
        bool noLeft = true;

        while (Itr->valor != obj) {
            Itr2 = Itr;
            if (obj < Itr->valor) {
                Itr = Itr->left;
                noLeft = true;
            }
            else { Itr = Itr->right; noLeft = false; }
        }

        if (Itr->left == NULL && Itr->right == NULL) {
            if (Itr == &rad) { rad = NULL; }
            else if (noLeft) { Itr2->left = NULL; }
            else { Itr2->right = NULL; }
        }

        else if (Itr->right == NULL) {
            if (Itr == &rad) { rad = *Itr->left; }
            else if (noLeft) { Itr2->left = Itr->left; }
            else { Itr2->right = Itr->left; }

        }

        else if (Itr->left == NULL) {
            if (Itr == &rad) { rad = *Itr->right; }
            else if (noLeft) { Itr2->left = Itr->right; }
            else { Itr2->right = Itr->left; }
        }

        else {
            NoArv<TABa>* prox = prox_no(Itr);
            
            if (Itr == &rad) { rad = *prox; }
            else if (noLeft) { Itr2->left = prox; }
            else { Itr2->right = prox; }

            prox->left = Itr->left;
        }
        return;
        }

    void printPreord() { printPreord2(&rad); } 

    void printOrd() { printOrd2(&rad); }
    
    void printPosOrd() { printPosord2(&rad); }

 private: 
     NoArv<TABa>* prox_no(NoArv<TABa>* obj) {
     NoArv<TABa>* Itr = obj;
     NoArv<TABa>* Itr2 = obj;
     NoArv<TABa>* Itr3 = obj->right;

     while (Itr3 != NULL) {
         Itr2 = Itr;
         Itr = Itr3;
         Itr3 = Itr3->right;
     }

     if (Itr != obj->right) {
         Itr2->left = Itr->right;

         Itr->right = obj->right;
     }
     return Itr;
 }

     void printPreord2(NoArv<TABa>* Itr) {
         if (Itr != NULL) {
             cout << Itr->valor << endl;
             printPreord2(Itr->left);
             printPreord2(Itr->right);
         }
     }

     void printPosord2(NoArv<TABa>* Itr) {
         if (Itr != NULL) {
             printPosord2(Itr->left);
             printPosord2(Itr->right);
             cout << Itr->valor << endl;
         }
     }

     void printOrd2(NoArv<TABa>* Itr) {
         if (Itr != NULL) {
             printOrd2(Itr->left);
             cout << Itr->valor << endl;
             printOrd2(Itr->right);
         }

     }

};
