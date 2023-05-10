#include <stdio.h> 



int main(){

FILE* arquivo = fopen("arquivo.txt", "r");
if (arquivo == NULL){
    printf("Erro a abrir o arquivo!");
}
int x, y, z;
fscanf(arquivo, "%i %i %i ", &x, &y, &z);
printf("%i %i %i ", x, y, z);

fclose(arquivo);


return 0;


}