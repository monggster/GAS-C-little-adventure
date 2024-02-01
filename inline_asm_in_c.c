/*
 *  $ gcc -S n.c -o n.s
 *  $ as n.s -o n.o
 *  $ ld n.o -o n /lib/libc.so -I /lib64/ld-linux-x86-64.so.2
 *
 *  This file shows how to use inline assembly and how to link
 *  your file with dynamic librarises (.so) using ld-linux-x86-64 for
 *  dynamic linking
 *
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void _start()
{

    char *str;
    int len, ret;

    str = "Hello world\n";
    len = strlen(str);

    /*__asm__
    (
        "movq $1, %%rax\n\t"
        "movq $1, %%rdi\n\t"
        "movq %1, %%rsi\n\t"
        "movq %2, %%rdx\n\t"
        "syscall"
        : "=g"(ret)
        : "g"(str), "g"(len)
    );*/

    __asm__("syscall" : "=g"(ret) : "a"(1), "D"(1), "S"(str), "d"(len));

    printf("%d\n", ret);

    exit(ret);
}
