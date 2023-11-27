org 100h

section .data

xPos dw 0
xVelocity dw 1

desired_x equ 0
desired_y equ 0


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

move_player:

    mov si, right
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
	mov ax, [xPos]
	sub ax, window_width
    mov [xPos], ax
	mov di, [xPos]
	call changeboucle
    jmp _start.awaitKey
movedown:
    mov ax, [xPos]
    add ax, window_width
    mov [xPos], ax
	mov di, [xPos]
	call changeboucle
    jmp _start.awaitKey
moveleft:
    mov ax, [xPos]
	sub ax, [xVelocity]
	mov [xPos], ax
	mov di, [xPos]
	call changeleft
    jmp _start.awaitKey
moveright:
    mov ax, [xPos]
	add ax, [xVelocity] 
	mov [xPos], ax
	mov di, [xPos]
	call changeboucle
    jmp _start.awaitKey

changeboucle:
	; cmp si, left_opened
	; jne pacmanclosed
    ; cmp si, left_closed
	; jne pacmanopend

    cmp si, rightop
	jne pacmanclosed
    cmp si, right
	jne pacmanopend

pacmanopend:
    ; mov si, left_closed
    mov si, right
	ret

pacmanclosed:
    ; mov si, left_opened
    mov si, rightop
	ret

changeleft:
    ; cmp si, right
    ; je leftrankyop
    ; cmp si, rightop
    ; je leftrankycl
    cmp si, leftopened
	jne leftrankycl
    cmp si, leftclosed
	jne leftrankyop

leftrankyop:
    mov si, leftclosed
	ret

leftrankycl:
    mov si, leftopened
	ret