#include <stdio.h>
#include <stdlib.h>

char * inciar_string();
int len(char * vet);
char * inverter_str(char * str, int tam);
char * upper(char * str, int tam);
int comparar(char * vet1, char * vet2, int tam);

int main(int argc, char** argv){
    char * frase_inicial, * frase_final;
    int igual;
    printf("Digite a frase desejada:\n");
    frase_inicial = inciar_string();
    frase_inicial = upper(frase_inicial, len(frase_inicial));
    frase_final = inverter_str(frase_inicial, len(frase_inicial));
    //printf("Frase inicial: %s \n", frase_inicial);
    igual = comparar(frase_inicial, frase_final, len(frase_inicial));
    if(igual){
        printf("Palindrono: Verdadeiro");
    }
    else{
        printf("Palindrono: Falso");
    }


    free(frase_inicial);
    free(frase_final);
    
    return 0;

}


char * inciar_string(){ // alterada para já iniciar apenas com letras
    char str;
    char *string = (char *) malloc(1);
    int tam = 0;
    
    while(1){
        str = getchar();
        if( str != '\n' ){
            if( (str <= 122 && str >= 97 ) || ( str <= 90 && str >= 65 )){
                string = (char *) realloc(string, (tam+ 1) * sizeof(char) );
                string[tam] = str;
                tam += 1;
            }
        }
        else{
            string = (char *) realloc(string, (tam + 1) * sizeof(char) );
            string[tam] = '\0';
            tam += 1;
            break;

        }
        
    }

    return string;
}

int len(char * vet){
    int i = 0;
    while( *(vet + i) != '\0'){
        i += 1;

    }

    return i;
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

char * upper(char * str, int tam){
    for(int i = 0; i < tam; i++){
        if( (*(str + i) >= 97) && (*(str + i) <= 122) ){
            str[i] = *(str + i) + 'A' - 'a';  
        }
    }

    return str;
}

int comparar(char * vet1, char * vet2, int tam){
    int igualdade = 1;
    for(int i = 0; i < tam ; i++){
        if(vet1[i] != vet2[i]){
            igualdade = 0;
        }
    }    

    return igualdade;
}
