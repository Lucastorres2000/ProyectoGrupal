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



#define CANT_MAX 10

int main(void) {

	setbuf(stdout,NULL);
	int IDIncremental = 1000;

	eProducto eProducto[CANT_MAX];

	inicializarProducto(eProducto,CANT_MAX);

	int flagCase1 = ERROR ;
	//int flagCase2 = ERROR ;
	//int flagCase3 = ERROR ;
	//int flagCase4 = ERROR ;


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
					if(altaProducto(eProducto,CANT_MAX,&IDIncremental))
					{
						flagCase1 = SUCCESS ;
					}
				}


		break;


		case 2:

				if(flagCase1 == SUCCESS )
				{
					bajaProducto(eProducto,CANT_MAX);

				}else{

					printf("\nPrimero de deben cargar Productos ..\n ");
				}


		break;


		case 3:
				if(flagCase1 == SUCCESS )
				{
					modificarProducto(eProducto,CANT_MAX );

				}else{

					printf("\nPrimero de deben cargar Productos ..\n ");
				}

		break;


		case 4:
				if(flagCase1 == SUCCESS )
				{
					mostrarProductos(eProducto, CANT_MAX);
					mostrarPorPrecio(eProducto,CANT_MAX);

				}else{

					printf("\nPrimero de deben cargar Productos ..\n ");
				}



		break;


		case 5:

			if(flagCase1 == SUCCESS )
			{
				printf("No se pueden forzar los datos cuando ya hay datos Cargados ..");
			}else{
				if(forzarDatos(eProducto,CANT_MAX)== SUCCESS )
				{
					printf("Carga Forzada Exitosa");
					flagCase1 = SUCCESS;
				}
			}

		break;

	}


	system("pause");
	system("cls");
	}while(opcion != 6);




	return EXIT_SUCCESS;
}
