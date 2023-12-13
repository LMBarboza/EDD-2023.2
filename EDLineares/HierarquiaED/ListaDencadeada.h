#include <iostream>
#include "ClassABS.h"

using namespace std;

class DNode {
public:
    int value;
    DNode(int i = NULL) { value = i; }
    DNode* next;
    DNode* prev;
};

class C_Ldupla:C_ABS<DNode> {
public:

    DNode tail;

    C_Ldupla() {}
    C_Ldupla(int i) { head.value = i; tail = head; }

    void append(int num) {
        length++;
        if (head.value == NULL) {
            cout << "appendou" << num << "na primeira posição" << endl;
            head.value = num;
            tail =  head;
        }
        else {
            cout << "appendou" << num << endl;
            DNode node_num(num);
            //DNode* Prev = tail;
            //node_num = new DNode(num);
            DNode ex_tail = *tail;
            (*tail).next = &node_num;
            //node_num->next = NULL;
            node_num.prev = &ex_tail;
            cout << "node_num prev " << node_num.prev->value << endl;
            cout << "tail " << tail->value << endl;
            *tail = node_num;
            
            cout << "tail " << tail->value << endl;
            cout << "tail prev " << tail->prev->value << endl;

        }

    }
};

/*
void printFoward(C_Ldupla lista){
    DNode* Itr = lista.head;
    while(Itr->next != NULL) {
        cout << Itr->value << endl;
        Itr = Itr -> next;
    };

}

void printBackward(C_Ldupla lista){
    DNode* Itr = lista.tail;
    while(Itr != NULL) {
        cout << "loop infinito" << endl;
        cout << Itr -> value << endl;
        //cout << Itr->prev->value << endl;
        Itr = Itr -> prev;
    };

}

/*
int main()
{
    C_Ldupla lista1;
    lista1.append(1);
    lista1.append(2);
    lista1.append(3);

    cout << "print foward lista" << endl;
    printFoward(lista1);
    cout << "print backward lista" << endl;
    printBackward(lista1);


    return 0;
}*/
