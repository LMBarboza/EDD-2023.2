#include <array>
#include <stdexcept>

template <class T, size_t TAM_MAX>
class Pilha {
private:
    std::array<T, TAM_MAX> pilha;
    size_t topo;

public:
    Pilha();
    void empilha(T dado);
    T desempilha(void);
    bool pilha_esta_cheia(void);
    bool pilha_esta_vazia(void);
    size_t tamanho(void);  
};
