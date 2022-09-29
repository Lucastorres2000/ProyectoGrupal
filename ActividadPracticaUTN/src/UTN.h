/*
 * Validaciones.h
 *
 *  Created on: 16 sep. 2022
 *      Author: Lenovo
 */

#ifndef UTN_H_
#define UTN_H_

/**
 * \brief Requests the user to enter a number (integer)
 * \param int *pNumber, pointer to the space where the value obtained will be left
 * \param char *message, message to be shown to the user
 * \param char *errorMessage, message to be shown to the user
 * \param int min, minimum value allowed
 * \param int max, maximum value allowed
 * \param int retries, number of opportunities to enter the data
 * \return (-1) ERROR (0) SUCCESS
 */
int utnGetNumber(int* pNumber, char* message, char* errorMessage, int min, int max,int retries);

/**
 * \brief Requests the user to enter a number (decimal number)
 * \param float *pNumber, pointer to the space where the value obtained will be left
 * \param char *message, message to be shown to the user
 * \param char *errorMessage, message to be shown to the user
 * \param float min, minimum value allowed
 * \param float max, maximum value allowed
 * \param int retries, number of opportunities to enter the data
 * \return (-1) ERROR (0) SUCCESS
 */
int utnGetFloatNumber(float *pNumber, char *message, char *errorMessage, float min, float max, int retries);

/**
 * \brief Requests the user to enter a string (only letters)
 * \param char *name, pointer to the space where the value obtained will be left
 * \param int len, size of name
 * \param char *message, message to be shown to the user
 * \param char *errorMessage, message to be shown to the user
 * \param int retries, number of opportunities to enter the data
 * \return (-1) ERROR (0) SUCCESS
 */
int utnGetName(char* name, int len, char* message, char* errorMessage, int retries);

/**
 * \brief Requests the user to enter a string (letters or numbers)
 * \param char *name, pointer to the space where the value obtained will be left
 * \param int len, size of name
 * \param char *message, message to be shown to the user
 * \param char *errorMessage, message to be shown to the user
 * \param int retries, number of opportunities to enter the data
 * \return (-1) ERROR (0) SUCCESS
 */
int utnGetAlphanumeric(char* name, int len, char* message, char* errorMessage, int retries);

#endif /* UTN_H_ */
