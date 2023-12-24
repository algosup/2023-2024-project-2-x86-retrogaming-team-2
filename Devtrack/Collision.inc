org 100h
section .data

    colorWall dw 0x10                        ; color of the walls
    candyColor dw 0x43
    colorCheckMark dw 0x2F
    colorBug1 dw 0x6F
    colorBug2 dw 0x7E
    colorBug3 dw 0x6C
    colorBug4 dw 0x6A
    colorBug4_1 dw 0x20
    colorRanky dw 0x27


section .text


; Collisions
; 0 - Wall
; 1 - Nothing
; 2 - Candies
; 3 - Check Marks
; 4 - Bug or ranky
; 5 - Frenzy on Bug 1
; 6 - Eat Ranky
; 7 - Frenzy on Bug 2
; 8 - Frenzy on Bug 3
; 9 - Frenzy on Bug 4
getColor:
    mov ah, 0DH                 ; AH = 0Dh for "Read Dot" function
    int 10h

    ; mov ah, 0CH
    ; mov al, 0DH
    ; int 10h

    mov bx, 0

    ; color of the pixel in al
    cmp al, [colorWall]
    je .end 

    mov bx, 1

    cmp al, [candyColor]
    je .candy

    cmp al, [colorCheckMark]
    je .check_mark

    cmp al, [colorBug1]
    je .bug1
    cmp al, [colorBug2]
    je .bug2
    cmp al, [colorBug3]
    je .bug3
    cmp al, [colorBug4]
    je .bug4

    cmp al, [colorRanky]
    je .eat_ranky

    jmp .end
   
    .candy:
        mov bx, 2
        jmp .end

    .check_mark:
        mov bx, 3
        jmp .end
    .bug1:
        mov bx, 5
        mov si, isFrenzy
        add si, 0
        cmp word [si],1
        je .end

        mov bx, 4
        jmp .end
    
    .bug2:
        mov bx, 7
        mov si, isFrenzy
        add si, 2
        cmp word [si],1
        je .end

        mov bx, 4
        jmp .end

    .bug3:
        mov bx, 8
        mov si, isFrenzy
        add si, 4
        cmp word [si],1
        je .end

        mov bx, 4
        jmp .end

    .bug4:
        mov bx, 9
        mov si, isFrenzy
        add si, 6
        cmp word [si],1
        je .end

        mov bx, 4
        jmp .end

    .eat_ranky:
        mov bx, 6
        jmp .end

    .end:
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
            add ax, -1
            add word [yPos], 0
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
            add ax, -1
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
            add ax, -1
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
            add ax, 16
            add word [yPos], 0
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
            add ax, 16
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
            add ax, 16
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
            add ax, 0
            sub word [yPos], 1
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
            sub word [yPos], 1
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
            sub word [yPos], 1
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
            add ax, 0
            add word [yPos], 16
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
            add word [yPos], 16
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
            add word [yPos], 16
            mov cx, [yPos]
            mov dx, ax
            call getColor
            jmp .end

    .end:
        ret