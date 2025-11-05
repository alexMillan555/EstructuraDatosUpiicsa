#include <iostream>
#include<stdlib.h>

int menuPrograma();

using namespace std;

int main()
{
	int tamanioCola = 5;
	int min,max,cont, actual;
	int cola[tamanioCola];
	int menu = 0;
	int pregunta = 0;
	int vacios = 0;
	int ocupados = 0;
	actual = 0;
	
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
				
				if(cont == tamanioCola)
				{
					cout<<"\nCola llena";
					cout<<"\n";
					system("pause");
					break;
				}
				else
				{
					for(int i = cont; i < tamanioCola; i++)
					{
						cout<<"\nPor favor, dame el elemento no. "<<i+1<<"(escriba 0 para abortar) : ";
						cin>>cola[i];
						
						if(cola[i]<=0)
							break;	
						else
							cont +=1;					
						
					}
				}
				
				break;
				case 2:
					system("cls");
					cout<<"\t\t***ELIMINAR ELEMENTO**\t\t\n";
					if(cont <= 0)
					{
						cout<<"\nCola vacía";
						system("pause");
						break;
					}					
					
					if(actual <= tamanioCola-1)
					{
						
						if(cola[actual] == 0)
						{
							cout<<"\nEl valor actual en la posicion actual esta vacio!";
							cout<<"\nSe recorrera al siguiente valor de la cola!";							
							cout<<"\nPosicion anterior en la cola: "<<actual+1;
							
							actual+=1;						
							cout<<"\nPosicion despues de recorrer al siguiente lugar de la cola: "<<actual+1;
							system("pause");
							break;
						}
						
						cout<<"\nPosicion actual pila: "<<actual+1;
						cout<<"\nValor actual: "<<cola[actual];
						cola[actual] = 0;
						actual+=1;
						
						cout<<"\nPosicion actual despues de eliminar: "<<actual+1;
						cout<<"\nValor actual despues de eliminar: "<<cola[actual];						
					}
					
					else
					{						
						cout<<"\nSe regresa al primer valor de la cola";
						actual = 0;	
					}				
					
					cout<<"\n";
					system("pause");
					break;
				case 3:
					system("cls");
					cout<<"\t\t***LIMPIAR COLA**\t\t\n";
					cout<<"\nLimpiando cola...";
					for(int i = 0; i<tamanioCola; i++)
						cola[i] = 0;
					
					actual = 0;
						
					cout<<"\nCola limpiada!";
					cout<<"\n";
					system("pause");
					
					break;
				case 4:
					system("cls");
					cout<<"\t\t***IMPRIMIR COLA**\t\t\n";
					
					if(cont<=min)
					{
						cout<<"\nCola vacia!";
						cout<<"\n";
						system("pause");
						break;
					}
					
					for(int i=0; i<tamanioCola;i++)
					{
						if(cola[i]>0)
							ocupados++;
						else
							vacios++;
						cout<<"\nValor de la posicion "<<i+1<<" de la pila: "<<cola[i];
					}
					
					cout<<"\nEspacios vacios en la cola: "<<vacios;
					cout<<"\nEspacios llenos en la cola: "<<ocupados;
					cout<<"\nPosicion actual de la cola: "<<actual+1;
					
					cout<<"\n";
					
					vacios = 0;
					ocupados = 0;
					cont = 0; 
					actual = 0;
					
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
	cout<<"\t\t***COLA***\t\t\t\n";
	cout<<"\n1.- Insertar elemento";
	cout<<"\n2.- Eliminar elemento";
	cout<<"\n3.- Limpiar cola";
	cout<<"\n4.- Imprimir cola";
	cout<<"\n5.- Salir";
	cout<<"\nElige una opcion: ";
	cin>>menu;
	return menu;
}
