/*
    El concepto de recursividad puede referirse a la habilidad que
    tiene un bloque de instrucciones de ejecutarse "n" veces con
    una condición de parada establecida.

    Ese concepto lo podemos adaptar a una función cualquiera en programación
    obteniendo así una función recursiva. Esta no es más que una función que
    se llama a si misma hasta que se cumpla su condición de parada.

    Al principio suele ser costoso entender como trabaja una función recursiva
    pero poco a poco se va aclarando y más aún cuando se toca el tema de Arboles,
    que veremos más adelante.

    A continuación se muestran unos ejemplos de funciones recursivas...

*/


//Líbreria necesaria
#include<stdio.h>

//Definición de las funciones recursivas
int factorial(int n);
int division(int a,int b);
int multiplicacion(int a, int b);
int potencia(int a, int b);



int main(){

   //Pruebas de las funciones
   printf("Factorial:         %i\n",factorial(6));
   printf("Division:          %i\n",division(8,2));
   printf("Multiplicacion:    %i\n",multiplicacion(2,8));
   printf("Potencia:          %i\n",potencia(3,3));


  fflush(stdin); getchar(); //Nos aseguramos que haya una pausa al final del programa
  return 0;
}


int factorial(int n){
    /*
        El ejemplo más común que se suele utilizar es el
        del factorial ya que su fórmula como tal se puede
        expresar de manea recursiva, de la siguiente manera:

        n! = n * n-1!
        "El factorial de un número es igual a la multiplicación
         de dicho número por el factorial del número réstandole 1"

         Por ej:

         3! = 3 x 2 x 1 = 6 (Normalmente)

         Entonces...
         3! = 3 * 3-1!
                    2! = 2 * 2-1!
                               1! = 1 * 1-1!
                                          0! = 1

         Cuando tenemos todos los resultados:
         3! = 3 * 2 * 1 * 1 = 6


       Para el desarrollo de la función sabemos entonces
       que la función ya no debe llamarse cuando el número
       a calcular el factorial sea igual 0. Esa será la
       condición de parada */

    if(n == 0) return 1; // La recursividad se detiene al retornar un valor.
        /* Si n == 0 retornamos 1 porque el factorial de 0 es 1.
            De lo contrario, si no hemos llegado a 0, retornamos la multiplicación del número
            por el retorno de la llamada a la función, con el valor del número menos 1. Esto hará
            que inicie la recursividad */
        return n * factorial(n-1); // Retornamos la multiplicación como se describe en la fórmula
}

int division(int a,int b){
    /* Con esta función hacemos una división entera
       utilizando el método de la resta. Teniendo en
       cuenta que la veces que le restemos el divisor
       al dividendo hasta que este sea igual 0 es el
       resultado de la división. Por ej:
       10/2 = 5
       Para que esa división se de hay que restarle el 2 al 10
       unas 5 veces... 10-2 = 8-2 = 6-2 = 4-2 = 2-2 = 0

        Tenemos entonces que nuestra condición de parada sería cuando
        a sea menor o igual que 0 */
    if(a <= 0) return 0;
        /* De lo contrario retornamos 1 + el llamado a la función
           haciendo la resta al dividendo. De esta manera solo contamos
           las veces que se hace la resta (llamada a la función).
        */
        return 1 + division(a-b,b);
}

int multiplicacion(int a, int b){
    /* La multiplicación entera se puede expresar como la
       suma de a, restandole 1 a b repetidamente hasta que
       b sea menor o igual a 0

        Por ej:
                 a     a     a     a     a     a
        2*6 =    2  +  2  +  2  +  2  +  2  +  2 = 12
               (6-1) (5-1) (4-1) (3-1) (2-1) (1-1)
                 b     b     b     b     b     b
    */
    if(b <= 0) return 0; // Condición de parada
        return a + multiplicacion(a,b-1); // Retorno acumulador
}

int potencia(int a, int b){
    /*
       La función de la potencia es parecida a la de multiplicación,
       solo que aqui la condición de parada es si b == 0, retorna 1,
       y el retorno es una multplicación de "a" con el retorno de la
       llamada a la función restandole 1 a b.
       Por ej:
        2^3 = 2 * 2^(3-1)
                      2^2 = 2 * 2^(2-1)
                                    2^1 = 2 * 2^(1-1)
                                                   1
        entonces tenemos que:

        2^3 = 2 * 2 * 2 * 1 = 8

     */
    if(b == 0) return 1; //Condición de parada
        return a * potencia(a,b-1); //Retorno acumulador
}
