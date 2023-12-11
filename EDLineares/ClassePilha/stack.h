#include <array>
#include <stdexcept>
#include <algorithm>

template <class T, size_t TAM_MAX>
class Pilha {
private:
    std::array<T, TAM_MAX> pilha;
    size_t topo;

public:
    Pilha();
    void empilha(T dado);
    T desempilha(void);
    bool pilha_esta_vazia(void);
    bool pilha_esta_cheia(void);
    void troca(void);
    size_t tamanho(void);  
    T top(void);
};


template <class T, size_t TAM_MAX>
Pilha<T, TAM_MAX>::Pilha() : topo(0) {}

template <class T, size_t TAM_MAX>
void Pilha<T, TAM_MAX>::empilha(T dado) {
    if (topo >= TAM_MAX) {
        throw std::length_error("1");
    }
    pilha[topo++] = dado;
}

template <class T, size_t TAM_MAX>
T Pilha<T, TAM_MAX>::desempilha() {
    if (topo == 0) {
        throw std::invalid_argument("1");
    }
    return pilha[--topo];
}

template <class T, size_t TAM_MAX>
bool Pilha<T, TAM_MAX>::pilha_esta_cheia() {
    return (topo == TAM_MAX);
}

template <class T, size_t TAM_MAX>
bool Pilha<T, TAM_MAX>::pilha_esta_vazia() {
    return (topo == 0);
}

template <class T, size_t TAM_MAX>
void Pilha<T, TAM_MAX>::troca() {
    if (topo < 2) {
        throw std::length_error("1");
    }
    std::swap(pilha[topo - 1], pilha[topo - 2]);
}

template <class T, size_t TAM_MAX>
size_t Pilha<T, TAM_MAX>::tamanho() {
    return topo;
}

template <class T, size_t TAM_MAX>
T Pilha<T, TAM_MAX>::top() {
    if (topo == 0) {
        throw std::out_of_range("1");
    }
    return pilha[topo - 1];
}
