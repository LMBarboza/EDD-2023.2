#include <vector>
#include <iostream>

class MatrizQ; // Forward declaration
class MatrizD; // Forward declaration

class Matriz {
protected:
  std::vector<std::vector<double>> elementos;

public:
  Matriz(const std::vector<std::vector<double>>& dados);

  void print() const;

  Matriz operator+(const Matriz& obj) const;
  Matriz operator-(const Matriz& obj) const;
  void difMatrizD(const class MatrizQ& matrizQ, const class MatrizD& matrizD, std::vector<std::vector<double>>& res) const;
  void somaMatrizD(const class MatrizQ& matrizQ, const class MatrizD& matrizD, std::vector<std::vector<double>>& res) const;
  Matriz operator*(double a) const;
  void mulMatrizD(const class MatrizD& matrizD, std::vector<std::vector<double>>& res, double a) const;
  Matriz operator/(const Matriz& obj) const;
  Matriz transpor() const;
};

class MatrizQ : public Matriz {
public:
  MatrizQ(const std::vector<std::vector<double>>& dados);

  double trace() const;
};

class MatrizT : public MatrizQ {
public:
  MatrizT(const std::vector<std::vector<double>>& dados);

  double determinante() const;
};

class MatrizD : public MatrizT {
public:
  MatrizD(const std::vector<double>& valoresDiagonal);

private:
  static std::vector<std::vector<double>> criarMatrizDiagonal(const std::vector<double>& valoresDiagonal);
};

