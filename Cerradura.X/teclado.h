/* 
 * File:   lcd.h
 * Author: Carlos H Tobar
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef TECLADO_H
#define	TECLADO_H

// Cambie el puerto y los pines si se requiere
#define A RB0
#define B RB1
#define C RB2
#define D RB3
#define S1 RB4
#define S2 RB5
#define S3 RB6


// Definicion de las funciones que manejan el Teclado
char Leer_tecla(void);

#endif