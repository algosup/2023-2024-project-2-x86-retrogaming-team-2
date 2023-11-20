; Config Area
window_width equ 320
window_height equ 200
game_stats_height equ 24

section .data
    ; maze blueprint (not implemented yet)
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
    mov di, window_width*game_stats_height    ; set the start of the maze
    xor bx, bx   
    .drawingloop:
        cmp di, window_width*window_height - 8  ; check if the generation is complete
        jae _start.spawn_entities               ; go to entity spawn if the maze generation is complete

        mov si, wall                            ; set the sprite of a wall
        call draw_tile                          ; call draw_tile function from sprite.inc
    
        sub di, window_width*8                  ; go back at the previous line after drawing a tile
        add di, 8                               ; add the width of a tile
        add bx, 8                           
        cmp bx, window_width                   
        jb .drawingloop                         ; loop while the window width is not reached
        add di, window_width*7                  ; go to the next tile row
        xor bx, bx                             
        jmp .drawingloop                        ; repeat while the generation is not complete