#include <vector>
#include <stdexcept>
#include <algorithm>

template <class T>
class Pilha {
private:
    std::vector<T> pilha;
    size_t tamanho_maximo;
    size_t topo;

public:
    Pilha(size_t tamanho_max);
    void empilha(T dado);
    T desempilha(void);
    bool pilha_esta_vazia(void);
    bool pilha_esta_cheia(void);
    void troca(void);
    size_t tamanho(void);  
    T top(void);
};


template <class T>
Pilha<T>::Pilha(size_t tamanho_max) : tamanho_maximo(tamanho_max), topo(0) {
  pilha.resize(tamanho_maximo);
}

template <class T>
void Pilha<T>::empilha(T dado) {
    if (topo >= tamanho_maximo) {
        throw std::length_error("1");
    }
    pilha[topo++] = dado;
}

template <class T>
T Pilha<T>::desempilha() {
    if (topo == 0) {
        throw std::invalid_argument("1");
    }
    return pilha[--topo];
}

template <class T>
bool Pilha<T>::pilha_esta_cheia() {
    return (topo == tamanho_maximo);
}

template <class T>
bool Pilha<T>::pilha_esta_vazia() {
    return (topo == 0);
}

template <class T>
void Pilha<T>::troca() {
    if (topo < 2) {
        throw std::length_error("1");
    }
    std::swap(pilha[topo - 1], pilha[topo - 2]);
}

template <class T>
size_t Pilha<T>::tamanho() {
    return topo;
}

template <class T>
T Pilha<T>::top() {
    if (topo == 0) {
        printf("Vazia \n");
    }
    return pilha[topo - 1];
}
