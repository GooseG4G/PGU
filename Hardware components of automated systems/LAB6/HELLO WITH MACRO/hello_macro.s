%include "syscall.mac"
global _start
section .text
_start: 
  WRITE msg, len
  EXIT 0
  section .data ; системный вызов
msg: ; метка -> адрес данных -> имя данных
DB "Hello, world!", 0xa; байтовый массив, может содержать строки
DB "NASM assembler", 0xa
len EQU $ - msg ; именованная константа len равна длине строки
