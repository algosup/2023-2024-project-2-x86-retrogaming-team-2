org 100h

section .data

xPos dw window_width*80+(window_width-16)/2                 ; 12 952
yPos dw 0
xVelocity dw 1

; Bugs Positions
bug1_pos dw window_width*136+(window_width-16)/2            ; Outside of the house
bug2_pos dw window_width*108+(window_width-16)/2            ; Center in the house
bug3_pos dw window_width*108+((window_width-16)/2 - 24)     ; Left in the house
bug4_pos dw window_width*108+((window_width-16)/2 + 24)     ; Right in the house

truem db '1',13,10,'$'   ; true and false message.
falsem db '0',13,10,'$'


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
    call getColor
	mov ax, [xPos]
	sub ax, window_width
    mov [xPos], ax
	mov di, [xPos]
	call changeloop
    call draw_sprite
    jmp _start.awaitKey

movedown:
    call getColor
    mov ax, [xPos]
    add ax, window_width
    mov [xPos], ax
    mov ax, xPos
    mov cx, window_width
    xor dx, dx
    div cx
    mov [yPos], dl
	mov di, [xPos]
	call changeloop
    call draw_sprite
    jmp _start.awaitKey

moveleft:
    call getColor
    mov ax, [xPos]
	sub ax, [xVelocity]
	mov [xPos], ax
	mov di, [xPos]
	call changeloop
    call draw_sprite
    jmp _start.awaitKey

moveright:
    
    mov ax, [xPos]
	add ax, [xVelocity] 
	mov [xPos], ax
	mov di, [xPos]
	call changeloop
    call draw_sprite
    call getColor
    jmp _start.awaitKey

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