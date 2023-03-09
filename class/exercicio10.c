// Faça um programa que lê n x m valores decimais, armazenando-os em uma matriz com n
// linhas e m colunas. Após, para cada linha da matriz, o algoritmo calcula a média e conta
// quantos elementos estão acima da média calculada, imprimindo estas informações

#include <stdio.h> 


int main(){
    int m,n;
    double matriz[n][m];

    printf("Digite o numero de linhas da matriz:");
    scanf("%d", &n);

    printf("Digite o numero de colunas da matriz:");
    scanf("%d", &m);

for(int i =0; i<n; i++){
    for(int j=0; j<m; j++){
        printf("Digite o elemento da linha %d e coluna %d:", i, j);
        scanf("%lf", &matriz[i][j]);
    }

    double soma = 0;
    for(int j=0; j<m; j++){
        soma += matriz[i][j];
    }

    double media = soma/m;

    int acima_media = 0;
    for(int j=0; j<m; j++){
        if(matriz[i][j] > media){
            acima_media++;
        }
    }

    printf("A média da linha %d é %lf e tem %d elementos acima da média\n", i, media, acima_media);

    return 0;

}


}