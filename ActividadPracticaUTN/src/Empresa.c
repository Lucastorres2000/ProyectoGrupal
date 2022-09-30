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

int inicializarProducto(eProducto* Lista,int cantMax){

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

int buscarLibre(eProducto List[], int size){

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
int BuscarProductoPorId(eProducto Lista[], int tam, int id)
{
	int i;
	int retorno = -1;

	if(Lista != NULL && tam > 0 && id > 0 )
	{
		for(i=0; i<tam; i++)
		{
			if(Lista[i].isEmpty == OCUPADO && Lista[i].idProducto == id)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

int altaProducto(eProducto Lista[], int size, int* ID){

	eProducto auxProducto;
	int retorno = ERROR;

	if(utnGetName(auxProducto.descripcion,200,"Ingrese Descripcion: ","Error  en Descripcion",3) == SUCCESS &&
			utnGetNumber(&auxProducto.nacionalidad,"Ingrese nacionalidad :  ","ERROR",1,4,3) == SUCCESS &&
			utnGetNumber(&auxProducto.tipo,"Ingrese el tipo : ","ERROR",1,4,3) == SUCCESS &&
			utnGetFloatNumber(&auxProducto.precio,"Ingrese el precio : ","ERROR",1,999999,3) == SUCCESS &&
			cargarProducto(Lista,size,*ID,auxProducto.descripcion,auxProducto.nacionalidad,auxProducto.tipo,auxProducto.precio) == SUCCESS )
	{
		(*ID)++;
		retorno = SUCCESS;

	}
	return retorno;
}

int cargarProducto(eProducto Lista[], int size, int auxIDProducto, char auxDescripcion[], int auxNacionalidad, int auxTipo ,float auxPrecio){

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
		Lista[index].isEmpty = OCUPADO;

		retorno = SUCCESS ;
	}

	return retorno;
}


void mostrarUnProducto(eProducto Lista){

	//printf("\nID \t DESCRP \t NACIO \t TIPO \t PRECIO");

	printf("\n\t%d \t%s \t%d \t%d \t%f ", Lista.idProducto,
											Lista.descripcion,
											Lista.nacionalidad,
											Lista.tipo,
											Lista.precio);



}


int mostrarProductos(eProducto Lista[],int  size ){
	int retorno = ERROR;

		if(Lista !=  NULL && size > 0 )
		{

			for(int i = 0 ; i < size ; i++ )
			{
				if(Lista[i].isEmpty == OCUPADO )
				{
						mostrarUnProducto(Lista[i]);
				}

			}
		}

	return  retorno;


}
int modificarProducto(eProducto* Lista,int size ){

	int retorno=ERROR;
	int auxID;
	int index;
	int opcion;

	eProducto bufferProducto;
	utnGetNumber(&auxID,"Ingrese ID a modificar","ERROR",1,10000,3);
	index=BuscarProductoPorId(Lista, size,auxID);

	if(Lista != NULL  && size > 0  && Lista[index].isEmpty == OCUPADO)
	{

		do{

			 system("cls");
			 printf(" !! - - - MENU DE MODIFICACION - - - !! ");
			 printf("\n 1 > Descripcion. ");
			 printf("\n 2 > Nacionalidad. ");
			 printf("\n 3 > Tipo.");
			 printf("\n 4 > Precio.");
			 printf("\n 5 > Volver al menu principal ");

			 utnGetNumber(&opcion, "Elija la opcion que desea modificar : ","Opcion no valida",1,5,3);


			switch(opcion)
			{

			case 1:
					if(utnGetAlphanumeric(bufferProducto.descripcion,200, "Ingrese la descripcion ","Error",3)==SUCCESS)
					{
						strcpy(Lista[index].descripcion,bufferProducto.descripcion);
						retorno=SUCCESS;
					}
				break;

			case 2:

				break;

			case 3:

				break;

			case 4:

				break;

			case 5:

				break;






			}






		}while(opcion != 5);



	}


	return retorno;
}
