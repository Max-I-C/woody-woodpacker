BITS 64

global _init
section .text

_init:
    jmp save_data
    msg: db "....WOODY....", 10

save_data:
    push rax
    push rcx
    push rdx
    push rdi
    push rsi
    push r11
    mov rax, 1
    mov rdi, rax
    lea rsi, [rel msg]
    mov rdx, 14
    syscall
    pop r11
    pop rsi 
    pop rdi
    pop rdx
    pop rcx
    pop rax