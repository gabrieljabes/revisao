#include <stdio.h>
#include <string.h>

/*Crie um enum chamado "tipo_figura" com os valores "CIRCULO", "QUADRADO" e
"RETANGULO". Em seguida, crie uma estrutura chamada "figura" com os campos "tipo"
(do tipo "tipo_figura") e "dados" (do tipo "void *", que pode ser um ponteiro para uma
estrutura "circulo", "quadrado" ou "retangulo"). Em seguida, crie uma variável do tipo
"figura" e atribua valores a ela.*/

typedef enum{
    CIRCULO,
    QUADRADO,
    RETANGULO
} tipo_figura;

typedef struct{
    tipo_figura tipo;
    void *dados;
} figura;

typedef struct {
    float raio;
} circulo;

typedef struct {
    float lado;
} quadrado;

typedef struct {
    float lado_a, lado_b;
} retangulo;


int main(){
quadrado dados_quadrado;
circulo dados_circulo;
retangulo dados_retangulo;
figura minha_figura;

minha_figura.tipo = CIRCULO;
minha_figura.dados = &dados_circulo;
dados_circulo.raio = 5.0;

if(minha_figura.tipo == CIRCULO){
    circulo *ptr_circulo_dados = (circulo *)minha_figura.dados;
    printf("A figura eh um CIRCULO.\n");
    printf("De raio: %.2f\n", ptr_circulo_dados->raio);
}

    return 0;
}