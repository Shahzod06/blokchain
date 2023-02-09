CC=gcc
CFLAGS= -Wall -Wextra -I.
DEPS = my_blockchain.h
OBJ = my_blockchain.c 
TARGET = my_blockchain
%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(TARGET): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

fclean:
	rm -f ${TARGET} *.o