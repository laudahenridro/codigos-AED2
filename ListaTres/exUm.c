#include <stdio.h>

int expon(int, int);

int main(){

    int poderBase = 0, nivel = 0, dano = 0;

    scanf("%d",&poderBase);
    scanf("%d",&nivel);

    dano = expon(poderBase, nivel);

    printf("O dano e %d\n", dano);


}

int expon(int poderBase, int nivel){

    int dano = poderBase;
    
    if(nivel == 0)
        return 1;
    else if(nivel == 1)
        return dano;
    else if(nivel%2){

        for(int i = 1; i<(nivel+1/2); i++)
            dano*=poderBase;
        
        return dano;
    }
    else{

        for(int i = 1; i<nivel/2; i++)
            dano*=poderBase;

        return dano*dano;
    }

}