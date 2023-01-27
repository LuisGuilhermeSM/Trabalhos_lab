#include <stdio.h>
#include <stdlib.h>

long long int * seq_fib(int ind);

int main(int argc, char** argv){
    FILE *arq;
    int num;
    long long int *seq;
    printf("Digite o numero de elementos da sequencia:\n");
    scanf("%d", &num);
    seq = seq_fib(num);

    /*for(int i = 0; i < num; i++){
        printf("%lld ", seq[i]);
    }*/
    printf("O ultimo numero e:\n%lld", seq[num - 1]);

    arq = fopen("fibonacci.txt", "w");
    for(int i = 0; i < num; i++){
        fprintf(arq, "%lld\n", seq[i]);
    }
    
    
    
    fclose(arq);
    free(seq);

    return 0;
}

long long int * seq_fib(int ind){
    long long int *seq = (long long int*) malloc( (ind) * sizeof(long long int) );
    long long int num_ant = 0, aux0 = 0, num_seq = 0;

    for(int i = 0; i < ind; i++){
        if(i == 1){
            seq[i] = 1;
            num_seq = 1;
        }
        else{
            num_ant = num_seq;
            num_seq = num_seq + aux0;
            seq[i] = num_seq;
            
            aux0 = num_ant;
        }
    }

    return seq;
}