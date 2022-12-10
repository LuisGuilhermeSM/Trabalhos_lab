#include <stdio.h>
#include <stdlib.h>

char * inciar_string();
int conta_vogais(char * str);

int main(int argc, char** argv){
    char * frase;
    printf("Digite a frase desejada: \n");;
    frase = inciar_string();
    printf("%d",conta_vogais(frase));
    
    
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


int conta_vogais(char * str){
    int cont = 0, tam = 0;
    while( *(str + tam) != '\0'){
        
        if( ((*(str + tam) == 'a') || (*(str + tam) == 'e') || (*(str + tam) == 'i') || (*(str + tam) == 'o') || (*(str + tam) == 'u')) ){
            cont += 1;
        } 
        else if( (*(str + tam) == 'A') || (*(str + tam) == 'E') || (*(str + tam) == 'I') || (*(str + tam) == 'O') || (*(str + tam) == 'U') ){
            cont += 1;
        }
        
        tam += 1;

    }
    
    return cont;

}
