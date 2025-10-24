#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void guessGame()
{
    int numberOfTries = 10;
    int guess;
    int randomNumber;
    int attempts = 0;

    srand(time(NULL));

    randomNumber = rand() % 100 + 1;

    printf("Welcome to the Number Guessing Game!\n");
    printf("I'm thinking of a number between 1 and 100.\n");
    printf("You have %d tries to guess it!\n\n", numberOfTries);

    while (attempts < numberOfTries)
    {
        printf("Attempt %d/%d - Enter your guess: ", attempts + 1, numberOfTries);
        if (scanf("%d", &guess) != 1)
        {
            printf("Invalid input! Please enter a number.\n");
            while (getchar() != '\n')
                ;
            continue;
        }

        attempts++;

        if (guess == randomNumber)
        {
            printf("🎉 Congratulations! You guessed the number %d correctly!\n", randomNumber);
            printf("It took you %d attempt(s) to win!\n", attempts);
            return;
        }
        else if (guess < randomNumber)
        {
            printf("Too low! Try a higher number.\n");
        }
        else
        {
            printf("Too high! Try a lower number.\n");
        }

        if (attempts < numberOfTries)
        {
            printf("You have %d attempt(s) remaining.\n\n", numberOfTries - attempts);
        }
    }

    printf("\n😞 Sorry! You've used all %d attempts.\n", numberOfTries);
    printf("The number I was thinking of was: %d\n", randomNumber);
    printf("Better luck next time!\n");
}

int main()
{
    char playAgain;

    do
    {
        guessGame();

        printf("\nWould you like to play again? (y/n): ");
        scanf(" %c", &playAgain);
        printf("\n");

    } while (playAgain == 'y' || playAgain == 'Y');

    printf("Thanks for playing! Goodbye!\n");
    return 0;
}