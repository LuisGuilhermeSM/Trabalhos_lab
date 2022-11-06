#include <stdio.h>

int main(int argc, char** argv){
    int num, fatorial, numimprimir;
    fatorial = 1;
    printf("Digite um numero: \n");
    scanf("%d", &num);
    numimprimir = num;
    //printf(" %d", num);

    for( ; num > 0; num = num - 1 ){
        fatorial = fatorial * num;
        
    };

    printf("%d! = %d \n ", numimprimir, fatorial);

    return 0;
}