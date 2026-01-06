#include <iostream>
#include <stdlib.h> 

using namespace std;

// ==========================================
//    ESTRUCTURAS DEL GRAFO
// ==========================================

// 1. ESTRUCTURA PARA EL NODO DE LA LISTA DE ADYACENCIA
struct Nodo 
{
    int destino;        // A qué vértice (ID) conecta
    Nodo* siguiente;    // Puntero al siguiente vecino
};

// 2. ESTRUCTURA PARA EL GRAFO
struct Grafo 
{
    int numVertices; // Tamaño total (ej. 6 nodos)
    Nodo** listasAdyacencia; // Un ARREGLO de PUNTEROS. Cada casilla del arreglo es el inicio de una lista enlazada.
    bool* visitado;          // Un arreglo de falsos/verdaderos para saber si ya pasamos por ahí.
};

// ==========================================
//    ESTRUCTURA: COLA MANUAL (FIFO)
// ==========================================

struct NodoCola 
{
    int datoID; // El dato importante: El ID del vértice (ej. 0, 1, 5)
    NodoCola* siguiente; // El enlace: Apunta a la persona que está detrás en la fila
};

struct ColaManual 
{
    NodoCola* frente; // El nodo que está hasta el frente
    NodoCola* final;  // El último nodo que está hasta el frente
};

// --- FUNCIONES DE LA COLA MANUAL ---


//Se inicializa la cola en NULL 
void inicializarCola(ColaManual& c) 
{
    c.frente = NULL; 
    c.final = NULL;
}

//Comprueba si la cola está vacía
bool colaVacia(ColaManual& c) 
{
    return (c.frente == NULL); 
}

void encolar(ColaManual& c, int id) 
{
	// 1. Creamos el nodo nuevo
    NodoCola* nuevo = new NodoCola;
    nuevo->datoID = id;
    nuevo->siguiente = NULL;

	// 2. Si la fila está vacía, se inserta el primer nodo
    if (colaVacia(c)) 
    {
        c.frente = nuevo;
        c.final = nuevo;
    } // 3. Si ya hay nodos, lo ponemos DETRÁS del que era el último
    else 
    {
        c.final->siguiente = nuevo; // El último ahora apunta al nuevo
        c.final = nuevo; // Actualizamos la etiqueta "final" al nuevo
    }
}

int desencolar(ColaManual& c) 
{
    if (colaVacia(c)) 
        return -1;
	// 1. Guardamos el primer nodo (para no perder el dato)
    int id = c.frente->datoID;
    
    // 2. Guardamos la dirección de memoria para borrarla luego
    NodoCola* temp = c.frente;
    
    // 3. El "frente" ahora es la SEGUNDA persona de la fila
    c.frente = c.frente->siguiente;
	
	// 4. Si la fila se quedó vacía, aseguramos que "final" sea NULL también
    if (c.frente == NULL) 
        c.final = NULL;     

    delete temp; //Liberamos la memoria (Muy importante en C++)
    return id; // Retornamos el ID de quien atendimos
}

// Recibe 'ColaManual c' por VALOR (una copia), así que no rompemos la original
void mostrarColaManual(ColaManual c) 
{
	// Cremos un puntero temporal 'temp' que apunta al inicio de la fila (frente).
    // Usamos 'temp' para recorrerla sin perder la referencia del inicio real.
    NodoCola* temp = c.frente;
    cout << "   [COLA ACTUAL]: { ";
    
    // Si el frente es NULL, no hay nadie formado.
    if (temp == NULL) 
        cout << "VACIA ";
    
    // Bucle: Mientras 'temp' apunte a algo válido (no sea NULL)...
    while (temp != NULL) 
    {
        cout << temp->datoID << " "; // Imprimimos el ID de la persona
        temp = temp->siguiente; // Movemos 'temp' al siguiente en la fila
    }
    cout << "}";
}

// ==========================================
//    FUNCIONES DEL GRAFO
// ==========================================

