#include <stdio.h>
#ifdef M_PI
  #undef M_PI
#endif
#define M_PI 3.141592653589793115997963468544185161590576171875

int fat(int num);
double pot(double num, int expoente);

int main(int argc, char** argv){
    int n;
    double x;
    float cos;
    cos = 0;
    printf("Digite um valor n: \n");
    scanf("%d", &n);
    printf("Digite um valor x: \n");
    scanf("%lf", &x);

    for( ; n >= 0 ; n -= 1){
        cos = cos + pot(-1 , n) * pot(x * M_PI, 2 * n) / fat(2*n);
    };

    //printf("cos(%lfpi) = %f ", x, cos);
    printf("%lf", cos);

    return 0;

}


int fat(int num){
    int fatorial;
    fatorial = 1;
    for( ; num > 0; num = num - 1 ){
        fatorial = fatorial * num;
        
    };

    //printf("%d,", fatorial);
    return fatorial;

}

double pot(double num, int expoente){
    double resultado;
    resultado = 1;
    for( ; expoente > 0 ; expoente -= 1 ){
        resultado = resultado * num;

    };

    //printf("%lf,", resultado);
    return resultado;

}