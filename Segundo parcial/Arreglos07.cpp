/*Arreglos07.cpp
	programa que grafica funciones la funciA3n seno en una matriz con más valores 
	Observacion:**** Agrandar la ventana de la ejecución para visualizar correctamente la gráfica
	Transcibrió: Alejandro Millán Jiménez
	Compiló: Alejandro Millán Jiménez
	Fecha de compilación: 21/10/2025 18:49
	
	*/	
	
#include<stdio.h> 
#include<math.h> 
#include <iostream> 

using namespace std; 

#define RENG 42
#define COL 155 
int main()
{
	int x,y;
	float senflo,rad;
	char grafica[COL][RENG];
	//Se limpia la matriz colocando espacios 
	for(x=0; x<COL; x++)
		for(y=0; y<RENG; y++) 
			grafica[x][y]=' ';
	//Se realizan los calculos y se colocan * en la matriz: 
	for(x=1; x<=COL; x++)
	{ //rad=x*J.141592/40; 
		rad=x*M_PI/(COL/2); 
		senflo=sin(rad); 
		y=(senflo*(RENG/2))+(RENG/2); 
		grafica[x-1][y]='*';
	}
	//Se imprime la matriz de arriba hacia abajo y de izq. a dcha. 
	for(y=RENG-1; y>=0; y--)
	{
		for(x=0; x<COL; x++)
			cout<<grafica[x][y]; //printf("%c",grafica[x][y]); 
		cout<<"\n";
	}
	
	
	return 0;
}



