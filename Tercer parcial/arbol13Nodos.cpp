/*arbol03_13nodos.cpp
	Programa que realiza un árbol con 13 nodos
	Realizó: Alejandro Millán Jiménez
	Compiló: Alejandro Millán Jiménez
	Fecha de compilación: 02/12/2025 21:15
	
	*/	

#include <stdio.h>
#include <stdlib.h>

struct NODO
{
    int DATO;
    struct NODO *IZQ;
    struct NODO *CENTRO;
    struct NODO *DCHO;
};

// Variables globales para los 13 nodos
struct NODO *RAIZ = NULL;
struct NODO *HIJO_I = NULL, *HIJO_C = NULL, *HIJO_D = NULL;  // Nivel 2
struct NODO *II = NULL, *IC = NULL, *ID = NULL;              // Nietos de HIJO_I
struct NODO *CI = NULL, *CC = NULL, *CD = NULL;              // Nietos de HIJO_C
struct NODO *DI = NULL, *DC = NULL, *DD = NULL;              // Nietos de HIJO_D

// Función para crear un nuevo nodo
struct NODO* crearNodo(int valor)
{
    struct NODO* nuevo = new NODO;
    nuevo->DATO = valor;
    nuevo->IZQ = NULL;
    nuevo->CENTRO = NULL;
    nuevo->DCHO = NULL;
    return nuevo;
}

// Función para liberar toda la memoria
void liberarArbol()
{
    // Liberar nietos (nivel 3)
    delete II; delete IC; delete ID;
    delete CI; delete CC; delete CD;
    delete DI; delete DC; delete DD;
    
    // Liberar hijos (nivel 2)
    delete HIJO_I; delete HIJO_C; delete HIJO_D;
    
    // Liberar raíz (nivel 1)
    delete RAIZ;
}

void imprimirArbol()
{
	printf("\n=== REPRESENTACION GRAFICA ===\n");
    printf("                [%d]\n", RAIZ->DATO);
    printf("               /  |  \\\n");
    printf("              /   |   \\\n");
    printf("             /    |    \\\n");
    printf("           [%d]  [%d]  [%d]\n", 
           HIJO_I->DATO, HIJO_C->DATO, HIJO_D->DATO);
    printf("          / | \\  / | \\  / | \\\n");
    printf("        [%d][%d][%d] [%d][%d][%d] [%d][%d][%d]\n",
           II->DATO, IC->DATO, ID->DATO,
           CI->DATO, CC->DATO, CD->DATO,
           DI->DATO, DC->DATO, DD->DATO);
}

