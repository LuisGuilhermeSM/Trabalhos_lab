#include <stdio.h>
#include <stdlib.h>

char * inciar_string();
int encontrar(char *str1, char *str2);
void imprimir_onde_encontrou(int posi, char *str1, char *str2);
int len(char * vet);

int main(int argc, char** argv){
    char * str1, * str2;
    int encontrou;
    printf("Digite a primeira frase:\n");
    str1 = inciar_string();
    printf("Digite a segunda frase:\n");
    str2 = inciar_string();
    encontrou = encontrar(str1, str2);
    //printf("%d", encontrou);
    if(encontrou == -1){
        printf("mensagem que nao esta contida");
    }
    else{
        imprimir_onde_encontrou(encontrou, str1, str2);
    }
    free(str1);
    free(str2);
    return 0;
}

char * inciar_string(){ // Lembrar de dar free depois e tambem tomar cuidado com o buffer se ocorrer um scanf antes da chamada da função.
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

int encontrar(char *str1, char *str2){ //Ve se a string1 existe na string2 e caso sim retorna a posicao de str1 em str2q
    int tam1, tam2, i = 0, encontrou = 0;
    tam1 = len(str1);
    tam2 = len(str2);

    for(i; i < tam2; i++ ){
        //printf("%d\n", i);
        if(encontrou){
            return (i - 1); 
        }
        else if( (tam2 - i)  < tam1){
            return -1;
        }
        else{
            for(int j = 0; j < tam1; j++){
                if(str1[j] != str2[i + j]){
                    encontrou = 0;
                    break;
                }
                else{
                    encontrou = 1;
                }
            }
        }
    }

    return i;

}

int len(char * vet){
    int i = 0;
    while( *(vet + i) != '\0'){
        i += 1;

    }

    return i;
}

void imprimir_onde_encontrou(int posi, char *str1, char *str2){
    int tam1, tam2;
    tam1 = len(str1);
    tam2 = len(str2);
    for(int j = 0; j < tam2; j++ ){
        if(j == posi){
            printf("*");
        }
        printf("%c", str2[j]);
        if(j == (posi + tam1 - 1)){
            printf("*");
        }
    }

}