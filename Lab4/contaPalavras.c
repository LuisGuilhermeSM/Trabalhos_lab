#include <stdio.h>
#include <stdlib.h>

char * inciar_string();
int conta_palavras(char * vet);
int conta_palavras(char * vet);

int main( int argc, char** argv){
    char * frase;
    int quant_palavras;
    printf("Digite a frase desejada:\n");
    frase = inciar_string();
    printf("%s\n", frase);
    quant_palavras = conta_palavras(frase);
    printf("%d", quant_palavras); 

    free(frase);
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


int conta_palavras(char * vet){ // com o ç na palavra não da certo.
    int i = 0, palavras = 0, e_palavra = 0;
    while( *(vet + i) != '\0'){
        if( ( (*(vet + i) <= 122 && *(vet + i) >= 97 ) || ( *(vet + i) <= 90 && *(vet + i) >= 65 ) || (*(vet + i) <= 57 && *(vet + i) >= 48) ) ){
            e_palavra = 1;
            //printf(" e_palavra 1 if: %d \n", e_palavra);
        }
        else if( (e_palavra == 1 && (*(vet + i) == '-')) ){
            e_palavra = 1;
            //printf(" e_palavra 2 if: %d \n", e_palavra);
        }
        else{
            //printf(" e_palavra else: %d \n", e_palavra);
            if( e_palavra == 1){
                palavras += 1;
                e_palavra = 0;
                //printf(" e_palavra if do else: %d \n", e_palavra);
            }
        }

        i += 1;

    }
    if(e_palavra){ // para quando terminar com uma palavra.
            palavras += 1;
            e_palavra = 0;
        }

    return palavras;
}