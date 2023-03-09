// Usando o comando for, faça um programa que calcule o fatorial de um número inteiro n


#include <stdio.h>

int main(){

    int n;
    int fatorial = 1;

    printf("Digite um numero:");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++){
        fatorial = fatorial * i;
    }

    printf("O fatorial de %d é: %d", n, fatorial);

    return 0;
}