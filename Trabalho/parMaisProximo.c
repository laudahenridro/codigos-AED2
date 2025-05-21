#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct coord{
    float x;
    float y;
};

struct coord* criaCoord(int, int);
struct coord** criaPreencheLista(int);

int main(){
    srand(time(NULL));
    
    int qtd;
    scanf("%d",&qtd);

    struct coord** lista = criaPreencheLista(qtd);

    /*
    A fins de teste, impressão da lista no terminal. 
    
    for(int i = 0; i<qtd; i++){
        if(i == qtd - 1)
            printf("(%.1f, %.1f)", lista[i]->x, lista[i]->y);
        else
            printf("(%.1f, %.1f), ", lista[i]->x, lista[i]->y);

    }*/

    return 0;

}

struct coord* criaCoord(int a, int b){
    struct coord* p = malloc(sizeof(*p));
    p->x = a;
    p->y = b;

    return p;
}

struct coord** criaPreencheLista(int n){
    
    struct coord** aux = malloc(n*sizeof(*aux));

    for(int i = 0; i<n; i++){   
        float a = rand() % 100 + 0, b = rand() % 100 + 0;
        
        struct coord* p = criaCoord(a,b);
        aux[i] = p;
    }

    return aux;
}


