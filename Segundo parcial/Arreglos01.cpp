/*Arreglos01.cpp
	Manejo de arreglos con enteros
	Transcibrió: Alejandro Millán Jiménez
	Compiló: Alejandro Millán Jiménez
	Fecha de compilación: 21/10/2025 17:46 
	
	*/	
	
#include<stdio.h>
#include<conio.h>
#include<iostream>

using namespace std;

int main()
{
	int x[5],i;
	
	for(i = 0; i < 5; i++)
	{
		cout<<"\n x"<<i+1<<"=";
		cin>>x[i];
	}
	for(i = 0; i < 5; i++)
		cout<<"\n x["<<i+1<<"]= "<<x[i];
	getch();
	return 0;
}
