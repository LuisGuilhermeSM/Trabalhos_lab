#include <stdio.H>

void intervalo(int a, int b);

int main(int arcg, char** argv){
    int a, b;
    printf(" Digite o intervalo desejado em que o primeiro numero seja menor que o segundo: \n");
    scanf("%d %d", &a, &b);

    if(b > a){
        intervalo(a, b);
    };



}

void intervalo(int a, int b){
    for(int i = 0; i <= b - a; i = i + 1 ){
        if (((a + i) % 2) == 1){
            printf("%d", a + i);
            if(i != b - a){
                printf(", ");
            };
    };

    
    };

}