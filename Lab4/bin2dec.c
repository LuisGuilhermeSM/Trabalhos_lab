#include <stdio.h>
#include <stdlib.h>

char * inciar_string();
char * inverter_str(char * str, int tam);
int len(char * vet);
unsigned long long int  bin_deci(char * bin);


int main(int argc, char** argv){
    char * num_bin, * num_bin_invertido;
    printf("Digite o numero binario que deseja converter:\n");
    num_bin = inciar_string();
    //printf("%s\n", num_bin);
    num_bin_invertido = inverter_str(num_bin, len(num_bin) );
    //printf("%d", len(num_bin));
    //printf("\n%s", num_bin_invertido );
    printf("%llu",bin_deci(num_bin_invertido) );



    free(num_bin);
    free(num_bin_invertido);
}

char * inciar_string(){
    char str;
    char *string = (char *) malloc(1);
    int tam = 0;
    
    while(1){
        str = getchar();
        if( str != '\n' ){
            if(str == '1' || str == '0' ){
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

unsigned long long int  bin_deci(char * bin){
    unsigned long long int deci = 0, mult = 1;
    int tam = 0;
    while(bin[tam] != '\0'){
        if(bin[tam] == '1'){
            deci = deci + mult;
            mult = mult * 2;
            tam += 1;
        }
        else{
            mult = mult * 2;
            tam += 1;
        }
    }

    return deci;
}
