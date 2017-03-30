#Ramzi El-abdallah
#Lab 10


.data

input: .space 10
newline: .asciiz "\n"
encrypt: .space 10
break:	.word	0
decrypt: .space 10

.text

main:
	la $s1, encrypt			#load address of encrypt into $s1
	la $s2, input
	la $s3, decrypt
	li $s0, 10			#count 1
	li $s4, 10			#count 2
	li $s5, 10			#key

	li $v0,8
	la $a0, input
	li $a1, 10
	syscall

	li $v0, 4
	la $a0, newline
	syscall

	li $v0, 4
	la $a0, input
	syscall


loop:
	beq $s0, $0, next
	lb $t0, 0($s2)
	xor $t1, $t0, $s5
	sb $t1, 0($s1)
	li $t0, 0
	li $t1, 0
	addi $s2, $s2, 1
	addi $s1, $s1, 1
	sub $s0, $s0, 1
	j loop

next:
	la $s1, encrypt	
	

loop2:
	beq $s4, $0, print
	lb $t0, 0($s1)
	xor $t1, $t0, $s5
	sb $t1, 0($s3)
	li $t0, 0
	li $t1, 0
	addi $s3, $s3, 1
	addi $s1, $s1, 1
	sub $s4, $s4, 1
	j loop2

print:
	li $v0, 4
	la $a0, newline
	syscall

	li $v0, 4
	la $a0, encrypt
	syscall

	li $v0, 4
	la $a0, decrypt
	syscall


exit:
	li $v0, 10
	syscall