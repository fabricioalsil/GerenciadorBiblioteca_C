#ifndef ARQUIVO_H_INCLUDED
#define ARQUIVO_H_INCLUDED

#include "cabecalho.h"

void criptografar(char *palavra, int senha);//funcao responsavel por criptografar as palavras a serem escritas no arquivo

void descriptografar(char *palavra, int senha);//funcao responsavel por descriptografar as palavras lidas do arquivo

//As tres proximas funcoes sao referentes a iniciacao das listas encadeadas a partir dos documentos salvo:

void iniciar_aluno(struct alunos *cab_alunos, int *id_alunos, int *qnt_alunos, int senha);

void iniciar_livro(struct livros *cab_livros, int *id_livros, int *qnt_livros, int senha);

void iniciar_infraestrutura(struct infraestrutura *cab_infraestrutura, int *qnt_infraestrutura, int senha);

//As tres proximas funcoes sao referentes ao encerramento das listas encadeadas e escrita nos documentos:

void encerrar_aluno(struct alunos *cab_alunos, int id_alunos, int qnt_alunos, int senha);

void encerrar_livro(struct livros *cab_livros, int id_livros, int qnt_livros, int senha);

void encerrar_infraestrutura(struct infraestrutura *cab_infraestrutura, int qnt_infraestrutura, int senha);

#endif // ARQUIVO_H_INCLUDED
