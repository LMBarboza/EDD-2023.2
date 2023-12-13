#include <iostream>
#include "ClassABS.h"

using namespace std;

class SNode{
public:
    int value;
    SNode(int i = NULL) {value = i;} //construtores
    SNode* next;
};


class C_Lsimples:public C_ABS<SNode>{
public:



    void append(int num) {
        length++;
        if (head.value == NULL) {
            cout << "appendou" << num << endl;
            head.value = num;
        }

        else {
            SNode* Itr = &head;
            while (Itr->next != NULL) {
                Itr = Itr->next;
            };
            cout << "appendou" << num << endl;
            SNode* node_num;
            node_num = new SNode(num);
            Itr->next = node_num;
            //node_num->value = num;
            node_num->next = NULL;
        };
    };

    int pop(void) {
        length--;
        SNode* Itr = &head;
        SNode* Itr2 = Itr;
        while (Itr->next != NULL) {
            Itr2 = Itr;
            Itr = Itr->next;
        }
        int R = Itr->value;
        Itr2->next = NULL;
        return R;
    }

    /*operador[]
    int operator[](int index) {
        SNode* Itr = &head;
        for (int i = 0; i < index; i++) {
            Itr = Itr->next;
        }
        return Itr->value;
    }*/

    //adiciona no inicio
    void add(int i) {
        length++;
        SNode* new_num;
        new_num = new SNode(head.value);
        new_num->next = head.next;
        head.next = new_num;
        head.value = i;
        cout << "addou" << i << endl;
        
    }
};


void printList(C_Lsimples lista1) {
    cout << "print da lista" << endl;
    SNode* Itr = &lista1.head;
    cout << Itr->value << endl;
    while (Itr->next != NULL) {
        Itr = Itr->next;
        cout << Itr->value << endl;
    }
    
};

/*
int main()
{
    C_Lsimples lista;

    printList(lista);
    lista.append(10);
    lista.append(0);
    lista.append(78);
    lista.append(7);
    lista.add(9);
    printList(lista);
    lista.add(1);
    printList(lista);
    cout << "pop lista:" << lista.pop() <<endl;
    printList(lista);
    cout << "lista[0]" << lista[0] << endl;

    /*
    second->value = 2;
    second ->next = third;
    /third->value = 3;
    third ->next = NULL;
    

    //printList(lista);
    cout << "oi" << endl;
    

    system("pause>0");
}*/

