TARGET = cmp
OBJS = main.o cmpt.o stack.o fact.o
CFLAGS = -O3
LDFLAGS = -lm

$(TARGET): $(OBJS)
	gcc $(OBJS) -o $@ $(LDFLAGS)

cmpt.o: cmpt.c fact.h stack.h
fact.o: fact.c
main.o: main.c cmpt.h
stack.o: stack.c

clean:
	-rm *.o *~ $(TARGET)
.PHONY: clean

