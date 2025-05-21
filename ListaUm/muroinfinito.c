#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct no{
    int valor;
    struct no* prox;
    struct no* ant;
};

struct no* criaElem(int);
void insereMeio(struct no**, int);
void imprime(struct no*);
int busca(struct no*, int);
void exclui_lista(struct no**);


int main(){
    
    struct no* phead = NULL;
    
    srand(time(NULL));

    int tamanho = rand() % 15 + 5, alvo = 0, vetAuxiliar[tamanho];

    for(int i = tamanho-1; i>= 0; i--){ 
        
        int x = rand() % 100 + 1;
        insereMeio(&phead, x);
        vetAuxiliar[i] = x;
    }


    printf("\nDigite um valor alvo para ser procurado:\n");
    scanf("%d", &alvo);

    if (busca(phead, alvo) == 0)
        printf("Alvo %d encontado\n", alvo);
    else
    printf("Alvo %d nao encontado\n", alvo);

    for(int i = 0 ; i < tamanho; i++){
        printf("%d ", vetAuxiliar[i]);
    }

    exclui_lista(&phead);

    return 0;
}


struct no* criaElem(int numero){

    struct no* p = malloc(sizeof(*p));
    p->valor = numero;
    p->prox = NULL;
    p->ant = NULL;

    return p;
};

void insereMeio (struct no** phead, int numero){
    struct no* auxiliar = criaElem(numero);

    if(*phead){
        auxiliar->prox = (*phead)->prox;
        (*phead)->prox = auxiliar;
        auxiliar->ant = (*phead);
    }
    else{
        *phead = auxiliar;
        auxiliar->prox = *phead;
        auxiliar->ant = *phead;
    }
 
}

void exclui_lista(struct no** pp){
	if(*pp){
		exclui_lista((&(*pp)->prox));
		free(*pp);
		*pp = NULL;
		
	}
}

void imprime(struct no* p){

	if(p){
		printf("%d ", p->valor);
		imprime(p->prox);
	}
	else{
		printf("Lista vazia\n");
	}
}

int busca(struct no* phead, int numero){

    struct no* auxiliar = phead;

    do{

        if(phead->valor == numero || auxiliar->valor == numero){
            return 0;
        }
        else{
            phead = phead->prox;
            auxiliar = auxiliar->ant;
        }

    }while ( (phead->prox) != (phead->ant) );

    return -1;

}