; Point of view of the bugs
; when there is a dot on their way -> get color = 2
; get position top left of the dot
; xPos+ the difference between to potision of the dot 
; data
; and redraw it 18 frame after

section .data

top dw 2238         ; + 2238 for the left
bot dw 2256         ; + 2256 for the right
lef dw 647          ; -  647 for the top
rig dw 5127         ; + 5127 for the bottom

; bug1_pos

waiting dw 0
dotPos dw 0

section .text

    CandyBuffer:        ;top
        
        mov ax, [bug1_pos]
        mov cx, window_width
        xor dx, dx
        div cx
        mov [bug1_YPos],dx
        sub ax, 0
        add word [bug1_YPos], 15
        mov cx, [bug1_YPos]         
        mov dx, ax      
        xor bx, bx
        mov bx, [dotPos]
        add bx, top
        mov [dotPos], bx
        xor bx, bx
        call getColor 

        cmp bx, 2
        je .wait18

        ret
        .wait18:
            cmp word [waiting], 18
            jne .wait18
            jmp .redraw

        .redraw:
            ; code to draw the 4 pixels
            int3
            ret
