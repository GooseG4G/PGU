# Компиляторы и флаги
NASM=nasm
NASM_FLAGS=-f elf64
GCC=gcc
GCC_FLAGS=-no-pie

# Цель "all" (по умолчанию)
all: bmi1_bmi2_adx

# Объектный файл
bmi1_bmi2_adx.o: bmi1_bmi2_adx.s
	$(NASM) $(NASM_FLAGS) bmi1_bmi2_adx.s -o bmi1_bmi2_adx.o

# Исполняемый файл
bmi1_bmi2_adx: bmi1_bmi2_adx.o
	$(GCC) $(GCC_FLAGS) bmi1_bmi2_adx.o -o bmi1_bmi2_adx

# Очистка
clean:
	rm -f bmi1_bmi2_adx.o bmi1_bmi2_adx