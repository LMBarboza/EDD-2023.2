Esse projeto é dividido em dois diretórios:
* /data: Contém os dados utilizados no problema e o arquivo responsável por gerar os dados
* /src: Arquivo principal com a classe MergeSortExterno

No diretório /data, o programa para gerar dados simulados de DRE, números inteiros de 9 dígitos, recebe a quantidade de registros a serem gerados do usuário.
Os números são criados aleatoriamente usando o módulo random do Python e o arquivo com os dados, chamado DRE.csv, é gerado.

Já no arquivo main.cpp, no diretório /src, está implementada a classe MergeSortExterno. Seu construtor recebe como argumentos o arquivo contendo os dados as serem ordenados, o nome do arquivo de saída ordenado e o tamanho de cada uma das runs. A classe possui 4 métodos necessários para ordenação de registros em memória secundária.
O primeiro método cria as runs a partir do arquivo completo, as ordena, a partir do número do DRE, e as armazena em arquivos temporaŕios. Depois, é chamado o método para realizar o merge desses arquivos temporários ordenados, esse método depende de um segundo método para unir duas runs. Por fim, o arquivo completo ordenado é retornado para o diretório /data.

O programa necessita da biblioteca pandas. Para instalar os pacotes necessários, rode "make install" e para rodar o programa rode "make run".
