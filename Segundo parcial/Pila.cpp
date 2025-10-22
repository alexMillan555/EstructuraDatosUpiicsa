#include <iostream>
#include<stdlib.h>

int menuPrograma();

using namespace std;

int main()
{
	int tamanioPila = 5;
	int min,max,actual;
	int pila[tamanioPila];
	int menu = 0;
	int pregunta = 0;
	int vacios = 0;
	int ocupados = 0;
	
	min = 0; 
	max = 5;
	actual = 0;
	system("color 17");
	
	do
	{
		menu = menuPrograma();
		switch(menu)
		{
			case 1:
				system("cls");
				cout<<"\t\t***INSERTAR ELEMENTO**\t\t";
				
				if(actual == tamanioPila)
				{
					cout<<"\nPila llena";
					cout<<"\n";
					system("pause");
					break;
				}
				else
				{
					for(int i = actual; i < tamanioPila; i++)
					{
						cout<<"\nPor favor, dame el elemento no. "<<i+1<<"(escriba 0 para abortar) : ";
						cin>>pila[i];
						
						if(pila[i]<=0)
							break;						
						else
							actual = i+1;
						
					}
				}
				
				break;
				case 2:
					system("cls");
					cout<<"\t\t***ELIMINAR ELEMENTO**\t\t\n";
					if(actual-1 >=0)
					{
						cout<<"\nPosicion actual pila: "<<actual;
						cout<<"\nValor actual: "<<pila[actual-1];
						pila[actual-1] = 0;
						actual-=1;
						
						cout<<"\nPosicion actual despues de eliminar: "<<actual;
						cout<<"\nValor actual despues de eliminar: "<<pila[actual-1];
						
					}
					else
						cout<<"\nPila vacia!";					
					
					cout<<"\n";
					system("pause");
					break;
				case 3:
					system("cls");
					cout<<"\t\t***LIMPIAR PILA**\t\t\n";
					cout<<"\nLimpiando pila...";
					for(int i = 0; i<tamanioPila; i++)
						pila[i] = 0;
					
					actual = 0;
						
					cout<<"\nPila limpiada!";
					cout<<"\n";
					system("pause");
					
					break;
				case 4:
					system("cls");
					cout<<"\t\t***IMPRIMIR PILA**\t\t\n";
					
					if(actual-1<min)
					{
						cout<<"\nPila vacia!";
						cout<<"\n";
						system("pause");
						break;
					}
					
					for(int i=0; i<tamanioPila;i++)
					{
						if(pila[i]>0)
							ocupados++;
						else
							vacios++;
						cout<<"\nValor de la posicion "<<i+1<<" de la pila: "<<pila[i];
					}
					
					cout<<"\nEspacios vacios en la pila: "<<vacios;
					cout<<"\nEspacios llenos en la pila: "<<ocupados;
					
					cout<<"\n";
					
					vacios = 0;
					ocupados = 0;
					
					system("pause");
					
					break;
				case 5:
					cout<<"\nSaliendo del programa...";
					cout<<"\n";
					system("pause");
					break;
				default:
					cout<<"\nOpcion invalida! elige una opcion correcta";
					cout<<"\n";
					system("pause");
					break;
		}
	}while(menu!=5);
	
}

int menuPrograma()
{
	int menu = 0;
	system("cls");
	cout<<"\t\t***PILAS***\t\t\t\n";
	cout<<"\n1.- Insertar elemento";
	cout<<"\n2.- Eliminar elemento";
	cout<<"\n3.- Limpiar pila";
	cout<<"\n4.- Imprimir pila";
	cout<<"\n5.- Salir";
	cout<<"\nElige una opcion: ";
	cin>>menu;
	return menu;
}
