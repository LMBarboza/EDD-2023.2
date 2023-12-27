#include "../include/matrix.h"
#include <vector>

int main() {
    std::vector<std::vector<double>> dadosMatrizA = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    std::vector<std::vector<double>> dadosMatrizB = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};

    Matriz matrizA(dadosMatrizA);
    MatrizD matrizB({1, 2, 3});

    Matriz resultado = matrizA + matrizB;
    resultado.print();

    resultado = matrizA * 2.0;
    resultado.print();

    return 0;
}

