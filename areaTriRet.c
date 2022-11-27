#include <stdio.h>
#include <math.h>

float norma_vetor(float vet[], int tam);

int main(int argc, char** argv){
    float xa, ya, xb, yb, xc, yc, area;
    //float altura;
    //float vetorAB[2], vetorAC[2];
    printf("Digite as cordenadas do ponto A: \n");
    scanf("%f %f", &xa, &ya);
    printf("Digite as cordenadas do ponto B: \n");
    scanf("%f %f", &xb, &yb);

    xc = xb;
    yc = ya;

    float vetorAC[] = { xc - xa, yc - ya};
    float vetorCB[] = { xb - xc, yb - yc};

    /*for(int i = 0; i < 2; i++){
        printf("coordenada %d: %f \n",i, vetorAB[i] );
        printf("coordenada %d: %f \n",i, vetorAC[i] );
    } */
    //norma(vetorAB , 2);
    //mult_escalar(vetorAB, vetorAC, 2);

    area = norma_vetor(vetorAC, 2) * norma_vetor(vetorCB, 2) / 2;

    printf("%f", area);




    return 0;
    
}

float norma_vetor(float vet[], int tam){
    float norma, soma_dos_quadrados = 0;


    for(tam = tam - 1; tam >= 0; tam--){
        //printf("%f \n", vet[tam]);
        soma_dos_quadrados = (vet[tam] * vet[tam]) + soma_dos_quadrados;
        //printf("%f \n", soma_dos_quadrados);
    }

    norma = sqrt(soma_dos_quadrados);
    //printf("%f", norma);
    return norma;

}

