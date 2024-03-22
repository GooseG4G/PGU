# Усложненный make-file.  Введены переменные для параметров компиляции и исполняемых файлов

.PHONY: all debug release clean

RELEASE_FLAGS = -O2 -Wall -DNDEBUG
DEBUG_FLAGS   = -g -O0 -Wall
RELEASE_EXEC  =Calculator
DEBUG_EXEC    =Calculator-dbg
SOURCE        = $(Calculator.cpp)

all: debug release

debug: $(DEBUG_EXEC)

$(DEBUG_EXEC): Calculator.cpp
	g++ $(DEBUG_FLAGS) Calculator.cpp -o $(DEBUG_EXEC) 

release: $(RELEASE_EXEC)

$(RELEASE_EXEC): Calculator.cpp
	g++ $(RELEASE_FLAGS) Calculator.cpp -o $(RELEASE_EXEC)

clean:
	rm -f $(RELEASE_EXEC) $(DEBUG_EXEC)