#include <iostream>

#include "ClassABS.h"

#include "ListaSencadeada.h"
#include "ListaDencadeada.h"
#include "ListaCencadeada.h"

#include "Queue.h"
#include "stack.h"

using namespace std;


void printList(C_Lsimples lista1) {
	cout << "print da lista" << endl;
	SNode* Itr = lista1.head;
	cout << Itr->value << endl;
	while (Itr->next != NULL) {
		Itr = Itr->next;
		cout << Itr->value << endl;
	};

};

template <class C_lista, class cNode >
void printFoward(C_lista lista) {
	cNode* Itr = lista.head;
	while (Itr->next != lista.head && Itr->next != NULL) {
		cout << Itr->value << endl;
		Itr = Itr->next;
	};

}
template <class C_lista, class cNode>
void printBackward(C_lista lista) {
	cNode* Itr = lista.tail;
	while (Itr->prev != lista.tail && Itr->prev != NULL) {
		cout << "loop infinito" << endl;
		cout << Itr->value << endl;
		cout << Itr->prev->value << endl;
		Itr = Itr->prev;
	};
}







int main()
{
	cout << "inicio" << endl;

	C_Lsimples listaS;
	C_Ldupla listaD;
	C_Lcirc listaC;

	listaS.append(1);
	listaS.push(0);
	listaS.append(9);
	listaD.append(1);
	listaD.append(9);
	listaC.append(1);
	listaC.append(2);

	cout << "LISTA SIMPLES" << endl;
	printList(listaS);

	cout << "LISTA DUPLA" << endl;
	printFoward<C_Ldupla, DNode>(listaD);

	cout << "LISTA CIRCULAR" << endl;
	printFoward<C_Lcirc, CNode>(listaC);

	QUEUE fila;
	for (int i = 0; i <= 10; i++) {
		fila.append(i);
		cout << fila.tempo() << endl;
	}

	for (int i = 0; i < 5; i++) {
		cout << "oi" << endl;
		cout << fila.dequeue() << endl;
	}
	cout << fila.tempo() << endl;

	cout << fila.pop(3) << endl;

	cout << fila.tempo() << endl;

	while (!fila.isEmpty()) {
		cout << fila.dequeue() << endl;
	}

	cout << "Hello World" << endl;
}