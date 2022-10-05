/*
 ============================================================================
 Name        : ActividadPracticaUTN.c
 Author      : Torres Lucas -

 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include "UTN.h"
#include "Empresa.h"

//#define VACIO 0
//#define OCUPADO 1
//#define ERROR -1

#define CANT_MAX 10

int main(void) {

	setbuf(stdout,NULL);
	int IDIncremental = 1000;

	eProducto eProducto[CANT_MAX];

	inicializarProducto(eProducto,CANT_MAX);


	int opcion;

	do{
		printf("\n1. Alta");
		printf("\n2. Baja");
		printf("\n3. Modificacion");
		printf("\n4. Mostrar");
		printf("\n5. Forzar Datos");
		printf("\n6. Finalizar");

	utnGetNumber(&opcion,"\nIngrese una opcion : ","Opcion Incorrecta",1,5,99);

	switch(opcion){


		case 1:
				if(buscarLibre(eProducto,CANT_MAX)== ERROR)
				{
					printf("\n Ya no hay espacio !!!\n ");
				}else{

					altaProducto(eProducto,CANT_MAX,&IDIncremental);
				}


		break;


		case 2:

				printf("Entro bien 2");
		break;


		case 3:

				modificarProducto(eProducto,CANT_MAX );

		break;


		case 4:

				mostrarProductos(eProducto, CANT_MAX);

		break;


		case 5:
				forzarDatos(eProducto,CANT_MAX);

		break;

	}


	system("pause");
	system("cls");
	}while(opcion != 6);




	return EXIT_SUCCESS;
}
