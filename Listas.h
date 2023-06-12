#include <stdio.h>			//  Para la I/O del programa
#include <stdlib.h>			//  Para las rutinas de utiler�a 
#include <malloc.h>			//  PAra la memoria din�mica

#define pausa system("pause")	//  Pausa en la ejecucuin del programa
#define cls sysstem("cls")		//  PAra borrar pantalla

struct Nodo 
{
	char info;
	struct Nodo *sig;
};								// Creando un nuevo tipo de dato

typedef struct Nodo nodo;		//  Se define formalemnte como tipo de dato

//  Prototipos de Funci�n 
nodo *insert(nodo *raiz, char dato);
void imprimeLista(nodo *raiz);
nodo *insert1(nodo *raiz, char dato);
nodo *insertn(nodo *raiz, char dato, int pos);
nodo *remueve(nodo *raiz, char *dato);
nodo *remueve1(nodo *raiz, char *dato);
nodo *remueven(nodo *raiz, int pos,char *dato);

// Funciones

nodo *insert(nodo *raiz, char dato)
{
	nodo *nuevo = NULL;			//  Apuntador para el nuevo nodo
	nuevo = (nodo *) malloc(sizeof (nodo) );		// reservo un nuevo nodo
	if( nuevo == NULL)			//  Hay memoria disponible?
	{
		printf("ERROR: No hay memoria disponible");		// No hay memoria
		pausa;
		exit(1);		//  Termina el programa con condici�n de error 1 (no hay memoria)
	}
	nuevo -> info = dato;	// Preservamos el dato recibido en el nodo
	nuevo -> sig = NULL;	// El apuntador sigueinte se apunta NULL	
	if( raiz == NULL)		// La lista est� vac�a?
	{						//  Si esta vac�a
		raiz = nuevo;
		return raiz;
	}
	else					//  No est� vac�a
	{				
		nodo *recorre = raiz;	//  Me posiciono en el primer nodo de la lista
		while( recorre -> sig != NULL)		// Es el ultimo nodo
		{									// No.
			recorre = recorre-> sig;		// Me muevo al siguente nodo
		}
		recorre ->sig = nuevo;				// Inserto al final el nuevo nodo
	}
	//return raiz;
}


nodo *insertn(nodo *raiz, char dato, int pos)
{
	int cont;
	nodo *nuevo = NULL;			//  Apuntador para el nuevo nodo
	if(pos < 1) return;			// Ante una posici�n negativa no hacemos nada.
	nuevo = (nodo *) malloc(sizeof (nodo) );		// reservo un nuevo nodo
	if( nuevo == NULL)			//  Hay memoria disponible?
	{
		printf("ERROR: No hay memoria disponible");		// No hay memoria
		pausa;
		exit(1);		//  Termina el programa con condici�n de error 1 (no hay memoria)
	}
	nuevo -> info = dato;	// Preservamos el dato recibido en el nodo
	nuevo -> sig = NULL;	// El apuntador sigueinte se apunta NULL	
	if( raiz == NULL)		// La lista est� vac�a?
	{						//  Si esta vac�a
		raiz = nuevo;
		return;
	}
	if(pos == 1)			//  Me pidieron insertar en la pos 1?
	{
		nuevo -> sig = raiz;	//  Preservo la lista restante
		raiz = nuevo;			//  El nuevo nodo se vuelve el primero
		
	}
	else					//  No est� vac�a
	{				
		nodo *recorre = raiz;	//  Me posiciono en el primer nodo de la lista
		cont = 1;				//  Estoy en el nodo num 1
		while( recorre -> sig != NULL && cont < pos - 1)	// Es el ultimo nodo o la posici�n anterior
		{									// No.
			recorre = recorre-> sig;		// Me muevo al siguente nodo
			cont++;							// cuento el nodo
		}
		nuevo -> sig = recorre ->sig;		// Preservo el resto de la lista
		recorre ->sig = nuevo;				// Inserto en la posici�n el nuevo nodo
	}
	return raiz;
}

nodo *insert1(nodo *raiz, char dato)
{
	nodo *nuevo = NULL;			//  Apuntador para el nuevo nodo
	nuevo = (nodo *) malloc(sizeof (nodo) );		// reservo un nuevo nodo
	if( nuevo == NULL)			//  Hay memoria disponible?
	{
		printf("ERROR: No hay memoria disponible");		// No hay memoria
		pausa;
		exit(1);		//  Termina el programa con condici�n de error 1 (no hay memoria)
	}
	nuevo -> info = dato;	// Preservamos el dato recibido en el nodo
	nuevo -> sig = NULL;	// El apuntador siguiente se apunta NULL	
						//  Si esta vac�a
	nuevo ->sig = raiz;  // preservo el primer nodo de la lista
	raiz = nuevo;			// Inserto el nuevo nodo como primero
	return raiz;
}

