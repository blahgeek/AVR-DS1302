/// @file ds1302  @date 10/01/2013
/// @author i@BlahGeek.com

#ifndef __DS1302_H__
#define __DS1302_H__

#define PORT_DS1302 PORTD
#define DDR_DS1302 DDRD
#define PIN_DS1302 PIND

#define sbi(X, Y) (X |= ( 1 << Y))
#define cbi(X, Y) (X &= ~(1 << Y))

unsigned int ds1302rtcRead       (const int reg) ;
void         ds1302rtcWrite      (const int reg, const unsigned int data) ;

unsigned int ds1302ramRead       (const int addr) ;
void         ds1302ramWrite      (const int addr, const unsigned int data) ;

void         ds1302clockRead     (int clockData [8]) ;
void         ds1302clockWrite    (const int clockData [8]) ;

void         ds1302trickleCharge (const int diodes, const int resistors) ;

void         ds1302setup         (const int clockPin, const int dataPin, const int csPin) ;


#endif

