section .data

    topLeftDot dw 0
    topRightDot dw 0
    botleftDot dw 0
    botRightDot dw 0
    zero dw 0


section .text

; Change the value of the dots in the array Dots_pos
; only when it's ranky that touching them.

; Redraw the dots every time the bugs are moving

; get color of the middle pixel of the direction
; if white -> erease the dot in the next move  
; else return
check_candies_top:
    mov cx, [xPos]
    sub cx, 313
    call getColor
    cmp bx, 2           ; if bx = 2; there is a dot
    je update_top_dots
    je erase_candy
    ret


; Here because there is a dot in Ranky direct path

; create a copy of the Dots_pos array -> dotsArray for the moment

; find the index on the array Dots_pos
; change the value of this index to ?? Or erase it ??
erase_candy:

    ; mov si, dotsArray
    lea si, [Dots_pos]
    mov ax, cx

    .topLeft:
        cmp si, [topLeftDot]
        jne .increTL
        mov cx, si
        mov al, [si]
        mov al, 0
        mov [si], al
        ; mov [topLeftDot], [si]

    .topRight:
        cmp si, [topRightDot]
        jne .increTR
        mov word [si], 0

    .botLeft:
        cmp si, [topRightDot]
        jne .increBL
        mov word [si], 0

    .botRight:
        cmp si, [topRightDot]
        jne .increBR
        mov word [si], 0

    .increTL:
        ; add si, 2
        inc si
        jmp .topLeft

    .increTR:
        add si, 2
        jmp .topRight

    .increBR:
        add si, 2
        jmp .botRight

    .increBL:
        add si, 2
        jmp .botLeft


update_top_dots:
    mov bx, [topLeftDot]
    sub bx, 313
    add bx, [xPos]
    mov [topLeftDot], bx

    mov bx, [topRightDot]
    sub bx, 312
    add bx, [xPos]
    mov [topRightDot], bx

    mov bx, [botleftDot]
    sub bx, 633
    add bx, [xPos]
    mov [botleftDot], bx

    mov bx, [botRightDot]
    sub bx, 632
    add bx, [xPos]
    mov [botRightDot], bx

    ret

