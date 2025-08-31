#include <stdio.h>
#include <string.h>

void printStruct(char *var1, int var2, float var3);

/*1. Crie uma estrutura chamada "pessoa" com os campos "nome", "idade" e "altura". Em
seguida, crie uma variável do tipo "pessoa" e atribua valores aos seus campos. */
typedef struct{
 char nome[50];
 int idade;
 float altura;
} pessoa;
int main (){

    pessoa p1;
    strcpy(p1.nome, "Joao");
    p1.idade = 18;
    p1.altura = 1.7;

    printStruct(p1.nome, p1.idade, p1.altura);

    return 0;
}

void printStruct(char *var1, int var2, float var3){
    printf("Nome: %s\nIdade: %d\nAltura: %.2f\n", var1, var2, var3);
}