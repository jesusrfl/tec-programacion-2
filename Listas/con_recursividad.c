#include<stdio.h>
#include<stdlib.h>


typedef struct Nodo{
    int num;
    struct Nodo *sig;
}NODO;


NODO* crearNodo();
int agregarNodo(NODO* *p,int n);
int agregarNodo2(NODO* *p,int n);
void mostrarLista(NODO *p);
int eliminarNodo(NODO* *p,int n);
void liberarMemoria(NODO* *p);



int main(){

    NODO *lista = NULL;

    agregarNodo(&lista,1);
    agregarNodo(&lista,2);
    agregarNodo(&lista,3);
    agregarNodo(&lista,4);
    agregarNodo(&lista,5);


    mostrarLista(lista);
    eliminarNodo(&lista,1);
    eliminarNodo(&lista,5);
    agregarNodo2(&lista,0);
    agregarNodo(&lista,9);

    printf("\n");
    mostrarLista(lista);

  liberarMemoria(&lista);
  fflush(stdin); getchar();
  return 0;
}


NODO* crearNodo(){ return ((NODO*) malloc(sizeof(NODO))); }

int agregarNodo(NODO* *p, int n){
     if(*p == NULL){
        *p = crearNodo();
        if(*p == NULL) return 0;
        (*p)->num = n;
        (*p)->sig = NULL;
        return 1;
     }
     agregarNodo(&(*p)->sig,n);
}

int agregarNodo2(NODO* *p, int n){
    // No tiene recursividad porque no necesita de algún ciclo para ejecutarse
    NODO *temp,*nuevo = crearNodo();

    if(!nuevo) return 0;
    nuevo->num = n;
    nuevo->sig = NULL;

    if(*p == NULL){
        *p = nuevo;
        return 1;
    }

    temp = *p;
    *p = nuevo;
    (*p)->sig = temp;
  return 1;
}

int eliminarNodo(NODO* *p, int n){
    NODO *temp;

    if(*p == NULL) return 0;

    if((*p)->num == n){
        temp = *p;
        *p = (*p)->sig;
        free(temp);
        return 1;
    }
    eliminarNodo(&(*p)->sig,n);
}

void mostrarLista(NODO *p){
    if(!p) return;
    printf("%i \n",p->num);
    mostrarLista(p->sig);
}


void liberarMemoria(NODO* *p){
    if(*p == NULL) return;
    liberarMemoria(&(*p)->sig);
    free(*p);
}
