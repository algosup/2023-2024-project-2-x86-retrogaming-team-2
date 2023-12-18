org 100h
section .data

    colorWall dw 0x10                        ; color of the walls
    candyColor dw 0x43
    colorCheckMark dw 0x2F
    colorBug1 dw 0x6F
    colorBug2 dw 0x7E
    colorBug3 dw 0x6C
    colorBug4 dw 0x6A
    colorBug4_1 dw 0x20
    colorRanky dw 0x27


section .text


; Collisions
; 0 - Wall
; 1 - Nothing
; 2 - Candies
; 3 - Check Marks
; 4 - Bug or ranky
; 5 - Frenzy on Bug 1
; 6 - Eat Ranky
; 7 - Frenzy on Bug 2
; 8 - Frenzy on Bug 3
; 9 - Frenzy on Bug 4
getColor:
    mov ah, 0DH                 ; AH = 0Dh for "Read Dot" function
    int 10h

    ; push ax

    ; mov ah, 0CH               ; draw the points
    ; mov al, 0DH
    ; int 10h

    ; pop ax

    mov bx, 0

    ; color of the pixel in al
    cmp al, [colorWall]
    je .end 

    mov bx, 1

    cmp al, [candyColor]
    je .candy

    cmp al, [colorCheckMark]
    je .check_mark

    cmp al, [colorBug1]
    je .bug
    cmp al, [colorBug2]
    je .bug
    cmp al, [colorBug3]
    je .bug
    cmp al, [colorBug4]
    je .bug

    cmp al, [colorRanky]
    je .eat_ranky

    jmp .end
   
    .candy:
        mov bx, 2
        jmp .end

    .check_mark:
        mov bx, 3
        jmp .end
    .bug:
        cmp byte [isFrenzy],1
        je .frenzy_active

        mov bx, 4
        jmp .end

    .eat_ranky:
        mov bx, 6
        jmp .end

    .frenzy_active:
        mov bx, 5

        cmp al, [colorBug1]
        je .end
        
        mov bx, 7
        cmp al, [colorBug2]
        je .end

        mov bx, 8
        cmp al, [colorBug3]
        je .end

        mov bx, 9
        cmp al, [colorBug4]
        je .end

    .end:
        ret

