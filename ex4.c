/*
 * Exercício 4 - Fila Simples de char (A) + Fila Circular de int (B)
 * Lê vetor de char e distribui:
 *   - Dígito → converte para int e enfileira em B (circular)
 *   - Letra  → enfileira em A (simples)
 *   - Outros → ignorados
 * Ao final: desenfileira B depois A, exibindo os valores.
 */

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 200

/* ── Fila A: simples de char ── */
typedef struct {
    char dados[MAX];
    int inicio;
    int fim;
    int tamanho;
} FilaChar;

void filaA_init(FilaChar *f) {
    f->inicio  = 0;
    f->fim     = -1;
    f->tamanho = 0;
}

int filaA_vazia(FilaChar *f) { return f->tamanho == 0; }
int filaA_cheia(FilaChar *f) { return f->tamanho == MAX; }

int filaA_enfileirar(FilaChar *f, char c) {
    if (filaA_cheia(f)) return 0;
    f->fim = (f->fim + 1) % MAX;
    f->dados[f->fim] = c;
    f->tamanho++;
    return 1;
}

int filaA_desenfileirar(FilaChar *f, char *c) {
    if (filaA_vazia(f)) return 0;
    *c = f->dados[f->inicio];
    f->inicio = (f->inicio + 1) % MAX;
    f->tamanho--;
    return 1;
}

/* ── Fila B: circular de int com contador ── */
typedef struct {
    int dados[MAX];
    int inicio;
    int fim;
    int contador;
} FilaCircularInt;

void filaB_init(FilaCircularInt *f) {
    f->inicio   = 0;
    f->fim      = 0;
    f->contador = 0;
}

int filaB_vazia(FilaCircularInt *f) { return f->contador == 0; }
int filaB_cheia(FilaCircularInt *f) { return f->contador == MAX; }

int filaB_enfileirar(FilaCircularInt *f, int valor) {
    if (filaB_cheia(f)) return 0;
    f->dados[f->fim] = valor;
    f->fim = (f->fim + 1) % MAX;
    f->contador++;
    return 1;
}

int filaB_desenfileirar(FilaCircularInt *f, int *valor) {
    if (filaB_vazia(f)) return 0;
    *valor = f->dados[f->inicio];
    f->inicio = (f->inicio + 1) % MAX;
    f->contador--;
    return 1;
}

int main(void) {
    FilaChar      filaA;
    FilaCircularInt filaB;

    filaA_init(&filaA);
    filaB_init(&filaB);

    char entrada[MAX];
    printf("Digite uma sequencia de caracteres: ");
    fgets(entrada, MAX, stdin);

    /* Remove newline */
    int len = strlen(entrada);
    if (len > 0 && entrada[len - 1] == '\n')
        entrada[len - 1] = '\0';

    printf("Entrada: %s\n\n", entrada);

    /* Distribui nas filas */
    for (int i = 0; entrada[i] != '\0'; i++) {
        char c = entrada[i];
        if (isdigit((unsigned char)c)) {
            int num = c - '0';  /* converte dígito para valor numérico real */
            filaB_enfileirar(&filaB, num);
        } else if (isalpha((unsigned char)c)) {
            filaA_enfileirar(&filaA, c);
        }
        /* outros caracteres: ignorados */
    }

    /* Desenfileira B (inteiros) */
    printf("Fila B (digitos convertidos para inteiro): ");
    if (filaB_vazia(&filaB)) {
        printf("(vazia)");
    } else {
        int val;
        while (filaB_desenfileirar(&filaB, &val)) {
            printf("%d ", val);
        }
    }
    printf("\n");

    /* Desenfileira A (letras) */
    printf("Fila A (letras):                          ");
    if (filaA_vazia(&filaA)) {
        printf("(vazia)");
    } else {
        char c;
        while (filaA_desenfileirar(&filaA, &c)) {
            printf("%c ", c);
        }
    }
    printf("\n");

    return 0;
}
