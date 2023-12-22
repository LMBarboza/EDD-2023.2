#ifndef ListaSencadeada_h
#define ListaSencadeada_h

#include <iostream>
#include "ClassABS.h"

using std::cout; 
using std::endl;

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
        if (head->value == NULL) {
            head->value = num;
        }

        else {
            SNode* Itr = head;
            while (Itr->next != nullptr) {
                Itr = Itr->next;
            };

            SNode* node_num;
            node_num = new SNode(num);
            Itr->next = node_num;
            node_num->next = NULL;
        };
    };

    void push(int i) {
        length++;
        SNode* new_num;
        new_num = new SNode(head->value);
        new_num->next = head->next;
        head->next = new_num;
        head->value = i;

    }

    int pop(void) {
        length--;
        SNode* Itr = head;
        SNode* Itr2 = Itr;
        while (Itr->next != nullptr) {
            Itr2 = Itr;
            Itr = Itr->next;
        }
        int R = Itr->value;
        Itr2->next = NULL;
        return R;
    }

    int pop(int num) {
        length--;
        SNode* Itr = head;
        SNode* Itr2;
        for (int i = 0; i < num; i++) {
            Itr2 = Itr;
            Itr = Itr->next;
        }
        Itr2->next = Itr->next;
        return Itr->value;
    }

    int pop_back(void) {
        length--;
        head = head->next;
        return head->value;
    }

};

#endif