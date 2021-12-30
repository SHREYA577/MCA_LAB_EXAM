//The code is written for common Anode configuration

// Considering P0.0-P0.15 as output pins.
//P0.0-P0.7 output pins have been given to 7 segment display 1
//P0.8-P0.15 output pins have been given to 7 segment display 2

#include<lpc21xx.h>
void delay(unsigned int c)
{unsigned int a;
for(a=1;a<=30000;a++);}

int main()
{
PINSEL0=0x00000000;
PINSEL1=0x00000000;
IO0DIR=0x0000FFFF;

while(1)
{ unsigned long int j,i;

		int a[]={0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90};//Using common Anode configuration
		int b[]={0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90};
		for(i=0;i<10;i++)
			{
			IO0SET=IO0SET|a[i];
			for(j=0;j<10;j++)
			{
				IO0SET= IO0SET|(b[j]<<8);//Shift the array bits to left by 8 positions for the output to reflect on P0.8-P0.15 bits
				delay(100000);
				IO0CLR= IO0CLR|(b[j]<<8);
			}
			IO0CLR=IO0CLR|a[i];
			}
}
}
