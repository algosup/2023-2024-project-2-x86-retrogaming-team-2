move_ranky:
        call getCollision

        cmp bx, 0
        je .stop
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
        mov word [current_bug], 0
        call move_bug.eaten
        pop bx
        jmp .moving

    .eat_ghost2:
        push bx
        mov word [current_bug], 2
        call move_bug.eaten
        pop bx
        jmp .moving

    .eat_ghost3:
        push bx
        mov word [current_bug], 4
        call move_bug.eaten
        pop bx
        jmp .moving

    .eat_ghost4:
        push bx
        mov word [current_bug], 6
        call move_bug.eaten
        pop bx
        jmp .moving

    .remove_candy:
        call EraseCandy
        jmp .moving
        

    .kill_ranky:
        call dec_life
        jmp .moving
    
    .eat_check_mark:
        call erase_check_mark
        jmp .moving

    .check_tp:
        call check_teleporter
        jmp .moving

    .stop:
        mov word [xVelocity], 0
        jmp .moving

    .moving:
        mov ax, [xPos]
        add ax, [xVelocity]
        mov [xPos], ax
        mov di, [xPos]
        call change_sprite
        call draw_sprite
        jmp .end

    .end:
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