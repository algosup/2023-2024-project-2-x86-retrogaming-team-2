org 100h

section .data

; Bugs Positions

bug1_default_Pos equ window_width*136+(window_width-16)/2  ; Outside of the house
bug2_default_Pos equ window_width*108+(window_width-16)/2  ; Center in the house
bug3_default_Pos equ window_width*108+((window_width-16)/2 - 24)     ; Left in the house
bug4_default_Pos equ window_width*108+((window_width-16)/2 + 24)     ; Right in the house


bug1_pos dw bug1_default_Pos
;bug1_pos dw nineteenthLine + 41 - (320*7) ; actual location of the bug 1
;nineteenthLine = 58575 -> where should starts the 19th line of the maze
;bug1_pos = 56376 -> position X of the bug 1
;41 = column number -> the column (from 0 to 320) where is located the bug through the line 19 of the maze

; GOAL, make an equation to retrieve the column number for calculations
; check .calculateBugLocation


bug1_YPos dw 0

bugs_velocity dw 1, -1, -320, 320
;1 to go right, -1 to go left, -320 to go up, and 320 to go down

bug2_pos dw bug2_default_Pos

bug3_pos dw bug3_default_Pos
bug3_YPos dw 0

bug4_pos dw bug4_default_Pos
bug4_YPos dw 0

loc0_pos dw sixteenthLine + 21 - (320*7) ; actual location of the spot we need to reach
;sixteenthLine = 50895 -> where should starts the 16th line of the maze
;loc0_pos = 48676 -> position X of the Spot
;21 = column number -> the column (from 0 to 320) where is located the spot through the line 16 of the maze

; GOAL, make an equation to retrieve the column number for calculations
; check .calculateSpotLocation

adjust dw (320*7) ; adjustement to place the bug in the maze properly
;adjust = 2240


section .text

;bug 1 starts to go on the right
;if he hits a wall, it goes up
;if he hits a wall, it goes left
;if he hits a wall, it goes down
;if he hits a wall, it goes right

move_bug1:
    xor bx, bx
    mov si, 0
    mov si, bugs_velocity
    ;call .calculateBugLocation
    ;call .calculateSpotLocation
    ;call .searchLocation
    mov bx, [bug1_pos]
    ;jl .changeDirectionRight
    ;call .changeDirectionLeft
    ;cmp bx, [loc0_pos]
    ;je .stop
    cmp word [si], 1
    je .check_right_col_top
    cmp word [si], -320
    je .check_up_col_left
    cmp word [si], -1
    je .check_left_col_top
    cmp word [si], 320
    je .check_down_col_left

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
            je .collideNew
            
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
            je .collideNew
            
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
            je .collideNew

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
            je .collideNew

            add dx, -2
            add cx, -2
            call getColor
            cmp bx, 6
            je .kill_ranky

            jmp .moving

    ; Up Collisions
        .check_up_col_left:
            mov ax, [bug1_pos]
            mov cx, window_width
            xor dx, dx
            div cx
            mov [bug1_YPos], dx
            add ax, -1
            add word [bug1_YPos], 0
            mov cx, [bug1_YPos]       
            mov dx, ax      
            call getColor 

            cmp bx, 0
            je .collideNew
            
            add dx, -2
            add cx, 2
            call getColor
            cmp bx, 6
            je .kill_ranky
        
        .check_up_col_right:
            mov ax, [bug1_pos]
            mov cx, window_width
            xor dx, dx
            div cx
            mov [bug1_YPos],dx
            add ax, -1
            add word [bug1_YPos], 15
            mov cx, [bug1_YPos]
            mov dx, ax      
            call getColor 

            
            cmp bx, 0
            je .collideNew
            
            add dx, -2
            add cx, 2
            call getColor
            cmp bx, 6
            je .kill_ranky

            jmp .moving
        
        .check_down_col_left:
            mov ax, [bug1_pos]
            mov cx, window_width
            xor dx, dx
            div cx
            mov [bug1_YPos], dx
            add ax, 16
            add word [bug1_YPos], 0
            mov cx, [bug1_YPos]       
            mov dx, ax      
            call getColor 

            cmp bx, 0
            je .collideNew
            
            add dx, -2
            add cx, 2
            call getColor
            cmp bx, 6
            je .kill_ranky


            
        .check_down_col_right:
            xor bx, bx
            mov ax, [bug1_pos]
            mov cx, window_width
            xor dx, dx
            div cx
            mov [bug1_YPos],dx
            add ax, 16
            add word [bug1_YPos], 15
            mov cx, [bug1_YPos]         
            mov dx, ax      
            call getColor 

            
            cmp bx, 0
            je .collideNew
            
            add dx, -2
            add cx, 2
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

    .collideNew:; previous test program to change directions when colliding with a wall
        xor bx, bx
        mov si, 0
        mov si, bugs_velocity
        cmp word [si], 1; if bug is going on the right
        je .changeDirectionUp;go UP if possible
        cmp word [si], -320; if bug is going up
        je .changeDirectionLeft;go LEFT if possible
        cmp word [si], -1; if bug is going on the left
        je .changeDirectionDown;go DOWN if possible
        cmp word [si], 320; if bug is going down
        je .changeDirectionRight;go RIGHT if possible
        jmp .moving; continue to move
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

    .stop:; make the character stop
        mov word [si], 0; change velocity to stay immobile
        ret

    .calculateBugLocation:;calculate the column location of the bug
        xor cx, cx; reset cx to 0 to use it properly
        mov cx, [bug1_pos]; cx = 56376
        sub cx, [nineteenthLine]; cx = 56376 - 58575 = -2199
        neg cx ; cx = -2199 * -1 = 2199
        xor bx, bx; reset bx to 0 to use it properly 
        mov bx, [adjust]; bx = 2240
        sub bx, cx; bx = 2240 - 2199 = 41
        ret; result = 41 -> the column number of the bug
    
    .calculateSpotLocation:;calculate the column location of the spot
        xor dx, dx; reset dx to 0 to use it properly
        mov dx, [loc0_pos]; dx = 48676
        sub dx, [sixteenthLine]; cx = 48676 - 50895 = -2219
        neg dx ; cx = -2219 * -1 = 2219
        xor cx, cx; reset cx to 0 to use it properly
        mov cx, [adjust]; cx = 2240
        sub cx, dx; cx = 2240 - 2219 = 21
        ret; result = 21 -> the column number of the spot
    
    .searchLocation:;search the location the bug must reach
        cmp bx, cx; compare the bug and the spot's column location
        jb .changeDirectionRight ;if bx < cx, go right
        ja .changeDirectionLeft; if bx > cx, go left
        je .stop; if bx == cx, stop
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
        
        add dx, -2
        add cx, 2
        call getColor
        cmp bx, 6
        je dec_life


        
    .check_down_col_right:
        xor bx, bx
        mov ax, [bug3_pos]
        mov cx, window_width
        xor dx, dx
        div cx
        mov [bug3_YPos],dx
        add ax, 16
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