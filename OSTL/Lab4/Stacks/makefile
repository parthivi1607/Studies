GCCO=gcc -o
GCCC=gcc -c

stack: stack_test.c push.o pop.o
	$(GCCO) stack stack_test.c push.o pop.o

push.o: push.c
	${GCCC} push.c

pop.o: pop.c
	${GCCC} pop.c
