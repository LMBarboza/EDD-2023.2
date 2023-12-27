#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include <stdexcept>

class Matriz {
public:
    std::vector<std::vector<double>> elementos;

    Matriz(const std::vector<std::vector<double>>& dados);

    void print();

    virtual Matriz operator+(const Matriz& obj);

    virtual Matriz operator-(const Matriz& obj);

    virtual Matriz operator*(double a);

    Matriz operator/(const Matriz& obj);

    Matriz transpor();

};

class MatrizQ : public Matriz {
public:
    MatrizQ(const std::vector<std::vector<double>>& dados);

    double trace();

};

class MatrizT : public MatrizQ {
public:
    MatrizT(const std::vector<std::vector<double>>& dados);

    double determinante() const;

};

class MatrizD : public MatrizT {
public:
    MatrizD(const std::vector<double>& valoresDiagonal);

    Matriz operator-(const MatrizD& obj);

    Matriz operator+(const MatrizD& obj);

    Matriz operator*(double a);

private:
    static std::vector<std::vector<double>> criarMatrizDiagonal(const std::vector<double>& valoresDiagonal);

};

#endif // MATRIX_H

