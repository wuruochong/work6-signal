signal: signal.c
	gcc signal.c -o signal.out
run: signal
	./signal.out
clean:
	rm signal.out
	rm *~
