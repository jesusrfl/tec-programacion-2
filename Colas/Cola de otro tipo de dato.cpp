/*
    En este archivo se muestra un ejemplo de como sería
    una cola con otro tipo de dato definido, en este caso
    un "Automóvil".

    El ejemplo simula una cola en una gasolinera.
*/

#include<stdio.h>
#include<string.h>

#define MAX 5


//Definición del tipo de dato AUTOMOVIL
typedef struct Automovil{
    char descripcion[35]; // Descripción del automóvil
    float tanque_gasolina; // Porcentaje de gasolina en el tanque
}AUTOMOVIL;

typedef struct Cola{
    AUTOMOVIL automoviles[MAX]; // Vector de automóviles
    int primero;
    int ultimo;
}COLA;


void inicializarCola(COLA *c);
bool estaVacia(COLA c);
bool estaLlena(COLA c);
int obtenerProximo(int pos);
bool insertarAutomovil(COLA *c,AUTOMOVIL a);
AUTOMOVIL atenderAutomovil(COLA *c);


//------------------------------------------------------------------------------------------------------------------------------------
int main(){

    COLA cola;
    AUTOMOVIL automovil; //Declaramos variable de tipo AUTOMOVIL

    //Vectores con valores para los automóviles
    char descripciones[][35] = { "Lamborghini Veneno Roadster",
                                  "Lykan Hypersports",
                                  "Bugatti Veyron Super Sports",
                                  "Aston Martin One-77",
                                  "Koenigsegg Agera R"
                                };
    float tanques[] = {50,70,10,25,30};

    inicializarCola(&cola);

    //Insertamos los 5 automóviles a la cola
    for(int i=0; i<=4; i++){
        //Asignamos los datos de los vectores a las variables de "automovil"
        strcpy(automovil.descripcion,descripciones[i]);
        automovil.tanque_gasolina = tanques[i];
        insertarAutomovil(&cola,automovil); // Insertamos en la cola
        printf("Insertado: %s, Tanque: %.2f%% \n",automovil.descripcion,automovil.tanque_gasolina);
    }

    printf("\n \n");

    while(!estaVacia(cola)){
        automovil = atenderAutomovil(&cola); // Le asignamos a la variable el retorno de la función que es de tipo AUTOMOVIL
        printf("Atendido: %s, Tanque: %.2f%% \n",automovil.descripcion,automovil.tanque_gasolina);
    }

  fflush(stdin); getchar();// Nos aseguramos que haya una pausa al final del programa
  return 0;
}
//------------------------------------------------------------------------------------------------------------------------------------

void inicializarCola(COLA *c){
    c->primero = 0;
    c->ultimo = -1;
}

bool estaVacia(COLA c){
  return(c.ultimo == -1);
}

bool estaLlena(COLA c){
  return(obtenerProximo(c.ultimo)==c.primero && c.ultimo>=0);
}

int obtenerProximo(int pos){
  return(pos+1)%MAX;
}

bool insertarAutomovil(COLA *c, AUTOMOVIL a){
    if(estaLlena(*c)){
        printf("Cola llena \n");
        return false;
    }
    c->ultimo = obtenerProximo(c->ultimo);
    c->automoviles[c->ultimo] = a;
  return true;
}

AUTOMOVIL atenderAutomovil(COLA *c){
    AUTOMOVIL a = c->automoviles[c->primero];
    a.tanque_gasolina = 100; // "LLenamos el tanque"
    if(c->primero == c->ultimo) inicializarCola(c);
        else c->primero = obtenerProximo(c->primero);
  return a;
}
