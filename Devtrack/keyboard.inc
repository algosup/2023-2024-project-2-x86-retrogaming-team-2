section .data

    ; KeyBind
    %DEFINE key_up 2Ch      ; Z
    %DEFINE key_up2 48h     ; Arrow Up

    %DEFINE key_down 1Fh    ; S
    %DEFINE key_down2 50h   ; Arrow Down

    %DEFINE key_left 10h    ; Q
    %DEFINE key_left2 4BH   ; Arrow Left

    %DEFINE key_right 20h   ; D
    %DEFINE key_right2 4DH  ; Arrow Right

    %DEFINE key_exit 01h    ; Escape
    %DEFINE key_menu 1Ch    ; Enter



    keyPressed dw 0
    newKeyPressed dw 0

section .text

keyboard_handler:

    mov ah, 01h
    int 16h
    jz .skip_buffer


    .read_buffer:
        mov ah, 00h
        int 16h


        mov [newKeyPressed], ah

        push cx
        push ax
            
        call check_col

        pop ax
        pop cx
        
        cmp bx, 0
        jne .skip_key_change

        mov ch, [keyPressed]
        mov ax, cx

        .skip_key_change:
            mov bx, ax
            mov ah, 01h
            int 16h
            jnz .read_buffer

    mov [keyPressed], bh

    .skip_buffer:

        mov bh, [newKeyPressed]
        cmp byte [keyPressed], bh
        je .skip_update_key

        call check_col

        cmp bx, 0
        je .skip_update_key

        mov bh, [newKeyPressed]
        mov [keyPressed], bh

        .skip_update_key:
        ; Exit
        cmp byte [keyPressed], key_exit
        je .exit

        ; Menu
        cmp byte [keyPressed], key_menu
        je .menu

        ; Key_Up
        cmp byte [keyPressed], key_up
        je .moveUp

        ; Key_Down
        cmp byte [keyPressed], key_down
        je .moveDn

        ; Key_Right
        cmp byte [keyPressed], key_right
        je .moveRg

        ; Key_Left
        cmp byte [keyPressed], key_left
        je .moveLf

        ; Key_Up 2
        cmp byte [keyPressed], key_up2
        je .moveUp

        ; Key_Down 2
        cmp byte [keyPressed], key_down2
        je .moveDn

        ; Key_Right 2
        cmp byte [keyPressed], key_right2
        je .moveRg

        ; Key_Left 2
        cmp byte [keyPressed], key_left2
        je .moveLf



        jmp .end_buffer

        .moveUp:
            call moveup
            jmp .end_buffer
        .moveDn:
            call movedown
            jmp .end_buffer
        .moveRg:
            call moveright
            jmp .end_buffer
        .moveLf:
            call moveleft
            jmp .end_buffer
        .exit:
            mov ah, 4ch
            xor al, al
            int 21h
        .menu:
            ; mov ah, 4ch
            ; xor al, al
            ; int 21h

        .end_buffer:
            ret


check_col:

    cmp byte [newKeyPressed], key_right
    je .right_col

    cmp byte [newKeyPressed], key_right2
    je .right_col

    .right_col:
        cmp word [xVelocity], -320
        je .right_bottom
        cmp word [xVelocity], 320
        je .right_top
        ret
        ; issue if direction not found 

    .right_bottom:
        
        ; Check Collisions at 1 px at Right of Ranky
        mov ax, [xPos]
        mov cx, window_width
        xor dx, dx
        div cx
        mov [yPos], dx
        add ax, 16
        add word [yPos], 15
        mov cx, [yPos]
        mov dx, ax
        call getColor 

        ret

    .right_top:
        
        ; Check Collisions at 1 px at Right of Ranky
        mov ax, [xPos]
        mov cx, window_width
        xor dx, dx
        div cx
        mov [yPos], dx
        ; add ax, 16
        add word [yPos], 16
        mov cx, [yPos]
        mov dx, ax
        call getColor 

        ret