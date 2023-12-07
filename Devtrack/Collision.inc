org 100h

section .data

    colorWall dw 0x10                        ; color of the walls
    candyColor dw 0x43
    colorCheckMark dw 0x2F

section .text

getColor:
    ; mov ah, 0CH               ; draw the points
    ; mov al, 0DH
    ; int 10h

    mov ah, 0DH                 ; AH = 0Dh for "Read Dot" function
    int 10h

    mov bx, 0

    ; color of the pixel in al
    cmp al, [colorWall]
    je .end 

    mov bx, 1

    cmp al, [candyColor]
    je .candy

    cmp al, [colorCheckMark]
    je .check_mark
    jmp .end
   

    .candy:
        mov bx, 2
        jmp .end

    .check_mark:
        mov bx, 3
        jmp .end

    .end:
        ret