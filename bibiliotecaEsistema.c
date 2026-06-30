#include <stdio.h>
#include <string.h>

#define MAX_LIVROS 100

typedef struct {
    int codigo;
    char titulo[80];
    char autor[80];
    int quantidade;
    float preco;
} Livro;

void cadastrarLivro(Livro livros[], int *total) {
    if (*total >= MAX_LIVROS) {
        printf("\nLimite de livros atingido!\n");
        return;
    }

    printf("\n=== Cadastro de Livro ===\n");

    printf("Digite o codigo do livro: ");
    scanf("%d", &livros[*total].codigo);

    printf("Digite o titulo do livro: ");
    scanf(" %[^\n]", livros[*total].titulo);

    printf("Digite o autor do livro: ");
    scanf(" %[^\n]", livros[*total].autor);

    printf("Digite a quantidade em estoque: ");
    scanf("%d", &livros[*total].quantidade);

    printf("Digite o preco do livro: ");
    scanf("%f", &livros[*total].preco);

    (*total)++;

    printf("\nLivro cadastrado com sucesso!\n");
}

void listarLivros(Livro livros[], int total) {
    if (total == 0) {
        printf("\nNenhum livro cadastrado.\n");
        return;
    }

    printf("\n=== Lista de Livros ===\n");

    for (int i = 0; i < total; i++) {
        printf("\nLivro %d\n", i + 1);
        printf("Codigo: %d\n", livros[i].codigo);
        printf("Titulo: %s\n", livros[i].titulo);
        printf("Autor: %s\n", livros[i].autor);
        printf("Quantidade: %d\n", livros[i].quantidade);
        printf("Preco: R$ %.2f\n", livros[i].preco);
    }
}

void buscarLivro(Livro livros[], int total) {
    int codigo;
    int encontrado = 0;

    printf("\nDigite o codigo do livro que deseja buscar: ");
    scanf("%d", &codigo);

    for (int i = 0; i < total; i++) {
        if (livros[i].codigo == codigo) {
            printf("\n=== Livro Encontrado ===\n");
            printf("Codigo: %d\n", livros[i].codigo);
            printf("Titulo: %s\n", livros[i].titulo);
            printf("Autor: %s\n", livros[i].autor);
            printf("Quantidade: %d\n", livros[i].quantidade);
            printf("Preco: R$ %.2f\n", livros[i].preco);

            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("\nLivro nao encontrado.\n");
    }
}

void venderLivro(Livro livros[], int total) {
    int codigo;
    int quantidadeVenda;
    int encontrado = 0;

    printf("\nDigite o codigo do livro vendido: ");
    scanf("%d", &codigo);

    for (int i = 0; i < total; i++) {
        if (livros[i].codigo == codigo) {
            encontrado = 1;

            printf("Digite a quantidade vendida: ");
            scanf("%d", &quantidadeVenda);

            if (quantidadeVenda <= 0) {
                printf("\nQuantidade invalida.\n");
            } else if (quantidadeVenda > livros[i].quantidade) {
                printf("\nEstoque insuficiente.\n");
            } else {
                livros[i].quantidade -= quantidadeVenda;
                printf("\nVenda registrada com sucesso!\n");
                printf("Valor total: R$ %.2f\n", quantidadeVenda * livros[i].preco);
                printf("Quantidade restante: %d\n", livros[i].quantidade);
            }

            break;
        }
    }

    if (!encontrado) {
        printf("\nLivro nao encontrado.\n");
    }
}

void reporEstoque(Livro livros[], int total) {
    int codigo;
    int quantidadeReposicao;
    int encontrado = 0;

    printf("\nDigite o codigo do livro para repor estoque: ");
    scanf("%d", &codigo);

    for (int i = 0; i < total; i++) {
        if (livros[i].codigo == codigo) {
            encontrado = 1;

            printf("Digite a quantidade para adicionar: ");
            scanf("%d", &quantidadeReposicao);

            if (quantidadeReposicao <= 0) {
                printf("\nQuantidade invalida.\n");
            } else {
                livros[i].quantidade += quantidadeReposicao;
                printf("\nEstoque atualizado com sucesso!\n");
                printf("Nova quantidade: %d\n", livros[i].quantidade);
            }

            break;
        }
    }

    if (!encontrado) {
        printf("\nLivro nao encontrado.\n");
    }
}

int main() {
    Livro livros[MAX_LIVROS];
    int total = 0;
    int opcao;

    do {
        printf("\n==============================\n");
        printf(" SISTEMA DE BIBLIOTECA\n");
        printf("==============================\n");
        printf("1 - Cadastrar livro\n");
        printf("2 - Listar livros\n");
        printf("3 - Buscar livro por codigo\n");
        printf("4 - Vender livro\n");
        printf("5 - Repor estoque\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarLivro(livros, &total);
                break;

            case 2:
                listarLivros(livros, total);
                break;

            case 3:
                buscarLivro(livros, total);
                break;

            case 4:
                venderLivro(livros, total);
                break;

            case 5:
                reporEstoque(livros, total);
                break;

            case 0:
                printf("\nSaindo do sistema...\n");
                break;

            default:
                printf("\nOpcao invalida. Tente novamente.\n");
        }

    } while (opcao != 0);

    return 0;
}