#include <stdio.h>

int somar( int*, int);

int main(){

	int n = 4;
	int V[] = {2000,1500, 4000, 1200};
	
	
	printf("%d\n", somar(V, n));
	
	return 0;
}

int somar( int*V, int n){
	
	int soma = 0;

    for(int i = 0; i < n; i++){
        soma += V[i];
    }

    return soma;
}