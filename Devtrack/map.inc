window_width equ 320
window_height equ 200

section .data
    maze:
        dw 0b0000_0000_0000_0000
        dw 0b0111_1111_1111_1110
        dw 0b0100_0010_0000_0010
        dw 0b0100_0010_0000_0010
        dw 0b0111_1111_1111_1111
        dw 0b0100_0010_0100_0000
        dw 0b0111_1110_0111_1110
        dw 0b0000_0010_0000_0010
        dw 0b0000_0010_0111_1111
        dw 0b0000_0011_1100_0000
        dw 0b0000_0010_0100_0000
        dw 0b0000_0010_0111_1111
        dw 0b0000_0010_0100_0000
        dw 0b0111_1111_1111_1110
        dw 0b0100_0010_0000_0010
        dw 0b0111_1011_1111_1111
        dw 0b0000_1010_0100_0000
        dw 0b0111_1110_0111_1110
        dw 0b0100_0000_0000_0010
        dw 0b0111_1111_1111_1111
        dw 0b0000_0000_0000_0000

drawMaze:
    mov di, 320*24    ; set the initalize start of the maze (window_width * offset pixel in Y axis)
    xor bx, bx      ; reset bx      
    .drawingloop:   ; row generation loop
        cmp di, window_width*window_height - 8 ; compare di with the maximum number of pixels minus size of the tile (8) to check if the generation is complete
        jae _start.spawn_entities               ; jump to entity spawn if result of the compare is above or equal

        mov si, wall                            ; copy the sprite of the wall in si
        call draw_tile                          ; call draw_tile function from sprite.inc
    
        sub di, window_width*8                  ; remove the size of the sprite to di to go back at the previous line
        add di, 8                               ; add the size of the add the width of the sprite
        add bx, 8                               ; increament bx by 8
        cmp bx, window_width                    ; campare bx to the window width
        jb .drawingloop                         ; loop drawing loop if the width is not reached
        jmp .drawcol                            ; jump to drawcol if the width is reached

    .drawcol:
        add di, window_width*8      ; add window width multiply by the sprite height
        xor bx, bx                  ; reset bx
        jmp .drawingloop            ; go back in the loop drawingloop