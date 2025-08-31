#include <stdio.h>
#include <string.h>

void printUnion(char *var1, int var2, float var3);

/*12. Crie uma união chamada "tipo_dado" que pode armazenar um número inteiro, um número
de ponto flutuante ou uma string. Em seguida, crie uma variável do tipo "tipo_dado" e
atribua valores a ela. */
typedef union{
 int i;
 float j;
 char str[50];
} tipo_dado;
int main (){
    tipo_dado dados;

    dados.i = 10;
    printUnion(dados.str, dados.i, dados.j);
    dados.j = 10.5;
    printUnion(dados.str, dados.i, dados.j);
    strcpy(dados.str, "union");
    printUnion(dados.str, dados.i, dados.j);
 
    // nota-se que só é possivel atribuir um valor de cada vez para cada variável de union. É interessante quando pensamos em otimizar memória.
}

void printUnion(char *var1, int var2, float var3){
    printf("str: %s\ni: %d\nj: %.2f\n", var1, var2, var3);
}