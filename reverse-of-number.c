#include <stdio.h>
int reverse (int n)
{
    int remainder,remaining=0;
    while (n!=0)
    {
        remainder=n%10;
        remaining = remaining * 10 +remainder;
        n=n/10;
    }
    return remaining;
}

int main()
{
    int n;
    printf ("Enter a number you want reverse: ");
    scanf ("%d",&n);
    reverse(n);
    printf ("The reversed number is: %d",reverse(n));
    return 0;
}