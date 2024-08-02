.globl my_ili_handler

.text
.align 4, 0x90
my_ili_handler:
movq 0(%rsp) , %rax # need to save the registers
cmpb $0x0f , %al
je what_to_do_2bytes
movzx %al , %rdi
call what_to_do

cmp $0 , %rax
je old_precedure
movq 0(%rsp) , %r9 # advancing rip 1 byte
leaq 1(%r9) , %r9
movq %r9 , 0(%rsp)
jmp next_precedure

what_to_do_2bytes:
movb %ah , %al
movzx  %al , %rdi
call what_to_do
cmp $0 , %rax
je old_precedure

movq 0(%rsp) , %r9 # advancing rip 2 bytes
leaq 2(%r9) , %r9
movq %r9 , 0(%rsp)
jmp next_precedure

old_precedure:
old_ili_handler
next_precedure:
iretq
