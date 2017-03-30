.data

str1: .asciiz "\nPlease input two numbers:\n"
str2: .asciiz "\nSum is:\t\t"
str3: .asciiz "\nDifference is:\t"
str4: .asciiz "\nProduct is:\t\t"
str5: .asciiz "\nQuotient is:\t"
str6: .asciiz "\nRemainder is:\t"

.text


main:

li $v0,4
la $a0, str1
syscall

li $v0,5
syscall

add $s0, $v0, $0

li $v0,5
syscall

add $s1, $v0, $0

add $s2, $s0, $s1

li $v0, 4
la $a0, str2
syscall

add $a0, $s2, $0

li $v0, 1
add $a0, $s2, $0
syscall

sub $s2, $s0, $s1

li $v0, 4
la $a0, str3
syscall

li $v0, 1
add $a0, $s2, $0
syscall

mult $s0, $s1

mfhi $t0
mflo $t1

li $v0, 4
la $a0, str4
syscall

li $v0, 1
add $a0, $t0, $t1
syscall

div $s0, $s1

mfhi $t0
mflo $t1

li $v0, 4
la $a0, str5
syscall

li $v0, 1
add $a0, $t1, $0
syscall

li $v0, 4
la $a0, str6
syscall

li $v0, 1
add $a0, $t0, $0
syscall

li, $v0, 10
syscall