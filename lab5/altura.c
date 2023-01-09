#include <stdio.h>

typedef
    struct Comprimento{
        int metro, cent;
    } 
Comprimento;

int cm(int x);

int main(int argc, char** argv){
    Comprimento altura;
    printf("Digite a altura em metros: ");
    scanf("%d.%d", &altura.metro, &altura.cent);
    altura.cent = cm(altura.cent);
    printf("Altura %dm%02d", altura.metro, altura.cent);

    return 0;

}

int cm(int x) {
if(x < 10) return x*10;
if(x > 99) return cm(x/10);
return x;
}