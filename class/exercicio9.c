// // Faça um programa que lê n números decimais, armazenando-os em um vetor. Após, o
// // programa identifica o menor número do vetor e imprime sua posição.



#include <stdio.h>


int main(){

    int n;

    printf("Digite oo numero de elementos do vetor:")
    scanf("%d", &n);

    double vetor[n];

    printf("Digite os %d elementos do vetor:\n", n);

    for(int=i; i < n; i++){
        scanf("%lf", &vetor[i]);
    }

double menor = vetor[0];
int posicao_menor = 0;

for(int i=1; i < n; i++){
    if(vetor[i] < menor){
        menor = vetor[i];
        posicao_menor = i;
    }

    printf("O menor elemento do vetor é %lf e está na posição %d\n", menor, posicao_menor);

    return 0;

}
