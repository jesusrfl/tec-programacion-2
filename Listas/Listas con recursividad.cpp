#include<stdio.h>
#include<stdlib.h>


typedef struct Nodo{
    int num;
    struct Nodo *sig;
}NODO;


NODO* crearNodo();
bool agregarNodo(NODO* &p,int n);
bool agregarNodo2(NODO* &p,int n);
void mostrarLista(NODO *p);
bool eliminarNodo(NODO* &p,int n);
void liberarMemoria(NODO* &p);



int main(){

    NODO *lista = NULL;

    agregarNodo(lista,1);
    agregarNodo(lista,2);
    agregarNodo(lista,3);
    agregarNodo(lista,4);
    agregarNodo(lista,5);


    mostrarLista(lista);
    eliminarNodo(lista,1);
    eliminarNodo(lista,5);
    agregarNodo2(lista,0);
    agregarNodo(lista,9);

    printf("\n");
    mostrarLista(lista);

  fflush(stdin); getchar();
  liberarMemoria(lista);
  return 0;
}


NODO* crearNodo(){ return ((NODO*) malloc(sizeof(NODO))); }

bool agregarNodo(NODO* &p, int n){
     if(!p){
        p = crearNodo();
        p->num = n;
        p->sig = NULL;
        return true;
     }
     agregarNodo(p->sig,n);
}

bool agregarNodo2(NODO* &p, int n){
    // No tiene recursividad porque no necesita algún ciclo para ejecutarse
    NODO *temp,*nuevo = crearNodo();
    nuevo->num = n;
    nuevo->sig = NULL;
    if(!p){
        p = nuevo;
        return true;
    }
    temp = p;
    p = nuevo;
    p->sig = temp;
  return true;
}

bool eliminarNodo(NODO* &p, int n){
    NODO *temp;
    if(!p) return false;
    if(p->num == n){
        temp = p;
        p = p->sig;
        free(temp);
        return true;
    }
    eliminarNodo(p->sig,n);
}

void mostrarLista(NODO *p){
    if(!p) return;
    printf("%i \n",p->num);
    mostrarLista(p->sig);
}


void liberarMemoria(NODO* &p){
    if(!p) return;
    liberarMemoria(p->sig);
    free(p);
}
