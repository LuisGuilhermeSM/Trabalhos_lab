#include <stdio.h>

void iniciar_vetor(int * vetor, int tam);
int ver_se_e_divisor(int num_vetor, int num);
void printar_vetor(int * vetor, int tam, int num_dividido);

int main(int argc, char** argv){
    int n, num_divisores;
    printf("Digite o numero de elementos do vetor: \n");
    scanf("%d", &n);
    int vetor[n]; // so funciona no c99
    iniciar_vetor(vetor, n);
    printf("Digite o numero que deseja ver quais os divisores: \n");
    scanf("%d", &num_divisores);
    printar_vetor(vetor, n, num_divisores);

    return 0;

}

void iniciar_vetor(int * vetor, int tam){
    printf("Informe os elementos do vetor: \n");
    for(int i = 0; i < tam; i++ ){
        scanf("%d", vetor + i); 
    }

}

int ver_se_e_divisor(int num_vetor, int num){
    if( num % num_vetor == 0){
        return 1;
    }
    else{
        return 0;
    }
}

void printar_vetor(int * vetor, int tam, int num_dividido){
    for(int i = 0; i < tam; i++ ){
        //printf("%g ", vetor[i]);
        if( ver_se_e_divisor( *(vetor + i), num_dividido ) ){
            printf("%d# ", *(vetor + i));
        }
        else{
            printf("%d ", *(vetor + i));
        }
    }
}



