#Ramzi Elabdallah
#Lab 6
#9/18/2013

.data

str0: .asciiz "\n\nEnter in your number:\t"
str1: .asciiz " is divisible by 7."
str2: .asciiz " is not divisible by 7, enter another number."
str3: .asciiz "\nGoodbye"

.text


main:

li $s0, 0
li $s1, 5
li $s3, 7

loop:	beq $s0, $s1, exit

	
	li $v0, 4
	la $a0, str0
	syscall

	li $v0, 5
	syscall

	add $s2, $v0, $0

	div $s2, $s3
	mfhi $t0		#moves remainder

	bne $t0, $0, no
	beq $t0, $0, yes

yes:	addi $s0, $s0, 1	#is divisible by 7
		
	li $v0, 1
	add $a0, $s2, $0
	syscall

	li $v0, 4
	la $a0, str1
	syscall

	j loop

no:	li $v0, 1		#is not divisible by 7
	add $a0, $s2, $0
	syscall
		
	li $v0, 4
	la $a0, str2
	syscall

	j loop

exit:	li $v0, 4
	la $a0, str3
	syscall

	li, $v0, 10
	syscall