#include <stdio.h>


// o algoritmo deve informar se o numero é par ou impar 
int main() {
    int n;

    printf("digite o numero da semana \n");
    scanf("%d",&n);

    switch (n)
    {
    case 1 : printf("DOMINGO\n");
        break;
    case 2 : printf("SEGUNDA \n");
        break;
    case 3 : printf("TERÇA \n");
        break;
    case 4 : printf("QUARTA \n");
        break;
    case 5 : printf("QUINTA \n");
        break;
    case 6 : printf("SEXTA \n");
        break;
    case 7 : printf("SÁBADO \n");
        break;
    
    default: printf("Digite um número de 1 a 7 para ver o dia da semana correspondente.\n");
        break;
    }

    return 0;
}


// Quando o usuário digita aparece um dia da semana
/*int main() {
    int n;

    printf("digite o numero da semana \n");
    scanf("%d",&n);

    switch (n)
    {
    case 1 : printf("DOMINGO\n");
        break;
    case 2 : printf("SEGUNDA \n");
        break;
    case 3 : printf("TERÇA \n");
        break;
    case 4 : printf("QUARTA \n");
        break;
    case 5 : printf("QUINTA \n");
        break;
    case 6 : printf("SEXTA \n");
        break;
    case 7 : printf("SÁBADO \n");
        break;
    
    default: printf("Digite um número de 1 a 7 para ver o dia da semana correspondente.\n");
        break;
    }

    return 0;
}
*/
