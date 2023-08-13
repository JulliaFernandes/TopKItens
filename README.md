<h1 align="center" font-size="200em"><b> Top K Itens </b></h1>

<div align = "center" >
<!-- imagem -->

[![requirement](https://img.shields.io/badge/IDE-Visual%20Studio%20Code-informational)](https://code.visualstudio.com/docs/?dv=linux64_deb)
![Make](https://img.shields.io/badge/Compilacao-Make-orange)
![Linguagem](https://img.shields.io/badge/Linguagem-C%2B%2B-blue)
</div>

## 📌Sumário
- [Introdução](#Introdução)
- [Objetivos](#Objetivos)
- [Arquivos](#Arquivos)
- [Resolução do Problema](#Resolução-do-problema)
- [Funções](#Funções)
- [Resultados](#Resultados)
- [Conclusão](#Conclusão)
- [Referências](#Referências)
- [Compilação e execução](#Compilação-e-execução)
- [Contato](#Contato)

## ✒️Introdução
<p align="justify">
Este é um programa desenvolvido em C++ para a disciplina de Algoritmos e Estruturas de Dados II. <br>
Neste problema, é preciso encontrar os k itens mais valiosos de uma coleção de dados. Logo, utiliza-se o hash para contar a frequência de todos os itens, enquanto o heap se aplica na manutenção de uma lista dos k itens de maior valor.
</p>

## 💻Objetivos

O objetivo desta atividade consiste em criar uma tabela de dispersão (hash) para contar a frequência de cada elemento tokenizado
da coleção de dados de entrada, logo apos criar uma árvore de prioridades (heap) de tamanho k e inserir os primeiros k elementos do
hash nela. Ao final ao fazer a combinação do uso de hash e da heap para manter a lista dos k elementos com maiores valores presentes nos textos. Para alcançar esse objetivo, é fundamental realizar um cuidadoso projeto das estruturas de dados e dos algoritmos correspondentes, com o intuito de garantir o resultado esperado.

<strong><h4>Condições impostas: </h4></strong>
- A quantidade de textos a serem processados deve ser colocado na variável `ARQ`, presente na `main.cpp` linha XX.
- O código realiza a leitura de arquivos ja existentes na pasta `data`, que devem ser intitulados como `input1`, `input2`..., ate a quantidade de arquivos desejada.
- As K palavras mais frequentes que deseja saber deve ser informado tambem, na varivel `K` presente no arquivo `main.cpp` linha XX.
- Existe um arquivo de ```stop words``` para análise. Sendo as stop words artigos e conjunções que podem ser alteradas de acordo com a preferência do usuário.
- A saída vai fornecer os dados após a análise do arquivo de entrada.
 
## 📄Arquivos
- <strong>Main.cpp:</strong> Leitura dos arquivos ```input1.txt```, ```stopwords.txt```,  tempo de execução do código e é realizada a chamada das funções necessários para o funcionamento.
- <strong>header.cpp:</strong> Inclusão das bibliotecas e arquivos utilizados.
- <strong>functions.hpp:</strong> Declaração das funções.
- <strong>functions.cpp:</strong> Desenvolvimento das funções. 
- <strong>data/input.txt:</strong> Texto de entrada.
- <strong>data/stopwords.txt:</strong> Stop words, como por exemplo, para artigo (a, o, as,os) e para conjunções (e, ou).

## 🔨Resolução do problema
Foi pensado em qual maneira poderia ser realizado a leitura dos texto de forma eficiente e rapida, com isso foi achado uma expressão regular nominada Regex. As expressoes regulares vem exatamente com o intuito de serem usadas em textos para manipular e encontrar padroes, são muito utlizadas para achar palavras reservadas e tokens especificos, sendo isso exataemente oque é preciso para a realização dessa atividade.
O Regex foi usado no contexto no qual iria processar somente as palavras que eram consideradas expressoes regulares, isso é todas as palvras do texto em exceto os caracteres de pontuação.
Entao inicialmente é feito a abertura do arquivo `stopwords.txt` e armazenado todas as palavras em uma hash para ser usado mais a frente, logo apos é feito a abertura do texto a ser analisado, com isso é lido linha a linha e sendo processado pelo regex para obter somente as expressoes regulares, a cada hora que encontrasse algo não estivesse contido no regex era significado que de havia encontrado uma palavra e entao poderia colocar na hash, esse processamento é feito em todos os textos e fazendo a comparação tambem se a palavra encontrada nao é uma StopWord, pois se for nao ira ser adicioando a hash, pois devemos desconsiderar as palavras contidas no arquivo de StopWords. 
Logo apos todos os textos terem sido lidos e as palavras terem sido devidamente contabilizadas e adicionadas a hash é colocada as K, quantidade desejada pelo usuario, primeiras palavras da hash em um vetor e realizado a comparação com cada item restante da hash para obter somente as K mais frequentes na hash.


## 🔨 Funções
- <strong>readText:</strong> Processamento dos textos baseados nas expressoes regulares.
- <strong>treatments:</strong> É uma função para o tratamento de caracteres que deveriam ser desconsiderados nos texto.
- <strong>fillHeap:</strong> É a função que ira adicionar as K primeiras da hash em um vetor e feita a comparação com o restante da hash, o processo de adicionar na hash e fazer a comparação é feita com o heapify do heap_sort, logo depois de comparado com todos os elementos da hash é chamado uma função de ordenação para o vetor, o QuickSort ja que é um dos melhores algoritmos de ordenação e com uma boa complexidade.


## 🎯Resultados
É mostrado ao usuario em formato de tabela as K palavras mais frequentes na cor vermelha e suas respectivas frequencias. 
Foto do Output

## ✔️Conclusão
A partir dessa atividade foi possivel aprender novas maneiras de otimização na leitura de textos e mlehoras nessas praticas, foi possivel aprimorar os conehcimentos na tokenização e aprender tmabem novas estruturas para serem utlizdas como o Regex. Uma boa atividade que agrgou meus conheciemntos

## ✔️Referências
- https://www.geeksforgeeks.org/regex-regular-expression-in-c/
- https://pt.wikipedia.org/wiki/Express%C3%A3o_regular


## 👾Compilação e execução

O codigo disponibilizado foi criado e executado em notebook Acer core i5 Aspire M com sistema operacional Windowns 10 e utlizado um terminal de comando com WSL.

O codigo possui um arquivo Makefile que realiza todo o procedimento de compilação e execução. Para tanto, temos as seguintes diretrizes de execução:


| Comando                |  Função                                                                                           |                     
| -----------------------| ------------------------------------------------------------------------------------------------- |
|  `make clean`          | Apaga a última compilação realizada contida na pasta build                                        |
|  `make`                | Executa a compilação do programa utilizando o g++, e o resultado vai para a pasta build           |
|  `make run`            | Executa o programa da pasta build após a realização da compilação                                 |


## ✉️Contato
<div>
 <br><p align="justify"> Jullia Fernandes Felizardo</p>
 <a href="https://t.me/JulliaFernandes">
 <img align="center" src="https://img.shields.io/badge/Telegram-2CA5E0?style=for-the-badge&logo=telegram&logoColor=white"/> 
 </div>
<a style="color:black" href="mailto:julliacefet@gmail.com?subject=[GitHub]%20Source%20Dynamic%20Lists">
✉️ <i>julliacefet@gmail.com</i>
</a>
