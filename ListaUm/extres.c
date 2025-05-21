#include <stdio.h>

int somar( int*, int);

int main(){
    
    int n = 5;
    int V[] = {2000, 1500, 4000, 1200, 5000};

    printf("%d\n", somar(V,n));

    return 0;
}

int somar( int*V, int n){
	
    int soma = 0;
    
    if(n%2 == 0){
        for(int i = 0; i < n; i+= 2){
            soma += V[i] + V[i+1];
        }
    }
    else{
        for(int i = 0; i < n-1; i+= 2){
            soma += V[i] + V[i+1];
        }
        soma += V[n-1];
        
    }
    
    
    return soma;
}