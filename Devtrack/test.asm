org 100h

; -----------------------------------------------
; We declare some initialized data.
section .data
    yes db '1',13,10,'$'   ; DOS printable string must be terminated by a dollar sign.
    no db '0',13,10,'$'
    end db 'end$'
    

; -----------------------------------------------
; This section host code.
section .text

mov eax, 0b100100100   ; init byte
mov bx,  0b00000000
mov cl,9

jmp reverse

ShiftCheck:
shr ax, 1
jc yesm

jmp nom


yesm:
    inc cl
    ; Print the message to the screen
    mov ah, 9       ; AH=9 means "print string" function
    mov dx, yes   ; Load the offset address of 'hello' into DX
    int 21h         ; Call the DOS interrupt 21h to execute the function
    
    cmp cl, 8
    jb ShiftCheck

    jmp endm

nom:
    inc cl
; Print the message to the screen
    mov ah, 9       ; AH=9 means "print string" function
    mov dx, no   ; Load the offset address of 'hello' into DX
    int 21h         ; Call the DOS interrupt 21h to execute the function

    cmp cl, 8
    jb ShiftCheck
    
    jmp endm

endm:
; Print the message to the screen
    mov ah, 9       ; AH=9 means "print string" function
    mov dx, end   ; Load the offset address of 'hello' into DX
    int 21h         ; Call the DOS interrupt 21h to execute the function

    ; Exit the program
    mov ah, 4Ch     ; AH=4Ch means "exit" function
    xor al, al      ; Set AL to 0 (return code)
    int 21h         ; Call the DOS interrupt 21h to exit the program


  
  

reverse:
mov cx,0b00000001
dec cl
shr eax, 1
jc reverseTrue

cmp cl,0
jg reverse

jmp ShiftCheck
reverseTrue:
shl cx,cl
add ax, cx

cmp cl,0
jg reverse

