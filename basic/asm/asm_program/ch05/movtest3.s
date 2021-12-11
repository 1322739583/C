#@TODO 先放着吧，明白代码的意思就行，后面再找运行的办法

#执行的时候需要使用下面的命令，要用64位的so，书上使用的是32位的，在执行的二进制的时候会报正在访问一个已经损坏的库
#但这也不是好的方法，因为as命令还是只能是32位的，执行二进制的时候直接core dump
#ld -dynamic-linker /lib/ld-linux-x86-64.so.2  -o movtest3  -lc  movtest3.o 

#需要添加这行，在64位系统和32位系统的as命令对于某些汇编指令的处理支持是不一样的。
#如果不添加，在执行as命令的时候就会报错，如invalid instruction suffix for `push'
.code32
.section .data
output:
# 后面将执行一段非常神奇的操作，通过调用C语言的printf函数来输出。
    .asciz "The value is %d\n"
values:
    .int 10,20,25,30,33,36,37
.section .text
.globl _start
_start:
    nop
    # edi寄存器是(destination index)目标地址寄存器,从名字就可以看出，这个寄存器就是用来存放地址的
    mov $0,%edi
#在汇编中，后面有：的叫做标记，可以当变量使用，还可以用来卡地址，非常的有意思
#例如这里的loop,可以通过别的代码跳到这个位置实现循环的效果，loop这个名字是可以随便取的g
loop:
# 第一个参数表示偏移量，不写就是0,第二个参数表示index,第三个参数表示变量大小
# base_address(offset,index,size),adress=base_adress+offset+index*size
# 这里表示取values的第一个值，int占4个字节，并把取出来的值传给eax
    movl values(,%edi,4),%eax
# 把这两个内容压入栈中，作为printf的两个参数printf(char *,int)
#这样就可以调用C语言的printf方法,需要在链接的时候添加具体的命令
    pushl %eax
    pushl $output
    call printf
    addl $8,%esp
    inc %edi
    cmpl $7,%edi
    jne loop
    movl $0,%ebx
    movl $1,%eax
    int $0x80