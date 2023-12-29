Esse diretório está dividido da seguinte maneira:
* /bin: Binários para execução do programa principal (compilado pelo g++ sem flags)
* /include: Header file para o template pilha
* /src: Código fonte do programa principal

No arquivo stack.h, tempos a implementação de uma classe genérica para uma pilha. Essa classe possui como atributos um vetor armazenando os elementos da pilha, o tamanho máximo da pilha e um índice para o topo dela. No construtor, o tamanho e o topo são inicializados e o vetor dos elementos é redimensionado.

Além do construtor, a classe possui outros 7 métodos:
* Empilha: Adiciona elemento ao topo da pilha
* Desempilha: Remove elemento do topo da pilha
* Pilha está cheia: Verifica se a pilha está cheia
* Pilha está vazia: Verifica se a pilha está vazia
* Troca: Troca os dois elementos no topo da pilha
* Tamanho: Retorna o tamanho da pilha
* Top: Retorna o elemento no topo da lista

No programa principal, o usuário fornece como input a quantidade de discos para o problema da torre de Hanoi. Três pilhas são instanciada e a pilha inicial é inicializada com discos de tamanho decrescente. Essas pilhas são fornecidas à função que resolve o problema de maneira recursiva e durante cada passo a pilha sendo modificada é impressa.

O programa pode ser executado pelo arquivo a.out no diretório /bin ou compilado novamente usando o comando "make all".
