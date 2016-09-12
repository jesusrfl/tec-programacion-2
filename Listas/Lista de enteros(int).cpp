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


//----------------------------------------------------------------------------------------------------------------
int main(){

    NODO *lista = NULL;

    agregarNodo(lista,1);
    agregarNodo(lista,2);
    agregarNodo(lista,3);
    agregarNodo(lista,4);
    agregarNodo(lista,5);

    mostrarLista(lista); 
    eliminarNodo(lista,3);
    eliminarNodo(lista,1); 
    agregarNodo2(lista,0);
    printf("\n"); 
    mostrarLista(lista);
    
  fflush(stdin); getchar();
  liberarMemoria(lista);
  return 0;
}
//----------------------------------------------------------------------------------------------------------------

NODO* crearNodo(){ return ((NODO*) malloc(sizeof(NODO))); }

bool agregarNodo(NODO* &p, int n){
    NODO *temp,*nuevo = crearNodo();

    if(!nuevo) return false;
    nuevo->num = n;
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

bool agregarNodo2(NODO* &p, int n){
    NODO *temp,*nuevo = crearNodo();

    if(!nuevo) return false;
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
    NODO *temp,*ant;
    if(!p) return false; 

    if(p->num == n){
        temp = p;
        p = p->sig; 
        free(temp); 
        return true;
    }

    temp = p; 

    while(temp && temp->num != n){
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
        printf("%i \n",p->num);
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
