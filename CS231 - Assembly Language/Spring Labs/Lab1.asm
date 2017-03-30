#Program Description: Output
#Author: Ramzi El-Abdallah
#Creation Date: 01/31/2014

	.data	# Data declaration section
str0: .asciiz "Here is the Report of Top 5 employees in Erickson Company:"
str1: .asciiz "\n===========================================================================\n"
str2: .asciiz "Last Name\t\tFirst Name\t\tPosition\t\tSalary\n"
str3: .asciiz "---------\t\t----------\t\t--------\t\t------\n"
str4: .asciiz "Smith			Adam\t		Director\t\t"
str5: .asciiz "\nHadden		Mary\t		Director\t\t"
str6: .asciiz "\nSimpson\t	Mike\t		Manager\t\t"
str7: .asciiz "\nWilliams\t	Andrea\t	Designer\t\t"
str8: .asciiz "\nAmer			Ali\t		Designer\t\t"
	.text

main:		# Start of code section
	
	li $v0, 4
	la $a0, str0
	syscall
	
	li $v0, 4
	la $a0, str1
	syscall
	
	li $v0, 4
	la $a0, str2
	syscall
	
	li $v0, 4
	la $a0, str3
	syscall

	li $v0, 4
	la $a0, str4
	syscall
	
	li $v0, 1
	li $a0, 99010
	syscall
		
	li $v0, 4
	la $a0, str5
	syscall
	
	li $v0, 1
	li $a0, 95220
	syscall
	
	li $v0, 4
	la $a0, str6
	syscall
	
	li $v0, 1
	li $a0, 80000
	syscall
	
	li $v0, 4
	la $a0, str7
	syscall
	
	li $v0, 1
	li $a0, 70000
	syscall
	
	li $v0, 4
	la $a0, str8
	syscall
	
	li $v0, 1
	li $a0, 55000
	syscall
	
	li $v0, 4
	la $a0, str1
	syscall
	
	li $v0, 10
	syscall
# END OF PROGRAM