BITS 64                 ; 64-bit mode
SECTION .text           ; Code section
GLOBAL memmove          ; export "memmove"

memmove:
        ENTER 0, 0       ; Prolog
        MOV RAX, RDI     ; Copy dest to RAX
        JMP .loop        ; Jump to loop

        .loop:
                CMP RSI, RDI    ; Compare src with dest
                JG .memcpy      ; If src > dest -> jump to memcpy
                CALL .memmove_stack   ; Else call memmove

        .memmove_stack:
                CALL memmove_stack ; call memmove_stack
                JMP .end        ; jump to end

        .memcpy:
                CALL memcpy     ; call memcpy
                JMP .end        ; jump to end

        .end:
                MOV RAX, RDI    ; return dest
                LEAVE           ; Epilog
                RET             ; Return

memmove_stack:
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

memcpy:
        ENTER 0, 0      ; Prolog
        MOV RCX, RDX    ; Copy length to RCX
        MOV RAX, RDI    ; Copy source to RAX

        .loop:
                CMP RCX, 0      ; If length is 0, we're done
                JE .done
                MOV R8B, BYTE [RSI]   ; Copy the byte to a tmp register
                MOV BYTE [RDI], R8B   ; Copy the byte to the destination
                INC RDI         ; Move source pointer
                INC RSI         ; Move destination pointer
                DEC RCX         ; Decrement length
                JMP .loop       ; Repeat

        .done:
                LEAVE           ; Epilog
                RET             ; Return
