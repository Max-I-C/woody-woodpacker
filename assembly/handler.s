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

    mov rax, 0xAAAAAAAAAAAAAAAA
    jmp rax