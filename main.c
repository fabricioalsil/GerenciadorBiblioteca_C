#include "cabecalho.h"

int main()
{
    struct alunos* cab_alunos = (struct alunos*) malloc (sizeof(struct alunos)); //criação do cabeça de cada uma das listas encadeadas
    cab_alunos->prox = NULL;

    struct livros* cab_livros = (struct livros*) malloc (sizeof(struct livros));
    cab_livros->prox = NULL;

    struct infraestrutura* cab_infraestrutura = (struct infraestrutura*) malloc (sizeof(struct infraestrutura));
    cab_infraestrutura->prox = NULL;

    int id_aluno = 0; //IDs gerados automaticamente pela bilioteca
    int id_livro = 0;

    int num_infraestrutura = 0; //ID que será inserida pelo usuário

    int qnt_aluno = 0; //Quantidade real de cada lista, retirando os removidos
    int qnt_livro = 0;
    int qnt_infraestrutura = 0;

    int opcao; //opção para os próximos menus

    system(CLEAR);
    puts("Escolha uma das opcoes abaixo: ");
    puts("1 - Comecar do zero ou primeira inicializacao");
    puts("2 - Comecar da ultima sessao salva");
    puts("Digite a opcao: ");
    scanf("%d", &opcao);
    flush_in(); //limpa buffer de entrada 'n'
    while(opcao != 1 && opcao != 2){
        printf("Opcao invalida, tente novamente: ");
        scanf("%d", &opcao);
        flush_in();
    }

    system(CLEAR);

    if(opcao == 2){
        iniciar_aluno(cab_alunos, &id_aluno, &qnt_aluno);
        iniciar_livro(cab_livros, &id_livro, &qnt_livro);
        iniciar_infraestrutura(cab_infraestrutura, &num_infraestrutura, &qnt_infraestrutura);
    }
    opcao = 0;
    int enq = 1;
    while(enq){
        //Abre o menu até que a opção de encerrar o programa seja escolhida
        puts("Bem vindo ao menu inicial!");
        puts("Digite sua opcao abaixo para prosseguir:\n");

        puts("1 - Adicionar novo aluno");
        puts("2 - Remover aluno");
        puts("3 - Listar todos os alunos cadastrados");
        puts("4 - Buscar aluno\n");

        puts("5 - Adicionar livro");
        puts("6 - Remover livro");
        puts("7 - Listar todos os livros");
        puts("8 - Buscar livro");
        puts("9 - Emprestar livro");
        puts("10 - Devolver livro\n");

        puts("11 - Adicionar infraestrutura");
        puts("12 - Remover infraestrutura");
        puts("13 - Listar todas as infraestruturas");
        puts("14 - Buscar infraestrutura");
        puts("15 - Ocupar recurso");
        puts("16 - Desocupar recurso\n");

        puts("17 - Encerrar o programa");
        puts("Digite: ");
        scanf("%d", &opcao);
        flush_in();

        while(opcao < 1 || opcao > 17){//garante o range de opcoes
            printf("Opcao invalida, tente novamente: ");
            scanf("%d", &opcao);
            flush_in();
        }
        system(CLEAR);

        switch (opcao){
            case 1:
                inserir_aluno(cab_alunos, &id_aluno, &qnt_aluno);
                continuar();
                break;
            case 2:
                remover_aluno(cab_alunos, &qnt_aluno);
                continuar();
                break;
            case 3:
                imprimir_todos_alunos(cab_alunos);
                continuar();
                break;
            case 4:
                imprimir_aluno(cab_alunos);
                continuar();
                break;
            case 5:
                inserir_livro(cab_livros, &id_livro, &qnt_livro);
                continuar();
                break;
            case 6:
                remover_livro(cab_livros, &qnt_livro);
                continuar();
                break;
            case 7:
                imprimir_todos_livros(cab_livros, cab_alunos);
                continuar();
                break;
            case 8:
                imprimir_livro(cab_livros, cab_alunos);
                continuar();
                break;
            case 9:
                emprestar_livro(cab_alunos, cab_livros);
                continuar();
                break;
            case 10:
                devolver_livro(cab_alunos, cab_livros);
                continuar();
                break;
            case 11:
                inserir_infraestrutura(cab_infraestrutura, &num_infraestrutura, &qnt_infraestrutura);
                continuar();
                break;
            case 12:
                remover_infraestrutura(cab_infraestrutura, &qnt_infraestrutura);
                continuar();
                break;
            case 13:
                imprimir_toda_infraestrutura(cab_infraestrutura, cab_alunos);
                continuar();
                break;
            case 14:
                imprimir_infraestrutura(cab_infraestrutura, cab_alunos);
                continuar();
                break;
            case 15:
                emprestar_infraestrutura(cab_infraestrutura, cab_alunos);
                continuar();
                break;
            case 16:
                devolver_infraestrutura(cab_infraestrutura, cab_alunos);
                continuar();
                break;
            case 17:
                puts("Escolha uma das opcoes abaixo:");
                puts("1 - Encerrar sem salvar.");
                puts("2 - Salvar e encerrar.");
                puts("Digite a opcao: ");
                scanf("%d", &opcao);
                flush_in();

                if(opcao == 2){ //usado para salvar e criptografar os arquivos
                    int senha;
                    printf("Digite uma senha numerica entre 1 e 74: ");//quantida de caracteres da tabela ASCII entre 'A' e 'z'
                    scanf("%d", &senha);
                    flush_in();
                    while(senha < 1 || senha > 74){
                        printf("Senha invalida, tente novamente: ");
                        scanf("%d", &senha);
                        flush_in();
                    }
                    encerrar_aluno(cab_alunos, id_aluno, qnt_aluno, senha);
                    encerrar_livro(cab_livros, id_livro, qnt_livro, senha);
                    encerrar_infraestrutura(cab_infraestrutura, num_infraestrutura, qnt_infraestrutura, senha);
                }else if(opcao == 1){//limpa todas as listas
                    struct alunos *p = cab_alunos->prox;
                    struct alunos *antp;
                    while(p != NULL){
                        antp = p;
                        p = p->prox;
                        free(antp->nome);
                        free(antp->matricula);
                        free(antp);
                    }
                    free(cab_alunos);

                    struct livros *r = cab_livros->prox;
                    struct livros *antr;
                    while(r != NULL){
                        antr = r;
                        r = r->prox;
                        free(antr->nome);
                        free(antr->categoria);
                        free(antr);
                    }
                    free(cab_livros);

                    struct infraestrutura *s = cab_infraestrutura->prox;
                    struct infraestrutura *ants;
                    while(s != NULL){
                        ants = s;
                        s = s->prox;
                        free(ants);
                    }
                    free(cab_infraestrutura);
                }else{
                    puts("Opcao invalida.");
                    continuar();
                    continue;
                }

                enq = 0;
                break;
        }
    }


    system(CLEAR);
    puts("Fim do programa!");
    return 0;
}
