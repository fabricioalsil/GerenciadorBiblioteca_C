#include "livros.h"


void imprimir_todos_livros(struct livros *cab_livros, struct alunos *cab_alunos) {
    struct alunos *aluno;

    if (cab_livros->prox == NULL) {
        puts("Nenhum livro cadastrado!");
        return;
    }

    struct livros *p = cab_livros->prox;
    puts("Livros cadastrados:");
    while (p != NULL) {
        printf("Nome: %s; ID: %d.\n", p->nome, p->id);
        if(p->estado == 0)
            puts("Livro disponivel!\n");
        else{
            aluno = busca_aluno(cab_alunos, p->id_aluno);
            printf("Livro emprestado para o aluno de matricula: %s.\n\n", aluno->matricula);
        }
        p = p->prox;
    }
}

struct livros *busca_livro(struct livros *cab, int id) {
    struct livros *p = cab->prox;
    while (p != NULL && p->id < id)
        p = p->prox;
    return p;
}

struct livros *busca_livro_ant(struct livros *cab, int id, struct livros **ant) {
    (*ant) = cab;
    struct livros *p = cab->prox;
    while (p != NULL && p->id < id) {
        (*ant) = p;
        p = p->prox;
    }
    return p;
}

void imprimir_livro(struct livros *cab, struct alunos *cab_alunos){
    struct alunos *aluno;
    int contador=0;

    int opcao;
    puts("Se deseja buscar por ID digite 1, por categoria digite 2: ");
    scanf("%d", &opcao);
    flush_in();

    if(opcao == 2){
        struct livros *p = cab->prox;
        char *categoria=(char *) malloc (sizeof(char));
        size_t tam=1;
        int posicao;

        puts("Digite a categoria: ");
        posicao = getline(&categoria, &tam, stdin);
        categoria[posicao - 1] = '\0';

        while (p != NULL) {
            if( strcmp(p->categoria, categoria) ){
                p = p->prox;
                continue;
            }
            contador++;
            printf("Nome: %s; ID: %d.\n", p->nome, p->id);
            if(p->estado == 0)
                puts("Livro disponivel!\n");
            else{
                aluno = busca_aluno(cab_alunos, p->id_aluno);
                printf("Livro emprestado para o aluno de matricula: %s.\n", aluno->matricula);
            }
        p = p->prox;
        }
        if(contador == 0){
            printf("Nenhum livro da categoria: %s, foi encontrado!", categoria);
        }
        free(categoria);
        return;
    }
    int id;
    puts("Digite o ID do livro que deseja buscar: ");
    scanf("%d", &id);
    flush_in();

    struct livros *p = busca_livro(cab, id);

    if(p != NULL && p->id == id){
        printf("Nome: %s; ID: %d.\n", p->nome, p->id);
        if(p->estado == 0)
            puts("Livro disponivel!\n");
        else{
            aluno = busca_aluno(cab_alunos, p->id_aluno);
            printf("Livro emprestado para o aluno de matricula: %s.\n", aluno->matricula);
        }
    }else{
        puts("ID nao encontrado.");
    }
}

void inserir_livro(struct livros *cab, int *id_livro, int *qnt_livro) {
    struct livros *ant = NULL;
    struct livros *p = busca_livro_ant(cab, *id_livro, &ant);
    size_t tam = 1;
    size_t tam2 = 1;
    int posicao;

    p = (struct livros*) malloc (sizeof(struct livros));
    p->categoria = (char *) malloc (sizeof(char));
    p->nome = (char *) malloc (sizeof(char));
    p->prox = ant->prox;
    ant->prox = p;

    puts("Digite o nome do livro: ");
    posicao = getline(&p->nome, &tam, stdin);
    p->nome[posicao - 1] = '\0';
    puts("Digite a categoria: ");
    posicao = getline(&p->categoria, &tam2, stdin);
    p->categoria[posicao - 1] = '\0';
    puts("Digite o ano de publicacao: ");
    scanf("%d", &p->ano);
    flush_in();
    p->id = *id_livro;
    p->estado = 0;
    p->id_aluno = 0;
    printf("Livro %s de %d cadastrado com sucesso!\n", p->nome, p->ano);
    (*id_livro)++;
    (*qnt_livro)++;
}

void remover_livro(struct livros *cab, int *qnt_livro) {
    struct livros *ant = NULL;
    struct livros *p;
    int id;
    puts("Digite o ID do livro que deseja remover: ");
    scanf("%d", &id);
    flush_in();
    p = busca_livro_ant(cab, id, &ant);

    if (p != NULL) {
        if (p->estado == 0){
            ant->prox = p->prox;
            printf("Livro %s de %d removido com sucesso!\n", p->nome, p->ano);
            (*qnt_livro)--;
            free(p->nome);
            free(p->categoria);
            free(p);
        }else{
            printf("Livro %s de %d esta sendo usado e nao pode ser removido!\n", p->nome, p->ano);
        }
    }else {
        printf("Livro de ID: %d, nao encontrado!", id);
    }
}

void emprestar_livro(struct alunos *cab_alunos, struct livros *cab_livros){
    int id_livro;
    int id_aluno;
    struct livros *livro;
    struct alunos *aluno;

    puts("Digite o ID do livro que deseja emprestar: ");
    scanf("%d", &id_livro);
    flush_in();


    livro = busca_livro(cab_livros, id_livro);
    if(livro==NULL || livro->id!=id_livro){
        puts("Livro nao encontrado");
        return;
    }
    if(livro->estado!=0){
        puts("Livro ja esta emprestado");
        return;
    }

    puts("Digite o ID do aluno que deseja o livro: ");
    scanf("%d", &id_aluno);
    flush_in();

    aluno = busca_aluno(cab_alunos, id_aluno);
    if(aluno==NULL || aluno->id!=id_aluno){
        puts("Aluno nao encontrado");
        return;
    }

    puts("Livro emprestado com sucesso!");
    aluno->pendencia++;
    livro->id_aluno = aluno->id;
    livro->estado = 1;
}

void devolver_livro(struct alunos *cab_alunos, struct livros *cab_livros){
    int id_livro;
    int id_aluno;
    struct livros *livro;
    struct alunos *aluno;

    puts("Digite o ID do aluno que deseja devolver o livro: ");
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

    puts("Digite o ID do livro a ser devolvido: ");
    scanf("%d", &id_livro);
    flush_in();

    livro = busca_livro(cab_livros, id_livro);
    if(livro==NULL || livro->id!=id_livro){
        puts("Livro nao encontrado");
        return;
    }if(livro->estado == 0){
        puts("O livro ja se encontra disponivel");
        return;
    }if(livro->id_aluno != aluno->id){
        puts("O livro nao esta com esse aluno");
        return;
    }

    puts("Livro devolvido com sucesso");
    livro->estado = 0;
    aluno->pendencia--;
}
