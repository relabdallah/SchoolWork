.data

str1: .asciiz "Here is the Report of Top 5 employees in Erickson Company:\n"
str2: .asciiz "=============================================\n"
str3: .asciiz "\tLast Name\t\t\tFirst Name\t\tPosition\t\t\tSalary\n"
str10: .asciiz "\t--------\t\t\t--------\t\t-------\t\t\t-----"
str4: .asciiz "\n\tSmith\t\t\t\tAdam\t\t\tDirector\t\t\t"
str5: .asciiz "\n\tHadden\t\t\tMary\t\t\tDirector\t\t\t"
str6: .asciiz "\n\tSimpson\t\t\tMike\t\t\tManager\t\t\t"
str7: .asciiz "\n\tWilliams\t\t\tAndrea\t\tDesigner\t\t\t"
str8: .asciiz "\n\tAmer\t\t\t\tAli\t\t\tDesigner\t\t\t"
str9: .asciiz "\n============================================="

.text

main:
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
	la $a0, str10
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
	la $a0, str9
	syscall

	li $v0, 10
	syscall