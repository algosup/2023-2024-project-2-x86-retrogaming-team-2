org 100h

section .data

; Bugs Positions

bug1_default_Pos equ window_width*136+(window_width-16)/2  ; Outside of the house
bug2_default_Pos equ window_width*108+(window_width-16)/2  ; Center in the house
bug3_default_Pos equ window_width*108+((window_width-16)/2 - 24)     ; Left in the house
bug4_default_Pos equ window_width*108+((window_width-16)/2 + 24)     ; Right in the house

bug_XPos dw 0

bugs_velocity dw 1, 320, -320, 320
;1 to go right, -1 to go left, -320 to go up, and 320 to go down

bugs_area dw bug2_default_Pos

defaults_bugs_pos dw bug1_default_Pos, bug2_default_Pos, bug3_default_Pos, bug4_default_Pos
bug_pos dw bug1_default_Pos, bug2_default_Pos, bug3_default_Pos, bug4_default_Pos

current_bug dw 0
current_bug_pos dw 0


section .text

;bug 1 starts to go on the right
;if he goes to right and hits a wall, it goes up
;if he goes to up and hits a wall, it goes left
;if he goes to left and hits a wall, it goes down
;if he goes to down and hits a wall, it goes right


get_bug_collision:
    xor si, si
    mov si, bugs_velocity
    add si, [current_bug]
    cmp word [si], 1
    je .check_right_col_top
    cmp word [si], -320
    je .check_up_col_left
    cmp word [si], -1
    je .check_left_col_top
    cmp word [si], 320
    je .check_down_col_left
    jmp .end

    ; Right Collisions
        .check_right_col_top:
            mov ax, [current_bug_pos]
            mov cx, window_width
            xor dx, dx
            div cx
            mov [bug_XPos], dx
            add word [bug_XPos], 16
            mov cx, [bug_XPos]       
            mov dx, ax      
            call getColor 
            
        .check_right_col_bottom:
            mov ax, [current_bug_pos]
            mov cx, window_width
            xor dx, dx
            div cx
            mov [bug_XPos],dx
            add ax, 15
            add word [bug_XPos], 16
            mov cx, [bug_XPos]         
            mov dx, ax      
            call getColor 

            jmp .end

    ; Left Collisions
        .check_left_col_top:
            mov ax, [current_bug_pos]
            mov cx, window_width
            xor dx, dx
            div cx
            mov [bug_XPos], dx
            sub word [bug_XPos], 1
            mov cx, [bug_XPos]       
            mov dx, ax      
            call getColor 
    
        .check_left_col_bottom:
            mov ax, [current_bug_pos]
            mov cx, window_width
            xor dx, dx
            div cx
            mov [bug_XPos],dx
            add ax, 15
            sub word [bug_XPos], 1
            mov cx, [bug_XPos]         
            mov dx, ax
            call getColor 

            jmp .end

    ; Up Collisions
        .check_up_col_left:
            mov ax, [current_bug_pos]
            mov cx, window_width
            xor dx, dx
            div cx
            mov [bug_XPos], dx
            add ax, -1
            add word [bug_XPos], 0
            mov cx, [bug_XPos]       
            mov dx, ax      
            call getColor 
        
        .check_up_col_right:
            mov ax, [current_bug_pos]
            mov cx, window_width
            xor dx, dx
            div cx
            mov [bug_XPos],dx
            add ax, -1
            add word [bug_XPos], 15
            mov cx, [bug_XPos]
            mov dx, ax      
            call getColor 

            jmp .end
        
        .check_down_col_left:
            mov ax, [current_bug_pos]
            mov cx, window_width
            xor dx, dx
            div cx
            mov [bug_XPos], dx
            add ax, 16
            add word [bug_XPos], 0
            mov cx, [bug_XPos]       
            mov dx, ax      
            call getColor 
            
        .check_down_col_right:
            mov ax, [current_bug_pos]
            mov cx, window_width
            xor dx, dx
            div cx
            mov [bug_XPos],dx
            add ax, 16
            add word [bug_XPos], 15
            mov cx, [bug_XPos]         
            mov dx, ax      
            call getColor 

        .end:
            ret

