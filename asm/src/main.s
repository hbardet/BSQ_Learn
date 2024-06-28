; section .data
;     hello db 'Hello, ', 0
;     newline db 10, 0
;     no_args_msg db "No arguments provided.", 10, 0
;
; section .bss
;     ; Rien pour l'instant
;
; section .text
;     global _start
;
;     extern get_size_file
;
; _start:
;     ; Enregistrer argc et argv
;     mov rdi, [rsp]          ; argc est passé via la pile (après l'appel au linker/loader)
;     mov rsi, [rsp + 8]      ; argv est passé via la pile (après l'appel au linker/loader)
;
;     ; Vérifier qu'il y a au moins un argument
;     cmp rdi, 1
;     jle .no_args
;
;     call get_size_file
;     ; Sortir proprement
;     mov rax, 60             ; syscall: sys_exit
;     xor rdi, rdi            ; exit code 0
;     syscall
;
; .no_args:
;     ; Afficher un message d'erreur
;     mov rax, 1              ; syscall: sys_write
;     mov rdi, 1              ; file descriptor: stdout
;     mov rsi, no_args_msg    ; buffer to write
;     mov rdx, 23          ; number of bytes
;     syscall
;
;     ; Sortir proprement
;     mov rax, 60             ; syscall: sys_exit
;     xor rdi, rdi            ; exit code 0
;     syscall
;
; x86_64 linux nasm

section .data
rootFileName: db "../bsq_map/map_default/map_100_100", 0

section .text
  extern get_size_file
global _start

_start:
  
  mov rdi, rootFileName
  mov rax, 10140
  call get_size_file
  ; test successful
  cmp rax, 10140
  jne fail

  mov rax, 60
  mov rdi, 0
  syscall

  ; test failed
  fail:
    mov rax, 60
    mov rdi, 1
    syscall
