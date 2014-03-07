OBJ=sym.o word.o ui.o main.o
BIN=WorLd
LIBS=-lncurses
CC=g++

NO_COLOR=\033[0m
OK_COLOR=\033[32;01m
ERROR_COLOR=\033[31;01m
WARN_COLOR=\033[33;01m
HIGHLIGHT_COLOR=\033[1m


all: $(BIN)
	@echo -e "$(HIGHLIGHT_COLOR)  ./$(BIN)$(NO_COLOR)"
	@./$(BIN)

session:
	@echo "Recovering session..."
	@gedit Makefile $(OBJ:.o=.hpp) $(OBJ:.o=.cpp) 2>/dev/null &

$(BIN): $(OBJ)
	@echo -e "Linking for $(BIN)..."
	@$(CC) -o $(BIN) $(OBJ) $(LIBS)
	@echo -e "$(OK_COLOR)Done.$(NO_COLOR)"

.SUFFIXES: .cpp .hpp .o

.cpp.o:
	$(CC) -c $< $(LIBS)

clean:
	@echo -e "Cleaning directory..."
	@rm -v -f *~ $(BIN) $(OBJ)
	@echo -e "$(OK_COLOR)Done.$(NO_COLOR)"


.PHONY: all clean session

