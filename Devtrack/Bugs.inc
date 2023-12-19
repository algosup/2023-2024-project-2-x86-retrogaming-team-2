org 100h

section .data

; Bugs Positions

bug1_default_Pos equ window_width*136+(window_width-16)/2  ; Outside of the house
bug2_default_Pos equ window_width*108+(window_width-16)/2  ; Center in the house
bug3_default_Pos equ window_width*108+((window_width-16)/2 - 24)     ; Left in the house
bug4_default_Pos equ window_width*108+((window_width-16)/2 + 24)     ; Right in the house



bug1_pos dw bug1_default_Pos
bug1_YPos dw 0


bugs_velocity dw 1, -1, -320, 320


bug2_pos dw bug2_default_Pos
bug3_pos dw bug3_default_Pos
bug3_YPos dw 0
bug4_pos dw bug4_default_Pos
bug4_YPos dw 0

section .text

move_bug1:
    xor bx, bx
    mov si, 0
    mov si, bugs_velocity
    cmp word [si], 1
    je .check_right_col_top
    jmp .check_left_col_top

    ; Right Collisions
    .check_right_col_top:
        mov ax, [bug1_pos]
        mov cx, window_width
        xor dx, dx
        div cx
        mov [bug1_YPos], dx
        add word [bug1_YPos], 16
        mov cx, [bug1_YPos]       
        mov dx, ax      
        call getColor 

        cmp bx, 0
        je .collide
        
        add dx, -2
        add cx, 2
        call getColor
        cmp bx, 6
        je .kill_ranky


        
    .check_right_col_bottom:
        mov ax, [bug1_pos]
        mov cx, window_width
        xor dx, dx
        div cx
        mov [bug1_YPos],dx
        add ax, 15
        add word [bug1_YPos], 16
        mov cx, [bug1_YPos]         
        mov dx, ax      
        call getColor 

        
        cmp bx, 0
        je .collide
        
        add dx, -2
        add cx, 2
        call getColor
        cmp bx, 6
        je .kill_ranky

        jmp .moving

; Left Collisions
    .check_left_col_top:
        mov ax, [bug1_pos]
        mov cx, window_width
        xor dx, dx
        div cx
        mov [bug1_YPos], dx
        sub word [bug1_YPos], 1
        mov cx, [bug1_YPos]       
        mov dx, ax      
        call getColor 

        cmp bx, 0
        je .collide

        add dx, -2
        add cx, 2
        call getColor
        cmp bx, 6
        je .kill_ranky

    .check_left_col_bottom:
        mov ax, [bug1_pos]
        mov cx, window_width
        xor dx, dx
        div cx
        mov [bug1_YPos],dx
        add ax, 15
        sub word [bug1_YPos], 1
        mov cx, [bug1_YPos]         
        mov dx, ax
        call getColor 

        cmp bx, 0
        je .collide

        add dx, -2
        add cx, -2
        call getColor
        cmp bx, 6
        je .kill_ranky

        jmp .moving

    ; .telep:
    ;     mov bx, [bug1_pos]
    ;     cmp bx, [telepUp]        
    ;     jne .moving
    ;     mov si, clean
    ;     mov di, [bug1_pos]
    ;     call draw_sprite
    ;     mov bx, [telepBottom]
    ;     sub bx, (window_width * 3)
    ;     mov [bug1_pos], bx
    ;     mov si, up_closed

    .kill_ranky:
        xor si, si
        mov si, isFrenzy
        cmp byte [si], 1
        je .skip_dec_life
            call dec_life
        .skip_dec_life:
            jmp .moving

    .moving:
        xor bx, bx
        mov si, 0
        mov si, bugs_velocity
        mov bx, [si]
        add bx, [bug1_pos]
        mov [bug1_pos], bx


        mov di, [bug1_pos]


        xor si, si
        mov si, isFrenzy
        cmp byte [si], 1
        je .frenzymode
        mov si, bug1_sprite
        call draw_sprite
        ret

        .frenzymode:
        mov si, bug1_sprite_frenzy
        call draw_sprite
        ret

    .collide:
        xor bx, bx
        mov si, 0
        mov si, bugs_velocity
        neg word [si]
        jmp .moving
        ret

    .eaten:
        mov cx, [killStreak]
        mov ax, 200
        mul cx

        mov bx, ax
        call add_score
        inc word [killStreak]

        ; disable frenzy mode
        mov si, 0
        mov si, isFrenzy           ; Load the address into si
        mov byte [si + 0], 0       ; Store the value at the current address

        mov si, clean
        mov di, [bug1_pos]
        call draw_sprite

        mov word [bug1_pos], bug1_default_Pos

        ret


move_bug2:
    .eaten:
        ret

move_bug3:

    xor bx, bx
    mov si, 0
    mov si, bugs_velocity
    add si, 4
    cmp word [si], 320
    je .check_down_col_left
    jmp .check_up_col_left

    .check_up_col_left:
        mov ax, [bug3_pos]
        mov cx, window_width
        xor dx, dx
        div cx
        mov [bug3_YPos], dx
        add ax, -1
        add word [bug3_YPos], 0
        mov cx, [bug3_YPos]       
        mov dx, ax      
        call getColor 

        cmp bx, 0
        je .collide
        
        add dx, -2
        add cx, 2
        call getColor
        cmp bx, 6
        je dec_life


        
    .check_up_col_right:
        mov ax, [bug3_pos]
        mov cx, window_width
        xor dx, dx
        div cx
        mov [bug3_YPos],dx
        add ax, -1
        add word [bug3_YPos], 15
        mov cx, [bug3_YPos]
        mov dx, ax      
        call getColor 

        
        cmp bx, 0
        je .collide
        
        add dx, -2
        add cx, 2
        call getColor
        cmp bx, 6
        je dec_life

        jmp .moving


    .check_down_col_left:
        mov ax, [bug3_pos]
        mov cx, window_width
        xor dx, dx
        div cx
        mov [bug3_YPos], dx
        add ax, 16
        add word [bug3_YPos], 0
        mov cx, [bug3_YPos]       
        mov dx, ax      
        call getColor 

        cmp bx, 0
        je .collide
        
        ; add dx, -2
        ; add cx, 2
        ; call getColor
        ; cmp bx, 6
        ; je dec_life


        
    ; .check_down_col_right:
    ;     xor bx, bx
    ;     mov ax, [bug3_pos]
    ;     mov cx, window_width
    ;     xor dx, dx
    ;     div cx
    ;     mov [bug3_YPos],dx
    ;     add ax, 16
    ;     add word [bug3_YPos], 15
    ;     mov cx, [bug3_YPos]         
    ;     mov dx, ax      
    ;     call getColor 

        
    ;     cmp bx, 0
    ;     je .collide
        
    ;     add dx, -2
    ;     add cx, 2
    ;     call getColor
    ;     cmp bx, 6
    ;     je dec_life

        jmp .moving

    .moving:
        xor bx, bx
        mov si, 0
        mov si, bugs_velocity
        add si, 4
        mov bx, [si]

        add bx, [bug3_pos]
        mov [bug3_pos], bx


        mov di, [bug3_pos]

        xor si, si
        mov si, isFrenzy
        add si, 2
        cmp byte [si], 1
        je .frenzymode
        xor si, si
        mov si, bug3_sprite
        call draw_sprite
        ret

        .frenzymode:
        mov si, bug3_sprite_frenzy
        call draw_sprite
        ret

    .collide:
        xor bx, bx
        mov si, 0
        mov si, bugs_velocity
        add si, 4
        neg word [si]
        jmp .moving
        ret

    .eaten:
        ret


move_bug4:
    .eaten:
        ret