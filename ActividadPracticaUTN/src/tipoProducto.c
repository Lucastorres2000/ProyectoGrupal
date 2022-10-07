/*
 * eTipo.c
 *
 *  Created on: 5 oct. 2022
 *      Author: Lenovo
 */

#include "tipoProducto.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "UTN.h"

int inicializarProductos(eTipoProducto listaProducto [] , int  size){
	int retorno = ERROR;

		if(listaProducto != NULL && size > 0 )
		{
				int auxIDProducto[3] = {1001,1002,1003};
				char auxDescripcion [3][100] = {"IPHONE","MAC","OTRO"};

				for(int  i = 0 ; i < size ; i ++)
				{
					listaProducto[i].IDtipoProducto=auxIDProducto[i];
					strcpy(listaProducto[i].descripcion,auxDescripcion[i]);
					retorno = SUCCESS;
				}


		}

	return retorno;
}
