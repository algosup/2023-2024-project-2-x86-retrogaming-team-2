cpu 8086
org 100h


section .data
    old_time equ 0xf9fe+0x06


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

game_loop:
    mov ah, 00h
    int 1Ah
    cmp dx, [old_time]
    je game_loop
    mov [old_time], dx

    ; call move_bug1
    call update_score

    call keyboard_handler





    .endloop:
        jmp game_loop


	.end:
		mov ah, 00h
		mov al, 03h
		int 10h
		mov ax, 4C00h
		int 21h





; includes
%include "keyboard.inc"
%include "Sprites_List.inc"
%include "Animations/Ranky_Anims.inc"
%include "Animations/Bugs_Anims.inc"
%include "Map.inc"
%include "Sprite.inc"
%include "Scoreboard.inc"
%include "Collision.inc"
%include "Items.inc"
%include "Bugs.inc"