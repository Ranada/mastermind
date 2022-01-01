# Mastermind Game

This is a command line game where you have to guess a four digit secret code using numbers between 0 and 7 (ex: 0357). 

You can play by yourself against a random computer generated secret four digit code.

Or, you can play with another person. As a "game master" you can set a four digit code (using numbers between 0 and 7) and set the number of attempts available to a player (default is 10 attempts).

## How to install

You can download the project folder and files manually to your computer or fork the Github repo at: 
https://github.com/Ranada/mastermind_game


## How to play

### To play by yourself

- In the command line type `./my_mastermind`

### To play with another person

- The game master can set a four digit code using numbers between 0 and 7 after a `-c` flag 
- For example: `./my_mastermind -c 0357`
- Enter your four digit guess (using numbers between 0 and 7) in the command line until you run out of attempts

- To customize the number of attempts (default is 10), add a number after a `-t` flag
- For example: `./my_mastermind -c 0357 -t 5`
- The player enters a four digit guess (using numbers between 0 and 7) in the command line until they run out of attempts