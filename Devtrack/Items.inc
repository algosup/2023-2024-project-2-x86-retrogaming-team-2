%define origin 39*window_width+15 ; 12495
%define line 8

section .data

    dotsArray   dw origin, origin+ 8, origin+ 16, origin+ 24, origin+ 32, origin+ 40, origin+ 48, origin+ 56 
                dw origin+ 64, origin+ 72, origin+ 80, origin+ 88, origin+ 96, origin+ 104, origin+ 112, origin+ 120 
                dw origin+ 168, origin+ 176, origin+ 184, origin+ 192, origin+ 200, origin+ 208, origin+ 216, origin+ 224
                dw origin+ 232, origin+ 240, origin+ 248, origin+ 256, origin+ 264, origin+ 272, origin+ 280, origin+ 288 
                ; 2nd line
                dw origin+(1*line)*320, origin+(1*line)*320+ 96, origin+(1*line)*320+ 120, origin+(1*line)*320+ 168, origin+(1*line)*320+ 192, origin+(1*line)*320+ 288
                ; 3rd line
                dw origin+(2*line)*320, origin+(2*line)*320+ 96, origin+(2*line)*320+ 120, origin+(2*line)*320+128, origin+(2*line)*320+136, origin+(2*line)*320+ 144, origin+(2*line)*320+ 152, origin+(2*line)*320+ 160, origin+(2*line)*320+ 168, origin+(2*line)*320+ 192, origin+(2*line)*320+ 288 
                ; 4th line
                dw origin+(3*line)*320, origin+(3*line)*320+ 8, origin+(3*line)*320+ 24, origin+(3*line)*320+ 32, origin+(3*line)*320+ 40, origin+(3*line)*320+ 48, origin+(3*line)*320+ 56 
                dw origin+(3*line)*320+ 64, origin+(3*line)*320+ 72, origin+(3*line)*320+ 80, origin+(3*line)*320+ 88, origin+(3*line)*320+ 96, origin+(3*line)*320+ 120 
                dw origin+(3*line)*320+168, origin+(3*line)*320+192, origin+(3*line)*320+ 200, origin+(3*line)*320+ 208, origin+(3*line)*320+ 216, origin+(3*line)*320+ 224
                dw origin+(3*line)*320+ 232, origin+(3*line)*320+ 240, origin+(3*line)*320+ 248, origin+(3*line)*320+ 256, origin+(3*line)*320+ 264, origin+(3*line)*320+ 280, origin+(3*line)*320+ 288 
                ; 5th line
                dw origin+(4*line)*320, origin+(4*line)*320+ 40, origin+(4*line)*320+ 120, origin+(4*line)*320+ 168, origin+(4*line)*320+ 248, origin+(4*line)*320+ 288   
                ; 6th line
                dw origin+(5*line)*320, origin+(5*line)*320+ 40, origin+(5*line)*320+ 120, origin+(5*line)*320+ 168, origin+(5*line)*320+ 248, origin+(5*line)*320+ 288 
                ; 7th line
                dw origin+(6*line)*320, origin+(6*line)*320+ 8, origin+(6*line)*320+ 16, origin+(6*line)*320+ 40, origin+(6*line)*320+ 48, origin+(6*line)*320+ 56, origin+(6*line)*320+ 64, origin+(6*line)*320+ 72, origin+(6*line)*320+ 80 
                dw origin+(6*line)*320+ 88, origin+(6*line)*320+ 96, origin+(6*line)*320+ 104, origin+(6*line)*320+ 112, origin+(6*line)*320+ 120 
                dw origin+(6*line)*320+ 168, origin+(6*line)*320+ 176, origin+(6*line)*320+ 184, origin+(6*line)*320+ 192, origin+(6*line)*320+ 200, origin+(6*line)*320+ 208, origin+(6*line)*320+ 216,
                dw origin+(6*line)*320+ 224, origin+(6*line)*320+ 232, origin+(6*line)*320+ 240, origin+(6*line)*320+ 248, origin+(6*line)*320+ 272, origin+(6*line)*320+ 280, origin+(6*line)*320+ 288 
                ; 8th line
                dw origin+(7*line)*320+ 16, origin+(7*line)*320+ 72, origin+(7*line)*320+ 96, origin+(7*line)*320+ 192, origin+(7*line)*320+ 216, origin+(7*line)*320+ 272 
                ; 9th line
                dw origin+(8*line)*320+ 16, origin+(8*line)*320+ 72, origin+(8*line)*320+ 96, origin+(8*line)*320+ 192, origin+(8*line)*320+ 216, origin+(8*line)*320+ 272
                ; 10th line
                dw origin+(9*line)*320+ 16, origin+(9*line)*320+40 , origin+(9*line)*320+ 48, origin+(9*line)*320+ 56, origin+(9*line)*320+ 64, origin+(9*line)*320+ 72, origin+(9*line)*320+ 80, origin+(9*line)*320+ 88, origin+(9*line)*320+ 96
                dw origin+(9*line)*320+ 192, origin+(9*line)*320+ 200, origin+(9*line)*320+ 208, origin+(9*line)*320+ 216, origin+(9*line)*320+ 224, origin+(9*line)*320+ 232, origin+(9*line)*320+ 240, origin+(9*line)*320+ 248, origin+(9*line)*320+ 272
                ; 11th line
                dw origin+(10*line)*320+ 16, origin+(10*line)*320+ 40, origin+(10*line)*320+ 96, origin+(10*line)*320+ 192, origin+(10*line)*320+ 248, origin+(10*line)*320+ 272
                ; 12th line
                dw origin+(11*line)*320+ 16, origin+(11*line)*320+ 40, origin+(11*line)*320+ 96, origin+(11*line)*320+ 192, origin+(11*line)*320+ 248, origin+(11*line)*320+ 272
                ; 13th line
                dw origin+(12*line)*320, origin+(12*line)*320+ 8, origin+(12*line)*320+ 16, origin+(12*line)*320+ 40, origin+(12*line)*320+ 48, origin+(12*line)*320+ 56, origin+(12*line)*320+ 64, origin+(12*line)*320+ 72
                dw origin+(12*line)*320+ 80, origin+(12*line)*320+ 88, origin+(12*line)*320+ 96, origin+(12*line)*320+ 192, origin+(12*line)*320+ 200, origin+(12*line)*320+ 208, origin+(12*line)*320+ 216
                dw origin+(12*line)*320+ 224, origin+(12*line)*320+ 232, origin+(12*line)*320+ 240, origin+(12*line)*320+ 248, origin+(12*line)*320+ 272, origin+(12*line)*320+ 280, origin+(12*line)*320+ 288 
                ; 14th line
                dw origin+(13*line)*320, origin+(13*line)*320+ 40, origin+(13*line)*320+ 96, origin+(13*line)*320+ 104, origin+(13*line)*320+ 112, origin+(13*line)*320+ 120, origin+(13*line)*320+ 168, origin+(13*line)*320+ 176;start 14th line
                dw origin+(13*line)*320+ 184, origin+(13*line)*320+ 192, origin+(13*line)*320+ 248, origin+(13*line)*320+ 288
                ; 15th line
                dw origin+(14*line)*320, origin+(14*line)*320+ 40, origin+(14*line)*320+ 96, origin+(14*line)*320+ 120,origin+(14*line)*320+ 168, origin+(14*line)*320+ 192, origin+(14*line)*320+ 248, origin+(14*line)*320+ 288
                ; 16th line
                dw origin+(15*line)*320, origin+(15*line)*320+ 24, origin+(15*line)*320+ 32, origin+(15*line)*320+ 40, origin+(15*line)*320+ 48, origin+(15*line)*320+ 56, origin+(15*line)*320+ 64, origin+(15*line)*320+ 72, origin+(15*line)*320+ 80, origin+(15*line)*320+ 88
                dw origin+(15*line)*320+ 96, origin+(15*line)*320+ 120, origin+(15*line)*320+ 168, origin+(15*line)*320+ 192, origin+(15*line)*320+ 200, origin+(15*line)*320+ 208, origin+(15*line)*320+ 216, origin+(15*line)*320+ 224, origin+(15*line)*320+ 232
                dw origin+(15*line)*320+ 240, origin+(15*line)*320+ 248, origin+(15*line)*320+ 256, origin+(15*line)*320+ 264, origin+(15*line)*320+ 288
                ; 17th line
                dw origin+(16*line)*320, origin+(16*line)*320+ 48, origin+(16*line)*320+ 120,origin+(16*line)*320+ 128,origin+(16*line)*320+ 136,origin+(16*line)*320+ 144,origin+(16*line)*320+ 152,origin+(16*line)*320+ 160, origin+(16*line)*320+ 168, origin+(16*line)*320+ 240, origin+(16*line)*320+ 288
                ; 18th line
                dw origin+(17*line)*320, origin+(17*line)*320+ 48, origin+(17*line)*320+ 120, origin+(17*line)*320+ 168, origin+(17*line)*320+ 240, origin+(17*line)*320+ 288
                ; 19th line
                dw origin+(18*line)*320, origin+(18*line)*320+ 8, origin+(18*line)*320+ 16, origin+(18*line)*320+ 24, origin+(18*line)*320+ 40, origin+(18*line)*320+ 48, origin+(18*line)*320+ 56 
                dw origin+(18*line)*320+ 64, origin+(18*line)*320+ 72, origin+(18*line)*320+ 80, origin+(18*line)*320+ 88, origin+(18*line)*320+ 96, origin+(18*line)*320+ 104, origin+(18*line)*320+ 112, origin+(18*line)*320+ 120 
                dw origin+(18*line)*320+ 168, origin+(18*line)*320+ 176, origin+(18*line)*320+ 184, origin+(18*line)*320+ 192, origin+(18*line)*320+ 200, origin+(18*line)*320+ 208, origin+(18*line)*320+ 216, origin+(18*line)*320+ 224
                dw origin+(18*line)*320+ 232, origin+(18*line)*320+ 240, origin+(18*line)*320+ 248, origin+(18*line)*320+ 264, origin+(18*line)*320+ 272, origin+(18*line)*320+ 280, origin+(18*line)*320+ 288 
               
    checkMarkPos dw origin+(3*line)*320+13-(320*3), origin+(3*line)*320+269-(320*3),origin+(18*line)*320+29-(320*3),origin+(18*line)*320+253-(320*3)
    Dots_pos times 270 dw 10
    
    OldVelocity dw -1

