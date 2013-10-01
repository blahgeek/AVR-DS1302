/// @file num_display.c  @version 1.0 @date 07/30/2012
/// @author BlahGeek@Gmail.com

#include <avr/io.h>
#include <math.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <avr/sleep.h>
#include <avr/wdt.h>
#include "ds1302.h"

static unsigned int masks [] = { 0x7F, 0x7F, 0x3F, 0x3F, 0x1F, 0x07, 0xFF } ;
static int bcdToD (unsigned int byte, unsigned int mask)
{
  unsigned int b1, b2 ;
  byte &= mask ;
  b1 = byte & 0x0F ;
  b2 = ((byte >> 4) & 0x0F) * 10 ;
  return b1 + b2 ;
}

void feedit(int pin){
    sbi(DDRB, pin);
    sbi(PORTB, pin);
    _delay_ms(2250);
    cbi(PORTB, pin);
}

int main(){
    DDRB = 0xff;
    PORTB = 0x00;
    int clock [8] ;
    ds1302setup   (4, 6, 7) ;
    ds1302clockRead (clock) ;
    int hour = bcdToD (clock [2], masks [2]);
    int minute = bcdToD (clock [1], masks [1]);
    int sec = bcdToD (clock [0], masks [0]);
    if(hour % 12 == 2 && minute == 0 && sec == 0) 
        feedit(0);
    sei();
    wdt_enable(WDTO_500MS);
    set_sleep_mode(7);
    while(1){
        sleep_mode();
    }
}
