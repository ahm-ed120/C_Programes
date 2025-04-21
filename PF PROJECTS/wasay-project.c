#include<stdio.h>
#include<conio.h>
#include<string.h>
#define max 100

//making structures
 typedef struct {
	char name[100];
	float price;
	int model;
	int status;
}manage;
//customer
typedef struct {
	char name[50];
	char gender[50];
	int age;
	int id;
	
}data1;
//order data
typedef struct{
	int c_id;    //customer id
	int car_id;   //car  id
    int order_id;   //order id
    float total_price;
}order;
// employee 
typedef struct {
	char name[50];
	int age;
	float salary;
	int id;
//bonous points
	int points;
}data2;

//working for order

int add_order(order c[],data1 customer[],manage car[],int count_order,int count_cust,int count_car)
{
	int found=-1;
	int found1=-1;

	printf("ENTER THE ID OF THE ORDER");
	scanf("%d",&c[count_order].order_id);
	printf("ENTER THE ID OF THE CUSTOMER");
	scanf("%d",&c[count_order].c_id);
	for(int i=0;i<count_cust;i++)
	{
		if(c[count_order].c_id==customer[i].id)
		{
			found=1;
		}
	}
	if(found==-1)
	{
		printf("INVALID CUSTOMER ID MEANS THAT CUSTOMER OF THIS ID IS NOT PRESENT!!\n\n");
		return 0;
	}
		for(int i=0;i<count_car;i++)
		{
			printf("car%d of model number is %d\n",i,car[i].model);
		}
		printf("ENTER THE model number OF THE CAR YOU WANT TO  ON A RENT");
		scanf("%d",&c[count_order].car_id);
		
		for(int i=0;i<count_car;i++)
		{
			
			if(c[count_order].car_id==car[i].model)
			{
				found1=i;
				break;
			}
			
		}
		if(found1==-1)
		{
			printf("CAR NOT FOND!!\n");
			return 0;
		}
		else
		{
			if(car[found1].status!=1)
			{
			
				c[count_order].total_price=(car[found].price*5)/100.0;
				printf("YOUR TOTAL BILL OF RENTING A CAR IS :\n");
				printf("::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
				printf("%s\n",car[found1].name);
				printf("%.2f\n",car[found1].price);
				printf("CUSTOMER NAME %s\n",customer[found1].name);
				printf("FINAL BILL===%.2f\n",c[count_order].total_price);
				printf("::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
				car[found1].status=1;
				
				FILE *fcar;
				fcar=fopen("car.txt","w");
				fprintf(fcar,"%d\n",count_car);
				for(int i=0;i<count_car;i++)
				{
					fprintf(fcar,"%s;%f;%d;%d\n",car[i].name,car[i].price,car[i].model,car[i].status);
				}
					fclose(fcar);
				return 1;
			}
			else
			{
				printf("CAR IS ALREADY ON RENT\n");
				return 0;
			}
		}
		
}

int DELETE_order(order c[],manage car[],int count_order,int count_car)
{
	int id;
	int found3=-1;
	if(count_order!=0)
	{
		printf("ENTE THE ID  NUMBER YOU WANT TO DELETE ");
		scanf("%d",&id);
		for(int i=0;i<count_order;i++)
		{
			if(id==c[i].order_id)
			{
				car[i].status=0;
				found3=i;
			}
			if(found3!=-1)
			{
				for(int j=found3;j<count_order-1;j++)
				{
					c[j]=c[j+1];
				}
				
				FILE *fcar;
				fcar=fopen("car.txt","w");
				fprintf(fcar,"%d\n",count_car);
				for(int i=0;i<count_car;i++)
				{
				fprintf(fcar,"%s;%f;%d;%d\n",car[i].name,car[i].price,car[i].model,car[i].status);
				}
				fclose(fcar);
				return 1;
				
			}
		}
	}
	
	
		printf("NO ORDER PLACED YET\n");
		return 0;
	
}
void display_order(order c[],int count_order)
{
	if(count_order!=0)
	{
		for(int i=0;i<count_order;i++)
		{
			printf("\t\t\t\tORDER %d\n",i+1);
			printf("::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
			printf("CUSTOMER ID :%d\n",c[i].c_id);
			printf("CAR ID :%d\n",c[i].car_id);
			printf("ORDER ID :%d\n",c[i].order_id);
			printf("::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
			
		}
		return;
	}
	printf("NO ORDERS AVAILABLE YET!!\n");
	return;
	
}
//add car data
int add_car(manage car[],int count_car)
{

	 if (count_car < max)
    {
        printf("\nENTER THE MODEL OF THE CAR:\n");
        scanf("%d", &car[count_car].model);
        

        printf("ENTER THE NAME OF THE CAR:\n");
        scanf(" %[^\n]s", car[count_car].name);

        printf("ENTER THE PRICE OF CARS: \n");
        scanf("%f", &car[count_car].price);
 		car[count_car].status=0;
		return 1;
    }
    else
    {
        printf("\nLIST OF CAR IS FULL.\n");
        return 0;
    }
    

}
//update car data
void upp_car(manage car[],int count_car)
{

	int model;
    printf("\nENTER THE MODEL OF THE CAR: \n");
    scanf("%d", &model);

    for (int i = 0; i <count_car ; i++)
    {
        if (car[i].model == model)
        {
            printf("ENTER THE NEW NAME OF THE CAR : ");
            scanf(" %s", &car[i].name);
            printf("ENTER THE NEW PRICE OF THE CAR : ");
            scanf("%f", &car[i].price);
            printf("CAR DATA UPDATE SUCCESSFULLY!!!\n");
            return;
        }
    }
    printf("\nCAR NOT FOUNDED!!\n");

}
//delete car
 int del_car(manage car[],int count_car)
{
	
	 int model;
    printf("\nENTER THE MODEL OF CAR YOU WANT TO REMOVE:");
    scanf("%d", &model);

    for (int i = 0; i < count_car; i++)
    {
        if (car[i].model == model)
        {
            for (int j = i; j < count_car - 1; j++)
            {
                car[j] = car[j + 1];
            }
            return 1;
            
        }
    }
    printf("CAR NOT FOUNDED!!\n");
    return 0;

}
//display car data
 void display_car(manage car[],int count_car)
{
	 for (int i = 0; i < count_car; i++)
    {
        printf("\n\t\t\t\t\tYOUR CAR %d : \n", i + 1);
        printf("::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
        printf("model : %d \n Name : %s \n price : %.2f\n\n", car[i].model, car[i].name, car[i].price);
        if(car[i].status==1)
        {
        	printf("CAR %d IS ON RENT",i+1);
		}
		else
		{
			printf("CAR %d IS AVAILABLE IN SHOWROOM",i+1);
		}
    }
    if (count_car == 0)
    {
        printf("\nCARS ARE NOT AVAILABLE YET!!!\n");
    }

}

//functions of customer
int add_cust(data1 customer[],int count_cust)
{
	 if (count_cust < max)
    {
        
        printf("ENTER THE NAME OF THE CUSTOMER:\n");
        scanf(" %[^\n]s", customer[count_cust].name);

        printf("ENTER THE gender OF THE CUSTOMER:\n");
        scanf(" %[^\n]s", customer[count_cust].gender);
        printf("ENTER THE AGE OF THE CUSTOMER\n");
        scanf("%d",&customer[count_cust].age);
        printf("ENTER THE id number  OF THE CUSTOMER\n");
        scanf("%d",&customer[count_cust].id);
        return 1;
        
    }
    else
    {
        printf("\nLIST OF CUSTOMER IS FULL.\n");
    }
    return 0;
}
void upp_cust(data1 customer[],int count_cust)
{
	char name[50];
	int choice10;
	int id1;
	do
	{
				printf("1.UPDATE THROUGH NAME \n2.UPDATE THROUGH ID NUMBER\n\n");
			printf("ENTER YOUR CHOICE");
			scanf("%d",&choice10);
			switch(choice10)
			{
				case 1:
					{
						printf("\nENTER THE NAME OF THE CUSTOMER YOU WANT TO UPDATE: \n");
					    scanf(" %[^\n]s",&name);
					
					    for (int i = 0; i <count_cust ; i++)
						{
					        	if (strcmp(customer[i].name,name)==0)
					        {
					            printf("ENTER THE NEW NAME OF THE customer : ");
					            scanf(" %[^\n]s", &customer[i].name);
					            printf("ENTER THE NEW GENDER OF THE customer : ");
					            scanf(" %[^\n]s", &customer[i].gender);
					            printf("ENTER THE NEW age OF THE CUSTOMER : ");
					            scanf("%d", &customer[i].age);
					            printf("CUSTOMER DATA UPDATE SUCCESSFULLY!!!\n");
					            return;
					        }
					    }
		    				printf("\nCUSTOMER NOT FOUNDED!!\n");
		    			break;
					}
				case 2:
					{
						printf("ENTER THE ID NUMBER OF THE CUSTOMER");
						scanf("%d",&id1);
						for(int i=0; i<count_cust;i++)
						{
							if(id1==customer[i].id)
							{
								printf("ENTER THE NEW NAME OF THE customer : ");
					            scanf(" %[^\n]s", &customer[i].name);
					            printf("ENTER THE NEW GENDER OF THE customer : ");
					            scanf(" %[^\n]s", &customer[i].gender);
					            printf("ENTER THE NEW age OF THE CUSTOMER : ");
					            scanf("%d", &customer[i].age);
					            printf("CUSTOMER DATA UPDATE SUCCESSFULLY!!!\n");
					            return;
							}
						}
						printf("\nCUSTOMER NOT FOUNDED!!\n");
		    			break;
						
					}
				case 3:
					{
						printf("OK AS YOU WISH\n");
						break;
					}
				default:
					{
						printf("INVALID CHOICE TRY AGAIN");
					}
					
			}
		    
	}while(choice10!=3);
	
}
int del_cust(data1 customer[],int count_cust)
{
	char name[50];
	printf("ENTER THE NAME OF THE CUSTOMER");
	scanf(" %[^\n]s",&name);
	for (int i = 0; i < count_cust; i++)
    {
        if (strcmp(customer[i].name,name)==0)
        {
            for (int j = i; j < count_cust - 1; j++)
            {
                customer[j] = customer[j + 1];
            }
            return 1;

        }
    }
    printf("CUSTOMER NOT FOUNDED!!\n");        
	
	return 0;
}
void display_cust(data1 customer[],int count_cust)
{
	if(count_cust!=0)
	{
		for(int i=0;i<count_cust;i++)
		{
			printf("\t\t\t\tTHE CUSTOMER%d\n",i+1);
			printf("::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
			printf("THE NAME :%s\nTHE AGE:%d\nGENDER:%s\nID NUMBER OF CUSTOMER%d\n",customer[i].name,customer[i].age,customer[i].gender,customer[i].id);
			printf("::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
		}
	}
	else
	{
		printf("no customer yet\n");
	}
}

//functions of employee
int  add_emp(data2 employee[],int count_emp)
{
	if(count_emp<max)
	{
		printf("ENTER THE NAME OF THE EMPLOYEE\n");
		scanf(" %[^\n]s",&employee[count_emp].name);
		printf("ENTER THE SALARY OF THE EMPLOYEE\n");
		scanf("%f",&employee[count_emp].salary);
		printf("ENTER THE ID NUMBER OF THE EMPLOYEE\n");
		scanf("%d",&employee[count_emp].id);
		printf("ENTER THE AGE OF THE EMPLOYEE");
		scanf("%d",&employee[count_emp].age);
		printf("ENTER THE POINTS OF THE EMPLOYEE");
		scanf("%d",&employee[count_emp].points);
		return 1;
	}
	else
	{
		printf("LIST OF EMPLOYEE IS ALREADY FULL\n");
	}
	return 0;
}

void upp_emp(data2 employee[],int count_emp)
{
	char name[50];
	int choice8,id;
	printf("|1.UPPDATE BY NAME\n|2.UPPDATE BY ID NUMBER\n");
	printf("ENTER YOUR CHOICE");
	scanf("%d",&choice8);
	switch(choice8)
	{
		case 1:
			{
				printf("ENTER THE NAME OF THE CUSTOMER YOU WANT TO UPDATE");
				scanf(" %[^\n]s",&name);
				for(int i=0;i<count_emp;i++)
				{
					if(strcmp(name,employee[i].name)==0)
					{
						printf("ENTER THE NEW NAME OF THE EMPLOYEE\n");
						scanf(" %[^\n]s",&employee[i].name);
						printf("ENTER THE NEW SALARY OF THE EMPLOYEE\n");
						scanf("%f",&employee[i].salary);
						printf("ENTER THE NEW  ID NUMBER OF THE EMPLOYEE\n");
						scanf("%d",&employee[i].id);
						printf("ENTER THE NEW AGE OF THE EMPLOYEE");
						scanf("%d",&employee[i].age);
						printf("ENTER THE NEW  POINTS OF THE EMPLOYEE");
						scanf("%d",&employee[i].points);
						return;
					}
				}
				printf("NO EMPLOYEE FOUND OF NAME %s\n",name);
				break;
			}
		case 2:
			{
				printf("ENTER THE ID NUMBER OF THE EMPLOYEE");
				scanf("%d",&id);
				for(int i=0;i<count_emp;i++)
				{
					if(employee[i].id==id)
					{
						printf("ENTER THE NEW NAME OF THE EMPLOYEE\n");
						scanf(" %[^\n]s",&employee[i].name);
						printf("ENTER THE NEW SALARY OF THE EMPLOYEE\n");
						scanf("%f",&employee[i].salary);
						printf("ENTER THE NEW  ID NUMBER OF THE EMPLOYEE\n");
						scanf("%d",&employee[i].id);
						printf("ENTER THE NEW AGE OF THE EMPLOYEE");
						scanf("%d",&employee[i].age);
						printf("ENTER THE NEW  POINTS OF THE EMPLOYEE");
						scanf("%d",&employee[i].points);
						return;
					}
				}
				printf("NO EMPLOYEE FOUND OF ID %d\n",id);
				break;
			}
			default:
			{
				printf("you have entered a wrong choice\n");
			}
	}
	
	
}
int del_emp(data2 employee[],int count_emp)
{
	char name1[50];
	int choice9,id1;
	printf("|1.DELETE BY NAME\n|2.DELETE BY ID NUMBER\n");
	printf("ENTER YOUR CHOICE");
	scanf("%d",&choice9);
	switch(choice9)
	{
		case 1:
			{
				printf("ENTER THE NAME OF THE EMPLOYEE");
				scanf(" %[^\n]s",&name1);
				for(int i=0;i<count_emp;i++)
				{
					if(strcmp(employee[i].name,name1)==0)
					{
						for(int j=i;j<count_emp-1;j++)
						{
							employee[j]=employee[j+1];
						}
						return 1;
					
						
					}
				}
				printf("NO EMPLOYEE DATA FOUNDED\n");
				break;
			}
		case 2:
			{
				printf("ENTER THE ID NUMBER OF THE EMPLOYEE YOU WANTED TO DELETE");
				scanf("%d",&id1);
				for(int i=0;i<count_emp;i++)
				{
					if(employee[i].id==id1)
					{
						for(int j=i;j<count_emp-1;j++)
						{
							employee[j]=employee[j+1];
						}
						return 1;
						
					}
				}
				printf("NO EMPLOYEE OF ID NUMBER %d FOUND\n",id1);
				break;
				
			}
			default:
			{
				printf("you have entered a wrong choice\n");
			}
	}
	return 0;
}
void display_emp(data2 employee[],int count_emp)
{
	if(count_emp==0)
	{
		printf("NO EMPLOYEE YET\n");
	}
	else
	{
		for(int i=0;i<count_emp;i++)
		{
			printf("\t\t\t\t\tEMPLOYEE NUMBER %d\n",i+1);
			printf("::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
			printf("NAME OF THE EMPLOYEE==%s\n",employee[i].name);
			
			printf("SALARY OF THE EMPLOYEE==%.2f\n",employee[i].salary);
		
			printf("ID NUMBER OF THE EMPLOYEE==%d\n",employee[i].id);
			
	 		printf("AGE OF THE EPLOYEE==%d\n",employee[i].age);
			
			printf("POINTS OF THE EMPLOYEE==%d\n",employee[i].points);
			printf("::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
			
		}
	}
}

void search_car(manage car[],int count_car)
{
	int choice11;
	int model;
	char name[50];
	if(count_car!=0)
	{
		do
		{
			printf("1.SEARCH BY NAME\n2.SEARCH BY MODEL NUMBER\n3.BACK TO MENUE\n\n");
			printf("ENTER YOUR CHOICE\n");
			scanf("%d",&choice11);
			switch(choice11)
			{
				case 1:
					{
						printf("ENTER THE NAME OF THE CAR YOU WANT TO UPDATE\n");
						scanf(" %[^\n]s",name);
						for(int i=0;i<count_car;i++)
						{
							if(strcmp(car[i].name,name)==0)
							{
								printf("HERE IS YOUR DATA OF THE CAR %s\n",name);
								printf("::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
								printf("THE NAME OF THE CAR ==%s\n ",name);
								printf("THE MODEL NUMBER OF CAR IS %d\n",car[i].model);
								printf("THE PRICE OF THE CAR IS %.2f\n",car[i].price);
								printf("::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
								return;
								
								
							}
						}
						printf("NO CAR FOUNDED !!");
						break;
					}
				case 2:
					{
						printf("ENTER THE MODEL NUMBER OF THE CAR YOU WANT TO UPDATE ");
						scanf("%d",&model);
						for(int i=0;i<count_car;i++)
						{
							if(model==car[i].model)
							{
								printf("HERE IS YOUR DATA OF THE CAR %d\n",car[i].model);
								printf("::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
								printf("THE NAME OF THE CAR ==%s\n",car[i].name);
								printf("THE MODEL NUMBER OF CAR IS %d\n",car[i].model);
								printf("THE PRICE OF THE CAR IS %.2f\n",car[i].price);
								printf("::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
								return;
							}
						}
						printf("NO CAR FOUNDED!!\n");
						break;
					}
				case 3:
					{
						printf("GOING BACK TO MAIN MENUE\n");
						break;
					}
				default:
					{
						printf("INVALID CHOICE !! TRY GAIN!!\n");
					}
				
			}
			
		}while(choice11!=3);
		
		
	}
	else
	{
		printf("NO CAR AVAILABLE\n");
	}
	
}
void search_cust(data1 customer[],int count_cust)
{
	int id2;
	char name[50];
	int choice12;
	if(count_cust!=0)
	{
		do
		{
			printf("1.SEARCH BY NAME  \n2.SEARCH BY ID NUMBER \n3. BACK TO MENUE\nENTER YOUR CHOICE\n");
			scanf("%d",&choice12);
			switch(choice12)
			{
				case 1:
					{
						printf("ENTER THE NAME OF THE CUSTOMER\n");
						scanf(" %[^\n]s",name);
						for(int i=0;i<count_cust;i++)
						{
							if(strcmp(name,customer[i].name)==0)
							{
								printf("HERE IS THE DETAIL OF THE CUSTOMER\n\n");
								printf("::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
								printf("|THE NAME==%s\n|THE AGE IS==%d\n|THE ID NUMBER IS %d\n|THE GENDER IS %s\n",customer[i].name,customer[i].age,customer[i].id,customer[i].gender);
								printf("::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
								return;
							}
						
						}
						printf("NO CUSTOMER FOUNDED\n");
						break;
					}
				case 2:
					{
						printf("enter the id number of the customer");
						scanf("%d",&id2);
						for(int i=0;i<count_cust;i++)
						{
							if(id2==customer[i].id)
							{
								printf("HERE IS THE DETAIL OF THE CUSTOMER\n\n");
								printf("::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
								printf("|THE NAME==%s\n|THE AGE IS==%d\n|THE GENDER IS %s\n|THE ID NUMBER IS %d\n",customer[i].name,customer[i].age,customer[i].gender,customer[i].id);
								return;
							}
						}
						break;
					}
				case 3:
					{
						printf("going back to menue\n\n");
						break;
					}
				default:
					{
						printf("INVALID CHOICE TRY AGIN!!\n");
					}
			}
		}while(choice12!=3);
		
	}
	else
	{
		printf("NO CUSTOMER YET\n");
		return;
	}
}
void search_emp(data2 employee[],int count_emp)
{
	
	int id3;
	char name[50];
	int choice13;
	if(count_emp!=0)
	{
		do
		{
			printf("1.SEARCH BY NAME  \n2.SEARCH BY ID NUMBER \n3. BACK TO MENUE\nENTER YOUR CHOICE\n");
			scanf("%d",&choice13);
			switch(choice13)
			{
				case 1:
					{
						printf("ENTER THE NAME OF THE EMPLOYEE");
						scanf(" %[^\n]s",name);
						for(int i=0;i<count_emp;i++)
						{
							if(strcmp(name,employee[i].name)==0)
							{
								printf("HERE IS THE DETAIL OF THE CUSTOMER\n\n");
								printf("::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
								printf("THE NAME OF EMPLOYEE IS %s\n",employee[i].name);
								printf("THE ID NUMBER OF EMPLOYEE IS %d \n",employee[i].id);
								printf("THE AGE OF EMPLOYEE IS %d \n",employee[i].age);
								printf("THE POINTS NUMBER OF EMPLOYEE IS %d\n ",employee[i].points);
								printf("THE SALARY OF EMPLOYEE IS %f\n ",employee[i].salary);
								return ;
								
							}
						}
						
						printf("NO EMPLOYEE FOUNDED\n");
						break;
					}
				case 2:
					{
						printf("ENTER THE ID NUMBER OF THE EMPLOYEE");
						scanf("%d",&id3);
						for(int i=0;i<count_emp;i++)
						{
							if(id3==employee[i].id)
							{
								printf("HERE IS THE DETAIL OF THE CUSTOMER\n\n");
								printf("::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
								printf("THE NAME OF EMPLOYEE IS %s\n",employee[i].name);
								printf("THE ID NUMBER OF EMPLOYEE IS %d \n",employee[i].id);
								printf("THE AGE OF EMPLOYEE IS %d\n ",employee[i].age);
								printf("THE POINTS NUMBER OF EMPLOYEE IS %d \n",employee[i].points);
								printf("THE SALARY OF EMPLOYEE IS %f\n ",employee[i].salary);
								return ;
							}
						}
						break;
					}
				case 3:
					{
						printf("going back to menue\n\n");
						break;
					}
				default:
					{
						printf("INVALID CHOICE TRY AGIN!!\n");
					}
			}
		}while(choice13!=3);
		
	}
	else
	{
		printf("NO EMPLOYEE YET YET\n");
		return ;
	}
}
void report_car(manage car[],int count_car)
{
	int found1,found2;
	if(count_car!=0)
	{
		
		printf("\t\t\t\tTHE CARS available IN SHOWROOM \n\n");
		printf("::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
		for(int i=0;i<count_car;i++)
		{	if(car[i].status==0)
			{
				printf("::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
				printf("%dcar %s\n:",i+1,car[i].name);
			}
		}
		printf("\t\t\t\tTHE CARS ON RENT \n\n");
		printf("::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
		for(int i=0;i<count_car;i++)
		{	if(car[i].status==1)
			{
				printf("::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
				printf("%dcar %s\n:",i+1,car[i].name);
			}
		}
			printf("::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
		int max1=car[0].price;
		int a=0;
		int min=car[0].price;
		int b=0;
		for(int i=1;i<count_car;i++)
		{
			if(max1<car[i].price)
			{
				max1=car[i].price;
				a=i;
			}
		}
		printf("\t\t\t\tTHE MOST EXPENSIVE CAR !!\n");
		printf("::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
		printf("THE MOST EXPENSIVE CAR IS %s \n",car[a].name);
		printf("THE PRICE OF CAR IS %.2f\n",car[a].price);
		printf("THE MODEL NUMBER OF CAR IS %d\n\n",car[a].model);
		printf("::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
	
		for(int i=0;i<count_car;i++)
		{
			if(min>car[i].price)
			{
				min=car[i].price;
				b=i;
			}
		}
		printf("\t\t\t\tTHE LEAST EXPENSIVE CAR IS !!\n");
		printf("::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
		printf("THE LEAST EXPENSIVE CAR IS %s \n",car[b].name);
		printf("THE PRICE OF CAR IS %.2f\n",car[b].price);
		printf("THE MODEL NUMBER OF CAR IS %d\n\n",car[b].model);
		printf("::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
		
	
	}
	else
	{
		printf("::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
		printf("\t\t\t\tYOU DID NOT SELL ANY CAR YET!!\n\n");
		printf("::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
		
	}
}
void report_cust(data1 customer[],int count_cust)
{
	if(count_cust!=0)
	{
	
	printf("\t\t\t\tOUR PAST CUSTOMER ARE AS FOLLOW \n\n");
	printf("::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
	for(int i=0;i<count_cust;i++)
	{
		printf("\t\t\t\tCUSTOMER NO %d\n\n",i+1);
		printf("::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
		printf("CUSTOMER      :%s\n",customer[i].name);
		printf("ID NUM#       :%d\n\n",customer[i].id);
		printf("::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
	}
		return;
	}
	
	
		printf("NO CUSTOMER YET!!\n");
		return;
	
}
void report_emp(data2 employee[],int count_emp)
{
	if(count_emp!=0)
	{
		for(int i=0;i<count_emp;i++)
		{
			printf("\t\t\t\tEMPLOYEE NO %d\n\n",i+1);
			printf("::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
			printf("EMPLOYEE NAME :   %s\n",employee[i].name);
			printf("EMPLOYEE ID NUM : %d\n",employee[i].id);
			printf("EMPLOYEE SALARY : %f\n",employee[i].salary);
			printf("EMPLOYEE POINTS : %d\n",employee[i].points);
			printf("::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
			printf("\t\t\t\tIF OUR EMPLOYEE IS ELIGIBLE FOR BONUS OR NOT!!\n\n");
			if(employee[i].points>7)
			{
				float a=0.0;
				a+=(employee[i].salary/100.0)*20.0;
				printf("NET INCOME IS %f",a);
				
			}
			else
			{
				printf("NET INCOME IS %.2f",employee[i].salary);
				
			}
		}
		
	}

}
// main body work
int main()
{
	int choice6, choice5, choice7,choice0;;
	int choice1,choice2,choice3,choice4;
	// variables for addition
		int count_car=0;
		int count_cust=0;
		int count_emp=0;
		int count_order=0;
		manage car[max];
		data1 customer[max];
		data2 employee[max];
		order c[max];
	// filling for reading 
	FILE *faddo1;
		faddo1=fopen("addo.txt","r");
		fscanf(faddo1,"%d\n",&count_order);
		for(int i=0;i<count_order;i++)
		{
			fscanf(faddo1,"%d;%d;%d;%f\n",&c[i].c_id,&c[i].car_id,&c[i].order_id,&c[i].total_price);
		}
			fclose(faddo1);
			
	FILE *fcar1;
	fcar1=fopen("car.txt","r");
	fscanf(fcar1,"%d\n",&count_car);
	for(int i=0;i<count_car;i++)
	{
		fscanf(fcar1,"%100[^;];%f;%d;%d\n",car[i].name,&car[i].price,&car[i].model,&car[i].status);
	}
		fclose(fcar1);
		
		
	FILE *fcust1;
	fcust1=fopen("cust.txt","r");
	fscanf(fcust1,"%d\n",&count_cust);
	for(int i=0;i<count_cust;i++)
	{
		fscanf(fcust1,"%50[^;];%50[^;];%d;%d\n",customer[i].name,customer[i].gender,&customer[i].age,&customer[i].id);
	}
		fclose(fcust1);
		
		
		FILE *femp1;
		femp1=fopen("emp.txt","r");
		fscanf(femp1,"%d\n",&count_emp);
		for(int i=0;i<count_emp;i++)
		{
			fscanf(femp1,"%50[^;];%d;%f;%d;%d",employee[i].name,&employee[i].age,&employee[i].salary,&employee[i].id,&employee[i].points);
												
		}
		fclose(femp1);	
		
		
		// start!!
	printf("\t\t\t\t\tRENT A CAR SYSTEM\n");
	printf("::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
	
	do									
	{
		printf("|1.MANAGE DATA\n|2.SEARCH DATA\n|3.REPORT OF THE DATA\n|4.SUSTEM SHUT DOWN\n|ENTER YOUR CHOICE");
		scanf("%d",&choice1);
		switch(choice1)
		{
			case 1:
				{
					printf("\t\t\t\t\tMANAGE DATA\n\n");
					printf("::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
					do
					{
						printf("|0.ORDER DATA\n|1.MANAGE CAR DATA\n|2.MANAGE CUSTOMER DATA\n|3.MANAGE EMPLOYEE DATA\n|4.BACK TO MENUE\n");
						printf("|ENTER YOUR CHOICE");
						scanf("%d",&choice2);
						switch(choice2)
						{
							case 0:
								{
									printf("\t\t\t\t\tORDER CAR \n");
									printf("::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
									do
									{
										printf("|1.ADD ORDER DATA\n|2.DELETE ORDER DATA\n|3.DISPLAY ORDERS\n|4.BACK TO MENUE\n");
										printf("ENTER YOUR CHOICE==");
										scanf("%d",&choice0);
										switch(choice0)
										{
											case 1:
												{
													printf("\t\t\t\t\tADD ORDER \n");
													printf("::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");\
													int k=add_order(c,customer,car,count_order,count_cust,count_car);
													if(k==1)
													{
														
														printf("ORDERED PLACED SUCCESSFULLY!!\n");
														count_order++;
													}
													break;
												}
											case 2:
												{
													printf("\t\t\t\t\tDELETE ORDER ORDER \n");
													printf("::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
													int f=DELETE_order(c,car,count_order,count_car);
													if(f==1)
													{
														count_order--;
														printf("DELETE ORDER SUCCESSFULLY");
													}
													break;
												}
											
											case 3:
												{
													printf("\t\t\t\t\tDISPLAY ORDER \n");
													printf("::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
													display_order(c,count_order);
													break;
												}
											case 4:
												{
													printf("\t\t\t\t\tBACK TO MENUE \n");
													printf("::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
													break;
												}
											default:
												{
													printf("INVALID CHOICE TY AGAIN!!\n");
												}	
										}
										FILE *faddo;
										faddo=fopen("addo.txt","w");
										fprintf(faddo,"%d\n",count_order);
										for(int i=0;i<count_order;i++)
										{
											fprintf(faddo,"%d;%d;%d;%f\n",c[i].c_id,c[i].car_id,c[i].order_id,c[i].total_price);
										}
										fclose(faddo);
									}while(choice0!=4);
									break;
								}
							case 1:
								{
									printf("\t\t\t\t\tMANAGE CAR DATA\n");
									printf("::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
								
										do
										{
											printf("|1.ADD CAR DATA\n|2.UPDATE CAR DATA\n|3.DELETE CAR DATA\n|4.DISPLAY CAR DATA\n|5.BACK TO MENUE\n");
											printf("ENTER YOUR CHOICE==");
											scanf("%d",&choice5);
											switch(choice5)
											{
												case 1:
													{
														printf("\t\t\t\t\tADD CAR DATA\n");
														printf("::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
														int c=add_car(car,count_car);
														if(c==1)
														{
															printf("CAR DATA ADDED SUCCESSFULLY!!\n");
															count_car++;
														}
														break;
													}
												case 2:
													{
														printf("\t\t\t\t\tUPDATE CAR DATA\n");
														printf("::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
														upp_car( car,count_car);
														break;
													}
												case 3:
													{
														printf("\t\t\t\t\tDELETE CAR DATA\n");
														printf("::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
														int b=del_car(car,count_car);
														if(b==1)
														{
															printf("CAR DATA OF given MODEL  IS DELETED SUCCESSFULLY!!!\n");
															count_car--;
														}
														break;
													}
												case 4:
													{
														printf("\t\t\t\t\tDISPLAY CAR DATA\n");
														printf("::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
														display_car(car,count_car);
														break;
													}
												case 5:
													{
														printf("\t\t\t\t\t BACK TO MENUE\n");
														printf("::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
														break;
													}
												default:
													{
														printf("TRY AGAIN");
													}
											}
											
											FILE *fcar;
											fcar=fopen("car.txt","w");
											fprintf(fcar,"%d\n",count_car);
											for(int i=0;i<count_car;i++)
											{
												fprintf(fcar,"%s;%f;%d;%d\n",car[i].name,car[i].price,car[i].model,car[i].status);
											}
											fclose(fcar);
										}while(choice5!=5);
	
									break;
								}
							case 2:
								{
									printf("\t\t\t\t\tMANAGE CUSTOMER DATA\n");
									printf("::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
										
											do
											{
												printf("|1.ADD CUSTOMER DATA\n|2.UPDATE CUSTOMER DATA\n|3.DELETE CUSTOMER DATA\n|4.DISPLAY CUSTOMER DATA\n|5.BACK TO MENUE\n");
												printf("ENTER YOUR CHOICE==");
												scanf("%d",&choice6);
												switch(choice6)
												{
													case 1:
														{
															printf("\t\t\t\t\tADD CUSTOMER DATA\n");
															printf("::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
															int c=add_cust(customer,count_cust);
															if(c==1)
															{
																printf("CUSTOMER DATA ADDED SUCCESSFULLY!!\n");
																count_cust++;
															}
															break;
														}
													case 2:
														{
															printf("\t\t\t\t\tUPDATE CUSTOMER DATA\n");
															printf("::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
															upp_cust(customer,count_cust);
															break;
														}
													case 3:
														{
															printf("\t\t\t\t\tDELETE CUSTOMER DATA\n");
															printf("::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
															int d=del_cust(customer,count_cust);
															if(d==1)
															{
																printf("CUSTOMER DATA OF NAME  IS DELETED SUCCESSFULLY!!!\n");
																count_cust--;
															}
															
															break;
														}
													case 4:
														{
															printf("\t\t\t\t\tDISPLAY CUSTOMER DATA\n");
															printf("::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
															display_cust(customer,count_cust);
															break;
														}
													case 5:
														{
															printf("\t\t\t\t\t BACK TO MENUE\n");
															printf("::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
															break;
														}
													default:
														{
															printf("TRY AGAIN");
														}
												}
												FILE *fcust;
												fcust=fopen("cust.txt","w");
												fprintf(fcust,"%d\n",count_cust);
												for(int i=0;i<count_cust;i++)
												{
													fprintf(fcust,"%s;%s;%d;%d\n",customer[i].name,customer[i].gender,customer[i].age,customer[i].id);
												}
												fclose(fcust);
											}while(choice6!=5);
									break;
								}
							case 3:
								{
									printf("\t\t\t\t\tMANAGE EMPLOYEE DATA\n");
									printf("::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
							
									do
										{
											printf("|1.ADD EMPLOYEE DATA\n|2.UPDATE EMPLOYEE DATA\n|3.DELETE EMPLOYEE DATA\n|4.DISPLAY EMPLOYEE DATA\n|5.BACK TO MENUE\n");
											printf("ENTER YOUR CHOICE==");
											scanf("%d",&choice7);
											switch(choice7)
											{
												case 1:
													{
														printf("::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
														printf("\t\t\t\t\tADD EMPLOYEE DATA\n");
														printf("::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
														int e=add_emp(employee,count_emp);
														if(e==1)
														{
															printf("employee data added successfully!!\n");
															count_emp++;
														}
														break;
													}
												case 2:
													{
														printf("::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
														printf("\t\t\t\t\tUPDATE EMPLOYEE DATA\n");
														printf("::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
														upp_emp(employee,count_emp);
														break;
													}
												case 3:
													{
														printf("::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
														printf("\t\t\t\t\tDELETE EMPLOYEE DATA\n");
														printf("::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
														int f=del_emp(employee,count_emp);
														if(f==1)
														{
															printf("employee data deleted successfully!!\n");
															count_emp--;
														}
														
														break;
													}
												case 4:
													{
														printf("::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
														printf("\t\t\t\t\tDISPLAY EMPLOYEE DATA\n");
														printf("::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
														display_emp(employee,count_emp);
														break;
													}
												case 5:
													{
														printf("::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
														printf("\t\t\t\t\t BACK TO MENUE\n");
														printf("::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
														break;
													}
												default:
													{
														printf("TRY AGAIN");
													}
											}
											FILE *femp;
											femp=fopen("emp.txt","w");
											fprintf(femp,"%d\n",count_emp);
											for(int i=0;i<count_emp;i++)
											{
												fprintf(femp,"%s;%d;%f;%d;%d",employee[i].name,employee[i].age,employee[i].salary,employee[i].id,employee[i].points);
												
											}
											fclose(femp);
										}while(choice7!=5);
														break;
								}
							case 4:
								{
									printf("\t\t\t\t\tBACK TO MENUE\n");
									printf("::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
									break;
								}
							default:
								{
									printf("you have entered invalid choice\n");
						
								}
								
						}
					}while(choice2!=4);
				break;
				}
			case 2:
				{
						printf("\t\t\t\t\tSEARCH\n\n");
						printf("::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
					do
					{
						printf("|1.SEARCH CAR DATA\n|2.SEARCH CUSTOMER DATA\n|3.SEARCH EMPLOYEE DATA\n|4.BACK TO MENUE\n");
						printf("|ENTER YOUR CHOICE");
						scanf("%d",&choice3);
						switch(choice3)
						{
							case 1:
								{
									printf("\t\t\t\t\tSEARCH CAR DATA\n");
									printf("::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
									search_car(car,count_car);
									break;
								}
							case 2:
								{
									printf("\t\t\t\t\tSEARCH CUSTOMER DATA\n");
									printf("::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
									search_cust(customer,count_cust);
									break;
								}
							case 3:
								{
									printf("\t\t\t\t\tSEARCH EMPLOYEE DATA\n");
									printf("::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
									search_emp(employee,count_emp);
									break;
								}
							case 4:
								{
									printf("\t\t\t\t\tBACK TO MENUE\n");
									printf("::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
									break;
								}
							default:
								{
									printf("you have entered invalid choice\n");
						
								}
								
						}
					}while(choice3!=4);
				break;	
				}
			case 3:
				{
					printf("\t\t\t\t\tREPORT DATA\n");
					printf("::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
					do
					{
						printf("|1.REPORT OF THE CARS\n|2.REPORTS OF THE EMPLOYEE\n|3.REPORT OF CUSTOMERS\n|4.GOING BACK\n");
						printf("ENTER YOUR CHOICE");
						scanf("%d",&choice4);
						switch(choice4)
						{
							case 1:
								{
									printf("\t\t\t\t\tREPORT CARS DATA\n");
									printf("::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
									report_car(car,count_car);
									break;
								}
							case 2:
								{
									printf("\t\t\t\t\tREPORT EMPLOYEE DATA\n");
									printf("::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
									report_emp(employee,count_emp);
									break;
								}
							case 3:
								{
									printf("\t\t\t\t\tGOING BACK\n");
									printf("::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
									report_cust(customer,count_cust);
									break;
								}
								case 4:
									{
										printf("GOING BACK\n");
										break;
									}
							default:
								{
									printf("YOU HAVE ENTERED INVALID CHOICE\n");
								}
						}
					}while(choice4!=4);
					
					
				}
			case 4:
				{
					printf("\t\t\t\t\tSUSTEM SHUT DOWN\n");
					printf("::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
					break;
				}
			default:
				{
					printf("YOU HAVE ENTERED INVALID CHOICE\n");
				}
		}
	}while(choice1!=4);
	
	
	return 0;
}



