section .text:
    drawDot:
        mov ax, 0xA000  ; address to write
        mov cx,0
        mov si, Dots_pos
        mov es,ax
        mov di,[si]
        mov al, 0x43

        ; to change color, in case

        DrawDotLoop:
        
        ; don't draw if the dot position is 0
        cmp di, 0
        je .endLoop
        

        mov al, 0x43
        mov [es:di], al

        .SecondPoint:
        inc di
        cmp word [es:di],0x00
        jne .ThirdPoint
        mov [es:di], al
        .ThirdPoint:
        call newLine

        add si,2 ; add 2 because each element is 2 byte long
        mov di, [si]

        inc cx
        cmp cx,270
        jb DrawDotLoop

        ret

    .endLoop:
        inc cx
        add si,2
        mov di,[si]
        jmp DrawDotLoop
	newLine:
		add di, window_width

        cmp word [es:di],0x00
        jne .FourthPoint
		mov [es:di], al

        .FourthPoint:
		add di, -1
		mov [es:di], al
		ret

DrawCheckMark:
    mov ax, 0xA000
    mov cx,4
    mov si, checkMarkPos
    mov es,ax
    
    .CheckMarkLoop:
        mov di,[si]

        ; don't draw if the checkMark position is 0
        cmp di, 0
        je .end

        push si
        push cx
        push ax

        mov si, check_mark
        call draw_tile
    
        pop ax
        pop cx
        pop si

        add si, 2
        loop .CheckMarkLoop
    
    .end:
        ret


