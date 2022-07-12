#include <stdio.h>
#include <stdlib.h>

struct INFO
{
	int num;
};
struct NODO
{
	struct INFO elemento;
	struct NODO *p_anterior;
	struct NODO *p_siguiente;
};

struct BICOLA
{
	int nodos;
	struct NODO *primero;
	struct NODO *ultimo;
};


// Pone los punteros de una bicola a NULL
void inicializarBicola( struct BICOLA **bicola )
{
	struct BICOLA *temp = (struct BICOLA *) malloc(sizeof(struct BICOLA));

	temp->nodos		= 0;
	temp->primero	= NULL;
	temp->ultimo	= NULL;

	(*bicola) 		= temp;

};



// Inserta nodos por la izquierda:
void insertIzqBicola( struct BICOLA **bicola, int dato )
{
	
	struct NODO *temp = (struct NODO *) malloc(sizeof(struct NODO));


	if( (*bicola)->primero == NULL )
	{
		temp->elemento.num	= dato;					
		temp->p_anterior	= NULL;					
		temp->p_siguiente	= NULL;

		(*bicola)->primero	= temp;					
		(*bicola)->ultimo	= temp;
	}
	else
	{
		temp->elemento.num	= dato;					
		temp->p_anterior	= NULL;					
		temp->p_siguiente	= (*bicola)->primero;	

		(*bicola)->primero->p_anterior	= temp;
		(*bicola)->primero				= temp;		
	};


	(*bicola)->nodos += 1;							

};



// Inserta nodos por la derecha:
void insertDerBicola( struct BICOLA **bicola, int dato )
{

	struct NODO *temp = (struct NODO *) malloc(sizeof(struct NODO));

	if( (*bicola)->primero == NULL )
	{
		temp->elemento.num	= dato;
		temp->p_anterior	= NULL;
		temp->p_siguiente	= NULL;

		(*bicola)->primero	= temp;
		(*bicola)->ultimo	= temp;
	}
	else
	{
		temp->elemento.num	= dato;
		temp->p_anterior	= (*bicola)->ultimo;
		temp->p_siguiente	= NULL;

		(*bicola)->ultimo->p_siguiente	= temp;
		(*bicola)->ultimo				= temp;
	};


	(*bicola)->nodos += 1;

};



// Elimina el primer Nodo:
void eliminaIzqBicola( struct BICOLA **bicola )
{

	struct NODO *aBorrar;


	
	if( (*bicola)->primero == NULL )
	{
		printf( "No puede eliminar Nodos de una Bicola vacía." );
	}
	  
	else if( (*bicola)->nodos == 1 )
	{
		free(*bicola);
		inicializarBicola( bicola );
	}
	else if( (*bicola)->nodos > 1 )
	{
		aBorrar = (*bicola)->primero;

		(*bicola)->primero->p_siguiente->p_anterior	= NULL;
		(*bicola)->primero= (*bicola)->primero->p_siguiente;
		free(aBorrar);

		(*bicola)->nodos -= 1;
	};

};



// Elimina el ultimo Nodo:
void eliminaDerBicola( struct BICOLA **bicola )
{

	struct NODO *aBorrar;


	
	if( (*bicola)->primero == NULL )
	{
		printf( "No puede eliminar Nodos de una Bicola vacía." );
	}
	else if( (*bicola)->nodos == 1 )
	{
		free(*bicola);
		inicializarBicola( bicola );
	}
	else if( (*bicola)->nodos > 1 )
	{
		aBorrar = (*bicola)->ultimo;

		(*bicola)->ultimo->p_anterior->p_siguiente	= NULL;
		(*bicola)->ultimo							= (*bicola)->ultimo->p_anterior;
		free(aBorrar);

		(*bicola)->nodos -= 1;
	};

};

// imprime por pantalla el contenido de todos los Nodos de la Bicola:
void imprimeBicola( struct BICOLA **bicola )
{

	struct NODO *bic = (*bicola)->primero;



	if( bic == NULL )
		printf( "La Bicola no contiene Nodos." );
	else
	{

		printf( "Su Bicola contiene: " );

		while( bic != NULL )
		{
			printf( "%i, ", bic->elemento.num );
			bic = bic->p_siguiente;
		};

		printf( "\n\n" );

	};

};
void mostrarOpcionesMenu()
{
    printf("\n1.Agregar por la izquierda\n");
    printf("2.- Agregar por la derecha.\n");
    printf("3.- Eliminar por la izquierda.\n");
    printf("4.- Eliminar por la derecha.\n");
    printf("5.- Imprimir bicola.\n");
    printf("6.- Salir del programa.\n");
    printf("Seleccione una opcion.\n");
}

int main()
{
	struct BICOLA *bicolaA;
	int opcion, nuevoDato;


	inicializarBicola( &bicolaA );
    while(1)
    {
        do
        {
            mostrarOpcionesMenu();
            scanf("%d", &opcion);
            getchar();
        } while (opcion < 1 || opcion > 8);

        switch (opcion)
        {
            case 1:
            {
                printf( "Introduzca el número entero que contendrá el nuevo Nodo de la Bicola: " );
				scanf( "%i", &nuevoDato );
				insertIzqBicola( &bicolaA, nuevoDato );
                break;
            }
            case 2:
            {
                printf( "Introduzca el número entero que contendrá el nuevo Nodo de la Bicola: " );
				scanf( "%i", &nuevoDato );
				insertDerBicola( &bicolaA, nuevoDato);
                 break;
            }
            case 3:
            {
                eliminaIzqBicola( &bicolaA );
                 break;
            }
            case 4:
            {
                eliminaDerBicola( &bicolaA );
                break;
            }
            case 5:
            {
                imprimeBicola( &bicolaA );
                break;
            }
            case 6:
            {
                printf("\nGracias por utilizar el programa\n");
                return 0;
            }
        }

        do
        {
            printf("\n¿Desea continuar?\n");
            printf("1- Si. / 2- NO.\n");
            scanf("%d", &opcion);
            getchar();
        } while (opcion < 1 || opcion > 2);

        if (opcion == 2)
        {
            printf("\nGracias por utilizar el programa\n");
            break;
        }
    }
    return 0;

}