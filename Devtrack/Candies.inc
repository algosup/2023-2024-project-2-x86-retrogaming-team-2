section .data

    topLeftDot dw 39*window_width+15
    topRightDot dw topLeftDot+288
    botleftDot dw 0
    botRightDot dw 0
    zero dw 00
    index dw 0


section .text


; Here because there is a dot in Ranky direct path

; create a copy of the Dots_pos array -> dotsArray for the moment

; find the index on the array Dots_pos
; change the value of this index to ?? Or erase it ??
erase_candy:
    ; mov bl, [Dots_pos + index]      ; index 0
    .topLeft:

        mov si, Dots_pos

        .loopTL:
            
            add si, [index]

            mov dx, [index]
            add dx, 2
            mov word [index], dx
            mov bx, [topLeftDot]
            cmp word [si], bx
            jne .loopTL
            mov word [si], 0
            ret

    ; .increTL:
    ;     mov dx, index
    ;     add dx, 2
    ;     mov [index], dx
    ;     jmp .topLeft

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