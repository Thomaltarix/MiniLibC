BITS 64                 ; 64-bit mode
SECTION .text           ; Code section
GLOBAL memmove          ; export "memmove"


memmove:
        ENTER 0, 0              ; Prologue
        XOR RCX, RCX            ; Initialize counter
        JMP .check_null         ; Jump to check for null pointers

        .loop:
                CMP RDX, RCX            ; Compare counter with length
                JE .end                 ; Jump to end if equal
                MOV R8B, [RSI + RCX]   ; Move byte from source to R8B
                MOV [RDI + RCX], R8B   ; Move byte from R8B to destination
                INC RCX                 ; Increment counter
                JMP .loop               ; Jump to loop

        .check_null:
                CMP RDI, 0              ; Check if destination pointer is null
                JE .end                 ; Jump to end if null
                CMP RSI, 0              ; Check if source pointer is null
                JE .end                 ; Jump to end if null
                JMP .loop               ; Jump to compare if not null

        .end:
                MOV RAX, RDI            ; Return destination pointer
                LEAVE                   ; Epilogue
                RET                     ; Return