Nodo* crearNodo(int destino) 
{
	// 1. Pide memoria al sistema operativo para un nuevo bloque 'Nodo'.
    // 'new' devuelve la dirección de memoria donde se creó.
    
    // 2. Rellena los datos del bloque.
    Nodo* nuevoNodo = new Nodo;
    
    // Guardamos con quién conecta (el vecino)
    nuevoNodo->destino = destino;
    
    // 3. Importante: Inicializamos el puntero en NULL por seguridad.
    // Al principio, este nodo no apunta a nadie más en la lista de vecinos.
    nuevoNodo->siguiente = NULL;
    
    // 4. Entregamos el nodo nuevo listo para usarse.
    return nuevoNodo;
}

Grafo* crearGrafo(int vertices) 
{
	// 1. Crea la estructura principal del Grafo
    Grafo* grafo = new Grafo;
    
    // 2. Guarda cuántos nodos tendrá (ej. 6)
    grafo->numVertices = vertices;
    
    // 3. Crea el ARREGLO DE LISTAS (Adyacencia).
    // Es un arreglo de punteros (Nodo**). Cada casilla será la cabeza de una lista.
    grafo->listasAdyacencia = new Nodo*[vertices];
    
    // 4. Crea el ARREGLO DE VISITADOS.
    // Un simple arreglo de booleanos para marcar por dónde ya pasamos.
    grafo->visitado = new bool[vertices];
    
    // 5. LIMPIEZA INICIAL (Paso Crítico)
    // La memoria recién creada puede tener "basura" electrónica.
    // Debemos poner todo en NULL y false explícitamente.
    for (int i = 0; i < vertices; i++) 
    {
        grafo->listasAdyacencia[i] = NULL; // Nadie tiene hijos todavía
        grafo->visitado[i] = false; // Nadie ha sido visitado
    }
    return grafo; // Devuelve el grafo vacío y limpio
}

// [NUEVO] Función auxiliar para insertar ORDENADAMENTE en una lista enlazada
// Esto garantiza que si metes vecinos (5, 1, 3), la lista quede: 1 -> 3 -> 5
void insertarOrdenado(Nodo*& cabeza, int destino) 
{
    Nodo* nuevo = crearNodo(destino);
    
    // CASO A: Insertar al principio
    // Si la lista está vacía O si el nuevo es MENOR que el primero (ej. meter 1 antes de 5)
    if (cabeza == NULL || cabeza->destino >= destino) 
    {
        nuevo->siguiente = cabeza;
        cabeza = nuevo;
    }
    else // CASO B: Insertar en medio o al final
    {
        // Caso 2: Buscar la posición correcta en medio o al final
        Nodo* actual = cabeza;
        // Caminamos mientras el siguiente sea MENOR que el nuestro.
        // Ej: Tenemos 1->5->9. Queremos meter 6.
        // ¿5 < 6? Sí, avanza. ¿9 < 6? No, detente ahí.
        while (actual->siguiente != NULL && actual->siguiente->destino < destino)
        {
            actual = actual->siguiente;
        }
        // "Costuramos" los punteros para meterlo en medio
        nuevo->siguiente = actual->siguiente;
        actual->siguiente = nuevo;
    }
}

// [MODIFICADO] Ahora usa insertarOrdenado en lugar de inserción simple
void agregarArista(Grafo* grafo, int origen, int destino) 
{
    // Validar que los nodos existan para evitar errores de memoria
    if (origen >= grafo->numVertices || destino >= grafo->numVertices || origen < 0 || destino < 0) 
    {
        cout << "   [ERROR]: Nodo invalido (" << origen << " o " << destino << "). Se ignora.\n";
        return;
    }

    // 1. Agregamos arista de origen -> destino (Ordenado)
    insertarOrdenado(grafo->listasAdyacencia[origen], destino);

    // 2. Como es grafo NO dirigido, agregamos destino -> origen (Ordenado)
    insertarOrdenado(grafo->listasAdyacencia[destino], origen);
}

