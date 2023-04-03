// Nome: Henrique Borges Krause     Matricula: 21201500



#include <stdio.h>
#include <math.h>


//soma
double soma(double num1, double num2) {
    return num1 + num2;
}


//subtração 
double subtrai(double num1, double num2) {
    return num1 - num2;
}


//Multiplicação 
double multiplica(double num1, double num2) {
    return num1 * num2;
}

//divisão

double divide(double num1, double num2) {
    return num1 / num2;
}

//fatorial 
double fatorial(double num) {
    num = lround(num); // arredonda o número
    double fat = 1;
    while (num > 1) {
        fat *= num--;
    }
    return fat;
}


//inicio da função main
int main() {
    int opcao;
    double num, num1, num2;

    do {
        
        printf("\nSeja Bem-Vindo a calculadora:\n ");
        printf("====================================\n");
        printf("\nEscolha a operacao desejada:\n");
        printf("1 - Soma\n");
        printf("2 - Subtrai\n");
        printf("3 - Multiplica\n");
        printf("4 - Divide\n");
        printf("5 - Fatorial\n");
        printf("6 - Sair\n");
        printf("\n====================================\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        
        switch(opcao) {
            case 1:
                printf("Digite os dois numeros a serem somados:\n ");
                scanf("%lf %lf", &num1, &num2);
                printf("Resultado: %lf\n", soma(num1, num2));
                break;
            case 2:
                printf("Digite os dois numeros a serem subtraidos: \n");
                scanf("%lf %lf", &num1, &num2);
                printf("Resultado: %lf\n", subtrai(num1, num2));
                break;
            case 3:
                printf("Digite os dois numeros a serem multiplicados: \n");
                scanf("%lf %lf", &num1, &num2);
                printf("Resultado: %lf\n", multiplica(num1, num2));
                break;
            case 4:
                printf("Digite os dois numeros a serem divididos: \n");
                scanf("%lf %lf", &num1, &num2);
                printf("Resultado: %lf\n", divide(num1, num2));
                break;
            case 5:
                printf("Digite o numero a ser calculado o fatorial:\n ");
                scanf("%lf", &num);
                double resultado = fatorial(num);
                printf("O fatorial de %.1f arredondado é: %.0f\n", num, resultado);
                break;
            case 6:
                printf("Encerrando o programa...\n");
                printf("Obrigado!");
                break;
            default:
                printf("\n => !WARNING! <=\n");
                printf("Opcao invalida! Escolha uma opcao valida.\n");
        }

    } while(opcao != 6);  

    return 0;
}