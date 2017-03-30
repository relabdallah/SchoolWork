.data

str1: .asciiz "Enter 5 Integers:\n"
str2: .asciiz "\nThe sum of the numbers is:\t"

.text

main:


li $v0,4
la $a0, str1
syscall

li $s0, 0
li $s1, 0
li $s2, 5

input:	beq $s1, $s2, sum

	li $v0,5
	syscall

	add $s0, $v0, $s0
	addi $s1, $s1, 1
	j input

sum:	li $v0,4
	la $a0, str2
	syscall

	li $v0, 1
	add $a0, $s0, $0
	syscall


exit:	li, $v0, 10
	syscall