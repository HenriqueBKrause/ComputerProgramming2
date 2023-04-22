// 1. Construa uma estrutura para armazenar pontos (coordenadas x e y) no plano cartesiano. Crie
// um algoritmo que permita ler, armazenar e imprimir uma quantidade TAM de pontos. 

#include <stdio.h>


#define TAM 5

struct ponto {
    int x;
    int y;
};

int main() {
    struct ponto pontos[TAM];
    int i;
    
    for (i = 0; i < TAM; i++) {
        printf("Digite o valor de x: ");
        scanf("%d", &pontos[i].x);
        printf("Digite o valor de y: ");
        scanf("%d", &pontos[i].y);
    }
    
    for (i = 0; i < TAM; i++) {
        printf("Ponto %d: (%d, %d)\n", i, pontos[i].x, pontos[i].y);
    }
    
    return 0;
}