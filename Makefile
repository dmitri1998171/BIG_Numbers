BIN := main
SRC := main.cpp
CC := g++
CFLAGS := 
LDFLAGS :=

$(BIN): $(SRC)
	clear && $(CC) $(SRC) -o $(BIN)

clean:
	rm -rf $(BIN)