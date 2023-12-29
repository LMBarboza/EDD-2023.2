Esse diretório está dividido da seguinte maneira:
* /bin: Binários para execução do programa principal (compilado pelo g++ sem flags)
* /include: Header file para as matrizes 
* /src: Código fonte do programa principal e matriz

O programa contém:
* Uma classe base Matriz, que recebe um vetor de vetores da STL como elementos
* Uma classe filho MatrizQ para matrizes quadradas que herda de Matriz
* Uma classe MatrizT para matrizes triangulares que herda de MatrizQ
* Uma classe MatrizD para matrizes diagonais que herdda de MatrizT

A classe base Matriz possui 6 métodos comuns a todos os filhos na hierarquia de herança:
* Imprimir a matriz
* Operações matriciais padrões:
  * Adição e Subtração entre matrizes
  * Multiplicação por escalar e multiplciação matricial
* Transpor a matriz

As classes MatrizQ e MatrizT possuem os métodos para calcular o traço e o determinante. Já a classe MatrizD possui operações matriciais especiais,
a fim de aproveitar a estrutura desse tipo de matriz. Isso é possível, pois essas operações são definidas como funções virtuais na classe base.

O menu interativo permite a inserção de matrizes pelo usuário. Primeiro, deve-se fornecer o número de matrizes que vão ser inseridas. Depois, as dimensões da matriz (
exemplo 2 2) e por fim os elementos da matriz. Após a construção da matriz, o menu perguntará, dependendo da quantidade de matrizes fornecidas, quais operações
o usuário deseja realizar.

O programa pode ser executado com o executável no diretório /bin. Caso seja necessário recompilar, execute o comando "make all".




