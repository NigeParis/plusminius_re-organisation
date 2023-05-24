EXEC=plusminus
CFLAGS=-Wall -Wextra -Werror
CC=gcc
FF=ft_plus_minus
GUI=ft_interface

.PHONY: run
run: $(EXEC)
	./$(EXEC)

$(EXEC): main.o $(FF).o $(GUI).o
	$(CC) $^ -o $(EXEC)

main.o: main.c $(FF).h $(GUI).h
	$(CC) $(CFLAGS) -c main.c

$(FF).o: $(FF).c
	$(CC) $(CFLAGS) -c $(FF).c

$(GUI).o: $(GUI).c
	$(CC) $(CFLAGS) -c $(GUI).c

.PHONY: clean
clean:
	rm -rf $(EXEC) *.o

