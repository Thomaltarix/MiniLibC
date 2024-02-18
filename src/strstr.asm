BITS 64                 ; 64-bit mode
SECTION .text           ; Code section
GLOBAL strstr           ; export "strstr"

strstr:
        ENTER 0,0           ; starts the program
        MOV RDX, RSI        ; Moves the pointer of s to RDX

        .loop:              ; loop to find the c character
                MOV R8B, BYTE [RDX]          ; Moves the character of s to R8B
                CMP BYTE [RDI], R8B     ; Compares the character of s with the character of needle
                JNE .not_equal          ; If the characters are not equal, jump to .not_equal
                JE .equal               ; If the characters are equal, jump to .equal

        .not_equal:
                INC RDI                ; Increments the pointer of haystack
                JMP .loop              ; Jumps to the beginning of the loop

        .equal:
                MOV RCX, RDI           ; Moves the pointer of haystack to RCX
                INC RCX                ; Increments the pointer of haystack
                MOV RSI, RDX           ; Moves the pointer of s to RSI
                INC RSI                ; Increments the pointer of s
                JMP .compare           ; Jumps to .compare

        .compare:
                CMP BYTE [RCX], 0         ; Compares the character of haystack with the null character
                JE .end                    ; If the character is the null character, jump to .end
                CMP BYTE [RSI], 0         ; Compares the character of s with the null character
                JE .end                    ; If the character is the null character, jump to .end
                MOV R8B, BYTE [RSI]         ; Moves the character of s to R8B
                CMP BYTE [RCX], R8B         ; Compares the character of s with the character of needle
                JE .equal2                 ; If the characters are equal, jump to .equal2

        .equal2:
                INC RCX                ; Increments the pointer of haystack
                INC RSI                ; Increments the pointer of s
                JMP .compare           ; Jumps to the beginning of the loop

        .end:
                MOV RAX, RDI           ; Moves the pointer of haystack to RAX
                LEAVE                  ; Ends the program
                RET                    ; Returns the pointer of haystack