
section .data
    buf resb 32           ; Tampon pour stocker la chaîne convertie

section .bss
    num resq 1            ; Espace pour stocker le nombre (en 64 bits)

section .text
    global display_number

display_nbr:
    push rax
    xor rdx, rdx          ; Initialise rdx à 0 pour la division
    mov rcx, 10           ; Base décimale
    mov rsi, buf + 31     ; Pointeur à la fin du tampon

.loop:
    mov rax, [rdi]        ; Charge le nombre depuis num
    test rax, rax
    js .negative          ; Gère les nombres négatifs

    ; Division par 10
    div rcx               ; rax = rax / 10, rdx = rax % 10

    ; Convertit le chiffre en caractère ASCII
    add dl, '0'
    mov byte [rsi], dl    ; Stocke le caractère dans le tampon
    dec rsi               ; Déplace le pointeur vers la gauche

    test rax, rax
    jnz .loop             ; Continue jusqu'à ce que rax soit nul

.done:
    add rsi, 1            ; Ajuste rsi pour pointer vers le début du tampon
    mov rdx, (buf + 31) - rsi  ; Calcul de la longueur de la chaîne
    mov [rsi], byte 0     ; Terminateur de chaîne null
    mov rax, 1            ; sys_write
    mov rdi, 1            ; Descripteur de fichier (stdout)
    mov rsi, buf          ; Adresse du tampon de données
    mov rdx, rax          ; Longueur de la chaîne à écrire (dans rax)
    syscall
    pop rax
    ret

.negative:
    mov byte [rsi], '-'   ; Ajoute le signe négatif
    add rsi, -1           ; Déplace le pointeur vers la gauche pour inclure le signe
    neg rax                ; Met rax en valeur absolue
    jmp .loop

