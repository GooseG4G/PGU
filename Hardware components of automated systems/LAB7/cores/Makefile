# Компиляторы и флаги
NASM=nasm
NASM_FLAGS=-f elf64
GCC=gcc
GCC_FLAGS=-no-pie

# Цель "all" (по умолчанию)
all: cores

# Объектный файл
cores.o: cores.s
	$(NASM) $(NASM_FLAGS) cores.s -o cores.o

# Исполняемый файл
cores: cores.o
	$(GCC) $(GCC_FLAGS) cores.o -o cores

# Очистка
clean:
	rm -f cores.o cores