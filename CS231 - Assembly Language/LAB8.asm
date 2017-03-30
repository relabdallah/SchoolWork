#Ramzi El-abdallah
#Lab 8 - Floating Point (Convert Fahrenheit to Celsius)

	.data
		str0: .asciiz "Please enter in a temperature in Celsius: "
		str1: .asciiz "\nThe temperature in Fahrenheit is : "
	
	.text

main:		# Start of code section
	li $v0, 4
	la $a0, str0	#Prints string
	syscall
	
	li $v0, 5
	syscall		#gets input from user (temperature in Celsius)
	
	mtc1 $v0, $f1	#moves value from main processor to coprocessor
	cvt.s.w	$f1, $f1#converts to float
	mov.s $f5, $f1
	
	li $v0, 9	#loads values to be used in conversion formula
	mtc1 $v0, $f1
	cvt.s.w	$f1, $f1
	mov.s $f2, $f1
	
	li $v0, 5
	mtc1 $v0, $f1
	cvt.s.w	$f1, $f1
	mov.s $f3, $f1
	
	li $v0, 32
	mtc1 $v0, $f1
	cvt.s.w	$f1, $f1
	mov.s $f4, $f1
	
	mul.s $f5, $f5, $f2	#multiplies temperature by 9
	div.s $f5, $f5, $f3	#divides by 5
	add.s $f5, $f5, $f4	#adds 32
	
	li $v0, 4
	la $a0, str1
	syscall
	
	li $v0, 2
	mov.s $f12, $f5
	syscall
	
done:
	li $v0, 10
	syscall
	
	
	
	
	
	

# END OF PROGRAM