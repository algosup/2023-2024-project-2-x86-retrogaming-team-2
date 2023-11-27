section .data
    bitArray db 0b10101010, 0b01010101, 0b11110000, 0b00001111, 0b11001100  ; 5-byte bit array

section .text
    org 100h

start:
    mov ax, 0xA000  ; Video memory segment address (for text color)
    mov es, ax
    xor di, di  ; Start of the screen

    lea si, [bitArray]  ; Pointer to the bit array
    mov cx, 40     ; Total number of bits in the array (5 bytes x 8 bits per byte)

loop_start:
    lodsb     ; Load a byte from the array
    mov dl, al  ; Copy the byte to register DL

bit_loop:
    mov ah, 2  ; Character display function

    and dl, 0b10000000  ; Test the most significant bit
    ; test dl, 0b10000000
    ; cmp dl, 0
    jz zero    ; Jump to the 'zero' label if the bit is 0

    ; Display '1' if the bit is 1
    mov dx, '1'
    int 21h

    jmp next_bit  ; Jump to the 'next_bit' label

zero:
    ; Display '0' if the bit is 0
    mov dx, '0'
    int 21h

next_bit:
    shr dl, 1  ; Shift one bit to the left
    loop bit_loop  ; Repeat until all bits are traversed

    ; New line
    mov dx, 0Ah
    int 21h

exit:
    mov ax, 4C00h  ; Program exit function
    int 21h       ; System call to exit the program
