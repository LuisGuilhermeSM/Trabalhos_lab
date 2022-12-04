#include <stdio.h>

void iniciar_vetor(float * vetor, int tam);
float produtorio_vetor(float * vetor, int tam);
void printar_vetor_produtorio(float * vetor, int tam );

int main(int argc, char** argv){
    int n;
    printf("Digite o numero de elementos do vetor: \n");
    scanf("%d", &n);
    float vetor[n]; // so funciona no c99
    iniciar_vetor(vetor, n);
    printar_vetor_produtorio(vetor, n );
    

    return 0;
}

void iniciar_vetor(float * vetor, int tam){
    printf("Informe os elementos do vetor: \n");
    for(int i = 0; i < tam; i++ ){
        scanf("%f", &vetor[i]); 
    }

}

float produtorio_vetor(float * vetor, int tam){
    float produto = 1;
    for(int i = 0; i < tam; i++){
        produto = produto * *(vetor + i);
    }

    return produto;
}

void printar_vetor_produtorio(float * vetor, int tam ){
    float produto = produtorio_vetor(vetor, tam);
    printf("%g ", vetor[0]);
    for(int i = 1; i < tam; i++ ){
        printf("* %g ", *(vetor + i));  
    }
    printf("= %g", produto);
    
}