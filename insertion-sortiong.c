#include <stdio.h>
void Insertionsort(int a[], int s)
{
	int key;
	for (int i = 1; i < s; i++)
	{
		key = a[i];
		int j = i - 1;
		while (j >= 0 && a[j] > key)
		{
			a[j + 1] = a[j];

			j--;
		}
		a[j + 1] = key;
	}
}
int main()
{

	int a[10];
	printf("Enter the value of arrar :\n");
	for (int i = 0; i < 10; i++)
	{
		scanf("%d", &a[i]);
	}
	Insertionsort(a, 10);
	printf("Ater insertion sorting : ");
	for (int l = 0; l < 10; l++)
		printf("%d ", a[l]);
}
