#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*9. Considere uma loja de eletrônicos que vende três tipos de produtos: smartphones, notebooks
e televisores. Cada produto possui as seguintes informações: nome, marca, modelo e preço.
Além disso, cada produto possui informações específicas, descritas a seguir:

• Smartphone: sistema operacional (Android ou iOS) e capacidade de armazenamento (em GB).
• Notebook: tamanho da tela (em polegadas) e quantidade de memória RAM (em GB).
• Televisor: tamanho da tela (em polegadas) e resolução (HD, Full HD, 4K).

a) Crie uma estrutura de dados chamada "Produto" que armazene todas as informações
descritas acima. Utilize as estruturas "enum" e "union" quando necessário. 

b Crie uma função que receba como parâmetro um produto e imprima na tela todas as suas informações,
incluindo as informações específicas de cada tipo de produto. 

c) Crie um programa que
permita ao usuário cadastrar produtos na loja, imprimir na tela os produtos cadastrados e
buscar um produto pelo seu nome.
*/

typedef enum{
    SMARTPHONE, NOTEBOOK, TELEVISOR,
} tipo_produto;

typedef struct{
    char nome[50], marca[10], modelo[10];
    float preco;
} info_produto;

typedef union{
    float tamanho_tela;
    int memoria_ram, memoria_ssd;
    char resolucao[8], so[8];
} info_especifica;

typedef struct{
    tipo_produto tipo;
    info_produto info;
    info_especifica info_espec1, info_espec2;
} produto;

void printProduto(produto p);
void cadastrarProduto(produto **p, int *n);
void exibirProdutos(produto *p, int qtd_produtos);
void buscarProduto(produto *p, char *nome, int qtd_produtos);
void voltarAoMenu();

int main(){
    int qtd_produtos = 0;
    produto *produtos = NULL;
    int menu = 0;
    int encerrar = 0;
    char resposta = 's';

    char busca[20];

    while(encerrar == 0){
        //system("cls || clear");
        printf("\t=====================\n\t\tMENU\n\t=====================\n");
        printf("\t1. Cadastrar produto\n\t2. Buscar produto\n\t3. Listar produtos\n\t4. Encerrar\n");
        printf("\t=====================\n\t=====================\n");
        scanf("%d", &menu);
    switch (menu){
        case 1: 
            do{
            cadastrarProduto(&produtos, &qtd_produtos);
            printf("\ndeseja cadastrar mais produtos?\n");
            scanf(" %c", &resposta);
            }while(resposta == 'S' || resposta == 's');
            voltarAoMenu();
            break;
        case 2:
            printf("digite o nome do produto que deseja buscar:\n");
            getchar();
            fgets(busca, 20, stdin);
            busca[strcspn(busca, "\n")] = '\0';
            buscarProduto(produtos, busca, qtd_produtos);
            voltarAoMenu();
            break;
        case 3:
            exibirProdutos(produtos, qtd_produtos);
            voltarAoMenu();
            break;
        case 4:
            encerrar = 1;
            break;
        default:
            printf("opcao invalida");
        }
    };
            

     free(produtos);
     return 0;
    }

void buscarProduto(produto *p, char *nome, int qtd_produtos){
    int j;
    int i;
    for(i = 0; i < qtd_produtos ; i++){
        if (strcmp(nome, p[i].info.nome) == 0){
            j = i;
            break;
        }
    }
    printProduto(p[i]);
    }

