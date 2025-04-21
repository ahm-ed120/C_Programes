#include <stdio.h>
int pow(int a, int b)
{
    if (b == 0)
    {
        return 1;
    }

    return a * pow(a, b - 1);
}

int main()
{
    int a, b;
    printf("Enter number two number:");
    scanf("%d %d", &a, &b);

    printf("%d", pow(a,b));
}