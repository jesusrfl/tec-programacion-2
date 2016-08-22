/*
    Hay dos formas de manejar el uso de memoria cuando se programa,
    por lo menos en C/C++, se puede estática y dinámicamente.

    Estáticamente es lo que ya conocemos, lo que hemos usado siempre.
    Cuando declaramos una variable estamos diciendo que usaremos cierta
    cantidad de memoria para esa variable y esta es reservada. Por ej.
        int num;
         En la memoria se reservará lo que sea necesario para guardar en ella
         un entero, cualquiera en cualquier momento, pero solo un entero.

         También tenemos los vectores, por ej, int numeros[10]. En este se reserva
         la suficiente cantidad de memoria pero solo para que se almacenen 10 enteros,
         no más.

    Esto a la larga es un problema, por el obvio inconveniente de el límite que esto significa.
    Para solventar esto podemos hacer el uso de memoria dinámicamente, solo necesitamos 2 funciones
    de la librería stdlib.h

        1) malloc: Esta función reserva la memoria y retorna la dirección de esta. Recibe como parámetro
                   el tamaño en bytes a reservar.
        2) free: Libera la memoria reservada. Recibe el puntero que contiene la dirección de memoria a liberar.

     Podemos hacer el uso de esas funciones con el objetivo de ir reservando memoria a medida que se va
     necesitando en tiempo de ejecución. A continuación tenemos un ejemplo del funcionamiento de estas 2
     funciones.

 
*/


#include<stdio.h>
#include<stdlib.h>


int main(){

    // En este ejemplo haremos un vector pero con las funciones para el uso de memoria dinámica

    int *x,t; // Declaramos un puntero y una variable para el tamaño del vector

    // Pedimos el tamaño por pantalla
    printf("Cantidad: ");
    scanf("%i",&t);


    /* Reservamos la memoria y guardamos su dirección en x
        1) Tenemos que hacer un casting para que el retorno sea compatible con la variable a utilizar
        2) En el tamaño usamos la función "sizeof" para determinar el tamaño de un entero y lo multiplicamos
            por el tamaño que hemos pedido para el vector */
    x = (int*) malloc(t*sizeof(int));

    // Verificamos que se haya reservado la memoria correctamente
    if(x){
       for(int i=0; i<t; i++) x[i] = i+1; // Inicializamos el vector
       for(int i=0; i<t; i++) printf("%i \n",x[i]); // Imprimimos por pantalla sus valores
       free(x); // Finalmente liberamos la memoria utilizada
    }else printf("No se ha podido reservar la memoria \n");



  fflush(stdin);getchar();// Nos aseguramos que haya una pausa al final del programa
  return 0;
}
