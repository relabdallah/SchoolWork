# Ramzi El-abdallah
# Lab 9 Encryption and Decryption
# March 3, 1014


	.data	
		input: .space 10
		encrypt: .space 10
		decrypt: .space 10
		
		str0: .asciiz "Enter up to 9 characters: "
		str1: .asciiz "The encryption is: "
		str2: .asciiz "\nThe decryption is: "
		
	.text

main:	
	la $s0, input
	la $s1, encrypt
	la $s2, decrypt

	li $t0, 10	#count limit
	li $t1, 0	#count
	li $t2, 24	#key
	
	li $v0, 4
	la $a0, str0	#prints str0
	syscall
	
	li $v0, 8
	la $a0, input	#reads characters and saves them to input array
	li $a1, 10
	syscall
	
encr:
	beq $t1, $t0, print1
	lb $t3, 0($s0)		#loads byte from input
	xor $t4, $t3, $t2	#xor's the character
	sb $t4, 0($s1)		#saves encrypted byte into $t4
	li $t3, 0
	li $t4,0
	addi $s0, $s0, 1	#resets and incriments
	addi $s1, $s1, 1
	addi $t1, $t1, 1
	
	j encr
	
	
	
print1:	
	li $v0, 4
	la $a0, str1
	syscall

	li $v0, 4		#prints encrypted message
	la $a0, encrypt
	syscall
	
	li $t1, 0	#reset counter
	la $s1, encrypt
	
decr:
	beq $t1, $t0, print2
	lb $t3, 0($s1)		#loads byte from encrypt
	xor $t4, $t3, $t2
	sb $t4, 0($s2)		#saves decrypted byte into decrypt array
	li $t3, 0
	li $t4,0
	addi $s2 $s2, 1		#resets registers and incriments
	addi $s1, $s1, 1
	addi $t1, $t1, 1
	
	j decr
	
print2:
	li $v0, 4
	la $a0, str2
	syscall

	li $v0, 4
	la $a0, decrypt		#prints out decryp/original message
	syscall

done:
	li $v0, 10		#exit
	syscall
	
	
	
# END OF PROGRAM