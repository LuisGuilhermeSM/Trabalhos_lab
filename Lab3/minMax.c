#include <stdio.h>

void iniciar_vetor(float * vetor, int tam);
void printar_vetor(float * vetor, int tam, int menor, int maior);
float min_vetor(float * vetor, int tam);
float max_vetor(float * vetor, int tam);

int main(int argc, char** argv){
    int n;
    float min, max;
    printf("Digite o numero de elementos do vetor: \n");
    scanf("%d", &n);
    float vetor[n]; // so funciona no c99
    iniciar_vetor(vetor, n);
    //printar_vetor(vetor, n);
    min = min_vetor(vetor, n);
    max = max_vetor(vetor, n);
    printar_vetor(vetor, n, min, max);
    //printf("\nMinimo: %g", min);
    //printf("\nMaximo: %g", max);



    return 0;

}

void iniciar_vetor(float * vetor, int tam){
    printf("Informe os elementos do vetor: \n");
    for(int i = 0; i < tam; i++ ){
        scanf("%f", &vetor[i]); 
    }

}

void printar_vetor(float * vetor, int tam, int menor, int maior){
    for(int i = 0; i < tam; i++ ){
        //printf("%g ", vetor[i]);
        if(vetor[i] == menor){
            printf("%g< ", vetor[i]);
        }
        else if(vetor[i] == maior)
        {
            printf("%g> ", vetor[i]);
        }
        else{
            printf("%g ", vetor[i]);
        }
        
        /*if(i != (tam - 1) ){
            printf(", ");
        } */   
    }
}

float min_vetor(float * vetor, int tam){
    float menor;
    menor = vetor[0];
    for(int i = 1; i < tam; i++){
        if(menor > vetor[i]){
            menor = vetor[i];
        }   
    }
    return menor;
}

float max_vetor(float * vetor, int tam){
    float max;
    max = vetor[0];
    for(int i = 1; i < tam; i++){
        if(max < vetor[i]){
            max = vetor[i];
        }   
    }
    return max ;
}