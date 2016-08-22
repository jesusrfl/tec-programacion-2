/*
    En este archivo se hace la representación de un ABB
    (Árbol Binario de Búsqueda). Se le llama binario porque
    solo puede tener 2 hijos y de búsqueda porque está ordenado
    con fines acelerativos de búsqueda.

    Para manejar un árbol en el lenguaje C/C++ lo mas conveniente
    es utilizar funciones recursivas ya que se adapta perfectamente
    a su funcionamiento.

    Por ej: Un árbol puede tener 2 hijos que a su vez son árboles que
            pueden tener 2 hijos y así sucesivamente las veces que se
            quiera.

    Al igual que las listas, se pueden agregar nodos, eliminarlos, mostrarlos, etc.

    Un árbol de números por ejemplo, se ordena agregando los menores a la izquierda
    del número raiz(el primer nodo) y los mayores a la derecha. Esto se hace para
    que al buscar un número, si este es mayor que el de la raiz, descartamos todos los
    números que estan a la izquierda y nos vamos solo con los que estan en la derecha
    y asi sucesivamente vamos descartando opciones hasta encontrarlo.

    Muy eficiente la búsqueda de esta manera.

    Un árbol puede ser recorridos de 3 formas:
        1)preorden: se visita la raiz, luego el hijo izquierdo y finalmente el hijo derecho.
        2)inorden:  se visita el hijo izquierdo, luego la raiz y finalmente el hijo derecho.
        3)postorden: se visita el hijo izquierdo, luego el hijo derecho y finalmente la raiz.


*/

//Librerías a utilizar
#include<stdio.h>
#include<stdlib.h>

//Definición del nodo Arbol
typedef struct Arbol{
    int num; //Dato
    struct Arbol *izq;// Puntero de tipo Arbol que apunta al hijo izquierdo
    struct Arbol *der;// Puntero de tipo Arbol que apunta al hijo derecho
}ARBOL;



//Definición de funciones
ARBOL* crearNodo();
bool agregarNodo(ARBOL* &p, int n);
void verArbol(ARBOL *p, int n);
void preOrden(ARBOL *p);
void inOrden(ARBOL *p);
void postOrden(ARBOL *p);
ARBOL* eliminarNodo(ARBOL* &p, int n);
void liberarMemoria(ARBOL* &p);



//---------------------------------------------------------------------------------
int main(){

    ARBOL *arbol = NULL; // Declaramos el puntero que apuntará a la raiz, por los momentos apunta a NULL

    // Agregamos algunos números
    agregarNodo(arbol,12);
    agregarNodo(arbol,10);
    agregarNodo(arbol,14);
    agregarNodo(arbol,15);
    agregarNodo(arbol,5);
    agregarNodo(arbol,13);
    agregarNodo(arbol,11);


    // Mostramos todos los números siguiendo cada tipo de orden
    printf("preOrden:  ");
    preOrden(arbol);
    printf("\n\n");

    printf("inOrden:   ");
    inOrden(arbol);
    printf("\n\n");

    printf("postOrden:  ");
    postOrden(arbol);
    printf("\n\n");

    //Mostramos el árbol
    verArbol(arbol,0);

    // Hacemos pruebas de la función para eliminar un nodo
    printf("\n Eliminando numero 5...\n");
    arbol = eliminarNodo(arbol,5);
    verArbol(arbol,0);

    printf("\n Eliminando numero 14...\n");
    arbol = eliminarNodo(arbol,14);
    verArbol(arbol,0);

    printf("\n Eliminando numero 12...\n");
    arbol = eliminarNodo(arbol,12);
    verArbol(arbol,0);

    liberarMemoria(arbol); // Finalmente liberamos la memoria

    fflush(stdin);getchar(); // Nos aseguramos que haya una pausa al final del programa
  return 0;
}
//---------------------------------------------------------------------------------



ARBOL* crearNodo(){
    //Retornamos la direccion de memoria reservada
  return (ARBOL*) malloc(sizeof(ARBOL));
}

bool agregarNodo(ARBOL* &p, int n){
    /*
        La primera vez que se llama a la función recibe el puntero que apunta a la raiz,
        luego si es necesario recibirá otras posiciones hasta que encuentre una libre
        correspondiente al dato que se va a agregar
    */

    if(!p){
        //Si el puntero no apunta a nada procedemos a agregar el nodo
        p = crearNodo(); // Le asignamos la dirección de memoria de la reserva
        if(!p) return false; // Si no se ha podido reservar salimos de la función
        p->num = n; // Asignamos el número a agregar
        //Inicializamos los punteros de tipo Arbol que serán futuros hijos de este nuevo nodo
        p->izq = NULL;
        p->der = NULL;
        return true; // Finalmente salimos de la función
    }

    /* Si el puntero que recibe la función ya está ocupado entonces
        debemos agregar el dato en unos de sus hijos dependiendo del
        valor de este para que sea ordenado correctamente en el árbol. */
    if(n <= p->num) return agregarNodo(p->izq,n); // Inicia la recursividad por el lado izquierdo hasta encontrar una posición libre
        else return agregarNodo(p->der,n); // Inicia la recursividad por el lado derecho hasta encontrar una posición libre
}

