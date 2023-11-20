cpu 8086
org 100h

section .data

    ; add variables for all keys
    charValue db 'X$'

section .text
    global _start

_start:
    xor sp, sp        ; Reset Stack Pointer
    ; Initialize graphics mode
    mov ah, 00h ; set video mode requirement
    mov al, 13h ; set video mode option o 320 x 200 256 colors
    int 10h

    ; Return to text mode and exit
    mov ax, 0xA000
    int 0x10       ; Set destination index to 0 (start of video memory)

    ;call move_player

    call drawMaze
    ; mov si, sprite
    ; mov di, 0
    ; call draw_sprite

    ; mov si, blinky
    ; mov di, 32
    ; call draw_sprite

    ; mov si, inky
    ; mov di, 48
    ; call draw_sprite

    ; mov si, clyde
    ; mov di, 64
    ; call draw_sprite

    ; mov si, pinky
    ; mov di, 80
    ; call draw_sprite

    ; mov si, wall
    ; mov di, 96
    ; call draw_sprite

    .spawn_entities:
        ; call move_player

    .awaitKey:
        call keyHandler
        mov [charValue], al
        cmp al ,27  ; Escape ??
        je .exit
        cmp al ,'z'
        je .moveUp
        cmp al ,'s'
        je .moveDn
        cmp al ,'d'
        je .moveRg
        cmp al ,'q'
        je .moveLf
        jmp .awaitKey

    .moveUp:
        ;move up
        call moveup
    .moveDn:
        ;move down
        call movedown
    .moveRg:
        ;move right
        call moveright
    .moveLf:
        ;move left
        call moveleft
    .exit:
        mov ah, 4ch
        xor al, al
        int 21h

keyHandler:
    xor ax, ax
    int 16h
    ret

%include "map.inc"
%include "sprite.inc"