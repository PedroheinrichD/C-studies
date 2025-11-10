#include <stdio.h>


// o algoritmo deve informar se o numero é par ou impar 
int main() {
    int m;
    printf("Digite á média");
    scanf("%d",&m);
    
    if(m > 7){
        printf("APROVADO COM A MÉDIA: %d ",m);
    }else if(m >= 4){
        printf("FAZER PROVA SUBSTITUTIVA MÉDIA: %d ",m);
    }else{
        printf("REPROVADO COM A MÉDIA: %d ",m);
    }
    
    
    return 0;
}
