#include "arquivo.h"

void iniciar_aluno(struct alunos *cab_alunos, int *id_alunos, int *qnt_alunos){

    char *copiar;
    size_t tam = 1;
    int posicao;

    copiar = (char *) malloc (sizeof(char));

    FILE *arquivo;
    arquivo = fopen("aluno.txt", "r");

    getline(&copiar, &tam, arquivo);
    (*id_alunos) = atoi(copiar);
    getline(&copiar, &tam, arquivo);
    (*qnt_alunos) = atoi(copiar);
    struct alunos* p;
    struct alunos* ant = cab_alunos;
    for(int i=0; i<(*qnt_alunos); i++){
        p = ant->prox;
        p = (struct alunos *) malloc (sizeof(struct alunos));
        ant->prox = p;
        getline(&copiar, &tam, arquivo);
        p->id = atoi(copiar);
        posicao = getline(&p->nome, &tam, arquivo);
        p->nome[posicao - 1] = '\0';
        posicao = getline(&p->matricula, &tam, arquivo);
        p->matricula[posicao - 1] = '\0';
        getline(&copiar, &tam, arquivo);
        p->pendencia = atoi(copiar);
        p->prox = NULL;
        ant = p;
    }

    fclose(arquivo);
    return;
}

void iniciar_livro(struct livros *cab_livros, int *id_livros, int *qnt_livros){

    char *copiar;
    size_t tam = 1;
    int posicao;

    copiar = (char *) malloc (sizeof(char));

    FILE *arquivo;
    arquivo = fopen("livro.txt", "r");

    getline(&copiar, &tam, arquivo);
    (*id_livros) = atoi(copiar);
    getline(&copiar, &tam, arquivo);
    (*qnt_livros) = atoi(copiar);
    struct livros* p;
    struct livros* ant = cab_livros;
    for(int i=0; i<(*qnt_livros); i++){
        p = ant->prox;
        p = (struct livros *) malloc (sizeof(struct livros));
        ant->prox = p;
        getline(&copiar, &tam, arquivo);
        p->id = atoi(copiar);
        posicao = getline(&p->nome, &tam, arquivo);
        p->nome[posicao - 1] = '\0';
        getline(&copiar, &tam, arquivo);
        p->ano = atoi(copiar);
        posicao = getline(&p->categoria, &tam, arquivo);
        p->categoria[posicao - 1] = '\0';
        getline(&copiar, &tam, arquivo);
        p->estado = atoi(copiar);
        getline(&copiar, &tam, arquivo);
        p->id_aluno = atoi(copiar);
        p->prox = NULL;
        ant = p;
    }

    fclose(arquivo);
    return;
}

void iniciar_infraestrutura(struct infraestrutura *cab_infraestrutura, int *num_infraestrutura, int *qnt_infraestrutura){

    char *copiar;
    size_t tam = 1;

    copiar = (char *) malloc (sizeof(char));

    FILE *arquivo;
    arquivo = fopen("infraestrutura.txt", "r");

    getline(&copiar, &tam, arquivo);
    (*num_infraestrutura) = atoi(copiar);
    getline(&copiar, &tam, arquivo);
    (*qnt_infraestrutura) = atoi(copiar);
    struct infraestrutura *antr = cab_infraestrutura;
    struct infraestrutura *r;
    for(int i=0; i< (*qnt_infraestrutura); i++){
        r = antr->prox;
        r = (struct infraestrutura *) malloc (sizeof(struct infraestrutura));
        antr->prox = r;
        getline(&copiar, &tam, arquivo);
        r->id = atoi(copiar);
        getline(&copiar, &tam, arquivo);
        r->tipo = atoi(copiar);
        getline(&copiar, &tam, arquivo);
        r->estado = atoi(copiar);
        getline(&copiar, &tam, arquivo);
        r->id_aluno = atoi(copiar);
        r->prox = NULL;
        antr = r;
    }

    fclose(arquivo);
    return;
}

void encerrar_aluno(struct alunos *cab_alunos, int id_alunos, int qnt_alunos){

    FILE *arquivo;
    arquivo = fopen("aluno.txt", "w");

    fprintf(arquivo, "%d\n", id_alunos);
    fprintf(arquivo, "%d\n", qnt_alunos);
    struct alunos *p = cab_alunos->prox;
    struct alunos *ant = cab_alunos->prox;
    while(p != NULL){
    	fprintf(arquivo, "%d\n", p->id);
        fprintf(arquivo, "%s\n", p->nome);
        fprintf(arquivo, "%s\n", p->matricula);
        fprintf(arquivo, "%d\n", p->pendencia);
        p = p->prox;
        free(ant->nome);
        free(ant->matricula);
        free(ant);
        ant = p;
    }

    free(cab_alunos);
    fclose(arquivo);
    return;
}

void encerrar_livro(struct livros *cab_livros, int id_livros, int qnt_livros){

    FILE *arquivo;
    arquivo = fopen("livro.txt", "w");

    fprintf(arquivo, "%d\n", id_livros);
    fprintf(arquivo, "%d\n", qnt_livros);
    struct livros *p = cab_livros->prox;
    struct livros *ant = cab_livros->prox;
    while(p != NULL){
    	fprintf(arquivo, "%d\n", p->id);
    	fprintf(arquivo, "%s\n", p->nome);
    	fprintf(arquivo, "%d\n", p->ano);
    	fprintf(arquivo, "%s\n", p->categoria);
    	fprintf(arquivo, "%d\n", p->estado);
    	fprintf(arquivo, "%d\n", p->id_aluno);
        p = p->prox;
        free(ant->nome);
        free(ant->categoria);
        free(ant);
        ant = p;
    }

    free(cab_livros);
    fclose(arquivo);
    return;
}

void encerrar_infraestrutura(struct infraestrutura *cab_infraestrutura, int num_infraestrutura, int qnt_infraestrutura){

    FILE *arquivo;
    arquivo = fopen("infraestrutura.txt", "w");

    fprintf(arquivo, "%d\n", num_infraestrutura);
    fprintf(arquivo, "%d\n", qnt_infraestrutura);
    struct infraestrutura *r = cab_infraestrutura->prox;
    struct infraestrutura *antr = cab_infraestrutura->prox;
    while(r != NULL){
    	fprintf(arquivo, "%d\n", r->id);
    	fprintf(arquivo, "%d\n", r->tipo);
    	fprintf(arquivo, "%d\n", r->estado);
    	fprintf(arquivo, "%d\n", r->id_aluno);
        r = r->prox;
        free(antr);
        antr = r;
    }

    free(cab_infraestrutura);
    fclose(arquivo);
    return;
}
