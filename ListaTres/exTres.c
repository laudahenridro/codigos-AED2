#include <stdio.h>

int buscaBinaria(int*, int, int);
void ordena(int*, int, int);

int main(){

    int x = 0, qtd = 0;

    scanf("%d", &qtd);
    int tesouro[qtd];

    for(int i = 0; i<qtd; i++){
        int valor = 0;
        scanf("%d",&valor);
        tesouro[i] = valor;
    }

    for(int i = 0; i< qtd -1; i++){
        int j = i+1;
        if(tesouro[i] > tesouro[j])
            ordena(tesouro, i, j);
    }

    for(int i = 0; i<qtd; i++)
        printf("%d ", tesouro[i]);
    printf("\n");



    scanf("%d",&x);

    if(x == buscaBinaria(tesouro,x, (sizeof(tesouro)/sizeof(*tesouro)))){
        printf("O valor %d foi encontrado",x);
        return 0;
    }

    printf("O valor %d nao foi encontrado",x);
    return 1;



}

int buscaBinaria(int* vetor, int val, int tam){

    int i = 0, meio = tam/2 - 1;
    
    while(i<=meio){
        if(val == vetor[meio]){
            return val;
        }
        else if(val>vetor[meio]){
            i = meio+1;
            meio = (meio+tam)/2;
            printf("A:%d\n", meio);
        }
        else{
            meio = (meio/2);
            printf("B:%d\n", meio);
        }
        
    }
    return 1;
}

void ordena(int* vetor, int i, int j){

    int temp = vetor[i];
    vetor[i] = vetor[j];
    vetor[j] = temp;

    if(i > 0 && vetor[i-1] > vetor[j-1]){
        ordena(vetor, i-1, j-1);
    }
}