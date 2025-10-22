/*Arreglos02.cpp
	Manejo de bidimensionales arreglos con enteros
	Transcibrió: Alejandro Millán Jiménez
	Compiló: Alejandro Millán Jiménez
	Fecha de compilación: 21/10/2025 18:00
	
	*/	
	
#include<stdio.h>
#include<conio.h>
#include<iostream>

using namespace std;

int main()
{
	int xb[3][3],i,j;
	
	for(i = 0; i < 3; i++)
	{
		for(j=0; j< 3; j++)
		{
			cout<<"\n xb["<<i<<"]["<<j<<"]= ";
			cin>>xb[i][j];
		}
		
	}
	cout<<"\n";
	
	for(i = 0; i < 3; i++)
	{
		for(j = 0; j < 3; j++)
			cout<<"\n xb["<<i<<"]["<<j<<"]= ["<<xb[i][j]<<"]\t"<<endl;
	}
		
	return 0;
}
