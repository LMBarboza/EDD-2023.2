O diretório está dividido em dois subdiretórios:
* /src: Onde está a classe HashTable e a função para remoção de registros duplicados
* /data: Onde está o código para gerar os dados com repetição

Neste problema, os dados contém um identificador (DRE), usado como chave de busca, e a nota associada ao aluno. O DRE é um inteiro de nove dígitos e a nota um float entre 0 e 10. A nota é amostrada de uma distribuição normal e arredondada para duas casas decimais. Além disso, o código pede ao usuário uma quantidade de registros repetidos necessários ao problema.

A classe HashTable possui dois atributos, tamanho e uma lista de tuplas para armazenar as chaves de buscas e o restante dos dados. A função de hash é o resto da divisão 
da chave pelo tamanho da lista. Essa função de hash performou bem no quesito de colisões e é muito mais simples de ser computada do que outras funções mais complexas, como o hash multiplicativo de Knuth. Para a resolução de colisões, é usado o linear probing, uma forma de endereçamento aberto.

A função para remoção de registros duplicados busca na hash table se há alguma entrada de alguma chave de busca já utilizada, caso ela não encontre, o registro será inserido na tabela.

As dependências podem ser instaladas rodando "make install" e o programa pode ser executado por "make run"


