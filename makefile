all:
	gcc -Wall -Wextra -Werror *.c -o play_mastermind

clean:
	rm -r *.dSYM