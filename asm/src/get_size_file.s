[Bits 64]

global get_size_file

section .bss
    statbuf resb 88; Taille de la structure stat (variable selon le système, souvent autour de 144 octets)

section .data
    filename db '../bsq_map/map_default/map_100_100', 0

section .text

get_size_file:

    enter 0,0                    ; sys_stat (filename, statbuf)
; open file in current dir
    mov rax, 2
    mov rdi, filename 
    xor rsi, rsi
    mov rdx, 0
    syscall
    push rax

    mov rdi, rax ; file descriptior
    mov rsi, 0 ; offset
    mov rdx, 2 ; whence
    mov rax, 8 ; sys_lseek
    syscall

    push rax
  ; compare result to actual size
  ; close the file
    pop rdi
    mov rax, 3
    syscall
    
    mov rax, r14
    leave
    ret

.error:
    ; En cas d'erreur, sortir avec un code d'erreur
    mov rax, 60         ; sys_exit
    mov rdi, 2          ; code de sortie 1 (erreur)
    syscall

