BITS 64                 ; 64-bit mode
SECTION .text           ; Code section
GLOBAL strncmp        ; export "strncmp"

strncmp:
        ENTER 0, 0      ; Prologue
        MOV RCX, 0      ; Initialize counter
        XOR R8, R8      ; Clear R8
        XOR R9, R9      ; Clear R9

        .loop:
                CMP RDX, RCX    ; Check if counter is equal to length
                JE .exit        ; If null terminator, jump to exit
                MOV R8B, BYTE [RDI + RCX] ; Load byte from first string
                MOV R9B, BYTE [RSI + RCX] ; Load byte from second string
                CMP R8B, R9B        ; Compare bytes
                JE .are_equal           ; If not equal, jump to are_equal
                MOV RAX, R8        ; Move byte to RAX
                SUB RAX, R9        ; Subtract second byte from first byte
                LEAVE               ; Epilogue
                RET                 ; Return

        .are_equal:
                CMP R8B, 0      ; Check for null terminator
                JE .exit        ; If null terminator, jump to exit
                INC RCX         ; Increment counter
                JMP .loop       ; Jump to loop

        .exit:
                MOV RAX, 0      ; Return 0
                LEAVE           ; Epilogue
                RET             ; Return
