org 100h

section .data

xPos dw window_width*80+(window_width-16)/2       ; 25 752
yPos dw 0
xVelocity dw 1

isFrenzy dw 0, 0, 0, 0

oldPos dw 0

; Teleporter positions
telepRight dw window_width*105-16
telepLeft dw window_width*104
telepUp dw window_width*24+(window_width-16)/2
telepBottom dw window_width*185+(window_width-16)/2

killStreak dw 1

section .text

; draw sprite in 16x16 pixels
draw_sprite:
    mov ax, 0xA000
    mov es, ax
    mov dx, 16
    .eachLine:
        mov cx, 16
        rep movsb
        add di, window_width-16
        dec dx
        jnz .eachLine
    ret

; draw sprite in 8x8 pixels
draw_tile:
    mov ax, 0xA000
    mov es, ax
    mov dx, 8
    .eachLine:
        mov cx, 8
        rep movsb
        add di, window_width-8
        dec dx
        jnz .eachLine
    ret


draw_letter:
    mov ax, 0xA000
    mov es, ax
    mov dx, 7
    .eachLine:
        mov cx, 7
        rep movsb
        add di, window_width-7
        dec dx
        jnz .eachLine
    ret


draw_gameover:
    mov ax, 0xA000
    mov es, ax
    mov dx, 38
    .eachLine:
        mov cx, 78
        rep movsb
        add di, window_width-78
        dec dx
        jnz .eachLine
    ret