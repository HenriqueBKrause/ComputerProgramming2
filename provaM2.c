#include <math.h>
#include <stdio.h>

#define MAXDELEGACIAS 5
#define MAXVITIMAS 10

typedef struct {
  int x;
  int y;
} coord;

typedef struct {
  coord local;
  float raio;
  int capac;
} delegacia;

typedef struct {
  coord local;
} vitima;

delegacia listadelegacias[MAXDELEGACIAS];
vitima listavitimas[MAXVITIMAS];

void questao01(int *qdel, int *qvit);
vitima questao02(int del, int vit);
void questao03(vitima x);
void questao04(int qdel, int qvit);
float dist(int x1, int y1, int x2, int y2);

int main() {
  int qtde_del, qtde_vit;
  questao01(&qtde_del, &qtde_vit);
  questao03(questao02(qtde_del, qtde_vit));
  questao04(qtde_del, qtde_vit);
  return 0;
}

void questao01(int *qdel, int *qvit) {
  int i;
  printf("Digite a quantidade de delegacias:");
  scanf("%d", &*qdel);
  for (i = 0; i < *qdel; i++) {
    printf("\nDigite a coord x da deliegacia %d:", i);
    scanf("%d", &listadelegacias[i].local.x);
    printf("\nDigite a coord y da deliegacia %d:", i);
    scanf("%d", &listadelegacias[i].local.y);
    printf("\nDigite o raio da deliegacia %d:", i);
    scanf("%f", &listadelegacias[i].raio);
    printf("\nDigite a capacidade da deliegacia %d:", i);
    scanf("%d", &listadelegacias[i].capac);
  }

  printf("\nQual a quantidade de vitimas;\n");
  scanf("%d", &*qvit);
  for (i = 0; i < *qvit; i++) {
    printf("\nDigite a coord x da vitima %d:", i);
    scanf("%d", &listavitimas[i].local.x);
    printf("\nDigite a coord y da vitima %d:", i);
    scanf("%d", &listavitimas[i].local.y);
  }
}

vitima questao02(int del, int vit) {
  int i, j, mais_proxima;
  float d, menor_d, distancias[MAXVITIMAS];

  /* 
  Estratégia: comparar as distâncias de cada vítima para todas 
 as delegacias e armazenas a menor distância no vetor distâncias.
 No final, verifica qual é a menor distância armazenada no vetor.
 */
  for (i = 0; i < vit; i++) {
    menor_d = 100000;
    for (j = 0; j < del; j++) {
      d = dist(listavitimas[i].local.x, listavitimas[i].local.y,
               listadelegacias[j].local.x, listadelegacias[j].local.y);
      if (d < menor_d) {
        menor_d = d;
      }
    }
    distancias[i] = menor_d;
  }
  mais_proxima = 0;
  for (i = 1; i < vit; i++) {
    if (distancias[i] < distancias[mais_proxima]) {
      mais_proxima = i;
    }
  }
  return listavitimas[mais_proxima];
}

void questao03(vitima x) { 
  printf("%d %d\n", x.local.x, x.local.y); 
}

float dist(int x1, int y1, int x2, int y2) {
  return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

void questao04(int qdel, int qvit) {
  int i, j, conta[MAXDELEGACIAS] = {0}, mais_proxima;
  float d, menor_d;

  /*
 Estratégia: verificar para cada vítima qual é a delegacia mais
 próxima e se está no raio de alcance. Para contar as vítimas em cada
 delegacia utiliza-se o vetor conta. Se a vítima não está no alcance
 de nenhuma delegacia, não conta (-1). Ao final, de acordo com a contagem,
 imprime -, = ou +.
  */
  for (i = 0; i < qvit; i++) {
    menor_d = 100000;
    mais_proxima = -1;
    for (j = 0; j < qdel; j++) {
      d = dist(listadelegacias[j].local.x, listadelegacias[j].local.y,
               listavitimas[i].local.x, listavitimas[i].local.y);
      if (d <= listadelegacias[j].raio) {
        if (d < menor_d) {
          mais_proxima = j;
          menor_d = d;
        }
      }
    }
    if (mais_proxima != -1)
      conta[mais_proxima]++;
  }

  for (i = 0; i < qdel; i++) {
    printf("%d: %d", i, conta[i]);
    if (conta[i] < listadelegacias[i].capac)
      printf("-\n");
    else if (conta[i] == listadelegacias[i].capac)
      printf("=\n");
    else
      printf("+\n");
  }
}