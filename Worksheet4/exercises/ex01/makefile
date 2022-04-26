PROGRAM = conta_letra
OBJS = main.o conta_letra.o debug.o
CFLAGS = -std=c11 -Wall -Wextra

all: $(PROGRAM)

$(PROGRAM): $(OBJS)
	$(CC) -o $@ $^

main.o: main.c
conta_letra.o: conta_letra.c conta_letra.h
debug.o: debug.c debug.h

.c.o:
	$(CC) -c $(CFLAGS) $<

depend:
	$(CC) -MM *.c

clean:
	rm -f $(PROGRAM) *.o core.* ~*