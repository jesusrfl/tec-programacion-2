#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct Asignatura{
    int codigo;
    char descripcion[40]; 
    int uc;
}ASIGNATURA;

typedef struct Nodo{
    ASIGNATURA asignatura; 
    struct Nodo *sig;
}NODO;


NODO* crearNodo();
bool agregarNodo(NODO* &p,int cod,char *des,int uc);
void mostrarLista(NODO *p);
bool eliminarNodo(NODO* &p,int cod);
void liberarMemoria(NODO* &p);



int main(){

    NODO *lista = NULL;

    agregarNodo(lista,1472103,"FUNDAMENTOS DE LA INFORMATICA",4);
    agregarNodo(lista,1472107,"LOGICA COMPUTACIONAL",3);
    agregarNodo(lista,1472211,"TECNICAS DE PROGRAMACION I",4);
    agregarNodo(lista,1472321,"TECNICAS DE PROGRAMACION II",4);
    agregarNodo(lista,1472424,"TECNICAS DE PROGRAMACION II",4);
    agregarNodo(lista,1472428,"ESTRUCTURA DE DATOS",4);
    mostrarLista(lista);

    eliminarNodo(lista,1472107); 
    printf("\n"); mostrarLista(lista);    

  fflush(stdin); getchar();
  liberarMemoria(lista);
  return 0;
}


NODO* crearNodo(){ return ((NODO*) malloc(sizeof(NODO))); }

bool agregarNodo(NODO* &p, int cod,char *des,int uc){
    NODO *temp,*nuevo = crearNodo();
    if(!nuevo) return false;
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
    NODO *temp,*ant;
    if(!p) return false;

    if(p->asignatura.codigo == cod){
        temp = p;
        p = p->sig;
        free(temp);
        return true;
    }

    temp = p;

    while(temp && temp->asignatura.codigo != cod){
        ant = temp;
        temp = temp->sig;
    }

    if(!temp) return false;
    
    ant->sig = temp->sig;
    free(temp);
  return true;  
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
