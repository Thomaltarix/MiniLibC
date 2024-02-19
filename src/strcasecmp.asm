BITS 64                 ; 64-bit mode
SECTION .text           ; Code section
GLOBAL strcasecmp        ; export "strcasecmp"

strcasecmp:
        ENTER 0, 0      ; Prologue
        MOV RCX, 0      ; Initialize counter
        XOR R8, R8      ; Clear R8
        XOR R9, R9      ; Clear R9

        .loop:
                MOV R8B, BYTE [RDI] ; Load byte from first string
                MOV R9B, BYTE [RSI] ; Load byte from second string
                JMP .check_case_1     ; Jump to check_case

        .check_case_1:
                CMP R8B, 'A'     ; Check if byte is lower case
                JL .check_case_2  ; If lower case, jump to check_case2
                CMP R8B, 'Z'     ; Check if byte is upper case
                JG .check_case_2  ; If upper case, jump to check_case2
                ADD R8B, 32      ; Convert upper case to lower case

        .check_case_2:
                CMP R9B, 'A'     ; Check if byte is lower case
                JL .cmp          ; If lower case, jump to cmp
                CMP R9B, 'Z'     ; Check if byte is upper case
                JG .cmp          ; If upper case, jump to cmp
                ADD R9B, 32      ; Convert upper case to lower case

        .cmp:
                CMP R8B, R9B        ; Compare bytes
                JE .are_equal           ; If not equal, jump to are_equal
                JNE .are_not_equal      ; If equal, jump to are_not_equal

        .are_equal:
                CMP R8B, 0      ; Check for null terminator
                JE .exit        ; If null terminator, jump to exit
                INC RDI         ; Increment first string pointer
                INC RSI         ; Increment second string pointer
                JMP .loop       ; Jump to loop


        .are_not_equal:
                MOV RAX, R8        ; Move byte to RAX
                SUB RAX, R9        ; Subtract second byte from first byte
                LEAVE               ; Epilogue
                RET                 ; Return

        .exit:
                MOV RAX, RCX    ; Return counter
                LEAVE           ; Epilogue
                RET             ; Return
