backgammon	:	main.o	back.o	bicola.o	jugador.o	elem.o	circular.o	lista.o
	gcc	-o	backgammon	main.o	back.o	bicola.o	elem.o	jugador.o	circular.o	lista.o
main.o	:	main.c	back.h	jugador.h
	gcc	-c	main.c
back.o	:	back.c bicola.h
	gcc	-c	back.c
bicola.o	:	bicola.c
circular.o	:	circular.c
	gcc	-c	circular.c	
	gcc	-c	bicola.c
jugador.o	:	jugador.c
	gcc	-c	jugador.c
elem.o	:	elem.c
	gcc	-c	elem.c
lista.o	:	lista.c	elem.h
	gcc	-c	lista.c
clean	:
	rm	backgammon	\
	main.o	back.o	bicola.o	jugador.o	elem.o
