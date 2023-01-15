#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long int *sequencia(long int num_elementos, long int num_inicial);
double media(long int * seq, long int num_elementos);
long int min_vetor(long int * vetor, long int tam);
long int max_vetor(long int * vetor, long int tam);

int main(int argc, char** argv){
    long int num_elementos, num_inicial, min, max, *seq;
    double med;
    printf("Digite o numero de elementos da sequencia e o numero inicial dela:\n");
    scanf("%ld %ld", &num_elementos, &num_inicial);
    seq = sequencia(num_elementos, num_inicial);
    med = media(seq, num_elementos);
    min = min_vetor(seq, num_elementos);
    max = max_vetor(seq, num_elementos);

    /*for(int i = 0; i < num_elementos; i++){ 
        printf("%d ", seq[i]);
    }*/

    printf("%ld %ld %llf", min, max, med);

    free(seq);

}

long int *sequencia(long int num_elementos, long int num_inicial){
    long int *sequencia = (long int*) malloc(1 * sizeof(long int));
    sequencia[0] = num_inicial; 
    int tam = 1;
    num_elementos -= 1;

    while(num_elementos > 0){
        if( (num_inicial % 2) == 0){
            num_inicial = floor(sqrt(num_inicial));
            sequencia = (long int *) realloc(sequencia, (tam + 1) * sizeof(long int));
            sequencia[tam] = num_inicial;
            num_elementos -= 1;
            tam += 1;
        }
        else{
            num_inicial = floor(sqrt(pow(num_inicial, 3)));
            sequencia = (long int *) realloc(sequencia, (tam + 1) * sizeof(long int));
            sequencia[tam] = num_inicial;
            num_elementos -= 1;
            tam += 1;
        }

    }

    return sequencia;
}

double media(long int * seq, long int num_elementos){
    double res = 0;
    for(int i = 0; i < num_elementos; i++){
        res = res + seq[i];
    }
    
    res = res/num_elementos;

    return res;
}

long int min_vetor(long int * vetor, long int tam){
    long int menor;
    menor = vetor[0];
    for(int i = 1; i < tam; i++){
        if(menor > vetor[i]){
            menor = vetor[i];
        }   
    }
    return menor;
}

long int max_vetor(long int * vetor, long int tam){
    long int max;
    max = vetor[0];
    for(int i = 1; i < tam; i++){
        if(max < vetor[i]){
            max = vetor[i];
        }   
    }
    return max ;
}