get_bug_sprite:
    cmp word [current_bug], 0
    jne .goto_bug2
        mov si, bug1_sprite
        
        push si
            xor si, si
            mov si, isFrenzy
            add si, [current_bug]
            mov bx, [si]
        pop si
        cmp word bx, 1
        jne .end
        mov si, bug1_sprite_frenzy
        jmp .end
    .goto_bug2:
    cmp word [current_bug], 2
    jne .goto_bug3
        mov si, bug2_sprite

        push si
            xor si, si
            mov si, isFrenzy
            add si, [current_bug]
            mov bx, [si]
        pop si
        cmp word bx, 1
        jne .end
        mov si, bug2_sprite_frenzy
        jmp .end
    .goto_bug3:
    cmp word [current_bug], 4
    jne .goto_bug4
        mov si, bug3_sprite

        push si
            xor si, si
            mov si, isFrenzy
            add si, [current_bug]
            mov bx, [si]
        pop si
        cmp word bx, 1
        jne .end
        mov si, bug3_sprite_frenzy
        jmp .end
    .goto_bug4:
    cmp word [current_bug], 6
    jne .end
        mov si, bug4_sprite

        push si
            xor si, si
            mov si, isFrenzy
            add si, [current_bug]
            mov bx, [si]
        pop si
        cmp word bx, 1
        jne .end
        mov si, bug4_sprite_frenzy
        jmp .end

    .end:
        ret

move_bug:
    xor bx, bx
    mov si, 0
    mov si, bugs_velocity
    push si
    mov si, bug_pos
    add si, [current_bug]
    
    mov bx, [si]
    mov word [current_bug_pos], bx
    pop si

    call get_bug_collision

    cmp bx, 0
    je .collide
    
    cmp bx, 6
    je .kill_ranky


    jmp .moving

    .kill_ranky:
        xor si, si
        mov si, isFrenzy
        add si, [current_bug]
        cmp word [si], 1
        je .skip_dec_life
            call dec_life
        .skip_dec_life:
            jmp .moving

    .moving:
        xor bx, bx
        mov si, 0
        mov si, bugs_velocity
        add si, [current_bug]
        mov bx, [si]
        
        add bx, [current_bug_pos]

        mov [current_bug_pos], bx

        mov si, bug_pos
        add si, [current_bug]
        mov [si], bx


        mov di, [current_bug_pos]

        call get_bug_sprite
        call draw_sprite
        ret

    .collide:
        call change_bug_direction
        ret

    .eaten:
        mov si, bug_pos
        add si, [current_bug]
        mov bx, [si]
        mov word [current_bug_pos], bx

        mov cx, [killStreak]
        mov ax, 200
        mul cx

        mov bx, ax
        call add_score
        inc word [killStreak]

        ; disable frenzy mode
        mov si, 0
        mov si, isFrenzy           ; Load the address into si
        add si, [current_bug]
        mov word [si], 0       ; Store the value at the current address

        ; remove the bug sprite
        mov si, clean
        mov di, [current_bug_pos]
        call draw_sprite

        ; change bug velocity, to force him to go out of the house
        mov si, bugs_velocity
        add si, [current_bug]
        mov word [si], 320

        ; teleport the bug into the house
        mov si, bug_pos
        add si, [current_bug]
        mov word [si], bugs_area - 5

        ret

change_bug_direction:
    xor bx, bx
    mov si, 0
    mov si, bugs_velocity
    add si, [current_bug]
    cmp word [si], 1; if bug is going on the right
    je .changeDirectionUp;go UP if possible
    cmp word [si], -320; if bug is going up
    je .changeDirectionLeft;go LEFT if possible
    cmp word [si], -1; if bug is going on the left
    je .changeDirectionDown;go DOWN if possible
    cmp word [si], 320; if bug is going down
    je .changeDirectionRight;go RIGHT if possible
    ret
    
    .changeDirectionUp:;change the bug's direction to go up
        mov word [si], -320; change velocity to go up
        ret
    
    .changeDirectionLeft:;change the bug's direction to go left
        mov word [si], -1; change velocity to go left
        ret

    .changeDirectionDown:;change the bug's direction to go down
        mov word [si], 320; change velocity to go down
        ret
    
    .changeDirectionRight:;change the bug's direction to go right
        mov word [si], 1; change velocity to go right
        ret