#include<stdio.h>
#include<stdlib.h>


int main(){

    int *x,*j,t,i=0;


    printf("Cantidad: ");
    scanf("%i",&t);

    x = (int*) malloc(t*sizeof(int));

    if(x){
       for(int i=0; i<t; i++) x[i] = i+1;
       for(int i=0; i<t; i++) printf("%i \n",x[i]);
       free(x);
    }else printf("No se ha podido reservar la memoria \n");

  fflush(stdin);getchar();
  return 0;
}