int main()
{
	system("color 17");
    int valor;
    
    printf("=== CREACION DE ARBOL DE ORDEN 3 (13 NODOS) ===\n\n");
    
    // ========== NIVEL 1: RAÍZ ==========
    printf("NIVEL 1 - RAIZ\n");
    printf("Dame el valor del nodo raiz: ");
    scanf("%d", &valor);
    RAIZ = crearNodo(valor);
    printf("Raiz creada con valor: %d\n\n", RAIZ->DATO);
    
    // ========== NIVEL 2: HIJOS DE LA RAÍZ ==========
    printf("NIVEL 2 - HIJOS DE LA RAIZ\n");
    
    // Hijo izquierdo
    printf("Dame el valor del hijo izquierdo: ");
    scanf("%d", &valor);
    HIJO_I = crearNodo(valor);
    RAIZ->IZQ = HIJO_I;
    printf("HIJO_I creado: %d\n", HIJO_I->DATO);
    
    // Hijo centro
    printf("Dame el valor del hijo centro: ");
    scanf("%d", &valor);
    HIJO_C = crearNodo(valor);
    RAIZ->CENTRO = HIJO_C;
    printf("HIJO_C creado: %d\n", HIJO_C->DATO);
    
    // Hijo derecho
    printf("Dame el valor del hijo derecho: ");
    scanf("%d", &valor);
    HIJO_D = crearNodo(valor);
    RAIZ->DCHO = HIJO_D;
    printf("HIJO_D creado: %d\n\n", HIJO_D->DATO);
    
    // ========== NIVEL 3: NIETOS ==========
    printf("NIVEL 3 - NIETOS (HIJOS DE HIJO_I)\n");
    
    // Nietos de HIJO_I
    printf("Hijo izquierdo de HIJO_I: ");
    scanf("%d", &valor);
    II = crearNodo(valor);
    HIJO_I->IZQ = II;
    printf("II creado: %d\n", II->DATO);
    
    printf("Hijo centro de HIJO_I: ");
    scanf("%d", &valor);
    IC = crearNodo(valor);
    HIJO_I->CENTRO = IC;
    printf("IC creado: %d\n", IC->DATO);
    
    printf("Hijo derecho de HIJO_I: ");
    scanf("%d", &valor);
    ID = crearNodo(valor);
    HIJO_I->DCHO = ID;
    printf("ID creado: %d\n\n", ID->DATO);
    
    // Nietos de HIJO_C
    printf("NIVEL 3 - NIETOS (HIJOS DE HIJO_C)\n");
    
    printf("Hijo izquierdo de HIJO_C: ");
    scanf("%d", &valor);
    CI = crearNodo(valor);
    HIJO_C->IZQ = CI;
    printf("CI creado: %d\n", CI->DATO);
    
    printf("Hijo centro de HIJO_C: ");
    scanf("%d", &valor);
    CC = crearNodo(valor);
    HIJO_C->CENTRO = CC;
    printf("CC creado: %d\n", CC->DATO);
    
    printf("Hijo derecho de HIJO_C: ");
    scanf("%d", &valor);
    CD = crearNodo(valor);
    HIJO_C->DCHO = CD;
    printf("CD creado: %d\n\n", CD->DATO);
    
    // Nietos de HIJO_D
    printf("NIVEL 3 - NIETOS (HIJOS DE HIJO_D)\n");
    
    printf("Hijo izquierdo de HIJO_D: ");
    scanf("%d", &valor);
    DI = crearNodo(valor);
    HIJO_D->IZQ = DI;
    printf("DI creado: %d\n", DI->DATO);
    
    printf("Hijo centro de HIJO_D: ");
    scanf("%d", &valor);
    DC = crearNodo(valor);
    HIJO_D->CENTRO = DC;
    printf("DC creado: %d\n", DC->DATO);
    
    printf("Hijo derecho de HIJO_D: ");
    scanf("%d", &valor);
    DD = crearNodo(valor);
    HIJO_D->DCHO = DD;
    printf("DD creado: %d\n\n", DD->DATO);
    
    system("cls");
    // ========== MOSTRAR ÁRBOL ==========
    printf("\n=== ESTRUCTURA DEL ARBOL ===\n");
    printf("Total de nodos: 13\n\n");
    
    printf("NIVEL 1 (Raiz):\n");
    printf("        [%d]\n", RAIZ->DATO);
    
    printf("\nNIVEL 2 (Hijos):\n");
    printf("    [%d]    [%d]    [%d]\n", 
           HIJO_I->DATO, HIJO_C->DATO, HIJO_D->DATO);
    
    printf("\nNIVEL 3 (Nietos):\n");
    printf("[%d][%d][%d]  [%d][%d][%d]  [%d][%d][%d]\n",
           II->DATO, IC->DATO, ID->DATO,
           CI->DATO, CC->DATO, CD->DATO,
           DI->DATO, DC->DATO, DD->DATO);
    
    printf("\n=== RELACIONES DETALLADAS ===\n");
    printf("Raiz (%d) -> Hijos: %d | %d | %d\n", 
           RAIZ->DATO, RAIZ->IZQ->DATO, RAIZ->CENTRO->DATO, RAIZ->DCHO->DATO);
    
    printf("HIJO_I (%d) -> Hijos: %d | %d | %d\n",
           HIJO_I->DATO, HIJO_I->IZQ->DATO, HIJO_I->CENTRO->DATO, HIJO_I->DCHO->DATO);
    
    printf("HIJO_C (%d) -> Hijos: %d | %d | %d\n",
           HIJO_C->DATO, HIJO_C->IZQ->DATO, HIJO_C->CENTRO->DATO, HIJO_C->DCHO->DATO);
    
    printf("HIJO_D (%d) -> Hijos: %d | %d | %d\n",
           HIJO_D->DATO, HIJO_D->IZQ->DATO, HIJO_D->CENTRO->DATO, HIJO_D->DCHO->DATO);
    
    // ========== MOSTRAR REPRESENTACIÓN GRÁFICA ==========
    imprimirArbol();
    
    // ========== CALCULAR SUMA DE VALORES ==========
    int suma = RAIZ->DATO + 
               HIJO_I->DATO + HIJO_C->DATO + HIJO_D->DATO +
               II->DATO + IC->DATO + ID->DATO +
               CI->DATO + CC->DATO + CD->DATO +
               DI->DATO + DC->DATO + DD->DATO;
    
    printf("\n=== INFORMACION ADICIONAL ===\n");
    printf("Suma de todos los valores: %d\n", suma);
    printf("Promedio de valores: %.2f\n", (float)suma / 13);
    
    system("pause");
    
    // ========== MENÚ DE ACCESO ==========
    
    int opcion = 0;
    do
    {
    	system("cls");
    	
	    printf("\n=== ACCESO A NODOS ===\n");
	    printf("1. Mostrar raiz\n");
	    printf("2. Mostrar hijos directos\n");
	    printf("3. Mostrar todos los nietos\n");
	    printf("4. Mostrar todo el arbol\n");
	    printf("5. Salir\n");
	    printf("Seleccione opcion: ");
	    scanf("%d", &opcion);
    	switch(opcion)
	    {
	        case 1:
	        	system("cls");
	        	printf("\t\t**Mostrar raiz**\t\t\n");
	            printf("Raiz: %d\n", RAIZ->DATO);
	            system("pause");
	            break;
	        case 2:
	        	system("cls");
	        	printf("\t\t**Mostrar hijos directos\t\t\n");
	            printf("Hijos: %d, %d, %d\n", 
	                   HIJO_I->DATO, HIJO_C->DATO, HIJO_D->DATO);
	            system("pause");
	            break;
	        case 3:
	        	system("cls");
	        	printf("\t\t**Mostrar todos los nietos\t\t\n");
	            printf("Nietos (HIJO_I): %d, %d, %d\n", II->DATO, IC->DATO, ID->DATO);
	            printf("Nietos (HIJO_C): %d, %d, %d\n", CI->DATO, CC->DATO, CD->DATO);
	            printf("Nietos (HIJO_D): %d, %d, %d\n", DI->DATO, DC->DATO, DD->DATO);
	            system("pause");
	            break;
	        case 4:
	        	system("cls");
	        	printf("\t\t**Mostrar todo el arbol**\t\t\n");
	            printf("Arbol completo:\n");
	            printf("Raiz: %d\n", RAIZ->DATO);
	            printf("Hijos: %d | %d | %d\n", 
	                   HIJO_I->DATO, HIJO_C->DATO, HIJO_D->DATO);
	            printf("Nietos: ");
	            printf("%d,%d,%d | ", II->DATO, IC->DATO, ID->DATO);
	            printf("%d,%d,%d | ", CI->DATO, CC->DATO, CD->DATO);
	            printf("%d,%d,%d\n", DI->DATO, DC->DATO, DD->DATO);
	            
	            printf("\n");
	            imprimirArbol();
	            printf("\n");
	            system("pause");
	            break;
	        case 5:
	        	printf("Saliendo...\n");
	        	break;
	        default:
	            printf("Opcion incorrecta, por favor seleccione una opcion valida...\n");
	            system("pause");
	            break;
	    }
	}while(opcion!=5);
    
    // ========== LIBERAR MEMORIA ==========
    liberarArbol();
    printf("\nMemoria liberada correctamente.\n");
    
    system("pause");
    return 0;
}
