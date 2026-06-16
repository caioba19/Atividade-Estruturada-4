/*
 * Exercício 3 - Fila Sequencial Circular
 * Menu: enfileirar valor não nulo, desenfileirar exibindo o dobro,
 * desenfileirar tudo sem alteração, terminar.
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int dados[MAX];
    int inicio;
    int fim;
    int contador;
} FilaCircular;

void inicializar(FilaCircular *f) { f->inicio = 0; f->fim = 0; f->contador = 0; }
int vazia(FilaCircular *f) { return f->contador == 0; }
int cheia(FilaCircular *f) { return f->contador == MAX; }

int enfileirar(FilaCircular *f, int valor) {
    if (cheia(f)) { printf("Fila cheia!\n"); return 0; }
    f->dados[f->fim] = valor;
    f->fim = (f->fim + 1) % MAX;
    f->contador++;
    return 1;
}

int desenfileirar(FilaCircular *f, int *valor) {
    if (vazia(f)) return 0;
    *valor = f->dados[f->inicio];
    f->inicio = (f->inicio + 1) % MAX;
    f->contador--;
    return 1;
}

int main(void) {
    FilaCircular f;
    inicializar(&f);
    int opcao = 0, valor;

    do {
        printf("\n=== MENU - FILA CIRCULAR ===\n");
        printf("1. Enfileirar valor inteiro nao nulo\n");
        printf("2. Desenfileirar um valor (exibe o dobro)\n");
        printf("3. Desenfileirar tudo (sem alteracao)\n");
        printf("4. Terminar programa\n");
        printf("Opcao: ");

        if (scanf("%d", &opcao) != 1) break;

        switch (opcao) {
            case 1:
                printf("Digite um valor inteiro nao nulo: ");
                if (scanf("%d", &valor) != 1) break;
                if (valor == 0) {
                    printf("Valor invalido! O numero nao pode ser zero.\n");
                } else if (enfileirar(&f, valor)) {
                    printf("Valor %d enfileirado.\n", valor);
                }
                break;

            case 2:
                if (vazia(&f)) {
                    printf("Fila vazia!\n");
                } else if (desenfileirar(&f, &valor)) {
                    printf("Valor desenfileirado: %d | Dobro: %d\n", valor, valor * 2);
                }
                break;

            case 3:
                if (vazia(&f)) {
                    printf("Fila vazia!\n");
                } else {
                    printf("Valores desenfileirados: ");
                    while (desenfileirar(&f, &valor)) printf("%d ", valor);
                    printf("\nFila esvaziada.\n");
                }
                break;

            case 4:
                printf("Encerrando programa...\n");
                break;

            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 4);

    return 0;
}
