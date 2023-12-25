# Компиляторы и флаги
NASM=nasm
NASM_FLAGS=-f elf64
GCC=gcc
GCC_FLAGS=-no-pie

# Цель "all" (по умолчанию)
all: rand_sha_avx

# Объектный файл
rand_sha_avx.o: rand_sha_avx.s
	$(NASM) $(NASM_FLAGS) rand_sha_avx.s -o rand_sha_avx.o

# Исполняемый файл
rand_sha_avx: rand_sha_avx.o
	$(GCC) $(GCC_FLAGS) rand_sha_avx.o -o rand_sha_avx

# Очистка
clean:
	rm -f rand_sha_avx.o rand_sha_avx