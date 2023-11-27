org 100h

section .data

xPos dw 0
xVelocity dw 1

; Bugs Positions
bug1_pos dw 32160
bug2_pos dw 0
bug3_pos dw 0
bug4_pos dw 0


section .text

; draw sprite in 16x16 pixels*
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


move_player:
       ;TO check collision, just check color of the next tile and to a jmp if it's not the wall color

    mov si, right_closed
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


spawn_bugs:
    jmp move_bug1
    ret

move_bug1:
    mov di, [bug1_pos]
    mov si, bug1_sprite
    call draw_sprite

    mov cx, 20000 
    .waitloop:
    loop .waitloop

    xor bx, bx
    add bx, 1
    add bx, [bug1_pos]
    mov [bug1_pos], bx
       
    jmp move_bug1

change_velocity:
    neg word [xVelocity]
    jmp move_player

moveup:
    mov ax, [xPos]
    sub ax, window_width
    mov [xPos], ax
    mov di, [xPos]
    ; call changeboucle
    jmp _start.awaitKey

movedown:
    mov ax, [xPos]
    add ax, window_width
    mov [xPos], ax
    mov di, [xPos]
    ; call changeboucle
    jmp _start.awaitKey

moveleft:
    mov ax, [xPos]
    sub ax, [xVelocity]
    mov [xPos], ax
    mov di, [xPos]
    ; call changeboucle
    jmp _start.awaitKey

moveright:
    mov ax, [xPos]
    add ax, [xVelocity] 
    mov [xPos], ax
    mov di, [xPos]
    ; call changeboucle
    jmp _start.awaitKey

changeboucle:    
    cmp si, right_opened
	je pacmanopend
    cmp si, right_closed
    je pacmanclosed

pacmanopend:
    mov si, right_closed
    ret

pacmanclosed:
    mov si, right_opened
    ret