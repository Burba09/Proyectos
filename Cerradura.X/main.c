/*
 * File:   main.c
 * Author: Carlos H Tobar
 *
 * Created on September 8, 2021, 7:39 PM
 */


#include "config.h"
#include "teclado.h"

//Variables:

int intentos=0;
int verificar=0;
int x1,x2,x3,x4; //digitos de la clave
int estado=0;
int clave;
int password=1234;

//Procedimientos:


void encender_ledVerde(){
    RC0 = 1;
}
void apagar_ledVerde(){
    RC0 = 0;
}
void encender_ledRojo(){
    RC1 = 1;
}
void apagar_ledRojo(){
    RC1 = 0;
}
void pulsar_boton(){
    RC2 = 1;
    __delay_ms(100);
    RC2 = 0;
    __delay_ms(100);
}


void ver_clave(char buffer1){

       Lcd_Set_Cursor(2,8);
       Lcd_Write_String(buffer1);
       __delay_ms(1000);
       Lcd_Set_Cursor(2,8);
       Lcd_Write_String("****"); 
    
}

void mover(){
    for(int c=0; c<15; c++){
    __delay_ms(400);
    Lcd_Shift_Left();   
    
    }
    for(int c=0; c<15; c++){
    __delay_ms(400);
    Lcd_Shift_Right();
    }
}

void Alarma(){

    for(int a=0; a<=4 ; a++){
        
        Lcd_Clear();
        Lcd_Set_Cursor(1,2);
        Lcd_Write_String("Caja Bloqueada");
        //Lcd_Set_Cursor(2,4);
        //Lcd_Write_String("Bloqueada");
        
        RC2 = 1;
        __delay_ms(1000);
        RC2 = 0;
        __delay_ms(1000);
           
    }
}
void inicio(){

 Lcd_Clear();
 Lcd_Set_Cursor(1,2);
 Lcd_Write_String("INGRESAR CLAVE:");
 Lcd_Set_Cursor(2,8);
 Lcd_Write_String("____");

}


//main

int main()
{ 
  int x;
  
  char buffer1[20];
  
  TRISD = 0x00;  //Salidas que van al LCD
  TRISC = 0x00;  //Salidas que van al LED y Buzzer
  TRISB = 0xF0;  //4MSB Entradas 4LSB Salidas
  PORTD = 0;
  PORTC = 0;
  PORTB = 0;
  
  Lcd_Init();
  Lcd_Clear();
  Lcd_Set_Cursor(1,1);
  Lcd_Write_String("Cerradura Electronica");
  mover();
  inicio();
 
  
  encender_ledRojo();
  
  while(intentos<3 && verificar==0){
      
      int tecla=Leer_tecla();
      __delay_ms(100);
      
      if(tecla!=100 && tecla!=35 && tecla!=42){
      
          if(estado==0){
              
              pulsar_boton();
              x1=tecla;
              clave = x1;
              
              Lcd_Set_Cursor(2,8);
              Lcd_Write_String("*");
              __delay_ms(500);
              estado++;
              
              sprintf(buffer1,"%i",clave);
                       
          }
          
          else if(estado==1){
              
              pulsar_boton();
              x2=tecla;
              clave = 10*x1+x2; //se corre a la izquierda    
              
              Lcd_Set_Cursor(2,9);
              Lcd_Write_String("*");
              __delay_ms(500);
              
              estado++;
              
              sprintf(buffer1,"%i",clave);
          }
              
           else if(estado==2){
              
              pulsar_boton();
              x3=tecla;
              clave = 100*x1+10*x2+x3; //se corre a la izquierda    
              
              Lcd_Set_Cursor(2,10);
              Lcd_Write_String("*");
              __delay_ms(500);
              
              estado++;
              
             sprintf(buffer1,"%i",clave);
              
              }    
              
           else if(estado==3){
              
              pulsar_boton();
              x4=tecla;
              clave = 1000*x1+100*x2+10*x3+x4; //se corre a la izquierda    
              
              Lcd_Set_Cursor(2,11);
              Lcd_Write_String("*");
              __delay_ms(500);
              
              estado++;
              
              sprintf(buffer1,"%i",clave);
              }
              
          }
            if(tecla==35){
                 
                 ver_clave(buffer1);
            }
            if(tecla==42){
                 
                pulsar_boton();
                 
                if(clave==password){
                 
                     verificar=1;
                     
                     apagar_ledRojo();
                     Lcd_Clear();
                     Lcd_Set_Cursor(1,2);
                     Lcd_Write_String("Clave Correcta");
                     __delay_ms(3000);
                     Lcd_Clear();
                     Lcd_Set_Cursor(1,4);
                     Lcd_Write_String("Cerradura");
                     Lcd_Set_Cursor(2,4);
                     Lcd_Write_String("Abierta");
                     //Lcd_Set_Cursor(2,6);
                     //Lcd_Write_String("Correcta");
                     encender_ledVerde();
                     __delay_ms(7000);
                     
                     
                }
                else{
                     intentos++;
                     estado=0;
                     Lcd_Clear();
                     Lcd_Set_Cursor(1,1);
                     Lcd_Write_String("Clave Incorrecta");
                     //Lcd_Set_Cursor(2,4);
                     //Lcd_Write_String("Incorrecta");
                     __delay_ms(1000);
                 
                 if(intentos<3){
                 
                     inicio();
                                         
                 }    
                 else{
                     Alarma();
                 }    
                 
                }
            }
      }
        
  return 0;
  
}
  
