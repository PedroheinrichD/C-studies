#include <stdio.h>


// o algoritmo deve informar se o numero é par ou impar 
int main() {
    int n;
    printf("Digite um numero");
    scanf("%d",&n);
    
    if (n % 2 == 0){
        printf("o número digitado é %d --> PAR ",n);
    }else{
        printf("número digitado foi %d --> ÍMPAR",n);
    }
    
    
    return 0;
}
