cpu 8086
org 100h



section .data
    ; KeyBind
    key_up db 'z'
    key_up2 db 'i'
    key_down db 's'
    key_down2 db 'k'
    key_left db 'q'
    key_left2 db 'j'
    key_right db 'd'
    key_right2 db 'l'
    key_exit db 27
    key_menu db 'p'

    charValue db 'X$'

section .text
    global _start
_start:
    ; Initialize graphics mode
    mov ah, 00h ; set video mode requirement
    mov al, 13h ; set video mode option o 320 x 200 256 colors
    int 10h

    ; Return to text mode and exit
    mov ax, 0xA000

    call drawMaze

    .spawn_entities:
        ; call move_player

    .awaitKey:
        call keyHandler
        mov [charValue], al
        cmp al , [key_exit]
        je .exit
        cmp al , [key_menu]
        je .menu
        cmp al , [key_up]
        je .moveUp
        cmp al , [key_down]
        je .moveDn
        cmp al , [key_right]
        je .moveRg
        cmp al , [key_left]
        je .moveLf
        cmp al , [key_up2]
        je .moveUp
        cmp al , [key_down2]
        je .moveDn
        cmp al , [key_right2]
        je .moveRg
        cmp al , [key_left2]
        je .moveLf
        jmp .awaitKey

    .moveUp:
        call moveup
    .moveDn:
        call movedown
    .moveRg:
        call moveright
    .moveLf:
        call moveleft
    .exit:
        mov ah, 4ch
        xor al, al
        int 21h
    .menu:
        jmp _start.awaitKey

keyHandler:
    xor ax, ax
    int 16h
    ret

; includes
%include "Sprites_List.inc"
%include "Map.inc"
%include "Sprite.inc"