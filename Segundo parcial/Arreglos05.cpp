/*Arreglos05.cpp
	programa que grafica funciones con la capacidad de la pantalla en modo texto 
	f(x)=x*x
	Transcibrió: Alejandro Millán Jiménez
	Compiló: Alejandro Millán Jiménez
	Fecha de compilación: 21/10/2025 18:25
	
	*/	
	
#include <iostream> 
using namespace std;

char xy[80][24]; 
int x,y,a;

int main()
{
	for(a=0; a<=10; a++)
	{
		xy[(a*a)/2][a*2]='*';
	}
		
	for(y=24; y>=0; y--)
	{
		for(x=0; x<80; x++) 		
			cout<<xy[x][y]; 			
		
		cout<<"\n";
		
	}
	
	
	return 0;
}


