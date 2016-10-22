#include<stdio.h>
#include<string.h>

#define MAX 5


typedef struct Automovil{
    char descripcion[35];
    float tanque_gasolina;
}AUTOMOVIL;

typedef struct Cola{
    AUTOMOVIL automoviles[MAX];
    int primero;
    int ultimo;
}COLA;


void inicializarCola(COLA *c);
int estaVacia(COLA c);
int estaLlena(COLA c);
int obtenerProximo(int pos);
int insertarAutomovil(COLA *c,AUTOMOVIL a);
AUTOMOVIL atenderAutomovil(COLA *c);


//------------------------------------------------------------------------------------------------------------------------------------
int main(){

    COLA cola;
    AUTOMOVIL automovil;
    int i;
    char descripciones[][35] = { "Lamborghini Veneno Roadster",
                                  "Lykan Hypersports",
                                  "Bugatti Veyron Super Sports",
                                  "Aston Martin One-77",
                                  "Koenigsegg Agera R"
                                };
    float tanques[] = {50,70,10,25,30};

    inicializarCola(&cola);

    for(i=0; i<5; i++){
        strcpy(automovil.descripcion,descripciones[i]);
        automovil.tanque_gasolina = tanques[i];
        insertarAutomovil(&cola,automovil);
        printf("Insertado: %s, Tanque: %.2f%% \n",automovil.descripcion,automovil.tanque_gasolina);
    }

    printf("\n \n");

    while(!estaVacia(cola)){
        automovil = atenderAutomovil(&cola);
        printf("Atendido: %s, Tanque: %.2f%% \n",automovil.descripcion,automovil.tanque_gasolina);
    }

  fflush(stdin); getchar();
  return 0;
}
//------------------------------------------------------------------------------------------------------------------------------------

void inicializarCola(COLA *c){
    c->primero = 0;
    c->ultimo = -1;
}

int estaVacia(COLA c){ return (c.ultimo == -1); }

int estaLlena(COLA c){ return (obtenerProximo(c.ultimo)==c.primero && c.ultimo>=0); }

int obtenerProximo(int pos){ return (pos+1)%MAX; }

int insertarAutomovil(COLA *c, AUTOMOVIL a){
    if(estaLlena(*c)){
        printf("Cola llena \n");
        return 0;
    }
    c->ultimo = obtenerProximo(c->ultimo);
    c->automoviles[c->ultimo] = a;
  return 1;
}

AUTOMOVIL atenderAutomovil(COLA *c){
    AUTOMOVIL a = c->automoviles[c->primero];
    a.tanque_gasolina = 100;
    if(c->primero == c->ultimo) inicializarCola(c);
    else c->primero = obtenerProximo(c->primero);
  return a;
}
