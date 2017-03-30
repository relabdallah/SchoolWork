# Assignment 1 - Question 3


	.data
	location1: .word 45, 67	#first memory location
	location2: .word 78, 90	#second memory location

	.text

main:
	la $s0, location1	#loads the address of location1 into $s0
	la $s1, location2	#loads the address of location2 into $s1
	
	lw $t0, 0($s0)		#loads the first number of location1 (45) into $t0
	lw $t1, 0($s1)		#loads the first number of location2 (78) into $t1
	
	sw $t0, 0($s1)		#replaces first number of location2 with first number of location1
	sw $t1, 0($s0)		#replaces first number of location1 with first number of location2
	
	lw $t0, 4($s0)		#loads the second number of location1 (67) into $t0
	lw $t1, 4($s1)		#loads the second number of location2 (90) into $t1
	
	sw $t0, 4($s1)		#replaces second number of location2 with second number of location1
	sw $t1, 4($s0)		#replaces second number of location1 with second number of location2
	
	li $v0, 10		#exit
	syscall
	


# END OF PROGRAM