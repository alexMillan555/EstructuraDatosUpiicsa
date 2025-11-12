/*MemDinamica06.cpp
	Funciones de asignacion para memoria dinamica
	Asigna suficiente memoria para almacenar estructuras tipo dir
	Transcibrió: Alejandro Millán Jiménez
	Compiló: Alejandro Millán Jiménez
	Fecha de compilación: 05/11/2025 10:06
	
	*/	
	
#include<iostream>
#include<conio.h>
using namespace std;
struct dir
{
	char nombre[20];
	char calle[40];
	char ciudad[40];
	char CP[5];
};

int main()
{
	struct dir *p;
	p=new(dir);
	if(p==NULL)
	{
		cout<<"Error en la asignacion, memoria insuficiente\n"<<endl;
		exit(1);
	}
	cout<<"Direccion de memoria donde apunta p: "<<p<<"\n"<<endl;
	p++;
	cout<<"Si se incrementa 1 a p, ahora vale: "<<p<<"\n"<<endl;
	delete(p);
	return 0;
}
