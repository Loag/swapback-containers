CC = clang
CFLAGS = -Wall -Wextra -g

# Build object files
swapback-list.o: swapback-list.h swapback-list.c
	$(CC) $(CFLAGS) -c swapback-list.c -o swapback-list.o

main.o: main.c swapback-list.h
	$(CC) $(CFLAGS) -c main.c -o main.o

# Link the final executable
main: main.o swapback-list.o
	$(CC) $(CFLAGS) -o main main.o swapback-list.o

# Clean up build artifacts
clean:
	rm -f *.o main
