org 100h

; -----------------------------------------------
; We declare some initialized data.
section .data
    truem db '1',13,10,'$'   ; true and false message.
    falsem db '0',13,10,'$'
    end db 'end$'
    

; -----------------------------------------------
; This section host code.
section .text

mov eax, 0b100100100   ; init byte
mov bx,  0b00000000 
mov cl,9 ;counter

jmp reverse

ShiftCheck:
shr ax, 1 ;check 
jc True ;if carry is set, jump to True

jmp False ;else jump to False


True:
    inc cl
    mov ah, 9       
    mov dx, truem   ; print "1"
    int 21h         
    
    cmp cl, 8
    jb ShiftCheck ;if byte is not finished continue the loop, else jump to end

    jmp endm

False:
    inc cl
    mov ah, 9       
    mov dx, falsem   ; print "0"
    int 21h       

    cmp cl, 8
    jb ShiftCheck ;if byte is not finished continue the loop, else jump to end
    
    jmp endm

endm:
    mov ah, 9       
    mov dx, end   ; print "end"
    int 21h         

    ; Exit the program
    mov ah, 4Ch     
    xor al, al      
    int 21h       


  
  

reverse:
mov cx,0b00000001 ; this is the result of future operations
dec cl
shr eax, 1
jc reverseTrue ;if the carry is set, jump, else continue the loop

cmp cl,0
jg reverse ;if the byte is not finished conitnue, else go to "ShiftCheck"

jmp ShiftCheck
reverseTrue:
shl cx,cl ; shift until the position of the bit
add ax, cx; add the bit to the result

cmp cl,0
jg reverse ;if the byte is not finished conitnue, else go to "ShiftCheck"

