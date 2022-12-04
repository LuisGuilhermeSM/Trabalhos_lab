#include <stdio.h>
#include <math.h>

void iniciar_vetor(float * vetor, int tam);
float somatorio_vetor(float * vetor, int tam);
float desvio_pad(float * vetor, int tam, float media);


int main(int argc, char** argv){
    int n;
    printf("Digite o numero de elementos do vetor: \n");
    scanf("%d", &n);
    float vetor[n], media, desvio; // so funciona no c99
    iniciar_vetor(vetor, n);
    media = somatorio_vetor(vetor, n) / n;
    desvio = desvio_pad(vetor, n, media);
    printf("Media = %g, Desvio = %g", media, desvio);

    
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

float desvio_pad(float * vetor, int tam, float media){
    float desvio = 0, soma_quadrada = 0;
    for(int i = 0; i < tam; i++ ){
        //soma_quadrada = (*(vetor + i) - media) * (*(vetor + i) - media);
        soma_quadrada = soma_quadrada + pow((*(vetor + i) - media), 2);
    }

    desvio = sqrt( soma_quadrada / tam);

    return desvio;
}

