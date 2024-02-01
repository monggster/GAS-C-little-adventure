#   $ as -o hello.o hello.s
#   $ ld -o hello hello.o

.globl _start

.data
message: .asciz "Hello world!\n" # some text

.text
_start:
	movq $message, %rsi	# address of the message
	movq $1, %rdi		# choose std (out)
	movq $12, %rdx		# length of the message
	movq $1, %rax		# write (to std)
	syscall
	
	movq $0, %rdi		# return 0
	movq $60, %rax 		# end program
	syscall