void printProduto(produto p){
    
    printf("\tMarca: %s\tNome: %s\tModelo: %s\tPreco: %.2f\n", p.info.marca, p.info.nome, p.info.modelo, p.info.preco);
    switch (p.tipo){
        case SMARTPHONE:
            printf("Sistema Operacional: %s\tArmazenamento: %d GB\t Categoria: SMARTPHONE\t\n", p.info_espec1.so, p.info_espec2.memoria_ssd);
            break;
        case NOTEBOOK:
            printf("Tamanho da tela: %.2f polegadas\tRAM: %d GB\t Categoria: NOTEBOOK\t\n", p.info_espec1.tamanho_tela, p.info_espec2.memoria_ram);
            break;
        case TELEVISOR:
            printf("Tamanho da tela: %.2f polegadas\tResolucao: %s\t Categoria: TELEVISOR\t\n", p.info_espec1.tamanho_tela, p.info_espec2.resolucao);
            break;
        default:
            printf("Categoria: N/A\t\n");
            break;
    }
}

void cadastrarProduto(produto **p, int *qtd_produtos){
    char categoria[12];
    produto *ptr_produto = (produto *)realloc(*p, *qtd_produtos + 1 * sizeof(produto)); // aloca mais um espaço para o novo produto no array
    if(ptr_produto == NULL){
        printf("memoria nao foi alocada corretamente!");
        free(*p);
        exit(1);
    }

    *p = ptr_produto;
    produto *novo = &((*p)[*qtd_produtos]);

    printf("digite a categoria do produto: \n");
    scanf("%s", categoria);
    if(strcmp(categoria, "smartphone") == 0){
        novo->tipo = SMARTPHONE;
        } else if(strcmp(categoria, "notebook") == 0){
            novo->tipo = NOTEBOOK;
            } else if(strcmp(categoria, "televisor") == 0){
                novo->tipo = TELEVISOR;
                }
    getchar();
    printf("digite o nome do produto: \n");
        fgets(novo->info.nome, 50, stdin);
        novo->info.nome[strcspn(novo->info.nome, "\n")] = '\0'; // tira o \n da string (tava atrapalhando no output)
    printf("digite a marca do produto: \n");
        fgets(novo->info.marca, 10, stdin);
        novo->info.marca[strcspn(novo->info.marca, "\n")] = '\0'; 
    printf("digite o modelo do produto: \n");
        fgets(novo->info.modelo, 10, stdin);
        novo->info.modelo[strcspn(novo->info.modelo, "\n")] = '\0';
    printf("digite o preco do produto: \n");
        scanf(" %f", &novo->info.preco);
        getchar();

    switch(novo->tipo){
        case SMARTPHONE:
            printf("digite o sistema operacional do smartphone: \n");
            fgets(novo->info_espec1.so, 8, stdin);
            novo->info_espec1.so[strcspn(novo->info_espec1.so, "\n")] = '\0';
            printf("digite o armazenamento do smartphone: \n");
            scanf(" %d", &novo->info_espec2.memoria_ssd);
            break;
        case NOTEBOOK:
            printf("digite o tamanho da tela do notebook: \n");
            scanf(" %f", &novo->info_espec1.tamanho_tela);
            printf("digite a quantidade de RAM de do notebook: \n");
            scanf(" %d", &novo->info_espec2.memoria_ram);
            break;
        case TELEVISOR:
            printf("digite o tamanho da tela do televisor: \n");
            scanf(" %f", &novo->info_espec1.tamanho_tela);
            getchar();
            printf("digite a resolucao (HD, Full HD, 4K) do televisor: \n");
            fgets(novo->info_espec2.resolucao, 8, stdin);
            novo->info_espec2.resolucao[strcspn(novo->info_espec2.resolucao, "\n")] = '\0';
            break;
        default:
            break;
    }

     (*qtd_produtos)++;

    printf("=== EXIBINDO PRODUTO CADASTRADO ===\n");
    printProduto(*novo);
    
}

void exibirProdutos(produto *p, int qtd_produtos){
    printf("=================\nTODOS OS PRODUTOS\n=================\n");

    for(int i = 0; i < qtd_produtos; i++){
        printProduto(p[i]);
    }
}

void voltarAoMenu(){
    printf("Pressione Enter para voltar ao menu...");
    getchar(); // para consumir o '\n' pendente, se necessário
    getchar(); // espera o Enter do usuário
}