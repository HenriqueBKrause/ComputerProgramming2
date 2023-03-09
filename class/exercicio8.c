// Faça um programa que recebe um número inteiro e verifica se o número é primo ou não,
// escrevendo uma mensagem apropriada.

#include <stdio.h>

int main() {
   int num, i, flag = 0;
   printf("Digite um número inteiro: ");
   scanf("%d", &num);

   for(i = 2; i <= num/2; ++i) {
      if(num%i == 0) {
         flag = 1;
         break;
      }
   }

   if (flag == 0)
      printf("%d é um número primo.", num);
   else
      printf("%d não é um número primo.", num);

   return 0;
}