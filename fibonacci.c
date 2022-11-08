#include <stdio.h>

int main(int argc, char** argv){
    int num_anterior, num_atual, num_temp, posicao;
    printf("Digite a posiçao desejada: \n");
    scanf("%d", &posicao);

    for(num_anterior = 0, num_atual = 1 ; posicao > 0 ; num_temp = num_atual, num_atual = num_atual + num_anterior, num_anterior = num_temp, posicao -= 1 ) printf("%d, ", num_anterior);

    printf("...");

    return 0;

}