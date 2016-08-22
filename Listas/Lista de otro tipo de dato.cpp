/*
    En este archivo se muestra un ejemplo de listas con otro
    tipo de dato, en este caso "Asignatura".

*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Definición del tipo de dato
typedef struct Asignatura{
    int codigo; // Código de la asignatura
    char descripcion[40]; // Descripción de la asignatura
    int uc; // Unidades de crédito
}ASIGNATURA;

typedef struct Nodo{
    ASIGNATURA asignatura; // Variable de tipo ASIGNATURA para el nodo
    struct Nodo *sig;
}NODO;


NODO* crearNodo();
bool agregarNodo(NODO* &p,int cod,char *des,int uc);
void mostrarLista(NODO *p);
bool eliminarNodo(NODO* &p,int cod);
void liberarMemoria(NODO* &p);



int main(){

    NODO *lista = NULL;

    //Agregamos las asignaturas a la lista, pasando los valores a la función "agregarNodo"
    agregarNodo(lista,1472103,"FUNDAMENTOS DE LA INFORMATICA",4);
    agregarNodo(lista,1472107,"LOGICA COMPUTACIONAL",3);
    agregarNodo(lista,1472211,"TECNICAS DE PROGRAMACION I",4);
    agregarNodo(lista,1472321,"TECNICAS DE PROGRAMACION II",4);
    agregarNodo(lista,1472424,"TECNICAS DE PROGRAMACION II",4);
    agregarNodo(lista,1472428,"ESTRUCTURA DE DATOS",4);
    mostrarLista(lista);

    eliminarNodo(lista,1472211); // Eliminamos una asignatura de la lista pasando el código de ésta

    printf("\n"); mostrarLista(lista); // Mostramos la lista actualizada para verificar que se haya eliminado el nodo

    liberarMemoria(lista);

  fflush(stdin); getchar(); // Nos aseguramos que haya una pausa al final del programa
  return 0;
}


NODO* crearNodo(){
  return ((NODO*) malloc(sizeof(NODO)));
}


bool agregarNodo(NODO* &p, int cod,char *des,int uc){
    /* Recibimos los atributos para la variable "asignatura" del nodo.
       Lo hacemos así porque son solo 3. Si son más atributos se podría
       declarar una variable de tipo ASIGNATURA, asignarles los valores
       y recibirla en esta función si se desea. */
    NODO *temp,*nuevo = crearNodo();
    if(!nuevo) return false;
    //Le asignamos los valores recibidos a la variable "asignatura" del nodo
    nuevo->asignatura.codigo = cod;
    strcpy(nuevo->asignatura.descripcion,des);
    nuevo->asignatura.uc = uc;
    nuevo->sig = NULL;

    if(!p){
        p = nuevo;
        return true;
    }

    temp = p;

    while(temp->sig) temp = temp->sig;
    temp->sig = nuevo;

  return true;
}

bool eliminarNodo(NODO* &p, int cod){
    /* Recibimos el código de la asignatura y buscamos el nodo
       que contenga en su variable asignatura ese código para
       proceder a eliminarlo */
    NODO *temp,*ant;
    if(!p) return false;

    if(p->asignatura.codigo == cod){
        temp = p;
        p = p->sig;
        free(temp);
        return true;
    }

    temp = p;

    do{
        ant = temp;
        temp = temp->sig;
    }while(temp && temp->asignatura.codigo != cod);

    if(temp){
      ant->sig = temp->sig;
      free(temp);
      return true;
    }else return false;
}

void mostrarLista(NODO *p){
    while(p){
        printf("%i %s %i \n",p->asignatura.codigo,p->asignatura.descripcion,p->asignatura.uc);
        p = p->sig;
    }
}

void liberarMemoria(NODO* &p){
    NODO *temp;
    while(p){
        temp = p;
        p = p->sig;
        free(temp);
    }
}
