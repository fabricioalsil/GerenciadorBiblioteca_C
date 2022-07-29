#include "alunos.h"

void flush_in() {
    int ch;
    do {
        ch = fgetc(stdin);
    } while (ch != EOF && ch != '\n');
}

void continuar(){
    printf("\nPressione Enter para continuar...");
    while( getchar() != '\n' );
    system(CLEAR);
}

void imprimir_todos_alunos(struct alunos *cab_alunos) {
    if (cab_alunos->prox == NULL) {
        puts("Nenhum aluno foi matriculado!");
        return;
    }

    struct alunos *p = cab_alunos->prox;
    puts("Alunos cadastrados:");
    while (p != NULL) {
        printf("Nome: %s; ID: %d.\n", p->nome, p->id);
        if(p->pendencia == 0)
            puts("Nao possui pendencias\n");
        else
            puts("Possui pendencias\n");
        p = p->prox;
    }
}

struct alunos *busca_aluno(struct alunos *cab, int id) {
    struct alunos *p = cab->prox;
    while (p != NULL && p->id < id)
        p = p->prox;
    return p;
}

struct alunos *busca_aluno_ant(struct alunos *cab, int id, struct alunos **ant) {
    (*ant) = cab;
    struct alunos *p = cab->prox;
    while (p != NULL && p->id < id) {
        (*ant) = p;
        p = p->prox;
    }
    return p;
}

void imprimir_aluno(struct alunos *cab){

    int id;
    puts("Digite o ID do aluno que deseja buscar: ");
    scanf("%d", &id);
    flush_in();

    struct alunos *p = busca_aluno(cab, id);

    if(p != NULL && p->id == id){
        printf("Nome: %s; ID: %d.\n", p->nome, p->id);
        if(p->pendencia == 0)
            puts("Nao possui pendencias.");
        else
            puts("Possui pendencias.");
    }else{
        puts("ID nao encontrado.");
    }
}

void inserir_aluno(struct alunos *cab, int *id_aluno, int *qnt_aluno) {
    struct alunos *ant = NULL;
    struct alunos *p = busca_aluno_ant(cab, *id_aluno, &ant);
    size_t tam = 1;
    size_t tam2 = 1;
    int posicao;

    p = (struct alunos*) malloc (sizeof(struct alunos));
    p->nome = (char *) malloc (sizeof(char));
    p->matricula = (char *) malloc (sizeof(char));
    p->prox = ant->prox;
    ant->prox = p;

    puts("Digite o nome do aluno: ");
    posicao = getline(&p->nome, &tam , stdin);
    p->nome[posicao - 1] = '\0';
    puts("Digite a matricula: ");
    posicao = getline(&p->matricula, &tam2, stdin);
    p->matricula[posicao - 1] = '\0';
    p->id = *id_aluno;
    p->pendencia = 0;

    printf("Aluno %s cadastrado com sucesso!", p->nome);
    (*id_aluno)++;
    (*qnt_aluno)++;
}

void remover_aluno(struct alunos *cab, int *qnt_aluno) {
    struct alunos *ant = NULL;
    struct alunos *p;
    int id;
    puts("Digite o ID do aluno que deseja remover: ");
    scanf("%d", &id);
    flush_in();
    p = busca_aluno_ant(cab, id, &ant);

    if (p != NULL) {
        if(p->pendencia == 0){
            ant->prox = p->prox;
            printf("Aluno %s removido com sucesso!", p->nome);
            (*qnt_aluno)--;
            free(p->matricula);
            free(p->nome);
            free(p);
        }else{
            printf("O aluno %s nao pode ser removido por possuir pendencias!", p->nome);
        }
    }else {
        printf("Aluno de id: %d, nao encontrado!", id);
    }
}
