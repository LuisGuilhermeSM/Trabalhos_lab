#include <stdio.h>

void iniciar_vetor(int * vetor, int tam);
int quant_neg(int * vetor, int tam);
void vetor_resposta(int * vetor_analisado, int tam_v_analisado, int * vetor_res);
void printar_vetor(int * vetor, int tam);


int main(int argc, char** argv){
    int n, quant_de_neg;
    printf("Digite o numero de elementos do vetor: \n");
    scanf("%d", &n);
    int vetor[n]; // so funciona no c99
    iniciar_vetor(vetor, n);
    quant_de_neg = quant_neg(vetor, n);
    //printf("qunat_n %d \n", quant_de_neg );
    int vetor_r[n - quant_de_neg];

    if(quant_de_neg == n){
        printf("vazio");
    }
    else{
        vetor_resposta(vetor, n, vetor_r);
        printar_vetor(vetor_r, n - quant_de_neg);
    }
    

    return 0;

}

void iniciar_vetor(int * vetor, int tam){
    printf("Informe os elementos do vetor: \n");
    for(int i = 0; i < tam; i++ ){
        scanf("%d", vetor + i); 
    }

}

int quant_neg(int * vetor, int tam){
    int quant = 0;
    for(int i = 0; i < tam; i++ ){
        if( *(vetor + i) < 0){
            quant += 1;
        }

    }

    return quant;
}

void vetor_resposta(int * vetor_analisado, int tam_v_analisado, int * vetor_res){
    int posicao_r = 0;
    for(int i = 0; i < tam_v_analisado; i++ ){
        if( *(vetor_analisado + i) >= 0){
            vetor_res[posicao_r] = *(vetor_analisado + i);
            posicao_r += 1;
        }


    }
}

void printar_vetor(int * vetor, int tam){
    printf("%d", *(vetor));
    for(int i = 1; i < tam; i++ ){
        printf(", %d", *(vetor + i));
    }

}