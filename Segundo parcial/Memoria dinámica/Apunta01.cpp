/*Apunta01.cpp
	Programa que ejemplifica el uso de los apuntadores
	Transcibrió: Alejandro Millán Jiménez
	Compiló: Alejandro Millán Jiménez
	Fecha de compilación: 04/11/2025 21:08
	
	*/	
	
#include<iostream>
#include<conio.h>

using namespace std;

int main()
{
	int cuenta, q;
	int *m; /*Las variables se declaran anteponiendo*/
	
	cuenta = 100; /*A cuenta se le asigna el valor de 100*/
	m=&cuenta; /* m recibe la dirección de cuenta &variable regresa el no. direccion de memoria de la variable*/
	
	q=*m; /*a q (cualquier variable) se le asigna el valor de cuenta indirectamente a traves de m*/
	cout<<"\n\nEl valor de q es: "<<q<<" igual a cuenta, ya que m apunta a cuenta: "<<cuenta<<endl;
	cout<<"\n\nY m se encuentra en la direccion de memoria: "<<&cuenta<<" y equivale a: "<<*m<<endl;
	getch();
	return 0;
}
