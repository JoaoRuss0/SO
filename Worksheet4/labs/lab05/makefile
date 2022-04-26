# Compiler flags
CFLAGS=-std=c11 -Wall -Wextra -pedantic -ggdb

# Name of the executable
PROGRAM=prog# Compiler flags
CFLAGS=-std=c11 -Wall -Wextra -pedantic -ggdb

# Name of the executable
PROGRAM=exemplo_opt

# Prefix for the gengetopt file (if gengetopt is used)
PROGRAM_OPT=args

# Object files required to build the executable
PROGRAM_OBJS=main.o $(PROGRAM_OPT).o

# Compiler flags
#CFLAGS=-std=c11 -Wall -Wextra -pedantic -ggdb
CFLAGS=-std=c11 -Wall -Wextra -ggdb

# Clean and all are not files
.PHONY: clean all

all: $(PROGRAM)

$(PROGRAM): $(PROGRAM_OBJS)
	$(CC) -o $@ $(PROGRAM_OBJS) $(LIBS) $(LDFLAGS)

# Dependencies
main.o: main.c $(PROGRAM_OPT).h
$(PROGRAM_OPT).o: $(PROGRAM_OPT).c $(PROGRAM_OPT).h

#how to create an object file (.o) from C file (.c)
.c.o:
	$(CC) $(CFLAGS) -c $<

# Generates command line arguments code from gengetopt configuration file
$(PROGRAM_OPT).h: $(PROGRAM_OPT).ggo
	gengetopt < $(PROGRAM_OPT).ggo --file-name=$(PROGRAM_OPT)

clean:
	rm -f *.o core.* *~ $(PROGRAM) *.bak $(PROGRAM_OPT).h $(PROGRAM_OPT).c
