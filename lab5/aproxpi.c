#include <stdio.h>

double serie(int indice);
//double pote(double num, int expoente);
float pot_menos_um(int expoente);
double serie_dois(int indice);

int main(int argc, char** argv){
    int i;
    printf("Digite o limite da serie:\n");
    scanf("%d", &i);
    printf("%lf", serie(i) );

    return 0;

}

double serie(int indice){ // Por recursão o caso 233333 nao funcionou o maximo foi ate o indice 32571.
    if(indice == 0){
        return 4;
    }
    else{
        return (4 * pot_menos_um(indice))/( (2 * indice) + 1) + serie(indice - 1);
    }
}

float pot_menos_um(int expoente){ //Potencia apenas do menos um
    if((expoente % 2) == 1){
        return (-1);
    }
    else{
        return 1;
    }
}


/*double pote(double num, int expoente){ Funçao para potencia geral de expoente > 0
    double resultado;
    resultado = 1;
    for( ; expoente > 0 ; expoente -= 1 ){
        resultado = resultado * num;

    };

    //printf("%lf,", resultado);
    return resultado;

}*/ 

double serie_dois(int indice){ // Assim o caso 233333 funcionou.
    double res = 0;
    for( ; indice >= 0; indice -= 1){
        if(indice == 0){
            res = res + 4;
        }
        else{
            res = res + (4 * pot_menos_um(indice))/( (2 * indice) + 1);
        }
    }

    return res;
}
