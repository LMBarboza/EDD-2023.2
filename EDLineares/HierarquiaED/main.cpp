#include <iostream>

#include "ClassABS.h"

#include "ListaSencadeada.h"
#include "ListaDencadeada.h"
#include "ListaCencadeada.h"
using namespace std;



void printList(C_Lsimples lista1) {
	cout << "print da lista" << endl;
	SNode* Itr = &lista1.head;
	cout << Itr->value << endl;
	while (Itr->next != NULL) {
		Itr = Itr->next;
		cout << Itr->value << endl;
	}

};
template <class C_lista>
void printFoward(C_lista lista) {
	CNode* Itr = &lista.head;
	while (Itr->next != &lista.head && Itr->next != NULL) {
		cout << Itr->value << endl;
		Itr = Itr->next;
	};

}
template <class C_lista>
void printBackward(C_lista lista) {
	CNode* Itr = &lista.tail;
	while (Itr->prev != &lista.tail && Itr->prev != NULL) {
		cout << "loop infinito" << endl;
		cout << Itr->value << endl;
		cout << Itr->prev->value << endl;
		Itr = Itr->prev;
	};
}







int main()
{

	C_Lsimples listaS;
	C_Ldupla listaD;
	C_Lcirc listaC;

	listaS.append(1);
	listaS.add(0);
	listaS.append(9);
	listaD.append(1);
	listaD.append(9);
	listaC.append(1);
	listaC.append(2);

	cout << "LISTA SIMPLES" << endl;
	printList(listaS);

	cout << "LISTA DUPLA" << endl;
	printFoward<C_Ldupla>(listaD);

	cout << "LISTA CIRCULAR" << endl;
	printFoward<C_Lcirc>(listaC);
	cout << "Hello World" << endl;
}