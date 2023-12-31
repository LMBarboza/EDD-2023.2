#include "../include/matrix.h"
#include <vector>
#include <iostream>

Matriz inputMatriz(void) {
    std::cout << "Insira o número de linhas e colunas: ";
    size_t lin, col;
    std::cin >> lin >> col;

    std::vector<std::vector<double>> dados(lin, std::vector<double>(col, 0.0));

    std::cout << "Insira a matriz linha a linha:\n";
    for (size_t i = 0; i < lin; ++i) {
        for (size_t j = 0; j < col; ++j) {
            std::cout << "Matriz[" << i << "][" << j << "]: ";
            std::cin >> dados[i][j];
        }
    }

    std::cout << "Insira o tipo de matriz (comum, quadrada, triangular, diagonal): ";
    std::string matrizTipo;
    std::cin >> matrizTipo;

    if (matrizTipo == "comum") {
        return Matriz(dados);
    } else if (matrizTipo == "quadrada") {
        return MatrizQ(dados);
    } else if (matrizTipo == "triangular") {
        return MatrizT(dados);
    } else if (matrizTipo == "diagonal") {
        return MatrizD(dados[0]);
    }
}

int main() {
  std::cout << "Insira o número de matrizes (1 ou 2): ";
  size_t numMatriz;
  std::cin >> numMatriz;

  if (numMatriz == 1) {
    std::cout << "Insira o número de linhas e colunas: ";
    size_t lin, col;
    std::cin >> lin >> col;

    std::vector<std::vector<double>> dados(lin, std::vector<double>(col, 0.0));

    std::cout << "Insira a matriz linha a linha:\n";
    for (size_t i = 0; i < lin; ++i) {
      for (size_t j = 0; j < col; ++j) {
        std::cout << "Matriz[" << i << "][" << j << "]: ";
        std::cin >> dados[i][j];
      }
    }

    std::cout << "Insira o tipo de matriz (comum, quadrada, triangular, diagonal): ";
    std::string matrizTipo;
    std::cin >> matrizTipo;

    if (matrizTipo == "comum") {
      std::cout << "Escolhe uma operação:\n";
      std::cout << "1. Multiplicar por escalar\n";
      std::cout << "2. Transposta\n";
      int choice;
      std::cin >> choice;
      Matriz matriz(dados);

      if (choice == 1) {
        double scalar;
        std::cout << "Insira um escalar: ";
        std::cin >> scalar;

        Matriz result = matriz * scalar;
        result.print();
      } else if (choice == 2) {
        Matriz result = matriz.transpor();
        result.print();
      }
    } else if (matrizTipo == "quadrada") {
      std::cout << "Escolhe uma operação:\n";
      std::cout << "1. Multiplicar por escalar\n";
      std::cout << "2. Transposta\n";
      std::cout << "3. Traço\n";
      int choice;
      std::cin >> choice;
      MatrizQ matrizQ(dados);

      if (choice == 1) {
        double scalar;
        std::cout << "Insira um escalar: ";
        std::cin >> scalar;

        Matriz result = matrizQ * scalar;
        result.print();
      } else if (choice == 2) {
        Matriz result = matrizQ.transpor();
        result.print();
      } else if (choice == 3) {
        double resultQ = matrizQ.trace();
        std::cout << resultQ << std::endl;
      }
    } else if (matrizTipo == "triangular") {
      std::cout << "Escolhe uma operação:\n";
      std::cout << "1. Multiplicar por escalar\n";
      std::cout << "2. Transposta\n";
      std::cout << "3. Traço\n";
      std::cout << "4. Determinante\n";
      int choice;
      std::cin >> choice;
      MatrizT matrizT(dados);

      if (choice == 1) {
        double scalar;
        std::cout << "Insira um escalar: ";
        std::cin >> scalar;

        Matriz result = matrizT * scalar;
        result.print();
      } else if (choice == 2) {
        Matriz result = matrizT.transpor();
        result.print();
      } else if (choice == 3) {
        double resultQ = matrizT.trace();
        std::cout<< resultQ << std::endl;
      } else if (choice == 4) {
        double resultT = matrizT.determinante();
        std::cout << resultT << std::endl;
      }
    } else if (matrizTipo == "diagonal") {
      std::cout << "Escolhe uma operação:\n";
      std::cout << "1. Multiplicar por escalar\n";
      std::cout << "2. Transposta\n";
      std::cout << "3. Traço\n";
      std::cout << "4. Determinante\n";
      int choice;
      std::cin >> choice;
      MatrizD matrizD(dados[0]);

      if (choice == 1) {
        double scalar;
        std::cout << "Insira um escalar: ";
        std::cin >> scalar;

        Matriz result = matrizD * scalar;
        result.print();
      } else if (choice == 2) {
        Matriz result = matrizD.transpor();
        result.print();
      } else if (choice == 3) {
        double resultQ = matrizD.trace();
        std::cout << resultQ << std::endl;
      } else if (choice == 4) {
        double resultT = matrizD.determinante();
        std::cout << resultT << std::endl;
      }
    }
  }
  else if (numMatriz == 2){
    Matriz matrizA = inputMatriz();
    Matriz matrizB = inputMatriz();
    std::cout << "Escolha uma operação:\n";
    std::cout << "1. Multiplicação Matricial\n";
    std::cout << "2. Adição \n";
    std::cout << "3. Subtração\n";
    int choice;
    std::cin >> choice;

    if (choice == 1) {
      Matriz result = matrizA / matrizB;
      result.print();
        } 
    else if (choice == 2) {
      Matriz result =  matrizA + matrizB; 
      result.print();
        }
    else if (choice == 3) {
      Matriz result = matrizA - matrizB;
      result.print();
    }

  }
  return 0;
}
