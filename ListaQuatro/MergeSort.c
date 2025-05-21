#include <stdio.h>
#include <stdlib.h>

void mergeSort(int*, int, int);
void merge(int*, int, int, int);

int main(){

    FILE* fp = NULL;
    char arquivo[256];
    int qtd = 0;

    scanf("%s", arquivo);

    sscanf(arquivo,"%d",&qtd);

    int vetor[qtd];

    if((fp = fopen(arquivo,"r")) == NULL){
        printf("Erro: arquivo inexistente.\n");
        return 1;
    }

    for(int i = 0; i<qtd; i++)
        fscanf(fp,"%d,",&vetor[i]);

    if(fclose(fp)!=0){
        printf("Erro: nao foi possivel fechar o arquivo");
        return 2;
    }
    
    mergeSort(vetor, 0, qtd);

    for(int i = 0; i<qtd; i++)
        printf("%d ", vetor[i]);
    printf("\n");

    
}

void mergeSort(int* array, int i, int f){
    if(i<f){
        int meio=(i+f)/2;
        mergeSort(array, i, meio);
        mergeSort(array, meio+1, f);
        merge(array, i, meio, f);
    }
}

void merge(int* array, int i, int mid, int f){

    int E[mid], D[(i+f)/2];

    for(int i = 0; i<mid;i++)
        E[i] = array[i];

    for(int j = mid; j < f; j++)
        D[j-mid] = array[j];
}

