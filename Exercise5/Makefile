FILE_NAMES=mutex.c
COMPLIER=gcc
FLAGS=-pthread

bin:
	$(COMPLIER) $(FILE_NAMES) -o $@ $(FLAGS)

.PHONY: run clean

clean:
	rm bin

run:
	./bin
