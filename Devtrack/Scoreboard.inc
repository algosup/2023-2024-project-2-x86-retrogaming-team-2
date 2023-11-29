score db '1418907',0
highscore_title dw 'high score', 0
highscore dw '4418907', 0

length db 0
singlechar dw 'X$'

letter_space_size equ 1

score_xoffset equ 5
score_yoffset equ 8

highscore_title_xoffset equ 130
highscore_title_yoffset equ 4

highscore_xoffset equ 137
highscore_yoffset equ 13

life_xoffset equ 10
life_yoffset equ 4

%DEFINE score_offset 10

draw_scoreboard:

    inc bx
    mov ah, 0Ch
    mov al, 19h ; color (08h)
    mov dx, 23
    mov cx, bx
    int 10h
    
    cmp bx, window_width
    jb draw_scoreboard
    ret

draw_score:
    push ax
    push si
    lea si, [score]
    call count_char
    pop si
    pop ax
    xor dx, dx

    mov dx, window_width*score_yoffset + score_xoffset

    mov si, score

    .drawingloop:
        mov al, [si]
        push si

        push dx
        call get_letter
        pop dx
        mov di, dx
        add dx, 7 + letter_space_size
        push dx
        call draw_letter
        pop dx
        pop si

        dec byte [length]
        inc si

        cmp byte [length], 0
        ja .drawingloop
        ret

count_char:
    mov byte [length], 0

    .count_loop:
        cmp byte [si], 0  
        je .count_end  

        inc byte [length]  
        inc si  
        jmp .count_loop  

    .count_end:
        ret
    
get_letter:
    cmp al, '0'
    je get_letter._0
    cmp al, '1'
    je get_letter._1
    cmp al, '2'
    je get_letter._2
    cmp al, '3'
    je get_letter._3
    cmp al, '4'
    je get_letter._4
    cmp al, '5'
    je get_letter._5
    cmp al, '6'
    je get_letter._6
    cmp al, '7'
    je get_letter._7
    cmp al, '8'
    je get_letter._8
    cmp al, '9'
    je get_letter._9
    cmp al, 'h'
    je get_letter._h
    cmp al, 'i'
    je get_letter._i
    cmp al, 'g'
    je get_letter._g
    cmp al, ' '
    je get_letter._space
    cmp al, 's'
    je get_letter._s
    cmp al, 'c'
    je get_letter._c
    cmp al, 'o'
    je get_letter._o
    cmp al, 'r'
    je get_letter._r
    cmp al, 'e'
    je get_letter._e


    ._0:
        mov si, num_0
        ret
    ._1:
        mov si, num_1
        ret
    ._2:
        mov si, num_2
        ret
    ._3:
        mov si, num_3
        ret
    ._4:
        mov si, num_4
        ret
    ._5:
        mov si, num_5
        ret
    ._6:
        mov si, num_6
        ret
    ._7:
        mov si, num_7
        ret
    ._8:
        mov si, num_8
        ret
    ._9:
        mov si, num_9
        ret

    ._h:
        mov si, letter_h
        ret
    ._i:
        mov si, letter_i
        ret
    ._g:
        mov si, letter_g
        ret
    ._space:
        mov si, letter_space
        ret
    ._s:
        mov si, letter_s
        ret
    ._c:
        mov si, letter_c
        ret
    ._o:
        mov si, letter_o
        ret
    ._r:
        mov si, letter_r
        ret
    ._e:
        mov si, letter_e
        ret



draw_highscore:

    push ax
    push si
    lea si, [highscore_title]
    call count_char
    pop si
    pop ax
    xor dx, dx

    mov dx, window_width*highscore_title_yoffset + highscore_title_xoffset

    mov si, highscore_title

    .drawingtitleloop:
        mov al, [si]
        push si

        push dx
        call get_letter
        pop dx
        mov di, dx
        add dx, 7 + letter_space_size
        push dx
        call draw_letter
        pop dx
        pop si

        dec byte [length]
        inc si

        cmp byte [length], 0
        ja .drawingtitleloop


    push ax
    push si
    lea si, [highscore]
    call count_char
    pop si
    pop ax
    xor dx, dx

    mov dx, window_width*highscore_yoffset + highscore_xoffset

    mov si, highscore

    .drawingscoreloop:
        mov al, [si]
        push si

        push dx
        call get_letter
        pop dx
        mov di, dx
        add dx, 7 + letter_space_size
        push dx
        call draw_letter
        pop dx
        pop si

        dec byte [length]
        inc si

        cmp byte [length], 0
        ja .drawingscoreloop
        ret

draw_life:
    mov si, right_closed
    mov di, (window_width*life_yoffset - 16) - life_xoffset
    call draw_sprite

    mov si, right_closed
    mov di, (window_width*life_yoffset - 16) - (life_xoffset + 18)
    call draw_sprite

    mov si, right_closed
    mov di, (window_width*life_yoffset - 16) - (life_xoffset + 36)
    call draw_sprite
    ret