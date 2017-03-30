/*----------------------------------------------------------------------------
LAB EXERCISE - Analog input and PWM
 ----------------------------------------
	Use two potentiometers to adjust the volume and pitch of the output sound wave.

	Inputs: potentiometers 1 and 2
	Output: speaker, PC

	GOOD LUCK!
 *----------------------------------------------------------------------------*/

#include "mbed.h"
#include "pindef.h"

/*
Define the PWM speaker output
Define analog inputs
*/

AnalogIn volume(PA_1);
AnalogIn pitch(PA_0);
PwmOut aout(PB_10);

//Define variables
float vol;	
float pit;
float a = 0.003;
float b = 0.000125;

/*----------------------------------------------------------------------------
 MAIN function
 *----------------------------------------------------------------------------*/

int main(){
	while(1){
		/*
		Create a saw-tooth sound wave (range: 320Hz to 8kHz)
		Make the period and volume adjustable using the potentiometers
		*/
		
		//reads analog signal and gives it a value from 0 to 1
		vol = volume.read();
		pit = pitch.read();
		
		//for loop that creats the saw tooth wave
		//linear function a*pit+b sets the frequency
		//a and b are set to be 8kHz at 0 and 320Hz at 1
		for(float i = 0; i < vol; i+=0.05){
			aout = i;
			aout.period(a*pit + b);
			wait(0.01);
		}
	}
}

//*******************************ARM University Program Copyright © ARM Ltd 2016*************************************
