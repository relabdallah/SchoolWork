#Ramzi El-abdallah
#Lab 6 Subroutine and Stack


.data
	str0: .asciiz "=========================================================================\n"
	str1: .asciiz "Please input a number in decimal form: "
	str2: .asciiz "The number "
	str3: .asciiz " in binary is: "
	newline: .asciiz "\n"

.text
	li $v0, 4
	la $a0, str0
	syscall

	li $v0, 4
	la $a0, str1		#asks user for decimal
	syscall

	li $v0, 5		#gets decimal from user
	syscall

	add $s0, $v0, $0	#saves input into s0 register
	add $t2, $v0, $0	#saves input

	li $v0, 4
	la $a0, str0
	syscall

	add $a0, $s0, $0	#saves input into a0 to pass to subroutine

	jal sub1

	li $v0, 4
	la $a0, str2
	syscall

	li $v0, 1
	addi $a0, $t2, 0
	syscall

	li $v0, 4
	la $a0, str3
	syscall

	jal print		#jumps to print subroutine

	li $v0, 4
	la $a0, newline
	syscall

	li $v0, 4
	la $a0, str0
	syscall

exit:
	li $v0, 10
	syscall

sub1:
	li $s1, 2
	li $t0, 0		#count
	li $t1, 32
	add $s0, $a0, $0	#saves back to s0

divide:	
	beq $t0, $t1, out
	div $s0, $s1		#divides by 2

	mfhi $s2		#stores remainder in s2
	mflo $s0		#stores quotient in s0

	sub $sp, $sp, 4		#moves up on the stack
	sw $s2, 0($sp)		#saves remainder on the stack

	addi $t0, $t0, 1	#incriment counter

	j divide

out:
	jr $ra



print:
	li $t0, 0		#reset counter
loop:
	beq $t0, $t1, out2
	lw $s3, 0($sp)		#loads number from stack to s3

	li $v0, 1
	addi $a0, $s3, 0	#outputs s3
	syscall

	addi $t0, $t0, 1	#incriment counter
	addi $sp, $sp, 4	#incriment stack

	j loop

out2:
	jr $ra