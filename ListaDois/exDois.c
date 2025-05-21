#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void inverte(int*, int, int, int*);

int main(){

    srand(time(NULL));

    int tam = 15, contador = 0;

    int teste[tam];

    for (int i = 0; i < tam; i++ ){
        teste[i] = rand() % 25 + 1;
    }

    //int teste[] = {2,4,1,3,5};

    for (int i = 0; i < tam; i++ ){
        printf("%d ", teste[i]);
    }
    printf("\n");

    for(int i = 0; i< tam -1; i++){
        int j = i+1;
        if(teste[i] > teste[j])
            inverte(teste, i, j, &contador);
    }

    for(int i = 0; i<tam; i++){
        printf("%d ", teste[i]);
    }

    printf("\n%d\n", contador);

    return 0;
}

void inverte(int* vetor, int i, int j, int* contador){

    int temp = vetor[i];
    vetor[i] = vetor[j];
    vetor[j] = temp;
    (*contador)++;

    if(i > 0 && vetor[i-1] > vetor[j-1]){
        inverte(vetor, i-1, j-1, contador);
    }
}