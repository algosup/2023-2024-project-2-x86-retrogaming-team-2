org 100h

section .data

xPos dw window_width*80+(window_width-16)/2
xVelocity dw 1

; Bugs Positions
bug1_pos dw window_width*136+(window_width-16)/2            ; Outside of the house
bug2_pos dw window_width*108+(window_width-16)/2            ; Center in the house
bug3_pos dw window_width*108+((window_width-16)/2 - 24)     ; Left in the house
bug4_pos dw window_width*108+((window_width-16)/2 + 24)     ; Right in the house


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

spawn_bugs:
    jmp move_bug1
    ret

move_bug1:
    mov di, [bug1_pos]
    mov si, bug1_sprite
    call draw_sprite

    xor bx, bx
    add bx, 1
    add bx, [bug1_pos]
    mov [bug1_pos], bx
    ret

moveup:
	mov ax, [xPos]
	sub ax, window_width
    mov [xPos], ax
	mov di, [xPos]
	call changeloop
    call draw_sprite
    ret

movedown:
    mov ax, [xPos]
    add ax, window_width
    mov [xPos], ax
	mov di, [xPos]
	call changeloop
    call draw_sprite
    ret

moveleft:
    mov ax, [xPos]
	sub ax, [xVelocity]
	mov [xPos], ax
	mov di, [xPos]
	call changeloop
    call draw_sprite
    ret

moveright:
    mov ax, [xPos]
	add ax, [xVelocity] 
	mov [xPos], ax
	mov di, [xPos]
	call changeloop
    call draw_sprite
    ret

changeloop:
    cmp si, right_opened
	jne pacmanclosed
    cmp si, right_closed
	jne pacmanopend

pacmanopend:
    mov si, right_closed
	ret

pacmanclosed:
    mov si, right_opened
	ret