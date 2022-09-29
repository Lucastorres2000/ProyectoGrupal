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

}eEmpresa;

int inicializarProducto(eEmpresa* Lista,int cantMax);
int buscarLibre(eEmpresa* List, int size);
int cargarProducto(eEmpresa* Lista, int size, int auxIDProducto, char auxDescripcion[], int auxNacionalidad, int auxTipo ,float auxPrecio );
int altaProducto(eEmpresa* Lista, int size);
int bajaProducto(eEmpresa Lista);
int modificarProducto(eEmpresa Lista);
int mostrarProductos(eEmpresa Lista[], int  size );
void mostrarUnProducto(eEmpresa Lista);

#endif /* EMPRESA_H_ */
