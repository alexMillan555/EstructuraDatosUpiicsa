/*Examen2ndoDepto.cpp
	Programa que implementa una Cola utilizando listas ligadas
	Transcibrió: Alejandro Millán Jiménez
	Compiló: Alejandro Millán Jiménez
	Fecha de compilación: 13/11/2025 19:51
	
	*/	
	
#include<iostream>
#include<conio.h>
#include<stdlib.h> //para new y delete
using namespace std;

struct NODO
{
	int ID;
	char Nombre[15];
	char Domicilio[30];
	float peso;
	NODO *SIG;
};
NODO *cabecero, *cola;

int menu;
int identidad=0;
void insertar();
void eliminar();
void eliminarPorID();
void mostrar();
void buscarMiembro();


int main()
{
	system("color 17");
	while(menu!=6)
	{
		system("cls");
		cout<<"\t\tIntroduce la opcion deseada: \n\n";
		cout<<"\t 1. Mostrar lista \n";
		cout<<"\t 2. Insertar miembro \n";
		cout<<"\t 3. Eliminar miembro \n";
		cout<<"\t 4. Buscar miembro \n";
		cout<<"\t 5. Eliminar miembro por ID \n";
		cout<<"\t 6. Salir \n";
		cout<<"\nPor favor, ingrese una opcion: ";
		cin>>menu;
		switch(menu)
		{
			case 1:
				system("cls");
				cout<<"\t\t**MOSTRAR LISTA**\t\t\n";
				mostrar();
				break;
			case 2:
				system("cls");
				cout<<"\t\t**INSERTAR ELEMENTO**\t\t\n";
				insertar();
				break;
			case 3:
				system("cls");
				cout<<"\t\t**BORRAR ELEMENTO**\t\t\n";
				eliminar();
				break;
			case 4:
				system("cls");
				cout<<"\t\t**BUSCAR MIEMBRO POR ID**\t\t\n";
				buscarMiembro();
				break;
			case 5:
				system("cls");
				cout<<"\t\t**BORRAR ELEMENTO POR ID**\t\t\n";
				eliminarPorID();
				break;
			case 6:
				cout<<"\n\n\t\t			Gracias por preferir el uso de estos programas		\n";
				getch();
				break;
			default:
				cout<<"\n\n\t\t			Por favor, ingrese una opcion valida		\n";
				getch();
				break;
		}
		
	}//del for
	return 0;
}//del main

void insertar()
{
	NODO *temp = new NODO;
	identidad++;
	temp->ID=identidad;
	cout<<"\n\n Ingresa el nombre: ";
	cin>>temp->Nombre;
	cout<<"\n\n Ingresa el domicilio: ";
	cin>>temp->Domicilio;
	cout<<"\n\n Ingresa el peso	";
	cin>>temp->peso;
	temp->SIG=NULL;
	if(cabecero==NULL)
	{
		cabecero=temp;
		cola=temp;
		temp=NULL;
	}
	else
	{
		cola->SIG=temp;
		cola=temp;
	}
	cout<<"\nElmento insertado \n";
	cout<<"\nID por identidad generado: "<<identidad<<endl;
	system("pause");
}

void eliminar()
{
	NODO *actual = new NODO;
	NODO *anterior = new NODO;
	actual = cabecero;
	
	if(cabecero==NULL)
	{
		cout<<"\nLA LISTA ESTA VACIA, NO HAY NADA QUE BORRAR\n";
		system("pause");
		return;
	}
	
	while(actual->SIG!=NULL)
	{
		anterior = actual;
		actual = actual->SIG;
	}
	cout<<"\n El elemento a borrar es ID: ["<<actual->ID<<"] \n";
	cola=anterior;
	anterior->SIG=NULL;
	delete actual;
	cout<<"\nElemento borrado\n";
	system("pause");
}

void eliminarPorID()
{
	NODO *actual = cabecero;
	NODO *anterior = NULL; 
	actual = cabecero;
	
	if(cabecero==NULL)
	{
		cout<<"\nLA LISTA ESTA VACIA, NO HAY NADA QUE BORRAR\n";
		system("pause");
		return;
	}
	
	int ID = 0;
	bool encontrado = false;
	
	cout<<"\nPor favor, dame el ID del elemento a eliminar: ";
	cin>>ID;
	
	while (actual != NULL) 
    {
        if (actual->ID == ID)
        {
            encontrado = true;
            break;
        }
        
        anterior = actual;
        actual = actual->SIG;
    }

    if (!encontrado)
    {
        cout << "\n\nNO SE ENCONTRO NINGUN NODO CON EL ID: " << ID;
        system("pause");
        return;
    }

    cout << "\n El elemento a borrar es ID: [" << actual->ID << "] \n";

    if (anterior == NULL)     
        cabecero = actual->SIG;     
    else     
        anterior->SIG = actual->SIG; // El "puente" para saltar el nodo
    
    if (actual == cola)    
        cola = anterior;     
	    
    delete actual;
    
    cout << "\nElemento borrado\n";
    system("pause");
}

void mostrar()
{
	NODO *temporal = new NODO;
	int cont = 0;
	temporal=cabecero;
	if(temporal==NULL)
		cout<<"\nLA LISTA ESTA VACIA, NO HAY NADA QUE MOSTRAR";
	else
	{
		for(; temporal!=NULL;)
		{
			cont++;
			cout<<"\nElemento no: "<<cont<<"\n";
			cout<<"----------------------------------------";
			cout<<"\n\n ID: ["<<temporal->ID<<"] \t";
			cout<<"\n\n Nombre: ["<<temporal->Nombre<<"] \t";
			cout<<"\n\n Domicilio: ["<<temporal->Domicilio<<"] \t";
			cout<<"\n\n Peso: ["<<temporal->peso<<"] \t";
			cout<<"\n----------------------------------------\n";
			temporal = temporal->SIG;
		}
	}
	cout<<"\n";
	system("pause");
}

void buscarMiembro()
{
	int id_buscado = 0;
	NODO *temporal = cabecero;
    
    bool encontrado = false; 
    
    cout<<"\nDame el ID a buscar: ";
    cin>>id_buscado;

    if (temporal == NULL)
    {
        cout << "\nLA LISTA ESTA VACIA, NO SE PUEDE BUSCAR";
    }
    else
    {
        
        while (temporal != NULL) 
        {
            
            if (temporal->ID == id_buscado)
            {
                cout << "\n\n--- NODO ENCONTRADO ---";
                cout << "\n ID: [" << temporal->ID << "] \t";
                cout << "\n Nombre: [" << temporal->Nombre << "] \t";
                cout << "\n Domicilio: [" << temporal->Domicilio << "] \t";
                cout << "\n Peso: [" << temporal->peso << "] \t";
                
                encontrado = true; 
                break;
            }
            
            
            temporal = temporal->SIG;
        }
    }

    
    if (encontrado == false)
    {
        cout << "\n\nNO SE ENCONTRO NINGUN NODO CON EL ID: " << id_buscado;
    }

    cout << "\n";
    system("pause");
}
