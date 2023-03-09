// Faça um programa que recebe um número inteiro e imprime o somatório de seus divisores.

#include <stdio.h>

int main() {
    int numero, soma = 0;

    printf("Digite um numero: ");
    scanf("%d", &numero);

    for (int i = 1; i <= numero; i++) {
        if (numero % i == 0) {
            soma += i;
        }
    }

    printf("Soma dos divisores: %d", soma);

    return 0;
}