org 100h

section .data

    colorWall dw 0xff                      ; background of the walls

    ; Variables for the next positions
    nextPosTop dw xPos - window_width
    nextPosBot dw xPos + (window_width * 16)
    nextPosLef dw xPos - 1
    nextPosRig dw xPos + 20

section .text

; get the color of of pixel
; color in al
getColor:
    mov ah, 0Dh
    int 10h

    ret

; check the color of
; the top next pixel
; the bottom next pixel
; top: -320, bottom: +320, left: -1, right: +1

; compare the color with the sprite's black
compColor:

; block ranky from going through the wall
; block the movements 
blockRanky:

checkColor:
    ; Check the top pixel
    mov dx, nextPosTop
    call getColor
    cmp al, colorWall
    je exit 

    ; Check the bottom pixel
    mov dx, nextPosBot
    call getColor
    cmp al, colorWall
    je exit 

    ; Check the left pixel
    mov dx, nextPosLef
    call getColor
    cmp al, colorWall
    je exit 

    ; Check the right pixel
    mov dx, nextPosRig
    call getColor
    cmp al, colorWall
    je exit 

exit:
    mov ah, 4ch
    xor al, al
    int 21h
