WALL_COLOR: equ 20h

xMaze dw 0

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
    ;mov di,BASE_MAZE

    mov ah, 0Ch                 ;set the configuration to write a pixel
    mov al, WALL_COLOR          ;Choose color to write
    xor bx, bx
    mov cx, 0000h                 ;set the column (X)
    mov dx, 0000h                 ;set the line (Y)

    ; call drawTile

    .exitloop:
        jmp _start.awaitKey

; drawTile:
;     ; while i < height / 16
;     ; draw wall tile
;     ; increase di with tile size
;     ; when di == width - 16
;     ; set di 0
;     ; add 640*16 to di
;     mov di, 0
;     mov si, wall
;     xor bx, bx
;     mov bx, 0
;     .drawingloop
;         call draw_sprite
        
;         jmp
;         cmp bx, 0
;         inc bx
;         jb .drawingloop

;     .
