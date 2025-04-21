#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void computer(int *comChoice)
{

    switch (*comChoice)
    {
    case 1:
        printf("Rock\n");
        break;
    case 2:
        printf("Paper\n");
        break;
    case 3:
        printf("Scissors\n");
        break;
    }
}

int main()
{
    int userChoice, comChoice;
    int player_score = 0, com_score = 0;
    char name[32];

    printf("**************Wellcome to the game************\n\n");

    printf("Enter your name : ");
    scanf("%s", name);
    getchar();

    srand(time(NULL));

    for (int i = 1; i <= 3; i++)
    {
        printf("\nRound %d : \n", i);
        printf("Choose your move:\n");
        printf("1. Rock\n");
        printf("2. Paper\n");
        printf("3. Scissors\n");
        scanf("%d", &userChoice);

        printf("%s choice : ", name);
        switch (userChoice)
        {
        case 1:
            printf("Rock\n");
            break;
        case 2:
            printf("Paper\n");
            break;
        case 3:
            printf("Scissors\n");
            break;
        default:
            printf("Invalid choice\n");
            continue;
        }

        comChoice = rand() % 3 + 1;
        printf("Computer choice : ");
        computer(&comChoice);

        if ((userChoice == 1 && comChoice == 3) ||
            (userChoice == 2 && comChoice == 1) ||
            (userChoice == 3 && comChoice == 2))
        {
            printf("%s wins!\n", name);
            player_score++;
        }
        else if (userChoice == comChoice)
        {
            printf("It's a tie!\n");
        }
        else
        {
            printf("Computer wins!\n");
            com_score++;
        }
    }

    printf("\n*****Final result*****\n");
    printf("%s scores %d\n", name, player_score);
    printf("Computer scores %d\n", com_score);

    if (player_score > com_score)
    {
        printf("%s Wins", name);
    }
    else if (player_score < com_score)
    {
        printf("Computer wins");
    }
    else
    {
        printf("Its a tie");
    }
    return 0;
}
