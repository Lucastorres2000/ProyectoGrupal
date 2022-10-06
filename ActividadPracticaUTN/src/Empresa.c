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
int Swap(eProducto*  unProducto,eProducto*  otroProductoNext){

	int  retorno= ERROR;
		if(unProducto != NULL && otroProductoNext != NULL)
		{
			eProducto auxProducto;
			auxProducto = *unProducto;
			*unProducto = *otroProductoNext;
			*otroProductoNext = auxProducto;
			retorno = SUCCESS;
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
			utnGetNumber(&auxProducto.nacionalidad,"Ingrese Nacionalidad  \n EEUU : 1 \n CHINA : 2 \n OTRO : 3 ","ERROR",1,4,3) == SUCCESS &&
			utnGetNumber(&auxProducto.tipo,"Ingrese tipo \n IPHONE : 1 \n MAC : 2 \n OTRO : 3 \n","ERROR",1,4,3) == SUCCESS &&
			utnGetFloatNumber(&auxProducto.precio,"Ingrese el precio : ","ERROR",1,100000,3) == SUCCESS &&
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



	printf("\n || %5d | %5s | %5d | %5d | \t%.2f \t||\n", Lista.idProducto,
											Lista.descripcion,
											Lista.nacionalidad,
											Lista.tipo,
											Lista.precio);



}


int mostrarProductos(eProducto Lista[],int  size ){
	int retorno = ERROR;

		if(Lista !=  NULL && size > 0 )
		{
			printf("\n\tID \t DESCRP \t NACIO \t TIPO \t   PRECIO");
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
	index=BuscarProductoPorId(Lista ,size ,auxID );

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

			 utnGetNumber(&opcion,"\nElija la opcion que desea modificar : ","Opcion no valida",1,5,3);


			switch(opcion)
			{

			case 1:
					if(utnGetAlphanumeric(bufferProducto.descripcion,200, "Ingrese la descripcion ","Error",3) == SUCCESS )
					{
						strcpy(Lista[index].descripcion,bufferProducto.descripcion);
						retorno=SUCCESS;
					}

				break;

			case 2:
					if(utnGetNumber(&bufferProducto.nacionalidad,"Ingrese Nacionalidad  \n EEUU : 1 \n CHINA : 2 \n OTRO : 3 ", "\n! -- ERROR -- !\n",1, 3, 3)== SUCCESS )
					{

						Lista[index].nacionalidad = bufferProducto.nacionalidad;
						retorno = SUCCESS ;
					}

				break;

			case 3:
					if(utnGetNumber(&bufferProducto.tipo,"Ingrese tipo \n IPHONE : 1 \n MAC : 2 \n OTRO : 3 \n"," \n  ! -- ERROR -- !\n ", 1, 3,3) == SUCCESS )
					{
						Lista[index].tipo = bufferProducto.tipo ;
						retorno = SUCCESS ;
					}

				break;

			case 4:
					if(utnGetFloatNumber(&bufferProducto.precio,"\nIngrese el precio :  ","\n ! - - Error - - ! \n",1,100000,3) == SUCCESS )
					{
						Lista[index].precio = bufferProducto.precio ;
						retorno = SUCCESS ;
					}

				break;

			case 5:
					printf("\n Volviendo al menu principal ... \n");

				break;

			}

		}while(opcion != 5);

	}

	return retorno;
}
int forzarDatos(eProducto Lista[], int size ){

	int	retorno = ERROR;

	if(Lista != NULL && size > 0 )
	{
		int auxIDProducto[10] = {1000,1001,1002,1003,1004,1005,1006,1007,1008,1009};

		int auxNacionalidad[10] = {1,2,3,3,2,1,2,3,1,2};

		int auxTipo[10] = {3,2,1,3,2,1,3,2,1,2};

		char auxDescripcion[10][999]={"Memoria : 64 GB ",
										"Memoria : 64 GB ",
										"Memoria : 64 GB ",
										"Memoria : 64 GB ",
										"Memoria : 64 GB ",
										"Memoria : 64 GB ",
										"Memoria : 64 GB ",
										"Memoria : 64 GB ",
										"Memoria : 64 GB ",
										"Memoria : 64 GB "};

		float auxPrecio[10]={5,4,3,2,1,6,7,8,9,10};
		int auxIsEmpty[10]={OCUPADO,OCUPADO,OCUPADO,OCUPADO,OCUPADO,OCUPADO,OCUPADO,OCUPADO,OCUPADO,OCUPADO};

		for(int i = 0 ; i < size ; i ++ )
		{
			Lista[i].idProducto = auxIDProducto[i];
			Lista[i].nacionalidad = auxNacionalidad[i];
			Lista[i].tipo = auxTipo[i];
			Lista[i].precio = auxPrecio[i];
			strcpy(Lista[i].descripcion,auxDescripcion[i]);
			Lista[i].isEmpty = auxIsEmpty[i];
			retorno = SUCCESS ;
		}


	}

	return retorno;

}

int bajaProducto(eProducto Lista[], int size ){
	int retorno = ERROR ;
	int auxID;
	int index;

	if(Lista != NULL && size > 0 )
	{
		mostrarProductos(Lista,size);
		utnGetNumber(&auxID,"\nIngrese el ID que desea eliminar : ","ERROR",1000,10000,3);
		index=BuscarProductoPorId(Lista,size,auxID);

		if(index == ERROR)
		{
			printf("\nEl ID no existe ..\n ");
		}else{
			Lista[index].isEmpty = VACIO ;
		}


	}


	return retorno;
}

int mostrarPorPrecio(eProducto Lista[],int size)
{
	int  retorno=ERROR;
	eProducto bufferProducto;

	if(Lista != NULL && size > 0)
	{
		for(int i = 0 ; i < size ; i++ )
		{
			for(int  j = i ; j < size - 1 ; j ++)
			{
				if(Lista[i].precio > Lista[j].precio)
				{
					//Swap(&Lista[i],&Lista[j]);
					bufferProducto = Lista[j] ;
					Lista[j] = Lista[i] ;
					Lista[i] = bufferProducto;

				}
			}
		}




	}


	return retorno;



}
