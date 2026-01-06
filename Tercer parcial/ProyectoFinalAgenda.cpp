#include <iostream>
#include <stdlib.h> 
#include <string.h> // Para strcpy
#include <fstream>  // Para manejo de archivos (leer la matriz)

using namespace std;

// ==========================================
//    AGENDA DE CONTACTOS
// ==========================================

const int MAX_USUARIOS = 100; 

// 1. ESTRUCTURA DEL NODO DE LA LISTA DE ADYACENCIA
struct NodoAmigo
{
    int idUsuario;
    NodoAmigo* siguiente;
};

// 2. ESTRUCTURA PARA EL USUARIO
struct Usuario 
{
    char nombre[60]; // [CAMBIO] Aumentamos de 30 a 60 para que quepan los cargos
};

// 3. ESTRUCTURA DE LA RED SOCIAL (GRAFO)
struct RedSocial 
{
    int totalUsuarios;
    Usuario infoUsuarios[MAX_USUARIOS];
    NodoAmigo* listaAmigos[MAX_USUARIOS]; 
    bool visitado[MAX_USUARIOS];
    int distancia[MAX_USUARIOS];
};

// --- AQUÍ ESTÁ LA COLA MANUAL (SIN <QUEUE>) ---

struct NodoCola 
{
    int datoID;
    NodoCola* siguiente;
};

struct ColaManual 
{
    NodoCola* frente; // Donde salen los datos
    NodoCola* final;  // Donde entran los datos
};

// ==========================================
//    FUNCIONES DE LA COLA MANUAL
// ==========================================

void inicializarCola(ColaManual& c)
{
    c.frente = NULL;
    c.final = NULL;
}

bool colaVacia(ColaManual& c) 
{
    return (c.frente == NULL);
}

void encolar(ColaManual& c, int id) 
{
    // 1. Crear nuevo nodo
    NodoCola* nuevo = new NodoCola;
    nuevo->datoID = id;
    nuevo->siguiente = NULL;

    // 2. Si está vacía, frente y final son el nuevo nodo
    if (colaVacia(c)) 
    {
        c.frente = nuevo;
        c.final = nuevo;
    } 
    else 
    {
        // 3. Si no, lo ponemos detrás del último
        c.final->siguiente = nuevo;
        c.final = nuevo;
    }
}

int desencolar(ColaManual& c) 
{
    if (colaVacia(c)) return -1;

    // 1. Guardar el dato del frente
    int id = c.frente->datoID;
    
    // 2. Mover el frente al siguiente nodo
    NodoCola* temp = c.frente;
    c.frente = c.frente->siguiente;

    // 3. Si al quitar quedó vacía, ajustar final
    if (c.frente == NULL) 
        c.final = NULL;
    
    // 4. Liberar memoria
    delete temp;
    return id;
}

// Función visual para ver quién está formado
void mostrarEstadoCola(ColaManual c) 
{
    NodoCola* temp = c.frente;
    cout << "   [COLA]: FRENTE <| ";
    if (temp == NULL) cout << "Vacia";
    while (temp != NULL)
    {
        cout << "[" << temp->datoID << "] ";
        temp = temp->siguiente;
    }
    cout << "|< FINAL\n";
}

// ==========================================
//    FUNCIONES DEL GRAFO Y ARCHIVOS
// ==========================================

// Inicializar punteros en NULL
void inicializarRed(RedSocial* red) 
{
    red->totalUsuarios = 0;
    for (int i = 0; i < MAX_USUARIOS; i++) 
        red->listaAmigos[i] = NULL;
    
}

// Agrega una conexión (Arista) a la lista enlazada
void conectarAmigosInterno(RedSocial* red, int idOr, int idDes) 
{
    // [COMENTARIO NUEVO]: Esta función agrega nodos al PRINCIPIO de la lista.
    // Por eso, si el archivo dice Ana(1) y luego Luis(2), la lista quedará: Luis -> Ana.
    // Esto es normal en listas enlazadas simples (inserción O(1)).
    NodoAmigo* nuevo = new NodoAmigo;
    nuevo->idUsuario = idDes;
    nuevo->siguiente = red->listaAmigos[idOr];
    red->listaAmigos[idOr] = nuevo;
}

