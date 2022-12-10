#include <stdio.h>

int primo(int num);
int soma_primos(int inicio_a, int final_b);

int main(int argc, char** argv){
    int a, b;
    printf(" Digite o intervalo desejado em que o primeiro numero deve ser menor que o segundo: \n");
    scanf("%d %d", &a, &b);

    printf("%d", soma_primos(a, b));
    //int teste = primo(7);
    
    //printf("%d", teste);

    return 0;

}

int primo(int num){
    
    int i = 2;
    while(i < num){
        if(num % i == 0){
            return 0;
        } 

        i = i + 1;
    }

    /*for(int i = num - 1; i > 2; i-- ){
        if(num % i == 0){
            return 0;
        }
    }*/
    if(num != 1){
        return num;
    }
    else{
        return 0;
    }
    
}

int soma_primos(int inicio_a, int final_b){
    int soma = 0;
    for(inicio_a; inicio_a <= final_b; inicio_a++){
        //printf("%d \n", soma);
        soma = primo(inicio_a) + soma;
    }

    return soma;

}

