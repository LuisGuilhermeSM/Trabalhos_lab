#include <stdio.h>

int main( int argc, char** argv){
    float peso, altura, imc;
    printf("Digite seu peso e sua altura: \n");
    scanf("%f  %f", &peso, &altura);
    imc = peso/(altura * altura);
    

    if(imc < 16){
        printf("%f Perigo de vida", imc);
    }
    else if (imc < 17){
        printf("%f Muito abaixo do peso", imc);
    }
    else if (imc < 18.5){
        printf("%f Abaixo do peso", imc);
    }
    else if (imc < 25){
        printf("%f Peso normal", imc);
    }
    else if (imc < 30){
        printf("%f Acima do peso", imc);
    }
    else if (imc < 35){
        printf("%f Obesidade grau I", imc);
    }
    else if (imc < 40){
        printf("%f Obesidade grau II", imc);
    }
    else{
        printf("%f Obesidade grau III", imc);
    }

    return 0;
}