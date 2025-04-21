/*Author : Ahmedullah
  Date   : 16/12/2023
  code for resturant managment getting orders and printting total bill*/
#include <stdio.h>
#include <conio.h>
// Declare two function for menu and calculate bill
void Display_menu();
float Calculate(int quantity , float price);
void Display_menu() // function for show menu
 {
 	
    printf("-------- Menu of restaurant --------\t\t\n\n");
    printf("1. Burger - $350\n");
    printf("2. Frie/s - $150\n");
    printf("3. Sandwich - $200\n");
    printf("4. Pasta - $480\n");
    printf("5. Margherita Pizza - $1200\n");
    printf("6. Pepperoni Pizza - $1250\n");
    printf("7. Veggie Pizza - $900\n");
    printf("8. Hawaiian Pizza - $1050\n");
    printf("9. BBQ Chicken Pizza - $1350\n");
    printf("10. Shwarma - $170\n\n");
    printf("\t\tHave a nice day Sir/Ma'am\n\n");
}

float Calculate(int quantity , float price) 
{
     return quantity*price;  // calulate the bill
}
int main()
{
       int quantity,choice_of_items;
       float price,bill,payment;
       char order_confirmation; 
      
       printf("Heya ! babes love yaa muuuaaahh\n\n");
       
       
      printf("--- Welcome to our Restaurent ---\n\n"); 

     Display_menu();// calling display manu Function 
     printf("Slect the item that you want to order\n");
     scanf("%d",&choice_of_items);
      printf("Enter quantity of items\n");  
      scanf("%d",&quantity); // user  the quantity

        switch (choice_of_items)   // set the prize of each items 
        {
        case 1:
            price = 350.0;
            break;
        case 2:
            price = 150.0;
            break;
        case 3:
            price = 200.0;
            break;
        case 4:
            price = 480.0;
            break;
        case 5:
            price = 1200.0;
            break;
        case 6:
            price = 1250.0;
            break;
        case 7:
            price = 900.0;
            break;
        case 8:
            price = 1050.0;
            break;
        case 9:
            price = 1350.0;
            break;
        case 10:
            price = 170.0;
            break;
        default:
            printf("Invalid choice!\n");
            return 0;
    } 
    
    //call the function that calulate total bill and store it in (bill) variable
      bill = Calculate(quantity,price); 

     printf("\n---Details of Order---\n\n");
     printf("item Number : %d\n\n",choice_of_items);
     printf("Quantity of items : %d\n\n",quantity);
     printf("Cost per item : %.1f\n\n",price);
     printf("For Confirm your order press (y) And for cancel you order press(n)\n\n");
     order_confirmation=getch();
     if(order_confirmation=='y'||order_confirmation=='Y')
     {
            printf("Total bill = %.1f\n",bill);
            // add sale tax 7%
            payment=(bill*0.07)+bill;
            printf("Total Payment after 7%% GST = %.1f \n\n",payment);

            printf("Thank you for your order\n");
     }
     else if (order_confirmation=='n'||order_confirmation=='N') {
          printf("Order Cancelled!!\n");
     }

     return 0;  

}
