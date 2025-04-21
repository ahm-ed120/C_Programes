#include <stdio.h>
#include <stdlib.h>
int main()
{
    char *id;
    int n, i = 0;
    while (i < 3)
    {
        printf("\nEmployee %d :\n", i + 1);
        printf("Enter the number of character in your Employee ID\n");
        scanf("%d", &n);
        id = (char *)malloc((n + 1) * sizeof(char));
        printf ("Enter your Employee ID : \n");
        scanf("%s",id);
        printf ("Your Employee ID : \n%s\n",id);
        free(id);
        i=i+1;
    }
    return 0;
}