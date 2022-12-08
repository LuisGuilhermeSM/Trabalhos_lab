#include <stdio.h>
#define N 5

void get_str( char * str, int tam_str);

int main(int argc ,char** argv){
    char texto[N];
    get_str(texto, N);

    return 0;

}

void get_str(char * str, int tam_str){
    int i;
    char c;
    printf("Digite algo: \n");
    for(i = 0; i < tam_str; i++){
        c = getchar();
        if(c != '\n'){
            str[i] = c;
        }
        else{
            str[i] = '\0';
            break;
        }
        printf("%c", c);
    }
}