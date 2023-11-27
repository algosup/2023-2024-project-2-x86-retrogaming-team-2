org 100h

section .data

xPos dw 0
xVelocity dw 1

desired_x equ 0
desired_y equ 0

truem db '1',13,10,'$'   ; true and false message.
falsem db '0',13,10,'$'


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
	call anim_loop
    jmp _start.awaitKey
movedown:
    mov ax, [xPos]
    add ax, window_width
    mov [xPos], ax
	mov di, [xPos]
	call anim_loop
    jmp _start.awaitKey
moveleft:
    mov ax, [xPos]
	sub ax, [xVelocity]
	mov [xPos], ax
	mov di, [xPos]
	call anim_loop
    jmp _start.awaitKey
moveright:
    mov ax, [xPos]
	add ax, [xVelocity] 
	mov [xPos], ax
	mov di, [xPos]
	call anim_loop
    jmp _start.awaitKey

anim_loop:
	cmp si, right_opened    ; compare if the mouth is opened
	je pacmanopened
    cmp si, right_closed    ; compare if the mouth is closed
	je pacmanclosed 

pacmanopened:
    mov si, right_closed    ; close the mouth if it's opened
	ret

pacmanclosed:
    mov si, right_opened ; open the mouth if it's closed
	ret


comp_color:
    push ax
    push bx
    push cx
    push dx
    push di

    mov dx, 8
    mov bx, 8

    mov ax, 0xA000           
    add ax, bx    
    mov di, ax   

    
    mov al, [di]  

    
    cmp al, 0x27
    je .true

    .false:
        mov ah, 9
        mov dx, falsem
        int 21h

        pop di
        pop dx
        pop cx
        pop bx
        pop ax
        ret

    .true:
        mov ah, 9
        mov dx, truem
        int 21h

        pop di
        pop dx
        pop cx
        pop bx
        pop ax
        ret