// Crie um algoritmo que leia 3 valores para um vetor de 3 posições
// e depois calcule a média dos valores acessande o vetor.


#include <stdio.h>


int main(){
    int vetor[3];
    int soma = 0;
    for (int i = 0; i < 3; i++){
        printf("Digite o valor %d: ", i+1);
        scanf("%d", &vetor[i]);
        soma += vetor[i];
    }
    double media = soma / 3.0;
    printf("Media: %.2lf", media);

    return 0;


}