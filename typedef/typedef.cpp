#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Estudiante{
       char Cedula[10];
       char Nombre[20];
       char Apellido[20];
       int Edad;       
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
    fflush(stdin);gets(est.Cedula);
    printf("Nombre:      ");
    fflush(stdin);gets(est.Nombre);
    printf("Apellido:    ");
    fflush(stdin);gets(est.Apellido);
    printf("Edad:        ");
    fflush(stdin); scanf("%i",&est.Edad);
  return est;    
}

void mostrarDatos(ESTUDIANTE est){
    printf("Cedula:      %s \n",est.Cedula);
    printf("Nombre:      %s \n",est.Nombre);
    printf("Apellido:    %s \n",est.Apellido);
    printf("Edad:        %i \n",est.Edad);
}

void modificarDatos(ESTUDIANTE *est){
    printf("Nombre:      ");
    fflush(stdin);gets(est->Nombre);
    printf("Apellido:    ");
    fflush(stdin);gets(est->Apellido);
    printf("Edad:        ");
    fflush(stdin); scanf("%i",&est->Edad);
}

