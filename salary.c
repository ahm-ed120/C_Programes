#include<stdio.h>
#include<conio.h>
#include<string.h>
int main()
{
	char name[32];
	char gender[32];
	int salary;
	int c;
	printf("Enter your name: ");
	gets(name);
	printf ("Enter your gender: ");
	gets(gender);
	printf ("Enter your salary: ");
	scanf("%d",&salary);
	
	if (strcmp(gender, "male") == 0)
	{
		if(salary<=10000)
		{
			printf ("You will get 7%% bonus\n");
			c=0.7*salary;
		}
		else
		{
			printf ("You will get 5%% bonus\n");
			c=0.5*salary;
		}
	}
	else if(strcmp(gender, "female") == 0)
	{
		if(salary<=10000)
		{
			printf ("You will get 12%% bonus\n");
			c=0.12*salary;
		}
		else
		{
			printf ("You will get 10%% bonus\n");
			c=0.1*salary;
		}
	}
	printf("Salary you will get after bonus %d\n",c+salary);
	
	return 0;
}
