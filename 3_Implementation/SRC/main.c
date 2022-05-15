


#define GPIOA_BASE_ADDR 0x40020000
#define GPIOA_IDR_OFFSET 0x10
#define GPIOA_IDR *(volatile long *)(GPIOA_BASE_ADDR + GPIOA_IDR_OFFSET)

#define RCC_BASE_ADDR 0x40023800
#define RCC_AHB1ENR_OFFSET 0x30
#define RCC_AHB1ENR *(volatile long *)(RCC_BASE_ADDR + RCC_AHB1ENR_OFFSET)


#define GPIOA_MODE_OFFSET 0x00
#define GPIOA_MODE *(volatile long *)(GPIOA_BASE_ADDR + GPIOA_MODE_OFFSET
  
#define GPIOD_MODE_OFFSET 0x00
#define GPIOD_MODE *(volatile long *)(GPIOD_BASE_ADDR + GPIOD_MODE_OFFSET)

#define GPIOD_BASE_ADDR 0x40020C00
#define GPIOD_ODR_OFFSET 0x14
#define GPIOD_ODR *(volatile long *)(GPIOD_BASE_ADDR + GPIOD_ODR_OFFSET)


#include "main.h"
#include "globalVar.h"
#include <stdio.h>
#include "MyStm32f407xx.h"
/**
 * @file wiper.c
 * @author Swetha M
 * @brief wiper control system
 * @version 0.1
 * @date 2022-05-12
 * 
 * @copyright Copyright (c) 2022
 * 
 */
int main()
{

       int i,b=0,j=0;  // Declare Initilize 
	RCC_AHB1ENR |= (1<<3)|(1<<0); //Enabling the LED and the switch
	GPIOD_MODE = 0; //For Clear LED
	GPIOA_MODE = 0; //For Clear Switch
	GPIOA_IDR |= 1<<3;
	GPIOD_MODE |= (0<<25)|(1<<24);  // LED 12th output pin
	GPIOD_MODE |= (0<<27)|(1<<26);  // LED 13th output pin
	GPIOD_MODE |= (0<<29)|(1<<28);  // LED 14th output pin
	GPIOD_MODE |= (0<<31)|(1<<30);  // Datasheet-LED 14th output pin
	GPIOA_MODE |= (0<<1)|(0<<0);    //Datasheet- Switch input pin
	GPIOD_ODR = 0X00;
	
	while(1)
	{
					while((GPIOA_IDR & 0x01) == 1) // Switch On
					{
						b++; //Increment-Switch
					}
					if(b>3000)
				    {
					b=0;//ON state RED LED
					GPIOD_ODR |= 1<<14;
					for(i=0;i<10000;i++);
					}
					else if(b>0 && b<3000)
					{
					j=1;
                    }
					else
					{

					}
						if(j==1)
						{

					    //By FAST FREQUENCY LAG 

				       
						for(j=0;j<5;j++)  //ORANGE LED
						{
						GPIOD_ODR |= 1<<13;
						for(i=0;i<2000;i++);
						GPIOD_ODR &= ~(1<<13);
					    for(i=0;i>=20000;i++);
						}
						for(j=0;j<7;j++)   // BLUE LED
						{
						GPIOD_ODR |= 1<<15;
						for(i=0;i<2000;i++);
						GPIOD_ODR &= ~(1<<15);
						for(i=0;i>=2000;i++);
						}
						 for(j=0;j<7;j++) //GREEN LED
						{
						GPIOD_ODR |= 1<<12;
						for(i=0;i<2000;i++);
						GPIOD_ODR &= ~(1<<12);
						for(i=0;i>=20000;i++);
						}

						//Medium LAG SPEED

						
						for(j=0;j<7;j++)  // BLUE LED
						{
						GPIOD_ODR |= 1<<15;
						for(i=0;i<4000;i++);
					    GPIOD_ODR &= ~(1<<15);
						for(i=0;i>=4000;i++);
						}
						for(j=0;j<7;j++)  //GREEN LED
						{
						GPIOD_ODR |= 1<<12;
						for(i=0;i<4000;i++);
						GPIOD_ODR &= ~(1<<12);
						for(i=0;i>=4000;i++);
						}
						for(j=0;j<7;j++)  //ORANGE LED
						{
						GPIOD_ODR |= 1<<13;
						for(i=0;i<4000;i++);
						GPIOD_ODR &= ~(1<<13);
						for(i=0;i>=4000;i++);
						}
						
						//High lag speed

						for(j=0;j<7;j++)  // GREEN LED
					    {
						GPIOD_ODR |= 1<<12;
						for(i=0;i<8000;i++);
						GPIOD_ODR &= ~(1<<12);
						for(i=0;i>=8000;i++);
						}
						for(j=0;j<7;j++)  //BLUE LED
						{
						GPIOD_ODR |= 1<<15;
						for(i=0;i<8000;i++);
						GPIOD_ODR &= ~(1<<15);
						for(i=0;i>=8000;i++);
						}
						for(j=0;j<7;j++)  // ORANGE LED
						{
						GPIOD_ODR |= 1<<13;
						for(i=0;i<8000;i++);
						GPIOD_ODR &= ~(1<<13);
						for(i=0;i>=8000;i++);
						}
						

						}


	}
	return 0;
}

