#include <LPC17xx.h>
#include<stdio.h>
#define	Ref_Vtg		3.300
#define	Full_Scale	0xFFF	

unsigned int delay, count=0, Switchcount=0,i,j,k,l,a,n,number=0,one_sec_flag=0;

unsigned int Disp[16]={0x000003f0, 0x00000060,
                                       0x000005b0, 0x000004f0,
                                       0x00000660,0x000006d0,
                                       0x000007d0, 0x00000070,
                                       0x000007f0, 0x000006f0,
                                      0x00000770,0x000007c0,
                                      0x00000390, 0x000005e0,
                                      0x00000790, 0x00000710 };

#define ALLDISP  0x00180000 //Select all display
#define DATAPORT 0x00000ff0 //P0.4 to P0.11 : Data lines connected to drive Seven Segments

int main (void)
{
	unsigned long adc_temp;
	unsigned int i;
	float in_vtg;

 LPC_PINCON->PINSEL0 = 0x00000000;
 LPC_PINCON->PINSEL3 |= 0xC0000000;	//P1.31 as AD0.5
	LPC_SC->PCONP |= (1<<12);	//enable the peripheral ADC

 //LPC_PINCON->PINSEL3 = 0X00000000;
 LPC_GPIO0->FIODIR = 0xFF<<4;
 LPC_GPIO1->FIODIR = 0xF<<23;
 
 
 
/*for(i=0;i<=9;i++)
	{
					LPC_GPIO1->FIOSET = 3<<23;
					LPC_GPIO0->FIOPIN = Disp[i];
					for(a=0;a<10000000;a++);
		for(j=0;j<=9;j++)
		{
					LPC_GPIO1->FIOSET = 2<<23;
					LPC_GPIO0->FIOPIN = Disp[j];
					for(a=0;a<10000000;a++);
			for(k=0;k<=9;k++)
			{
				  LPC_GPIO1->FIOSET = 1<<23;
					LPC_GPIO0->FIOPIN = Disp[k];
					for(a=0;a<10000000;a++);
				for(l=0;l<=9;l++)
				{
					LPC_GPIO1->FIOSET = 0x00000000;
					LPC_GPIO0->FIOPIN = Disp[l];
					for(a=0;a<10000000;a++);
					
				}
				 
				
				
			}
		}
	}
	*/
	
	
	while(1)
	{
		LPC_ADC->ADCR = (1<<5)|(1<<21)|(1<<24);//0x01200001;
		while((adc_temp = LPC_ADC->ADGDR) == 0x80000000);
		adc_temp = LPC_ADC->ADGDR;
		adc_temp >>= 4;
		adc_temp &= 0x00000FFF;			//12 bit ADC
		in_vtg = (((float)adc_temp * (float)Ref_Vtg))/((float)Full_Scale);
		number=adc_temp;
		
		if(number<1000)
		{
			n = 0001;
			for(i=0;i<4;i++)
		{
			LPC_GPIO1->FIOPIN=i<<23;
			LPC_GPIO0->FIOPIN=Disp[n%10];
			n=n/10;
			for(j=0;j<25000;j++);
		}	
			
		}
		
		else if(number<2000)
		{
			n = 11;
			for(i=0;i<4;i++)
		{
			LPC_GPIO1->FIOPIN=i<<23;
			LPC_GPIO0->FIOPIN=Disp[n%10];
			n=n/10;
			for(j=0;j<25000;j++);
		}	
			
		}
		
		
		else if(number<3000)
		{
			n = 111;
			for(i=0;i<4;i++)
		{
			LPC_GPIO1->FIOPIN=i<<23;
			LPC_GPIO0->FIOPIN=Disp[n%10];
			n=n/10;
			for(j=0;j<25000;j++);
		}	
			
		}
		
		
		else if(number<4000)
		{
			n = 1111;
			for(i=0;i<4;i++)
		{
			LPC_GPIO1->FIOPIN=i<<23;
			LPC_GPIO0->FIOPIN=Disp[n%10];
			n=n/10;
			for(j=0;j<25000;j++);
		}	
			
		}
	}
}
