#include <stdio.h>
int main()
{
	char input;
	float con[5]={0.621,0.083,0.393,0.453,0.025};
	float first,second;
	while (1)
	{
			
		printf ("Enter q to quit \n1. km to miles\n2. inces to foot\n3. cm to inces\n4. pound to kg\n5. inces to meter\n");
		scanf ("%c",&input);
		switch (input)
		{
			case 'q':
			 	printf("Quiting the program \n ");
			 	goto end;
			 	break;
			case '1':
			 	printf("Enter the value in km: ");
			 	scanf("%f",&first);
			 	second = first*con[0];
			 	printf ("%.2f km to miles is %.2f\n",first,second);
			 	break;
			 	
			case '2':
			 	printf("Enter the value in inches: ");
			 	scanf("%f",&first);
			 	second = first*con[1];
			 	printf ("%.2f inches to foots is %.2f\n",first,second);
			 	break;
			 	
			case '3':
			 	printf("Enter the value in cm: ");
			 	scanf("%f",&first);
			 	second = first*con[2];
			 	printf ("%.2f cm to inches is %.2f\n",first,second);
			 	break;
			case '4':
			 	printf("Enter the value in pounds: ");
			 	scanf("%f",&first);
			 	second = first*con[3];
			 	printf ("%.2f pounds to kg is %.2f\n",first,second);
				 break;	 
			case '5':
			 	printf("Enter the value in inches: ");
			 	scanf("%f",&first);
			 	second = first*con[4];
			 	printf ("%.2f inches to meters is %.2f\n\n",first,second);	
				break; 	  	
		}
	}	
	end:
	return 0;
}
