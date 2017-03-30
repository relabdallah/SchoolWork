/*----------------------------------------------------------------------------
LAB EXERCISE - Real-Time Operating System
 ----------------------------------------
	Integrate functions developed in previous modules and run then concurrently
	in the mbed RTOS. The following four threads have to be implemented:
	
 1.	Display the temperature on the PC
 2.	Adjust the frequency of a sound wave using a potentiometer
 3.	Display an incrementing counter on the PC
 4.	Blink an LED
 
	GOOD LUCK!
 *----------------------------------------------------------------------------*/

#include "mbed.h"
#include "rtos.h"
#include "DS1631.h"
#include "pindef.h"

/*
Define the mutex
Define the PC display and the temperature sensor
Define other inputs and outputs
*/

//Write your code here
I2C temp_sensor(I2C_SDA, I2C_SCL);
Serial pc(UART_TX, UART_RX);


//Display temperature on the PC
void temp_thread(void const *args){
	const int temp_addr = 0x90;
	char cmd[] = {0x51, 0xAA};
	char read_temp[2];
	while(1){
		//write your code here
		temp_sensor.write(temp_addr, &cmd[0], 1);
		wait(0.8);
		temp_sensor.write(temp_addr, &cmd[1], 1);
		wait(0.1);

		temp_sensor.read(temp_addr, read_temp, 2);
		
		//Convert temperature to Celsius
		float temp = (float((read_temp[0] << 8) | read_temp[1]) / 256);
		
		//Print temperature to the serial monitor
		pc.baud(9600);
		pc.printf("Temperature: %f\n", temp);
		wait(1);
	}
}

//Adjust the fequency of the sound wave
void adjust_frequency(void const *args){
	
	//write your code here
	
}

//Blink an LED
void led1_thread(void const *args){
	
	//write your code here
	
}

//Display a counter on the PC
void count_thread(void const *args){
	
	//write your code here
	
}

/*----------------------------------------------------------------------------
 MAIN function
 *----------------------------------------------------------------------------*/

int main(){
	/*
	Initialise 
	Start all threads
		*/
	Thread t1(temp_thread);
	//Thread t2(adjust_frequency);
	//Thread t3(led1_thread);
	//Thread t4(count_thread);
	
	//write your code here
	
	//Wait for timer interrupt
	  while(1){
		__wfi();
	}

}

// *******************************ARM University Program Copyright (c) ARM Ltd 2014*************************************
