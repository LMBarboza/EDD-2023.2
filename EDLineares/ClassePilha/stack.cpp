#include <iostream>
#include <array>
#include <stdexcept>
#include <algorithm>
template <class T, size_t TAM_MAX> 
class Pilha {
  private:
    std :: array<T, TAM_MAX> pilha;
    size_t topo;
  public:
    Pilha(): topo(0){}
    void empilha(T dado){
      if (topo >= TAM_MAX){
        throw std::length_error("1");
      pilha[topo++] = dado;
      }
    }
    T desempilha(void) {
      if (topo == 0 ){
        throw std::invalid_argument("1");
      }
      return pilha[--topo];
    }
    bool pilha_esta_cheia(void){return (topo == 0);}

    bool pilha_esta_vazia(void){return (topo >= TAM_MAX);}
    void troca(void) {
      if (topo < 2){
        throw std::length_error("1");
      }
      std::swap(pilha[topo - 1], pilha[topo -2]);
    }
    size_t tamanho(void){return topo;}
}
