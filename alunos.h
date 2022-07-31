#ifndef ALUNOS_H_INCLUDED
#define ALUNOS_H_INCLUDED

#include "cabecalho.h"

void flush_in(); //limpa o buffer de entrada lendo a linha inteira ate achar um \n

void continuar(); //pausa a tela para facilitar a visualizacao das saidas e aguarda um \n para continuar o codigo

void imprimir_todos_alunos(struct alunos *cab_alunos); //varre a lista imprimindo todas as posicoes ate achar NULL

struct alunos *busca_aluno(struct alunos *cab, int id); //encontra na lista o aluno que tenha ID maior ou igual ao necessario

struct alunos *busca_aluno_ant(struct alunos *cab, int id, struct alunos **ant); //encontra na lista o aluno que tenha ID maior ou igual ao necessario e tambem o anterior

void imprimir_aluno(struct alunos *cab); //imprime um aluno pelo ID inserido

void inserir_aluno(struct alunos *cab, int *id_aluno, int *qnt_aluno); //adiciona novo aluno utilizando id automatico e incrementando a quantidade total de alunos

void remover_aluno(struct alunos *cab, int *qnt_aluno); //remove um aluno e decrementa a quantidade total de alunos

#endif // ALUNOS_H_INCLUDED
