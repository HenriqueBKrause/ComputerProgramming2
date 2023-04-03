#include <stdio.h>
#include <stdlib.h>

#define MAX_ESCOLAS 10
#define MAX_ESTUDANTES 100

typedef struct {
    int x;
    int y;
    float raio;
    int capacidade;
} Escola;

typedef struct {
    int x;
    int y;
} Estudante;

Escola listaEscolas[MAX_ESCOLAS];
Estudante listaEstudantes[MAX_ESTUDANTES];

void leDados(int *qtdEscolas, int *qtdEstudantes) {
    printf("Informe a quantidade de escolas: ");
    scanf("%d", qtdEscolas);

    for (int i = 0; i < *qtdEscolas; i++) {
        printf("Escola %d:\n", i);
        printf("Coordenadas (x, y): ");
        scanf("%d %d", &listaEscolas[i].x, &listaEscolas[i].y);
        printf("Raio: ");
        scanf("%f", &listaEscolas[i].raio);
        printf("Capacidade: ");
        scanf("%d", &listaEscolas[i].capacidade);
    }

    printf("\nInforme a quantidade de estudantes: ");
    scanf("%d", qtdEstudantes);

    for (int i = 0; i < *qtdEstudantes; i++) {
        printf("Estudante %d:\n", i);
        printf("Coordenadas (x, y): ");
        scanf("%d %d", &listaEstudantes[i].x, &listaEstudantes[i].y);
    }
}

int main() {
    int qtdEscolas, qtdEstudantes;
    leDados(&qtdEscolas, &qtdEstudantes);
    return 0;
}
