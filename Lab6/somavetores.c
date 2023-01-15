#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int *sequencia_impar(int num_elementos);
int *sequencia_mult_4(int num_elementos);
bool soma_vet(int * v1, int n1, int * v2, int n2, int * res);
void printar_vetor(int * vetor, int tam );

int main(int argc, char** argv){
    int tam1, tam2, *seq_impares, *seq_mult_4, somou;
    //int *res = (int*) malloc(tam1 * sizeof(int));
    printf("Digite o numero de elementos da primeira sequencia: \n");
    scanf("%d%*c", &tam1);
    printf("Digite o numero de elementos da segunda sequencia: \n");
    scanf("%d%*c", &tam2);
    int *res = (int*) malloc(tam1 * sizeof(int));
    
    seq_impares = sequencia_impar(tam1);
    seq_mult_4 = sequencia_mult_4(tam2);
    somou = soma_vet(seq_impares, tam1, seq_mult_4, tam2, res);
    if(somou){
        printar_vetor(res, tam1);
    }
    else{
        printf("mensagem que nao pode somar vetores");
    }

    //free(seq_impares);
    //free(seq_mult_4);

    /*for(int i = 0; i < tam1; i++){ 
        printf("%d ", res[i]);
    }
    printf("\n");
    for(int i = 0; i < tam2; i++){ 
        printf("%d ", seq_mult_4[i]);
    }*/
    
    free(seq_impares);
    free(seq_mult_4);
    free(res);

    return 0;

}

int *sequencia_impar(int num_elementos){
    int *sequencia = (int*) malloc(1);
    int num_inicial = 1;
    int tam = 0;

    while(num_elementos > 0){
        if( (num_inicial % 2) == 1){
            sequencia = (int *) realloc(sequencia, (tam + 1) * sizeof(int));
            sequencia[tam] = num_inicial;
            num_inicial += 1;
            num_elementos -= 1;
            tam += 1;
        }
        else{
            num_inicial +=1;
        }

    }

    return sequencia;

}

int *sequencia_mult_4(int num_elementos){
    int *sequencia = (int*) malloc(1);
    int num_inicial = 0;
    int tam = 0;

    while(num_elementos > 0){
        sequencia = (int *) realloc(sequencia, (tam + 1) * sizeof(int));
        sequencia[tam] = num_inicial;
        num_inicial += 4;
        num_elementos -= 1;
        tam += 1;
    }

    return sequencia;

}

bool soma_vet(int * v1, int n1, int * v2, int n2, int * res){
    if(n1 == n2){
        //int *res = (int*) realloc(res, n1 * sizeof(int));
        for(int i = 0; i < n1; i++){
            res[i] = v1[i] + v2[i];
        }
        return true;
    }
    else{
        return false;
    }
}

void printar_vetor(int * vetor, int tam ){
    printf("%d", vetor[0]);
    for(int i = 1; i < tam; i++ ){
        printf(", %d", *(vetor + i));  
    }

}