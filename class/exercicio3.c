// Utilizando o programa anterior, fazer um novo programa que verifica se o aluno atingiu a
// média 7. Caso positivo, o programa imprime a mensagem “aprovado por média”. Caso
// contrário, o programa calcula e imprime o valor necessário na optativa, apresentando a
// mensagem apropriada. (Lembre-se que a média dos trabalhos não pode ser substituída
// pela optativa).

#include <stdio.h>


int main(){

    int v1 = 6;
    int v2 = 7;
    int mt = 8;

    int media;

    media = (3*v1+3*v2+4*mt)/10;


    if(media >= 7){
        printf("Aprovado por media");
    }
    else{
        printf("Reprovado por media");
    }

    return 0;

}