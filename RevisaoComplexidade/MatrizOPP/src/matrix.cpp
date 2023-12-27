#include <vector>
#include <typeinfo>
#include <iostream>


class Matriz {
protected:
  std::vector<std::vector<double>> elementos;

public:
  Matriz(const std::vector<std::vector<double>>& dados) : elementos(dados) {}

  void print() const {
    for (const std::vector<double>& linha : elementos) {
      for (const double& elemento : linha) {
        std::cout << elemento << " ";
      }
      std::cout << "\n";
    }
  }

  Matriz operator+(const Matriz& obj) const {
    if (obj.elementos.size() != elementos.size() || obj.elementos[0].size() != elementos[0].size()) {
      throw std::invalid_argument("1");
    }
    std::vector<std::vector<double>> res(elementos.size(), std::vector<double>(elementos[0].size(), 0.0));
    if (typeid(*this) == typeid(MatrizD)) {
      somaMatrizD(static_cast<const MatrizD&>(obj), static_cast<const MatrizQ&>(*this), res);
    } else if (typeid(obj) == typeid(MatrizD)) {
      somaMatrizD(static_cast<const MatrizQ&>(*this), static_cast<const MatrizD&>(obj), res);
    } else {
      for (size_t i = 0; i < elementos.size(); ++i) {
        for (size_t j = 0; j < elementos[0].size(); ++j) {
          res[i][j] = elementos[i][j] + obj.elementos[i][j];
        }
      }
    }
    return Matriz(res);
  }

  Matriz operator-(const Matriz& obj) const {
    if (obj.elementos.size() != elementos.size() || obj.elementos[0].size() != elementos[0].size()) {
      throw std::invalid_argument("1");
    }
    std::vector<std::vector<double>> res(elementos.size(), std::vector<double>(elementos[0].size(), 0.0));
    if (typeid(*this) == typeid(MatrizD)) {
      difMatrizD(static_cast<const MatrizD&>(obj), static_cast<const MatrizQ&>(*this), res);
    } else if (typeid(obj) == typeid(MatrizD)) {
      difMatrizD(static_cast<const MatrizQ&>(*this), static_cast<const MatrizD&>(obj), res);
    } else {
      for (size_t i = 0; i < elementos.size(); ++i) {
        for (size_t j = 0; j < elementos[0].size(); ++j) {
          res[i][j] = elementos[i][j] - obj.elementos[i][j];
        }
      }
    }
    return Matriz(res);
  }

  void difMatrizD(const MatrizQ& matrizQ, const MatrizD& matrizD, std::vector<std::vector<double>>& res) const {
    res = matrizQ.elementos;
    for (size_t i = 0; i < elementos.size(); ++i) {
      res[i][i] -= matrizD.elementos[i][i];
    }
  }

  void somaMatrizD(const MatrizQ& matrizQ, const MatrizD& matrizD, std::vector<std::vector<double>>& res) const {
    res = matrizQ.elementos;
    for (size_t i = 0; i < elementos.size(); ++i) {
      res[i][i] += matrizD.elementos[i][i];
    }
  }

  Matriz operator*(double a) const {
    std::vector<std::vector<double>> res(elementos.size(), std::vector<double>(elementos[0].size(), 0.0));
    if (typeid(*this) == typeid(MatrizD)) {
      mulMatrizD(static_cast<const MatrizD&>(*this), res, a);
    } else {
      for (size_t i = 0; i < elementos.size(); ++i) {
        for (size_t j = 0; j < elementos[0].size(); ++j) {
          res[i][j] = elementos[i][j] * a;
        }
      }
    }
    return Matriz(res);
  }

  void mulMatrizD(const MatrizD& matrizD, std::vector<std::vector<double>>& res, double a) const {
    res = matrizD.elementos;
    for (size_t i = 0; i < elementos.size(); ++i) {
      res[i][i] *= a;
    }
  }

  Matriz operator/(const Matriz& obj) const {
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

  Matriz transpor() const {
    std::vector<std::vector<double>> transposta(elementos[0].size(), std::vector<double>(elementos.size(), 0.0));
    for (size_t i = 0; i < elementos.size(); ++i) {
      for (size_t j = 0; j < elementos[0].size(); ++j) {
        transposta[j][i] = elementos[i][j];
      }
    }

    return Matriz(transposta);
  }
};

class MatrizQ : public Matriz {
public:
  MatrizQ(const std::vector<std::vector<double>>& dados) : Matriz(dados) {}

  double trace() const {
    double tr = 0.0;
    for (size_t i = 0; i < elementos.size(); ++i) {
      tr += elementos[i][i];
    }
    return tr;
  }
};

class MatrizT : public MatrizQ {
public:
  MatrizT(const std::vector<std::vector<double>>& dados) : MatrizQ(dados) {}

  double determinante() const {
    double det = 1.0;
    for (size_t i = 0; i < elementos.size(); ++i) {
      det *= elementos[i][i];
    }
    return det;
  }
};

class MatrizD : public MatrizT {
public:
  MatrizD(const std::vector<double>& valoresDiagonal) : MatrizT(criarMatrizDiagonal(valoresDiagonal)) {}

private:
  static std::vector<std::vector<double>> criarMatrizDiagonal(const std::vector<double>& valoresDiagonal) {
    size_t tamanho = valoresDiagonal.size();
    std::vector<std::vector<double>> matrizDiagonal(tamanho, std::vector<double>(tamanho, 0.0));

    for (size_t i = 0; i < tamanho; ++i) {
      matrizDiagonal[i][i] = valoresDiagonal[i];
    }

    return matrizDiagonal;
  }
};
