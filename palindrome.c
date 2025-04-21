#include <stdio.h>
int ifPalindrome(int num)
{
    int n = num;
    int remainder, remaining = 0;
    while (n != 0)
    {
        remainder = n % 10;
        remaining = remaining * 10 + remainder;
        n = n / 10;
    }
        if (num==remaining)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    
}

int main()
{
    int num;
    printf("Enter a number : ");
    scanf("%d", &num);
    if (ifPalindrome(num))
    {
        printf("The number u enter is a palindrome\n");
    }
    else
    {
        printf("The number u enter is not a palindrome \n");
    }
    return 0;
}