/*Arreglos04.cpp
	manejo de enteros con arreglos bidimensionales implementando el ordenamiento de burbuja
	Transcibrió: Alejandro Millán Jiménez
	Compiló: Alejandro Millán Jiménez
	Fecha de compilación: 21/10/2025 18:25
	
	*/	
#include <iostream> 
#include <string.h> 
#define COL 3
#define RENG 7
using namespace std; 
int main()
{
	int dcb[COL][RENG], j, i, a, x,opc,pru;
	cout<<"\n\tIMPLEMENTACION DEL ALGORITMO BURBUJA EN ARREGLO BIDIMENSIONAL PARA CUALQUIER COLUMNA\n";
	for(j=0;j<COL;j++)
	{
		cout<<"\nColumna "<<j+1<<"\n"; 
		for(i=0;i<RENG;i++)
		{
			cout<<"["<<j<<"]"<<"["<<i<<"]: ";
			cin>>dcb[j][i]; 
		}
	}
	
	cout<<"\nDesde que opcion desea ordenar (0,1,2)?:\n \t0. COLUMNA A \n\t1.COLUMNA B \n\t2. COLUMNA C\n";
	cin>>opc;
	for(i=0;i<RENG;i++)
	{
		for(a=i+1;a<RENG;a++)
		{
			if(dcb[opc][i]>dcb[opc][a])
			{
				x=dcb[opc][a]; 
				dcb[opc][a]=dcb[opc][i]; 
				dcb[opc][i]=x;
				for(j=0;j<COL;j++)
				{
					if(opc<j || opc > j)
					{
						pru= dcb[j][a]; 
						dcb[j][a] = dcb[j][i];
						dcb[j][i] = pru;
					}
				}
				
			}
			
		
		}
		
	}
	
	for(i=0;i<RENG;i++)
	{
		for(j=0;j<COL;j++)		
			cout<<"["<<j<<"]"<<"["<<i<<"]  "<<dcb[j][i] <<"\t";		
		cout<<"\n"; 
	}
	return 0;	
}


