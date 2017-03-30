#Ramzi El-abdallah
#Lab 9

.data

str0: .asciiz "=====================================================================\n"
str1: .asciiz "Please enter in a temperature in Celsius:\t"
str2: .asciiz "The temperature in Fahrenheit is:\t\t"
str3: .asciiz "\n"


.text


main:
	addi $s0, $0, 9
	addi $s1, $0, 5
	addi $s2, $0, 32

	mtc1 $s0, $f3
	cvt.s.w $f3, $f3

	mtc1 $s1, $f4
	cvt.s.w $f4, $f4
	
	mtc1 $s2, $f5
	cvt.s.w $f5, $f5

	li $v0, 4
	la $a0, str0
	syscall

	li $v0, 4
	la $a0, str1
	syscall

	li $v0, 5
	syscall

	mtc1 $v0, $f1
	cvt.s.w $f1, $f1

	li $v0, 4
	la $a0, str0
	syscall

	mul.s $f1, $f1, $f3
	div.s $f1, $f1, $f4
	add.s $f1, $f1, $f5

	mov.s $f12, $f1

	li $v0, 4
	la $a0, str2
	syscall

	li $v0, 2
	syscall

	li $v0, 4
	la $a0, str3
	syscall

exit:
	li $v0, 4
	la $a0, str0
	syscall

	li $v0, 10
	syscall