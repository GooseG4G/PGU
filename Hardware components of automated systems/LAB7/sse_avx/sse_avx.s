%include "syscall.mac"
section .data
    sse_msg db "SSE is supported!", 0xA, 0
    not_sse_msg db "SSE is not supported!", 0xA, 0
    avx_msg db "AVX is supported!", 0xA, 0
    not_avx_msg db "AVX is not supported!", 0xA, 0

section .text
    global _start

_start:
    ; Получить флаги поддерживаемых функций
    mov eax, 1
    cpuid

    test edx, 1<<25 ; Проверить поддержку SSE
    jnz sse_supported
    WRITE not_sse_msg, 32, 1
    jmp check_avx

sse_supported:
    WRITE sse_msg, 32, 1

check_avx:
    test ecx, 1<<28 ; Проверить поддержку AVX
    jnz avx_supported
    WRITE not_avx_msg, 32, 1
    jmp end

avx_supported:
    WRITE avx_msg, 32, 1

end:
    EXIT 0