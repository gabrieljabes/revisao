#include <stdio.h>
#include <string.h>

typedef enum{DOMINGO, SEGUNDA, TERCA, QUARTA, QUINTA, SEXTA, SABADO} dia_semana;

int main(){
    dia_semana dia = TERCA;

    printf("%d", dia);

    //enum enumera a partir de 0 todas as constantes que forem digitadas.
    return 0;
}