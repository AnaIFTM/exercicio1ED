#include <stdio.h>
#include <string.h>

const int maxlivros = 10;

struct Livro {
    char titulo[100];
    char autor[100];
    int numPags;
};

struct Biblioteca {
    struct Livro livros[maxlivros];
    int numLivros;
};

void lerLivro(struct Livro *livro) {
    printf("Titulo: ");
    fgets(livro->titulo, sizeof(livro->titulo), stdin);
    livro->titulo[strcspn(livro->titulo, "\n")] = '\0'; 

    printf("Autor: ");
    fgets(livro->autor, sizeof(livro->autor), stdin);
    livro->autor[strcspn(livro->autor, "\n")] = '\0'; 

    printf("Numero de paginas: ");
    scanf("%d", &livro->numPags);
    getchar();
}

void imprimeLivro(const struct Livro *livro) {
    printf("Titulo: %s\n", livro->titulo);
    printf("Autor: %s\n", livro->autor);
    printf("Numero de paginas: %d\n", livro->numPags);
}

void adicionaLivrobiblioteca(struct Biblioteca *biblioteca, const struct Livro *livro) {
    if (biblioteca->numLivros < maxlivros) {
        biblioteca->livros[biblioteca->numLivros] = *livro;
        biblioteca->numLivros++;
        printf("Livro adicionado a biblioteca.\n");
    } else {
        printf("Biblioteca cheia. Impossivel adicionar mais livros.\n");
    }
}

void mostratodososlivros(const struct Biblioteca *biblioteca) {
    if (biblioteca->numLivros == 0) {
        printf("Biblioteca vazia.\n");
    } else {
        printf("Livros na biblioteca:\n");
        for (int i = 0; i < biblioteca->numLivros; ++i) {
            imprimeLivro(&biblioteca->livros[i]);
            printf("----------------------------------\n");
        }
    }
}

void mostraLivrocommaispags(const struct Biblioteca *biblioteca) {
    if (biblioteca->numLivros == 0) {
        printf("Biblioteca vazia.\n");
    } else {
        int maxpags = biblioteca->livros[0].numPags;
        int aux = 0;

        for (int i = 1; i < biblioteca->numLivros; ++i) {
            if (biblioteca->livros[i].numPags > maxpags) {
                maxpags = biblioteca->livros[i].numPags;
                aux = i;
            }
        }

        printf("Livro com o maior numero de paginas:\n");
        imprimeLivro(&biblioteca->livros[aux]);
    }
}

int main() {
    struct Biblioteca biblioteca;
    biblioteca.numLivros = 0;

    int opcao;

    do {
        printf("Menu:\n");
        printf("1. Adicionar novo livro\n");
        printf("2. Mostrar todos os livros\n");
        printf("3. Mostrar livro com o maior numero de paginas\n");
        printf("0. Sair\n");

        scanf("%d", &opcao);
        getchar();

        switch (opcao) {
            case 1: {
                struct Livro novoLivro;
                lerLivro(&novoLivro);
                adicionaLivrobiblioteca(&biblioteca, &novoLivro);
                break;
            }
            case 2:
                mostratodososlivros(&biblioteca);
                break;
            case 3:
                mostraLivrocommaispags(&biblioteca);
                break;
            case 0:
                printf("Encerrando...\n");
                break;
            default:
                printf("Opção invalida. Tente novamente.\n");
                break;
        }
    } while (opcao != 0);

    return 0;
}

