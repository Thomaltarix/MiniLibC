SECTION .text           ; Code section
GLOBAL strcspn          ; export "strcspn"

strcspn:
        ENTER 0, 0          ; Prolog
        CALL strlen         ; Call strlen to get length of first string
        XOR RCX, RCX        ; Initialize first counter
        MOV RDX, RAX        ; Move length of first string to RDX
        MOV R9, 0           ; Initialize second counter
        JMP .loop            ; Jump to loop

        .loop:
                CMP BYTE [RDI], 0               ; Check for null terminator
                JE .end                 ; If null terminator, return length of string
                JMP .compare                    ; Jump to compare

        .compare:
                CMP BYTE [RSI + RCX], 0         ; Check for null terminator
                JE .next                        ; If null terminator, return length of string
                MOV R8B, BYTE [RSI + RCX]       ; Load character from second string
                CMP BYTE [RDI], R8B             ; Compare c from first string with c from second string
                JE .found                       ; If equal, return length of string
                INC RCX                         ; Increment first counter
                JMP .compare

        .next:
                INC R9                          ; Increment second counter
                INC RDI                         ; Increment pointer to second string
                MOV RCX, 0                      ; Reset first counter
                JMP .loop                        ; Jump to loop

        .found:
                MOV RAX, R9                     ; Return length of string
                LEAVE                           ; Epilog
                RET                             ; Return

        .end:
                MOV RAX, RDX                    ; Return length of string
                LEAVE                           ; Epilog
                RET                             ; Return

strlen:
        ENTER 0, 0          ; Starts the program
        MOV RCX, 0          ; Initializes the counter

        .loop_strlen:
                CMP BYTE [RDI + RCX], 0         ; Checks if the character is null
                JE .end_strlen                  ; True -> jumps to the end
                INC RCX                         ; False -> increments the length = the result
                JMP .loop_strlen                ; Jumps to the loop

        .end_strlen:
                MOV RAX, RCX                    ; Moves the length to RAX
                LEAVE                           ; Ends the program
                RET                             ; Returns the length of the string
