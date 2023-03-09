// Dados três números inteiros correspondentes, respectivamente, ao dia, mês e ano de
// nascimento de uma pessoa e três outros números correspondentes ao dia, mês e ano
// corrente (ex. data de hoje), calcular e imprimir a idade em anos completos. Verificar se as
// datas são compatíveis (nascimento <= corrente).

#include <stdio.h>

int main(){

int day, month, year, day1, month1, year1;

printf("Digite o dia do seu nascimento:");
scanf("%d", &day);

printf("Digite o mes do seu nascimento:");
scanf("%d", &month);

printf("Digite o ano do seu nascimento:");
scanf("%d", &year);

printf("Digite o dia atual:");
scanf("%d", &day1);

printf("Digite o mes atual:");
scanf("%d", &month1);

printf("Digite o ano atual:");
scanf("%d", &year1);

int idade = year - year1;

if ( year > year1){
    printf("Vocẽ não nasceu ainda !");
}

else {
    printf("Sua idade é: %d", idade);

}



    return 0;

}