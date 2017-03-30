# Ramzi El-abdallah
#Lab 6
#9/22/2013
#========================================================================

.data

str1: .asciiz "The arrray arr1 has the following numbers:\n"
str2: .asciiz " is divisible by 5\n"
str3: .asciiz "\nThe sum of the numbers that is divisible by 5 is: "
str4: .asciiz "\n"
arr1: .word 10, 12, 30, 41, 105

.text


main:	li $t0, 5
	li $t1, 0
	la $t2, arr1

	li $v0, 4
	la $a0, str1
	syscall


loop:	beq $t1, $t0, exit
	lw $s0, 0($t2)
	div $s0, $t0		#divides by 5
	mfhi $t3		#moves remainder

	beq $t3, $0, sum

	li $v0, 1
	add $a0, $s0, $0
	syscall

	li $v0, 4
	la $a0, str4
	syscall

	add $t1, $t1, 1		#increment counter
	add $t2, $t2, 4		#increment array
	j loop
	

sum:	li $v0, 1
	add $a0, $s0, $0
	syscall

	li $v0, 4
	la $a0, str2
	syscall

	add $s1, $s0, $s1	#adds numbers that are divisible be 5
	add $t1, $t1, 1		#increment counter
	add $t2, $t2, 4		#increment array
	j loop


exit:	li $v0, 4
	la $a0, str3
	syscall

	li $v0, 1
	add $a0, $s1, $0
	syscall

	li $v0, 10
	syscall