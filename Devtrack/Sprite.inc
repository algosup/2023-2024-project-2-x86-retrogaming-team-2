org 100h

section .data

xPos dw window_width*80+(window_width-16)/2       ; 25 752
yPos dw 0
xVelocity dw 1

isFrenzy db 0

oldPos dw 0

; Bugs Positions
bug1_pos dw window_width*136+(window_width-16)/2  ; Outside of the house
bug2_pos dw window_width*108+(window_width-16)/2  ; Center in the house
bug3_pos dw window_width*108+((window_width-16)/2 - 24)     ; Left in the house
bug4_pos dw window_width*108+((window_width-16)/2 + 24)     ; Right in the house

; Teleporter positions
telepRight dw window_width*105-16
telepLeft dw window_width*104
telepUp dw window_width*24+(window_width-16)/2
telepBottom dw window_width*185+(window_width-16)/2

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


draw_gameover:
    mov ax, 0xA000
    mov es, ax
    mov dx, 38
    .eachLine:
        mov cx, 78
        rep movsb
        add di, window_width-78
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
        jne .telep

    .remove_candy:
        ; Remove candy
        call EraseCandyTop
        dec word [candies_remain]
        push bx
        mov bx, 10
        call add_score
        pop bx

    .telep:
        mov bx, [xPos]
        cmp bx, [telepUp]        
        jne .moving
        mov si, clean
        mov di, [xPos]
        call draw_sprite
        mov bx, [telepBottom]
        sub bx, (window_width * 3)
        mov [xPos], bx
        mov si, up_closed

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
        jne .telep

    .remove_candy:
        ; Remove candy
        call EraseCandyBottom
        dec word [candies_remain]
        push bx
        mov bx, 10
        call add_score
        pop bx

    .telep:
        mov bx, [xPos]
        cmp bx, [telepBottom]        
        jne .moving
        mov si, clean
        mov di, [xPos]
        call draw_sprite
        mov bx, [telepUp]
        add bx, (window_width * 3)
        mov [xPos], bx
        mov si, down_closed

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
        je .remove_candy
        cmp bx, 3
        je .eat_check_mark
        jmp .telep
        

    .remove_candy:
        ; Remove candy
        call EraseCandyLeft
        dec word [candies_remain]
        push bx
        mov bx, 10
        call add_score
        pop bx
        jmp .moving

    .eat_check_mark:
        call toggle_frenzy

        mov si, clean
        mov bx, [oldPos]
        sub bx, 8
        mov di, bx
        call draw_sprite
        jmp .moving

    .telep:
        mov bx, [xPos]
        cmp bx, [telepLeft]        
        jne .moving
        mov si, clean
        mov di, [xPos]
        call draw_sprite
        mov bx, [telepRight]
        sub bx, 3
        mov [xPos], bx
        mov si, left_closed

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
        je .remove_candy
        cmp bx, 3
        je .eat_check_mark
        jmp .telep

    .remove_candy:
        ; Remove candy
        call EraseCandyRight
        dec word [candies_remain]
        push bx
        mov bx, 10
        call add_score
        pop bx
        jmp .moving

    .eat_check_mark:
        call toggle_frenzy

        mov si, clean
        mov bx, [oldPos]
        add bx, 8
        mov di, bx
        call draw_sprite
        jmp .moving

    .telep:
        mov bx, [xPos]
        cmp bx, [telepRight]        
        jne .moving
        mov si, clean
        mov di, [xPos]
        call draw_sprite
        mov bx, [telepLeft]
        add bx, 3
        mov [xPos], bx
        mov si, right_closed

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
	jne .pacmanclosed
    cmp si, right_closed
	jne .pacmanopend

    .pacmanopend:
        mov si, right_closed
        ret

    .pacmanclosed:
        mov si, right_opened
        ret


toggle_frenzy:
    cmp byte [isFrenzy], 0
    jz .enable_frenzy
    jmp .disable_frenzy

    .enable_frenzy:
        mov byte [isFrenzy], 1
        ret

    .disable_frenzy:
        mov byte [isFrenzy], 0
        ret

EraseCandyRight:
    mov al,0x00
    mov di, [xPos]
    add di,16+320*7
    mov [es:di],al

    add di,320

    mov [es:di],al

    ret
EraseCandyLeft:
    mov al,0x00
    mov di, [xPos]
    dec di
    add di, 320*7
    mov [es:di],al

    add di,320

    mov [es:di],al

    ret
EraseCandyTop:
    mov al,0x00
    mov di, [xPos]
    add di,7
    sub di,320
    mov [es:di],al

    add di,1

    mov [es:di],al

    ret
EraseCandyBottom:
    mov al,0x00
    mov di, [xPos]
    add di,7+320*16
    mov [es:di],al

    add di,1

    mov [es:di],al

    ret