/*
    En este archivo se muestra la representanción de una lista en C/C++
    con uso de memoria dinámicamente.

    A diferencia de las anteriores estructuras de datos (Pilas y Colas), en las listas
    podemos recorrer sin extraer los datos, los mismos son eliminados si se desea, y
    no hay un orden de salida en específico. Se puede mostrar la lista en el orden que
    se desee.

    Una lista esta constituida por nodos, estos contienen el dato y la dirección del
    siguiente nodo. Por ej:

    |NODO(#F123){dato=1,sig=#F124}| -> |NODO(#F124){dato=2,sig=#F125}| -> |NODO(#F125){dato=1,sig=NULL}| -> NULL

    donde: |TIPO_DE_DATO_DEFINIDO(DIRECCION_EN_MEMORIA){dato=CUALQUIER_TIPO_DE_DATO,sig=DIRECCION_EN_MEMORIA_DEL_SIGUIENTE_NODO}|

    A continuación veremos como se realizan las funciones básicas para manejar una lista.
    Si se tiene alguna duda en cuanto a el pase de variables por referencia y el manejo de
    memoria dinámicamente se recomienda primero repasar dichos temas.


*/


//Líbrerias necesarias
#include<stdio.h>
#include<stdlib.h>


// Estructura de tipo NODO
typedef struct Nodo{
    int num; // Dato que contiene el nodo
    struct Nodo *sig; // Puntero de tipo Nodo que apuntará al siguiente nodo
}NODO;


//Funciones a utilizar
NODO* crearNodo();
bool agregarNodo(NODO* &p,int n);
bool agregarNodo2(NODO* &p,int n);
void mostrarLista(NODO *p);
bool eliminarNodo(NODO* &p,int n);
void liberarMemoria(NODO* &p);



int main(){

    /* Declaramos el puntero a usar de tipo NODO para el
      primer nodo a agregar y lo inicializamos NULL porque
      aún no va a apuntar a ningún nodo */
    NODO *lista = NULL;

    // Agregamos los números del 1 al 6
    agregarNodo(lista,1);
    agregarNodo(lista,2);
    agregarNodo(lista,3);
    agregarNodo(lista,4);
    agregarNodo(lista,5);


    mostrarLista(lista); // Mostramos la lista
    eliminarNodo(lista,3); // Eliminamos el número 3
    eliminarNodo(lista,1); // Eliminamos el número 1
    agregarNodo2(lista,0); // Agregamos un nodo al principio con el 0

    printf("\n"); // Salto de línea para diferenciar los cambios
    mostrarLista(lista); // Mostramos la lista

    liberarMemoria(lista); // Liberamos la memoria usada por toda la lista

  fflush(stdin); getchar(); // Nos aseguramos que haya una pausa al final del programa
  return 0;
}


NODO* crearNodo(){
    /* Se retorna la dirección de memoria que devuelve la función
        malloc de una vez con el tipo de dato NODO */
  return ((NODO*) malloc(sizeof(NODO)));
}


bool agregarNodo(NODO* &p, int n){
    /* Se recibe el puntero de tipo NODO, por referencia,
        que apunta al primer nodo de la lista y el número a
        agregar */

    /* Se declara las variables a utilizar, de una vez se inicializa
      el puntero del nuevo nodo con la función "crearNodo" */
    NODO *temp,*nuevo = crearNodo();

    /* Si no se ha podido reservar la memoria para el nuevo nodo
        salimos de la función retornando false */
    if(!nuevo) return false;

    //Se inicializan los valores de nodo
    nuevo->num = n;
     /*NULL significa que no apunta a nada y por lo tanto si ponemos
        en una condición por ej: if(nuevo->sig), esta rertornará falso por el NULL */
    nuevo->sig = NULL;


    /* Si el puntero recibido no apunta a ningún nodo, se le asigna el nuevo y se sale
        de la función retornando true */
    if(!p){
        p = nuevo;
        return true;
    }

    /* De lo contrario, quiere decir que hay mas de un nodo y en
        este caso debemos recorrer la lista hasta llegar al puntero
        "sig" del último nodo que apunta a NULL */

    temp = p; // Se utiliza una variable temporal para no perder la lista

    /* Mientras no retorne falso "temp-sig", recorremos toda la lista
       asignandole a la variable el siguiente nodo sucesivamente */
    while(temp->sig) temp = temp->sig;

    // Al salir del while ya podremos asignar el nuevo nodo a la última posición de la lista
    temp->sig = nuevo;

  return true;// Finalmente retornamos true, porque hemos podido agregar el nuevo número sin problemas
}


bool agregarNodo2(NODO* &p, int n){

    /*Esta función es igual a la anterior, solo que aquí se agrega
       el número al principio de la lista */
    NODO *temp,*nuevo = crearNodo();

    if(!nuevo) return false;

    nuevo->num = n;
    nuevo->sig = NULL;

    if(!p){
        p = nuevo;
        return true;
    }


    //Esta es la parte que cambia...
    temp = p; // Se guarda el primer nodo en una variable temporal
    p = nuevo; // Se le asigna el nuevo nodo al apuntador
    p->sig = temp; // Se le asigna el anterior primer nodo al apuntador "sig" del nuevo primer nodo

  return true;
}


bool eliminarNodo(NODO* &p, int n){
    /*Se recibe el apuntador por referencia y el número a eliminar.

        Para eliminar un nodo se deben tener en consideración los
        siguientes pasos:

            1) Verificar que haya por lo menos un nodo en la lista
            2) Buscar el nodo que contiene el número a eliminar
            3) Unir el nodo anterior al que se va a eliminar con el siguiente de dicho nodo
            4) Liberar la memoria utilizada por el nodo */


    NODO *temp,*ant;// Se declaran variables a usar

    if(!p) return false; // Si no hay ningún nodo salimos de la función retornando falso

    // Se evalua el primer nodo
    if(p->num == n){
        temp = p; // Guardamos el primer nodo
        p = p->sig; // Le asignamos al apuntador el siguiente nodo
        free(temp); // Liberamos la memoria del nodo que guardamos
        return true; // Finalmente salimos de la función retornando true
    }

    temp = p; // Inicializamos variable temporal

    // Si el número no se encuentra en el primer nodo debemos recorrer la lista
    do{
        ant = temp; // Guardamos el actual que será luego el anterior
        temp = temp->sig; // Avanzamos al siguiente nodo
    }while(temp && temp->num != n); // Mientras haya un nodo y no se haya encontrado el número

    // Al salir del "while", o se ha encontrado el número o ya no hay nodos donde buscar

    //Verificamos que haya un nodo, si lo hay, entonces es el que estamos buscando
    if(temp){
      ant->sig = temp->sig; // Unimos el anterior con el siguiente del nodo
      free(temp); // Liberamos el nodo
      return true; // Salimos de la función retornando true
    }else return false; // Si no hay nodo, no existe el número recibido y entonces retornamos false
}

void mostrarLista(NODO *p){
    //Recibimos el puntero por "valor"
    while(p){
    // Mientras haya un nodo
        printf("%i \n",p->num); //Imprimimos el numero
        p = p->sig; // Avanzamos al siguiente nodo
    }
}


void liberarMemoria(NODO* &p){
    //Recibimos el puntero por "referencia"
    NODO *temp;
    while(p){
    // Mientras haya un nodo
        temp = p; // Guardamos el nodo actual para no perder la lista
        p = p->sig; // Avanzamos
        free(temp); // Eliminamos el nodo guardado
    }
}
