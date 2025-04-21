#include <stdio.h>
int main()
{
    int arr[10];
    printf("Enter array :\n");
    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &arr[i]);
    }
    int max1, max2;
    if (arr[0] > arr[1])
    {
        max1 = arr[0];
        max2 = arr[1];
    }
    else
    {
        max1 = arr[1];
        max2 = arr[0];
    }
    for (int i = 2; i < 10; i++)
    {
        if (arr[i] > max1)
        {
            max2 = max1;
            max1 = arr[i];
        }
        else if (arr[i] > max2 && arr[i] != max1)
        {
            max2 = arr[i];
        }
    }
    printf("The second largest value is %d ", max2);

    return 0;
}