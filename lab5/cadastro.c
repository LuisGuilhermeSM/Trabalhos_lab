#include <stdio.h>
#include <stdlib.h>

typedef
    struct Datas{
        int dia, mes, ano;
    }
Datas;

typedef
    struct Altura{
        int metro, cm;
    }
Altura;

typedef
    struct Cadastro{
        char * nome;
        Datas data;
        Altura altura;
        float peso;
    }
Cadastro;    

char * inciar_string();
Cadastro cadastrar();
int cmt(int x);
void imprimir_cadastro(int num_usuarios, Cadastro *usuarios);

int main(int argc, char** argv){
    int num_usuarios;
    printf("Digite o numero de usuarios que deseja cadastrar:\n");
    scanf("%d%*c", &num_usuarios);
    Cadastro usuarios[num_usuarios];
    //printf("%d", num_usuarios);

    for(int i = 0; i < num_usuarios; i += 1 ){
        //printf("\noi");
        usuarios[i] = cadastrar();
    }
    
    //printf("%d", num_usuarios);
    imprimir_cadastro(num_usuarios, usuarios);
    //printf("%s %d/%d/%d %d.%d %f",usuarios[0].nome, usuarios[0].data.dia, usuarios[0].data.mes, usuarios[0].data.ano, usuarios[0].altura.metro, usuarios[0].altura.cm, usuarios[0].peso);

    return 0;
}

Cadastro cadastrar(){
    Cadastro usuario;

    printf("Digite os dados do usuario: \n");
    usuario.nome = inciar_string();
    scanf("%d/%d/%d", &usuario.data.dia, &usuario.data.mes, &usuario.data.ano);
    //printf("%d/%d/%d", usuario.data.dia, usuario.data.mes, usuario.data.ano);
    //printf("altura:\n");
    scanf("%d.%d", &usuario.altura.metro, &usuario.altura.cm);
    usuario.altura.cm = cmt(usuario.altura.cm);
    //printf("peso:\n");
    scanf("%f%*c", &usuario.peso);
    

    return usuario;
}

void imprimir_cadastro(int num_usuarios, Cadastro *usuarios){
    char strmes[13][4] = {
    "", "JAN", "FEV", "MAR", "ABR", "MAI", "JUN",
    "JUL", "AGO", "SET", "OUT", "NOV", "DEZ"
    };
    
    for(int i = 0; i < num_usuarios; i+= 1){
        printf("%s; %02d%s%04d; %dm.%d; %.1fKg \n",usuarios[i].nome, usuarios[i].data.dia, strmes[usuarios[i].data.mes], usuarios[i].data.ano, usuarios[i].altura.metro, usuarios[i].altura.cm, usuarios[i].peso);
    }
}

char * inciar_string(){
    char str;
    char *string = (char *) malloc(1);
    //printf("%x \n", string);
    int tam = 0;
    
    while(1){
        str = getchar();
        //printf("%c", str);
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

int cmt(int x) {
    if(x < 10) return x*10;
    if(x > 99) return cmt(x/10);
    return x;
}