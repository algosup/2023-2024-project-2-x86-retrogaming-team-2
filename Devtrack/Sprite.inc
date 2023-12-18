org 100h

section .data

xPos dw window_width*80+(window_width-16)/2       ; 25 752
yPos dw 0
xVelocity dw 1

isFrenzy db 0, 0, 0, 0

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

getCollision:

    cmp word [xVelocity], -320
    je .check_up_col_left

    cmp word [xVelocity], 320
    je .check_down_col_left

    cmp word [xVelocity], -1
    je .check_left_col_top

    cmp word [xVelocity], 1
    je .check_right_col_top
    jmp .end

        ; Collisions Up
        .check_up_col_left:
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

        .check_up_col_right:
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

        .check_up_col_middle:
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
            jmp .end


        ; Collisions Down
        .check_down_col_left:
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
    
        .check_down_col_right:
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

        .check_down_col_middle:
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
            jmp .end


        ; Collisions Left
        .check_left_col_top:
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
    
        .check_left_col_down:
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

        .check_left_col_middle:
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
            jmp .end


        ; Collisions Right
        .check_right_col_top:
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
        
        .check_right_col_down:
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

        .check_right_col_middle:
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
            jmp .end

    .end:
        ret


move_ranky:
	mov ax, [xPos]
    mov [oldPos], ax
	add ax, [xVelocity]
    mov [xPos], ax

        call getCollision

        cmp bx, 0
        je .end
        cmp bx, 2
        je .remove_candy
        cmp bx, 3
        je .eat_check_mark
        cmp bx, 4
        je .kill_ranky
        cmp bx, 5
        je .eat_ghost1
        cmp bx, 7
        je .eat_ghost2
        cmp bx, 8
        je .eat_ghost3
        cmp bx, 9
        je .eat_ghost4

        jmp .check_tp


    .eat_ghost1:
        push bx
        call move_bug1.eaten
        pop bx
        jmp .moving

    .eat_ghost2:
        push bx
        call move_bug2.eaten
        pop bx
        jmp .moving

    .eat_ghost3:
        push bx
        call move_bug3.eaten
        pop bx
        jmp .moving

    .eat_ghost4:
        push bx
        call move_bug4.eaten
        pop bx
        jmp .moving

    .remove_candy:
        ; Remove candy
        call erase_candy
        call EraseCandy
        dec word [candies_remain]
        push bx
        mov bx, 10
        call add_score
        pop bx
        jmp .moving

    .kill_ranky:
        call dec_life
        jmp .moving
    
    .eat_check_mark:
        call toggle_frenzy.enable_frenzy

        
        mov bx, 50
        call add_score
        mov bx, [oldPos]

        cmp word [xVelocity], 1
        je .right
            sub bx, 8
            jmp .skip_check_mark
        .right:
            add bx, 8
        .skip_check_mark:
            mov si, clean
            mov di, bx
            call draw_sprite
            jmp .moving

    .check_tp:
        call check_teleporter
        jmp .moving

    .moving:
        mov di, [xPos]
        call change_sprite
        call draw_sprite
        ret

    .end:
        mov bx, [oldPos]
        mov [xPos], bx
        mov di, [xPos]
        call change_sprite
        call draw_sprite
        ret

