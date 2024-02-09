BITS 64                 ; 64-bit mode
SECTION .text           ; Code section
GLOBAL strrchr        ; export "strrchr"

strrchr:
        ENTER 0,0       ; starts the program
        CALL strlen     ; Calls the strlen function to get the length of the string
        MOV RCX, RAX    ; Moves the length to RCX

        .loop:          ; loop to find the last c character
                CMP RCX, 0      ; Checks if the length is 0
                JE .not_found        ; If it is 0, then it is the end of the string
                CMP BYTE [RDI + RCX - 1], SIL  ; Compares the last character with the character
                JE .found           ; If it is the same, then it is found
                DEC RCX             ; Decrements the length
                JMP .loop           ; Jumps to the loop

        .not_found:
                MOV RAX, 0      ; If the character is not found, return 0
                LEAVE           ; Ends the program
                RET

        .found:
                MOV RAX, RDI    ; If the character is found, return the pointer
                ADD RAX, RCX    ; Moves the pointer to the last character found
                DEC RAX     ; Moves the pointer to the last character found
                LEAVE           ; Ends the program
                RET

strlen:              ; Loops through the string to return its len
        ENTER 0, 0              ; Starts the program
        MOV RCX, 0              ; Initializes the counter

        .loop:                  ; Loop which checks if the character is null or not
                CMP BYTE [RDI], 0       ; Checks if the character is null
                JE .end                 ; True -> jumps to the end
                INC RDI                 ; Increments the pointer
                INC RCX                 ; False -> increments the length = the result
                JMP .loop               ; Jumps to the loop

        .end:                   ; End of the program
                MOV RAX, RCX            ; Moves the length to RAX
                LEAVE                   ; Ends the program
                RET                     ; Returns the length of the string
