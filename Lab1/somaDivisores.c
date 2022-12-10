#include <stdio.h>

int main(int argc, char** argv){
    int num, divisor, soma;
    printf("Digite um numero: \n");
    scanf("%d", &num);

    for( divisor = num ; divisor > 0; divisor--){
        if( (num % divisor) == 0){
            soma = soma + divisor;
        }

    };

    //printf("Soma dos divisores de %d = %d", num, soma);
    printf("%d", soma);
    return 0;

}