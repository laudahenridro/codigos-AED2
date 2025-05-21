#include <stdio.h>

void Hanoi(int, char , char , char, int*);

int main(){

    int soma = 0;

    Hanoi(100,'A','B','C', &soma);

    printf("A quantidade de passos totais e: %d", soma);

    return 0;

}

void Hanoi(int n, char ori, char trab, char dest, int* soma){
    
    if(n>0){
        Hanoi(n-1, ori, dest, trab, soma);
        (*soma)++;
        Hanoi(n-1, trab, ori, dest, soma);
    }
}