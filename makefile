all: menu

menu: menu.o
	gcc -g -Wall -o menu menu.o

menu.o: menu.c
	gcc -g -Wall -c -o menu.o menu.c  

.PHONY: clean 

clean:
	rm -f *.o menu

