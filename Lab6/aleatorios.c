#include <stdio.h>
#include <stdlib.h>

long long int * seq_aleatoria(long long int num_elementos);
double media(long long int * seq, long long int num_elementos);
long long int min_vetor(long long int * vetor, long long int tam);
long long int max_vetor(long long int * vetor, long long int tam);

int main(int argc, char** argv){
    long long int n, *seq, min, max;
    double med;
    printf("Digite o numero de elementos:\n");
    scanf("%lld%*c", &n);
    seq = seq_aleatoria(n);
    med = media(seq, n);
    min = min_vetor(seq, n);
    max = max_vetor(seq, n);
    printf("%lld %lld %llf\n", min, max, med);

    /*for(int i = 0; i < n; i++){ 
        printf("%d ", seq[i]);
    }*/

    free(seq);
    return 0;
}

long long int * seq_aleatoria(long long int num_elementos){
    long long int * seq = (long long int*) malloc(num_elementos * sizeof(long long int));
    srand(num_elementos);

    for(int i = 0; i < num_elementos; i++){
        seq[i] = rand() % num_elementos;
    }

    return seq;
}

double media(long long int * seq, long long int num_elementos){
    double res = 0;
    for(int i = 0; i < num_elementos; i++){
        res = res + seq[i];
    }
    
    res = res/num_elementos;

    return res;
}

long long int min_vetor(long long int * vetor, long long int tam){
    long long int menor;
    menor = vetor[0];
    for(int i = 1; i < tam; i++){
        if(menor > vetor[i]){
            menor = vetor[i];
        }   
    }
    return menor;
}

long long int max_vetor(long long int * vetor, long long int tam){
    long long int max;
    max = vetor[0];
    for(int i = 1; i < tam; i++){
        if(max < vetor[i]){
            max = vetor[i];
        }   
    }
    return max ;
}