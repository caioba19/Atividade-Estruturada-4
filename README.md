# Atividade Estruturada 4 – Filas Sequenciais

**Disciplina:** Estrutura de Dados  
**Linguagem:** C

---

## Estrutura do Projeto

```
filas/
├── ex1/ex1.c   — Fila simples com menu (múltiplos de 2)
├── ex2/ex2.c   — Fila de char + Pilha (inverter com minúsculas)
├── ex3/ex3.c   — Fila circular com menu (dobro ao desenfileirar)
└── ex4/ex4.c   — Duas filas: A (letras) e B circular (dígitos)
```

---

## Compilação

```bash
gcc -o ex1/ex1 ex1/ex1.c
gcc -o ex2/ex2 ex2/ex2.c
gcc -o ex3/ex3 ex3/ex3.c
gcc -o ex4/ex4 ex4/ex4.c
```

---

## Exercício 1 – Fila Sequencial Simples com Menu

**Arquivo:** `ex1/ex1.c`

### O que faz
Apresenta um menu repetitivo com três opções:
1. Enfileirar um número inteiro positivo
2. Desenfileirar **tudo** e exibir apenas os múltiplos de 2
3. Terminar o programa

### Estrutura utilizada
Fila sequencial simples com array circular e controle de `inicio`, `fim` e `tamanho`.

### Exemplo de execução
```
Opcao: 1
Digite um numero inteiro positivo: 5
Numero 5 enfileirado com sucesso.

Opcao: 1
Digite um numero inteiro positivo: 4
Numero 4 enfileirado com sucesso.

Opcao: 2
Multiplos de 2 encontrados: 4
Fila esvaziada.

Opcao: 3
Encerrando programa...
```

---

## Exercício 2 – Fila de Char + Pilha

**Arquivo:** `ex2/ex2.c`

### O que faz
1. Lê uma sequência de caracteres e **enfileira** todos.
2. **Desenfileira** um a um e **empilha** com a seguinte regra:
   - Letras → converte para **minúscula** antes de empilhar
   - Outros caracteres → empilha sem alteração
3. **Desempilha tudo** e exibe o resultado (sequência invertida e com letras em minúscula).

### Estruturas utilizadas
- **Fila** sequencial simples de `char`
- **Pilha** de `char`

### Exemplo de execução
```
Digite uma sequencia de caracteres: AbC123!
Sequencia enfileirada: AbC123!
Resultado apos desempilhar: !321cba
```

> A sequência fica invertida porque a pilha inverte a ordem. As letras ficam em minúscula.

---

## Exercício 3 – Fila Sequencial Circular com Menu

**Arquivo:** `ex3/ex3.c`

### O que faz
Apresenta um menu repetitivo com quatro opções:
1. Enfileirar um valor inteiro **não nulo**
2. Desenfileirar **um** valor e exibir o seu **dobro**
3. Desenfileirar **tudo** sem alteração
4. Terminar o programa

### Estrutura utilizada
Fila **circular** com array e contador de elementos, implementada com funções `enfileirar` e `desenfileirar`.

### Exemplo de execução
```
Opcao: 1
Digite um valor inteiro nao nulo: 3
Valor 3 enfileirado.

Opcao: 2
Valor desenfileirado: 3 | Dobro: 6

Opcao: 3
Valores desenfileirados: 5
Fila esvaziada.

Opcao: 4
Encerrando programa...
```

---

## Exercício 4 – Duas Filas (Simples + Circular)

**Arquivo:** `ex4/ex4.c`

### O que faz
Lê um vetor de `char` e distribui os caracteres em duas filas:

| Caractere | Destino |
|-----------|---------|
| Dígito (`0`–`9`) | Converte para inteiro real e enfileira em **Fila B** (circular de `int`) |
| Letra (`a`–`z`, `A`–`Z`) | Enfileira em **Fila A** (simples de `char`) |
| Outros (`!`, `@`, espaço…) | **Ignorado** |

Ao final, desenfileira **B** e depois **A**, exibindo os valores.

### Estruturas utilizadas
- **Fila A:** fila sequencial simples de `char`
- **Fila B:** fila sequencial circular de `int` com contador

### Exemplo de execução
```
Digite uma sequencia de caracteres: a3B2!c
Entrada: a3B2!c

Fila B (digitos convertidos para inteiro): 3 2
Fila A (letras):                          a B c
```

---

## Conceitos Abordados

| Conceito | Exercícios |
|----------|-----------|
| Fila sequencial simples | 1, 2, 4 |
| Fila sequencial circular | 3, 4 |
| Pilha (para comparação) | 2 |
| Funções de enfileirar/desenfileirar | Todos |
| Conversão de dígito para inteiro (`c - '0'`) | 4 |
| Conversão de letra para minúscula (`tolower`) | 2 |
