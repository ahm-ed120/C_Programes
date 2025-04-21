#include <stdio.h>
#include <conio.h>
int main ()
{
	int n;
	printf ("Enter the number of drivers : ");
	scanf ("%d",&n);
	printf("\n\n");
	struct manager {
		char name[50];
		char license[34];
		char rout[34];
		int km;
	}driver[n];
	
	
	int i,j=1;
	for (i=0;i<n;i++)
	{
		printf ("Enter the detail of %d driver\n",j);
		j++;
		printf ("Name : \n");
		scanf("%s",&driver[i].name);
		printf ("License number : \n");
		scanf ("%s",&driver[i].license);
		printf ("Enter your rout : \n");
		scanf ("%s",&driver[i].rout);
		printf ("Enter distance in km : \n");
		scanf ("%d",driver[i].km);
		getch();
		
	}
	printf ("\n\n");
	j=1;
	printf ("The details of drivers are as following\n");
}
