CC = gcc
FILES  = src/hash.c src/main.c
OUT_EXE = bin/output
LIBS = -lssl -lcrypto

build: $(FILES)
	$(CC) -o $(OUT_EXE) $(FILES) $(LIBS)

clean:
	-rm $(OUT_EXE)

rebuild: clean build
