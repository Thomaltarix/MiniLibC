BITS 64                 ; 64-bit mode
SECTION .text           ; Code section
GLOBAL memmove          ; export "memmove"


memmove:
        ENTER 0, 0              ; Prolog
        MOV RCX, 0              ; Initialize counter
        JMP .push_rsi           ; Jump to .push_rsi

        .push_rsi:
                CMP RCX, RDX                    ; Compare counter with len
                JE .pop_rsi                     ; If equals -> jump to .pop_rsi
                MOV R8B, BYTE [RSI + RCX]       ; Move byte from src to R8B
                PUSH R8                         ; Push byte to stack
                INC RCX                         ; Increment counter
                JMP .push_rsi                   ; Loop

        .pop_rsi:
                CMP RCX, 0                      ; Compare counter with 0
                JE .exit                        ; If equals -> jump to .exit
                POP R8                          ; Pop byte from stack
                DEC RCX                         ; Decrement counter
                MOV BYTE [RDI + RCX], R8B       ; Move byte from R8B to dest
                JMP .pop_rsi                    ; Loop

        .exit:
                MOV RAX, RDI                    ; Return dest
                LEAVE                           ; Epilog
                RET                             ; Return
