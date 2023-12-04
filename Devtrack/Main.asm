cpu 8086
org 100h

section .data
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

    .spawn_entities:
        call draw_score
        call draw_highscore
        call draw_life

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
        call draw_sprite

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
        cmp ah , [key_up2]
        je .moveUp
        cmp ah , [key_down2]
        je .moveDn
        cmp ah , [key_right2]
        je .moveRg
        cmp ah , [key_left2]
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

; game_loop:
;     mov cx, 20000 
;     .waitloop:
;     loop .waitloop
;     call move_bug1
;     jmp _start.awaitKey

; includes
%include "Sprites_List.inc"
%include "Animations/Ranky_Anims.inc"
%include "Animations/Bugs_Anims.inc"
%include "Map.inc"
%include "Sprite.inc"
%include "Scoreboard.inc"
%include "Collision.inc"