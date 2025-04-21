#include <stdio.h>
int main()
{
    int s = 19;
    int n;
    for (int i = 1; i <= 19; i++)
    {
        if (i <= 10)
        {
            n = i;
        }
        else
        {
            n = 20 - i;
        }
        for (int j = 1; j <= 10 - n; j++)
        {
            printf(" ");
        }
        for (int k = 1; k <= 2 * n - 1; k++)
        {
            if (k == 1 || k == 2 * n - 1)
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
}