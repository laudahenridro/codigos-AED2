#include <stdio.h>

void mergeSort(int*, int, int);
void merge(int*, int, int, int);

int main(){

    int tam = 0;
    scanf("%d", &tam);

    int tempos[tam];
    for(int i = 0; i< tam; i++){
        
        int tempo = 0;
        scanf("%d", &tempo);
        tempos[i] = tempo;
    }

    mergeSort(tempos, 0, tam);

    for(int i = 0; i< tam; i++)
        printf("%d ", tempos[i]);
    printf("\n");

    

    return 0;

}

void mergeSort(int* vetor, int ini, int fim){
    
    if(ini<fim){
        int meio = (ini+fim)/2 - 1;
        mergeSort(vetor, ini , meio);
        mergeSort(vetor, meio+1, fim);
        merge(vetor, ini, meio, fim);
    }
    

}

void merge(int* array, int i, int mid, int f){

    int E[mid], D[(i+f)/2];

    for(int i = 0; i<mid;i++)
        E[i] = array[i];

    for(int j = mid; j < f; j++)
        D[j-mid] = array[j];

        

}

