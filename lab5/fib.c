#include <stdio.h>

int fib(int ind);

int main(int argc, char** argv){
    int ind;
    printf("Digite o indice do termo que deseja da sequencia de fibonicci:\n");
    scanf("%d", &ind);
    printf("O elemento desse indice e:\n%d", fib(ind));

    return 0;

}

int fib(int ind){
    if(ind == 0){
        return 0;
    }
    else if(ind == 1 || ind == 2){
        return 1;
    }
    else{
        return fib(ind - 1) + fib(ind - 2);
    }
}