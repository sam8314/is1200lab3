/* mipslabwork.c

   This file written 2015 by F Lundevall
   Updated 2017-04-21 by F Lundevall

   This file should be changed by YOU! So you must
   add comment(s) here with your name(s) and date(s):

   This file modified 2017-04-31 by Ture Teknolog 

   For copyright and licensing, see file COPYING */

#include <stdint.h>   /* Declarations of uint_32 and the like */
#include <pic32mx.h>  /* Declarations of system-specific addresses etc */
#include "mipslab.h"  /* Declatations for these labs */

int mytime = 0x0; //initialize at zero

char textstring[] = "text, more text, and even more text!";

/* Interrupt Service Routine */
void user_isr( void )
{
  return;
}

void labinit( void )
{

  volatile int * trisE = (volatile int *) 0xbf886100;
  *trisE = 0xF & *trisE; //1.c : bits 7 through 0 of port E are set as output

  TRISDSET = 0xFE0; //1.e set bits 11 through 5 of port D as inputs

  return;
}

/* This function is called repetitively from the main program */
void labwork( void )
{ 
  //1.d : increase bin value shown on 8 green LEDs
  volatile int * portE = (volatile int *) 0xbf886110;

  //assignement 1.h
  int button_pressed = getbtns();
  int switches_on = getsw();

  if(button_pressed & 0b001) //pressing BTN2
  {
    mytime = mytime & 0xFF0F;
    mytime = mytime | (switches_on<<4);
  }
  if(button_pressed & 0b010) //pressing BTN3
  {
    mytime = mytime & 0xF0FF;
    mytime = mytime | (switches_on<<8);
  }
  if(button_pressed & 0b100) //pressing BTN4
  {
    mytime = mytime & 0x0FFF;
    mytime = mytime | (switches_on<<12);
  }

  
  delay( 1000 );
  time2string( textstring, mytime );
  display_string( 3, textstring );
  display_update();
  tick( &mytime );
  *portE +=1;
  display_image(96, icon);


}
