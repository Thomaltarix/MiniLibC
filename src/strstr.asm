BITS 64                 ; 64-bit mode
SECTION .text           ; Code section
GLOBAL strstr           ; export "strstr"

strstr:
        ENTER 0, 0      ; Prologue

        .loop:          ; Loops to find the first character of needle
                CMP BYTE [RDI], 0       ; Check if the string is empty
                JE .not_found           ; If it is, return NULL
                CMP BYTE [RSI], 0       ; Check if the needle is empty
                JE .done                ; If it is, jump to the done label
                CMP BYTE [RDI], [RSI]   ; Check the first character of needle with the current character of haystack
                JE .found               ; If they are equal, jump to the found label

        .not_found:
                MOV RAX, 0              ; Return NULL
                LEAVE                   ; Epilogue
                RET                     ; Return

        .done:
                MOV RAX, RDI            ; Return the position of the first character of needle
                LEAVE                   ; Epilogue
                RET                     ; Return

        .next:          ; Passes to the next occurent of the first character of needle
                MOV RDI, RDX            ; Move the haystack pointer to the next character
                INC RDI                 ; Increment the pointer
                JMP .loop               ; Jump to the loop label