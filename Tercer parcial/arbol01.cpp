/*arbol01.cpp
	Programa que genera un árbol de orden 3
	Transcibrió: Alejandro Millán Jiménez
	Compiló: Alejandro Millán Jiménez
	Fecha de compilación: 02/12/2025 20:53
	
	*/	

#include<stdio.h>
#include<stdlib.h>

struct NODO
{
	int DATO;
	struct NODO *IZQ;
	struct NODO *CENTRO;
	struct NODO *DCHO;
};

int aux;
struct NODO *PADRE, *N=NULL, *HIJOI=NULL, *HIJOC=NULL, *HIJOD=NULL;

int main()
{
	N=new(NODO);
	printf("Dame el valor del nodo Padre: \n");
	scanf("%d", &aux); 
	N->DATO=aux;
	N->IZQ=NULL;
	N->CENTRO=NULL ; 
	N->DCHO=NULL ; 
	PADRE=N;

	//Nodo   hijo   izq
	N=new(NODO);
	printf("Dame el valor del hijo izquierdo:\n");
	scanf("%d",&aux); 
	N->DATO=aux;
	N->IZQ=NULL;
	N->CENTRO=NULL; 
	N->DCHO=NULL; 
	PADRE->IZQ=N; 
	HIJOI=N;
	
	//Nodo   hijo   centro
	N=new(NODO);
	printf("Dame el valor del hijo centro:\n");
	scanf("%d",&aux); 
	N->DATO=aux;
	N->IZQ=NULL;
	N->CENTRO=NULL; 
	N->DCHO=NULL; 
	PADRE->CENTRO=N; 
	HIJOC=N;

	//Nodo   hijo   derecho
	N=new(NODO) ;
	printf("Dame el valor del hijo derecho:\n");
	scanf("%d",&aux); 
	N->DATO=aux;
	N->IZQ=NULL;
	N->CENTRO=NULL; 
	N->DCHO=NULL; 
	PADRE->DCHO=N; 
	HIJOD=N; 
	
	printf("El nodo padretiene el valor: %d\n",PADRE->DATO);
	printf ("El nodo hijo izquierdo tiene el valor: %d\n", HIJOI->DATO); 
	printf("El nodo hijo centro tiene el valor: %d\n", HIJOC->DATO); 
	printf("El nodo hijo derecho tiene el valor: %d\n",HIJOD->DATO);
	
	printf("\n\t\t\t %d\n", PADRE->DATO); 
	printf("\n\t\t %d",HIJOI->DATO); 
	printf("\t %d",HIJOC->DATO);
	printf ("\t %d\n", HIJOD->DATO);
	system("pause");
	
	delete(PADRE);
	delete(N);
	delete(HIJOI); 
	delete(HIJOC); 
	delete (HIJOD);

}
