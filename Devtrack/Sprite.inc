org 100h

section .data

xPos dw window_width*80+(window_width-16)/2
xVelocity dw 1

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
	call changeloop
    jmp _start.awaitKey
movedown:
    mov ax, [xPos]
    add ax, window_width
    mov [xPos], ax
	mov di, [xPos]
	call changeloop
    jmp _start.awaitKey
moveleft:
    mov ax, [xPos]
	sub ax, [xVelocity]
	mov [xPos], ax
	mov di, [xPos]
	call changeloop
    jmp _start.awaitKey
moveright:
    mov ax, [xPos]
	add ax, [xVelocity] 
	mov [xPos], ax
	mov di, [xPos]
	call changeloop
    jmp _start.awaitKey

changeloop:
    cmp si, rightop
	jne pacmanclosed
    cmp si, right
	jne pacmanopend

pacmanopend:
    mov si, right
	ret

pacmanclosed:
    mov si, rightop
	ret