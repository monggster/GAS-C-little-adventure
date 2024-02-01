.globl _start, sys_write
.text

_start:
    call main

exit:
    movq $0, %rdi
    movq $60, %rax
    syscall

sys_write:
    pushq %rdi

    call _strlen
    movq %rdi, %rdx

    popq %rsi
    movq $1, %rdi
    movq $1, %rax
    syscall
    ret

_strlen:
    pushq %rdi
    movq %rdi, %rsi     # копируем адрес в RSI для последующего поиска индекса
    movb $0, %al        # в AL символ для поиска
    movq $-1, %rcx      # максимальное число
    repne scasb         # ищем байт
    popq %rsi
    subq %rsi, %rdi     # если символ найден, получаем индекс следующего символа после найденного
    ret
