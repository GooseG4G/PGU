%include "syscall.mac"
global _start

section .text
_start:
    ; Вывод приглашения
    WRITE in_prompt, in_prompt_len, 1
    
    ; Прослушивание ввода
    READ buffer, 255, 0
    
    ; Вывод приглашения
    WRITE out_prompt, out_prompt_len, 1
    
    ; Вывод введенного сообщения
    WRITE buffer, 255, 1
    
    EXIT 0

section .data
in_prompt: 
    DB "input message: ", 0xa
in_prompt_len EQU $ - in_prompt

out_prompt:
    DB "your message: ", 0xa
out_prompt_len EQU $ - out_prompt

section .bss
    buffer: resb 256
