//crio um algoritimo que diga que o numero lido é primo ou não;
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
 
int main() {
 
    int i, valor, aux = 0;
 
    printf("Digite um valor para saber se ele é primo:");
    scanf("%d", &valor);
 
    for(i = 1; i <= valor ; i++){
        if(valor % i == 0){
            aux++;
        }
 
        printf("%d / %d tem o resto = %d \n", valor, i, valor%i);
     }
 
     if(aux == 2){
        printf("O número é primo!");
    }else{
        printf("O número não é primo! Pois ele tem %d divisores", aux);
    }
}