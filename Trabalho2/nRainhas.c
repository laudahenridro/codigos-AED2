/*
9) Problema das N Rainhas: Colocar N rainhas em um tabuleiro de xadrez NxN de
forma que nenhuma rainha possa atacar outra, ou seja, não compartilhem a
mesma linha, coluna ou diagonal.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int** criacaoTabuleiro(int);
void printaTabuleiro(int**, int);
void nRainhas(int**, int);
int podeColocar(int**, int, int, int);

int main(){
    srand(time(NULL));
    int N = 8, **M;

    M = criacaoTabuleiro(N);
    nRainhas(M,N);

    return 0;
}

int** criacaoTabuleiro(int N){

    int** M = malloc(N*sizeof(*M));
    for(int i = 0; i<N; i++)
        M[i] = malloc(N*sizeof(**M));

    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++)
            M[i][j] = 0;
    }

    return M;



}

void printaTabuleiro(int** M, int N){


    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            if(j == N-1)
                printf("%d\n",M[i][j]);
            else
                printf("%d ", M[i][j]);
        }
    }

}

void nRainhas(int** M, int N){

    int cont = 0;
    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            if(podeColocar(M,N,i,j) == 1 && cont<N){
                printf("Return %d\n",podeColocar(M,N,i,j));
                M[i][j] = 1;
            }
        }
    }

    printaTabuleiro(M,N);
}

int podeColocar(int**M, int N, int i, int j){

    printf("i = %d\n", i);
    printf("j = %d\n", j);

    for(int k = 0; k<N; k++){
        printf("M[%d][%d] = %d\n",k,j,M[k][j]);
        if(M[k][j] == 1)
            return 0;
    }

    for(int k = 0; k<N; k++){
        printf("M[%d][%d] = %d\n",i,k,M[i][k]);
        if(M[i][k]== 1){
            return 0;
        }
    }

    for(int k = 0; k<N;k++){
        printf("M[%d][%d] = %d\n",k+i,k+j,M[k+i][k+j]);
        if(M[k+i][k+j] == 1 && (((k+i)<N) && ((k+j)<N)))
            return 0;
    }

    /*for(int k = 0; k<N;k++){
        printf("M[%d][%d] = %d\n",k+i,k+j,M[k+i][k+j]);
        if(M[i-k][j-k] == 1 && (((i-k)>=0) && ((j-k)>=0)))
            return 0;
    }*/

    return 1;
}