// --- FUNCIONES VISUALES DEL GRAFO ---

// [NUEVO] Función para dibujar el grafo de forma rudimentaria en consola
// Intenta imitar una estructura visual usando caracteres ASCII
void dibujarGrafo(Grafo* grafo)
{
    cout << "\n   === REPRESENTACION GRAFICA (VISUAL) ===\n";
    cout << "   (Las lineas indican conexion directa)\n\n";
	
	// Recorremos cada nodo principal (0, 1, 2...)
    for (int i = 0; i < grafo->numVertices; i++)
    {
        // Dibujamos el Nodo Principal
        cout << "   [" << i << "]";
        
        Nodo* temp = grafo->listasAdyacencia[i];
        
        // Si no tiene hijos
        if(temp == NULL) 
		{
            cout << " (Aislado)\n";
            cout << "\n"; // Espacio extra
            continue;
        }

        // Si tiene hijos, dibujamos las "ramas"
        // Primer hijo (misma línea)
        cout << "-------> [" << temp->destino << "]\n";
        temp = temp->siguiente;

        // Resto de hijos (líneas abajo)
        while(temp != NULL)
        {
            cout << "    | \n"; // Tallo vertical
            cout << "    +------> [" << temp->destino << "]\n"; // Rama
            temp = temp->siguiente;
        }
        cout << "\n"; // Separador entre nodos
    }
    cout << "   =======================================\n";
}

void mostrarConexiones(Grafo* grafo) 
{
    cout << "\n   TABLA DE CONEXIONES (Adyacencia Ordenada):\n";
    cout << "   ----------------------------------------\n";
    
    // Bucle externo: Recorre cada nodo principal (0, 1, 2...)
    // Es decir, recorre el arreglo verticalmente.
    for (int i = 0; i < grafo->numVertices; i++) 
    {
        cout << "   Nodo [" << i << "] conecta con -> ";
        
        // Obtenemos el inicio de la lista de amigos del nodo 'i'
        Nodo* temp = grafo->listasAdyacencia[i];
        
        // Caso especial: Si el puntero es NULL, no tiene amigos.
        if (temp == NULL) 
            cout << "(Sin conexiones)";
        
        // Bucle interno: Recorre la lista enlazada horizontalmente.
        // Mientras haya nodos en la lista...
        while (temp) 
        {
            cout << "[" << temp->destino << "] "; // Imprime al vecino
            temp = temp->siguiente; // Salta al siguiente vecino
        }
        cout << "\n"; // Salto de línea al terminar con el nodo 'i'
    }
    cout << endl;
}

// ==========================================
//    ALGORITMO BFS VISUAL
// ==========================================

void bfsVisual(Grafo* grafo, int nodoInicio) 
{
    // 1. Preparamos la cola y metemos el inicio
    if (nodoInicio < 0 || nodoInicio >= grafo->numVertices) 
    {
        cout << "   [ERROR]: El nodo de inicio no existe.\n";
        return;
    }

    ColaManual cola;
    inicializarCola(cola);

    grafo->visitado[nodoInicio] = true; // ¡Importante! Marcarlo para no repetir
    encolar(cola, nodoInicio); 

    cout << "==========================================\n";
    cout << "   INICIANDO ALGORITMO BFS (Paso a Paso)\n";
    cout << "==========================================\n";
    cout << "   Inicio en nodo: " << nodoInicio << "\n";
    
    int paso = 1;
	
	// 2. BUCLE PRINCIPAL: Mientras haya alguien en la fila...
    while (!colaVacia(cola)) 
    {
        cout << "\n------------------------------------------\n";
        cout << "   PASO " << paso++ << ":\n";
        
        // Mostramos cómo se ve la cola en este instante
        mostrarColaManual(cola); 
        cout << "\n";
	
		// Sacamos al primero de la fila para "procesarlo"
        int nodoActual = desencolar(cola);

        cout << "   -> Visitando nodo [" << nodoActual << "]\n";
        cout << "   -> Buscando vecinos...\n";

        // Como usamos insertarOrdenado, los vecinos saldrán de menor a mayor automáticamente
        
        // 3. BUCLE DE HIJOS: Revisamos todos los HIJOS del nodo actual
        Nodo* temp = grafo->listasAdyacencia[nodoActual];
        while (temp != NULL) 
        {
            int nodoVecino = temp->destino;
            
            cout << "      * Vecino [" << nodoVecino << "]... ";
			
			// Si el vecino NO ha sido visitado...
            if (!grafo->visitado[nodoVecino]) 
            {
                cout << "NUEVO. A la cola.\n";
                grafo->visitado[nodoVecino] = true; // Lo marcamos
                encolar(cola, nodoVecino); // Lo mandamos a la fila
            } 
            else 
                cout << "Ya visitado.\n";
            
            temp = temp->siguiente; // Pasamos al siguiente hijo
        }
        
        cout << "\n   [ENTER] para continuar..."; 
        // system("pause");  // Descomentar en Windows
        cin.ignore(); // Pausa portable simple
        cin.get();
    }
    cout << "\n==========================================\n";
    cout << "   RECORRIDO FINALIZADO\n";
    cout << "==========================================\n";
}

