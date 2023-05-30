#include <stdio.h>
#include <stdlib.h>

// funcao que ordena o array em ordem DECRESCENTE
int compare(const void *a, const void *b) {
    return (*(int*)b - *(int*)a);
}

int maxCoins(int* piles, int pilesSize) {
    // ordena piles em ordem DECRESCENTE
    qsort(piles, pilesSize, sizeof(int), compare);

    int totalCoins = 0;
    int count = 0;

    for (int i = 1; i < pilesSize; i += 2) {
        //soma o total de moedas da pilha "do meio" e adiciona 1 ao contador
        totalCoins += piles[i];
        count++;

        //confere se o contador ja alcancou um terco de pilesSize
        if (count == pilesSize / 3) {
            break;
        }
    }

    return totalCoins;
}

int main() {
    int* piles = NULL;
    int capacity = 0;
    int count = 0;
    int num;

    // Recebe o valor em piles ate receber EOF
    printf("Informe o tamanho da pilha: (Insira CTRL + Z para encerrar)\n");
    while (scanf("%d", &num) != EOF) {
        if (count == capacity) {
            /* Dobra a capacidade, caso necessario (se o array tiver totalmente preenchido, dobra a capacidade para que nao seja necessario
            realocar cada vez que um elemento for adicionado)
            */
            capacity = (capacity == 0) ? 1 : capacity * 2;
            piles = realloc(piles, capacity * sizeof(int));
        }
        piles[count++] = num;
    }

    int result = maxCoins(piles, count);

    // imprime o resultado
    printf("Maximo numero de moedas: %d\n", result);

    // libera a memória
    free(piles);

    return 0;
}
