#include <stdio.h>
#include <string.h>

/*5. Crie uma estrutura chamada "aluno" com os campos "nome", "idade" e "notas" (um array
com as notas do aluno). Em seguida, crie uma função chamada "calcula_media" que recebe
uma variável do tipo "aluno" e retorna a média das notas.*/

typedef struct{
    char nome[50];
    int idade;
    float notas[3];
}aluno;

float calcula_media(aluno a);

int main (){
    aluno g;
    strcpy(g.nome, "Gabriel");
    g.idade = 18;
    g.notas[0] = 7, g.notas[1] = 4.6, g.notas[2] = 10;

    printf("a media do aluno %s eh: %.2f\n", g.nome, calcula_media(g));
    return 0;
}

float calcula_media(aluno a){
    float media_notas;
    for(int i = 0; i < 3; i++){
        media_notas+=a.notas[i];
    }
    return media_notas/=3;
}