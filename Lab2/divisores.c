#include <stdio.h>

int main(int argc, char** argv){
    int num;

    printf("Digite um numero inteiro: \n");
    scanf("%d", &num);

    for(int i = 1; i <= num; i++ ){
        if(num % i == 0){
            printf("%d", i);
            
            if(i != num){
                printf(", ");
            }
        }
    }

    return 0;

}