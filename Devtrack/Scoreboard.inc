score1 dw 0000
score2 dw 0000

digits db 5 DUP(0) ; Array to store individual digits
highscore_title dw 'high score', 0
highscore1 dw 0625
highscore2 dw 9100

candies_remain dw 0270

length db 0

letter_space_size equ 1
thousand_space_size equ 5

digits_counter dw 2

score_xoffset equ 5
score_yoffset equ 8

highscore_title_xoffset equ 130
highscore_title_yoffset equ 4

highscore_xoffset equ 137
highscore_yoffset equ 13

life_xoffset equ 10
life_yoffset equ 4

life_count db 3

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

update_score:
    cmp word [candies_remain], 0
    jz end_level

    cmp byte [life_count], 0
    jz .die

    call draw_score
    call draw_highscore
    call draw_life


    ret

    .die:
        mov si, game_over
        mov di, 31040 + 121 
        call draw_gameover

        mov ah, 4ch
        xor al, al
        int 21h

draw_score:
    mov ax, [score1]  ; Load the integer into AX
    mov dx, window_width*score_yoffset + score_xoffset
    
    call get_score

    mov ax, [score2]  ; Load the integer into AX
    mov dx, window_width*score_yoffset + score_xoffset + ((7*4) + (letter_space_size*4)) + (thousand_space_size - letter_space_size)
    
    call get_score
    
    mov word [digits_counter], 2
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
    cmp al, 0
    je get_letter._0
    cmp al, 1
    je get_letter._1
    cmp al, 2
    je get_letter._2
    cmp al, 3
    je get_letter._3
    cmp al, 4
    je get_letter._4
    cmp al, 5
    je get_letter._5
    cmp al, 6
    je get_letter._6
    cmp al, 7
    je get_letter._7
    cmp al, 8
    je get_letter._8
    cmp al, 9
    je get_letter._9
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


    .drawing_highscore:
        mov ax, [highscore1]  ; Load the integer into AX
        mov dx, window_width*highscore_yoffset + highscore_xoffset
        
        call get_score

        mov ax, [highscore2]  ; Load the integer into AX
        mov dx, window_width*highscore_yoffset + highscore_xoffset + ((7*4) + (letter_space_size*4)) + (thousand_space_size - letter_space_size)
        
        call get_score

        mov word [digits_counter], 2
        ret

draw_life:

    cmp byte [life_count], 3
    jb .empty_life_3
    mov si, right_closed
    jmp .draw_life_3

        .empty_life_3:
            mov si, clean
            jmp .draw_life_3

        .draw_life_3:
            mov di, (window_width*life_yoffset - 16) - (life_xoffset)
            call draw_sprite

    .second_life:
        cmp byte [life_count], 2
        jb .empty_life_2
        mov si, right_closed
        jmp .draw_life_2

        .empty_life_2:
            mov si, clean
            jmp .draw_life_2

        .draw_life_2:
            mov di, (window_width*life_yoffset - 16) - (life_xoffset + 18)
            call draw_sprite

    .first_life:
        jb .empty_life_1
        mov si, right_closed
        jmp .draw_life_1

        .empty_life_1:
            mov si, clean
            jmp .draw_life_1

        .draw_life_1:
            mov di, (window_width*life_yoffset - 16) - (life_xoffset + 36)
            call draw_sprite
    ret


get_score:
    mov cx, 10        ; Set divisor to 10
    mov si, 0         ; Initialize index for digits array
    push dx
    .extract_digits:
        xor dx, dx        ; Clear DX for the division
        div cx            ; Divide AX by 10, result in AX, remainder in DX

        add dl, '0'       ; Convert the remainder to ASCII
        mov [digits + si], dl ; Store the digit in the array

        inc si            ; Move to the next index in the array

        test ax, ax       ; Check if quotient is zero
        jnz .extract_digits ; If not, continue extracting digits

        ; Add a null terminator at the end of the string
        mov byte [digits + 4], 0

        mov si, 0        ; Reset si to index the 'digits' array
        mov di, 4

        .reverse_digits:
            cmp si, di
            jge .done_reversing

            mov al, [digits + si]
            mov ah, [digits + di]

            mov [digits + si], ah
            mov [digits + di], al

            inc si
            dec di
            jmp .reverse_digits

        .done_reversing:

        ; Display each reversed digit
        mov si, 1         ; set si to index 1 to skip the 0 in the 'digits' array

        pop dx
        mov bx, 4
        mov cx, 0
    .display_digits:
        mov al, [digits + si]
        push bx
        push si
        push dx
        push cx
        call get_letter
        pop cx
        pop dx
        mov di, dx

        inc cx
        cmp cx, [digits_counter]
        jae .thousand_space

        .regular_space:
            mov bx, letter_space_size
            jmp .skip
        .thousand_space:
            mov bx, thousand_space_size
            xor cx, cx
            cmp word [digits_counter], 1
            ja .skip
            mov word [digits_counter], 10
        .skip:
            add bx, 7
    
        add dx, bx
        push dx
        push cx
        call draw_letter
        pop cx
        pop dx
        pop si
        pop bx

        inc si
        dec bx
        cmp bx, 0
        jne .display_digits ; Repeat for all digits

        dec word [digits_counter]
        call reset_digits
    ret

reset_digits:
    mov si, digits
    mov cx, 5
    .resetting_loop:
    mov byte [si], 0 ; Set the byte at the current index to zero
    inc si           ; Move to the next byte
    loop .resetting_loop
    ret

add_score:
    mov si, [score2]
    add si, bx

    .compare_10k:
        cmp si, 9999
        ja .sub_10k
        jmp .skip

    .sub_10k:
        sub si, 10000
        inc word [score1]
        jmp .compare_10k
    .skip:
        mov [score2], si

    ret

end_level:
    mov word [candies_remain], 270
    mov byte [life_count], 3

    mov si, clean
    mov di, [xPos]
    call draw_sprite

    mov word [xPos], window_width*80+(window_width-16)/2

    call DrawCheckMark
    call drawDot

    jmp _start.spawn_entities