void imprimeLista(nodo *raiz)
{
	nodo *recorre = raiz;	//  Me posiciono en el primer nodo de la lista
	while( recorre != NULL)		// Se acab� la lista?
	{									// No.
		printf("%c, ", recorre->info);
		recorre = recorre-> sig;		// Me muevo al siguente nodo
	}
	putchar('\n');
}

nodo *remueve(nodo *raiz, char *dato)
{
	
	nodo *recorre = raiz, *elimina = NULL;
	if( raiz == NULL)			//  La lista est� vac�a?
	{							//  Si
		return NULL;			//  No hacemos nada.
	}
	if(recorre -> sig == NULL)	//  Es una lista de 1 solo nodo?
	{							// Si
		*dato = recorre -> info;	// Preservamos el campo info
		free(recorre);			// Liberamos la memoria reservada por malloc()
		raiz = NULL;			// Se vuelve una lista vac�a
		return raiz;			// Regresamos el dato que salio de la lista ligada
	}
	elimina = recorre ->sig;	//  Nos posicionamos delante de recorre
	while( elimina ->sig != NULL )	// elimina esta posicionado en el �ltimo?
	{								// no
		recorre = recorre ->sig;	// recorre avanza al siguiente nodo
		elimina = elimina ->sig;	// elimina avanza al siguiente nodo
	}
	recorre ->sig = NULL;	// El pen�ltimo se vuelve el �ltimo nodo de la lista
	*dato = elimina -> info;	// Preservamos el campo info
	free(elimina);			// Liberamos la memoria reservada por malloc()
	return raiz;			// Regresamos el dato que salio de la lista ligada
}

nodo *remueve1(nodo *raiz, char *dato)
{
	nodo *elimina = NULL;
	if( raiz == NULL)			//  La lista est� vac�a?
	{							//  Si
		return NULL;			//  No hacemos nada.
	}
	elimina = raiz;				//  Apuntamos elimina al primer nodo
	raiz = raiz ->sig;			//  raiz se apunta a lo que le seg�ia (otro nodo o NULL)
	*dato = elimina ->info;		//  Preservamos el campo info
	free(elimina);				// Liberamos memoria reservada por malloc()
	return raiz;			// Regresamos el dato que salio de la lista ligada
}

nodo *remueven(nodo *raiz, int pos,char *dato)
{
	int cont = 1;
	nodo *recorre = raiz, *elimina = NULL;
	if( raiz == NULL)			//  La lista est� vac�a?
	{							//  Si
		return NULL;			//  No hacemos nada.
	}
	if(recorre -> sig == NULL)	//  Es una lista de 1 solo nodo?
	{							// Si
		*dato = recorre -> info;	// Preservamos el campo info
		free(recorre);			// Liberamos la memoria reservada por malloc()
		raiz = NULL;			// Se vuelve una lista vac�a
		return raiz;			// Regresamos el dato que salio de la lista ligada
	}
	if(pos == 1)				//  Me pidieron borrar el ultimo?
	{							//  Si
		raiz = raiz ->sig;		//  raiz se mueve al segundo nodo que se vuelve el primero
		*dato = recorre ->info;	//  Preservamos la informaci�n
		free(recorre);			//  Liberamos memoria reservada con malloc()
		return raiz;			//  Regresamos el dato
	}
	elimina = recorre ->sig;	//  Nos posicionamos delante de recorre
	while( elimina ->sig != NULL && cont < pos - 1)	// elimina esta posicionado en el �ltimo?
	{								// no
		recorre = recorre ->sig;	// recorre avanza al siguiente nodo
		elimina = elimina ->sig;	// elimina avanza al siguiente nodo
		cont++;
	}
	if( cont < pos - 1 )				// llegu� a la posici�n a borrar?
	{								//  No...
		return NULL;				// No hago nada.
	}
	recorre ->sig = elimina ->sig;	// El pen�ltimo se vuelve el �ltimo nodo de la lista
	*dato = elimina -> info;	// Preservamos el campo info
	free(elimina);			// Liberamos la memoria reservada por malloc()
	return raiz;			// Regresamos el dato que salio de la lista ligada
}

