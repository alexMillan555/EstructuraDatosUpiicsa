/*MemDinamica01.cpp		
	Funcion de asignacion para memoria dinamica.
	Este programa asigna valores enteros
	Transcibrió: Alejandro Millán Jiménez
	Compiló: Alejandro Millán Jiménez
	Fecha de compilación: 04/11/2025 21:31
	
	*/	
	
#include<iostream>
#include<conio.h>

using namespace std;

int main()
{
	int *p, *q, *r;
	p = new(int);
	q=new(int);
	r = new(int);
	*p = 20;
	*q = 100;
	*r = *p * *q;
	cout<<"\n\nLa direccion de memoria donde asigno p es: "<<p<<", y el valor almacenado es: "<<*p<<endl;
	cout<<"\n\nLa direccion de memoria donde asigno q es: "<<q<<", y el valor almacenado es: "<<*q<<endl;
	cout<<"\n\nLa direccion de memoria donde asigno r es: "<<r<<", y el valor almacenado es: "<<*r<<endl;
	delete(p);
	delete(q);
	delete(r);
	
	system("pause");
	return 0;
}