void verArbol(ARBOL *p, int n){
    /*
        Esta función nos permite visualizar el árbol de una manera
        semi-gráfica. Recibe el puntero de la raiz y una variable
        entera que se usa para posicionar los datos.
    */

    //Verificamos que haya un nodo
    if(p){
        verArbol(p->der,n+1);  // Empezamos la recursividad por la derecha
        for(int i = 0; i<n; i++) printf("   "); // Mostramos un espacio dependiendo de la posición que llevamos acumulada
        printf("%i \n",p->num); // Mostramos el dato
        verArbol(p->izq,n+1); // Empezamos la recursividad por la izquierda
    }
}

void preOrden(ARBOL *p){
    //Recibe el puntero para mostrar los datos en "preorden"

    //Verificamos que haya un nodo
    if(p){
        printf("%i ",p->num); // Mostramos el dato
        preOrden(p->izq); // Empezamos la recursividad por la izquierda
        preOrden(p->der); // Empezamos la recursividad por la derecha
    }
}

void inOrden(ARBOL *p){
    //Recibe el puntero para mostrar los datos en "inorden"

    //Verificamos que haya un nodo
    if(p){
        inOrden(p->izq); // Empezamos la recursividad por la izquierda
        printf("%i ",p->num); // Mostramos el dato
        inOrden(p->der);
        /* En este caso los numeros se mostrarán siguiendo el orden menor-mayor,
           si se quiere mayor-menor, se debe empezar la recursividad por la
           derecha primero */
    }
}

void postOrden(ARBOL *p){
    //Recibe el puntero para mostrar los datos en "postorden"

    //Verificamos que haya un nodo
    if(p){
        postOrden(p->izq); // Empezamos la recursividad por la izquierda
        postOrden(p->der); // Empezamos la recursividad por la derecha
        printf("%i ",p->num); // Mostramos el dato
    }
}

ARBOL* eliminarNodo(ARBOL* &p, int n){
    /*
        Para eliminar un nodo deben tomarse en cuenta las siguientes
        consideraciones:

        1) Encontrar el nodo que vamos a eliminar.
        2) Si el nodo no tiene hijos se puede simplemente liberar la memoria de este.
        3) Si el nodo tiene un solo hijo, el hijo toma el lugar del nodo y se procede
           a liberar la memoria del nodo.
        4) Si el nodo tiene 2 hijos, el hijo derecho toma su lugar y se le agrega a su
           último nodo izquierdo el hijo izquierdo del nodo a eliminar. Finalmente se
           libera la memoria.
        5) La función debe llamarse asignandose al puntero principal del árbol. Por ej:
            "arbol = eliminarNodo(arbol,x);", ya que si eliminamos la raiz del árbol
            retornamos la que será su nueva raiz.
    */

    ARBOL *temp_der,*temp_izq; // Declaramos punteros a utilizar
    if(!p) return NULL; // Si no hay nodo retornamos NULL


        if(p->num == n){
            //Si encontramos el nodo...
                if(!p->izq && !p->der){
                    //Si no tiene hijos...
                    free(p); // Liberamos memoria
                    return NULL; // Retornamos NULL
                }else if(!p->izq){
                        //Si no tiene hijo izquierdo...
                        temp_der = p->der; // Guardamos a su hijo derecho en la variable temporal
                        free(p); // Liberamos la memoria
                        return temp_der; // Retornamos al hijo derecho
                }else if(!p->der){
                        //Si no tiene hijo derecho...
                        temp_izq = p->izq; // Guardamos a su hijo izquierdo en la variable temporal
                        free(p); // Liberamos la memoria
                        return temp_izq; // Retornamos al hijo izquierdo
                }else{
                       //Si tiene sus dos hijos...
                       temp_der = p->der; // Guardamos al hijo derecho en la variable temporal
                       temp_izq = p->der; // Hacemos otra copia del hijo derecho
                       while(temp_izq->izq) temp_izq = temp_izq->izq; // Recorremos a través de la copia, hasta el último nodo de la izquierda
                       temp_izq->izq = p->izq; // Le asignamos al último nodo el hijo izquierdo del nodo
                       free(p); // Liberamos la memoria
                       return temp_der; // Retornamos al hijo derecho
                     }
        }

        /* Si no hemos encontrado el nodo a eliminar, seguimos con la recursividad
            dependiendo del valor del dato.

            Como se puede apreciar, no solo se hace el llamado si no que se le asigna
            el retorno al hijo izquierdo o derecho. Esto se hace ya que al eliminar un
            nodo, otro tomará su lugar si este tiene alguno de sus hijos o los dos.
        */
        if(n <= p->num) p->izq = eliminarNodo(p->izq,n);
            else p->der = eliminarNodo(p->der,n);
  return p;
}

void liberarMemoria(ARBOL* &p){
    /* Para liberar la memoria de todo el árbol debemos
       hacerlo en "postorden" ya que no podemos liberar
       la raiz antes que algún otro nodo y ese es el orden
       de recorrido que nos permite liberar todo dejando de
       último la raiz. */
    if(p){
       //Si hay un nodo...
       liberarMemoria(p->izq); // Empezamos la recursividad por izquierda
       liberarMemoria(p->der); // Empezamos la recursividad por derecha
       free(p); // Liberamos el nodo
    }
}
