#ifndef INFRAESTRUTURA_H_INCLUDED
#define INFRAESTRUTURA_H_INCLUDED

#include "cabecalho.h"

void imprimir_toda_infraestrutura(struct infraestrutura *cab_infraestrutura, struct alunos *cab_alunos); //varre a lista imprimindo todas as posicoes ate NULL

struct infraestrutura *busca_infraestrutura(struct infraestrutura *cab, int id); //encontra na lista a infraestrutura que tenha ID igual ao necessario

struct infraestrutura *busca_infraestrutura_ant(struct infraestrutura *cab, int id, struct infraestrutura **ant); //encontra na lista a infraestrutura que tenha ID igual ao necessario devolvendo tambem o anterior

void imprimir_infraestrutura(struct infraestrutura *cab, struct alunos *cab_alunos); //imprime uma infraestrutura pelo ID

void inserir_infraestrutura(struct infraestrutura *cab, int *qnt_infraestrutura); //insere uma nova infraestrutura incrementando a quantidade de infraestruturas

void remover_infraestrutura(struct infraestrutura *cab, int *qnt_infraestrutura); //remove uma infraestrutura decrementando a quantidade de infraestruturas

void emprestar_infraestrutura(struct infraestrutura *cab, struct alunos *cab_alunos); //ocupa uma infraestrutura aumentando o numero de pendencia do aluno

void devolver_infraestrutura(struct infraestrutura *cab, struct alunos *cab_alunos); //desocupa uma infraestrutura decrementando o numero de pendencia do aluno

#endif // INFRAESTRUTURA_H_INCLUDED
