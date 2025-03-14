/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2025 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include <stdint.h>
#include <stdio.h>

/*
 * INPUT PINS: PD11, PD10, PD9, PD8
 * OUTPUT PINS: PD0, PD1, PD2, PD3
 *
 * ADDRESSES:
 * GPIOD Base Register Address:  0x4002 0C00
 * RCC Base Register Address:  0x4002 3800
 * */

void delay() {
	for (uint32_t i = 0; i < 400000; i++) {

	}
}

int main(void)
{
	printf("Debug");
	//Memory Map Pointers
	uint32_t volatile *const RCC_AHB1_REG = (uint32_t*) 0x40023830; //GPIO D Clock Register
	uint32_t volatile *const GPIOD_MODE_REG = (uint32_t*) 0x40020C00; //GPIO D Mode Register
	uint32_t volatile *const GPIOD_PULLUP_REG = (uint32_t*) 0x40020C0C; //GPIO D Pull up Register
	uint32_t volatile *const GPIOD_INPUT_REG = (uint32_t*) 0x40020C10; //GPIO D Data Input Register
	uint32_t volatile *const GPIOD_OUTPUT_REG = (uint32_t*) 0x40020C14; //GPIO D Data Output Register

	//Turn on GPIO D RCC Clock
	*RCC_AHB1_REG |= (1<<3);

	//Set Row Pins as Output: PD0, PD1, PD2, PD3

	/*Could use *GPIOD_MODE_REG |= (0x55); */

	*GPIOD_MODE_REG &= ~(0xFF); //Clearing all bit fields
	*GPIOD_MODE_REG |= (1); //Setting PD0 to output
	*GPIOD_MODE_REG |= (1<<2); //Setting PD1 to output
	*GPIOD_MODE_REG |= (1<<4); //Setting PD2 to output
	*GPIOD_MODE_REG |= (1<<6); //Setting PD3 to output

	//Set Column Pins as Input: PD11, PD10, PD9, PD8

	/* Could use *GPIOD_MODE_REG &= ~(0xFF << 16); */

	*GPIOD_MODE_REG &= ~(1<<23); //Setting PD11 to input
	*GPIOD_MODE_REG &= ~(1<<22); //Setting PD11 to input

	*GPIOD_MODE_REG &= ~(1<<21); //Setting PD10 to input
	*GPIOD_MODE_REG &= ~(1<<20); //Setting PD10 to input

	*GPIOD_MODE_REG &= ~(1<<19); //Setting PD9 to input
	*GPIOD_MODE_REG &= ~(1<<18); //Setting PD9 to input

	*GPIOD_MODE_REG &= ~(1<<17); //Setting PD8 to input
	*GPIOD_MODE_REG &= ~(1<<16); //Setting PD8 to input

	//Activate pull-up resistors for all input pins PD11, PD10, PD9, PD8:

	/* Could use:
	 * *GPIOD_PULLUP_REG &= ~(0xFF << 16);
	 * *GPIOD_PULLUP_REG |= (0x55 << 16);
	 */

	*GPIOD_PULLUP_REG &= ~(1<<23); //Setting pull-up for PD11
	*GPIOD_PULLUP_REG |= ~(1<<22); //Setting pull-up for PD11

	*GPIOD_PULLUP_REG &= ~(1<<21); //Setting pull-up for PD10
	*GPIOD_PULLUP_REG |= ~(1<<20); //Setting pull-up for PD10

	*GPIOD_PULLUP_REG &= ~(1<<19); //Setting pull-up for PD9
	*GPIOD_PULLUP_REG |= ~(1<<18); //Setting pull-up for PD9

	*GPIOD_PULLUP_REG &= ~(1<<17); //Setting pull-up for PD8
	*GPIOD_PULLUP_REG |= ~(1<<16); //Setting pull-up for PD8

	//------------------------------------------------------------------------------------------------->
while(1) {
	//Set all rows to HIGH:
	*GPIOD_OUTPUT_REG |= 0x0F;

	//Make row one(PD0) LOW:
	*GPIOD_OUTPUT_REG &= ~(1 << 0);

	//Scan columns for ROW 1:

	//check C1 (PD8) for LOW or HIGH:
	if (!(*GPIOD_INPUT_REG & (1 << 8))) {
		//The key must be pressed
		delay();
		printf("1\n");
	}

	//check C2 (PD9) for LOW or HIGH:
	if (!(*GPIOD_INPUT_REG & (1 << 9))) {
		//The key must be pressed
		delay();
		printf("2\n");
	}

	//check C3 (PD10) for LOW or HIGH:
	if (!(*GPIOD_INPUT_REG & (1 << 10))) {
		//The key must be pressed
		delay();
		printf("3\n");
	}

	//check C4(PD11) for Low or HIGH:
	if (!(*GPIOD_INPUT_REG & (1 << 11))) {
		//The key must be pressed
		delay();
		printf("A\n");
	}

	//-------------------------------------------------------------------------------------------------->

	//Set all rows to HIGH:
	*GPIOD_OUTPUT_REG |= 0x0F;

	//make Row 2 LOW (PD1)
	*GPIOD_INPUT_REG &= ~(1 << 1);

	//scan columns for ROW 2:

	//check C1 (PD8) for LOW or HIGH:
	if (!(*GPIOD_INPUT_REG & (1 << 8))) {
		//The key must be pressed
		delay();
		printf("4\n");
	}

		//check C2 (PD9) for LOW or HIGH:
	if (!(*GPIOD_INPUT_REG & (1 << 9))) {
		//The key must be pressed
		delay();
		printf("5\n");
	}

		//check C3 (PD10) for LOW or HIGH:
	if (!(*GPIOD_INPUT_REG & (1 << 10))) {
		//The key must be pressed
		delay();
		printf("6\n");
	}

		//check C4(PD11) for Low or HIGH:
	if (!(*GPIOD_INPUT_REG & (1 << 11))) {
		//The key must be pressed
		delay();
		printf("B\n");
	}

		//-------------------------------------------------------------------------------------------------------------->

	//Set all rows to HIGH:
	*GPIOD_OUTPUT_REG |= 0x0F;

	//make Row 3 LOW (PD1)
	*GPIOD_INPUT_REG &= ~(1 << 2);

	//scan columns for ROW 3:

	//check C1 (PD8) for LOW or HIGH:
	if (!(*GPIOD_INPUT_REG & (1 << 8))) {
		//The key must be pressed
		delay();
		printf("7\n");
	}

		//check C2 (PD9) for LOW or HIGH:
	if (!(*GPIOD_INPUT_REG & (1 << 9))) {
		//The key must be pressed
		delay();
		printf("8\n");
	}

		//check C3 (PD10) for LOW or HIGH:
	if (!(*GPIOD_INPUT_REG & (1 << 10))) {
		//The key must be pressed
		delay();
		printf("9\n");
	}

		//check C4(PD11) for Low or HIGH:
	if (!(*GPIOD_INPUT_REG & (1 << 11))) {
		//The key must be pressed
		delay();
		printf("C\n");
	}

	//----------------------------------------------------------------------------------------------->
//
	//Set all rows to HIGH:
	*GPIOD_OUTPUT_REG |= 0x0F;

	//make Row 4 LOW (PD1)
	*GPIOD_INPUT_REG &= ~(1 << 3);

	//scan columns for ROW 4:

	//check C1 (PD8) for LOW or HIGH:
	if (!(*GPIOD_INPUT_REG & (1 << 8))) {
		//The key must be pressed
		delay();
		printf("*\n");
	}

		//check C2 (PD9) for LOW or HIGH:
	if (!(*GPIOD_INPUT_REG & (1 << 9))) {
		//The key must be pressed
		delay();
		printf("0\n");
	}

		//check C3 (PD10) for LOW or HIGH:
	if (!(*GPIOD_INPUT_REG & (1 << 10))) {
		//The key must be pressed
		delay();
		printf("#\n");
	}

		//check C4(PD11) for Low or HIGH:
	if (!(*GPIOD_INPUT_REG & (1 << 11))) {
		//The key must be pressed
		delay();
		printf("D\n");
	}
} //while end

} //main function end

