#include <stdio.h>

int mdc(int num1, int num2);

int main(int argc, char** argv){
    int num1, num2, maxdc;
    printf("Digite os dois numeros desejados:\n");
    scanf("%d %d", &num1, &num2);
    maxdc = mdc(num1, num2);
    printf("%d", maxdc);

    return 0;

}

int mdc(int num1, int num2){
    if(num2 == 0){
        return num1;
    }
    else{
        return mdc(num2, num1%num2);
    }
}