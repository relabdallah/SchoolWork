#Program Description: Arithmatic Instruction
#Author: Ramzi El-Abdallah
#Creation Date: 02/3/2014

	.data
str0: .asciiz "Please enter two numbers:\n"
str1: .asciiz "\nSum is:\t\t"
str2: .asciiz "\nDifference is:\t"
str3: .asciiz "\nProduct is:\t\t"
str4: .asciiz "\nQuotient is:\t"
str5: .asciiz "\nRemainder is:\t"

	.text

main:

	li $v0, 4		#asks user for numbers
	la $a0, str0
	syscall

	li $v0, 5
	syscall
	
	add $t0, $v0, $0	#user inputs first number

	li $v0, 5
	syscall
	
	add $t1, $v0, $0	#user inputs second number

	add $t2, $t0, $t1	#sum

	li $v0, 4		#sum
	la $a0, str1
	syscall

	li $v0, 1		#displays sum
	add $a0, $t2, $0
	syscall

	sub $t2, $t0, $t1	#difference

	li $v0, 4		#difference
	la $a0, str2
	syscall

	li $v0, 1		#displays difference
	add $a0, $t2, $0
	syscall

	mult $t0, $t1		#product
	mflo $t2

	li $v0, 4		#product
	la $a0, str3
	syscall

	li $v0, 1		#displays product
	add $a0, $t2, $0
	syscall

	div $t0, $t1		#division
	mflo $t2
	mfhi $t3		#remainder


	li $v0, 4		#quotient
	la $a0, str4
	syscall

	li $v0, 1		#displays product
	add $a0, $t2, $0
	syscall

	li $v0, 4		#remainder
	la $a0, str5
	syscall

	li $v0, 1		#displays remainder
	add $a0, $t3, $0
	syscall


	li $v0, 10		#exit
	syscall