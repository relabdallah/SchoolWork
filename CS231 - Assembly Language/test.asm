# UNTITLED PROGRAM

	.data	# Data declaration section

	.text

main:		# Start of code section
	li $v0, 5
	syscall
	
	add $s0, $v0, $0
begin:
	addi $t0, $0, 0
	addi $t1, $0, 1
loop:
	slt $t2, $s0, $t1
	bne $t2, $0, finish
	add $t0, $t0, $t1
	addi $t1, $t1, 2
	j joop
finish:
	li $v0, 1
	add $a0, $t0, $0
	syscall

# END OF PROGRAM