#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Estudiante{
       char Cedula[10];
       char Nombre[20];
       char Apellido[20];
       int Edad;
}ESTUDIANTE;

typedef struct Nodo{
        ESTUDIANTE Estudiante;        
        struct Nodo *Sig;
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
    fflush(stdin);scanf("%s",cedula);

    temp = buscarEstudiante(p,cedula);

    if(!temp){
       agregarNodo(p,crearEstudiante(cedula));
       printf("\nEl siguiente estudiante ha sido agregado a la lista: \n");
       temp = buscarEstudiante(p,cedula);
       mostrarEstudiante(temp->Estudiante);
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
                fflush(stdin);scanf("%s",cedula);

                temp = buscarEstudiante(p,cedula);

                if(temp){
                   modificarEstudiante(&temp->Estudiante);
                   printf("\nEl siguiente estudiante ha sido modificado en la lista: \n");
                   mostrarEstudiante(temp->Estudiante);
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
                fflush(stdin);scanf("%s",cedula);

                temp = buscarEstudiante(p,cedula);

                if(temp){
                   eliminarEstudiante(p,temp->Estudiante.Cedula);
                   printf("\nEl estudiante con la cedula '%s' ha sido eliminado correctamente. \n",cedula);
                }else printf("No existe un estudiante registrado con la cedula introducida");
        }

   guardarDatos(p);
   fflush(stdin); getchar();
}


NODO* crearNodo(){ return ((NODO*) malloc(sizeof(NODO))); }

ESTUDIANTE crearEstudiante(char *cedula){
    ESTUDIANTE est;
    strcpy(est.Cedula,cedula);
    printf("Nombre:      ");
    fflush(stdin);scanf("%s",est.Nombre);
    printf("Apellido:    ");
    fflush(stdin);scanf("%s",est.Apellido);
    printf("Edad:        ");
    fflush(stdin); scanf("%i",&est.Edad);
  return est;
}

bool agregarNodo(NODO* &p,ESTUDIANTE est){
     if(!p){
        p = crearNodo();
        p->Estudiante = est;  
        p->Sig = NULL;
        return true;
     }
     agregarNodo(p->Sig,est);
}

NODO* buscarEstudiante(NODO *p,char *cedula){
    if(!p) return NULL;
    /* Como la función retorna 0 cuando son iguales podemos usar !strcmp(), que sería verdadero
       cuando las cedulas coincidan */
    if(!strcmp(cedula,p->Estudiante.Cedula))
         return p;
    buscarEstudiante(p->Sig,cedula);
}

void modificarEstudiante(ESTUDIANTE *est){
    printf("Nombre:      ");
    fflush(stdin);scanf("%s",est->Nombre);
    printf("Apellido:    ");
    fflush(stdin);scanf("%s",est->Apellido);
    printf("Edad:        ");
    fflush(stdin);scanf("%i",&est->Edad);
}

int contarNodos(NODO *p){ return (!p) ? 0 : 1+contarNodos(p->Sig); }

void mostrarEstudiante(ESTUDIANTE est){
    printf("Cedula:      %s \n",est.Cedula);
    printf("Nombre:      %s \n",est.Nombre);
    printf("Apellido:    %s \n",est.Apellido);
    printf("Edad:        %i \n\n",est.Edad);
}

void mostrarLista(NODO *p){
    if(!p) return;
    mostrarEstudiante(p->Estudiante);
    mostrarLista(p->Sig);
}

bool eliminarEstudiante(NODO* &p,char *cedula){
    NODO *temp;
    if(!p) return false;
    if(!strcmp(cedula,p->Estudiante.Cedula)){
        temp = p;
        p = p->Sig;
        free(temp);
        return true;
    }
    eliminarEstudiante(p->Sig,cedula);
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
    liberarMemoria(p->Sig);
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
    fwrite(&p->Estudiante,sizeof(ESTUDIANTE),1,archivo);
    guardarLista(p->Sig,archivo);
}

