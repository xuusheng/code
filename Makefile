TARGET = maze
OBJS = maze.o stack.o
CFLAGS = -O3
LDFLAGS =

$(TARGET): $(OBJS)
clean:
	rm *.o $(TARGET)
install:
	install $(TARGET) ~/bin/
.PHONY: clean
.PHONY: install
