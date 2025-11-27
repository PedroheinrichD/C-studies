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
      printf("quantos livros deseja cadastrar?\n");

      scanf("%d",&quantidadeLivros);
      fflush(stdin);

      for (int i = 0; i < quantidadeLivros; i++){
        printf("Código do livro: ");
        gets, acervo[i].codigo;
        fflush(stdin);

        printf("Título do livro: ");
        gets, acervo[i].titulo;
        fflush(stdin);

        printf("Autor(a) do livro: ");
        gets, acervo[i].autor;
        fflush(stdin);

        printf("Área do livro: ");
        gets, acervo[i].area;
        fflush(stdin);

        printf("Ano do livro: ");
        gets, acervo[i].ano;
        fflush(stdin);

        printf("Editora do livro: ");
        gets, acervo[i].editora;
        fflush(stdin);
    }
};


void imprimirLivros(struct Livro acervo[], int tamanho){
    if (tamanho == 0){
        printf("Nenhum livro cadastrado ainda.\n");
        return;
    }

    printf("===== IMPRIMIR LIVROS ===== \n");

    for (int i = 0; i < quantidadeLivros; i++){
        printf("== LIVRO %d == \n",i+1);
        printf("%d",acervo[i].codigo);
        printf("%s",acervo[i].titulo);
        printf("%s",acervo[i].autor);
        printf("%d",acervo[i].area);
        printf("%d",acervo[i].ano);
        printf("%s",acervo[i].editora);
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

    printf("1 - Cadastrar livros");
    printf("2 - Imprimir todos os livros \n");
    printf("3 - Pesquisar livro por código \n");
    printf("4 - Ordenar livros por ano de publicação \n");
    printf("5 - Sair do programa \n");
    scanf("%d",&numeroMenu);
    

    
    switch (numeroMenu){
    case 1 : cadastrarLivros(acervo,TAMANHO_ACERVO);

        break;
        
    case 2 : // função imprimirLivros;

        break;
        
    case 3 : // função pesquisa;

        break;
        
    case 4 : // função ordenação;

        break;
        
    case 5 : // função encerra;

        break;
        
    
    default: ("Número inválido. Por favor digitar corretamente...");
        break;
    }
    
}
 
   

    return 0;
}
