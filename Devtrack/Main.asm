bits 16
org 100h


section .data
    old_time equ 0xf9fe+0x06

    ; KeyBind
    key_up db 'z'
    key_up2 db 48h
    key_down db 's'
    key_down2 db 50h
    key_left db 'q'
    key_left2 db 4BH
    key_right db 'd'
    key_right2 db 4DH
    key_exit db 27
    key_menu db 'p'


    charValue db 'X$'
    charNoKey db 'False$'
    
section .text
    global _start
_start:
    ; Initialize graphics mode
    mov ah, 00h ; set video mode requirement
    mov al, 13h ; set video mode option 320 x 200 256 colors
    int 10h

    mov di, 0
    ; Return to text mode and exit
    mov ax, 0xA000
    call drawMaze

    .spawn_dots:
        call DrawCheckMark
        call drawDot

    .spawn_entities:

        push bx
        mov bx, 10
        call add_score
        pop bx
        call update_score

        mov si, bug1_sprite
        mov di, [bug1_pos]
        call draw_sprite

        mov si, bug2_sprite
        mov di, [bug2_pos]
        call draw_sprite

        mov si, bug3_sprite
        mov di, [bug3_pos]
        call draw_sprite

        mov si, bug4_sprite
        mov di, [bug4_pos]
        call draw_sprite

        mov di, [xPos]

        mov si, right_closed
        mov si, right_closed
        call draw_sprite

        jmp game_loop

keyHandler:
    xor ax, ax
    mov ah, 00h
    int 16h
    ret

game_loop:
    mov ah, 00h
    int 0x1a
    cmp dx, [old_time]
    je game_loop
    mov [old_time], dx

    call keyHandler
    

    .awaitKey:
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
        cmp ah , [key_up2]
        je .moveUp
        cmp ah , [key_down2]
        je .moveDn
        cmp ah , [key_right2]
        je .moveRg
        cmp ah , [key_left2]
        je .moveLf



        jmp .endloop


        .moveUp:
            call moveup
            jmp .endloop
        .moveDn:
            call movedown
            jmp .endloop
        .moveRg:
            call moveright
            jmp .endloop
        .moveLf:
            call moveleft
            jmp .endloop
        .exit:
            mov ah, 4ch
            xor al, al
            int 21h
        .menu:

        .endloop:
            jmp game_loop

; includes
%include "Sprites_List.inc"
%include "Animations/Ranky_Anims.inc"
%include "Animations/Bugs_Anims.inc"
%include "Map.inc"
%include "Sprite.inc"
%include "Scoreboard.inc"
%include "Collision.inc"
%include "Items.inc"