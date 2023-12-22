#ifndef ListaCencadeada_h
#define ListaCencadeada_h

#include <iostream>
#include "ClassABS.h"

using std::cout;
using std::endl;

class CNode {
public:
    int value;
	CNode(int i = NULL) { value = i; }
	CNode* next;
	CNode* prev;

};

class C_Lcirc :public C_ABS<CNode> {
public:

    CNode* tail;

    C_Lcirc() { tail->next = head; }
    C_Lcirc(int i) { head->value = i; tail->next = head; }

    void append(int num) {
        length++;
        if (head->value == NULL) {
            cout << "appendou" << num << "na primeira posição" << endl;
            head->value = num;
            tail->value = num;
        }
        else {
            CNode* new_node;
            new_node = new CNode(num);
            new_node->next = head;
            new_node->prev = tail;
            tail = new_node;

        }
    }

    void add(int num, int pos) {
        CNode* Itr;
        for (int i = 0; i <= pos; i++) {
            Itr = Itr->next;
        }
        CNode new_node(num);
        (Itr->next)->prev = &new_node;
        new_node.next = Itr->next;
        Itr->next = &new_node;
        new_node.prev = Itr;
    }

    int pop(void) {
        length--;
        int R = tail->value;
        tail = tail->prev;
        tail->next = head;
        return R;
    }

    int pop(int num) {
        length--;
        CNode* Itr = head;
        for (int i = 0; i <= num; i++) {
            Itr = Itr->next;
        }
        (Itr->prev)->next = Itr->next;
        (Itr->next)->prev = Itr->prev;

        return Itr->value;
    }

    int pop_back(void) {
        int R = head->value;
        head = head->next;
        head->prev = tail;
        tail->next = head;

        return R;
    }

};


#endif
