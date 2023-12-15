section .data

    topLeftDot dw 39*window_width+15
    topRightDot dw topLeftDot+(320*8)
    botleftDot dw 0
    botRightDot dw 0
    zero dw 00
    index dw 0


section .text

; check_candies_top:
;     mov ax, Dots_pos

; ; Change the value of the dots in the array Dots_pos
; ; only when it's ranky that touching them.

; ; Redraw the dots every time the bugs are moving

; ; get color of the middle pixel of the direction
; ; if white -> erease the dot in the next move  
; ; else return
check_candies_top:
    mov cx, [xPos]
    ; sub cx, 313
    call getColor
    ;cmp bx, 2           ; if bx = 2; there is a dot
    ; je update_top_dots

    ;je erase_candy
    ret


; ; Here because there is a dot in Ranky direct path

; ; create a copy of the Dots_pos array -> dotsArray for the moment

; ; find the index on the array Dots_pos
; ; change the value of this index to ?? Or erase it ??
erase_candy:
    ; mov bl, [Dots_pos + index]      ; index 0
    int3
    .topLeft:
        mov al, [Dots_pos]
        xor bx, bx
        mov bx, index
        mov bl, [Dots_pos + bx]  ; index 0 at the start
        cmp bl, [topLeftDot]
        jne .increTL
        mov word [Dots_pos + bx], 0
        ret

    .increTL:
        mov dx, index
        add dx, 2
        mov [index], dx
        jmp .topLeft

; update_top_dots:
;     xor bx, bx
;     mov bx, [topLeftDot]
;     sub bx, 313
;     add bx, [xPos]
;     mov [topLeftDot], bx

; exit:
;     mov ah, 4ch
;             xor al, al
;             int 21h