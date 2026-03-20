#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>
#include <limits.h>
struct nodo {
    int num;
    struct nodo* siguiente;
    int peso;
};

struct grafo {
    int numVertices;
    struct nodo** adjLists;
};
int tamanoArr = 15;



void anadirArista(struct grafo*, int, int, int);
void printGraph(struct grafo*);
int buscarUsuario(struct grafo*, int);
void eliminarArista(struct grafo* g, int nodo1, int nodo2);
int esAmigo(struct grafo* g, int nodo1, int nodo2);
void crearUsuario(struct grafo* g, int usuario);
void amigosEnComun(struct grafo* g, int nodo1, int nodo2);
void dijkstra(struct grafo* g, int inicio, int destino);
int minDistancia(int distancias[], int conjunto[], int numVertices);
void imprimirListaAmigos(struct grafo* g, int usuario);

int esNumeroEntero();

int main() {
    printf("======BISONTEBOOK======\n");

    printf("\nBienvenido a BisonTeBook, la red social del futuro.\n");
    printf("Conecta con amigos, comparte momentos y descubre nuevas conexiones.\n");
    printf("Explora las funciones emocionantes que BisonTeBook tiene para ofrecer.\n");
    printf("Permite a los usuarios realizar diversas operaciones, como iniciar sesión, crear usuarios, añadir y eliminar amigos, ver amigos en común, visualizar la lista de amigos, y utilizar un algoritmo para determinar la conexión entre dos usuarios en la red.\n");
    printf("\nPresiona cualquier tecla para continuar...\n");
    _getch();
    // Inicializa el grafo con 15 nodos
    struct grafo* miGrafo = (struct grafo*)malloc(sizeof(struct grafo));
    miGrafo->numVertices = 15;
    miGrafo->adjLists = (struct nodo**)malloc(tamanoArr * sizeof(struct nodo*));

    // Inicializa nodos con valores del 1 al 15
    for (int i = 0; i < tamanoArr; ++i) {
        struct nodo* nuevoNodo = (struct nodo*)malloc(sizeof(struct nodo));
        nuevoNodo->num = i+1;
        nuevoNodo->siguiente = NULL;
        miGrafo->adjLists[i] = nuevoNodo;
    }

    // Conexiones específicas (no dirigidas)
    anadirArista(miGrafo, 0, 1, 1);
    anadirArista(miGrafo, 1, 2, 4);
    anadirArista(miGrafo, 1, 13, 2);
    anadirArista(miGrafo, 2, 12, 10);
    anadirArista(miGrafo, 2, 13, 14);
    anadirArista(miGrafo, 3, 14, 1);
    anadirArista(miGrafo, 3, 11, 1);
    anadirArista(miGrafo, 3, 13, 2);
    anadirArista(miGrafo, 4, 5, 9);
    anadirArista(miGrafo, 4, 9, 8);
    anadirArista(miGrafo, 5, 7, 7);
    anadirArista(miGrafo, 6, 11, 3);
    anadirArista(miGrafo, 6, 12, 6);
    anadirArista(miGrafo, 7, 10, 6);
    anadirArista(miGrafo, 8, 14, 5);
    anadirArista(miGrafo, 9, 10, 11);
    anadirArista(miGrafo, 10, 14, 13);
    anadirArista(miGrafo, 10, 14, 2);

   
    int opc1, usuario, contrasena, opc2, opc3;
    struct nodo* nuevoUsuario = NULL; 
    char entrada[20];

    printf("======BISONTEBOOK======\n");
   
    do {
        _getch();
        printf("\n1.-Iniciar Sesion\n2.-Crear Usuario\n3.-Opciones de desarrollador\n4.-Finalizar\n");
      
        opc1 = esNumeroEntero();


        switch (opc1) {
        case 1:
            printf("Usuario: ");
            usuario = esNumeroEntero();
          

            if (buscarUsuario(miGrafo, usuario)) {
                opc3 = 10;
                while (opc3 != 6) {

                    printf("\nMenu de operaciones\n1.-Anadir amigo\n2.-Eliminar Amigo\n3.-Nueva funcion! Que tan lejano estoy?\n4.-Amigos en comun\n5.-Lista de amigos\n6. - Cerrar sesion\n");
                    opc3 = esNumeroEntero();
                    switch (opc3)
                    {
                    case 1:
                        printf("ID del amigo a anadir: ");
                        int amigoID;
                        scanf_s("%i", &amigoID);
                        if (buscarUsuario(miGrafo, amigoID)) {
                            int z;
                            z = rand() % 15 + 1;
                            anadirArista(miGrafo, usuario, amigoID, z);
                            printf("Amigo anadido exitosamente.\n");
                        }
                        else {
                            printf("El amigo no existe en la red. Verifica el ID del amigo.\n");
                        }
                        break;

                    case 2:  printf("ID del amigo a eliminar: ");
                        int amigoIDEliminar;
                        scanf_s("%i", &amigoIDEliminar);

                        if (buscarUsuario(miGrafo, amigoIDEliminar)) {
                            if (esAmigo(miGrafo, usuario, amigoIDEliminar)) {
                                eliminarArista(miGrafo, usuario, amigoIDEliminar);
                                printf("Amigo eliminado exitosamente.\n");
                            }
                            else {
                                printf("El usuario no está conectado con el amigo que intentas eliminar.\n");
                            }
                        }

                        else {
                            printf("El amigo no existe en la red. Verifica el ID del amigo.\n");
                        }
                        break;

                        break;
                    case 3:
                        printf("Conoce ahora que tan lejano o cercano eres a alguien!!. Con nuestro nuevo algoritmo, le asignamos un nivel de interaccion a todas tus conexiones, y con esta hacemos un camino para conectarte con quien quieras!\n");
                        printf("Con que usuario deseas ver tu conexion: ");
                        int con1;
                        scanf_s("%i", &con1);
                        if (buscarUsuario(miGrafo, con1)) {

                            dijkstra(miGrafo, usuario, con1);
                        }
                        else {
                            printf("Usuario no valido");
                        }
                        break;
                  
                    case 4:  printf("Amigos en comun con: ");
                        int x;
                        scanf_s("%i", &x);
                        amigosEnComun(miGrafo, usuario, x);
                        break;
                    case 5: printf("Lista de amigos\n");
                        imprimirListaAmigos(miGrafo, usuario);
                        break;
                    default:
                        break;
                    }
                }
            }


            else {
                printf("Usuario no encontrado. Por favor, inicie sesión con un usuario valido.\n");
            }
                
            break;

        case 2: {
            printf("Nuevo Usuario: ");
            scanf_s("%i", &usuario);


            crearUsuario(miGrafo, usuario);
            printf("Anade tu primer amigo, ID del amigo a anadir: ");
            int amigoID;
            scanf_s("%i", &amigoID);
            if (buscarUsuario(miGrafo, amigoID)) {
                int z;
                z = rand() % 15 + 1;
                anadirArista(miGrafo, usuario, amigoID, z);
                printf("Amigo anadido exitosamente.\n");
            }

            break;
        }
        case 3:
 
         
            printf("1.-Visualizar Grafo\n");
            scanf_s("%i", &opc2);
            switch (opc2) {
            case 1:
                printGraph(miGrafo);
                break;
            case 2: 
            default:
                break;
            }
            break;

        default:
            break;
        }
    } while (opc1 != 4);

    return 0;
}


