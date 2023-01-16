#include <stdio.h>
#include <stdlib.h>

long long int elemento_golom(long long int n);
long long int * sequencia_de_golomb(long long int a, long long int b);
double media(long long int * seq, long long int num_elementos);

int main(int argc, char** argv){
    long long int a, b, *seq, aux;
    double med;
    printf("Digite o primeiro indice:\n");
    scanf("%lld%*c", &a);
    printf("Digite o segundo indice:\n");
    scanf("%lld%*c", &b);
    if(b < a){ 
        aux = a; 
        a = b; 
        b = a; 
    }
    /*aux = elemento_golom(5);
    printf("%lld", aux );*/
    seq = sequencia_de_golomb(a, b);
    /*for(long long int i = 0; i < (1 + b - a); i++){ 
        printf("%lld ", seq[i]);
    }*/

    med = media(seq, b-a + 1);
    printf("%lld %lld %llf", seq[0], seq[(b - a)], med);

    free(seq);
    
    
    return 0;

}

/*long long int * sequencia_de_golomb(long long int b){ //Ate o indice b
    //printf("%lld\n", b);
    long long int * seq = (long long int*) malloc((b + 1) * sizeof(long long int));
    //printf("%lld\n", b);
    
    for(long long int i = 0; i <= b; i++){
        seq[i] = elemento_golom(i);
    }

    return seq;
}*/

long long int * sequencia_de_golomb(long long int a, long long int b){
    //printf("%lld\n", b);
    long long int * seq = (long long int*) malloc((b + 1 - a) * sizeof(long long int));
    //printf("%lld\n", b);
    
    for(long long int i = 0; i < (1 + b - a); i++){
        seq[i] = elemento_golom(i + a);
        //printf("%lld ", seq[i]);
    }

    return seq;
}


long long int elemento_golom(long long int n){
    if(n == 0){
        return 1;
    }
    else{
        return 1 + elemento_golom(n - elemento_golom(elemento_golom(n-1) - 1));
    }
}

double media(long long int * seq, long long int num_elementos){
    double res = 0;
    for(int i = 0; i < num_elementos; i++){
        res = res + seq[i];
    }
    
    res = res/num_elementos;

    return res;
}