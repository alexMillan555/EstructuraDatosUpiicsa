/*MemDinamica02.c
	Funciones de asignacion para memoria dinamica 
	Asigna memoria para las cadenas introducidas por el usuario y luego las libera
	Transcibrió: Alejandro Millán Jiménez
	Compiló: Alejandro Millán Jiménez
	Fecha de compilación: 04/11/2025 21:41
	
	*/	
	
#include<stdlib.h>
#include<stdio.h>
#define NCAD 5

int main()
{
	char *cad[NCAD];
	int i;
	for(i = 0;i < NCAD; i++)
	{
		if((cad[i] = malloc(128)) == NULL )
		{
			printf("Error de asingacion\n");
			exit(1);
		}
		
		printf("Introduce cadena %d: ", i+1);
		gets(cad[i]);
	}
	
	for(i = 0; i<NCAD; i++)
		printf("%s\n", cad[i]);
	/*Liberar la memoria*/
		
	for(i=0; i<NCAD; i++)
		free(cad[i]);
		
	printf("\n");
	system("pause");
		
	return 0;
}
/*
La funcion malloc() [void *malloc(size_t tam) ] devuelve un apuntador al primer byte de una region de memoria
de tamaño tam asignada del monton. Si no hay memoria suficiente en el monton, para satisfacer la peticion, 
malloc() devuelve un apuntador NULO.
La funcion free() [void free(void *punt); ] devuelve al monton de la memoria apuntada por punt. Esto hace que
esa memoria este disponible para futuras asignaciones. Solo esto debe llamar estrictamente a free() las 
funciones del sistema de asignacion dinamica.
El uso de un apuntador no valido en la llamada, probablemente destruya el mecanismo de gestion de memoria y 
provoque fallo en el sistema
*/
