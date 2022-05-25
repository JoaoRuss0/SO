# flags para o compilador
CFLAGS=-Wall -Wextra -ggdb -std=c11 -pedantic -D_POSIX_C_SOURCE=200809L

# ficheiros objectos
OBJS = main.o debug.o
PROGRAM = lab3

all: ${PROGRAM}

debugon: CFLAGS += -D SHOW_DEBUG
debugon: ${PROGRAM}

${PROGRAM}: ${OBJS}
	${CC} -o $@ ${OBJS}

# Lista de dependências dos ficheiros código fonte
debug.o: debug.c debug.h
main.o: main.c debug.h

# Indica como transformar um ficheiro .c num ficheiro .o
.c.o:
	${CC} ${CFLAGS} -c $<

# remove ficheiros sem interesse
clean:
	rm -f *.o core.* *~ ${PROGRAM}
