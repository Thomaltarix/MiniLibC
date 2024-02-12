BITS 64                 ; 64-bit mode
SECTION .text           ; Code section
GLOBAL strrchr        ; export "strrchr"

strrchr:
        ENTER 0, 0       ; starts the program

        .start_loop:
                CMP BYTE [RDI + 1], 0       ; Checks if it's the end of the string
                JE .loop                ; True -> jump to the loop
                INC RDI                 ; Increments the pointer
                JMP .start_loop         ; Jumps to itself

        .loop:              ; loop to find the c character
                CMP BYTE [RDI], 0       ; Checks if it's the end of the string
                JE .not_found           ; True -> jump to the end
                CMP BYTE [RDI], SIL     ; Checks if the caracters of s is c
                JE .end                 ; True -> jump to the end
                DEC RDI                 ; Decrements the pointer
                JMP .loop               ; Jumps to itself

        .end:                ; End of the program
                MOV RAX, RDI            ; Moves the pointer found to RAX
                LEAVE                   ; Ends the program
                RET                     ; Returns

        .not_found:          ; Not found
                MOV RAX, 0              ; Moves 0 to RAX
                LEAVE                   ; Ends the program
                RET                     ; Returns
