#include <mega328p.h>
#include <delay.h>
#include <twi2.c>
#include <pcf8575.c>


void main(void){
#pragma optsize-
CLKPR=0x80;
CLKPR=0x00;
#ifdef _OPTIMIZE_SIZE_
#pragma optsize+
#endif

twiinit();
tulis_pcf8575(0xaa,0xaa); // Keadaan pin akan bergantian on dan off

while (1){

}
}
