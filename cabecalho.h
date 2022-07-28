#ifndef CABECALHO_H_INCLUDED
#define CABECALHO_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef __linux__
	#define CLEAR "clear"
#elif _WIN32
	#define CLEAR "cls"
#endif

struct alunos{  //definição dos structs necessários
    char *nome;
    char *matricula;
    int id;
    int pendencia;
    struct alunos* prox;
};

struct livros{
    char *nome;
    int ano;
    char *categoria;
    int id;
    int estado;
    int id_aluno;
    struct livros* prox;
};

struct infraestrutura{
    int id;
    int tipo;
    int estado;
    int id_aluno;
    struct infraestrutura* prox;
};

#include "alunos.h"
#include "livros.h"
#include "infraestrutura.h"
#include "arquivo.h"

#endif // CABECALHO_H_INCLUDED
