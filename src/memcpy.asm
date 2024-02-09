BITS 64                 ; 64-bit mode
SECTION .text           ; Code section
GLOBAL memcpy        ; export "memcpy"

memcpy:
        ENTER 0, 0      ; Prolog
        MOV RCX, RDX    ; Copy length to RCX
        MOV RAX, RDI    ; Copy source to RAX

        .loop:
                CMP RCX, 0      ; If length is 0, we're done
                JE .done
                MOV BYTE [RSI], R8B ; Copy the byte to a tmp register
                MOV BYTE [RDI], R8B ; Copy the byte to the destination
                INC RDI         ; Move source pointer
                INC RSI         ; Move destination pointer
                DEC RCX         ; Decrement length
                JMP .loop       ; Repeat

        .done:
                LEAVE           ; Epilog
                RET             ; Return