BITS 64                 ; 64-bit mode
SECTION .text           ; Code section
GLOBAL strstr           ; export "strstr"

strstr:
        ENTER 0, 0      ; Prolog
        MOV RCX, 0      ; Initialize the counter
        MOV RDX, 0      ; Initialize the second counter
        JMP .loop

        .loop:
                CMP BYTE [RSI + RCX], 0         ; Check if the needle is empty
                JE .found                       ; If it is, jump to .found
                CMP BYTE [RDI + RDX], 0         ; Check if the haystack is empty
                JE .not_found                   ; If it is, jump to .notfound
                MOV R8B, BYTE [RSI + RCX]            ; Load the current character of the needle
                CMP BYTE [RDI + RDX], R8B       ; Compare it with the current character of the haystack
                JE .match                       ; If they are the same, jump to .match
                JNE .next                       ; If they are different, jump to .next

        .not_found:
                MOV RAX, 0                      ; Return 0
                LEAVE                           ; Epilogue
                RET

        .found:
                MOV RAX, RDI                    ; Return the address of the first occurrence of the needle
                LEAVE                           ; Epilogue
                RET

        .next:
                INC RDI                         ; Move to the next character of the haystack
                MOV RCX, 0                      ; Reset the counter
                MOV RDX, 0                      ; Reset the second counter
                JMP .loop                       ; Repeat the loop

        .match:
                INC RCX                         ; Move to the next character of the needle
                INC RDX                         ; Move to the next character of the haystack
                JMP .loop                       ; Repeat the loop