PROGRAM = lab4
OBJS = main.o funcoesAux.o funcoes.o
CFLAGS = -std=c11 -Wall -Wextra

all: $(PROGRAM)

$(PROGRAM): $(OBJS)
	$(CC) -o $@ $^

main.o: main.c funcoes.h funcoesAux.h
funcoesAux.o: funcoesAux.c funcoesAux.h funcoes.h
funcoes.o: funcoes.c funcoes.h

.c.o:
	$(CC) -c $(CFLAGS) $<

depend:
	$(CC) -MM *.c

clean:
	rm -f $(PROGRAM) *.o core.* *~