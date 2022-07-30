#ifndef ALUNOS_H_INCLUDED
#define ALUNOS_H_INCLUDED

#include "cabecalho.h"

void flush_in(); //limpa o buffer de entrada

void continuar(); //pausa a tela para facilitar a visualizacao das saidas

void imprimir_todos_alunos(struct alunos *cab_alunos); //varre a lista imprimindo todas as posicoes

struct alunos *busca_aluno(struct alunos *cab, int id); //encontra na lista o aluno que tenha ID maior ou igual ao necessario

struct alunos *busca_aluno_ant(struct alunos *cab, int id, struct alunos **ant); //encontra na lista o aluno que tenha ID maior ou igual ao necessario e tambem o anterior

void imprimir_aluno(struct alunos *cab); //imprime um aluno pelo ID inserido

void inserir_aluno(struct alunos *cab, int *id_aluno, int *qnt_aluno); //adiciona novo aluno

void remover_aluno(struct alunos *cab, int *qnt_aluno); //remove um aluno

#endif // ALUNOS_H_INCLUDED
