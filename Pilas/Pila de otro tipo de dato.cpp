#include<stdio.h>

#define MAX 7 


typedef struct Moneda{
    float valor; 
    int diametro;
}MONEDA;

typedef struct Pila{
    MONEDA monedas[MAX]; 
    int ultimo;
}PILA;


void inicializarPila(PILA *p);
bool estaVacia(PILA p);
bool estaLlena(PILA p);
bool insertarMoneda(PILA *p, MONEDA m);
MONEDA extraerMoneda(PILA *p);


//---------------------------------------------------------------------------------------------------------------------------------
int main(){

    PILA mi_pila;
    MONEDA moneda; 
    float valores[] = {0.01,0.05,0.10,0.125,0.25,0.50,1}; 
    int diametros[] = {15,17,18,23,20,22,24};

    inicializarPila(&mi_pila);

    for(int i = 0; i<7; i++){
        moneda.valor = valores[i];
        moneda.diametro = diametros[i];
        insertarMoneda(&mi_pila,moneda); 
    }

    while(!estaVacia(mi_pila)){
        moneda = extraerMoneda(&mi_pila);
        printf("Valor: %.2fbs, Diametro: %imm \n",moneda.valor,moneda.diametro);
    }

    fflush(stdin); getchar();
  return 0;
}
//---------------------------------------------------------------------------------------------------------------------------------


void inicializarPila(PILA *p){ p->ultimo = -1; }

bool estaVacia(PILA p){ return (p.ultimo == -1); }

bool estaLlena(PILA p){ return (p.ultimo == (MAX-1)); }

bool insertarMoneda(PILA *p,MONEDA m){
    if(estaLlena(*p)){
        printf("Pila llena \n");
        return false;
    }    
    p->ultimo++;
    p->monedas[p->ultimo] = m;
  return true;
}

MONEDA extraerMoneda(PILA *p){ return p->monedas[p->ultimo--]; }
