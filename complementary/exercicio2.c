//crie um algoritimo que imprima os numeros pares de 10 a 20;


#include <stdio.h>

int main(){

    int i;

    for(i=10; i<=20; i++){
        if(i%2 == 0){
            printf("%d\n", i);
        }
    }

    printf("Esses são todos os numeros pares ente 10 e 20!");
    return 0;

}