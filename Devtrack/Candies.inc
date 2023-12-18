section .data

    topLeftDot dw 39*window_width+15
    topRightDot dw topLeftDot+288
    botleftDot dw 0
    botRightDot dw 0
    zero dw 00
    index dw 60


section .text


; Here because there is a dot in Ranky direct path

; create a copy of the Dots_pos array -> dotsArray for the moment

; find the index on the array Dots_pos
; change the value of this index to ?? Or erase it ??
erase_candy:
    .topLeft:

        mov si, Dots_pos
        mov bx, 0

        .loopTL:
            
            add si, [bx]
            add bx, 2

            cmp word [si], 60000
            jae .end
            mov dx, [topRightDot]
            cmp word [si], dx
            jne .loopTL
            mov word [si], 0

            .end:
            ret