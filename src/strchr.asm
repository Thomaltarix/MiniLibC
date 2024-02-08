BITS 64                 ; 64-bit mode
SECTION .text           ; Code section
GLOBAL strchr        ; export "strchr"

strchr:
        ENTER 0,0           ; starts the program

        .loop:              ; loop to find the c character
                CMP BYTE [RDI], 0       ; Checks if it's the end of the string
                JE .not_found           ; True -> jump to the end
                CMP BYTE [RDI], SIL     ; Checks if the caracters of s is c
                JE .end                 ; True -> jump to the end
                INC RDI                 ; Increments the pointer
                JMP .loop               ; Jumps to itself

        .end:                ; End of the program
                MOV RAX, RDI            ; Moves the pointer found to RAX
                LEAVE                   ; Ends the program
                RET                     ; Returns

        .not_found:          ; Not found
                MOV RAX, 0              ; Moves 0 to RAX
                LEAVE                   ; Ends the program
                RET                     ; Returns