// --- FUNCIÓN DE CARGA DESDE ARCHIVO (MATRIZ) ---
bool cargarDesdeArchivo(RedSocial* red, const char* nombreArchivo) 
{
    ifstream archivo(nombreArchivo); // Abrir archivo para lectura
    
    if (!archivo.is_open()) 
        return false; // Error si no existe

    // 1. Leer cantidad de usuarios
    archivo >> red->totalUsuarios;
    archivo.ignore(); // Limpiar el buffer del salto de línea

    // 2. Leer nombres de usuarios
    for (int i = 0; i < red->totalUsuarios; i++)     
        archivo.getline(red->infoUsuarios[i].nombre, 60); // [CAMBIO] Aquí también ponemos 60    

    // 3. Leer la MATRIZ DE ADYACENCIA y convertirla a LISTA
    int conexion;
    cout << "\n   --> Leyendo Matriz de Adyacencia del archivo...\n";
    
    // [COMENTARIO NUEVO]: Aquí usamos 'fila' y 'columna' para entender mejor la matriz.
    // El ciclo NO es reiterativo innecesariamente: Una matriz es NxN datos,
    // necesitamos recorrer TODAS las casillas para saber dónde hay un 1 y dónde un 0.
    
    for (int fila = 0; fila < red->totalUsuarios; fila++) 
    {
        for (int columna = 0; columna < red->totalUsuarios; columna++) 
        {
            archivo >> conexion; // Lee el dato (0 o 1) de la matriz en el archivo
            
            if (conexion == 1)
             {
                // Si encontramos un 1 en la posición [fila][columna], significa que
                // el usuario 'fila' es amigo del usuario 'columna'.
                // Lo agregamos a nuestra estructura de grafos.
                conectarAmigosInterno(red, fila, columna);
            }
        }
    }
    
    archivo.close();
    return true;
}

// [NUEVO SEGMENTO DE CÓDIGO]: Función para mostrar visualmente las conexiones
// Esto satisface tu petición de mostrar "cada persona con su respectiva conexión"
// antes de iniciar el algoritmo BFS.
void imprimirListaDeConexiones(RedSocial* red)
{
    cout << "\n   ========================================\n";
    cout << "      LISTA DE AMIGOS (ESTADO DEL GRAFO)\n";
    cout << "   ========================================\n";

    for (int i = 0; i < red->totalUsuarios; i++)
    {
        cout << "   Usuario [" << i << "] " << red->infoUsuarios[i].nombre << " conecta con: ";
        
        NodoAmigo* actual = red->listaAmigos[i];
        if (actual == NULL) 
        {
            cout << "(Sin amigos)";
        }

        while (actual != NULL)
        {
            // Imprimimos el nombre del amigo conectado
            int idAmigo = actual->idUsuario;
            cout << " -> [" << red->infoUsuarios[idAmigo].nombre << "]";
            actual = actual->siguiente;
        }
        cout << "\n";
    }
    cout << "\n";
}

// Función auxiliar para crear el archivo si no existe
void generarArchivoEjemplo() 
{
    ofstream archivo("red_social.txt");
    if (archivo.is_open()) 
    {
        archivo << "6\n"; // 6 empleados
        
        // [CAMBIO] Aquí ponemos los Nombres + Cargos
        archivo << "Yo (Desarrollador)\n";        // ID 0
        archivo << "Ana (Jefa de Proyecto)\n";       // ID 1
        archivo << "Luis (Gerente de Area)\n";       // ID 2
        archivo << "Pepe (Director Operativo)\n";    // ID 3
        archivo << "Jorge (Director General)\n";      // ID 4
        archivo << "Elon Musk (CEO)\n";              // ID 5

        // Matriz de conexiones (Jerarquía + Atajos)
        // Imagina:
        // Yo -> Ana (Jefa) y Luis (Gerente - Atajo)
        // Ana -> Pepe (Director)
        // Luis -> Jefe (Director General - Atajo Grande)
        // Pepe -> Elon Musk (CEO)
        
        //       0 1 2 3 4 5
        archivo << "0 1 1 0 0 0\n"; // 0 (Yo) conecta con Ana y Luis
        archivo << "1 0 0 1 0 0\n"; // 1 (Ana) conecta con Yo y Pepe
        archivo << "1 0 0 0 1 0\n"; // 2 (Luis) conecta con Yo y Director General (Atajo)
        archivo << "0 1 0 0 0 1\n"; // 3 (Pepe) conecta con Ana y Elon
        archivo << "0 0 1 0 0 0\n"; // 4 (Dir. General) conecta con Luis
        archivo << "0 0 0 1 0 0\n"; // 5 (Elon) conecta con Pepe
        
        archivo.close();
        cout << "   [SISTEMA]: Se ha actualizado la 'Agenda Empresarial'.\n";
    }
}

