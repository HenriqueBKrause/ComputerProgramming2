// Faça um programa que lê n x m valores decimais, armazenando-os em uma matriz com n
// linhas e m colunas. Após, para cada linha da matriz, o algoritmo calcula a média e conta
// quantos elementos estão acima da média calculada, imprimindo estas informações

#include <stdio.h>

int main() {
    int n, m;
    printf("Digite o número de linhas (n) e colunas (m): ");
    scanf("%d%d", &n, &m);

    double matriz[n][m];
    for (int i = 0; i < n; i++) {
        printf("Digite os %d valores da linha %d: ", m, i+1);
        for (int j = 0; j < m; j++) {
            scanf("%lf", &matriz[i][j]);
        }
    }

    for (int i = 0; i < n; i++) {
        double soma = 0;
        for (int j = 0; j < m; j++) {
            soma += matriz[i][j];
        }
        double media = soma / m;
        int acima_da_media = 0;
        for (int j = 0; j < m; j++) {
            if (matriz[i][j] > media) {
                acima_da_media++;
            }
        }
        printf("Linha %d: media = %.2lf, %d elementos acima da media\n", i+1, media, acima_da_media);
    }

    return 0;
}
