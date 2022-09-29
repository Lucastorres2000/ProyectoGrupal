/*
 * Empresa.c
 *
 *  Created on: 23 sep. 2022
 *      Author: lucas
 */

#include <stdio.h>
#include <stdlib.h>
#include  <string.h>
#include "Empresa.h"
#include "UTN.h"

int inicializarProducto(eEmpresa* Lista,int cantMax){

	int retorno=-1;

	if(Lista != NULL && cantMax > 0)
	{
		for(int i = 0 ; i < cantMax ; i++ )
		{
			Lista[i].isEmpty = VACIO ;
		}

	}

	return retorno;
}

int buscarLibre(eEmpresa List[], int size){

	int retorno=ERROR;

		if(List != NULL )
		{
			for(int i = 0 ; i < size ; i ++)
			{
				if(List[i].isEmpty == VACIO )
				{
					retorno = i;
					break;
				}
			}
		}


	return retorno;

}

int cargarProducto(eEmpresa Lista[], int size, int auxIDProducto, char auxDescripcion[], int auxNacionalidad, int auxTipo ,float auxPrecio){

	int retorno = ERROR;
	int index;

	if(Lista != NULL && size > 0 && auxIDProducto > 0 && auxDescripcion != NULL && auxNacionalidad > 0 && auxTipo > 0 && auxPrecio > 0 )
	{
		index = buscarLibre(Lista,3);

		Lista[index].idProducto = auxIDProducto;
		strcpy(Lista[index].descripcion,auxDescripcion);
		Lista[index].nacionalidad= auxNacionalidad ;
		Lista[index].tipo = auxTipo ;
		Lista[index].precio = auxPrecio ;

		retorno = SUCCESS ;
	}

	return retorno;
}
int altaProducto(eEmpresa* Lista, int size){

	eEmpresa auxProducto;
	int retorno = ERROR;

	if(utnGetNumber(&auxProducto.idProducto,"Ingrese ID","ID ERROR",1,100,3) == SUCCESS &&
			utnGetName(auxProducto.descripcion,200,"Ingrese Descripcion","Error  en Descripcion",3) == SUCCESS &&
			utnGetNumber(&auxProducto.nacionalidad,"Ingrese nacionalidad ","ERROR",1,4,3) == SUCCESS &&
			utnGetNumber(&auxProducto.tipo,"Ingrese el tipo ","ERROR",1,4,3) == SUCCESS &&
			utnGetFloatNumber(&auxProducto.precio,"Ingrese el precio ","ERROR",1,999999,3) == SUCCESS &&
			cargarProducto(Lista,size,auxProducto.idProducto,auxProducto.descripcion,auxProducto.nacionalidad,auxProducto.tipo,auxProducto.precio) )
	{
		retorno = SUCCESS;

	}
	return retorno;
}

void mostrarUnProducto(eEmpresa Lista){

	printf("\nID \t DESCRP \t NACIO \t TIPO \t PRECIO");

	printf("\n\t%d \t%s \t%d \t%d \t%f ", Lista.idProducto,
											Lista.descripcion,
											Lista.nacionalidad,
											Lista.tipo,
											Lista.precio);



}


int mostrarProductos(eEmpresa Lista[],int  size ){
	int retorno = ERROR;

		if(Lista !=  NULL && size > 0 )
		{

			for(int i = 0 ; i < size ; i++ )
			{
				if(Lista[i].isEmpty == VACIO )
				{
						mostrarUnProducto(Lista[i]);
				}

			}
		}

	return  retorno;


}
