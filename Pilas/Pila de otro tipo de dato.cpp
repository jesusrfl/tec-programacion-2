/*
    En este archivo se muestra un ejemplo de como sería
    una pila con otro tipo de dato definido, en este caso
    una "Moneda".

*/

#include<stdio.h>

#define MAX 7 // Definimos una macro para almacenar un máximo de 7 monedas

// Definición del tipo de dato Moneda
typedef struct Moneda{
    float valor; // Valor de la moneda
    int diametro; // Diámetro en mm de la Moneda
}MONEDA;

typedef struct Pila{
    MONEDA monedas[MAX]; // Vector de tipo MONEDA
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
    MONEDA moneda; // Declaración de variable a utilizar
    float valores[] = {0.01,0.05,0.10,0.125,0.25,0.50,1}; // Vector con valores de las monedas
    int diametros[] = {15,17,18,23,20,22,24}; // Vector con diametros de las monedas

    inicializarPila(&mi_pila);

    // Insertamos las 7 monedas
    for(int i = 0; i<=6; i++){
    /* Le asignamos los valores de los vectores a la variable de tipo MONEDA
        declarada previamente */
        moneda.valor = valores[i];
        moneda.diametro = diametros[i];
        insertarMoneda(&mi_pila,moneda); // Insertamos la moneda ya inicializada
    }

    // Extraemos cada moneda mientras la pila no esté vacia
    while(!estaVacia(mi_pila)){
        moneda = extraerMoneda(&mi_pila); // Le asignamos a la variable moneda el retorno de la función que será de tipo MONEDA
        printf("Valor: %.2fbs, Diametro: %imm \n",moneda.valor,moneda.diametro); // Mostramos los valores de las variables
    }

    fflush(stdin); getchar();// Nos aseguramos que haya una pausa al final del programa
  return 0;
}
//---------------------------------------------------------------------------------------------------------------------------------


void inicializarPila(PILA *p){
    p->ultimo = -1;
}

bool estaVacia(PILA p){
  return (p.ultimo == -1);
}

bool estaLlena(PILA p){
  return (p.ultimo == (MAX-1));
}

bool insertarMoneda(PILA *p,MONEDA m){
    if(estaLlena(*p)){
        printf("Pila llena \n");
        return false;
    }
    p->ultimo++;
    p->monedas[p->ultimo] = m;
  return true;
}

MONEDA extraerMoneda(PILA *p){
  return p->monedas[p->ultimo--];
}
