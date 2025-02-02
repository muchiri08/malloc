CFLAGS=-Wall -Wextra -std=c17 -pedantic -ggdb

heap: main.c
	$(CC) $(CFLAGS) -o heap main.c
