#include <stdio.h>

void NumbersWithTwoNines(int arr[], int size);

int main()
{
    int arr[10];
    printf ("Enter array : \n");
    for (int i=0;i<10;i++)
    {
        scanf ("%d",&arr[i]);
    }

    NumbersWithTwoNines(arr, 10);

    return 0;
}

void NumbersWithTwoNines(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        int count = 0;
        int number = arr[i];

        while (number != 0)
        {
            if (number % 10 == 9)
            {
                count++;
            }
            number /= 10;
        }

        if (count == 2)
        {
            printf("\n Number with two 9 is %d\n", arr[i]);
        }
    }
}