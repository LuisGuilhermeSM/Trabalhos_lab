#include <stdio.h>

typedef
    struct Datas{
        int dia, mes, ano;
    }
Datas;

int dois_digitos(int num);

int main(int argc, char** argv){
     char strmes[13][4] = {
    "", "JAN", "FEV", "MAR", "ABR", "MAI", "JUN",
    "JUL", "AGO", "SET", "OUT", "NOV", "DEZ"
    };
    Datas data;
    printf("Digite a data no formato D/M/YYYY ex. (3/2/2003): \n");
    scanf("%d/%d/%d", &data.dia, &data.mes, &data.ano);
    printf("%02d.%02d.%04d ", data.dia, data.mes, data.ano);
    printf("%02d-%02d-%04d ", data.dia, data.mes, data.ano);
    printf("%02d/%02d/%02d ", data.dia, data.mes, dois_digitos(data.ano));
    printf("%02d%s%04d", data.dia, strmes[data.mes], data.ano);

    return 0;
}

int dois_digitos(int num){
    if(num > 99){
        return dois_digitos(num%10);
    }
    else{
        return num;
    }
}