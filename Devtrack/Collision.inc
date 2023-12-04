org 100h

section .data

    colorWall dw 0x06                        ; color of the walls

    ; Variables for the next positions
    nextPosTop dw xPos - window_width *2
    nextPosBot dw xPos + (window_width * 16)
    nextPosLef dw xPos - 1
    nextPosRig dw xPos + 16

section .text


; get the color of of pixel
; color in al
getColor:
    ; mov ah, 0ch
    ; mov al, 0dh
    ; mov dx, 111
    ; mov cx, 129
    ; int 10h
    ; mov bh, 1
    mov ah, 0DH  ; AH = 0Dh for "Read Dot" function
    mov cx, 129 ; CX = xPos for left
    mov dx, 111

    int 0x10

    cmp al, [colorWall]
    je blockRanky 

    ret

; checkColor:
;     ; Check the top pixel
;     mov dx, nextPosTop
;     call getColor
;     cmp al, colorWall
;     je blockRanky 

;     ; Check the bottom pixel
;     mov dx, nextPosBot
;     call getColor
;     cmp al, colorWall
;     je blockRanky 

;     ; Check the left pixel
;     mov dx, nextPosLef
;     call getColor
;     cmp al, colorWall
;     je blockRanky 

;     ; Check the right pixel
;     mov dx, nextPosRig
;     call getColor
;     cmp al, colorWall
;     je blockRanky 

; ; block ranky from going through the wall
; ; block the movements 
blockRanky:                                  ; exit code for the moment 
    mov ah, 4ch
    xor al, al
    int 21h