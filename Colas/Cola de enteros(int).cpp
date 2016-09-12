#include<stdio.h>

#define MAX 5 


typedef struct Cola{
    int numeros[MAX];
    int primero;
    int ultimo;
}COLA;


void inicializarCola(COLA *c);
bool estaVacia(COLA c);
bool estaLlena(COLA c);
int obtenerProximo(int pos);
bool insertarNumero(COLA *c,int num);
int extraerNumero(COLA *c);


//-----------------------------------------------------------------------------------------------------
int main(){

    COLA cola; 
    inicializarCola(&cola);
    
    for(int i = 1; i<=6; i++){
        /* Se intenta insertar 6 elementos para comprobar que no se puede 
          porque la cola ya estar�a llena al insertar 5.
       */
        if(insertarNumero(&cola,i)) printf("#%i insertado \n",i);
    }

    while(!estaVacia(cola)) printf("#%i extraido \n",extraerNumero(&cola));

    // Comprobando que ha quedado vacia la cola
    if(estaVacia(cola)) printf("Cola vacia \n");

  fflush(stdin); getchar();
  return 0;
}
//-----------------------------------------------------------------------------------------------------


void inicializarCola(COLA *c){    
    c->primero = 0;
    c->ultimo = -1;
}

bool estaVacia(COLA c){ return (c.ultimo == -1); }

bool estaLlena(COLA c){ return (obtenerProximo(c.ultimo)==c.primero && c.ultimo>=0); }

int obtenerProximo(int pos){ return (pos+1)%MAX; } 

bool insertarNumero(COLA *c, int num){
    if(estaLlena(*c)){        
        printf("Cola llena \n");
        return false;
    }
    c->ultimo = obtenerProximo(c->ultimo);
    c->numeros[c->ultimo] = num;
  return true; 
}

int extraerNumero(COLA *c){  
    int num = c->numeros[c->primero];
    if(c->primero == c->ultimo) inicializarCola(c);      
        else c->primero = obtenerProximo(c->primero);
  return num; 
}
