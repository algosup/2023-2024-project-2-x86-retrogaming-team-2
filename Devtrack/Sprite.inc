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
	call changeboucle
    jmp _start.awaitKey
moveright:
    mov ax, [xPos]
	add ax, [xVelocity] 
	mov [xPos], ax
	mov di, [xPos]
	call changeboucle
    jmp _start.awaitKey

changeboucle:
	cmp si, mouth_opened
	jne pacmanclosed
    cmp si, sprite
	jne pacmanopend

pacmanopend:
    mov si, sprite
	ret

pacmanclosed:
    mov si, mouth_opened
	ret