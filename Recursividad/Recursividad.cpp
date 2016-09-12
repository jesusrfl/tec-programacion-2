#include<stdio.h>


int factorial(int n);
int division(int a,int b);
int multiplicacion(int a, int b);
int potencia(int a, int b);
int contar(char *c);


int main(){

    printf("Factorial:         %i\n",factorial(5));
    printf("Division:          %i\n",division(8,2));
    printf("Multiplicacion:    %i\n",multiplicacion(2,8));
    printf("Potencia:          %i\n",potencia(3,3));
    printf("Contar:            %i\n",contar("hola"));

  fflush(stdin); getchar();
  return 0;
}


int factorial(int n){ return (n==1 || n==0) ? 1 : n*factorial(n-1); }

int division(int a,int b){ return (a<=0) ? 0 : 1+division(a-b,b); }

int multiplicacion(int a, int b){ return (b==0) ? 0 : a+multiplicacion(a,b-1); }

int potencia(int a, int b){ return (b==0) ? 1 : a*potencia(a,b-1); }

int contar(char *c){ return (*c=='\0') ? 0 : 1+contar(++c); }

