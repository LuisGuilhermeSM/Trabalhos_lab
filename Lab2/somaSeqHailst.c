#include <stdio.h>

int seq_hailst(int numi);

int main(int argc, char** argv){
    int numi, soma_total;

    printf("Digite um numero inteiro positivo: \n");
    scanf("%d", &numi );

    soma_total = seq_hailst(numi);
    printf("%d", soma_total);

    return 0;
}


int seq_hailst(int numi){
    int soma = numi, novo_num;

    if(numi == 1){
        return 1; 
    } 
    else if( (numi % 2) == 1 ){
        novo_num = ((3*numi) + 1);
        return soma = soma + seq_hailst(novo_num);
   
    }
    else{
        novo_num = numi / 2;
        return soma = soma + seq_hailst(novo_num);

    }
}