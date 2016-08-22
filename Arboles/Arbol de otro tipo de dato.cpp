/*
    En este archivo se hace la representación de un Árbol
    de otro tipo de dato definido, en este caso un Libro.
    Estarán ordenados por año.
*/


#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Definición del tipo de dato Libro
typedef struct Libro{
	int ID; // Año del libro
	char titulo[20]; 
	char autor[20]; 	
}LIBRO;

typedef struct Arbol{
    LIBRO libro;
    struct Arbol *izq;
    struct Arbol *der;
}ARBOL;



ARBOL* crearNodo();
bool agregarNodo(ARBOL* &p, int id,char *titulo, char *autor);
void inOrden(ARBOL *p);
ARBOL* eliminarNodo(ARBOL* &p,char *titulo);
void verArbol(ARBOL *p,int n);
void liberarMemoria(ARBOL* &p);



//------------------------------------------------------------------------------------------------------------
int main(){

    ARBOL *arbol = NULL; 

    //Agregamos los libros pasando los datos a la función "agregarNodo"
    agregarNodo(arbol,1866,"Crimen y castigo","Fiodor Dostoievski");
    agregarNodo(arbol,1603,"Hamlet","William Shakespeare");
    agregarNodo(arbol,1725,"Los viajes de Gulliver","Jonathan Swift");
    agregarNodo(arbol,1926,"El castillo","Franz Kafka");
    agregarNodo(arbol,1913,"Hijos y amantes","D. H. Lawrence");
    agregarNodo(arbol,1946,"Zorba, el griego","Nikos Kazantzakis");
    agregarNodo(arbol,1595,"Ensayos","Michel de Montaigne");
    verArbol(arbol,0);
    
    //Mostramos los datos por año en orden
    printf("\n\n");
    inOrden(arbol);
    printf("\n\n");

   	// Probamos la función "eliminarNodo"
    printf("\n Eliminando Crimen y castigo...\n");
    arbol = eliminarNodo(arbol,"Crimen y castigo");
    verArbol(arbol,0);


    liberarMemoria(arbol);

    fflush(stdin);getchar(); // Nos aseguramos que haya una pausa al final del programa
  return 0;
}
//------------------------------------------------------------------------------------------------------------



ARBOL* crearNodo(){
  return (ARBOL*) malloc(sizeof(ARBOL));
}

bool agregarNodo(ARBOL* &p, int id, char *titulo, char *autor){
    if(!p){       
        p = crearNodo();
        if(!p) return false; 
		//Asignamos los atributos recibidos
		p->libro.ID = id;      
		strcpy(p->libro.titulo,titulo);  
		strcpy(p->libro.autor,autor);			
        p->izq = NULL;
        p->der = NULL;
        return true;
    }
    
    if(id <= p->libro.ID) return agregarNodo(p->izq,id,titulo,autor); 
        else return agregarNodo(p->der,id,titulo,autor);
}

void verArbol(ARBOL *p, int n){
    //Verificamos que haya un nodo
    if(p){
        verArbol(p->der,n+1);  
        for(int i = 0; i<n; i++) printf("   ");
        printf("%i \n",p->libro.ID);
        verArbol(p->izq,n+1);
    }
}

void inOrden(ARBOL *p){
    if(p){
        inOrden(p->izq);
        printf("%i.   %s.   %s. \n",p->libro.ID,p->libro.titulo,p->libro.autor); 
        inOrden(p->der);
    }
}

ARBOL* eliminarNodo(ARBOL* &p, char *titulo){
    ARBOL *temp_der,*temp_izq;
    if(!p) return NULL;
    	
		/* Para eliminar un libro por titulo lo hacemos recorriendo en post-orden
    		ya que el atributo principal de recorrido es el ID(año) */
    		
    	p->izq = eliminarNodo(p->izq,titulo);
    	p->der = eliminarNodo(p->der,titulo);
    	
    	//Comparamos los titulos(el del nodo con el recibido en la función)
        if(!strcmp(p->libro.titulo,titulo)){           
                if(!p->izq && !p->der){                   
                    free(p);
                    return NULL;
                }else if(!p->izq){                        
                        temp_der = p->der;
                        free(p);
                        return temp_der;
                }else if(!p->der){                       
                        temp_izq = p->izq; 
			free(p);
                        return temp_izq;
                }else{                       
                       temp_der = p->der; 
                       temp_izq = p->der;
                       while(temp_izq->izq) temp_izq = temp_izq->izq;
                       temp_izq->izq = p->izq;
                       free(p);
                       return temp_der;
                     }
        } 
        
  return p;
}

void liberarMemoria(ARBOL* &p){
    if(p){       
       liberarMemoria(p->izq);
       liberarMemoria(p->der); 
       free(p);
    }
}


