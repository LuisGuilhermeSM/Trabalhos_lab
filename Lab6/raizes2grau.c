#include <stdio.h>
#include <math.h>

int raizes(float a, float b, float c, float * x1, float * x2);

int main(int argc, char** argv){
    float a, b, c, x1, x2;
    //printf("%x\n", x1);
    //printf("%x\n", x2);
    int num_raiz;
    printf("Digite os termos a,b e c da equacao de segundo grau:\n");
    scanf("%f %f %f*%c", &a, &b, &c);
    num_raiz = raizes(a, b, c, &x1, &x2);
    //printf("%d %f %f", num_raiz, x1, x2);
    if(num_raiz > 1){
        printf("%d %f %f", num_raiz, x1, x2);
    }
    else if(num_raiz == 1){
        printf("%d %f", num_raiz, x1);
    }
    else{
        printf("%d", num_raiz);
    }
    
    //printf("%f", *x2);

    //printf("%d %f %f", num_raiz, x1[0], x2[0]);

    return 0;
}

int raizes(float a, float b, float c, float * x1, float * x2){
    float delta;
    delta = (pow(b, 2)) - (4 * a * c);
    //printf("%llf", delta);
    //printf("oi");

    if(a == 0 || delta < 0){
        //printf("oi");
        return 0;
    }
    else if(delta == 0){
        *x1 = -b/(2*a);
        //printf("%f\n", *x1);
        return 1;
    }
    else if (delta > 0){
        *x1 = (-b + sqrt(delta) )/(2*a);
        *x2 = (-b - sqrt(delta) )/(2*a);
        if(*x1 > *x2){
            float aux = *x1;
            *x1 = *x2;
            *x2 = aux;
        }
        return 2;
    }

}
