#include <stdio.h>

int fab_recursive(int n)
{
	if (n == 1 || n == 2)
		return n - 1;
	else
		return fab_recursive(n - 1) + fab_recursive(n - 2);
}

int main()
{
	int num;
	printf("Enter the number of terms: ");
	scanf("%d", &num);
	printf("Fibonacci series: ");
	for (int i = 1; i <= num; i++)
	{
		printf("%d ", fab_recursive(i));
	}
	return 0;
}