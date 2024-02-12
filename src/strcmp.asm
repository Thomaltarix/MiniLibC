BITS 64                 ; 64-bit mode
SECTION .text           ; Code section
GLOBAL strcmp        ; export "strcmp"

strcmp:
        ENTER 0, 0      ; Prologue
        MOV RCX, 0      ; Initialize counter
        XOR R8, R8      ; Clear R8
        XOR R9, R9      ; Clear R9

        .loop:
                MOV R8B, BYTE [RDI] ; Load byte from first string
                MOV R9B, BYTE [RSI] ; Load byte from second string
                CMP R8B, R9B        ; Compare bytes
                JE .are_equal           ; If not equal, jump to done
                MOV RAX, R8        ; Move byte to RAX
                SUB RAX, R9        ; Subtract second byte from first byte
                LEAVE               ; Epilogue
                RET                 ; Return

        .are_equal:
                CMP R8B, 0      ; Check for null terminator
                JE .exit        ; If null terminator, jump to exit
                INC RDI         ; Increment first string pointer
                INC RSI         ; Increment second string pointer
                JMP .loop       ; Jump to loop

        .exit:
                MOV RAX, RCX    ; Return counter
                LEAVE           ; Epilogue
                RET             ; Return
