/*Arreglos08.cpp
	Manejo de arreglos de tipo char implementando cadenas
	Imprime todo el contenido del arreglo tipo char, y despues lo imprime con la opcion str*
	Transcibrió: Alejandro Millán Jiménez
	Compiló: Alejandro Millán Jiménez
	Fecha de compilación: 21/10/2025 18:53
	
	*/	
	
#include<stdio.h> 
#include<iostream> 

using namespace std; 

int main()
{
	int i;
	char str[100]; 
	cout<<"cadena= "; 
	cin>>str; 
	cout<<"\n";
	for(i=0; i<100; i++) 
		cout<<str[i];
	cout<<"\n\nUtilizando solo cout<<str, imprime solo la cadema valida hasta antes de un espacio en blanco: \n\t";
	 
	cout<<str; 
	cout<<"\n"; 
	return 0;
}