void anadirArista(struct grafo* g, int nodo1, int nodo2, int peso) {
  
    if (nodo1 > 0 && nodo1 <= tamanoArr && nodo2 > 0 && nodo2 <= tamanoArr) {
      
        if (peso == 0) {
            peso = rand() % 15 + 1;
        }

      
        struct nodo* nuevaArista1 = (struct nodo*)malloc(sizeof(struct nodo));
        nuevaArista1->num = nodo2;
        nuevaArista1->peso = peso;
        nuevaArista1->siguiente = g->adjLists[nodo1 - 1]->siguiente;
        g->adjLists[nodo1 - 1]->siguiente = nuevaArista1;

       
        struct nodo* nuevaArista2 = (struct nodo*)malloc(sizeof(struct nodo));
        nuevaArista2->num = nodo1;
        nuevaArista2->peso = peso;
        nuevaArista2->siguiente = g->adjLists[nodo2 - 1]->siguiente;
        g->adjLists[nodo2 - 1]->siguiente = nuevaArista2;
    }
}


void printGraph(struct grafo* g) {
    for (int i = 0; i < tamanoArr; ++i) {
        struct nodo* temp = g->adjLists[i]->siguiente;  

        
        if (temp) {
            printf("\nLista de adyacencia del nodo %i:\n", i + 1);
            while (temp) {
                printf("%d", temp->num);
                if (temp->peso != 0) {
                    printf(" (%d)", temp->peso);
                }
                printf(" -> ");
                temp = temp->siguiente;
            }
            printf("NULL\n");
        }
    }
}


