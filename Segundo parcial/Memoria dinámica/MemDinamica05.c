/*MemDinamica05.c
	Funciones de asignacion para memoria dinamica
	Asigna suficiente memoria para almacenar estructuras tipo dir
	Transcibrió: Alejandro Millán Jiménez
	Compiló: Alejandro Millán Jiménez
	Fecha de compilación: 05/11/2025 09:59
	
	*/	
	
#include<stdlib.h>
#include<stdio.h>
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
	p = malloc(sizeof(struct dir));
	
	if(p==NULL)
	{
		printf("Error en la asignacion\n");
		exit(1);
	}
	
	printf("Direccion de memoria donde apunta p: %p en dec: %d \n",p,p);
	p++;
	printf("Si se incrementara en 1 a p: %p en dec: %d\n",p,p);
	free(p);
	
	printf("\n");
	system("pause");
	return 0;
}
