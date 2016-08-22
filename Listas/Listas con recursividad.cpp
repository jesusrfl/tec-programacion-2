#include<stdio.h>
#include<stdlib.h>


typedef struct Nodo{
    int Num; 
    struct Nodo *Sig; 
}NODO;


NODO* crearNodo();
bool agregarNodo(NODO* &p,int n);
bool agregarNodo2(NODO* &p,int n);
void mostrarLista(NODO *p);
bool eliminarNodo(NODO* &p,int n);
void liberarMemoria(NODO* &p);



int main(){

    NODO *lista = NULL;

    // Agregando nodos al final de la lista
    agregarNodo(lista,1);
    agregarNodo(lista,2);
    agregarNodo(lista,3);
    agregarNodo(lista,4);
    agregarNodo(lista,5);


    mostrarLista(lista);
    eliminarNodo(lista,1); 
    eliminarNodo(lista,5);
    agregarNodo2(lista,0);//Agrega el nodo al inicio
    agregarNodo(lista,9);

    printf("\n"); 
    mostrarLista(lista);

    liberarMemoria(lista); 

  fflush(stdin); getchar();
  return 0;
}


NODO* crearNodo(){ return ((NODO*) malloc(sizeof(NODO))); }


bool agregarNodo(NODO* &p, int n){     
     if(!p){
        p = crearNodo();
        p->Num = n;
        p->Sig = NULL; 
        return true;
     }     
     agregarNodo(p->Sig,n);
}


bool agregarNodo2(NODO* &p, int n){
    /*Esta función no cambia porque solo se ejecuta una vez */
    NODO *temp,*nuevo = crearNodo();
    nuevo->Num = n;
    nuevo->Sig = NULL;
    if(!p){
        p = nuevo;
        return true;
    }
    temp = p; 
    p = nuevo;
    p->Sig = temp;
  return true;       
}


bool eliminarNodo(NODO* &p, int n){
    NODO *temp;
    if(!p) return false; 
    if(p->Num == n){
        temp = p;
        p = p->Sig;
        free(temp);
        return true;
    }
    eliminarNodo(p->Sig,n);
}

void mostrarLista(NODO *p){   
    if(!p) return; 
    printf("%i \n",p->Num);
    mostrarLista(p->Sig);
}


void liberarMemoria(NODO* &p){    
    if(!p) return;      
    liberarMemoria(p->Sig);    
    free(p);
}