#ifndef ListaDencadeada_h
#define ListaDencadeada_h

#include <iostream>
#include "ClassABS.h"

using std::cout; 
using std::endl;

class DNode {
public:
    int value;
    DNode(int i = NULL) { value = i; }
    DNode* next;
    DNode* prev;
};

class C_Ldupla:public C_ABS<DNode> {
public:

    DNode* tail;

    C_Ldupla() {}
    C_Ldupla(int i) { head->value = i; tail = head; }

    void append(int num) {
        length++;
        if (head->value == NULL) {
            cout << "appendou" << num << "na primeira posição" << endl;
            head->value = num;
            tail =  head;
        }
        else {
            cout << "appendou" << num << endl;
            DNode node_num(num);
            DNode ex_tail = *tail;
            (*tail).next = &node_num;
            node_num.prev = &ex_tail;
            cout << "node_num prev " << node_num.prev->value << endl;
            cout << "tail " << tail->value << endl;
            *tail = node_num;
            
            cout << "tail " << tail->value << endl;
            cout << "tail prev " << tail->prev->value << endl;

        }

    }

    void push(int num) {
        DNode new_node = *head;
        head->next = &new_node;
        new_node.prev = head;
        head->value = num;
        
    }

    int pop(void) {
        length--;
        DNode* Itr = head;
        while (Itr->next != head){
            Itr = Itr->next;
        }
        DNode* Itr2 = Itr->prev;
        Itr2->next = head;
        head->prev = Itr2;

        return Itr->value;
    }

    int pop(int num) {
        length--;
        DNode* Itr = head;
        for (int i = 0; i <= num; i++) {
            Itr = Itr->next;
        }
        DNode* Itr2 = Itr->prev;
        DNode* Itr3 = Itr->next;
        Itr2->next = Itr3;
        Itr3->prev = Itr2;

        return Itr->value;
    }

    int pop_back(void) {
        int R = head->value;
        head = head->next;
        head->prev = nullptr;
        
        return R;
    }

};

#endif
