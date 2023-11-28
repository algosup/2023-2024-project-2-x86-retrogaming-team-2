draw_scoreboard:

    inc bx
    mov ah, 0Ch
    mov al, 08h
    mov dx, 23
    mov cx, bx
    int 10h
    
    cmp bx, window_width
    jb draw_scoreboard
    ret