#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Estudiante{
       char cedula[10];
       char nombre[20];
       char apellido[20];
       int edad;
}ESTUDIANTE;

ESTUDIANTE pedirDatos();
void mostrarDatos(ESTUDIANTE est);
void modificarDatos(ESTUDIANTE *est);

int main(){

    ESTUDIANTE estudiante;
    estudiante = pedirDatos();
    printf("\n\n------ Datos ------\n");
    mostrarDatos(estudiante);
    printf("\n\n------ Modificar datos ------\n");
    modificarDatos(&estudiante);
    printf("\n\n------ Datos ------\n");
    mostrarDatos(estudiante);

    fflush(stdin);getchar();
  return 0;
}


ESTUDIANTE pedirDatos(){
    ESTUDIANTE est;
    printf("Cedula:      ");
    fflush(stdin); gets(est.cedula);
    printf("Nombre:      ");
    fflush(stdin); gets(est.nombre);
    printf("Apellido:    ");
    fflush(stdin); gets(est.apellido);
    printf("Edad:        ");
    fflush(stdin); scanf("%i",&est.edad);
  return est;
}

void mostrarDatos(ESTUDIANTE est){
    printf("Cedula:      %s \n",est.cedula);
    printf("Nombre:      %s \n",est.nombre);
    printf("Apellido:    %s \n",est.apellido);
    printf("Edad:        %i \n",est.edad);
}

void modificarDatos(ESTUDIANTE *est){
    printf("Nombre:      ");
    fflush(stdin); gets(est->nombre);
    printf("Apellido:    ");
    fflush(stdin); gets(est->apellido);
    printf("Edad:        ");
    fflush(stdin); scanf("%i",&est->edad);
}

