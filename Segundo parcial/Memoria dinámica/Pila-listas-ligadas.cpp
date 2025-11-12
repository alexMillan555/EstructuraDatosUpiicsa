/*Pila-listas-ligadas.cpp
	Programa que implementa una Pila utilizando listas ligadas
	Transcibrió: Alejandro Millán Jiménez
	Compiló: Alejandro Millán Jiménez
	Fecha de compilación: 12/11/2025 14:58
	
	*/	
	
#include<iostream>
#include<conio.h>
#include<stdlib.h> //para new y delete
using namespace std;

struct NODO
{
	char ID;
	int Valor;
	int Valor2;
	struct NODO *SIG;
};
struct NODO *CIMA=NULL, *N;
char o;
void apilar();
void desapilar();
void mostrar();

int main()
{
	for(;;)
	{
		system("cls");
		cout<<"\t\tIntroduce la opcion deseada: \n\n";
		cout<<"\t 1. Apilar (insertar elemento) \n";
		cout<<"\t 2. Desapilar (eliminar elemento) \n";
		cout<<"\t 3. Mostrar pila \n";
		cout<<"\t 4. Salir \n";
		o=getche();
		if(o=='1')
			apilar();
		if(o=='2')
			desapilar();
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
}

void apilar()
{
	N=new(struct NODO);
	if(CIMA==NULL)
		N->SIG=NULL;
	else
		N->SIG=CIMA;
	cout<<"\n\n Indique Elemento a apilar:	";
	N->ID=getche();		//INSERTEN N-> Valor --scanf("%d", &Valor) cin << Valor
	CIMA = N;
	cout<<"\n Elemento apilado \n";
	system("pause");
}

void desapilar()
{
	if(CIMA==NULL)
		cout<<"\nPila vacia (UNDERFLOW) , no existen elementos que desapilar \n";
	else
	{
		cout<<"\n El elemento a desapilar es: ["<<CIMA->ID<<"] ";
		system("pause");
		N=CIMA;
		CIMA=N->SIG;
		delete(N);
		cout<<"\nElemento desapilado \n";
	}
	system("pause");
}

void mostrar()
{
	if(CIMA==NULL)
		cout<<"\nLA PILA ESTA VACIA, NO HAY NADA QUE MOSTRAR";
	else
	{
		N=CIMA;
		for(; N!=NULL;)
		{
			cout<<"\n ID: ["<<N->ID<<"] ";
			if(N==CIMA)
				cout<<"<-----CIMA";
			N=N->SIG;
		}
	}
	cout<<"\n";
	system("pause");
}

