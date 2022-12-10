#include <stdio.h>
#include <stdint.h>

int main(int argc, char** argv){
    int num, fatorial, numimprimir;
    
    int64_t fat = 1;
    //fatorial = 1;
    printf("Digite um numero: \n");
    scanf("%d", &num);
    numimprimir = num;
    //printf(" %d", num);

    for( ; num > 0; num = num - 1 ){
        //fatorial = fatorial * num;
        fat = fat * num;
        
    };

    //printf("%d! = %d \n", numimprimir, fatorial);
    printf("%d! = %lld \n", numimprimir, fat);

    return 0;
}