section .data
    bmi1_supported db "bmi1 TRUE", 0xA, 0
    bmi1_not_supported db "bmi1 FALSE", 0xA, 0
    bmi2_supported db "BMI2 TRUE", 0xA, 0
    BMI2_not_supported db "BMI2 FALSE", 0xA, 0
    ADX_supported db "ADX TRUE", 0xA, 0
    ADX_not_supported db "ADX FALSE", 0xA, 0

section .text
    extern printf

global main
main:
    ; Проверка наличия аппаратной генерации случайных чисел (RDRAND)
    mov eax, 7
    cpuid
    test ebx, 0x8 ; Проверка бита 3 в ebx
    jz bmi1_false_label
    mov rdi, bmi1_supported
    xor eax, eax
    call printf
    jmp check_bmi2

bmi1_false_label:
    mov rdi, bmi1_not_supported
    xor eax, eax
    call printf
    jmp check_bmi2

check_bmi2:
    ; Проверка BMI2
    mov eax, 7
    cpuid
    test ebx, 0x10 ; Проверка бита 4 в ebx
    jz bmi2_false_label
    mov rdi, bmi2_supported
    xor eax, eax
    call printf
    jmp check_adx

bmi2_false_label:
    mov rdi, BMI2_not_supported
    xor eax, eax
    call printf
    jmp check_adx

check_adx:
    ; Проверка наличия аппаратной поддержки хеширования ADX
    mov eax, 7
    xor ecx, ecx
    cpuid
    ; Проверка наличия аппаратной поддержки хеширования ADX
    test ebx, 0x8000 ; Проверка бита 15 в ebx
    jz adx_false_label

    mov rdi, ADX_supported
    xor eax, eax
    call printf
    jmp finish

adx_false_label:
    mov rdi, ADX_not_supported
    xor eax, eax
    call printf
    jmp finish

finish:
    mov eax, 0 ; Возвращаемое значение из функции main
    ret