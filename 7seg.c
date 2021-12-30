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

		int a[]={0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90};
		int b[]={0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90};
		for(i=0;i<10;i++)
			{
			IO0SET=IO0SET|a[i];
			for(j=0;j<10;j++)
			{
				IO0SET= IO0SET|(b[j]<<8);
				delay(100000);
				IO0CLR= IO0CLR|(b[j]<<8);
			}
			IO0CLR=IO0CLR|a[i];
			}
}
}
