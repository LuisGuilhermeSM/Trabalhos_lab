#include <stdio.h>

typedef
    struct Razao{
        int numerador, denominador;
    }
Razao;

//void simplificacao(int *numerador, int *denominador);
int mdc(int num1, int num2);
Razao simplificacao(Razao num);
Razao soma(Razao num1, Razao num2);
Razao sub(Razao num1, Razao num2);
Razao mult(Razao num1, Razao num2);
Razao div(Razao num1, Razao num2);

int main(int argc, char** argv){
    Razao racional1, racional2, adicao, subt, multi, divi;
    printf("Digite o primeiro numero raciona no formato numerador/denominador:\n");
    scanf("%d/%d", &racional1.numerador, &racional1.denominador);
    printf("Digite o segundo numero:\n");
    scanf("%d/%d", &racional2.numerador, &racional2.denominador);
    
    //simplificacao(racional1.numerador, &racional1.denominador);
    //simplificacao(racional2.numerador, &racional2.denominador);
    
    racional1 = simplificacao(racional1);
    racional2 = simplificacao(racional2);
    printf("%d/%d ", racional1.numerador, racional1.denominador);
    printf("%d/%d ", racional2.numerador, racional2.denominador);
    
    adicao = soma(racional1, racional2);
    printf("%d/%d ", adicao.numerador, adicao.denominador);

    subt = sub(racional1, racional2);
    printf("%d/%d ", subt.numerador, subt.denominador);

    multi = mult(racional1, racional2);
    printf("%d/%d ", multi.numerador, multi.denominador);

    divi = div(racional1, racional2);
    printf("%d/%d ", divi.numerador, divi.denominador);


    return 0;
}

/*void simplificacao(int *numerador, int *denominador){
    int maxdc;
    maxdc = mdc(*numerador, *denominador);
    *numerador = *numerador/maxdc;
    *denominador = *denominador/maxdc;

    if(*denominador < 0){
        *numerador = 0 - *numerador;
        *denominador = 0 - *denominador;
    }
    if(*numerador == 0){
        *denominador = 1;
    }


}*/

int mdc(int num1, int num2){
    if(num2 == 0){
        return num1;
    }
    else{
        return mdc(num2, num1%num2);
    }
}


Razao simplificacao(Razao num){
    int maxdc;
    maxdc = mdc(num.numerador, num.denominador);
    num.numerador = num.numerador/maxdc;
    num.denominador = num.denominador/maxdc;

    if(num.denominador < 0){
        num.denominador = 0 - num.denominador;
        num.numerador = 0 - num.numerador;
    }
    if(num.numerador == 0){
        num.denominador = 1;
    }

    return num;

}

Razao soma(Razao num1, Razao num2){
    Razao adicao;
    adicao.numerador = num1.numerador * num2.denominador + num2.numerador * num1.denominador;
    adicao.denominador = num1.denominador * num2.denominador;
    adicao = simplificacao(adicao);

    return adicao; 
}

Razao sub(Razao num1, Razao num2){
    Razao res;
    res.numerador = num1.numerador * num2.denominador - num2.numerador * num1.denominador;
    res.denominador = num1.denominador * num2.denominador;
    res = simplificacao(res);

    return res; 
}

Razao mult(Razao num1, Razao num2){
    Razao res;
    res.numerador = num1.numerador * num2.numerador;
    res.denominador = num1.denominador * num2.denominador;
    res = simplificacao(res);

    return res;
}

Razao div(Razao num1, Razao num2){
    Razao res;
    res.numerador = num1.numerador * num2.denominador;
    res.denominador = num1.denominador * num2.numerador;
    res = simplificacao(res);

    return res;
}