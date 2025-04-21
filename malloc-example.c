#include <stdio.h>
#include <stdlib.h>
int main()
{
    int *ptr;
    int n;
    printf("Enter the number of array you want to create\n");
    scanf("%d", &n);
    ptr = (int *)malloc(n*sizeof(int));
    for (int i = 0; i < n; i++)
    {
        printf ("Enter the value of %d array \n",i);
        scanf ("%d",&ptr[i]);
    }
    for (int i = 0; i < n; i++)
    {
        printf ("The value of %d array is %d\n",i,ptr[i]);
    }
    
    
    return 0;
}