/*
 * Empresa.h
 *
 *  Created on: 23 sep. 2022
 *      Author: lucas
 */

#define VACIO 2
#define OCUPADO 1
#define ERROR -1
#define SUCCESS 1

#ifndef EMPRESA_H_
#define EMPRESA_H_

typedef struct{

	int idProducto;
	char descripcion[200];
	int nacionalidad;
	int tipo;
	float precio;
	int isEmpty;

}eProducto;

int inicializarProducto(eProducto* Lista,int cantMax);

int buscarLibre(eProducto* List, int size);

int BuscarProductoPorId(eProducto Lista[], int tam, int id);

int cargarProducto(eProducto* Lista, int size, int auxIDProducto, char auxDescripcion[], int auxNacionalidad, int auxTipo ,float auxPrecio );

int altaProducto(eProducto Lista[], int size, int* ID);

int bajaProducto(eProducto Lista);

int modificarProducto(eProducto* Lista,int size );

int mostrarProductos(eProducto Lista[], int  size );

void mostrarUnProducto(eProducto Lista);

int forzarDatos(eProducto Lista[], int size );
#endif /* EMPRESA_H_ */
