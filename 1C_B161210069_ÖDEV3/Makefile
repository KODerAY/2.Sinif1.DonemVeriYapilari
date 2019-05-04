TARGET = BinaryTrees

CC = g++
CFLAGS = -Wall -I./include

LINKER = g++
LFLAGS = -Wall -I./include -lm

DIRSOURCE = src
DIROBJECT = lib
DIRBINARY = bin

SOURCES := $(wildcard $(DIRSOURCE)/*.cpp)
OBJECTS := $(SOURCES:$(DIRSOURCE)/%.cpp=$(DIROBJECT)/%.o)
rm = del /Q

ALL: $(DIRBINARY)/$(TARGET) RUN remove

$(DIRBINARY)/$(TARGET): $(OBJECTS)
	@$(LINKER) $(OBJECTS) $(LFLAGS) -o $@
	@echo "Linking complete!"

$(OBJECTS): $(DIROBJECT)/%.o : $(DIRSOURCE)/%.cpp
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiled "$<" successfully!"
	
RUN:
	./$(DIRBINARY)/$(TARGET)

.PHONY: clean
clean:
	@$(rm) $(SOURCES:$(DIRSOURCE)/%.cpp=$(DIROBJECT)\\%.o) 2>NULL.txt
	@echo "Cleanup complete!"

.PHONY: remove
remove: clean
	@$(rm) $(DIRBINARY)\\$(TARGET).exe 2>NULL.txt
	@echo "Executable removed!"