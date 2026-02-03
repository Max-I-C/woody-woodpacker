BITS 64

section .text 

start:
    ; 1. Save all register
    pushf
    push rax
    push rbx
    push rcx
    push rdx
    push rsi
    push rdi
    push r8
    push r9
    push r10
    push r11
    push r12
    push r13
    push r14
    push r15

    ; 2. mprotect of the .text section
    lea rdi, [rel start]
    mov rax, 0xDDDDDDDDDDDDDDDD ; Offset start - start of the segment
    sub rdi, rax               
    mov r12, rdi                ; We mark that area with the address of text offset 

    mov r13, 0xfffffffffffff000
    and rdi, r13                ; Align the page
    mov rsi, 0xEEEEEEEEEEEEEEEE ; size of the crypted area
    add rsi, 0x2000             ; Marge
    mov rdx, 7                  ; RWX
    mov rax, 10                 ; Selecting the mprotect syscall
    syscall                     ; Calling the mportect

    ; 3. TEA Decryptage
    call decrypt_tea

    ; 4. Virus
    lea rdi, [rel start]
    mov rax, 0xBBBBBBBBBBBBBBBB ; Mark the area to inject the parasite code
    sub rdi, rax
    call rdi                    ; Print "WOODY"

    ; 5. Restore all register
    pop r15
    pop r14
    pop r13
    pop r12
    pop r11
    pop r10
    pop r9
    pop r8
    pop rdi
    pop rsi
    pop rdx
    pop rcx
    pop rbx
    pop rax
    popf
    
    ; 6. Jump to entry point
    lea r11, [rel start]
    mov rax, 0xAAAAAAAAAAAAAAAA ; Mark the address for the old entry point 
    add rax, r11
    jmp rax

decrypt_tea:
    mov rdi, r12                ; Crypted address
    mov rcx, 0xEEEEEEEEEEEEEEEE ; Size
    shr rcx, 3                  ; 8 octet block
    
    ; Adress layout of the key
    lea rsi, [rel start]
    mov r9, 0xCCCCCCCCCCCCCCCC  ; Collecting the key
    add rsi, r9

.loop_blocks:
    test rcx, rcx
    jz .done
    mov r10d, [rdi]             ; v0
    mov r11d, [rdi+4]           ; v1
    mov r12d, 0xC6EF3720        ; sum = delta * 32
    mov edx, 32
.loop_rounds:
    ; --- Inversion TEA ---
    ; v1 -= ((v0 << 4) + k[2]) ^ (v0 + sum) ^ ((v0 >> 5) + k[3])
    mov eax, r10d
    shl eax, 4
    add eax, [rsi+8]
    mov ebx, r10d
    add ebx, r12d
    xor eax, ebx
    mov r8d, r10d
    shr r8d, 5
    add r8d, [rsi+12]
    xor eax, r8d
    sub r11d, eax

    ; v0 -= ((v1 << 4) + k[0]) ^ (v1 + sum) ^ ((v1 >> 5) + k[1])
    mov eax, r11d
    shl eax, 4
    add eax, [rsi]
    mov ebx, r11d
    add ebx, r12d
    xor eax, ebx
    mov r8d, r11d
    shr r8d, 5
    add r8d, [rsi+4]
    xor eax, r8d
    sub r10d, eax

    sub r12d, 0x9e3779b9        ; delta
    dec edx
    jnz .loop_rounds
    
    mov [rdi], r10d
    mov [rdi+4], r11d
    add rdi, 8
    dec rcx
    jmp .loop_blocks
.done:
    ret