/*
 * eTipo.h
 *
 *  Created on: 5 oct. 2022
 *      Author: Lenovo
 */

#define VACIO 2
#define OCUPADO 1
#define ERROR -1
#define SUCCESS 1

#ifndef TIPOPRODUCTO_H_
#define TIPOPRODUCTO_H_
typedef struct{
	int IDtipoProducto;
	char descripcion[100];
}eTipoProducto;

int inicializarProductos(eTipoProducto listaProducto[] , int  size);
#endif /* TIPOPRODUCTO_H_ */
