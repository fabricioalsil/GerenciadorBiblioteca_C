#ifndef ARQUIVO_H_INCLUDED
#define ARQUIVO_H_INCLUDED

#include "cabecalho.h"

//As tres proximas funcoes sao referentes a iniciacao das listas encadeadas a partir dos documentos salvo:

void iniciar_aluno(struct alunos *cab_alunos, int *id_alunos, int *qnt_alunos);

void iniciar_livro(struct livros *cab_livros, int *id_livros, int *qnt_livros);

void iniciar_infraestrutura(struct infraestrutura *cab_infraestrutura, int *num_infraestrutura, int *qnt_infraestrutura);

//As tres proximas funcoes sao referentes ao encerramento das listas encadeadas para os documentos:

void encerrar_aluno(struct alunos *cab_alunos, int id_alunos, int qnt_alunos, int senha);

void encerrar_livro(struct livros *cab_livros, int id_livros, int qnt_livros, int senha);

void encerrar_infraestrutura(struct infraestrutura *cab_infraestrutura, int num_infraestrutura, int qnt_infraestrutura, int senha);

#endif // ARQUIVO_H_INCLUDED
