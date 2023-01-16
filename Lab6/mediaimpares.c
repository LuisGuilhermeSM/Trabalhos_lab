#include <stdio.h>
#include <stdlib.h>

int *sequencia(int num_elementos, int num_inicial);
double media(int * seq, int num_elementos);

int main(int argc, char** argv){
    int num_elementos, num_inicial, *seq;
    double med;
    printf("Digite o numero de elementos da sequencia e o numero inicial dela:\n");
    scanf("%d %d", &num_elementos, &num_inicial);
    seq = sequencia( num_elementos, num_inicial);
    med = media(seq, num_elementos);

    printf("%d %llf", seq[num_elementos - 2], med);

    /*for(int i = 0; i < num_elementos; i++){ Para printar a sequencia
        printf("%d ", seq[i]);
    }*/

    free(seq);
    /*for(int i = 0; i < num_elementos; i++){ 
        printf("%d ", seq[i]);
    }*/

    return 0;
}

int *sequencia(int num_elementos, int num_inicial){
    int *sequencia = (int*) malloc(1);
    int tam = 0;
    //printf("%d %d\n", num_elementos, num_inicial);

    while(num_elementos > 0){
        if( (num_inicial % 2) == 1){
            //printf("oi");
            sequencia = (int *) realloc(sequencia, (tam + 1) * sizeof(int));
            sequencia[tam] = num_inicial;
            //printf("%d", sequencia[tam]);
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

double media(int * seq, int num_elementos){
    double res = 0;
    for(int i = 0; i < num_elementos; i++){
        res = res + seq[i];
    }
    //printf("%llf \n", res);
    res = res/num_elementos;
    //printf("%llf \n", res);

    return res;
}

