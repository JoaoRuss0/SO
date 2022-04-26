gcc -c main.c
gcc -c funcoes.c
gcc -c funcoes_aux.c

gcc -o lab3 main.o funcoes.o funcoes_aux.o -lm