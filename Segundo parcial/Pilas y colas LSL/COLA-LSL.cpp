/*COLA-LSL.cpp
	Programa que implementa una Cola utilizando listas ligadas
	Transcibrió: Alejandro Millán Jiménez
	Compiló: Alejandro Millán Jiménez
	Fecha de compilación: 12/11/2025 15:34
	
	*/	
	
#include<iostream>
#include<conio.h>
#include<stdlib.h> //para new y delete
using namespace std;

struct NODO
{
	char ID;
	struct NODO *SIG;
};
struct NODO *P=NULL, *N, *U=NULL;
char o;
void formar();
void eliminar();
void mostrar();

int main()
{
	for(;;)
	{
		system("cls");
		cout<<"\t\tIntroduce la opcion deseada: \n\n";
		cout<<"\t 1. Formar (insertar elemento) \n";
		cout<<"\t 2. Atender (eliminar elemento) \n";
		cout<<"\t 3. Mostrar cola \n";
		cout<<"\t 4. Salir \n";
		o=getche();
		if(o=='1')
			formar();
		if(o=='2')
			eliminar();
		if(o=='3')
			mostrar();
		if(o=='4')
		{
			cout<<"\n\n\t\t			Gracias por preferir el uso de estos programas		\n";
			getch();
			break;
		}
	}//del for
	return 0;
}//del main

void formar()
{
	N=new NODO; //(struct NODO*) malloc(sizeof(struct));
	cout<<"\n\n Indique el elemento a formar:	";
	N->ID=getche();
	N->SIG=NULL;
	if(U==NULL)
	{
		U=P;
		P=N;
	}
	else
	{
		U->SIG=N;
		U=N;
	}
	cout<<"\nElmento formado \n";
	system("pause");
}

void eliminar()
{
	if(P==NULL)
		cout<<"\nCola vacia (UNDERFLOW) , no existen elementos que eliminar \n";
	else
	{
		cout<<"\n El elemento a desapilar es: ["<<P->ID<<"] ";
		system("pause");
		N=P;
		P=P->SIG;
		delete N; //free(N);
		cout<<"\nElemento atendido \n";
		if(P==NULL)
			U=NULL;
	}
	system("pause");
}

void mostrar()
{
	if(P==NULL)
		cout<<"\nLA COLA ESTA VACIA, NO HAY NADA QUE MOSTRAR";
	else
	{
		N=P;
		for(; N!=NULL;)
		{
			cout<<"\n\n ID: ["<<N->ID<<"] \t";
			if(N==P)
				cout<<"	  <----P";
			if(N->SIG==NULL) 
				cout<<"	   <---U";	 //if(N==U)
			N=N->SIG;
		}
	}
	cout<<"\n";
	system("pause");
}

