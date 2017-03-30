#Ramzi El-abdallah
#Lab 5b


.data
	purchase: .space 80
	coupon:	.space 80
	total: .space 80
	str1: .asciiz "Please enter the number of items you are purchasing: "
	str2: .asciiz "\nSorry, too many items.\n"
	str3: .asciiz "Please enter the price for item "
	str4: .asciiz "Please enter the number of coupons you are using: "
	str5: .asciiz "\nPlease enter the ammount of coupon "
	str6: .asciiz "\nSorry, this coupon is not acceptable.\n"
	str7: .asciiz "\nYour total is: $"
	newline: .asciiz "\n"
	money: .asciiz "\n$"


.text
	la $s0, purchase
	la $s1, coupon
	la $s2, total
	addi $s3, $0, 20	#item limit
	addi $s4, $0, 10	#coupon limit
	addi $t0, $0, 1		#count

	li $v0, 4
	la $a0, str1
	syscall

	li $v0, 5
	syscall			#gets number of items from user

	add $t1, $v0, $0

check1:	ble $t1, $s3, next1

	li $v0, 4
	la $a0, str2
	syscall

	li $v0, 4
	la $a0, str1
	syscall

	li $v0, 5
	syscall			#gets number of items from user

	add $t1, $v0, $0

	j check1

next1: 
	bgt $t0, $t1, cpns
	
	li $v0, 4
	la $a0, str3
	syscall

	li $v0, 1
	addi $a0, $t0, 0
	syscall

	li $v0, 4
	la $a0, money
	syscall

	li $v0, 5
	syscall		#gets price of item

	add $t2, $v0, $0

	sw $t2, 0($s0)

	addi $t0, $t0, 1
	addi $s0, $s0, 4

	j next1

cpns:
	addi $t0, $0, 1	#reset counter

	li $v0, 4
	la $a0, str4
	syscall

	li $v0, 5
	syscall

	add $t3, $v0, $0	#number of coupons

entercpn:
	bgt $t0, $t3, next2

	li $v0, 4
	la $a0, str5
	syscall

	li $v0, 1
	addi $a0, $t0, 0
	syscall

	li $v0, 4
	la $a0, money
	syscall

	li $v0, 5
	syscall

	addi $t4, $v0, 0

	bgt $t4, $s4, check2

	sw $t4, 0($s1)

	addi $t0, $t0, 1
	addi $s1, $s1, 4

	j entercpn

check2:
	li $v0, 4
	la $a0, str6
	syscall

	sw $0, 0($s1)

	addi $t0, $t0, 1
	addi $s1, $s1, 4

	j entercpn

next2:
	la $s0, purchase
	la $s1, coupon
	addi $t0, $0, 1	#reset counter


subtotal:
	bgt $t0, $t1, reload

	lw $t5, 0($s0)
	lw $t6, 0($s1)

	sub $t7, $t5, $t6

	sw $t7, 0($s2)

	addi $t0, $t0, 1
	addi $s0, $s0, 4
	addi $s1, $s1, 4
	addi $s2, $s2, 4

	j subtotal

reload:
	la $s2, total
	addi $t0, $0, 1	#reset counter

sum:
	bgt $t0, $t1, exit
	
	lw $t8, 0($s2)

	add $s5, $t8, $s5

	addi $t0, $t0, 1
	addi $s2, $s2, 4

	j sum


exit:
	li $v0, 4
	la $a0, str7
	syscall

	li $v0, 1
	addi $a0, $s5, 0
	syscall

	li $v0, 10
	syscall