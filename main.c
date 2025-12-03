#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
#include <stdbool.h>
#define TAMANHO_ACERVO 20

// Definição da Estrutura Livro 
struct Livro{
    int codigo;
    char titulo[50];
    char autor[30];
    char area[30];
    int ano;
    char editora[30];
};

// Variáveis globais  
int quantidadeLivros = 0; 
int pesquisa_Codigo = 0; 


// ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// CADASTRAR LIVROS 
void cadastrarLivros(struct Livro acervo[], int tamanho){
    printf("===== CADASTRO DE LIVROS ===== \n");
    
    int qtdParaCadastrar; // Variável para a quantidade de livros que o usuário quer cadastrar.

    // usuario digita que quer cadastrar 5 livros, tamanho é 20 e a quantidadeLivros é 5 que o usuario digitou
    printf("Quantos livros deseja cadastrar? (Máx. %d disponíveis)\n", tamanho - quantidadeLivros); // 20 -5 = 15 livros restantes
    scanf("%d", &qtdParaCadastrar);

    // Garante que o programa ignore qualquer lixo que tenha sobrado na entrada
    while (getchar() != '\n'); 

    // O início do cadastro será na posição onde o acervo parou.
    int inicio = quantidadeLivros;

    if (qtdParaCadastrar < 1 || (inicio + qtdParaCadastrar) > tamanho) {
        printf("--------------------------------- \n");
        printf("Valor inválido ou acervo cheio! Tente novamente.\n");
        printf("--------------------------------- \n");
        return; 
    }
    
    // loop começa onde o acervo parou (inicio) e vai até o total desejado.
    for (int i = inicio; i < inicio + qtdParaCadastrar; i++){ 
        printf("-------------------------------------------------------------------------\n");
        
        printf("Código do livro %d : ",i+1);
        scanf("%d", &acervo[i].codigo);
        while (getchar() != '\n'); // Limpar após ler o inteiro

        // scanf(" %[^\n]") permite ler strings com espaços.
        printf("Título do livro %d : ",i+1);
        printf("(Sem limite de espaços):\n");
        scanf(" %[^\n]", acervo[i].titulo);

        printf("Autor(a) do livro %d : ",i+1);
        scanf(" %[^\n]", acervo[i].autor);

        printf("Área do livro %d: ",i+1);
        scanf(" %[^\n]", acervo[i].area);

        printf("Ano do livro %d: ",i+1);
        scanf("%d", &acervo[i].ano);
        while (getchar() != '\n'); // Limpar após ler o inteiro

        printf("Editora do livro %d:",i+1);
        scanf(" %[^\n]", acervo[i].editora);
        
        // Atualiza a variável global/local do acervo para o novo total
        quantidadeLivros++; 
    }
    printf("\n%d livro(s) cadastrado(s)! Total: %d.\n", qtdParaCadastrar, quantidadeLivros);
};
// ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------


// ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// IMPRESSÃO DE LIVROS
void imprimirLivros(struct Livro acervo[], int tamanho){
    if (tamanho == 0){
        printf("--------------------------------- \n");
        printf("Nenhum livro cadastrado ainda.\n");
        printf("--------------------------------- \n");
        return;
    }

    printf("===== LIVROS IMPRESSOS (%d) ===== \n", tamanho);

    for (int i = 0; i < tamanho; i++){ // Percorre apenas o tamanho 
        printf("\n== LIVRO %d == \n", i + 1);
        printf("Código: %d\n", acervo[i].codigo);
        printf("Título: %s\n", acervo[i].titulo);
        printf("Autor: %s\n", acervo[i].autor);
        printf("Área: %s\n", acervo[i].area);
        printf("Ano: %d\n", acervo[i].ano);
        printf("Editora: %s\n", acervo[i].editora);
        printf("------------------------------------- \n");
    }
};
// ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------


// ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------    
// PESQUISA DE LIVROS
void pesquisarLivro(struct Livro acervo[], int tamanho, int codigoBusca){ 
    
    printf("Para fazer a pesquisa de um livro, digite o CÓDIGO do livro:\n");
    scanf("%d",&codigoBusca);// numeros inteiros na linguagem C vão até 9 digitos
    while (getchar() != '\n'); // Limpar após ler o inteiro

    if (tamanho == 0){
        printf("--------------------------------- \n");
        printf("Nenhum livro cadastrado ainda para pesquisar.\n");
        printf("--------------------------------- \n");
        return;
    }
    
    int encontrado = false;
    int i = 0;
    
    while(i < tamanho){
        if (acervo[i].codigo == codigoBusca){ // eu comparando o código informado com o código de cada livro do acervo
            printf("-------------------------------------\n");
            printf("Livro ENCONTRADO! \n");
            printf("-------------------------------------\n");
            printf("\n== LIVRO == \n");
            printf("Código: %d\n", acervo[i].codigo);
            printf("Título: %s\n", acervo[i].titulo);
            printf("Autor: %s\n", acervo[i].autor);
            printf("Área: %s\n", acervo[i].area);
            printf("Ano: %d\n", acervo[i].ano);
            printf("Editora: %s\n", acervo[i].editora);
            printf("-------------------------------------\n");
            encontrado = true;
            break; //interromper imediatamente a execução de um loop
        }
        i++;
    };
    
    if (encontrado == false){
        printf("--------------------------------- \n");
        printf("Livro com código %d nao encontrado.\n", codigoBusca);
        printf("--------------------------------- \n");
    } 
};


// ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// ORNDENAR LIVROS
void ordenarLivros(struct Livro acervo[], int tamanho){
    struct Livro temp;

    if (tamanho < 2){
        printf("Não há livros suficientes para ordenar (min. 2).\n");
        return; // interrompe
    }

    
    for(int i = 0; i < tamanho - 1; i++) { // i → controla as passadas.
        for(int j = 0; j < tamanho - i - 1; j++) { // controla as comparações dentro de cada passada
        //EX:           2018 / 2020 / 2011 / 2025 
            if(acervo[j].ano > acervo[j+1].ano) { // Se o ano do livro atual for maior que o do próximo
                temp = acervo[j];      // guarda 2020
                acervo[j] = acervo[j+1]; // j recebe 2011
                acervo[j+1] = temp;      // j+1 recebe 2020
            }
        }
    }

    printf("\nLivros ordenados por ano com sucesso!\n");
}

// ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------


// CODIGO PRINCIPAL MAIN
int main(){
    struct Livro acervo[TAMANHO_ACERVO];
    int numeroMenu = 0;
    
    while (numeroMenu != 5){
        // system("cls"); // limpeza Para Windows
        // system("clear"); // limpeza Para Linux/Mac
        
        printf("======================================================== \n");
        printf("Seja bem vindo(a) ao menu principal! \n");
        printf("======================================================== \n");

        printf("Escolha uma das opções a seguir... (Livros cadastrados: %d)\n", quantidadeLivros);

        printf("1 - Cadastrar livros \n");
        printf("2 - Imprimir todos os livros \n");
        printf("3 - Pesquisar livro por código \n");
        printf("4 - Ordenar livros por ano de publicação \n");
        printf("5 - Sair do programa \n");
        printf("-------------------------------------------------------------------\n");
        
       
        if (scanf("%d",&numeroMenu) != 1) {
            // Se o usuário digitar algo que não é número
            numeroMenu = 0; // Força a entrada no default e limpa o buffer
            while (getchar() != '\n');  // Limpar o buffer 
        }
        
       
    

        switch (numeroMenu){
            case 1 : cadastrarLivros(acervo, TAMANHO_ACERVO);
                break;
                
            case 2 : imprimirLivros(acervo, quantidadeLivros); 
                break;
                
            
            case 3 : pesquisarLivro(acervo, quantidadeLivros, pesquisa_Codigo); 
                break;
                
            case 4 : ordenarLivros(acervo, quantidadeLivros);  // recebe acervo e a quantidade livros cadastrados no momento
                break;
                
            case 5 : 
                printf("Encerrando o sistema de biblioteca...\n");
                break;
                
            default:
                printf("Opção inválida! Digite um número de 1 a 5.\n");
        }
    }
    
    return 0;
}