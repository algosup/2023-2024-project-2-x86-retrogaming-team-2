org 100h

section .data

xPos dw 0
xVelocity dw 1

desired_x_coordinate equ 1
desired_y_coordinate equ 1


section .text

; draw sprite in 16x16 pixels
draw_sprite:
       mov ax, 0xA000
       mov es, ax
       mov dx, 16
       mov di, desired_x_coordinate + window_width * desired_y_coordinate
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

move_player:
       ;TO check collision, just check color of the next tile and to a jmp if it's not the wall color

       mov si, sprite
       mov di, [xPos]
       call draw_sprite
       mov cx, 20000 
       waitloop:
       loop waitloop

       mov bx, [xPos]
       add bx, [xVelocity]
       mov word [xPos], bx

       cmp word [xPos], window_width-16
       je change_velocity
       cmp word [xPos], 0
       je change_velocity
       jmp move_player

change_velocity:
       neg word [xVelocity]
       jmp move_player


moveup:
    mov ah, 9
    mov dx, charValue
    int 21h
    jmp _start.awaitKey
movedown:
    mov ah, 9
    mov dx, charValue
    int 21h
    jmp _start.awaitKey
moveleft:
    mov ah, 9
    mov dx, charValue
    int 21h
    jmp _start.awaitKey
moveright:
    mov ah, 9
    mov dx, charValue
    int 21h
    jmp _start.awaitKey
