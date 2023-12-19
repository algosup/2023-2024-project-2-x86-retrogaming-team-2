section .data

    topLeftDot dw 39*window_width+15
    topRightDot dw 12783;topLeftDot+288
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

        mov si, Dots_pos
        mov bx, 0

        .loopTL:
            xor dx, dx
            add si, bx
      
            cmp word [si], 60000
            jae .end

            mov bx, 2
            mov dx, di
            sub dx, [xVelocity]

            cmp dx, 12935
            je .deleteDot

            cmp dx, 12614
            je .deleteDot

            cmp word [si], dx
            jne .loopTL
            jmp .deleteDot

            .deleteDot:
                mov word [si], 0

            .end:
            ret