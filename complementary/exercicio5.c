// Preencha uma matriz 2x2 lendo valores do usuario e
// depois troque os valores entre a primeira e a segunda linha.

#include <stdio.h>


int main(){

    int matriz[2][2];
    int i, j, aux1, aux2;

//lendo os valores do usuario:
    printf("Digite o numero do valor [0][0] da matriz:");
    scanf("%d", &matriz[0][0]);

     printf("Digite o numero do valor [0][1] da matriz:");
    scanf("%d", &matriz[0][1]);

     printf("Digite o numero do valor [1][0] da matriz:");
    scanf("%d", &matriz[1][0]);

     printf("Digite o numero do valor [1][1] da matriz:");
    scanf("%d", &matriz[1][1]);

//armazendo os valores atravez das aux:

aux1=matriz[0][0];
aux2=matriz[0][1];

//troca de valores:
matriz[0][0]=matriz[1][0];
matriz[0][1]=matriz[1][1];
matriz[1][0]=aux1;
matriz[1][1]=aux2;


//imprimindo a matriz:

for(i=0; i<2; i++){
    for(j=0; j<2; j++){
        printf("%d ", matriz[i][j]);
    }
    printf("\n");
}   
return 0;
}