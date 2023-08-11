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

## 🔨 Funções
