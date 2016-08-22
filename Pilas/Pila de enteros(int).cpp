/* En este archivo se explican las funciones básicas de una pila con números enteros, 
	 de la siguiente manera: 
	 				Pos   Num
	 				[4] = {5}
	 				[3] = {8}
	 				[2] = {3}
	 				[1] = {7}
	 				[0] = {2}
	 										  	
	  Recordando que en una pila se va recorriendo desde el tope, uno por uno, respetando
	  el orden LIFO (Last in First out, "Último en entrar Primero en salir"), queriendo
	  decir que el orden de salida para el ejemplo de arriba debe ser:	
	  	                   
	  	                       5 8 3 7 2
*/

#include<stdio.h> //Incluir liberías a utilizar

#define MAX 5 //Definición de una macro para el valor del tamaño total de la pila


//Definición de la estructura que va a ser interpretada como una pila
typedef struct Pila{
    int numeros[MAX]; //Vector para almacenar los numeros
    int ultimo; //Indicador de la posición actual del último número o tope 
}PILA;


//Definición de las funciones a utilizar
void inicializarPila(PILA *p);
bool estaVacia(PILA p);
bool estaLlena(PILA p);
bool insertarNumero(PILA *p, int n);
int extraerNumero(PILA *p);


//--------------------------------------------------------------------------------------
int main(){
    
    PILA mi_pila; //Declaramos la variable de tipo Pila con el nombre que queramos.
    
    inicializarPila(&mi_pila); //Inicializamos la pila, muy importante.
    
    
    /*Usamos un ciclo for para insertar los números del 1 al 6, de una vez 
       comprobamos que dirá que la pila está llena cuando intente insertar el número 6.*/
    for(int i = 1; i <= 6; i++){
        if(insertarNumero(&mi_pila,i)) printf("#%i insertado \n",i);                 
    } 
    
    //Aquí extraemos cada número mientras la pila no este vacía 
    while(!estaVacia(mi_pila)) printf("#%i extraido \n",extraerNumero(&mi_pila));
    
    //Comprobamos que está vacía la pila
    if(estaVacia(mi_pila)) printf("Pila vacia");
    
    //Nos aseguramos que al final del programa exista una pausa.
    fflush(stdin); getchar();
  return 0;
}
//--------------------------------------------------------------------------------------


void inicializarPila(PILA *p){
    /* 
       En esta función se recibe la pila por referencia para modificar sus valores.
       Este procedimiento es importante ya que si no inicializamos una pila tendremos
       problemas con las posiciones del vector. Queriendo decir que cuando se inserte
       el primer número su posición debe ser 0 y cuando le asignamos el valor de -1 a
       la variable "ultimo" nos aseguramos de que eso pase y así siga el orden
       0,1,2,3,4,5,6,7,8,9...
    */
    p->ultimo = -1;        
}

bool estaVacia(PILA p){
     /*
        Se recibe la pila por valor y se retorna el resultado de la condición.
        Cuando inicializamos una pila y hacemos el llamado a esta función retornara
        verdadero ya que recién le asignamos -1 en la función "inicializarPila" y
        si el caso es en el que hayamos extraídos todos los números igual retornará 
        verdadero ya que al extraer un número iremos decrementando su valor hasta quedar
        en -1 al extraer el último y único número en la pila.         
     */
  return (p.ultimo == -1);
}

bool estaLlena(PILA p){
    /*
       Se recibe la pila por valor y se retorna el resultado de la condición.
       ¿Por què comparar "p.ultimo" con "MAX-1"?. 
       Recordando que se hizo la definición de una macro "MAX" con el valor de
       5 que sería el tope de la pila y que "último" almacena la posición en 
       el vector del último número insertado, sabremos que la pila estará llena 
       cuando el valor de "ultimo" sea igual a 4 (MAX-1) porque las posiciones 
       serían 0,1,2,3,4 (5 números en total). Entonces si se cumple que 
       "ultimo" == 4, retornará verdadero, de lo contrario retornará falso.
    */
  return (p.ultimo == (MAX-1));
}

bool insertarNumero(PILA *p,int n){
    //Se recibe la pila por referencia y el número a insertar 
    
    //Se comprueba que la pila no este llena
    if(estaLlena(*p)){
    	   /* Si está llena la pila entonces mostramos un mensaje y se sale de 
    	   	 la función retornando falso. */
        printf("Pila llena \n");
        return false;
    }
    
    /*Al no salirse de la función con la condición de arriba quiere decir que podremos
       insertar el número porque no está llena la pila */
    
    //Se incrementa la posición del último para asignarle el nuevo valor
    p->ultimo++; 
    p->numeros[p->ultimo] = n;
        
  return true; //finalmente retornamos verdadero porque hemos podido insertar el nuevo número
}

int extraerNumero(PILA *p){ 
  /* 
     Se recibe la pila por referencia y retornamos el último número en la pila cumpliendo con el orden LIFO.
  	   
  	   Accedemos al vector con el valor actual de la variable "ultimo" y se decrementa al instante. Si quisieramos
  	   hacer lo contrario, sería p->numeros[--p->ultimo]; (decrementando primero y luego accediendo al vector con 
  	   el nuevo valor).
  */       
  return p->numeros[p->ultimo--];
}
