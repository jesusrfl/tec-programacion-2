#include<stdio.h> 

#define MAX 5 


typedef struct Pila{
    int numeros[MAX];
    int ultimo;
}PILA;


void inicializarPila(PILA *p);
bool estaVacia(PILA p);
bool estaLlena(PILA p);
bool insertarNumero(PILA *p, int n);
int extraerNumero(PILA *p);


//--------------------------------------------------------------------------------------
int main(){
    
    PILA mi_pila;
    
    inicializarPila(&mi_pila);   

    for(int i=1; i<=6; i++){
       /* Se intenta insertar 6 elementos para comprobar que no se puede 
          porque la pila ya estaría llena al insertar 5.
       */
        if(insertarNumero(&mi_pila,i)) printf("#%i insertado \n",i);                 
    } 
    
    while(!estaVacia(mi_pila)) printf("#%i extraido \n",extraerNumero(&mi_pila));
    
    // Comprobando que ha quedado vacia la pila
    if(estaVacia(mi_pila)) printf("Pila vacia");

    fflush(stdin); getchar();
  return 0;
}
//--------------------------------------------------------------------------------------


void inicializarPila(PILA *p){ p->ultimo = -1; } 
   
bool estaVacia(PILA p){ return (p.ultimo == -1); }

bool estaLlena(PILA p){ return (p.ultimo == (MAX-1)); }

bool insertarNumero(PILA *p,int n){     
    if(estaLlena(*p)){    
        printf("Pila llena \n");
        return false;
    }
    p->ultimo++; 
    p->numeros[p->ultimo] = n;        
  return true;
}

int extraerNumero(PILA *p){ return p->numeros[p->ultimo--]; }