erase_candy:
    ; set the buffer of candies in SI
    ; set the index at 0
    mov si, Dots_pos
    mov bx, 0

    .loop:
        xor dx, dx
        add si, bx
    
        ; Limit to 60000 to avoid overflow
        cmp word [si], 60000
        jae .end

        ; inc the index
        mov bx, 2
        mov dx, di

        ; compare actual Velocity with Velocity saved
        cmp word [xVelocity], -320
        je .skipSub

        mov ax, [xVelocity]
        cmp ax, [OldVelocity]
        je .skipSub
        
        
        sub dx, [xVelocity]

    .skipSub:
        ; if candy's coords aren't equal to the coords in the buffer we continue to loop
        cmp word [si], dx
        jne .loop

        ; set the coords in the buffer to 0 to stop drawing this candy
        mov word [si], 0

        dec word [candies_remain]
        
        push bx
        mov bx, 10
        call add_score
        pop bx

        ; save the Velocity in OldVelocity
        mov ax, [xVelocity]
        mov word [OldVelocity], ax

        .end:
        ret

erase_check_mark:
    xor dx, dx
    mov dx, [xPos]

    cmp word [xVelocity], 1
    je .checkRight
    cmp word [xVelocity], -1
    je .checkLeft
    jmp .end

    .checkRight:
        add dx, 320*4+16
        jmp .EraseCheckMark
        
    .checkLeft:
        add dx, 320*4-8
        jmp .EraseCheckMark
        

    .EraseCheckMark:  

        mov si, checkMarkPos
        mov bx, 0

        .loop:
            add si, bx
            mov bx, 2

            cmp word [si], dx
            jne .loop
            
        mov word [si], 0

        mov di, dx
        mov si, clean
        call draw_tile

        mov bx, 50
        call add_score
        mov bx, [xPos]

        call toggle_frenzy.enable_frenzy

    .end:
        ret

