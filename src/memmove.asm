BITS 64                 ; 64-bit mode
SECTION .text           ; Code section
GLOBAL memmove          ; export "memmove"

memmove:
        ENTER 0,0       ; Prologue
        MOV RCX, 0      ; Initialize counter
        MOV R8, RDI     ; Save destination pointer

        .get_string:    ; Get copy of source
                CMP RCX, RDX                    ; Compare counter with length
                JE .set_string                  ; If equal, the string is copied
                MOV R9B, [RSI + RCX]            ; Move byte from source to destination
                MOV BYTE [R8 + RCX], R9B        ; Move byte from source to destination
                INC RCX                         ; Increment counter
                JMP .get_string                 ; Jump to loop

        .set_string:    ; Set the dest to the copy of the source
                XOR RCX, RCX                    ; Reset counter
                CMP RCX, RDX                    ; Compare counter with length
                JE .end                         ; If equal, jump to end
                MOV R9B, [R8 + RCX]             ; Move byte from source to destination
                MOV BYTE [RAX + RCX], R9B       ; Move byte from source to destination
                INC RCX                         ; Increment counter
                JMP .set_string                 ; Jump to set_string

        .end:
                LEAVE                           ; Epilogue
                RET                             ; Return
