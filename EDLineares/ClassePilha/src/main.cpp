#include "../include/stack.h"
#include <iostream>
void printPilha(const Pilha<int>& pilha, const std::string& nomePilha) {
  std::cout << nomePilha << ": ";
  Pilha<int> copiaPilha = pilha; 
  while (!copiaPilha.pilha_esta_vazia()) {
      std::cout << copiaPilha.top() << " ";
      copiaPilha.desempilha();
    }
    std::cout << std::endl;
}

void hanoi_hanoi(int numDisco, Pilha<int>& inicial, Pilha<int>& intermediario,
    Pilha<int>& destino) { 
  if (numDisco == 1) {
    int disco = inicial.top();
    inicial.desempilha();
    destino.empilha(disco);
    printPilha(inicial, "Inicio");
    printPilha(intermediario, "Intermediario");
    printPilha(destino, "Destino");
    std::cout << "-------------------------" << std::endl;

    }
    else {

        hanoi_hanoi(numDisco - 1, inicial, destino, intermediario);

        hanoi_hanoi(1, inicial, intermediario, destino);

        hanoi_hanoi(numDisco - 1, intermediario, inicial, destino);
    }
}
int main(void){
  size_t numDisco;
  printf("Insira a quantidade de discos: \n");
  scanf("%lu", &numDisco);
  Pilha<int> inicial(numDisco), intermediario(numDisco), destino(numDisco);
  for (int i = numDisco; i >= 1; i--){
    inicial.empilha(i);
  }
  std::cout << "Estado inicial" << std::endl;
  printPilha(inicial, "Inicio");
  printPilha(intermediario, "Intermediario");
  printPilha(destino, "Destino");
  std::cout << "-------------------------" << std::endl;
    
  hanoi_hanoi(numDisco, inicial, intermediario, destino); 

  return 0;
}


