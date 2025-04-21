#include <stdio.h>
int main()
{
    int a[10], swap = 0;
    printf("Enter the value of array \n");
    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10 - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                swap += 1;
            }
        }
    }
    printf("After Bubble Sorting:");
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", a[i]);
    }
    printf ("\nThe number of swapping is %d",swap);
    return 0;
}