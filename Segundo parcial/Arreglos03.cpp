/*Arreglos03.cpp
	Manejo de enteros con arreglos implementando
	el ordenamiento burbuja
	Transcibrió: Alejandro Millán Jiménez
	Compiló: Alejandro Millán Jiménez
	Fecha de compilación: 21/10/2025 18:13
	
	*/	
#include <stdio.h>
#include <conio.h> 
#include <iostream> 
using namespace std; 
main()
{

	int x[10],i,a,j;
	for(i=0;i<10;i++) //Se solicitan los valores del arreglo
	{
		cout<<"\nx"<<i+1<<"="; 
		cin>>x[i];
	}
	 
	for(i=0;i<9;i++) //Implementacion burbuja 
	for(j=i+1;j<10;j++)
	if(x[i]>x[j])
	{
	 	a=x[j];
	 	x[j]=x[i];
		x[i]=a;
	}
	cout<<"\n";
	for(i=0;i<10;i++) //Despliega resultados 
		cout<<"x["<<i+1<<"]: = "<<x[i]<<endl;
	return 0;
}

