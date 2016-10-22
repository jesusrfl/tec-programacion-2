#include<stdio.h>

#define MAX 5

typedef struct Pila{
    int numeros[MAX];
    int ultimo;
}PILA;

void inicializarPila(PILA *p);
int estaVacia(PILA p);
int estaLlena(PILA p);
int insertarNumero(PILA *p, int n);
int extraerNumero(PILA *p);


//--------------------------------------------------------------------------------------
int main(){

    PILA mi_pila;
    int i;
    inicializarPila(&mi_pila);

    for(i=1; i<=6; i++){
       /* Se intenta insertar 6 elementos para comprobar que no se puede
          porque la pila ya estará llena al insertar 5.
       */
        if(insertarNumero(&mi_pila,i)) printf("#%i insertado \n",i);
    }

    while(!estaVacia(mi_pila)) printf("#%i extraido \n",extraerNumero(&mi_pila));

    // Comprobando que ha quedado vacía la pila
    if(estaVacia(mi_pila)) printf("Pila vacia");

    fflush(stdin); getchar();
  return 0;
}
//--------------------------------------------------------------------------------------


void inicializarPila(PILA *p){ p->ultimo = -1; }

int estaVacia(PILA p){ return (p.ultimo == -1); }

int estaLlena(PILA p){ return (p.ultimo == (MAX-1)); }

int insertarNumero(PILA *p,int n){
    if(estaLlena(*p)){
        printf("Pila llena \n");
        return 0;
    }
    p->ultimo++;
    p->numeros[p->ultimo] = n;
  return 1;
}

int extraerNumero(PILA *p){ return p->numeros[p->ultimo--]; }
