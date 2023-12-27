#include <vector>
#include <typeinfo>

class Matriz{
  protected:
    std::vector<std::vector<double>> elementos;

  public:
    Matriz(const std::vector<std::vector<double>>& dados):
      elementos(dados){}
    
    Matriz operator+(const Matriz& obj){
      if (obj.elementos.size() != elementos.size() ||obj.elementos[0].size() != elementos[0].size()){
        throw std::invalid_argument("1")
      }
      std::vector<std::vector<double>> res(elementos.size(),
          std::vector<double>(elementos[0].size(), 0.0));
      if (typeid(*this) == typeid(MatrizD)){

      }
      else if (typeid(obj) == typeid(MatrizD)){

      }

      else if (typeid(*this) == typeid(MatrizTS)){
        
      }
      else if (typeid(obj) == typeid(MatrizTS)){

      }

      else if (typeid(*this) == typeid(MatrizTI)){
        
      }
      else if (typeid(obj) == typeid(MatrizTI)){

      }
      else { 
        for (size_t i = 0; i < elementos.size(); i++){
          for (size_t j = 0; j < elementos[0].size(); j++){
            res[i][j] = elementos[i][j] + obj.elementos[i][j];
          }
        }

      }
    } 
  void somaMatrizD(const MatrizQ& matrizQ, const MatrizD& matrizD, std::<vector<std::vector<double>>& res){


  }
  void somaMatrizTS(const MatrizQ& matrizQ, const MatrizTS& matrizTS, std::<vector<std::vector<double>>& res){

  }
  void somaMatrizTI(const MatrizQ& matrizQ, const MatrizTI& matrizTI, std::<vector<std::vector<double>>& res){

  }
  
};

class MatrizQ: public Matriz{
  public:
    MatrizQuad(const std::vector<std::vector<double>>& dados):
      Matriz(dados){}

}
