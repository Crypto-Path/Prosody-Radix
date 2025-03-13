# Compiler and Flags
CC = emcc
CFLAGS = -s USE_GLFW=3 -s WASM=1
INCLUDE = -I$(PWD)/raylib/src
LIBRARY = -L$(PWD)/raylib/src -lraylib.web
OUTPUT = index.html

# Sources
SRC = main.c

# Target to build index.html, index.js, and index.wasm
all: $(OUTPUT)

$(OUTPUT): $(SRC)
	$(CC) $(SRC) -o $(OUTPUT) $(CFLAGS) $(INCLUDE) $(LIBRARY) -s ERROR_ON_UNDEFINED_SYMBOLS=0

# Clean target to remove build artifacts
clean:
	rm -f $(OUTPUT) index.js index.wasm index.data index.wasm.map

# To remove any leftover files
clean_all: clean
	rm -rf build/