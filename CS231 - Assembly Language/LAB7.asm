# Ramzi El-abdallah
# Lab 7 - February 24, 2014

	.data	
	array1: .space 40
	str1: .asciiz "How many elements would you like to enter?\nChoose up to 10 elements: "
	str2: .asciiz "Element #"
	str3: .asciiz ":\t"
	str4: .asciiz "\nThe median number is "

	.text

main:		
	la $s0, array1	#loads address of array 1 into $s0
	
	li $v0, 4
	la $a0, str1	#asks user for number of elements
	syscall		
	
	li $v0, 5
	syscall		#gets input from user
	
	add $a0, $v0, $0 #stores input into $a0 to pass to subroutine
	add $a1, $s0, $0 #stores address of array1 into $a1 in order to pass to subroutine
	
	jal fillarray	#jump and link to fillarray
	add $s1, $v0, $0#total number of elements in $s1
	
	li $s2, 2
	
	div $s1, $s2	#divides number of elements by to to see if it is even or odd
	mflo $s3	#quotient
	mfhi $s4	#remainder
	
	add $a0, $s0, $0	#loads address of array into $a0 to pass
	add $a1, $s3, $0	#loads quotient into $a1 to pass
	
	beq $s4, $0, even	#checks if remainder is equal to zero. If so we know it is even
	
	jal ifodd
	
	j next

even:	jal ifeven

next:	
	add $s5, $v0, $0
	
	li $v0, 4
	la $a0, str4
	syscall
	
	li $v0, 1
	add $a0, $s5, $0
	syscall
	
	j done
	
ifodd:
	add $t0, $a0, $0	#array1 address
	add $t1, $a1, $0	#quotient
	li $t2, 4
	
	mult $t1, $t2
	mflo $t3
	
	add $t0, $t0, $t3
	
	lw $t4, 0($t0)
	add $v0, $t4, $0
	
	jr $ra

ifeven:
	add $t0, $a0, $0	#array1 address
	add $t1, $a1, $0	#quotient
	li $t2, 4
	li $t6, 2
	
	mult $t1, $t2
	mflo $t3
	
	add $t0, $t0, $t3
	
	lw $t4, 0($t0)
	sub $t0, $t0, 4
	lw $t5, 0($t0)
	
	add $t5, $t4, $t5
	
	div $t5, $t6
	mflo $t7
	
	add $v0, $t7, $0
	
	jr $ra	
	
fillarray:
	add $t0, $a0, $0 #stores back input into $t0
	add $t1, $a1, $0 #stores address of array1 into $t1
	li $t2, 1	#sets the count to 1
	
	fill:	bgt $t2, $t0, return	#loop to fill array
		
		li $v0, 4
		la $a0, str2
		syscall
	
		li $v0, 1
		add $a0, $t2, $0
		syscall
		
		li $v0, 4
		la $a0, str3
		syscall
		
		li $v0, 5
		syscall
		
		sw $v0, 0($t1)
				
		addi $t2, $t2, 1	#incriment count
		addi $t1, $t1, 4	#incriment address
		
		j fill
		
	return:	add $v0, $t0, $0
		jr $ra #returns to main
	
done: 
	li $v0, 10
	syscall

# END OF PROGRAM