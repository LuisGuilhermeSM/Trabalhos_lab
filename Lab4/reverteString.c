#include <stdio.h>
#include <stdlib.h>

char * inciar_string();
int len(char * vet);
char * inverter_str(char * str, int tam);
char * upper(char * str, int tam);

int main(int argc, char** argv){
    char * frase, * frase_invertida, * frase_final;
    printf("Escreva a frase desejada:\n");
    frase = inciar_string();
    frase_invertida = inverter_str(frase, len(frase));
    frase_final = upper(frase_invertida, len(frase_invertida));
    //printf("Frase invertida:\n%s", frase_invertida);
    printf("%s", frase_final);
    //printf("\n %x , %x", frase_invertida, frase_final);

    free(frase);
    free(frase_invertida);
    //printf("\n %x , %x", frase_invertida, frase_final);
    //printf("\n %s , %s", frase_invertida, frase_final);
    free(frase_final);

    return 0;
}


char * inciar_string(){
    char str;
    char *string = (char *) malloc(1);
    int tam = 0;
    
    while(1){
        str = getchar();
        if( str != '\n' ){
            string = (char *) realloc(string, (tam+ 1) * sizeof(char) );
            string[tam] = str;
            tam += 1;
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