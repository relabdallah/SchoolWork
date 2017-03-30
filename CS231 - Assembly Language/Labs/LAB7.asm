#Ramzi El-abdallah
#=====================================================================================

.data
purchasearray: 
	.align 2
	.space 150
coupon: 
	.align 2
	.space 150
str0: .asciiz "Please enter the number of items you are purchasing:\n"
str1: .asciiz "\nPlease enter the price of item "
str2: .asciiz "\nPlease enter the number of coupons you want to use:\n"
str3: .asciiz "\nPlease enter the ammount of coupon "
str4: .asciiz "\nSorry this coupon is not acceptable."
str5: .asciiz "\n\nYour Sub-total is: $"
str6: .asciiz "\n$"
str7: .asciiz "\nSorry too many items.\n"
str8: .asciiz "\n"
str9: .asciiz "\nThanks for shopping with us!"


.text

main:
	li $t0, 15		#item limit
	li $t1, 1		#item counter
	li $t4, 1		#coupon counter
	li $t7, 10		#coupon limit
	li $s2, 0
	la $t2, purchasearray
	la $s3, purchasearray
	la $t6, coupon
	la $s4, coupon

	li $v0, 4		#asks user for item number
	la $a0, str0
	syscall

	li $v0, 5		#gets number of items
	syscall
	add $s0, $v0, $0

	bgt $s0, $t0, main	#check item amount

loop1:		bgt $t1, $s0, coupons
		
		li $v0, 4	#asks user for price
		la $a0, str1
		syscall

		li $v0, 1
		add $a0, $t1, $0
		syscall

		li $v0, 4
		la $a0, str6
		syscall

		li $v0, 5
		syscall
		add $t3, $v0, $0
		
		add $t1, $t1, 1		#incriments item counter
		
		sw $t3, 0($t2)		#stores amount in array
		add $t2, $t2, 4		#incriment array
		
		j loop1

coupons:	li $t1, 1		#reinitialize counter

		li $v0, 4		#asks for number of coupons
		la $a0, str2
		syscall

		li $v0, 5		#Gets and stores number of coupons
		syscall
		add $s1, $v0, $0

loop2:		bgt $t4, $s1, subtotal
		li $v0, 4		#asks for amout of coupon
		la $a0, str3
		syscall

		li $v0, 1
		add $a0, $t4, $0
		syscall

		li $v0, 4
		la $a0, str8
		syscall

		li $v0, 5
		syscall
		add $t5, $v0, $0

		bgt $t5, $t7, nocoupon

		sw $t5, 0($t6)		#stores amount in array
		add $t6, $t6, 4		#incriment array
		add $t4, $t4, 1		#incriments coupon counter
		j loop2

nocoupon:	li $v0, 4
		la $a0, str4
		syscall

		bgt $t4, $s1, exit

		add $t4, $t4, 1		#incriments coupon counter
		j loop2

subtotal:	li $t4, 1
		bgt $t1, $s0, exit
		lw $t8, 0($s3)
		add $t9, $t8, $t9
		add $s3, $s3, 4
		add $t1, $t1, 1
		j subtotal

totalcoupons:	bgt $t4, $s1, exit
		lw $s5, 0($s4)
		add $s6, $s5, $s6
		add $s4, $s4, 4
		add $t4, $t4, 1
		j totalcoupons

exit:	sub $s7, $t9, $s6

	li $v0, 4
	la $a0, str5
	syscall

	li, $v0, 1
	add $a0, $s7, $0
	syscall

	li $v0, 4
	la $a0, str9
	syscall

	li $v0, 10
	syscall