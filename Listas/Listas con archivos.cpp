#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Estudiante{
       char cedula[10];
       char nombre[20];
       char apellido[20];
       int edad;
}ESTUDIANTE;

typedef struct Nodo{
        ESTUDIANTE estudiante;
        struct Nodo *sig;
}NODO;

void insertarDatos(NODO* &p);
void mostrarDatos(NODO *p);
void modificarDatos(NODO* &p);
void eliminarDatos(NODO* &p);
NODO* crearNodo();
ESTUDIANTE crearEstudiante(char *cedula);
bool agregarNodo(NODO* &p,ESTUDIANTE est);
NODO* buscarEstudiante(NODO *p,char *cedula);
int contarNodos(NODO *p);
void mostrarEstudiante(ESTUDIANTE est);
void mostrarLista(NODO *p);
void modificarEstudiante(ESTUDIANTE *est);
bool eliminarEstudiante(NODO* &p,char *cedula);
void liberarMemoria(NODO* &p);
void crearArchivo();
void cargarDatos(NODO* &p);
void guardarDatos(NODO *p);
void guardarLista(NODO *p, FILE *archivo);


//***************************************************************************************************************
int main(){

    NODO *lista = NULL;
    char op;

    crearArchivo(); // Si no ha sido creado
    cargarDatos(lista);

    do{
         system("cls");
         printf(" 1) Insertar  \n");
         printf(" 2) Mostrar   \n");
         printf(" 3) Modificar \n");
         printf(" 4) Eliminar  \n");
         printf(" 5) Salir \n");
         fflush(stdin); op = getchar();

         switch(op){
             case '1': insertarDatos(lista);break;
             case '2': mostrarDatos(lista);break;
             case '3': modificarDatos(lista);break;
             case '4': eliminarDatos(lista);break;
             case '5': op = 'Z'; break;
             default: printf("Opcion invalida"); fflush(stdin); getchar();
         }
    }while(op != 'Z');

    liberarMemoria(lista);
  return 0;
}
//***************************************************************************************************************


void insertarDatos(NODO* &p){
    char cedula[10];
    NODO *temp;

    system("cls");
    printf("Cedula: ");
    fflush(stdin); gets(cedula);

    temp = buscarEstudiante(p,cedula);

    if(!temp){
       ESTUDIANTE est = crearEstudiante(cedula);
       agregarNodo(p,est);
       printf("\nEl siguiente estudiante ha sido agregado a la lista: \n");
       mostrarEstudiante(est);
    }else printf("Ya existe un estudiante registrado con la cedula introducida");

   guardarDatos(p);
   fflush(stdin); getchar();
}

void mostrarDatos(NODO *p){
     system("cls");
     if(contarNodos(p) != 0) mostrarLista(p);
         else printf("No hay datos registrados");
    fflush(stdin); getchar();
}

void modificarDatos(NODO* &p){
    char cedula[10];
    NODO *temp;

    system("cls");
    if(!contarNodos(p)) printf("No hay datos registrados");
        else{
                printf("Cedula: ");
                fflush(stdin); gets(cedula);

                temp = buscarEstudiante(p,cedula);

                if(temp){
                   modificarEstudiante(&temp->estudiante);
                   printf("\nEl siguiente estudiante ha sido modificado en la lista: \n");
                   temp = buscarEstudiante(p,cedula);
                   mostrarEstudiante(temp->estudiante);
                }else printf("No existe un estudiante registrado con la cedula introducida");
        }

   guardarDatos(p);
   fflush(stdin); getchar();
}

void eliminarDatos(NODO* &p){
    char cedula[10];
    NODO *temp;

    system("cls");
    if(!contarNodos(p)) printf("No hay datos registrados");
        else{
                printf("Cedula: ");
                fflush(stdin); gets(cedula);

                temp = buscarEstudiante(p,cedula);

                if(temp){
                   eliminarEstudiante(p,temp->estudiante.cedula);
                   printf("\nEl estudiante con la cedula '%s' ha sido eliminado correctamente. \n",cedula);
                }else printf("No existe un estudiante registrado con la cedula introducida");
        }

   guardarDatos(p);
   fflush(stdin); getchar();
}


NODO* crearNodo(){ return ((NODO*) malloc(sizeof(NODO))); }

ESTUDIANTE crearEstudiante(char *cedula){
    ESTUDIANTE est;
    strcpy(est.cedula,cedula);
    printf("Nombre:      ");
    fflush(stdin); gets(est.nombre);
    printf("Apellido:    ");
    fflush(stdin); gets(est.apellido);
    printf("Edad:        ");
    fflush(stdin); scanf("%i",&est.edad);
  return est;
}

bool agregarNodo(NODO* &p,ESTUDIANTE est){
     if(!p){
        p = crearNodo();
        p->estudiante = est;
        p->sig = NULL;
        return true;
     }
     agregarNodo(p->sig,est);
}

NODO* buscarEstudiante(NODO *p,char *cedula){
    while(p){
        if(!strcmp(cedula,p->estudiante.cedula)) return p;
        p = p->sig;
    }
  return NULL;
}

void modificarEstudiante(ESTUDIANTE *est){
    printf("Nombre:      ");
    fflush(stdin); gets(est->nombre);
    printf("Apellido:    ");
    fflush(stdin); gets(est->apellido);
    printf("Edad:        ");
    fflush(stdin); scanf("%i",&est->edad);
}

int contarNodos(NODO *p){ return (!p) ? 0 : 1+contarNodos(p->sig); }

void mostrarEstudiante(ESTUDIANTE est){
    printf("Cedula:      %s \n",est.cedula);
    printf("Nombre:      %s \n",est.nombre);
    printf("Apellido:    %s \n",est.apellido);
    printf("Edad:        %i \n\n",est.edad);
}

void mostrarLista(NODO *p){
    if(!p) return;
    mostrarEstudiante(p->estudiante);
    mostrarLista(p->sig);
}

bool eliminarEstudiante(NODO* &p,char *cedula){
    NODO *temp;
    if(!p) return false;
    if(!strcmp(cedula,p->estudiante.cedula)){
        temp = p;
        p = p->sig;
        free(temp);
        return true;
    }
    eliminarEstudiante(p->sig,cedula);
}

void crearArchivo(){
     FILE *archivo = fopen("datos.dat","rb");
     if(!archivo){
        archivo = fopen("datos.dat","wb");
     }
  fclose(archivo);
}

void liberarMemoria(NODO* &p){
    if(!p) return;
    liberarMemoria(p->sig);
    free(p);
}

void cargarDatos(NODO* &p){
     ESTUDIANTE temp_est;
     FILE *archivo = fopen("datos.dat","rb");
     if(archivo){
        fread(&temp_est,sizeof(ESTUDIANTE),1,archivo);
        while(!feof(archivo)){
            agregarNodo(p,temp_est);
            fread(&temp_est,sizeof(ESTUDIANTE),1,archivo);
        }
     }
     fclose(archivo);
}

void guardarDatos(NODO *p){
     FILE *archivo = fopen("datos.dat","wb");
     if(archivo){
        guardarLista(p,archivo);
     }
     fclose(archivo);
}

void guardarLista(NODO *p,FILE *archivo){
    if(!p) return;
    fwrite(&p->estudiante,sizeof(ESTUDIANTE),1,archivo);
    guardarLista(p->sig,archivo);
}

