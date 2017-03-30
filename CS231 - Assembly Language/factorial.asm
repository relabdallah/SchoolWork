#Ramzi El-abdallah
#Lab 11

.data
str0: .asciiz "Enter an integer between 0-10: "
str1: .asciiz "Invalid Number\n\n"
str2: .asciiz "! = "
str3: .asciiz "0! = 1"

.text

main:
	li $t0, 10	#loads 10 into $t0 as a check

main2:	
	jal getnum	#Gets number from getnum subroutine

	addi $s0, $v0, 0 #saves input from getnum subroutine into $s0
	addi $a0, $s0, 0 #moves input to register to trasfer to subroutine

	jal check

	addi $s0, $v0, 0 #loads input back into $s0
	addi $a0, $s0, 0
	
	jal fact

	addi $s3, $v0, 0 #resut

	li $v0, 1
	addi $a0, $s0, 0
	syscall

	li $v0, 4
	la $a0, str2
	syscall

	li $v0, 1
	addi $a0, $s3, 0
	syscall
	
	j exit		#Jumps to exit

getnum:
	li $v0, 4
	la $a0, str0
	syscall

	li $v0, 5
	syscall

	jr $ra

check:				#subroutine that checks if input is less than 10
	addi $t1, $a0, 0	#loads input into $t1

	bge $t1, $0, check2

	li $v0, 4
	la $a0, str1
	syscall

	j main2

check2:
	ble $t1, $t0, check3

	li $v0, 4
	la $a0, str1
	syscall

	j main2

check3:
	bne $t1, $0, return

	li $v0, 4
	la $a0, str3
	syscall

	j exit

return:
	addi $v0, $t1, 0	#moves $t1 back to $v0 and goes back to main routrine
	jr $ra

fact:
	addi $t1, $a0, 0
	addi $s1, $a0, 0
	addi $t2, $t2, 1
	li  $t3, 1
start:	
	beq $t2, $s1, return2
	sub $t3, $s1, $t2
	mult $t1, $t3
	mflo $t1
	addi $t2, $t2, 1
	j start
	

return2:
	addi $v0, $t1, 0
	jr $ra

exit:
	li $v0, 10
	syscall