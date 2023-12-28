#include "../include/matrix.h"
#include <iostream>

Matriz::Matriz(const std::vector<std::vector<double>>& dados) : elementos(dados) {}

void Matriz::print() {
    for (const std::vector<double>& linha : elementos) {
        for (const double& elemento : linha) {
            std::cout << elemento << " ";
        }
        std::cout << "\n";
    }
}

Matriz Matriz::operator+(const Matriz& obj) {
    if (obj.elementos.size() != elementos.size() || obj.elementos[0].size() != elementos[0].size()) {
        throw std::invalid_argument("1");
    }

    std::vector<std::vector<double>> res(elementos.size(), std::vector<double>(elementos[0].size(), 0.0));

    for (size_t i = 0; i < elementos.size(); ++i) {
        for (size_t j = 0; j < elementos[0].size(); ++j) {
            res[i][j] = elementos[i][j] + obj.elementos[i][j];
        }
    }

    return Matriz(res);
}

Matriz Matriz::operator-(const Matriz& obj) {
    if (obj.elementos.size() != elementos.size() || obj.elementos[0].size() != elementos[0].size()) {
        throw std::invalid_argument("1");
    }

    std::vector<std::vector<double>> res(elementos.size(), std::vector<double>(elementos[0].size(), 0.0));

    for (size_t i = 0; i < elementos.size(); ++i) {
        for (size_t j = 0; j < elementos[0].size(); ++j) {
            res[i][j] = elementos[i][j] - obj.elementos[i][j];
        }
    }

    return Matriz(res);
}

Matriz Matriz::operator*(double a) {
    std::vector<std::vector<double>> res(elementos.size(), std::vector<double>(elementos[0].size(), 0.0));

    for (size_t i = 0; i < elementos.size(); ++i) {
        for (size_t j = 0; j < elementos[0].size(); ++j) {
            res[i][j] = elementos[i][j] * a;
        }
    }

    return Matriz(res);
}

Matriz Matriz::operator/(const Matriz& obj) {
    if (elementos[0].size() != obj.elementos.size()) {
        throw std::invalid_argument("1");
    }

    std::vector<std::vector<double>> res(elementos.size(), std::vector<double>(obj.elementos[0].size(), 0.0));

    for (size_t i = 0; i < elementos.size(); ++i) {
        for (size_t j = 0; j < obj.elementos[0].size(); ++j) {
            for (size_t k = 0; k < elementos[0].size(); ++k) {
                res[i][j] += elementos[i][k] * obj.elementos[k][j];
            }
        }
    }

    return Matriz(res);
}

Matriz Matriz::transpor() {
    std::vector<std::vector<double>> transposta(elementos[0].size(), std::vector<double>(elementos.size(), 0.0));

    for (size_t i = 0; i < elementos.size(); ++i) {
        for (size_t j = 0; j < elementos[0].size(); ++j) {
            transposta[j][i] = elementos[i][j];
        }
    }

    return Matriz(transposta);
}

MatrizQ::MatrizQ(const std::vector<std::vector<double>>& dados) : Matriz(dados) {}

double MatrizQ::trace() {
    double tr = 0.0;
    for (size_t i = 0; i < elementos.size(); ++i) {
        tr += elementos[i][i];
    }
    return tr;
}

MatrizT::MatrizT(const std::vector<std::vector<double>>& dados) : MatrizQ(dados) {}

double MatrizT::determinante() const {
    double det = 1.0;
    for (size_t i = 0; i < elementos.size(); ++i) {
        det *= elementos[i][i];
    }
    return det;
}

MatrizD::MatrizD(const std::vector<double>& valoresDiagonal) : MatrizT(criarMatrizDiagonal(valoresDiagonal)) {}

Matriz MatrizD::operator-(const MatrizD& obj) {
    std::vector<std::vector<double>> res(elementos.size(), std::vector<double>(elementos[0].size(), 0.0));

    res = obj.elementos;
    for (size_t i = 0; i < elementos.size(); ++i) {
        res[i][i] -= elementos[i][i];
    }
    return Matriz(res);
}

Matriz MatrizD::operator+(const MatrizD& obj) {
    std::vector<std::vector<double>> res(elementos.size(), std::vector<double>(elementos[0].size(), 0.0));

    res = obj.elementos;
    for (size_t i = 0; i < elementos.size(); ++i) {
        res[i][i] += elementos[i][i];
    }
    return Matriz(res);
}

Matriz MatrizD::operator*(double a) {
    std::vector<std::vector<double>> res(elementos.size(), std::vector<double>(elementos[0].size(), 0.0));

    res = elementos;
    for (size_t i = 0; i < elementos.size(); ++i) {
        res[i][i] *= a;
    }
    return Matriz(res);
}

std::vector<std::vector<double>> MatrizD::criarMatrizDiagonal(const std::vector<double>& valoresDiagonal) {
    size_t tamanho = valoresDiagonal.size();
    std::vector<std::vector<double>> matrizDiagonal(tamanho, std::vector<double>(tamanho, 0.0));

    for (size_t i = 0; i < tamanho; ++i) {
        matrizDiagonal[i][i] = valoresDiagonal[i];
    }

    return matrizDiagonal;
}
