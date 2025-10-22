/*Arreglos10.cpp
	Regresa el numero de caracteres de una cadena
	Transcibrió: Alejandro Millán Jiménez
	Compiló: Alejandro Millán Jiménez
	Fecha de compilación: 21/10/2025 18:59
	
	*/	
	
#include <stdio.h>
#include <iostream> 

using namespace std; 

main()
{
	int len=-1; 
	char str[100]; 
	cout<<"cadena="; 
	cin>>str;
	while(str[++len]!='\0'); //hasta donde la cadena es vA;lida, antes del espacio
	cout<<"logitud de la cadena= "<<len<<endl; 
	return 0;
}

