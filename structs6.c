#include <stdio.h>
#include <string.h>

/*6. Crie uma união chamada "tipo_pessoa" que pode armazenar uma variável do tipo "pessoa"
(da questão 1) ou uma variável do tipo "animal" (da questão 6). Em seguida, crie uma
variável do tipo "tipo_pessoa" e atribua valores a ela.*/


typedef enum{
    CACHORRO, // 0
    GATO, // 1
    PASSARO, // 2
} tipo_animais;

typedef struct{
    tipo_animais tipo;
    char nome[50];
} animal;

typedef struct{
 char nome[50];
 int idade;
 float altura;
} pessoa;

typedef union{
    pessoa individuo;
    animal silvestre;
} tipo_entidade;

int main(){
    char str[10];
    tipo_entidade e1;

    printf("pessoa ou animal\n");
    scanf("%s", str);

    if(strcmp(str, "animal") == 0){
        strcpy(e1.silvestre.nome, "yumi");
        e1.silvestre.tipo = CACHORRO;
    } else if(strcmp(str, "pessoa") == 0){
        strcpy(e1.individuo.nome, "gabriel");
        e1.individuo.idade = 17;
        e1.individuo.altura = 1.7;
    }

    printf("nome: %s\naltura: %.2f\nidade: %d\n", e1.individuo.nome, e1.individuo.altura, e1.individuo.idade);
    printf("nome: %s\ntipo: %d\n", e1.silvestre.nome, e1.silvestre.tipo);
    return 0;
}