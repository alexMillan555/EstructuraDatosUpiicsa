/*MemDinamica07.cpp
	Funciones de asignacion para memoria dinamica
	Asigna suficiente memoria para almacenar estructuras tipo dir
	Transcibrió: Alejandro Millán Jiménez
	Compiló: Alejandro Millán Jiménez
	Fecha de compilación: 05/11/2025 10:24
	
	*/
	
#include<iostream>
#include<conio.h>
using namespace std;
int entera;
struct dir
{
	char nombre[20];
	char calle[40];
	int numero;
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
	cout<<"Digita tu nombre: \t"<<endl;
	cin>>p->nombre;
	cout<<"Digita tu calle: \t"<<endl;
	cin>>p->calle;
	cout<<"Digita tu numero: \t"<<endl;
	cin>>p->numero;
	entera=p->numero;
	cout<<"Digita tu ciudad: \t"<<endl;
	cin>>p->ciudad;
	cout<<"Digita tu codigo postal: \t"<<endl;
	cin>>p->CP;
	
	system("cls");
	cout<<"\n\t\tLOS DATOS QUEDARON REGISTRADOS\n"<<endl;
	cout<<"Nombre almacena: "<<*p->nombre<<" y se encuentra en la direccion \t"<<&p->nombre<<"\n"<<endl;
	cout<<"Calle almacena: "<<*p->calle<<" y se encuentra en la direccion \t"<<&p->calle<<"\n"<<endl;
	cout<<"Numero almacena: "<<entera<<" y se encuentra en la direccion \t"<<&p->numero<<"\n"<<endl;
	cout<<"Ciudad almacena: "<<*p->ciudad<<" y se encuentra en la direccion \t"<<&p->ciudad<<"\n"<<endl;
	cout<<"Codigo postal almacena: "<<*p->CP<<" y se encuentra en la direccion \t"<<&p->CP<<"\n"<<endl;
	system("pause");
	delete(p);
	return 0;
}
