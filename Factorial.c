//code for finding factorials using recursive function

#include<stdio.h>

int factorial(int number){
	if (number == 1 || number == 0)
	{
		return 1;
	}
	else {
		return number*(factorial(number-1));
	}
}

int main()
{
	int num;
	printf ("Enter a number\n");
	scanf ("%d",&num);
	printf("The factorial of %d is %d ",num , factorial(num));
	
}