// --- MAIN [MODIFICADO PARA INPUT DE USUARIO] ---

int main() 
{
    system("color 17"); 
    
    int numNodos, origen, destino, nodoInicio;

    cout << "========================================\n";
    cout << "   CONFIGURACION DEL GRAFO DINAMICO\n";
    cout << "========================================\n";
    
    // 1. Pedir cantidad de nodos
    do 
    {
        cout << "Ingrese la cantidad total de nodos (ej. 6): ";
        cin >> numNodos;

        if (numNodos <= 0)          
            cout << "Error: Debe haber al menos 1 nodo.\n";             
        
    } 
    while(numNodos <=0);
    
    system("cls");
    cout << "========================================\n";
    cout << "   CONFIGURACION DEL GRAFO DINAMICO\n";
    cout << "========================================\n";
    
    Grafo* miRed = crearGrafo(numNodos);

    // 2. Bucle para ingresar conexiones
    cout << "\n--- INGRESO DE CONEXIONES ---\n";
    cout << "Los nodos van del ID 0 al " << numNodos - 1 << ".\n";
    cout << "Ingrese origen y destino separados por espacio.\n";
    cout << "Escriba '-1 -1' para terminar.\n\n";

    while (true)
    {
        cout << "\nIngresa el nodo origen: ";
        cin >> origen;
        cout << "Ingresa el nodo destino: ";
        cin >> destino;

        // Condición de salida
        if (origen == -1 || destino == -1) 
            break;

        // Validaciones básicas de rango
        if (origen >= 0 && origen < numNodos && destino >= 0 && destino < numNodos) 
        {
            agregarArista(miRed, origen, destino);
            cout << "   -> Conexion agregada (ordenada automaticamente).\n";
        } 
        else 
            cout << "   -> [ALERTA] IDs fuera de rango (0 a " << numNodos-1 << ")\n";
        
    }

    // 3. Mostrar la nueva gráfica rudimentaria
    system("cls"); // O system("clear") en Linux/Mac
    
    // [MODIFICADO] Llamamos a la nueva función gráfica en lugar de solo la tabla
    dibujarGrafo(miRed); 

    // Opcional: Si aun quieres ver la tabla clásica, descomenta la siguiente linea:
    // mostrarConexiones(miRed); 

    // 4. Pedir nodo de inicio para el BFS
    cout << "Ingrese el ID del nodo donde iniciara el BFS: ";
    cin >> nodoInicio;

    cout << "\nPresiona ENTER para iniciar la simulacion...\n";
    cin.ignore(); 
    cin.get();
    
    system("cls");

    // 5. Ejecutar Algoritmo
    bfsVisual(miRed, nodoInicio);

    return 0;
}
