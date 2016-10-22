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
int estaVacia(PILA p);
int estaLlena(PILA p);
int insertarMoneda(PILA *p, MONEDA m);
MONEDA extraerMoneda(PILA *p);


//---------------------------------------------------------------------------------------------------------------------------------
int main(){

    PILA mi_pila;
    MONEDA moneda;
    float valores[] = {0.01,0.05,0.10,0.125,0.25,0.50,1};
    int diametros[] = {15,17,18,23,20,22,24};
    int i;

    inicializarPila(&mi_pila);

    for(i = 0; i<7; i++){
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

int estaVacia(PILA p){ return (p.ultimo == -1); }

int estaLlena(PILA p){ return (p.ultimo == (MAX-1)); }

int insertarMoneda(PILA *p,MONEDA m){
    if(estaLlena(*p)){
        printf("Pila llena \n");
        return 0;
    }
    p->ultimo++;
    p->monedas[p->ultimo] = m;
  return 1;
}

MONEDA extraerMoneda(PILA *p){ return p->monedas[p->ultimo--]; }
