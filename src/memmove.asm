BITS 64                 ; 64-bit mode
SECTION .text           ; Code section
GLOBAL memmove          ; export "memmove"

memmove:
        ENTER 0, 0       ; Prolog
        MOV RAX, RDI     ; Copy dest to RAX
        XOR RCX, RCX     ; Initialize counter to 0

        .loop:
                CMP RSI, RDI    ; Compare src with dest
                JE .done        ; If equal, we're done
                JG .forward     ; If src > dest, jump to forward
                MOV RCX, RDX    ; If src > dest, set counter to length
                JL .backward    ; If src < dest, jump to backward

        .forward:
                CMP RCX, RDX    ; Compare counter with length
                JE .done        ; If counter is 0, we're done
                MOV R8B, BYTE [RSI + RCX] ; Move byte from src to R8B
                MOV BYTE [RDI + RCX], R8B ; Move byte from R8B to dest
                INC RCX         ; Increment counter
                JMP .forward    ; Jump to forward

        .backward:
                CMP RCX, 0      ; Compare counter with 0
                JE .done        ; If counter is 0, we're done
                MOV R8B, BYTE [RSI + RCX - 1] ; Move byte from src to R8B
                MOV BYTE [RDI + RCX - 1], R8B ; Move byte from R8B to dest
                DEC RCX         ; Decrement counter
                JMP .backward   ; Jump to backward

        .done:
                LEAVE           ; Epilog
                RET             ; Return