int buscarUsuario(struct grafo* g, int usuario) {
    for (int i = 0; i < g->numVertices; ++i) {
        struct nodo* temp = g->adjLists[i];
        while (temp) {
            if (temp->num == usuario) {
                return 1;  // El usuario existe en la lista de adyacencia.
            }
            temp = temp->siguiente;
        }
    }

  

    return 0; 
}
void eliminarArista(struct grafo* g, int nodo1, int nodo2) {
    
    struct nodo* temp1 = g->adjLists[nodo1 - 1];
    struct nodo* temp2 = g->adjLists[nodo2 - 1];

   
    while (temp1 && temp1->siguiente) {
        if (temp1->siguiente->num == nodo2) {
            struct nodo* tempEliminar = temp1->siguiente;
            temp1->siguiente = tempEliminar->siguiente;
            free(tempEliminar);
            break;
        }
        temp1 = temp1->siguiente;
    }

    
    while (temp2 && temp2->siguiente) {
        if (temp2->siguiente->num == nodo1) {
            struct nodo* tempEliminar = temp2->siguiente;
            temp2->siguiente = tempEliminar->siguiente;
            free(tempEliminar);
            break;
        }
        temp2 = temp2->siguiente;
    }
}

int esAmigo(struct grafo* g, int nodo1, int nodo2) {
 
    struct nodo* temp = g->adjLists[nodo1 - 1]->siguiente; 
    while (temp) {
        if (temp->num == nodo2) {
            return 1; 
        }
        temp = temp->siguiente;
    }
    return 0;
}

void crearUsuario(struct grafo* g, int usuario) {
    if (usuario <= 0) {
        printf("Error: El ID del usuario debe ser un número positivo.\n");
        _getch();
        return;
    }

    // Verificar si el usuario ya existe
    if (buscarUsuario(g, usuario)) {
        printf("Error: El usuario ya existe en la red.\n");
        return;
    }

    // Asegurarse de que hay suficiente espacio en el arreglo de nodos
    if (usuario > tamanoArr) {
        g->adjLists = (struct nodo**)realloc(g->adjLists, usuario * sizeof(struct nodo*));
        for (int i = tamanoArr; i < usuario; ++i) {
            struct nodo* nuevoNodo = (struct nodo*)malloc(sizeof(struct nodo));
            nuevoNodo->num = i + 1;
            nuevoNodo->siguiente = NULL;
            g->adjLists[i] = nuevoNodo;

          
        }
        tamanoArr = usuario;
        g->numVertices = tamanoArr;
    }

    // Crear el nuevo nodo para el usuario
    struct nodo* nuevoUsuario = (struct nodo*)malloc(sizeof(struct nodo));
    nuevoUsuario->num = usuario;
    nuevoUsuario->siguiente = NULL;
    nuevoUsuario->peso = 0;

  
  
  

    printf("Usuario Creado!!\n");
}

void amigosEnComun(struct grafo* g, int nodo1, int nodo2) {
   
    if (!buscarUsuario(g, nodo1) || !buscarUsuario(g, nodo2)) {
        printf("Al menos uno de los nodos no existe en el grafo.\n");
        return;
    }

   
    struct nodo* temp1 = g->adjLists[nodo1 - 1]->siguiente;
    struct nodo* temp2 = g->adjLists[nodo2 - 1]->siguiente;

  
    int* conexionesNodo1 = (int*)malloc(tamanoArr * sizeof(int));
   
    int* conexionesNodo2 = (int*)malloc(tamanoArr * sizeof(int));

   
    for (int i = 0; i < tamanoArr; ++i) {
        conexionesNodo1[i] = 0;
        conexionesNodo2[i] = 0;
    }

  
    while (temp1) {
        conexionesNodo1[temp1->num - 1] = 1;
        temp1 = temp1->siguiente;
    }

   
    while (temp2) {
        conexionesNodo2[temp2->num - 1] = 1;
        temp2 = temp2->siguiente;
    }

    
    printf("\nAmigos en común entre el nodo %d y el nodo %d:\n", nodo1, nodo2);
    int almenosUno = 0;
    for (int i = 0; i < tamanoArr; ++i) {
        if (conexionesNodo1[i] == 1 && conexionesNodo2[i] == 1 && i + 1 != nodo1 && i + 1 != nodo2) {
            printf("%d ", i + 1);
            almenosUno = 1;
        }
    }

    if (!almenosUno) {
        printf("No tienen amigos en común.\n");
    }

    free(conexionesNodo1);
    free(conexionesNodo2);

    printf("\n");
}
int minDistancia(int distancias[], int conjunto[], int numVertices) {
    int min = INT_MAX;
    int min_index;

    for (int v = 1; v <= numVertices; ++v) {
        if (!conjunto[v] && distancias[v] <= min) {
            min = distancias[v];
            min_index = v;
        }
    }

    return min_index;
}

