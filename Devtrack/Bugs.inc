org 100h

section .data

; Bugs Positions
bug1_pos dw window_width*136+(window_width-16)/2  ; Outside of the house
bug1_YPos dw 0

bugs_velocity dw 1, 1, 1, 1


bug2_pos dw window_width*108+(window_width-16)/2  ; Center in the house
bug3_pos dw window_width*108+((window_width-16)/2 - 24)     ; Left in the house
bug4_pos dw window_width*108+((window_width-16)/2 + 24)     ; Right in the house

section .text

    move_bug1:

        ; mov di, [bug1_pos]
        ; mov si, bug1_sprite
        ; call draw_sprite
        ; ret

		

        cmp byte [bugs_velocity], 1
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

                jmp .movingright

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

                jmp .movingleft

        ;
        ;
        ;
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

        .movingleft:
            xor bx, bx
            mov bx, [bugs_velocity]
            add bx, [bug1_pos]
            mov [bug1_pos], bx


            mov di, [bug1_pos]
            mov si, bug1_sprite_left
            call draw_sprite
            ret


        .movingright:
            xor bx, bx
            mov bx, [bugs_velocity]
            add bx, [bug1_pos]
            mov [bug1_pos], bx


            mov di, [bug1_pos]
            mov si, bug1_sprite_right
            call draw_sprite
            ret



        .collide:
            ; mov ah, 4ch
            ; xor al, al
            ; int 21h
            ; neg byte [bugs_velocity]
            mov bx, [bugs_velocity]
            neg bx
            mov [bugs_velocity], bx
            jmp .movingright

