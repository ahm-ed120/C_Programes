#include <stdio.h>
int main()
{
    int array[5];
    int p = 0 ,j = 1;
    for (int i = 0; i < 5; i++)
    {
        printf("Enter %d value :", j);
        scanf("%d", &array[i]);
        j++;
    }
    int max = array[0];
    for (int i = 0; i < 5; i++)
    {
        if (array[i] > max)
        {
            p = i;
            max = array[i];
        }
    }
    printf("The largest value is %d\n", max);
    printf("The largest value in array is placed in %d index", p);
    return 0;
}