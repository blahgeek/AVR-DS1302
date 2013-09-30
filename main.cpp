/// @file num_display.c  @version 1.0 @date 07/30/2012
/// @author BlahGeek@Gmail.com

#include <avr/io.h>
#include <math.h>
#include <util/delay.h>
#include <avr/interrupt.h>

int main(){
    DDRB |= (1 << 0);
    _delay_ms(200);
    while(1){
        PORTB |= (1 << 0);
        _delay_ms(2100);
        PORTB &= ~(1 << 0);
        for(int n = 0 ; n < 12 ; n += 1)
            for(int i = 0 ; i < 3600 ; i += 1)
                _delay_ms(1000);
    }
    while(1){}
}
