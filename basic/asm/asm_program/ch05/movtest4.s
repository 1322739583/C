.section .data
values:
    .int 10,20,33,35,36,37,38,39
.section .text
.globl _start
_start:
    nop
    movl values,%eax
    movl $values,%edi
    movl $100,4(%edi)
    movl $1,%edi
    movl values(,%edi,4),%ebx
    movl $1,%eax
    int $0x80