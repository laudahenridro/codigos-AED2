// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h> 
#include <math.h>

void parMaisProximo(double **, int, int, int *); 

int main(){
	int quant, par;
	double x, y;
	double ** vets;
	printf("Digite a quantidade de coordenadas: ");
	scanf("%d", &quant);
	vets = (double**)(malloc(2*(sizeof(double*) ) ) );
	*(vets) = (double*)(malloc(quant*sizeof(double) ) );
	*(vets+1) = (double*)(malloc(quant*sizeof(double) ) );
	printf("Digite a lista de coordenadas (por favor, digite como (x,y), respectivamente): \n");
	for(int i = 0; i < quant ;++i){
		printf("Coordenadas (x,y) %d: ", (i+1) );
		scanf("%lf %lf", &x, &y);
		(*(*(vets+1) + i) ) = x;
		(*(*(vets) + i) ) = y;
	}
	par = 0;
	parMaisProximo(vets, 0, quant, &par);
	printf("Par mais próximo: %d", par);
	free(*(vets+1) );
	free(*(vets) );
	free(vets);
	return 0;
} 

void parMaisProximo(double ** vetsAux, int nRef, int quant, int * nRet){
	// 1 : nRef ; 2 : nRet  
	if(nRef < quant){
		double x1, y1, d1, x2, y2, d2;
		int ret = *(nRet);
		parMaisProximo(vetsAux, (nRef+1), quant, nRet);
		(*(*(vetsAux+1) + nRef) ) = x1;
		(*(*(vetsAux) + nRef) ) = y1;
		(*(*(vetsAux+1) + ret) ) = x2;
		(*(*(vetsAux) + ret) ) = y2;
		d1 = (x1 - y1);
		d1 = pow(d1, 2.0);
		d1 = sqrt(d1);
		d2 = (x2 - y2);
		d2 = pow(d2, 2.0);
		d2 = sqrt(d2);
		if(d1 < d2){
			*(nRet) = nRef;
		}
		
	}
}