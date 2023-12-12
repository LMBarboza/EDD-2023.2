#include <iostream>

using namespace std;

class CNode {
public:
    int value;
	CNode(int i = NULL) { value = i; }
	CNode* next;
	CNode* prev;

};

class C_Lcirc {
public:
    CNode head;
    CNode tail;

    C_Lcirc() { tail.next = &head; }
    C_Lcirc(int i) { head.value = i; tail.next = &head; }

    void append(int num) {
        if (head.value == NULL) {
            cout << "appendou" << num << "na primeira posição" << endl;
            head.value = num;
            tail.value = num;
        }
        else {
            CNode* new_node;
            new_node = new CNode(num);
            new_node->next = &head;
            new_node->prev = &tail;
            tail = *new_node;
            
        }
    }

    int pop() {
        int R = tail.value;
        tail = *tail.prev;
        tail.next = &head;
        return R;
    }

}; 

void printFoward(C_Lcirc lista) {
    CNode* Itr = &lista.head;
    while (Itr->next != &lista.head) {
        cout << Itr->value << endl;
        Itr = Itr->next;
    };

}

void printBackward(C_Lcirc lista) {
    CNode* Itr = &lista.tail;
    while (Itr->prev != &lista.tail) {
        cout << "loop infinito" << endl;
        cout << Itr->value << endl;
        cout << Itr->prev->value << endl;
        Itr = Itr->prev;
    };

}
/*
int main()
{

    C_Lcirc lista1;
    lista1.append(1);
    lista1.append(2);
    lista1.append(3);

    cout << "print foward lista" << endl;
    printFoward(lista1);
    cout << "print backward lista" << endl;
    printBackward(lista1);

	cout << "Hello World!" << endl;

    return 0;
}*/