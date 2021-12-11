.section .data
msg:
    .ascii "This is the message"
#length相当于是变量，可以在后面的代码中引用
length:
    .int 10,20,30
factors:
    .double 3.3,1.0,0.5
#静态常量
.equ pi,3
.equ LINUX_SYSTEM_CALL,0x80
# $是取值符号
movl $LINUX_SYSTEM_CALL,%eax

.section .bss
# buffer这个变量现在就代表了10000个内存空间
.lcomm buffer,10000
# 定义500个内存空间 
.comm size,500 