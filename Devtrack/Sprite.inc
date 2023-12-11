org 100h

section .data

xPos dw window_width*80+(window_width-16)/2       ; 25 752
yPos dw 0
xVelocity dw 1

isFrenzy db 0

oldPos dw 0

; Teleporter positions
telepRight dw window_width*105-16
telepLeft dw window_width*104
telepUp dw window_width*24+(window_width-16)/2
telepBottom dw window_width*185+(window_width-16)/2

truem db '1',13,10,'$'   ; true and false message.
falsem db '0',13,10,'$'

killStreak db 1

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

moveup:
    mov word [xVelocity], -320
	mov ax, [xPos]
    mov [oldPos], ax
	add ax, [xVelocity]
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
        je .remove_candy
        cmp bx, 4
        je dec_life
        cmp bx, 5
        je .eat_ghost

        jmp .telep


    .eat_ghost:
        push bx
       mov bx, [killStreak]
        mov ax,200
        mul bx
        mov bx,ax
        call add_score
        inc byte [killStreak]
        pop bx
        jmp .moving

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
        call changeloopup
        call draw_sprite
        ret

    .end:
        mov bx, [oldPos]
        mov [xPos], bx
        mov di, [xPos]
        call changeloopup
        call draw_sprite
        ret

movedown:
    mov word [xVelocity], 320
    mov ax, [xPos]
    mov [oldPos], ax
	add ax, [xVelocity]
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
        je .remove_candy
        cmp bx, 4
        je dec_life
        cmp bx, 5
        je .eat_ghost

        jmp .telep

    .eat_ghost:
        push bx
       mov bx, [killStreak]
        mov ax,200
        mul bx
        mov bx,ax
        call add_score
        inc byte [killStreak]
        pop bx
        jmp .moving

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
        call changeloopdown
        call draw_sprite
        ret

    .end:
        mov bx, [oldPos]
        mov [xPos], bx
        mov di, [xPos]
        call changeloopdown
        call draw_sprite
        ret

moveleft:
    mov word [xVelocity], -1
    mov ax, [xPos]
    mov [oldPos], ax
	add ax, [xVelocity]
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
        cmp bx, 4
        je dec_life
        cmp bx, 5
        je .eat_ghost
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

    .eat_ghost:
        push bx
        mov bx, [killStreak]
        mov ax,200
        mul bx
        mov bx,ax
        call add_score
        inc byte [killStreak]
        pop bx
        jmp .moving

    .eat_check_mark:
        call toggle_frenzy

        
        mov bx, 50
        call add_score
        mov bx, [oldPos]
        sub bx, 8
        mov si, clean
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
        call changeloopleft
        call draw_sprite
        ret

    .end:
        mov bx, [oldPos]
        mov [xPos], bx
        mov di, [xPos]
        call changeloopleft
        call draw_sprite
        ret

moveright:
    mov word [xVelocity], 1
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
        cmp bx, 4
        je dec_life
        cmp bx, 5
        je .eat_ghost
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

        mov bx, 50
        call add_score

        mov bx, [oldPos]
        add bx, 8
        mov si, clean
        mov di, bx
        call draw_sprite
        
        jmp .moving

    .eat_ghost:
        push bx
       mov bx, [killStreak]
        mov ax,200
        mul bx
        mov bx,ax
        call add_score
        inc  byte [killStreak]
        pop bx
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
        call changeloopright
        call draw_sprite
        ret

    .end:
        mov bx, [oldPos]
        mov [xPos], bx
        mov di, [xPos]
        call changeloopright
        call draw_sprite
        ret

changeloopright:
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

changeloopdown:
	cmp si, down_opened
	jne .pacmanclosed
	cmp si, down_closed
	jne .pacmanopend

    .pacmanopend:
        mov si, down_closed
        ret

    .pacmanclosed:
        mov si, down_opened
        ret

changeloopleft:
	cmp si, left_opened
	jne .pacmanclosed
	cmp si, left_closed
	jne .pacmanopend

	.pacmanopend:
		mov si, left_closed
		ret

	.pacmanclosed:
		mov si, left_opened
		ret


changeloopup:
	cmp si, up_opened
	jne .pacmanclosed
	cmp si, up_closed
	jne .pacmanopend

	.pacmanopend:
		mov si, up_closed
		ret

	.pacmanclosed:
		mov si, up_opened
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
        mov byte [killStreak],1
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

dec_life:
    dec byte [life_count]
    mov si, clean
    mov di, [xPos]
    call draw_sprite
    mov word [xPos], window_width*80+(window_width-16)/2
    mov si, right_closed
    mov di, [xPos]
    call draw_sprite
    jmp game_loop

