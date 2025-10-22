/*Arreglos06.cpp
	programa que grafica funciones: Función seno en una matriz
	Transcibrió: Alejandro Millán Jiménez
	Compiló: Alejandro Millán Jiménez
	Fecha de compilación: 21/10/2025 18:45
	
	*/	
	
#include<stdio.h> 
#include<math.h> 
#include <iostream> 
using namespace std;
int main() 
{
	int x,y;
	float senflo,rad;
	char grafica[80][24];
	//Se limpia la matriz colocando espacios 
	for(x=0; x<80; x++)
		for(y=0; y<24; y++) 
			grafica[x][y]=' ';
	//Se realizan los calculos y se colocan * en la matriz: 
	for(x=1; x<=80; x++)	
	{ 
		//rad=x*J.141592/40; 
		rad=x*M_PI/40; 
		senflo=sin(rad); 
		y=(senflo*12)+12; 
		grafica[x-1][y]='*';
	}
	//Se imprime la matriz de arriba hacia abajo y de izq. a dcha. 
	for(y=23; y>=0; y--)
	{
		for(x=0; x<80; x++) 
			cout<<grafica[x][y];
		cout<<"\n"; 
	}
	
	return 0;
}


