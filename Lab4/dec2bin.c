#include <stdio.h>
#include <stdlib.h>

char * bin(unsigned long long deci);
char * inverter_str(char * str, int tam);
int len(char * vet);

int main(int argc, char** argv){
    unsigned long long int num;
    char * num_binario;
    printf("Digite o numero que deseja converter para binario:\n");
    scanf("%llu", &num);
    num_binario = bin(num);
    printf("%s", inverter_str(num_binario , len(num_binario)));

    free(num_binario);

    //printf("\n %d", (unsigned long long)4 / (unsigned long long)2 );
    //printf("i = %llu \ni<< = %llu", num, num<<1);

    return 0;

}

char * bin(unsigned long long deci){
    char * bina = (char *) malloc(1);
    int tam = 0;

    for(deci ; deci > 0 ; deci = deci / 2){
        if(deci % 2 == 1){
            bina = (char *) realloc(bina, (tam + 1) * sizeof(char) );
            //printf("%llu", deci);
            bina[tam] = '1';
            tam += 1;
        }
        else{
            bina = (char *) realloc(bina, (tam + 1) * sizeof(char) );
            //printf("%llu", deci);
            bina[tam] = '0';
            tam += 1;
        }

    }
    
    bina = (char *) realloc(bina, (tam + 1) * sizeof(char) );
    bina[tam] = '\0';

    return bina;

}

char * inverter_str(char * str, int tam){
    int i = 0;
    char * str_novo = (char *) malloc( (tam + 1) * sizeof(char));
    for(i; tam > 0; tam--){
        str_novo[i] = *(str + tam - 1);  
        i += 1;
    }
    //printf("%d\n", i);
    
    str_novo[i] = '\0';
    return str_novo;

}

int len(char * vet){
    int i = 0;
    while( *(vet + i) != '\0'){
        i += 1;

    }

    return i;
}