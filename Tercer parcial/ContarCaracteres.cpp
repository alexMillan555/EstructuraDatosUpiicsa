/*ContarCaracteres.cpp
	Conteo de caracteres recursivo y con apuntadores que busca la letra 'a' en una cadena dada
	Realizó: Alejandro Millán Jiménez
	Compiló: Alejandro Millán Jiménez
	Fecha de compilación: 02/12/2025 21:30
	
	*/	
#include <stdio.h>

// Contar apariciones de un carácter en una cadena (recursivo)
int contar_caracter(char *cadena, char caracter)
{
    // CASO BASE: fin de cadena
    if (*cadena == '\0')
        return 0;
    
    // CASO RECURSIVO: sumar 1 si coincide + procesar resto
    int suma = (*cadena == caracter) ? 1 : 0;
    return suma + contar_caracter(cadena + 1, caracter);
}

// Versión con apuntadores adicional para posición
int contar_desde_posicion(char *inicio, char *actual, char caracter)
{
    // CASO BASE: llegamos al final
    if (*actual == '\0')
        return 0;
    
    // Contar en posición actual + procesar siguiente
    int contador = (*actual == caracter) ? 1 : 0;
    
    // Mostrar información de depuración
    printf("Posicion %ld: '%c' %s\n", 
           actual - inicio, 
           *actual,
           (*actual == caracter) ? "-> Coincide!" : "");
    
    return contador + contar_desde_posicion(inicio, actual + 1, caracter);
}

int main()
{
    char texto[] = "UPIICSA Informatica Alejandro";
    char buscar = 'a';
    
    printf("Cadena: \"%s\"\n", texto);
    printf("Contando '%c' de forma recursiva...\n", buscar);
    
    int resultado = contar_caracter(texto, buscar);
    printf("Resultado simple: %d apariciones\n\n", resultado);
    
    printf("Contando con informacion de posicion:\n");
    resultado = contar_desde_posicion(texto, texto, buscar);
    printf("Total: %d apariciones del caracter '%c'\n", resultado, buscar);
    
    return 0;
}
