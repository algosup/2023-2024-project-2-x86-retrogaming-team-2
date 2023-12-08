org 100h

section .data

bugOld1 dw 0
bugPosY1 dw 0

up db 0
down db 0
left db 0
right db 0

section .text 

moveBug1:
    mov ax, [bug1_pos]
    mov [bugOld1], ax
    call check_col_left
    call check_col_up
    call check_col_right
    call check_col_down
    jmp moveBug1

check_col_down:
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

    ; if a wall
    cmp bx, 0       
    je falseDown

    ; no wall
    cmp bx, 0
    jne bugMoveDown
    ret


check_col_up:
    mov ax, [bug1_pos]
    mov cx, window_width
    xor dx, dx
    div cx
    mov [bugPosY1],dx
    sub ax, 0
    add word [bugPosY1], 8
    mov cx, [bugPosY1]         
    mov dx, ax      
    call getColor 

    ; if a wall
    cmp bx, 0       
    je falseUp

    ; no wall
    cmp bx, 0
    jne bugMoveUp
    ret

check_col_left:
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

    ; if a wall
    cmp bx, 0       
    je falseLeft

    ; no wall
    cmp bx, 0
    jne bugMoveLeft
    ret

check_col_right:
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

    ; if a wall
    cmp bx, 0       
    je falseRight

    ; no wall
    cmp bx, 0
    jne bugMoveRight
    ret

moving:
        mov di, [bug1_pos]
        add di, 1
        mov [bug1_pos], di
        call changeloop
        call draw_sprite
        jmp move_bug1

end:
        mov bx, [bugOld1]
        mov [bug1_pos], bx
        mov di, [bug1_pos]
        call changeloop
        call draw_sprite
        jmp move_bug1

falseDown:
    mov ax, [down]
    mov ax, 0
    mov [down], ax 
    ret

trueDown:
    mov ax, [down]
    mov ax, 1
    mov [down], ax 
    ret

bugMoveDown:
    call trueDown
    mov ax, [bug1_pos]
    add ax, window_width
    mov [bug1_pos], ax
    ret

falseUp:
    mov ax, [up]
    mov ax, 0
    mov [up], ax 
    ret

trueUp:
    mov ax, [up]
    mov ax, 1
    mov [up], ax 
    ret

bugMoveUp:
    call trueUp
    mov ax, [bug1_pos]
    sub ax, window_width
    mov [bug1_pos], ax
    ret

falseLeft:
    mov ax, [left]
    mov ax, 0
    mov [left], ax 
    jmp 

trueLeft:
    mov ax, [left]
    mov ax, 1
    mov [left], ax 
    ret

bugMoveLeft:
    call trueLeft
    mov ax, [bug1_pos]
    sub ax, 1
    mov [bug1_pos], ax
    ret

falseRight:
    mov ax, [right]
    mov ax, 0
    mov [right], ax 
    ret

trueRight:
    mov ax, [right]
    mov ax, 1
    mov [right], ax 
    ret

bugMoveRight:
    call trueRight
    mov ax, [bug1_pos]
    add ax, 1
    mov [bug1_pos], ax
    ret