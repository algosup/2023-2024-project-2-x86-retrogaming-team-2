section .data

    topLeftDot dw 39*window_width+15
    topRightDot dw topLeftDot+288
    botleftDot dw 0
    botRightDot dw 0
    zero dw 00
    index dw 62


section .text


; Here because there is a dot in Ranky direct path

; create a copy of the Dots_pos array -> dotsArray for the moment

; find the index on the array Dots_pos
; change the value of this index to ?? Or erase it ??
erase_candy:
    .topLeft:

        xor si, si
        mov si, Dots_pos
        mov bx, 0

        .loopTL:
            
            add si, [bx]
            add bx, 2

            mov dx, [si]
            mov word [highscore1], dx

            mov word [highscore2], di
      
            cmp word [si], di
            jne .loopTL
            mov word [si], 0

            .end:
            ret