# flags para o compilador
CFLAGS = -std=c11 -Wall -Wextra

# ficheiros objecto
OBJS = exemplo.o debug.o
PROGRAM = program

all: $(PROGRAM)

debugon: CFLAGS += -D SHOW_DEBUG
debugon: $(PROGRAM)

$(PROGRAM): $(OBJS)
	$(CC) -o $@ $(OBJS)

# Lista de dependências dos ficheiros código fonte
debug.o: debug.c debug.h
exemplo.o: exemplo.c debug.h

# Indica como transformar um ficheiro .c num ficheiro .o
.c.o:
	$(CC) $(CFLAGS) -c $<

# remove ficheiros sem interesse
clean:
	rm -f *.o core.* *~ $(PROGRAM)
