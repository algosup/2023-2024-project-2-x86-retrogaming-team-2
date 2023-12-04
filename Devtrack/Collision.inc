org 100h

section .data

    colorWall dw 0x06                        ; color of the walls

section .text

; get the color of of pixel
; color in al

getColor:
    ; mov ah, 0CH               ; draw the points
    ; mov al, 0DH
    ; int 10h
    mov ah, 0DH                             ; AH = 0Dh for "Read Dot" function
    int 0x10

    ; color of the pixel in al
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