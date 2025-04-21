#include<stdio.h>
#include <conio.h>
int main()
{
	char name[32];
	int account_num;
	float average_balance;
	int num_trnsaction;
	
	printf("Enter your name \n");
	gets(name);
	printf("Enter your acccount number\n");
	scanf ("%d",&account_num);
	printf("Enter your average balance\n");
	scanf ("%f",&average_balance);
	printf("Enter totale number of transaction you made this month\n");
	scanf ("%d",&num_trnsaction);
	double interest,sevice_charges;
	interest=0.06*average_balance;
	sevice_charges=0.5*num_trnsaction;
	printf ("your interest is %.2lf\n",interest);
	printf ("service charges is %.2lf\n",sevice_charges);
	return 0;
}
