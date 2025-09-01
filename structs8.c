#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*  Crie uma estrutura chamada "tempo" com os campos "hora", "minuto" e "segundo". Em
seguida, crie uma função chamada "converte_segundos" que recebe uma variável do tipo
"tempo" e retorna a quantidade de segundos correspondente a esse tempo. */

typedef struct{
int hora, minuto, segundo;
} tempo;

int converte_segundos(tempo val){
    return val.hora*3600 + val.minuto*60 + val.segundo;
}

int main(){
    tempo t;
    t.hora = 5;
    t.minuto = 23;
    t.segundo = 43;

    printf("horas: %d\tminutos: %d\t segundos: %d\n", t.hora, t.minuto, t.segundo);
    printf("convertido em segundos: %d\n", converte_segundos(t));
    
    return 0;
}