// ==========================================
//    ALGORITMO BFS VISUAL (SIN LIBRERÍA)
// ==========================================

int bfsVisual(RedSocial* red, int idOrigen, int idDestino) 
{
    // 1. Limpiar memoria del algoritmo
    for (int i = 0; i < red->totalUsuarios; i++) 
    {
        red->visitado[i] = false;
        red->distancia[i] = -1;
    }

    // 2. Usar nuestra COLA MANUAL
    ColaManual cola;
    inicializarCola(cola);

    // Configuración inicial
    red->visitado[idOrigen] = true;
    red->distancia[idOrigen] = 0;
    encolar(cola, idOrigen);

    cout << "\n   ===============================================\n";
    cout << "      INICIANDO BFS (Buscando camino mas corto)\n";
    cout << "   ===============================================\n";
    
    int pasos = 1;

    // 3. Bucle Principal
    while (!colaVacia(cola)) 
    {
        cout << "\n   --- PASO " << pasos++ << " ---\n";
        mostrarEstadoCola(cola); 

        // Sacar de la cola manual
        int idActual = desencolar(cola);
        cout << "   -> Atendiendo a: [" << red->infoUsuarios[idActual].nombre << "] (ID: " << idActual << ")\n";

        // Verificar si llegamos
        if (idActual == idDestino) 
        {
            cout << "\n   [EXITO]: Destino encontrado!\n";
            return red->distancia[idDestino];
        }

        // Explorar vecinos
        cout << "      Explorando contactos: ";
        NodoAmigo* temp = red->listaAmigos[idActual];
        
        while (temp != NULL) 
        {
            int vecino = temp->idUsuario;

            if (!red->visitado[vecino]) 
            {
                red->visitado[vecino] = true;
                red->distancia[vecino] = red->distancia[idActual] + 1;
                encolar(cola, vecino); 
                cout << "\t\t\n - " << red->infoUsuarios[vecino].nombre << " ";
            }
            temp = temp->siguiente;
        }
        cout << "\n\n";
        system("pause"); 
    }

    return -1; // No se encontró
}

// ==========================================
//    FUNCIÓN PRINCIPAL
// ==========================================

int main() 
{
    system("color 17"); // [CAMBIO] Color azul brillante (más legible)
    
    // 1. Generar el archivo si no existe
    generarArchivoEjemplo();

    RedSocial facebook;
    inicializarRed(&facebook);

    // 2. Cargar datos del archivo
    cout << "   [SISTEMA]: Cargando base de datos desde 'red_social.txt'...\n";
    
    // [NOTA]: La función ahora usa internamente lógica de filas y columnas claras
    if (cargarDesdeArchivo(&facebook, "red_social.txt")) 
    {
        cout << "   [SISTEMA]: Grafo cargado correctamente.\n";
        cout << "   [DATOS]: Total usuarios leidos: " << facebook.totalUsuarios << "\n";
    } 
    else 
    {
        cout << "   [ERROR]: No se pudo leer el archivo.\n";
        return 1;
    }

    // [NUEVO] Mostrar gráficamente las conexiones antes de empezar
    imprimirListaDeConexiones(&facebook);

    system("pause"); // Pausa para que el usuario pueda leer la lista

    // 3. Definir búsqueda
    int idOrigen = 0; // Yo
    int idObjetivo = 5; // Elon Musk

    cout << "\n   [META]: Calcular distancia de: " << facebook.infoUsuarios[idOrigen].nombre 
         << " --> " << facebook.infoUsuarios[idObjetivo].nombre << "\n";
    
    system("pause");
    system("cls");

    // 4. Ejecutar BFS
    int saltos = bfsVisual(&facebook, idOrigen, idObjetivo);

    // 5. Resultado Final
    cout << "\n   ===============================================\n";
    cout << "                  RESULTADO FINAL                 \n";
    cout << "   ===============================================\n";
    if (saltos != -1) 
        cout << "   La distancia es de: " << saltos << " grados de separacion.\n";
    else 
        cout << "   No hay conexion entre estas personas.\n";
    
    cout << "   ===============================================\n";

    return 0;
}
