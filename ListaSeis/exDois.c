/*2) “Distribuição Ótima de Doces”

Durante uma gincana escolar, os professores têm uma sacola com doces de diferentes
valores calóricos, representados por inteiros positivos, e precisam distribuir esses doces
para o maior número possível de crianças, com a seguinte regra:

• Cada criança só pode receber um doce, e o valor calórico do doce deve ser maior
ou igual a uma necessidade mínima específica daquela criança.

Você recebe:
• Uma lista com as necessidades mínimas calóricas de cada criança (n = número
de crianças).
• Uma lista com os valores calóricos dos doces disponíveis (m > n).*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void mergeSort(int*, int, int);
void merge(int*, int, int, int);
void distribuicaoOtimaDeDoces(int*, int*, int, int);

int main(){
    srand(time(NULL));
    int doces[14], alunos[10], tamanhoDoces = sizeof(doces)/ sizeof(*doces), tamanhoAlunos = sizeof(alunos)/ sizeof(*alunos);

    for(int i = 0; i<tamanhoDoces; i++){
        int x = rand() % 5000 + 2000;
        doces[i] = x;
    }
    for(int i = 0; i<tamanhoAlunos; i++){
        int x = rand() % 3500 + 2000;
        alunos[i] = x;
    }
    
    mergeSort(doces, 0, tamanhoDoces-1);
    mergeSort(alunos, 0, tamanhoAlunos-1);

    for(int i = 0; i<tamanhoDoces; i++)
        printf("%d ", doces[i]);                  //#Print dos vetores ordenados
    printf("\n");

    for(int i = 0; i<tamanhoAlunos; i++)
        printf("%d ", alunos[i]);
    printf("\n");
    
    distribuicaoOtimaDeDoces(doces, alunos, tamanhoDoces, tamanhoAlunos);

    
    /*for(int i = 0; i<tamanhoDoces; i++)
        printf("%d ", doces[i]);                
    printf("\n");*/

    return 0;
}

void distribuicaoOtimaDeDoces(int* doces, int* alunos, int tamanhoDoces, int tamanhoAlunos){
    int* relacao = malloc(tamanhoAlunos*(sizeof(relacao)));
    
    for(int i = 0; i<tamanhoAlunos; i++)
        relacao[i] = 0;

    int k = 0;
    for(int i = 0; i<tamanhoAlunos; i++){
        for(int j = 0; j<tamanhoDoces; j++){
            if((doces[j] >= alunos[i]) && (k<tamanhoAlunos)){
                relacao[k] = doces[j];
                doces[j] = 0;
                k++;
                break;
            }
        }
    }
    
    
    //Linha de comandos para printar o vetor relacao[]:

    for(int i = 0; i<tamanhoAlunos; i++)
        printf("%d ", relacao[i]);
    printf("\n");
    

    free(relacao);

}

void mergeSort(int* array, int i, int f){
    if(i<f){
        int q = (i+f)/2;
        mergeSort(array, i, q);
        mergeSort(array, q+1, f);
        merge(array, i, q, f);
    }
}

void merge(int* array, int i, int q, int f){
    int parte1 = q-i+1;
    int parte2 = f-q;

    int A1[parte1], A2[parte2];
    for(int j = 0; j<parte1; j++)
        A1[j] = array[i+j];

    for(int j = 0; j<parte2; j++)
        A2[j] = array[q+j+1];
    
    int a = 0, b = 0, c = i;

    while(a<parte1 && b<parte2){
        if(A1[a] <= A2[b]){
            array[c] = A1[a];
            a++;
        }
        else{
            array[c] = A2[b];
            b++;
        }
        c++;
    }

    while(a<parte1){
        array[c] = A1[a];
        c++;
        a++;
    }

    while(b<parte2){
        c++;
        b++;
    }
}