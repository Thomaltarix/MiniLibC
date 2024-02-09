BITS 64                 ; 64-bit mode
SECTION .text           ; Code section
GLOBAL memset        ; export "memset"

memset:
        ENTER 0, 0      ; starts the program
        MOV RCX, RDX    ; Move the value of RDX into RCX
        MOV RAX, RDI    ; Move the value of RDI into RAX

        .loop:
                CMP RCX, 0      ; If RCX is 0, we are done
                JE .done
                MOV BYTE [RDI], SIL ; Set the memory at RDI to the value of SIL
                INC RDI         ; Increment RDI
                DEC RCX         ; Decrement RCX
                JMP .loop       ; Repeat the loop

        .done:
                LEAVE           ; Clean up the stack
                RET             ; Return to the caller
