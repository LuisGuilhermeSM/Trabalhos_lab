#include <stdio.h>
#include <math.h>

int main(int argc, char** argv){
    float xa, ya, xb, yb;
    double de;
    printf("Digite a primeira cordenada A: \n");
    scanf("%f %f", &xa, &ya);
    printf("Digite a segunda cordenada b: \n");
    scanf("%f %f", &xb, &yb);

    de = sqrt((xa - xb) * (xa - xb) + (ya - yb) * (ya - yb)  );

    printf("de = %f ", de);

    return 0;

}