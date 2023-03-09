//Crie um algeritme que imprima os nimeres de 10 até 0
//de. forma regressiva. (usando While, Do While |B For)

#include <stdio.h>

// imprimindo com while

int main(){
    int contador = 10;

    while(contador >=0){
        printf("%d\n", contador);
        contador--;
    }
    printf("fim da contagem!");
return 0;
}


//usando do while

int main(){
    int contador=10;

    do {
        printf("%d\n", contador);
        contador--;
    }while(contador >=0);

    printf("fim da contagem!");
return 0;
}


//usando for 

int main(){
    int contador;

    for(contador=10;contador>=0;contador--){
        printf("%d\n", contador);
    }
printf("fim da contagem");
return 0;

}