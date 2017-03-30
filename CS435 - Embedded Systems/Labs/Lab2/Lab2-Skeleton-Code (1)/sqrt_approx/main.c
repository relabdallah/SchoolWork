/*----------------------------------------------------------------------------
LAB EXERCISE 5.2 - SQUARE ROOT APPROXIMATION
 ----------------------------------------
Write an assembly code subroutine to approximate the square root of an 
argument using the bisection method. All math is done with integers, so the 
resulting square root will also be an integer

GOOD LUCK!
 *----------------------------------------------------------------------------*/
//Ramzi El-abdallah
//Lab 2
//CS435 
//October 3, 2016

__asm int my_sqrt(int x){
	
	//pushes registers to be used onto stack
	push {r9};	//holds value of done
	push {r11};	//will hold c_old
	push {r6};	//used to hold a+b
	push {r7};	//holds 2
	push {r10};	//stores c*c
	
	mov32 r1, #0;				//a = 0
	mov32 r2, #65536;		//b = 2^16
	mov32 r3, #-1;			//c = -1
	mov32 r9, #0;				//Initiate done to 0
	mov32 r7, #2;				//holds value of 2
	
loop
	mov r11, r3;			//puts c into c_old
	add r6, r1, r2; 	//a+b
	udiv r6, r6, r7;	//divide by 2
	mov r3, r6;				//stores value of c
	mul r10, r3, r3;	//c*c
	cmp r10, r0;			//compare with x
	beq setdone;			//branch to setdone if result is found r10 = r0
	blt lessthan;			//branch to lessthan if r10 < r0
	bgt greaterthan;	//branch to greater than if r10 > r0
	
//sets a = c and checks if c = c_old, if so branches to setdone	
lessthan
	mov r1, r3;
	cmp r3, r11;
	beq setdone;
	b check1;
	
//sets b = c and checks if c = c_old, if so branches to setdone	
greaterthan
	mov r2, r3;
	cmp r3, r11;
	beq setdone;
	b check1;
	
//sets done to 1 then branches to check1
setdone
	mov32 r9, #1;
	b check1;
	
//checks to see if done != 0 is true(done = 1), then branches to finish. Else branch back to loop
check1
	cmp r9, #0;
	bne finish;
	beq loop;
	
//moves c (r3) into r0 to be returned to main
finish
	mov r0, r3;
	
	pop {r9, r11, r6, r7, r10};	//pops registers off the stack

	bx lr;	//branches back to main

}

/*----------------------------------------------------------------------------
 MAIN function
 *----------------------------------------------------------------------------*/
int main(void){
	volatile int r, j=0;
	int i;
  r = my_sqrt(0);     // should be 0
  r = my_sqrt(25);    // should be 5
	r = my_sqrt(133); 	// should be 11
  for (i=0; i<10000; i++){
		r = my_sqrt(i);
    j+=r;
  }
	while(1)
		;
}

// *******************************ARM University Program Copyright (c) ARM Ltd 2014*************************************
