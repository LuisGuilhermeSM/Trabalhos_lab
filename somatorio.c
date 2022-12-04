#include <stdio.h>

void iniciar_vetor(float * vetor, int tam);
float somatorio_vetor(float * vetor, int tam);
void printar_vetor_somatoria(float * vetor, int tam );

int main(int argc, char** argv){
    int n;
    printf("Digite o numero de elementos do vetor: \n");
    scanf("%d", &n);
    float vetor[n]; // so funciona no c99
    iniciar_vetor(vetor, n);
    printar_vetor_somatoria(vetor, n );
    

    return 0;
}

void iniciar_vetor(float * vetor, int tam){
    printf("Informe os elementos do vetor: \n");
    for(int i = 0; i < tam; i++ ){
        scanf("%f", &vetor[i]); 
    }

}

float somatorio_vetor(float * vetor, int tam){
    float soma = 0;
    for(int i = 0; i < tam; i++){
        soma = soma + *(vetor + i);
    }

    return soma;
}

void printar_vetor_somatoria(float * vetor, int tam ){
    float soma = somatorio_vetor(vetor, tam);
    printf("%g ", vetor[0]);
    for(int i = 1; i < tam; i++ ){
        printf("+ %g ", *(vetor + i));  
    }
    printf("= %g", soma);

}