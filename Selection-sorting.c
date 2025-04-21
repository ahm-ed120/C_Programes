#include <stdio.h>
void Selectionsorting(int array[], int s)
{
    int min, ind;
    for (int i = 0; i < s; i++)
    {
        min = array[i];
        ind = i;
        for (int j = i; j < s; j++)
        {
            if (array[j] < min)
            {
                min = array[j];
                ind = j;
            }
        }
        int temp = array[ind];
        array[ind] = array[i];
        array[i] = temp;
    }
}
int main()
{
    int a[10];
    printf("Enter array :\n");
    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &a[i]);
    }
    Selectionsorting(a, 10);
    printf("After Selection sorting :");
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", a[i]);
    }

    return 0;
}
