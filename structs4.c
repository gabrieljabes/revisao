#include <stdio.h>
#include <string.h>

/* 4. Crie um enum chamado "tipo_animais" com os valores "CACHORRO", "GATO" e
"PASSARO". Em seguida, crie uma estrutura chamada "animal" com os campos "tipo" (do
tipo "tipo_animais") e "nome" (do tipo string). Em seguida, crie uma variável do tipo
"animal" e atribua valores a ela.*/

typedef enum{
    CACHORRO, // 0
    GATO, // 1
    PASSARO, // 2
} tipo_animais;

typedef struct{
    tipo_animais tipo;
    char nome[50];
} animal;

void imprimirAnimal(animal a){
    switch (a.tipo){
    case CACHORRO: 
        printf("Tipo: cachorro\n");
        break;
    case PASSARO: 
        printf("Tipo: passaro\n");
        break;
    case GATO: 
        printf("Tipo: gato\n");
        break;
    default:
    break;
    }
    printf("Nome: %s\n", a.nome);
}
int main(){
    animal a1;
    a1.tipo = CACHORRO;
    strcpy(a1.nome, "Yumi");

    imprimirAnimal(a1);

    return 0;
}