#ifndef LIVROS_H_INCLUDED
#define LIVROS_H_INCLUDED

#include "cabecalho.h"

void imprimir_todos_livros(struct livros *cab_livros, struct alunos *cab_alunos); //varre a lista imprimindo todas as posicoes ate NULL

struct livros *busca_livro(struct livros *cab, int id); //encontra na lista o livro que tenha ID maior ou igual ao necessario

struct livros *busca_livro_ant(struct livros *cab, int id, struct livros **ant); //encontra na lista o livro que tenha ID maior ou igual ao necessario e tambem o anterior

void imprimir_livro(struct livros *cab_livros, struct alunos *cab_alunos); //imprime um livro pelo ID inserido ou todos que tenham a categoria inserida

void inserir_livro(struct livros *cab, int *id_livro, int *qnt_livro);  //adiciona um novo livro com id automatico e incrementa a quantidade de livros

void remover_livro(struct livros *cab, int *qnt_livro); //remove um livro e decrementa a quantidade de livros

void emprestar_livro(struct alunos *cab_alunos, struct livros *cab_livros); //empresta um livro para um aluno aumentando o numero de pendencias do aluno e ocupando o livro

void devolver_livro(struct alunos *cab_alunos, struct livros *cab_livros); //devolve um livro emprestado decrementando o numero de pendencia do aluno

#endif // LIVROS_H_INCLUDED
