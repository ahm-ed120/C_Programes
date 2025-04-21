#include <stdio.h>
void max_min_digit(int num)
{
   int max = 0;
   int min = 9;
   int digit;
   while (num != 0)
   {
      digit = num % 10;
      if (digit > max)
      {
         max = digit;
      }
      if (digit < min)
      {
         min = digit;
      }
      num /= 10;
   }
   printf("Maximun : %d\n", max);
   printf("Minimun : %d", min);
}

int main()
{
   int num;
   int max = 0, min = 9;
   printf("Enter a positive number :");
   scanf("%d", &num);
   max_min_digit(num);

   return 0;
}