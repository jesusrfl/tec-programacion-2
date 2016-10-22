#include<stdio.h>
#include<stdlib.h>

typedef struct Arbol{
    int num;
    struct Arbol *izq;
    struct Arbol *der;
}ARBOL;

ARBOL* crearNodo();
int agregarNodo(ARBOL* *p, int n);
void verArbol(ARBOL *p, int n);
void preOrden(ARBOL *p);
void inOrden(ARBOL *p);
void postOrden(ARBOL *p);
ARBOL* eliminarNodo(ARBOL* *p, int n);
void liberarMemoria(ARBOL* *p);



//---------------------------------------------------------------------------------
int main(){

    ARBOL *arbol = NULL;

    agregarNodo(&arbol,12);
    agregarNodo(&arbol,10);
    agregarNodo(&arbol,14);
    agregarNodo(&arbol,15);
    agregarNodo(&arbol,5);
    agregarNodo(&arbol,13);
    agregarNodo(&arbol,11);

    printf("preOrden:  ");
    preOrden(arbol);
    printf("\n\n");

    printf("inOrden:   ");
    inOrden(arbol);
    printf("\n\n");

    printf("postOrden:  ");
    postOrden(arbol);
    printf("\n\n");

    verArbol(arbol,0);

    printf("\n Eliminando numero 5...\n");
    arbol = eliminarNodo(&arbol,5);
    verArbol(arbol,0);

    printf("\n Eliminando numero 14...\n");
    arbol = eliminarNodo(&arbol,14);
    verArbol(arbol,0);

    printf("\n Eliminando numero 12...\n");
    arbol = eliminarNodo(&arbol,12);
    verArbol(arbol,0);

    liberarMemoria(&arbol);
    fflush(stdin);getchar();
  return 0;
}
//---------------------------------------------------------------------------------



ARBOL* crearNodo(){  return (ARBOL*) malloc(sizeof(ARBOL)); }

int agregarNodo(ARBOL* *p, int n){
    if(*p == NULL){
        *p = crearNodo();
        if(*p == NULL) return 0;
        (*p)->num = n;
        (*p)->izq = NULL;
        (*p)->der = NULL;
        return 1;
    }
    if(n <= (*p)->num) return agregarNodo(&(*p)->izq,n);
    else return agregarNodo(&(*p)->der,n);
}

void verArbol(ARBOL *p, int n){
    int i;
    if(p){
        verArbol(p->der,n+1);
        for(i = 0; i<n; i++) printf("   ");
        printf("%i \n",p->num);
        verArbol(p->izq,n+1);
    }
}

void preOrden(ARBOL *p){
    if(p){
        printf("%i ",p->num);
        preOrden(p->izq);
        preOrden(p->der);
    }
}

void inOrden(ARBOL *p){
    if(p){
        inOrden(p->izq);
        printf("%i ",p->num);
        inOrden(p->der);
    }
}

void postOrden(ARBOL *p){
    if(p){
        postOrden(p->izq);
        postOrden(p->der);
        printf("%i ",p->num);
    }
}

ARBOL* eliminarNodo(ARBOL* *p, int n){
    ARBOL *temp_der,*temp_izq;
    if(!p) return NULL;

        if((*p)->num == n){
            if((*p)->izq==NULL && (*p)->der==NULL){
                free(*p);
                return NULL;
            }else if((*p)->izq == NULL){
                temp_der = (*p)->der;
                free(*p);
                return temp_der;
            }else if((*p)->der == NULL){
                temp_izq = (*p)->izq;
                free(*p);
                return temp_izq;
            }else{
                   temp_der = (*p)->der;
                   temp_izq = (*p)->der;
                   while(temp_izq->izq) temp_izq = temp_izq->izq;
                   temp_izq->izq = (*p)->izq;
                   free(*p);
                   return temp_der;
            }
        }

        if(n <= (*p)->num) (*p)->izq = eliminarNodo(&(*p)->izq,n);
        else (*p)->der = eliminarNodo(&(*p)->der,n);

  return *p;
}

void liberarMemoria(ARBOL* *p){
    if(*p != NULL){
       liberarMemoria(&(*p)->izq);
       liberarMemoria(&(*p)->der);
       free(*p);
    }
}
