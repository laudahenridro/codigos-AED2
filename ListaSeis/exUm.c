/*
1) “A Pirâmide do Guardião”

O Antigo Templo de Kahr’Dan esconde um tesouro protegido por um enigma milenar:
uma pirâmide invertida de compartimentos. Cada compartimento guarda uma pedra
com um número inteiro positivo, e o objetivo do Guardião é escolher uma sequência de
pedras, começando do topo da pirâmide até chegar a qualquer posição da base, de modo
que:

• A soma dos valores das pedras escolhidas seja exatamente igual a uma chave
secreta S.
• De cada compartimento, o Guardião só pode descer para a pedra imediatamente
à esquerda ou à direita da linha abaixo.
• O Guardião não pode visitar o mesmo compartimento duas vezes.
• A pirâmide é dada como uma lista de listas, onde a linha 0 tem 1 elemento, a
linha 1 tem 2, e assim por diante. Implemente um algoritmo usando
backtracking para:

Encontre todas as sequências possíveis que somam S. Cada sequência deve ser uma lista
com os valores das pedras. Ao final, imprima as soluções encontradas (ou “Nenhuma
solução” se não houver).

Obs.:

• Você sempre começa do topo (p[0][0]).
• Em cada nível, pode ir para os índices [i][j] → [i+1][j] ou [i+1][j+1].
• Use backtracking para explorar as possibilidades e fazer poda quando a soma
parcial ultrapassar S.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int** criaPiramide(int);
int tesouroPerdido(int**, int, int);

int main(){
    
    srand(time(NULL));
    int S = rand() % 15+10, altura = rand() % 6+3,** pir;

    printf("%d\n", altura);

    printf("O valor de S e: %d\n", S);

    pir = criaPiramide(altura);
    tesouroPerdido(pir, altura, S);

    for(int i = 0; i< altura; i++){
        for(int j = 0; j<i; j++){
            if(j == i-1)
                printf("%d\n", pir[i][j]);                          //Printa pirâmide
            else   
                printf("%d ", pir[i][j]);
        }
    }




    return 0;
}

int** criaPiramide(int altura){

    int ** pir = malloc(altura*sizeof(pir));
    for(int i= 0; i< altura; i++)
        pir[i] = malloc(i*sizeof(pir));



    for(int i = 0; i<altura; i++){
        for(int j = 0; j<i; j++){
            pir[i][j] = rand() % 9+1;
        }
    }

    return pir;

}

int tesouroPerdido(int** pir, int altura, int S){
    int soma = 0;
    int sequencia[altura];

    for(int i = 0; i<altura; i++)
        sequencia[i] = 0;
    
    int i = 0, j = 0, k = 0;
    //printf("%d\n",pir[0][0]);

    while(i<altura){
        if(soma>=S){
            for(int l = 0; l<altura; l++)
                printf("%d ", sequencia[l]);
            printf("\n");
            return 0;
        }
        else if(i==0 && j==0){
            soma+= pir[i][j];
            sequencia[k] = pir[i][j];
            k++;
        }
        else if(pir[i+1][j] >= pir[i+1][j+1]){
            soma+=pir[i+1][j];
            sequencia[k] = pir[i+1][j];
            k++;
        }
        else{
            soma+=pir[i+1][j+1];
            sequencia[k] = pir[i+1][j+1];
            k++;
        }      
    }

    printf("Sequencia nao encontrada\n");
    return 1;


}