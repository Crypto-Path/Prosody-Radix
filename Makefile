# Compiler and Flags
CC = emcc
CFLAGS = -s USE_GLFW=3 -s USE_WEBGL2=1 -s WASM=1 -s ASYNCIFY -s ALLOW_MEMORY_GROWTH=1
INCLUDE = -I$(PWD)/raylib/src -I$(PWD)/clay
LIBRARY = -L$(PWD)/raylib/src -lraylib.web
OUTPUT = index.html

# Sources
SRC = main.c

# Font file embedding
EMBED_FILES = --embed-file resources/Roboto-Regular.ttf

# Target to build index.html, index.js, and index.wasm
all: $(OUTPUT)

$(OUTPUT): $(SRC)
	$(CC) $(SRC) -o $(OUTPUT) $(CFLAGS) $(INCLUDE) $(LIBRARY) $(EMBED_FILES) -s ERROR_ON_UNDEFINED_SYMBOLS=0

# Clean target to remove build artifacts
clean:
	rm -f $(OUTPUT) index.js index.wasm index.data index.wasm.map

# To remove any leftover files
clean_all: clean
	rm -rf build/