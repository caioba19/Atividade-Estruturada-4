/*
 * Exercício 2 - Fila Sequencial Simples + Pilha
 * Lê sequência de chars, enfileira, desenfileira para pilha
 * (letras → minúsculas, outros → sem alteração), depois desempilha.
 */

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 200

/* ── Fila de char ── */
typedef struct {
    char dados[MAX];
    int inicio;
    int fim;
    int tamanho;
} FilaChar;

void fila_init(FilaChar *f) {
    f->inicio  = 0;
    f->fim     = -1;
    f->tamanho = 0;
}

int fila_vazia(FilaChar *f) { return f->tamanho == 0; }
int fila_cheia(FilaChar *f) { return f->tamanho == MAX; }

int fila_enfileirar(FilaChar *f, char c) {
    if (fila_cheia(f)) return 0;
    f->fim = (f->fim + 1) % MAX;
    f->dados[f->fim] = c;
    f->tamanho++;
    return 1;
}

int fila_desenfileirar(FilaChar *f, char *c) {
    if (fila_vazia(f)) return 0;
    *c = f->dados[f->inicio];
    f->inicio = (f->inicio + 1) % MAX;
    f->tamanho--;
    return 1;
}

/* ── Pilha de char ── */
typedef struct {
    char dados[MAX];
    int topo;
} Pilha;

void pilha_init(Pilha *p) { p->topo = -1; }

int pilha_vazia(Pilha *p) { return p->topo == -1; }
int pilha_cheia(Pilha *p) { return p->topo == MAX - 1; }

int pilha_empilhar(Pilha *p, char c) {
    if (pilha_cheia(p)) return 0;
    p->dados[++p->topo] = c;
    return 1;
}

int pilha_desempilhar(Pilha *p, char *c) {
    if (pilha_vazia(p)) return 0;
    *c = p->dados[p->topo--];
    return 1;
}

int main(void) {
    FilaChar fila;
    Pilha    pilha;

    fila_init(&fila);
    pilha_init(&pilha);

    char entrada[MAX];
    printf("Digite uma sequencia de caracteres: ");
    fgets(entrada, MAX, stdin);

    /* Remove newline */
    int len = strlen(entrada);
    if (len > 0 && entrada[len - 1] == '\n')
        entrada[len - 1] = '\0';

    /* Enfileira todos os caracteres */
    for (int i = 0; entrada[i] != '\0'; i++) {
        fila_enfileirar(&fila, entrada[i]);
    }

    printf("Sequencia enfileirada: %s\n", entrada);

    /* Desenfileira e empilha com conversão */
    char c;
    while (fila_desenfileirar(&fila, &c)) {
        if (isalpha((unsigned char)c)) {
            pilha_empilhar(&pilha, (char)tolower((unsigned char)c));
        } else {
            pilha_empilhar(&pilha, c);
        }
    }

    /* Desempilha e exibe */
    printf("Resultado apos desempilhar: ");
    while (pilha_desempilhar(&pilha, &c)) {
        printf("%c", c);
    }
    printf("\n");

    return 0;
}
