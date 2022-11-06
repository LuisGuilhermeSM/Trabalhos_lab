#include <stdio.h>

int main(int argc, char** argv){
    int num, soma;
    soma = 0 ;
    printf("Digite um número: ");
    scanf("%d", &num);
    
    for( ; num > 0 ; num = num -1){
        soma = soma + num;
        
    };
    printf("Soma = %d\n", soma);


    return 0;
}