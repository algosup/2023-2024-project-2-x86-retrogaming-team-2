cpu 8086
org 100h


section .data
    old_time equ 0
    
section .text
    global _start
_start:
    ; Initialize graphics mode
    mov ah, 00h ; set video mode requirement
    mov al, 13h ; set video mode option 320 x 200 256 colors
    int 10h

    call reset_buffer

    mov di, 0
    ; Return to text mode and exit
    mov ax, 0xA000
    call drawMaze

    .spawn_dots:
        call DrawCheckMark
        call drawDot

    .spawn_entities:
        mov word [bug_pos + 0], bug1_default_Pos
        mov word [bug_pos + 2], bug2_default_Pos
        mov word [bug_pos + 4], bug3_default_Pos
        mov word [bug_pos + 6], bug4_default_Pos

        mov di, [xPos]
        mov si, right_closed
        mov si, right_closed
        call draw_sprite

        jmp game_loop

game_loop:
    mov ah, 00h
    int 1Ah         ; Get System Time (CX:DX = number of clock ticks since midnight | AL = midnight counter, advanced each time midnight passes.)
    cmp dx, [old_time]
    je game_loop
    mov [old_time], dx

    call drawDot
    call DrawCheckMark
    mov di, 100
    mov si, clean
    call draw_tile
    
    cmp word [isDead], 1
    je .skip_drawing

    mov word [current_bug], 0
    call move_bug
    mov word [current_bug], 2
    call move_bug
    mov word [current_bug], 4
    call move_bug
    mov word [current_bug], 6
    call move_bug

    .skip_drawing:

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