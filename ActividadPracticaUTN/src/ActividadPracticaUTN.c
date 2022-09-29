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

#define CANT_MAX 1

int main(void) {

	setbuf(stdout,NULL);
	int IDIncremental  = 0;

	eEmpresa eEmpresaLista[CANT_MAX];

	inicializarProducto(eEmpresaLista,CANT_MAX);


	int opcion;

	do{
		printf("\n1. Alta");
		printf("\n2. Baja");
		printf("\n3. Modificacion");
		printf("\n4. Mostrar");
		printf("\n5. Finalizar");

	utnGetNumber(&opcion,"Ingrese una opcion : ","Opcion Incorrecta",1,5,99);

	switch(opcion){


		case 1:
				altaProducto(eEmpresaLista, CANT_MAX);


		break;


		case 2:

				printf("Entro bien 2");
		break;


		case 3:

				printf("Entro bien 3");

		break;


		case 4:
			printf("Entre bien 4");
			mostrarProductos(eEmpresaLista, CANT_MAX);

		break;


		case 5:

				printf("Cerrando programa  ...");

		break;

	}


	system("pause");
	system("cls");
	}while(opcion != 5);




	return EXIT_SUCCESS;
}