check_teleporter:

    cmp word [xVelocity], -320
    je .tp_up
    cmp word [xVelocity], 320
    je .tp_down
    cmp word [xVelocity], -1
    je .tp_left
    cmp word [xVelocity], 1
    je .tp_right

    .tp_up:
        mov bx, [xPos]
        cmp bx, [telepUp]        
        jne .end
        mov si, clean
        mov di, [xPos]
        call draw_sprite
        mov bx, [telepBottom]
        sub bx, (window_width * 3)
        mov [xPos], bx
        mov si, up_closed
        jmp .end

    .tp_down:
        mov bx, [xPos]
        cmp bx, [telepBottom]        
        jne .end
        mov si, clean
        mov di, [xPos]
        call draw_sprite
        mov bx, [telepUp]
        add bx, (window_width * 3)
        mov [xPos], bx
        mov si, down_closed
        jmp .end

     .tp_left:
        mov bx, [xPos]
        cmp bx, [telepLeft]        
        jne .end
        mov si, clean
        mov di, [xPos]
        call draw_sprite
        mov bx, [telepRight]
        sub bx, 3
        mov [xPos], bx
        mov si, left_closed
        jmp .end

    .tp_right:
        mov bx, [xPos]
        cmp bx, [telepRight]        
        jne .end
        mov si, clean
        mov di, [xPos]
        call draw_sprite
        mov bx, [telepLeft]
        add bx, 3
        mov [xPos], bx
        mov si, right_closed
        jmp .end

    .end:
        ret


change_sprite:

    cmp word [xVelocity], 320
    je .changeloopdown
    cmp word [xVelocity], -320
    je .changeloopup
    cmp word [xVelocity], 1
    je .changeloopright
    cmp word [xVelocity], -1
    je .changeloopleft
    jmp .end

    .changeloopright:
        cmp si, right_opened
        jne .pacman_right_closed
        cmp si, right_closed
        jne .pacman_right_opened

    .pacman_right_opened:
        mov si, right_closed
        ret

    .pacman_right_closed:
        mov si, right_opened
        ret

    .changeloopdown:
        cmp si, down_opened
        jne .pacman_down_closed
        cmp si, down_closed
        jne .pacman_down_opened

        .pacman_down_opened:
            mov si, down_closed
            ret

        .pacman_down_closed:
            mov si, down_opened
            ret

    .changeloopleft:
        cmp si, left_opened
        jne .pacman_left_closed
        cmp si, left_closed
        jne .pacman_left_opened

        .pacman_left_opened:
            mov si, left_closed
            ret

        .pacman_left_closed:
            mov si, left_opened
            ret


    .changeloopup:
        cmp si, up_opened
        jne .pacman_up_closed
        cmp si, up_closed
        jne .pacman_up_opened

        .pacman_up_opened:
            mov si, up_closed
            ret

        .pacman_up_closed:
            mov si, up_opened
            ret

    .end:
        ret
toggle_frenzy:
    .enable_frenzy:

        mov si, isFrenzy       ; Load the address into si
        xor bx, bx

        .activation_loop:
            mov byte [si + bx], 1       ; Store the value at the current address
            inc bx 

            cmp bx, 4
            jl .activation_loop

            mov byte [killStreak], 1
            jmp .end

    .disable_frenzy:
        mov si, isFrenzy       ; Load the address into si
        xor bx, bx
        .desactivation_loop:
            mov byte [si + bx], 0       ; Store the value at the current address
            inc bx

            cmp bx, 4
            jl .desactivation_loop
            mov byte [killStreak], 1
            jmp .end

    .end:
        ret


EraseCandy:
    // Velocity determine on which side is the candy
    cmp word [xVelocity], 320
    je .EraseCandyBottom
    cmp word [xVelocity], -320
    je .EraseCandyTop
    cmp word [xVelocity], 1
    je .EraseCandyRight
    cmp word [xVelocity], -1
    je .EraseCandyLeft
    jmp .end

    .EraseCandyRight:
        mov al,0x00
        mov di, [xPos]
        add di,15+320*7

        jmp .EraseCandy
        
    .EraseCandyLeft:
        mov di, [xPos]
        add di, 320*7-1


        jmp .EraseCandy
    .EraseCandyTop:
        mov di, [xPos]
        sub di,313


        jmp .EraseCandy
    .EraseCandyBottom:
        mov di, [xPos]
        add di,7+320*15

        jmp .EraseCandy

    .EraseCandy:
        //DI is the dot on the top-left, position present in the array in item 
        mov al,0x00
        mov [es:di],al
        add di,1
        mov [es:di],al
        add di,320
        mov [es:di],al
        dec di
        mov [es:di],al

    .end:
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
    ret

