BITS 64                 ; 64-bit mode
SECTION .text           ; Code section
GLOBAL strpbrk           ; export "strpbrk"
strpbrk:
        ENTER 0, 0      ; Prolog
        MOV RCX, 0      ; Initialize counter
        CMP RSI, 0      ; Check for NULL pointer
        JE .not_found   ; If NULL, return NULL
        JMP .loop       ; Jump to loop

        .loop:
                CMP BYTE [RDI], 0 ; Check for null terminator
                JE .not_found           ; If null terminator, return NULL
                JMP .compare           ; Jump to compare

        .compare:
                CMP BYTE [RSI + RCX], 0 ; Check for null terminator
                JE .next               ; If null terminator, jump to next
                MOV R8B, BYTE [RSI + RCX] ; Load character from second string
                CMP BYTE [RDI], R8B ; Compare character
                JE .exit              ; If equal, jump to exit
                INC RCX               ; Increment counter
                JMP .compare          ; Jump to compare

        .next:
                INC RDI                 ; Increment pointer to character
                XOR RCX, RCX            ; Reset first counter
                JMP .loop               ; Jump to loop

        .not_found:
                MOV RAX, 0              ; Return NULL
                LEAVE                   ; Epilog
                RET                     ; Return

        .exit:
                MOV RAX, RDI          ; Return pointer to character
                LEAVE                 ; Epilog
                RET                   ; Return
