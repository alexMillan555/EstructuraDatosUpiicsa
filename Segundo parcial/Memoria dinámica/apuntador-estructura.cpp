/*apuntador-estructura.cpp
	Apuntadores a estructuras
	Transcibrió: Alejandro Millán Jiménez
	Compiló: Alejandro Millán Jiménez
	Fecha de compilación: 12/11/2025 13:58
	
	*/	
	
#include<iostream>
#include<conio.h>
#include<stdlib.h> //para new y delete
using namespace std;

struct Persona
{
	char nombre[15];
	int edad;
}persona, *apuntador_persona = &persona;

void pedirDatos();
void mostrarDatos(Persona *);

int main()
{
	pedirDatos();
	mostrarDatos(apuntador_persona);
	cout<<"Direccion de la variable: "<<apuntador_persona<<"\n"<<endl;
	getch();
	return 0;
}

void pedirDatos()
{
	cout<<"Digite el nombre: ";
	//sin apuntadores el acceso a los miembros seria: (persona.nombre)
	cin.getline(apuntador_persona->nombre,15,'\n');
	cout<<"Digita la edad: ";
	cin>>apuntador_persona->edad;
}

void mostrarDatos(Persona *apuntador_persona)
{
	cout<<"\nNombre almacenado: "<<&apuntador_persona->nombre<<endl;
	cout<<"\nEdad almacenada: "<<&apuntador_persona->edad<<endl;
}
