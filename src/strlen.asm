BITS 64                 ; 64-bit mode
SECTION .text           ; Code section
GLOBAL my_strlen        ; export "_start"

my_strlen:              ; Loops through the string to return its len
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
