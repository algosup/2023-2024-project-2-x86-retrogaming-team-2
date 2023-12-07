org 100h

section .data

xPos dw window_width*80+(window_width-16)/2                 ; 25 752
yPos dw 0
xVelocity dw 1

oldPos dw 0

; Bugs Positions
bug1_pos dw window_width*136+(window_width-16)/2            ; Outside of the house
bug2_pos dw window_width*108+(window_width-16)/2            ; Center in the house
bug3_pos dw window_width*108+((window_width-16)/2 - 24)     ; Left in the house
bug4_pos dw window_width*108+((window_width-16)/2 + 24)     ; Right in the house

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
    mov [oldPos], ax
	sub ax, window_width
    mov [xPos], ax


    .check_col_left:
        mov ax, [xPos]
        mov cx, window_width
        xor dx, dx
        div cx
        mov [yPos],dx
        sub ax, 0
        mov cx, [yPos]                           
        mov dx, ax                          
        call getColor 

        cmp bx, 0
        je .end
    
    .check_col_right:
        mov ax, [xPos]
        mov cx, window_width
        xor dx, dx
        div cx
        mov [yPos],dx
        sub ax, 0
        add word [yPos], 15
        mov cx, [yPos]                             
        mov dx, ax                          
        call getColor 

        cmp bx, 0
        je .end

    .check_col_middle:
        mov ax, [xPos]
        mov cx, window_width
        xor dx, dx
        div cx
        mov [yPos],dx
        sub ax, 0
        add word [yPos], 8
        mov cx, [yPos]                             
        mov dx, ax                          
        call getColor 

        cmp bx, 0
        je .end
        cmp bx, 2
        jne .moving

    .remove_candy:
        ; Remove candy
        push bx
        mov bx, 10
        call add_score
        pop bx


    .moving:
        mov di, [xPos]
        call changeloop
        call draw_sprite
        ret

    .end:
        mov bx, [oldPos]
        mov [xPos], bx
        mov di, [xPos]
        call changeloop
        call draw_sprite
        ret

movedown:
    mov ax, [xPos]
    mov [oldPos], ax
	add ax, window_width
    mov [xPos], ax

    .check_col_left:
        mov ax, [xPos]
        mov cx, window_width
        xor dx, dx
        div cx
        mov [yPos],dx
        add ax, 15
        mov cx, [yPos]                           
        mov dx, ax                          
        call getColor 

        cmp bx, 0
        je .end
    
    .check_col_right:
        mov ax, [xPos]
        mov cx, window_width
        xor dx, dx
        div cx
        mov [yPos],dx
        add ax, 15
        add word [yPos], 15
        mov cx, [yPos]                             
        mov dx, ax                          
        call getColor 

        cmp bx, 0
        je .end

    .check_col_middle:
        mov ax, [xPos]
        mov cx, window_width
        xor dx, dx
        div cx
        mov [yPos],dx
        add ax, 15
        add word [yPos], 8
        mov cx, [yPos]                             
        mov dx, ax                          
        call getColor 

        cmp bx, 0
        je .end
        cmp bx, 2
        jne .moving

    .remove_candy:
        ; Remove candy
        push bx
        mov bx, 10
        call add_score
        pop bx


    .moving:
        mov di, [xPos]
        call changeloop
        call draw_sprite
        ret

    .end:
        mov bx, [oldPos]
        mov [xPos], bx
        mov di, [xPos]
        call changeloop
        call draw_sprite
        ret

moveleft:
    mov ax, [xPos]
    mov [oldPos], ax
	sub ax, [xVelocity]
    mov [xPos], ax

    .check_col_top:
        mov ax, [xPos]
        mov cx, window_width
        xor dx, dx
        div cx
        mov [yPos],dx
        sub word [yPos], 0
        mov cx, [yPos]                           
        mov dx, ax                          
        call getColor 

        cmp bx, 0
        je .end
    
    .check_col_down:
        mov ax, [xPos]
        mov cx, window_width
        xor dx, dx
        div cx
        mov [yPos],dx
        add ax, 15
        sub word [yPos], 0
        mov cx, [yPos]                             
        mov dx, ax                          
        call getColor 

        cmp bx, 0
        je .end

    .check_col_middle:
        mov ax, [xPos]
        mov cx, window_width
        xor dx, dx
        div cx
        mov [yPos],dx
        add ax, 8
        sub word [yPos], 0
        mov cx, [yPos]                             
        mov dx, ax                          
        call getColor 

        cmp bx, 0
        je .end
        cmp bx, 2
        jne .moving

    .remove_candy:
        ; Remove candy
        push bx
        mov bx, 10
        call add_score
        pop bx


    .moving:
        mov di, [xPos]
        call changeloop
        call draw_sprite
        ret

    .end:
        mov bx, [oldPos]
        mov [xPos], bx
        mov di, [xPos]
        call changeloop
        call draw_sprite
        ret

moveright:
    mov ax, [xPos]
    mov [oldPos], ax
	add ax, [xVelocity]
    mov [xPos], ax

    .check_col_top:
        mov ax, [xPos]
        mov cx, window_width
        xor dx, dx
        div cx
        mov [yPos], dx
        add word [yPos], 15
        mov cx, [yPos]                           
        mov dx, ax                          
        call getColor 

        cmp bx, 0
        je .end
    
    .check_col_down:
        mov ax, [xPos]
        mov cx, window_width
        xor dx, dx
        div cx
        mov [yPos], dx
        add ax, 15
        add word [yPos], 15
        mov cx, [yPos]           
        mov dx, ax                          
        call getColor 

        cmp bx, 0
        je .end

    .check_col_middle:
        mov ax, [xPos]
        mov cx, window_width
        xor dx, dx
        div cx
        mov [yPos], dx
        add ax, 8
        add word [yPos], 15
        mov cx, [yPos]
        mov dx, ax
        call getColor 

        cmp bx, 0
        je .end
        cmp bx, 2
        jne .moving

    .remove_candy:
        ; Remove candy
        push bx
        mov bx, 10
        call add_score
        pop bx


    .moving:
        mov di, [xPos]
        call changeloop
        call draw_sprite
        ret

    .end:
        mov bx, [oldPos]
        mov [xPos], bx
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