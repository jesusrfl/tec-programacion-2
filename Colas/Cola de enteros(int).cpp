/* En este archivo se explican las funciones básicas de una cola con números enteros,
	 de la siguiente manera:
	 				Pos   Num
	                   primero->    [0] = {1}
	 				[1] = {2}
	 				[2] = {3}
	 				[3] = {4}
	         	   ultimo->     [4] = {5}

	  Recordando que en una cola se va recorriendo desde la primera posición, uno por uno,
	  respetando el orden FIFO (First in First out, "Primero en entrar Primero en salir"),
	  queriendo decir que el orden de salida para el ejemplo de arriba debe ser:

	  	                       1 2 3 4 5

	  En este código se hace el uso de una cola circular, para esto se usa una función llamada
	  "obtenerProximo" que mas abajo se explica como funciona, con el fin de re-utilizar el mismo
	  vector en el rango máximo establecido. Por ej, luego de insertar/extraer algunos numeros
	  nuestra cola en el vector podría quedar de la siguiente manera:
      				Pos   Num
                                [0] = {6}
	 	    ultimo->    [1] = {7}
	 			[2] = { }
	 	    primero->   [3] = {4}
	 	         	[4] = {5}
	  Quedando la salida de toda la cola: 4 5 6 7
*/

#include<stdio.h> //Incluir liberías a utilizar

#define MAX 5 ////Definición de una macro para el valor del tamaño total de la cola


//Definición de la estructura que va a ser interpretada como una cola
typedef struct Cola{
    int numeros[MAX]; //Vector para almacenar los numeros
    int primero; //Indicador de la primera posición en la cola
    int ultimo; //Indicador de la última posición de la cola
}COLA;


//Definición de las funciones a utilizar
void inicializarCola(COLA *c);
bool estaVacia(COLA c);
bool estaLlena(COLA c);
int obtenerProximo(int pos);
bool insertarNumero(COLA *c,int num);
int extraerNumero(COLA *c);


//-----------------------------------------------------------------------------------------------------
int main(){

    COLA cola; // Definimos nuestra variable de tipo Cola a utilizar
    inicializarCola(&cola); // Inicializamos la cola. Muy importante

    // Con este ciclo podemos comprobar el funcionamiento de la función "obtenerProximo"
    for(int i=0; i<MAX;i++) printf("posicion:%i proximo:%i\n",i,obtenerProximo(i));

    /* Procedemos a insertar los números del 1 al 6 y comprobamos de una vez que nos dice que
       la cola esta llena cuando intenta insertar el número 6 ya que MAX = 5 */
     for(int i = 1; i<=6; i++){
        if(insertarNumero(&cola,i)) printf("#%i insertado \n",i);
    }

    // Extraemos todos los números mientras la cola no está vacía
    while(!estaVacia(cola)) printf("#%i extraido \n",extraerNumero(&cola));

    // Comprobamos que finalmente esta vacía
    if(estaVacia(cola)) printf("Cola vacia \n");

  fflush(stdin); getchar();// Nos aseguramos que haya una pausa al final del programa
  return 0;
}
//-----------------------------------------------------------------------------------------------------


void inicializarCola(COLA *c){
    // Recibe la cola por referencia e inicializa los valores de los indicadores de posición
    c->primero = 0;
    c->ultimo = -1;
}

bool estaVacia(COLA c){
    /* Recibe la cola por valor y retorna el resultado de la condición.
       Cabe destacar que una cola está vacía cuando el indicador de la
       última posición es igual a -1  */
  return(c.ultimo == -1);
}

bool estaLlena(COLA c){
    /* Recibe la cola por valor y retorna el resultado de la condición.

      -La primera parte de la condición se traduce como:
          "Si el próximo de la última posición es igual a la primera posición"
      por ej: obtenerProximo(4) retorna 0, entonces si la primera posición es igual a 0
            quiere decir que la cola esta llena. Recordando que MAX = 5 y en el vector sería (MAX-1) = 4.
            4 es la última posición en el vector definido.

     -La segunda parte de la condición es para prevenir futuros inconvenientes ya que obtenerProximo(-1)
        retorna 0 y esta función retornaría 'true' si la cola en realidad no está llena. Muy importante esto. */
  return(obtenerProximo(c.ultimo)==c.primero && c.ultimo>=0);
}

int obtenerProximo(int pos){
    /* Recibe una posición y retorna la siguiente posición válida
        del vector, dado el tamaño máximo de este.
        Esto es gracias a la formula (pos+1) % MAX.
        Por ej:
            (0+1)%5 = 1
            (1+1)%5 = 2
            (2+1)%5 = 3
            (3+1)%5 = 4
            (4+1)%5 = 0
        Esto como ya se ha dicho antes, facilita el movimiento circular de la cola en el vector.  */
  return(pos+1)%MAX;
}

bool insertarNumero(COLA *c, int num){
    // Recibe la cola por referencia y el número a insertar

    // Verificamos si la cola está llena
    if(estaLlena(*c)){
        // Si es así, mostramos un mensaje y retornamos 'false'
        printf("Cola llena \n");
        return false;
    }

    /* Al no salirse de la función en la condición anterior, podemos proceder a insertar el número.
        Primero actualizamos el indicador de la última posición y luego le asignamos al vector en esa
        posición el nuevo número */
    c->ultimo = obtenerProximo(c->ultimo);
    c->numeros[c->ultimo] = num;

  return true; // Finalmente retornamos 'true' porque hemos podido insertar el número correctamente
}

int extraerNumero(COLA *c){
    // Recibe la cola por referencia

    /* Primero almacenamos el numero a extraer en una variable porque luego
       el indicador "c->primero" es actualizado */
    int num = c->numeros[c->primero];

    /* Si los dos indicadores son iguales quiere decir que estamos extrayendo el
       último y único elemento en la cola, y por lo tanto necesitamos inicializar
       la cola */
    if(c->primero == c->ultimo) inicializarCola(c);
        /* De no ser iguales, procedemos a actualizar el indicador de la primera posición
            al que le sigue. Todo esto para cumplir con el orden FIFO */
        else c->primero = obtenerProximo(c->primero);
  return num; //Finalmente retornamos la variable "num" que contiene el numero a extraer.
}
