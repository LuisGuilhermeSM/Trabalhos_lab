#include <stdio.h>


int soma_digitos_quadrados(int num);
int num_feliz(int numi);
int primo(int num);
int maior_primo_feliz(int num);

int main(int argc , char** argv){
    int num, num_primo_feliz;
    
    printf("Digite um numero: \n");
    scanf("%d", &num);

    //printf("Soma: %d \n", soma_digitos_quadrados(num));
    //printf("E feliz: %d", num_feliz(num));

    num_primo_feliz = maior_primo_feliz(num);
    //printf("%d", num_primo_feliz);
    if(num_primo_feliz == 0){
        printf("0***");
    }
    else{
        printf("%d", num_primo_feliz);
    }

    return 0;


}


int num_feliz(int numi){
    int soma_digitos;

    soma_digitos = soma_digitos_quadrados(numi);
    
    if(soma_digitos == 1){
        return 1;
    }
    else if(soma_digitos == 4){
        return 0;
    }
    else{
        return num_feliz(soma_digitos);
    }
    
}

int soma_digitos_quadrados(int num){
    int soma = 0, digito;

    for(num; num >= 1; num = num/10){
        soma = soma + ((num % 10) * (num % 10));
    } 

    return soma;
}

int primo(int num){
    
    int i = 2;
    while(i < num){
        if(num % i == 0){
            return 0;
        } 

        i = i + 1;
    }

    if(num != 1){
        return 1;
    }
    else{
        return 0;
    }
}

int maior_primo_feliz(int num){
    for(num; num > 0; num--){
        if( primo(num) & num_feliz(num)){
            return num ;
        }
    }

    return 0;
}