#include <stdio.h>
#define TAMANHO_ACERVO 20

/*Imagine que você foi contratado para desenvolver um sistema de gerenciamento de livros
para uma pequena biblioteca. O sistema deve permitir que o bibliotecário cadastre, pesquise,
ordene e gerencie o acervo de 20 livros.
Esta tarefa exigirá a aplicação de diversos conceitos fundamentais da linguagem C.
*/
struct Livro{
        int codigo;
        char titulo[50];
        char autor[30];
        char area[30];
        int ano;
        char editora[30];
    };


int quantidadeLivros = 0;
void cadastrarLivros(struct Livro acervo[], int tamanho){
      printf("===== CADASTRO DE LIVROS ===== \n");

    do {
    printf("Quantos livros deseja cadastrar? (max: %d)\n", tamanho);
    scanf("%d", &quantidadeLivros);

    if (quantidadeLivros < 1 || quantidadeLivros > tamanho) {
        printf("Valor inválido! Tente novamente.\n");
    }

} while (quantidadeLivros < 1 || quantidadeLivros > tamanho);
    
      for (int i = 0; i < quantidadeLivros; i++){
        printf("Código do livro %d : ",i+1);
        scanf("%d", &acervo[i].codigo);

        printf("Título do livro %d : ",i+1);
        scanf("%s", acervo[i].titulo);
        fflush(stdin);

        printf("Autor(a) do livro %d : ",i+1);
        scanf("%s", acervo[i].autor);
        fflush(stdin);

        printf("Área do livro %d: ",i+1);
        scanf("%s", acervo[i].area);
        fflush(stdin);

        printf("Ano do livro %d: ",i+1);
        scanf("%d", &acervo[i].ano);
        fflush(stdin);

        printf("Editora do livro %d:",i+1);
        scanf("%s", acervo[i].editora);
        fflush(stdin);
    }
};


void imprimirLivros(struct Livro acervo[], int tamanho){
    if (quantidadeLivros == 0){
        printf("Nenhum livro cadastrado ainda.\n");
        return;
    }

    printf("===== IMPRIMIR LIVROS ===== \n");

    for (int i = 0; i < quantidadeLivros; i++){
        printf("\n== LIVRO %d == \n", i + 1);
        printf("Código: %d\n", acervo[i].codigo);
        printf("Título: %s\n", acervo[i].titulo);
        printf("Autor: %s\n", acervo[i].autor);
        printf("Área: %s\n", acervo[i].area);
        printf("Ano: %d\n", acervo[i].ano);
        printf("Editora: %s\n", acervo[i].editora);
        printf("-------------------------------------");
    }
}



void pesquisarLivro(struct Livro acervo[], int tamanho, int codigoBusca);

void ordenarLivros(struct Livro acervo[], int tamanho);




int main(){
    struct Livro acervo[TAMANHO_ACERVO];
    int numeroMenu = 0;
    



while (numeroMenu != 5){
    // MENU
    printf("======================================================== \n");
    printf("Seja bem vindo(a) ao menu principal! \n");
    printf("======================================================== \n");

    printf("Escolha uma das opções a seguir... \n");

    printf("1 - Cadastrar livros \n");
    printf("2 - Imprimir todos os livros \n");
    printf("3 - Pesquisar livro por código \n");
    printf("4 - Ordenar livros por ano de publicação \n");
    printf("5 - Sair do programa \n");
    printf("-------------------------------------------------------------------\n");
    scanf("%d",&numeroMenu);
    

    
    switch (numeroMenu){
    case 1 : cadastrarLivros(acervo,TAMANHO_ACERVO);

        break;
        
    case 2 : imprimirLivros(acervo,quantidadeLivros);

        break;
        
    case 3 : // função pesquisa (ainda fazer);

        break;
        
    case 4 : // função ordenação (ainda fazer);

        break;
        
    case 5 : //encerra;

        break;
    }
}
 
   

    return 0;
}



/*

O QUE FAZER NA VOLTA?????
- Preciso ver como resolver a parte do Usuário  cadastrar 20 livros e sobrescrever 
-limpar o MENU QUANDO DIGITIAR um numero errado

*/