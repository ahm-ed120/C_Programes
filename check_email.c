#include <stdio.h>
#include <string.h>
#include <ctype.h>              

int isValidEmail(char email[])
{
    int atCount = 0;
    int dotCount = 0;
    int i;
    int atIndex = -1;
    int length = strlen(email);

    if (!isalnum(email[0]))
    {
        return 0;
    }

    for (i = 0; i < length; i++)
    {
        if (email[i] == '@')
        {
            atCount++;
            atIndex = i;
            if (atCount > 1 || i == 0 || i == length - 1)
            {
                return 0;
            }
        }

        if (email[i] == '.')
        {
            dotCount++;
            if (i == 0 || email[i - 1] == '@' || i == length - 1)
            {
                return 0;
            }
        }

        if (!isalnum(email[i]) && email[i] != '@' && email[i] != '.' && email[i] != '_' && email[i] != '-')
        {
            return 0;
        }
    }

    if (atIndex != -1 && length > atIndex + 4)
    {
        if (email[atIndex + 1] != '.' && strcmp(&email[length - 4], ".com") == 0)
        {
            return 1;
        }
    }

    return 0;
}

int main()
{
    char email[100];

    printf("Enter an email: ");
    scanf("%s", email);

    if (isValidEmail(email))
    {
        printf("The email is valid.\n");
    }
    else
    {
        printf("The email is invalid.\n");
    }

    return 0;
}