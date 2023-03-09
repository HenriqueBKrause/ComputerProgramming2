// Escreva um programa que lê as coordenadas de n pontos no plano cartesiano (x, y) e
// identifica se estes pontos pertencem: i) ao 1o. quadrante; ii) ao 2o. quadrante; iii) ao 3o.
// quadrante; iv) ao quarto quadrante; ou estão sobre v) o eixo dos “x”; vi) o eixo dos “y”; ou
// vii) estão na origem. Feito isso, o programa escreverá os totais de pontos em cada uma
// destas situações.

#include <stdio.h>

int main(){


    int x1;
    int y1;

    printf("Digite a coordenada de (x):");
    scanf("%d", &x1);

    printf("Digite a coordenada de (y):");
    scanf("%d", &y1);


    if (x1 > 0 && y1 > 0){
        printf("O ponrto 1 esta localizado no primeiro quadrande.");
    }

    if(x1 > 0 && y1 < 0){
        printf("O ponto 1 esta localizado no segundo quadrante.");

    }

    if ( x1 < 0 && x1 > 1){
        printf("O ponto 1 esta localizado no terceiro quadrante.");
    }

    if (x1 < 0 && y1 < 0){
        printf("O ponto 1 esta localizado no quarto quadrante.");
    }

    if (x1 == 0 && y1 != 0){
        printf("O ponto 1 esta localizado no eixo dos x.");
    }

    return 0;
}