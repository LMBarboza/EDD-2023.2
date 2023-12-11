#include "stack.h"
#include <iostream>

int main(void){
  constexpr int numDisco = 3;
  
  Pilha<int, numDisco> inicial;
  for (int i = numDisco; i >= 1; i--){
    inicial.empilha(i);
  }



  return 0;
}

