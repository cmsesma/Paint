paint.out: main.o final.o
	gcc -g -Wall -Werror main.o final.o -o paint.out

main.o: main.c
	gcc -g -Wall -Werror -c main.c

final.o: final.c final.h
	gcc -g -Wall -Werror -c final.c

clean:
	rm -f *.o *.out