reset_buffer:
    mov si, dotsArray ; Source index
    mov di, Dots_pos   ; Destination index
    mov cx, 540   ; Loop counter

    .overwrite_loop:
        ; Copy one byte from source to destination
        mov ax, [si]
        mov [di], ax

        ; Increment source and destination indices
        inc si
        inc di

        dec cx
        cmp cx,0
        ja .overwrite_loop
        ret
        

EraseCandy:
    ; Velocity determine on which side is the candy
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
        add di,16+320*7

        jmp .EraseCandy
        
    .EraseCandyLeft:
        mov di, [xPos]
        add di, 320*7-2


        jmp .EraseCandy
    .EraseCandyTop:
        mov di, [xPos]
        sub di, 320-7 ; 313 ; ISSUE

        jmp .EraseCandy
    .EraseCandyBottom:
        mov di, [xPos]
        add di,7+320*16

        jmp .EraseCandy

    .EraseCandy:
        ; DI is the dot on the top-left, position present in the array in item
        call erase_candy
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

toggle_frenzy:
    .enable_frenzy:

        mov si, isFrenzy       ; Load the address into si
        xor bx, bx

        .activation_loop:
            mov word [si + bx], 1       ; Store the value at the current address
            add bx, 2

            cmp bx, 8
            jl .activation_loop

            mov byte [killStreak], 1
            jmp .end

    .disable_frenzy:
        mov si, isFrenzy       ; Load the address into si
        xor bx, bx
        .desactivation_loop:
            mov word [si + bx], 0       ; Store the value at the current address
            add bx, 2

            cmp bx, 8
            jl .desactivation_loop
            mov byte [killStreak], 1
            jmp .end

    .end:
        ret