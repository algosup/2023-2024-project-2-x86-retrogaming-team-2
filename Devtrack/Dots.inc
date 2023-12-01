org 100h

%define firstLine 40*window_width+16
%define secondLine firstLine+(320*8)
%define thirdLine firstLine+(320*16)
%define fourthLine firstLine+(320*24)
%define fifthLine firstLine+(320*32)
%define sixthLine firstLine+(320*40)
%define seventhLine firstLine+(320*48)
%define eightLine firstLine+(320*56)
%define ninthLine firstLine+(320*64)
%define tenthLine firstLine+(320*72)
%define eleventhLine firstLine+(320*80)
%define twelfthLine firstLine+(320*88)
%define thirteenthLine firstLine+(320*96)
%define fourteenthLine firstLine+(320*104)
%define fifteenthLine firstLine+(320*112)
%define sixteenth firstLine+(320*120)
%define seventeenth firstLine+(320*128)
%define eighteenth firstLine+(320*136)
%define nineteenth firstLine+(320*144)

section .dina

    Dots_pos    dw firstLine, firstLine+ 8, firstLine+ 16, firstLine+ 24, firstLine+ 32, firstLine+ 40, firstLine+ 48, firstLine+ 56 
                dw firstLine+ 64, firstLine+ 72, firstLine+ 80, firstLine+ 88, firstLine+ 96, firstLine+ 104, firstLine+ 112, firstLine+ 120 
                dw firstLine+ 168, firstLine+ 176, firstLine+ 184, firstLine+ 192, firstLine+ 200, firstLine+ 208, firstLine+ 216, firstLine+ 224
                dw firstLine+ 232, firstLine+ 240, firstLine+ 248, firstLine+ 256, firstLine+ 264, firstLine+ 272, firstLine+ 280, firstLine+ 288 
                ; 2nd line
                dw secondLine, secondLine+ 96, secondLine+ 120, secondLine+ 168, secondLine+ 192, secondLine+ 288
                ; 3rd line
                dw thirdLine, thirdLine+ 96, thirdLine+ 120, thirdLine+128, thirdLine+136, thirdLine+ 144, thirdLine+ 152, thirdLine+ 160, thirdLine+ 168, thirdLine+ 192, thirdLine+ 288 
                ; 4th line
                dw fourthLine, fourthLine+ 8, fourthLine+ 24, fourthLine+ 32, fourthLine+ 40, fourthLine+ 48, fourthLine+ 56 
                dw fourthLine+ 64, fourthLine+ 72, fourthLine+ 80, fourthLine+ 88, fourthLine+ 96, fourthLine+ 120 
                dw fourthLine+168, fourthLine+192, fourthLine+ 200, fourthLine+ 208, fourthLine+ 216, fourthLine+ 224
                dw fourthLine+ 232, fourthLine+ 240, fourthLine+ 248, fourthLine+ 256, fourthLine+ 264, fourthLine+ 280, fourthLine+ 288 
                ; 5th line
                dw fifthLine, fifthLine+ 40, fifthLine+ 120, fifthLine+ 168, fifthLine+ 248, fifthLine+ 288   
                ; 6th line
                dw sixthLine, sixthLine+ 40, sixthLine+ 120, sixthLine+ 168, sixthLine+ 248, sixthLine+ 288 
                ; 7th line
                dw seventhLine, seventhLine+ 8, seventhLine+ 16, seventhLine+ 40, seventhLine+ 48, seventhLine+ 56, seventhLine+ 64, seventhLine+ 72, seventhLine+ 80 
                dw seventhLine+ 88, seventhLine+ 96, seventhLine+ 104, seventhLine+ 112, seventhLine+ 120 
                dw seventhLine+ 168, seventhLine+ 176, seventhLine+ 184, seventhLine+ 192, seventhLine+ 200, seventhLine+ 208, seventhLine+ 216,
                dw seventhLine+ 224, seventhLine+ 232, seventhLine+ 240, seventhLine+ 248, seventhLine+ 272, seventhLine+ 280, seventhLine+ 288 
                ; 8th line
                dw eightLine+ 16, eightLine+ 72, eightLine+ 96, eightLine+ 192, eightLine+ 216, eightLine+ 272 
                ; 9th line
                dw ninthLine+ 16, ninthLine+ 72, ninthLine+ 96, ninthLine+ 192, ninthLine+ 216, ninthLine+ 272
                ; 11th line
                dw tenthLine+ 16, tenthLine+40 , tenthLine+ 48, tenthLine+ 56, tenthLine+ 64, tenthLine+ 72, tenthLine+ 80, tenthLine+ 88, tenthLine+ 96
                dw tenthLine+ 192, tenthLine+ 200, tenthLine+ 208, tenthLine+ 216, tenthLine+ 224, tenthLine+ 232, tenthLine+ 240, tenthLine+ 248, tenthLine+ 272
                ; 12th line
                dw eleventhLine+ 16, eleventhLine+ 40, eleventhLine+ 96, eleventhLine+ 192, eleventhLine+ 248, eleventhLine+ 272
                dw twelfthLine+ 16, twelfthLine+ 40, twelfthLine+ 96, twelfthLine+ 192, twelfthLine+ 248, twelfthLine+ 272
                ; 13th line
                dw thirteenthLine, thirteenthLine+ 8, thirteenthLine+ 16, thirteenthLine+ 40, thirteenthLine+ 48, thirteenthLine+ 56, thirteenthLine+ 64, thirteenthLine+ 72
                dw thirteenthLine+ 80, thirteenthLine+ 88, thirteenthLine+ 96, thirteenthLine+ 192, thirteenthLine+ 200, thirteenthLine+ 208, thirteenthLine+ 216
                dw thirteenthLine+ 224, thirteenthLine+ 232, thirteenthLine+ 240, thirteenthLine+ 248, thirteenthLine+ 272, thirteenthLine+ 280, thirteenthLine+ 288 
                ; 14th line
                dw fourteenthLine, fourteenthLine+ 40, fourteenthLine+ 96, fourteenthLine+ 104, fourteenthLine+ 112, fourteenthLine+ 120, fourteenthLine+ 168, fourteenthLine+ 176;start 14th line
                dw fourteenthLine+ 184, fourteenthLine+ 192, fourteenthLine+ 248, fourteenthLine+ 288
                ; 15th line
                dw fifteenthLine, fifteenthLine+ 40, fifteenthLine+ 96, fifteenthLine+ 120,fifteenthLine+ 168, fifteenthLine+ 192, fifteenthLine+ 248, fifteenthLine+ 288
                ; 16th line
                dw sixteenth, sixteenth+ 24, sixteenth+ 32, sixteenth+ 40, sixteenth+ 48, sixteenth+ 56, sixteenth+ 64, sixteenth+ 72, sixteenth+ 80, sixteenth+ 88
                dw sixteenth+ 96, sixteenth+ 120, sixteenth+ 168, sixteenth+ 192, sixteenth+ 200, sixteenth+ 208, sixteenth+ 216, sixteenth+ 224, sixteenth+ 232
                dw sixteenth+ 240, sixteenth+ 248, sixteenth+ 256, sixteenth+ 264, sixteenth+ 288
                ; 17th line
                dw seventeenth, seventeenth+ 48, seventeenth+ 120,seventeenth+ 128,seventeenth+ 136,seventeenth+ 144,seventeenth+ 152,seventeenth+ 160, seventeenth+ 168, seventeenth+ 240, seventeenth+ 288
                ; 18th line
                dw eighteenth, eighteenth+ 48, eighteenth+ 120, eighteenth+ 168, eighteenth+ 240, eighteenth+ 288
                ; 19th line
                dw nineteenth, nineteenth+ 8, nineteenth+ 16, nineteenth+ 24, nineteenth+ 40, nineteenth+ 48, nineteenth+ 56 
                dw nineteenth+ 64, nineteenth+ 72, nineteenth+ 80, nineteenth+ 88, nineteenth+ 96, nineteenth+ 104, nineteenth+ 112, nineteenth+ 120 
                dw nineteenth+ 168, nineteenth+ 176, nineteenth+ 184, nineteenth+ 192, nineteenth+ 200, nineteenth+ 208, nineteenth+ 216, nineteenth+ 224
                dw nineteenth+ 232, nineteenth+ 240, nineteenth+ 248, nineteenth+ 264, nineteenth+ 272, nineteenth+ 280, nineteenth+ 288 




section .text:
    drawDot:
        mov ax, 0xA000
        mov cx,0
        mov si, Dots_pos
        mov es,ax
        mov di,[si]
        mov al, 0x43

        DrawDotLoop:
        
        mov [es:di], al

        inc di
        mov [es:di], al
        


        call .newLine

        add si,2 ; add 2 because idk why index need to be multiplied by 2
        mov di, [si]


        inc cx
        cmp cx,270
        jb DrawDotLoop
   



    jmp _start.spawn_entities


    .newLine:
        add di, window_width
        add di, -1
        mov [es:di], al
        inc di
        mov [es:di], al
        ret