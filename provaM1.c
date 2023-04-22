#include <stdio.h>
#include <math.h>

#define MAXESCOLAS 5

#define MAXESTUDANTES 10


typedef struct {
int x;
int y;
} coord;

typedef struct {
coord local;
float raio;
int capac;
} escola;

typedef struct {
coord local;
} estudante;


escola listaescolas[MAXESCOLAS];
estudante listaestudantes[MAXESTUDANTES];


void questao01(int *qesc, int *qest);
escola questao02(int qesc);
void questao03(escola x);
void questao04(int qesc, int qest);


int main(){

int qtde_esc, qtde_est;
questao01(&qtde_esc, &qtde_est);
questao03(questao02(qtde_esc));
questao04(qtde_esc, qtde_est);

return 0;
}


//Questão 1:

void questao01(int *qesc, int *qest){
int i;
    printf("Figite a quantidade de escolas disponiveis:");
    scanf("%d", &*qesc);

        for(i = 0; i < *qesc; i++){
        printf("Digite o valor de x da escola %d:", i);
        scanf("%d", &listaescolas[i].local.x);
        printf("Digite o valor de y da escola %d:", i);
        scanf("%d", &listaescolas[i].local.y);
        printf("Digite o raio da escola %d:", i);
        scanf("%d", &listaescolas[i].raio);
        printf("Digite a capacidade da escola %d:", i);
        scanf("%d", &listaescolas[i].capac);

    }

    printf("Digite a quantidade dos estudantes:");
    scanf("%d", &*qest);

        for( i=0; i < *qest; i++){
            printf("Digite a posição x do estudante %d:", i);
            scanf("%d", &listaestudantes[i].local.x);
            printf("Digite a posição y do estudante %d:", i);
            scanf("%d", &listaestudantes[i].local.y);
        }

}

//Qustaão 2:
// Escreva o corpo da função questao02 (apresentada no quadro anexo) que retorna as informações da
// escola com maior raio de abrangência.

escola questao02(int qesc){

    escola maior;
    maior.raio = 0;

    for(int i=0; i<qesc; i++){
        if(listaescolas[i].raio > maior.raio){
            maior = listaescolas[i];
        }
    }

    return maior;
}


//questão 3
// Escreva o corpo da função questao03 (apresentada no quadro anexo) que mostra na tela os dados da
// escola informada pela função questao02. (valor: 2 pts)

void questao03(escola x){

    printf("A escola com maior raio de abrangencia é a escola %d", x);
}


// Escreva o corpo da função questao04 (apresentada no quadro anexo) que mostra na tela, para cada
// estudante, os números das escolas que o abrigaria. Informe -1 caso nenhuma escola o abrigaria.
// Siga o formato: “0: 0 1 2”. (valor: 3 pts)

void questao04(int qesc, int qest){

    for(int i=0; i<qest; i++){
        printf("O estudante %d pode ser alocado nas escolas: ", i);
        for(int j=0; j<qesc; j++){
            if(sqrt(pow(listaestudantes[i].local.x - listaescolas[j].local.x, 2) + pow(listaestudantes[i].local.y - listaescolas[j].local.y, 2)) <= listaescolas[j].raio){
                printf("%d ", j);
            }
        }
        printf("\n");
    }
}

