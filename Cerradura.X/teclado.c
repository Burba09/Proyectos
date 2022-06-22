/*
 * File:   teclado.c
 * Author: carlosh
 *
 * Created on September 8, 2021, 9:58 PM
 */


#include "config.h"

int x=0;

char Leer_tecla(void) {
    
    x=100;
    
      PORTB=1;
      __delay_ms(10);
      
      
      if (RB4) {
          x = 1;
      }
      else if (RB5) {
          x = 2;
      }
      else if (RB6) {
          x = 3;
      }
      PORTB=2;
      __delay_ms(10);
      if (RB4) {
          x = 4;
      }
      else if (RB5) {
          x = 5;
      }
      else if (RB6) {
          x = 6;
      }
      PORTB=4;
      __delay_ms(10);
      if (RB4) {
          x = 7;
      }
      else if (RB5) {
          x = 8;
      }
      else if (RB6) {
          x = 9;
      }
      PORTB=8;
      __delay_ms(10);
      if (RB4) {
          x = 42;
      }
      else if (RB5) {
          x = 0;
      }
      else if (RB6) {
          x = 35;
      }
    return x;
}
