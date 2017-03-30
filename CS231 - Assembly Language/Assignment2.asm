#Ramzi El-abdallah
#Assignment 2

	.data	
		array: .space 80
		str0: .asciiz "\nPlease enter the size of your array (1-19): "
		str1: .asciiz "Sorry invalid entry.\n"
		str2: .asciiz "\nElement #"
		str3: .asciiz ": "
		str4: .asciiz "\n\nThe array in reverse order is:"
	.text

main:		
	la $s3, array
	
	li $v0, 4
	la $a0, str0
	syscall
	
	jal readNum		#jumps to readNum subroutine

	addi $s0, $v0, 0	#stores input into $s0 after returning from readNum
	addi $a0, $s0, 0	#stroes array size into $a0 to send to verifySize

	jal verifySize		#jumps to verifySize subroutine
	addi $s1, $v0, 0	#true or false value from verifySize
	
	bne $s1, $0, proceed
	
	li $v0, 4
	la $a0, str1
	syscall
	
	j main
	
proceed:
	addi $a0, $s0, 0	#loads array size to pass
	jal createArray
	
	
	addi $a0, $s0, 0
	jal printArray
	
	addi $a0, $s0, 0
	jal reverseArray
	
	addi $a0, $s0, 0
	jal printArray

	j exits

readNum:	
	li $v0, 5
	syscall			#user inputs size of array
	
	jr $ra

verifySize:
	li $t1, 20		#maximum
	addi $t0, $a0, 0	#loads user input into $t0
	
	check1:	
		bgt $t0, $0, check2	#checks to see if greater than 0
		
		addi $v0, $0, 0		#returns false if less than 0
		
		jr $ra
		
	check2:
		blt $t0, $t1, returnTrue	#checks to see if less than 20
		
		addi $v0, $0, 0			#returns false if less greater than 20
		
		jr $ra
		
	returnTrue:
		addi $v0, $t0, 1	#returns true if 0<input<20
		jr $ra

createArray:
	addi $t0, $0, 0 	#count
	addi $t1, $a0, 0	#array size
	la $s3, array		#loads address of array into $s3
	
	sub $sp, $sp, 4
	sw $ra, 0($sp)		#saves return address to stack pointer
	
	makingArray:
		beq $t0, $t1, returnMain
		jal readNum
		addi $s2, $v0, 0	#saves input into $s2
		
		j checkNumPositive
		
	
	checkNumPositive:
		sgt $t4, $s2, $0	#sets $t4 to 1 if number is greater than 0
	
		bne $t4, $0, divisibleBy3
		
		li $v0, 4
		la $a0, str1
		syscall
		
		j makingArray

	divisibleBy3:
		li $t4, 3
		
		div $s2, $t4
		mfhi $t5
		
		seq $t6, $t5, $0
		
		beq $t6, $0, makingArray
		
		sw $s2, 0($s3)
		addi $t0, $t0, 1
		addi $s3, $s3, 4
		
		j makingArray
	
	returnMain:
		lw $ra 0($sp)
		addi $sp, $sp, 4
		jr $ra
	
reverseArray:
	addi $t0, $0, 1		#count
	addi $s0, $a0, 0	#array size
	la $t3, array		#address of array
	la $t4, array		#address of array
	li $t1, 4
	
	mult $s0, $t1
	mflo $t2
	sub $t2, $t2, 4
	add $t4, $t4, $t2
	loop:
	ble $t4, $t3, endReverse
	
	lw $t5, 0($t3)
	lw $t6, 0($t4)
	
	sw $t5, 0($t4)
	sw $t6, 0($t3)
	
	addi $t3, $t3, 4
	sub $t4, $t4, 4
	
	j loop
	
	endReverse:
		li $v0, 4
		la $a0, str4
		syscall
	
		jr $ra


printArray:
	addi $t0, $0, 1
	addi $s0, $a0, 0
	la $t3, array
	
	start:
	bgt $t0, $s0, returnMain1
	lw $t4, 0($t3)
	
	li $v0, 4
	la $a0, str2
	syscall
	
	li $v0, 1
	addi $a0, $t0, 0
	syscall
	
	li $v0, 4
	la $a0, str3
	syscall
	
	li $v0, 1
	addi $a0, $t4, 0
	syscall
	
	addi $t0, $t0, 1
	addi $t3, $t3, 4
	
	j start
	
	returnMain1:
	jr $ra

exits:
	li $v0, 10
	syscall