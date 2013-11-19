TARGET = bf
OBJS = bf.o stack.o
CFLAGS = -O3
LDFLAGS =

$(TARGET): $(OBJS)
	gcc $(OBJS) -o $@ $(LDFLAGS)

bf.o: bf.c stack.h
stack.o: stack.c

clean:
	-rm *.o $(TARGET)
install:
	install bf ~/bin/
.PHONY: clean
.PHONY: install
