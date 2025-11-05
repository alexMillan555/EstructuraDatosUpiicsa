/*Apunta04.cpp		ARITMETICA DE APUNTADORES
	Se puede incrementar y decrementar el valor del apuntador
	Transcibrió: Alejandro Millán Jiménez
	Compiló: Alejandro Millán Jiménez
	Fecha de compilación: 04/11/2025 21:27
	
	*/	
	
#include<iostream>
#include<conio.h>

using namespace std;

int main()
{
	int x = 2024;
	int *p1, *p2, *inc, *dec; /*Las variables de apuntador se declaran anteponiendo un * */
	
	p1=&x; /*p1 recibira la direccion de memoria donde se encuentra x	*/
	p2=p1; /*p2 tendra el valor que recibio p1, esto es la direccion de memoria de x */
	
	inc=p1;
	dec=p1;
	inc++;
	dec--;
	
	/*Esto mostrara las direcciones contenidas en p1 y p2. Seran las mismas   */
	
	cout<<"\n\n\n\np1 vale: "<<p1<<" y p2 vale: "<<p2<<" y son de tipo entero"<<endl;
	cout<<"\n\n\n\np1 muestra el valor: "<<*p1<<" y p2 muestra el valor: "<<*p2<<" y son de tipo entero"<<endl;
	cout<<"\n\n\n\ninc ahora apunta a la direccion: "<<inc<<" y dec apunta a: "<<dec<<endl;
	getch();
	return 0;
}
