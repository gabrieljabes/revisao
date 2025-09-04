#include <stdio.h>
#include <string.h>

/* Considere o seguinte problema: uma empresa possui diversos funcionários que podem ser
de diferentes níveis (júnior, pleno ou sênior) e ter diferentes tipos de contrato (CLT ou PJ).
Cada funcionário é identificado por um código e possui um salário base.
Defina uma enumeração chamada "Nivel" com os valores JUNIOR, PLENO e SENIOR.
Defina uma estrutura chamada "CLT" contendo os campos: salário bruto, vale-refeição e
vale-transporte.
Defina uma estrutura chamada "PJ" contendo os campos: valor por hora trabalhada, número
de horas trabalhadas e valor do benefício.
Defina uma union chamada "Contrato" que pode armazenar um funcionário do tipo "CLT"
ou "PJ".
Defina uma estrutura chamada "Funcionario" contendo os campos: código, nome, nível,
contrato e salário líquido. O campo "salário líquido" deve ser calculado a partir do salário
base, descontando os impostos(20%) e adicionando eventuais benefícios.
Escreva uma função em C que receba como entrada um array de "Funcionarios" e o número
total de funcionários, e retorne o salário médio líquido da empresa.

*/

typedef enum{
    JUNIOR,
    PLENO,
    SENIOR
} nivel;

typedef struct{
    float salario_bruto;
    float vale_comida;
    float vale_transp;
} clt;

typedef struct{
    float valor_hora;
    int horas_trabalho;
    float valor_beneficio;
} pj;

typedef union{
    clt CLT;
    pj PJ;
} contrato;

typedef struct{
    int codigo_id;
    char nome[50];
    nivel nivel;
    contrato contrato;
    float salario_liquido;
} funcionario;

float salarioLiquido(funcionario *empregados);
void salarioMedioEmpresa(funcionario *empregados, int qtd_empregados);

int main(){

    funcionario empregados[10];



    return 0;
}

void salarioMedioEmpresa(funcionario *empregados, int qtd_empregados){
    float salario_total = 0;
    for(int i = 0; i < qtd_empregados; i++){
        salario_total+=empregados[i].salario_liquido;
    }
    salario_total /= qtd_empregados;
}

float salarioLiquido(funcionario *empregados){
    if(empregados->contrato.CLT.salario_bruto == -1){}
}


   


}