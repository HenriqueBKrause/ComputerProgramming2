//aplicação de ponteiros:

#include <stdio.h>


int main(){
    int a;
    int *ponteiro;

    a = 10;
    ponteiro = &a;

    printf("%d\n", a);
    printf("%d\n", *ponteiro);

    //mudando o valor de a atraves do ponteiro

    *ponteiro = 20;

    printf("%d\n", a);
    printf("%d\n", *ponteiro);

    return 0;
}