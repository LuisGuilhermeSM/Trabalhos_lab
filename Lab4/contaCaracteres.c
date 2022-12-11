#include <stdio.h>
#include <stdlib.h>

char * inciar_string();
int len(char * vet);
int * contar(char * vet);

int main(int argc, char** argv){
    char * frase;
    int * caracteres;
    printf("Digite a frase desejada: \n");
    frase = inciar_string();
    caracteres = contar(frase);
    //printf("%s ", frase);
    printf("letras: %d digitos: %d outros: %d", *(caracteres + 0), *(caracteres + 1), *(caracteres + 2) );

    free(frase);
    free(caracteres);

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

int * contar(char * vet){
    int i = 0; 
    int * lista_caracteres = (int *) calloc(3, sizeof(int));
    //printf(" %d %d %d", lista_caracteres[0], lista_caracteres[1], lista_caracteres[2]);
    while( *(vet + i) != '\0'){
        if( (( *(vet + i) <= 122 && *(vet + i) >= 97 ) || ( *(vet + i) <= 90 && *(vet + i) >= 65 )) ){
            lista_caracteres[0] += 1;
        }
        else if (*(vet + i) <= 57 && *(vet + i) >= 48){
            lista_caracteres[1] += 1;
        }
        else{
            lista_caracteres[2] += 1;
        }
        i += 1;

    }

    return lista_caracteres;
}