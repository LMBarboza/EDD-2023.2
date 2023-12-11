#include "stack.h"
#include <iostream>
constexpr int numDisco = 3;

void hanoi_hanoi(int numDisco, Pilha<int, 3>& inicial, Pilha<int, 3>& intermediario,
    Pilha<int, 3>& destino) { 
  if (numDisco == 1) {
    int disco = inicial.top();
    inicial.desempilha();
    destino.empilha(disco);
    std::cout << "Move disco " << disco << "Inicio para Destino" << std::endl;
    } else {

        hanoi_hanoi(numDisco - 1, inicial, destino, intermediario);

        hanoi_hanoi(1, inicial, intermediario, destino);

        hanoi_hanoi(numDisco - 1, intermediario, inicial, destino);
    }
}
int main(void){ 
  Pilha<int, numDisco> inicial, intermediario, destino;
  for (int i = numDisco; i >= 1; i--){
    inicial.empilha(i);
  }
  
  hanoi_hanoi(numDisco, inicial, intermediario, destino); 

  return 0;
}


