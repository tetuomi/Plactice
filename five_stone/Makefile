all: a.out
a.out: main.o five_stones.o
		gcc -o a.out main.o five_stones.o
main.o:src/main.c
		gcc -c src/main.c
five_stones.o:src/five_stones.c
		gcc -c src/five_stones.c
clean:
		rm five_stones.o main.o
