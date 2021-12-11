.section .data
#value相当于是int类型变量
value:
    .int 1
.section .text
# 这个_start是固定的，一个字符都不能改，相当于C语言main
.globl _start
_start:
    #nop可以让pc计数器加1,但在这个程序中没什么特别的作用，放在不管就好
    nop
    #把100这个数传给eax
    movl $100,%eax
    #相当于把eax的值赋值给value变量，并不是改变地址
    movl %eax,value
    #把1赋值给eax
    movl $1,%eax
    #把赋值给eax
    movl $0,%ebx
    #相当于C语言退出程序
    int $0x80