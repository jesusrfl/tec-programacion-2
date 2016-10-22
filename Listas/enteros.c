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


//----------------------------------------------------------------------------------------------------------------
int main(){

    NODO *lista = NULL;

    agregarNodo(&lista,1);
    agregarNodo(&lista,2);
    agregarNodo(&lista,3);
    agregarNodo(&lista,4);
    agregarNodo(&lista,5);

    mostrarLista(lista);
    eliminarNodo(&lista,3);
    eliminarNodo(&lista,1);
    agregarNodo2(&lista,0);
    printf("\n");
    mostrarLista(lista);

  liberarMemoria(&lista);
  fflush(stdin); getchar();
  return 0;
}
//----------------------------------------------------------------------------------------------------------------

NODO* crearNodo(){ return ((NODO*) malloc(sizeof(NODO))); }

int agregarNodo(NODO* *p, int n){
    NODO *temp,*nuevo = crearNodo();

    if(!nuevo) return 0;
    nuevo->num = n;
    nuevo->sig = NULL;

    if(*p == NULL){
        *p = nuevo;
        return 1;
    }

    temp = *p;
    while(temp->sig) temp = temp->sig;
    temp->sig = nuevo;

  return 1;
}

int agregarNodo2(NODO* *p, int n){
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
    NODO *temp,*ant;
    if(*p == NULL) return 0;

    if((*p)->num == n){
        temp = *p;
        *p = (*p)->sig;
        free(temp);
        return 1;
    }

    temp = *p;

    while(temp && temp->num != n){
        ant = temp;
        temp = temp->sig;
    }

    if(!temp) return 0;

    ant->sig = temp->sig;
    free(temp);

  return 1;
}

void mostrarLista(NODO *p){
    while(p){
        printf("%i \n",p->num);
        p = p->sig;
    }
}

void liberarMemoria(NODO* *p){
    NODO *temp;
    while(*p != NULL){
        temp = *p;
        *p = (*p)->sig;
        free(temp);
    }
}
