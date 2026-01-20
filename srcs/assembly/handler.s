BITS 64

section .text 

start:
    push rax
    push rdi
    push rsi

    lea rax, [rel start]
    mov rdi, 0xBBBBBBBBBBBBBBBB
    sub rax, rdi
    call rax

    pop rsi
    pop rdi
    pop rax

    lea r11, [rel start]
    mov rax, 0xAAAAAAAAAAAAAAAA
    add rax, r11
    jmp rax