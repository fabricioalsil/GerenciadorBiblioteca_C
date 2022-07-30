#include "infraestrutura.h"

//#include <stdio_ext.h>
//__fpurge(stdin);
//fflush(stdin);

void imprimir_toda_infraestrutura(struct infraestrutura *cab_infraestrutura, struct alunos *cab_alunos) { //percorre a lista printando todas as posições
    struct alunos *aluno;

    if (cab_infraestrutura->prox == NULL) {
        puts("Nenhuma infraestrutura cadastrada!");
        return;
    }

    struct infraestrutura *p = cab_infraestrutura->prox;
    puts("Infraestruturas cadastradas:");
    while (p != NULL) {
        if(p->tipo == 1)
            printf("Sala");
        else if(p->tipo == 2)
            printf("Computador");
        else if(p->tipo == 3)
            printf("Armario");
        printf("; ID: %d. ", p->id);
        if(p->estado == 0)
            puts("Disponivel!\n");
        else{
            aluno = busca_aluno(cab_alunos, p->id_aluno);
            printf("Ocupado pelo aluno de matricula: %s\n\n", aluno->matricula);
        }
        p = p->prox;
    }
}

struct infraestrutura *busca_infraestrutura(struct infraestrutura *cab, int id) { //percorre a lista procurando algum ID maior ou igual ao buscado retornando a posição atual
    struct infraestrutura *p = cab->prox;
    while (p != NULL && p->id != id)
        p = p->prox;
    return p;
}

struct infraestrutura *busca_infraestrutura_ant(struct infraestrutura *cab, int id, struct infraestrutura **ant) { //percorre a lista até achar um ID igual ou maior retornando a posição atual e anterior
    (*ant) = cab;
    struct infraestrutura *p = cab->prox;
    while (p != NULL && p->id != id) {
        (*ant) = p;
        p = p->prox;
    }
    return p;
}

void imprimir_infraestrutura(struct infraestrutura *cab, struct alunos *cab_alunos){ //imprime o aluno correspondente ao ID inserido
    struct alunos *aluno;

    int id;
    printf("Digite o ID que deseja buscar: ");
    scanf("%d", &id);
    flush_in();

    struct infraestrutura *p = busca_infraestrutura(cab, id);

    if(p != NULL && p->id == id){
        if(p->tipo == 1)
            printf("Sala");
        else if(p->tipo == 2)
            printf("Computador");
        else if(p->tipo == 3)
            printf("Armario");
        printf("; ID: %d. ", p->id);
        if(p->estado == 0)
            puts("Disponivel!\n");
        else{
            aluno = busca_aluno(cab_alunos, p->id_aluno);
            printf("Ocupado pelo aluno de matricula: %s\n\n", aluno->matricula);
        }
    }else{
        puts("ID nao encontrado.");
    }
}

void inserir_infraestrutura(struct infraestrutura *cab, int *num_infraestrutura, int *qnt_infraestrutura) { //adiciona nova infraestrutura
    struct infraestrutura *ant = NULL;
    int id;

    printf("Digite a ID da infraestrutura a ser cadastrada: ");
    scanf("%d", &id);
    flush_in();

    struct infraestrutura *p = busca_infraestrutura_ant(cab, id, &ant);

    if(p!=NULL && p->id == id){
        puts("ID ja cadastrado");
        return;
    }
    p = (struct infraestrutura *) malloc (sizeof(struct infraestrutura));
    p->prox = ant->prox;
    ant->prox = p;

    p->id = id;
    puts("Informe o tipo da infraestrutura sendo:");
    puts("1 - Salas");
    puts("2 - Computadores");
    puts("3 - Armarios");
    printf("Digite: ");
    scanf("%d", &p->tipo);
    flush_in();

    p->estado = 0;
    p->id_aluno = 0;

    if(p->tipo == 1)
        printf("Sala");
    else if(p->tipo == 2)
        printf("Computador");
    else if(p->tipo == 3)
        printf("Armario");
    puts(" cadastrado com sucesso!");
    (*num_infraestrutura)++;
    (*qnt_infraestrutura)++;
}

void remover_infraestrutura(struct infraestrutura *cab, int *qnt_infraestrutura) { //remove uma infraestrutura
    struct infraestrutura *ant = NULL;
    struct infraestrutura *p;
    int id;
    printf("Digite o ID da infraestrutura que deseja remover: ");
    scanf("%d", &id);
    flush_in();
    p = busca_infraestrutura_ant(cab, id, &ant);

    if (p != NULL) {
        if (p->estado == 0){
            ant->prox = p->prox;
            if(p->tipo == 1)
                printf("Sala");
            else if(p->tipo == 2)
                printf("Computador");
            else if(p->tipo == 3)
                printf("Armario");
            puts(" removido com sucesso!");
            (*qnt_infraestrutura)--;
            free(p);
        }else{
            if(p->tipo == 1)
                printf("Sala");
            else if(p->tipo == 2)
                printf("Computador");
            else if(p->tipo == 3)
                printf("Armario");
            puts(" esta sendo usado no momento!");
        }
    }else {
        printf("ID: %d nao foi encontrado!\n", id);
    }
}

void emprestar_infraestrutura(struct infraestrutura *cab, struct alunos *cab_alunos){ //ocupa uma infraestrutura
    int id_infraestrutura;
    int id_aluno;
    struct infraestrutura *infraestrutura;
    struct alunos *aluno;

    printf("Digite o ID da infraestrutura que deseja ocupar: ");
    scanf("%d", &id_infraestrutura);
    flush_in();

    infraestrutura = busca_infraestrutura(cab, id_infraestrutura);
    if(infraestrutura==NULL){
        puts("Nao encontrado");
        return;
    }if(infraestrutura->estado!=0){
        puts("A infraestrutura ja esta ocupada");
        return;
    }

    printf("Digite o ID do aluno que deseja ocupar a infraestrutura: ");
    scanf("%d", &id_aluno);
    flush_in();

    aluno = busca_aluno(cab_alunos, id_aluno);
    if(aluno==NULL || aluno->id!=id_aluno){
        puts("Aluno não encontrado");
        return;
    }

    puts("Infraestrutura ocupada com sucesso!");
    aluno->pendencia++;
    infraestrutura->id_aluno = aluno->id;
    infraestrutura->estado = 1;
}

void devolver_infraestrutura(struct infraestrutura *cab, struct alunos *cab_alunos){ //desocupa uma infraestrutura
    int id_infraestrutura;
    int id_aluno;
    struct infraestrutura *infraestrutura;
    struct alunos *aluno;

    printf("Digite o ID do aluno que deseja desocupar a infraestrutura: ");
    scanf("%d", &id_aluno);
    flush_in();

    aluno = busca_aluno(cab_alunos, id_aluno);
    if(aluno==NULL || aluno->id!=id_aluno){
        puts("Aluno nao encontrado");
        return;
    }if(aluno->pendencia == 0){
        puts("Aluno nao possui pendencias");
        return;
    }

    printf("Digite o ID da infraestrutura a ser desocupada: ");
    scanf("%d", &id_infraestrutura);
    flush_in();

    infraestrutura = busca_infraestrutura(cab, id_infraestrutura);
    if(infraestrutura==NULL){
        puts("Infraestrutura nao encontrada");
        return;
    }if(infraestrutura->estado == 0){
        puts("A infraestrutura ja se encontra disponivel");
        return;
    }if(infraestrutura->id_aluno != aluno->id){
        puts("A infraestrutura se encontra ocupada com outro aluno");
        return;
    }

    puts("Infraestrutura desocupada com sucesso");
    infraestrutura->estado = 0;
    aluno->pendencia--;
}
