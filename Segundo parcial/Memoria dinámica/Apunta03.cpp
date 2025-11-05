/*Apunta03.cpp		ASIGNACION DE APUNTADORES
	Como en el caso de cualquier otra variable, un apuntador puede utilizarse a la derecha de una 
	declaración de asignacion para asignar su valor a otro valor apuntador
	Transcibrió: Alejandro Millán Jiménez
	Compiló: Alejandro Millán Jiménez
	Fecha de compilación: 04/11/2025 21:20
	
	*/	
	
#include<iostream>
#include<conio.h>

using namespace std;

int main()
{
	int x = 2024;
	int *p1, *p2; /*Las variables de apuntador se declaran anteponiendo un * */
	
	p1=&x; /*p1 recibira la direccion de memoria donde se encuentra x	*/
	p2=p1; /*p2 tendra el valor que recibio p1, esto es la direccion de memoria de x */
	
	/*Esto mostrara las direcciones contenidas en p1 y p2. Seran las mismas   */
	
	cout<<"\n\n\n\np1 vale: "<<p1<<" y p2 vale: "<<p2<<endl;
	cout<<"\n\n\n\nQue es el numero de memoria donde se encuentra x -> "<<&x<<endl;
	getch();
	return 0;
}
