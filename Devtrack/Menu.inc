menu:
    mov ax, 0600h      ; Function 06h - Scroll Up
    mov bh, 0x00  ; Background color
    mov cx, 0          ; Upper-left corner of the area to fill (column 0, row 0)
    mov dx, 184fh
    int 10h

    mov word [candies_remain], 270
    mov byte [life_count], 2
    mov word [xPos], window_width*80+(window_width-16)/2

    .menuloop:
        call keyHandler
        
        cmp al , 13
        je .endloop

        jmp .menuloop

        .endloop:
            jmp _start