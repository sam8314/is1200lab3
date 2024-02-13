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
int timeouts = 0;

char textstring[] = "text, more text, and even more text!";

/* Interrupt Service Routine */
void user_isr( void )
{
  return;
}

void labinit( void )
{

  /*assignement 2.b*/
  T2CON = 0x70; //stop timer and clear control register, set prescale to 256:1
  TMR2 = 0x0; // clear timer register
  PR2 = 80000000/(256*10);/*period register = Fclk/Ftimer = Fclk/(prescale*Ftimer) = 80 MHz/(prescale*timer)*/
  T2CONSET = 0x8000; //start timer

  volatile int * trisE = (volatile int *) 0xbf886100;
  *trisE = 0xFFFFFF00 & *trisE; //1.c : bits 7 through 0 of port E are set as output

  TRISDSET = 0xFE0; //1.e set bits 11 through 5 of port D as inputs

  return;
}

/* This function is called repetitively from the main program */
void labwork( void )
{
  //1.d : increase bin value shown on 8 green LEDs
  volatile int * portE = (volatile int *) 0xbf886110;

  //delay( 1000 );
  if(IFS(0) & 0x100){
    timeouts+=1;
    IFSCLR(0) = 0;//reset the interrupt status flag

    if(timeouts==10){ //assignement 2.c
      time2string( textstring, mytime );
      display_string( 3, textstring );
      display_update();
      tick( &mytime );
      *portE = *portE +1;
      timeouts =0;
    }

    display_image(96, icon);
  }
  
  //assignement 1.h
  int button_pressed = getbtns();
  if(button_pressed & 0b0010) //pressing BTN2
  {
    mytime = mytime & 0xFF0F;
    mytime = mytime | (getsw()<<4);    
  }
  if(button_pressed & 0b0100) //pressing BTN3
  {
    mytime = mytime & 0xF0FF;
    mytime = mytime | (getsw()<<8);
  }
  if(button_pressed & 0b1000) //pressing BTN4
  {
    mytime = mytime & 0x0FFF;
    mytime = mytime | (getsw()<<12);
  }



}
