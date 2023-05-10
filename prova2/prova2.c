#include <stdio.h> //bibioteca padrão paa executar um prorama em c 
#include <stdlib.h> //usamos para a manipulação de arquivos 
#include <math.h> //usamos para os calculos matematicos, nao esquecer de adicionar o "-lm", no final do codigo de comilaçãõ 

//crinado estruturas de armazenamento

typedef struct antenas{
    int x;      //coordenada x da antena 
    int y;      //coordenada y da antena 
    float raio;    //rao que a antena abrange 
    struct antenas *prox;     //esse ponteiro serve para informar que a struct atual armazena e aponta para a proxima estrutura de armazenamento
} antenas;


typedef struct usuario{
    int x;     //coordenada x do usuario 
    int y;     //coordenada y do usuario 
    struct usuario*prox; //aqui se repete o mesmo caso da aterior
} usuario;

//inicio da função principal
int main(){



//abrir e ler o arquivo de entrada
FILE *entrada = fopen("entrada.txt", "r"); //a sigla r significa read, ou seja, vai abrir o arquivo para ler

if (entrada == NULL){  //verifica se existe esse arquivo e se existe conteudo, caso contrario ele não abre e da o aviso 
    printf("Erro ao abrir o programa, verifique se existe o arquivo.txt");
    return 1;
}



//fazer duas listas encadeadas com cabeça uma para usuários e outra para antenas
antenas *antena = malloc(sizeof(antenas)); //alocando memoria para a struct antenas
antena->prox = NULL; //inicializando o ponteiro prox da struct antenas
usuario *user = malloc(sizeof(usuario)); //alocando memoria para a struct usuario
user->prox = NULL; //inicializando o ponteiro prox da struct usuario


//Para que serve o operador "->":
// Esse operador é usado para ACESSAR uma estrutura ou um pnteiro, se observar ele esta acesando o prox que é um pnteiro definido dentro 
//das structs antenas e usuario por isso sua declaração é ( <nome da alocação> acessa <nome do ponteiro> = <sua condição), no caso em questão, ele esta acessando uma 
//nova struct apontada pelo ponteiro prox dentroda struct antenas e usuarios. 

//                (<nome da alocação> operador <nome do poteiro> = condição )
//                (antena                ->         prox          =   NULL  )


//nesse malloc é uma lista encadeada com cabeça, por conta de que a prmeira posição ou o primeiro bloco semr vai estar limpor sem nenhuma informação armazenada
//essa é a função do "prox = NULL" que avança uma posição  esta sempre vazia 


//ler e armazenar as antenas
int num_antenas;   //cria uma variavel para armazenar o numero de antenas contidas na entrada 
fscanf(entrada, "%d", &num_antenas);   //fscanf (lê é a mesma função scan padrão mas serve para ler o arquivo.txt)
                                        // aqui ele vai ler o prmeiro inteiro "%d" da entrada e armazenar como a quanidade de antenas, por conta desta ser a estrurua do arquivo txt



for (int i = 0; i < num_antenas; i++){ //cira um laço de repetição com uma varialvel local "i" que percorre a lista encadeada o numero de vezes que temos de antenas
                                        // se tivermos 3 antenas vai percorrer 3 vezes e armazenar a sequencia respectiva
                                        //No caso seria da seguinte forma 1° linha após a quantidade (x,y e raio) 2° (x,y e raio ) 3°(x,y e raio) e aqui encerra por que 
                                        //o numero de antenas acaba e se encerra o laço de repetição;
    
    
    int x, y;                           //variavel local de coordenanda da antena 
    float raio;                         //variavel local de raio da antena
    fscanf(entrada, "%d %d %f", &x, &y, &raio);    //leitura do arquivo com a função da <stdlib.h> de fscanf
    antenas *nova_antena = malloc(sizeof(antenas)); //alocando memoria para a struct antenas o *nova_antena é uma varivel local e temporaria que é usada para criar novos blocos de alocação 
    nova_antena->x = x;  //atribue o valor de x a variavel "x" da nova antena, e usa o operador "->" por que o nova antena é um ponteiro para a struct "antenas"(decarada la no inicio )
    nova_antena->raio = raio;
    nova_antena->prox = antena->prox;
    antena->prox = nova_antena;
    //aqui as infromções são armazenadas na estrutura cirada "nova_antena", que foi alocada dinamicamente pelo malloc
    //O operador "->" é usado para acessar o campo especifico da estrutura por exemplo o x, em seguida a estrutura "nova_antena" é armazenada 
    //na lista encadeada antena  por meio do ponteiro que criamos la na struct inicial "*prox";
}



//ler e armazenar os usuários
int num_usuarios;
fscanf(entrada, "%d", &num_usuarios);
for (int i = 0; i < num_usuarios; i++){
    int x, y;
    fscanf(entrada, "%d %d", &x, &y);
    usuario *novo_user = malloc(sizeof(usuario)); //alocando memoria para a struct usuario
    novo_user->x = x;
    novo_user->y = y;
    novo_user->prox = user->prox;
    user->prox = novo_user;

    //Aqui se repete a mesma questão da anterior, se le a quantidade armazena em uma variavel local, se cria um laço que percorre o tamanho da variavel criada
    //e se armazena as informações na estrutura criada "novo_user" e se armazena na lista encadeada "user" por meio do ponteiro "*prox"
}


//fechar o arquivo de entrada
fclose(entrada);



//abrir arquivo de saida
FILE *saida = fopen("saida.txt", "w");

if (saida == NULL){
    printf("Erro ao abrir arquivo de saida.");
    return 1;
}


//calcular a qualidade do sinal para cada usuário
usuario *u_atual = user->prox; //Esta linha cria um ponteiro para o próximo usuário na lista encadeada de usuários, começando a partir do nó raiz user.


while (u_atual != NULL){  //inicia um laço de repetição que continua executando enquanto o ponteiro temporario *u_atual (usuario atual) for diferente de vazio 
    
    antenas *a_atual = antena->prox; //inicialização e declaração de uma variavel que aponta para a primeira antena na lista "antena";
    float menor_distancia = -1; //inicia a variavel para encontrar a meos distancia, tendo um valor negativo para se identificar que não foi encontrado nenhuma ainda 
    float qualidade_sinal = -1; // aqui a mesma coisa da anterio mas indica que n encontramos nenhum sinal melhor 


    while (a_atual != NULL){ //laço de repetição percorre todas as antenas até ela ser diferente de vazia 
        float d = sqrt(pow(u_atual->x - a_atual->x, 2) + pow(u_atual->y - a_atual->y, 2)); //calculode distancia usando as funções dabiblioteca math.h
        if (menor_distancia < 0 || d < menor_distancia){ // se a distancia for menor que a a calculada armazena caso contrario mantem a ja existente 
            menor_distancia = d;
            qualidade_sinal = 1 / (1 + sqrt(d));
        }
        a_atual = a_atual->prox; //Move o ponteiro para a próxima antena na lista encadeada de antenas.


    }
    fprintf(saida, "Usuário: (%d,%d) - Qualidade do sinal: %f\n", u_atual->x, u_atual->y, qualidade_sinal); //Imprime no arquivo de saída a informação da qualidade do sinal para o usuário atual
    u_atual = u_atual->prox; //atualiza o ponteiro para o proximo usuario na lista 
}



//fechar o arquivo de saida
fclose(saida);


return 0;
}