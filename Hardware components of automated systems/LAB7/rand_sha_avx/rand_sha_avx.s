section .data
    rng_supported db "RNG TRUE", 0xA, 0
    rng_not_supported db "RNG FALSE", 0xA, 0
    aes_supported db "AES TRUE", 0xA, 0
    aes_not_supported db "AES FALSE", 0xA, 0
    sha_supported db "SHA TRUE", 0xA, 0
    sha_not_supported db "SHA FALSE", 0xA, 0

section .text
    extern printf

global main
main:
    ; Проверка наличия аппаратной генерации случайных чисел (RDRAND)
    mov eax, 1
    cpuid
    test ecx, 0x40000000 ; Проверка бита 30 в ecx
    jz rng_false_label
    mov rdi, rng_supported
    xor eax, eax
    call printf
    jmp check_aes

rng_false_label:
    mov rdi, rng_not_supported
    xor eax, eax
    call printf
    jmp check_aes

check_aes:
    ; Проверка AES
    mov eax, 1
    cpuid
    test ecx, 0x2000000 ; Проверка бита 25 в ecx
    jz aes_false_label
    mov rdi, aes_supported
    xor eax, eax
    call printf
    jmp check_sha

aes_false_label:
    mov rdi, aes_not_supported
    xor eax, eax
    call printf
    jmp check_sha

check_sha:
    ; Проверка наличия аппаратной поддержки хеширования SHA
    mov eax, 1
    xor ecx, ecx
    cpuid
    ; Проверка наличия аппаратной поддержки хеширования SHA
    test ecx, 0x8000000 ; Проверка бита 27 в ecx
    jz sha_false_label

    mov rdi, sha_supported
    xor eax, eax
    call printf
    jmp finish

sha_false_label:
    mov rdi, sha_not_supported
    xor eax, eax
    call printf
    jmp finish

finish:
    mov eax, 0 ; Возвращаемое значение из функции main
    ret