#include <stdio.h>

int somar(int*,int);

int main(){

    int n = 4;
    int V[] = {2000,1500,4000,1200};

    printf("%d\n", somar(V, n));

    return 0;
}

int somar(int* vet, int tam){
    
    if(tam == 1)
        return vet[tam-1];
    else
        return vet[tam-1] + somar(vet, tam-1);

}