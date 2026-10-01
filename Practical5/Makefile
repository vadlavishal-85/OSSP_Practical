CC = gcc
CFLAGS = -Wall -g

all: prog5 ls_grep_pipe

prog5: prog5.c
	$(CC) $(CFLAGS) -o prog5 prog5.c

ls_grep_pipe: ls_grep_pipe.c
	$(CC) $(CFLAGS) -o ls_grep_pipe ls_grep_pipe.c

clean:
	rm -f prog5 ls_grep_pipe
