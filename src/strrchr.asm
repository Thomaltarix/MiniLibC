BITS 64                 ; 64-bit mode
SECTION .text           ; Code section
GLOBAL strrchr, rindex        ; export "strrchr"

rindex:
strrchr:
        ENTER 0, 0       ; starts the program
        MOV RCX, 0      ; Initializes the counter

        .start_loop:
                CMP BYTE [RDI + RCX], 0       ; Checks if it's the end of the string
                JE .go_to_loop         ; True -> jump to the go_to_loop
                INC RCX                 ; Increments the counter
                JMP .start_loop         ; Jumps to itself

        .go_to_loop:
                CMP SIL, 0              ; Checks if it's the end of the string
                JE .found               ; True -> jump to the found
                DEC RCX                 ; Decrements the counter
                JMP .loop               ; Jumps to the loop

        .loop:              ; loop to find the c character
                CMP BYTE [RDI + RCX], 0       ; Checks if it's the end of the string
                JE .not_found           ; True -> jump to the end
                CMP BYTE [RDI + RCX], SIL     ; Checks if the caracters of s is c
                JE .found               ; True -> jump to the found
                DEC RCX                 ; Decrements the counter
                JMP .loop               ; Jumps to itself

        .found:
                CMP RCX, 0              ; Checks if it's the first character
                JE .end                 ; True -> jump to the end
                INC RDI                 ; Increments the pointer
                DEC RCX                 ; Decrements the counter
                JMP .found              ; Jumps to itself

        .end:                ; End of the program
                MOV RAX, RDI            ; Moves the pointer found to RAX
                LEAVE                   ; Ends the program
                RET                     ; Returns

        .not_found:          ; Not found
                MOV RAX, 0              ; Moves 0 to RAX
                LEAVE                   ; Ends the program
                RET                     ; Returns
