.data

str0: .asciiz "\nHow many numbers do you want to be added?\t"
str1: .asciiz "\nEnter Integers:\n"
str2: .asciiz "\nThe sum of the numbers is:\t"
str3: .asciiz "\nBye"

.text

main:

li $v0,4
la $a0, str0
syscall

li $v0,5
syscall

add $s2, $v0, $0

beq $s2, $0, exit

li $v0,4
la $a0, str1
syscall

li $s0, 0
li $s1, 0

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


exit:	li $v0,4
	la $a0, str3
	syscall

	li, $v0, 10
	syscall