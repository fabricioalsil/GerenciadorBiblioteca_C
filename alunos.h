#ifndef ALUNOS_H_INCLUDED
#define ALUNOS_H_INCLUDED

#include "cabecalho.h"

void flush_in();

void continuar();

void imprimir_todos_alunos(struct alunos *cab_alunos);

struct alunos *busca_aluno(struct alunos *cab, int id);

struct alunos *busca_aluno_ant(struct alunos *cab, int id, struct alunos **ant);

void imprimir_aluno(struct alunos *cab);

void inserir_aluno(struct alunos *cab, int *id_aluno, int *qnt_aluno);

void remover_aluno(struct alunos *cab, int *qnt_aluno);

#endif // ALUNOS_H_INCLUDED
