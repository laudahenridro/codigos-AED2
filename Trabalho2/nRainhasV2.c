/*
9) Problema das N Rainhas: Colocar N rainhas em um tabuleiro de xadrez NxN de
forma que nenhuma rainha possa atacar outra, ou seja, não compartilhem a
mesma linha, coluna ou diagonal.
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

void nRainhas(int*, int ,int);
int podeColocar(int*, int, int);
void printaTabuleiro(int*, int);

int main(){
    srand(time(NULL));
    int N = rand() % 9 + 4;
    int tabuleiro[N];
    for(int i = 0; i<N; i++)
        tabuleiro[i] = -1;

    printf("Fazendo solucoes para um tabuleiro %d x %d\n", N, N);
    nRainhas(tabuleiro,0,N);

    return 0;
}

void nRainhas(int tabuleiro[], int l ,int N){
    
    
    for(int c = 0; c<N; c++){
        if(podeColocar(tabuleiro, l, c)){
            tabuleiro[l] = c;
            if(l == N-1){
                printaTabuleiro(tabuleiro,N);
            }
            else
                nRainhas(tabuleiro, l+1, N);
        }
    }
    
}

int podeColocar(int tabuleiro[], int l, int c){

    for(int i = 0; i<l;i++){
        if(tabuleiro[i] == c)
            return 0;
        else if(abs(tabuleiro[i]-c)==abs(i-l))
            return 0;   
    }

    return 1;
}

void printaTabuleiro(int tabuleiro[], int N){

    printf("Printando solucao:\n\n");
    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            if(tabuleiro[i] == j){
                if(j==N-1)
                    printf("R\n");
                else
                    printf("R ");
            }
            else{
                if(j==N-1)
                    printf("-\n");
                else
                    printf("- ");
            }
        }
    }
    printf("\nAperte Enter para prosseguir.\n");
    getchar();

}