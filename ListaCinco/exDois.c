/*Problema das Moedas (Coin Change)

No Problema das Moedas, o objetivo é determinar o número mínimo de moedas (ou
recursos) necessários para atingir uma quantia alvo.

Suponha que o jogador precisa acumular 7 gemas mágicas para desbloquear um feitiço.
Ele pode obter gemas em quantidades de 1, 3 ou 4 por missão. Qual é o menor número
de missões que ele deve completar?*/

#include <stdio.h>
#include <stdlib.h>

int menorTroco(int*, int, int);

int main(){
    int moedas[] = {1,3,4}; 
    int alvo = 7;
    int tamanho = (sizeof(moedas) / sizeof(*moedas));

    printf("A quantidade minima de moedas necessarias para %d e: %d\n", alvo , menorTroco(moedas, alvo, tamanho));

    return 0;

}

int menorTroco(int* moedas, int alvo, int tamanho){

    int* menorQtd = malloc((alvo+1)*sizeof(*menorQtd));
    
    for(int i = 1; i<(alvo+1);i++)
        menorQtd[i] = 9999;
    menorQtd[0] = 0;


    for(int i = 0; i<(alvo+1); i++){
        for(int j = 0; j<tamanho; j++){
            if(moedas[j]<=i && menorQtd[i-moedas[j]] != 9999){
                if(menorQtd[i-moedas[j]] + 1 < menorQtd[i])
                    menorQtd[i] = menorQtd[i-moedas[j]] + 1;
            }
        }
    }
    free(menorQtd);
    return menorQtd[alvo];

    


}