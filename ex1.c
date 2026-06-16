/*
 * Exercício 1 - Fila Sequencial Simples
 * Menu com enfileirar, desenfileirar múltiplos de 2 e encerrar.
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int dados[MAX];
    int inicio;
    int fim;
    int tamanho;
} Fila;

void inicializar(Fila *f) { f->inicio = 0; f->fim = -1; f->tamanho = 0; }
int vazia(Fila *f)         { return f->tamanho == 0; }
int cheia(Fila *f)         { return f->tamanho == MAX; }

int enfileirar(Fila *f, int valor) {
    if (cheia(f)) { printf("Fila cheia!\n"); return 0; }
    f->fim = (f->fim + 1) % MAX;
    f->dados[f->fim] = valor;
    f->tamanho++;
    return 1;
}

int desenfileirar(Fila *f, int *valor) {
    if (vazia(f)) return 0;
    *valor = f->dados[f->inicio];
    f->inicio = (f->inicio + 1) % MAX;
    f->tamanho--;
    return 1;
}

int main(void) {
    Fila f;
    inicializar(&f);
    int opcao = 0, valor;

    do {
        printf("\n=== MENU - FILA SEQUENCIAL ===\n");
        printf("1. Enfileirar numero inteiro positivo\n");
        printf("2. Desenfileirar tudo e imprimir multiplos de 2\n");
        printf("3. Terminar programa\n");
        printf("Opcao: ");

        if (scanf("%d", &opcao) != 1) break;   /* EOF ou erro */

        switch (opcao) {
            case 1:
                printf("Digite um numero inteiro positivo: ");
                if (scanf("%d", &valor) != 1) break;
                if (valor <= 0) {
                    printf("Valor invalido! Digite um numero positivo.\n");
                } else if (enfileirar(&f, valor)) {
                    printf("Numero %d enfileirado com sucesso.\n", valor);
                }
                break;

            case 2:
                if (vazia(&f)) {
                    printf("Fila vazia!\n");
                } else {
                    printf("Multiplos de 2 encontrados: ");
                    int encontrou = 0;
                    while (desenfileirar(&f, &valor)) {
                        if (valor % 2 == 0) { printf("%d ", valor); encontrou = 1; }
                    }
                    if (!encontrou) printf("(nenhum)");
                    printf("\nFila esvaziada.\n");
                }
                break;

            case 3:
                printf("Encerrando programa...\n");
                break;

            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 3);

    return 0;
}
