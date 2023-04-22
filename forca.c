// Nome: Henrique Borges Krause     Matricula: 21201500



#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define TAM 100
#define NUM_PALAVRAS 10
#define ROWS 10
#define COLS 10



//matriz de palavras e dicas
char const tabelaDePalavras[NUM_PALAVRAS][TAM] = {
"BATATA$É um tubérculo",
"AIPIM$Usa-se para fazer sagu",
"COMPUTACAOi$Melhor curso do mundo",
"CHIMARRAO$Se toma numa cuia",
"LAGARTO$Lacoste de elo baixo",
"MARACUJA$Parece sua cara quando acorda",
"SOCORRO$Pedido de ajuda",
"TATU$Tem na terra e no seu nariz",
"FLORESTA$Amazônia",
"ARARA$Papagaio vip"
};


//estrutura de dados
typedef struct
{
char palavraEscolhida[TAM];
char palavraImpressa[TAM];
char dica[TAM];
int letrasRestantes;
int chancesRestantes;
} MatchData;


//Função 1
void sortearPalavra(MatchData *matchData);
//Função 2
int verificarLetra(MatchData *matchData, char letra);
//Função 3
void imprimirPalavra(MatchData *matchData);


    //inicio da função main

int main(){
    srand(time(NULL)); // gera de números aleatórios
    MatchData matchData;
    sortearPalavra(&matchData); 
    
        printf("Dica: %s\n", matchData.dica); // Dica
            imprimirPalavra(&matchData);
    matchData.chancesRestantes = 7; //  vidas 
    while (matchData.chancesRestantes > 0 && matchData.letrasRestantes > 0) {
    char letra;
    
        printf("Digite uma letra maiuscula: ");
        scanf(" %c", &letra); 
    
    
    if (verificarLetra(&matchData, letra)) {
        printf("Letra encontrada!\n");
        imprimirPalavra(&matchData);
    } 
    else {
    printf("Letra não encontrada! Você perdeu uma vida.\n");
        matchData.chancesRestantes--;
    printf("Vidas restantes: %d\n", matchData.chancesRestantes);
    }
    }
    if (matchData.letrasRestantes == 0) {
        printf("Parabéns, você acertou a palavra %s!\n", matchData.palavraEscolhida);
    }
     else {
        printf("Suas chances acabaram. A palavra era %s.\n", matchData.palavraEscolhida);
    }
return 0;
}



//função 1 |  sorteia uma palavra
void sortearPalavra(MatchData *matchData) {
    int indice = rand() % NUM_PALAVRAS; // sorteia um índice aleatório
    char palavra[TAM];
    
    strcpy(palavra, tabelaDePalavras[indice]); // copia a palavra escolhida para uma "char palavra"
    
        char *dica = strchr(palavra, '$'); // busca a dica na palavra escolhida

        *dica = '\0'; // insere o caractere nulo no lugar do '$', para separar a palavra da dica
        
        strcpy(matchData->palavraEscolhida, palavra); // copia apenas a palavra para a estrutura

        matchData->letrasRestantes = strlen(matchData->palavraEscolhida) - 1; // define a quantidade de letras restantes
        
        strcpy(matchData->dica, dica + 1); // manda a dica para a estrutura, ignorando o caractere "$"
        
        memset(matchData->palavraImpressa, '_', matchData->letrasRestantes); // Muda a palavra impressa por "_"
        
        matchData->chancesRestantes = 7; // define as chances iniciais do jogador
}


//função 2 | verifica a letra 
int verificarLetra(MatchData *matchData, char letra) {
    int encontrou = 0;
    for (int i = 0; i < strlen(matchData->palavraEscolhida); i++) {
        if (matchData->palavraEscolhida[i] == letra) {
            encontrou = 1;
            if (matchData->palavraImpressa[i] == '_') {
                matchData->palavraImpressa[i] = letra;
                matchData->letrasRestantes--;
            }
        }
    }
    if (!encontrou) {
        matchData->chancesRestantes--;
        printf("Letra nao encontrada! Restam %d chances\n", matchData->chancesRestantes);
    }
    return encontrou;
}

//função 3 | imprime a palavra com as letras já descobertas
void imprimirPalavra(MatchData *matchData) {
    printf("Palavra: ");
    for (int i = 0; i < strlen(matchData->palavraImpressa); i++) {
        printf("%c ", matchData->palavraImpressa[i]);
    }
    printf("\n");
}