void imprimirCamino(int* padres, int destino) {
    printf("Camino: %d", destino);
    int actual = destino;
    while (padres[actual] != actual) {
        printf(" <- %d", padres[actual]);
        actual = padres[actual];
    }
    printf("\n");
}

void dijkstra(struct grafo* g, int inicio, int destino) {
    int numVertices = g->numVertices;

    int* distancias = (int*)malloc((numVertices + 1) * sizeof(int));
    int* conjunto = (int*)malloc((numVertices + 1) * sizeof(int));
    int* padres = (int*)malloc((numVertices + 1) * sizeof(int));

    // Inicializar distancias, conjunto y padres
    for (int i = 0; i < numVertices; ++i) {
        distancias[i + 1] = INT_MAX;
        conjunto[i + 1] = 0;
        padres[i + 1] = -1;
    }

    // Inicializar distancias y padres con las conexiones específicas de la red social
    struct nodo* temp = g->adjLists[inicio - 1]->siguiente;
    while (temp) {
        distancias[temp->num] = temp->peso;
        padres[temp->num] = inicio;
        temp = temp->siguiente;
    }

    // Configurar el nodo de inicio
    distancias[inicio] = 0;
    padres[inicio] = inicio;

    // Algoritmo de Dijkstra
    for (int count = 0; count < numVertices - 1; ++count) {
        int u = minDistancia(distancias, conjunto, numVertices);
        conjunto[u] = 1;

        // Imprimir iteración actual
     //   printf("Iteración %d:\n", count + 1);
     //   printf("Vértice seleccionado: %d\n", u);

        // Actualizar distancias y padres teniendo en cuenta las conexiones específicas
        struct nodo* temp = g->adjLists[u - 1]->siguiente;
        while (temp) {
            int v = temp->num;
            if (!conjunto[v] && distancias[u] != INT_MAX &&
                distancias[u] + temp->peso < distancias[v]) {
                distancias[v] = distancias[u] + temp->peso;
                padres[v] = u;
                //printf("Distancia a %d actualizada a %d a través de %d\n", v, distancias[v], u);
            }
            temp = temp->siguiente;
        }
    }

    // Imprimir el resultado
    if (distancias[destino] > 100000) {
        printf("No existe conexión entre los usuarios\n");
        return;
    }

    printf("\nDistancia desde %d hasta %d: %d\n", inicio, destino, distancias[destino]);
    imprimirCamino(padres, destino);
    printf("\n");

    // Liberar memoria
    free(distancias);
    free(conjunto);
    free(padres);
}


int esNumeroEntero() {
    char Aux[' '];
    int i, p, y, num;
    do {

  
        gets_s(Aux, sizeof(Aux));//se lee los datos introducidos
        y = strlen(Aux);

        for (i = 0;i < y;i++)
        {
            if (isdigit(Aux[i]))
                p = 1;
            else
                p = 0;
            if (p == 0)
            {
                printf("\n Error,dato mal introducido, ingrese de nuevo\n\n ");
                break;
            }
        }
        if (y == 0)
            p = 0;
    } while (p == 0);

    num = atoi(Aux);
    return num;
}

void imprimirListaAmigos(struct grafo* g, int usuario) {
    if (!buscarUsuario(g, usuario)) {
        printf("El usuario no existe en la red.\n");
        return;
    }

    printf("Lista de amigos para el usuario %d:\n", usuario);

    struct nodo* temp = g->adjLists[usuario - 1]->siguiente;
    while (temp) {
        printf("%d ", temp->num);
        temp = temp->siguiente;
    }

    printf("\n");
}