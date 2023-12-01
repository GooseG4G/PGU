	global _start
section .text
_start:
	; Вывод приглашения
	mov     rax, 1                  ; номер функции (1 - write)
    	mov     rdi, 1                  ; номер файла (1 - stdout)
    	mov     rsi, in_prompt          ; адрес строки для вывода
    	mov     rdx, in_prompt_len      ; длина строки
    	syscall
    	
    	; Прослушивание ввода
    	mov     rax, 0                  ; номер функции (0 - read)
    	mov     rdi, 0                  ; номер файла (0 - stdin)
    	mov     rsi, buffer             ; адрес буфера для чтения
    	mov     rdx, 255            	; максимальная длина для чтения 255
    	syscall
    	
    	; Вывод приглашения
	mov     rax, 1                  ; номер функции (1 - write)
    	mov     rdi, 1                  ; номер файла (1 - stdout)
    	mov     rsi, out_prompt         ; адрес строки для вывода
    	mov     rdx, out_prompt_len     ; длина строки
    	syscall
    	
    	; Вывод введенного сообщения
    	mov     rax, 1                  ; номер функции (1 - write)
    	mov     rdi, 1                  ; номер файла (1 - stdout)
    	mov     rsi, buffer             ; адрес строки для вывода
    	mov     rdx, 255    ; длина строки
    	syscall
    	
    	mov rax, 60 ; номер функции, 60 - exit
	mov rdi, 0 ; код завершения программы
	syscall
    	
section .data
in_prompt: 
	DB "input message: ", 0xa
in_prompt_len EQU $ - in_prompt
out_prompt:
	DB "your message: ", 0xa
out_prompt_len EQU $ - out_prompt

; Резервируем память для вводимого сообщения 
section .bss
    	buffer:     resb 256
