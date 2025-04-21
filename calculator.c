#include<stdio.h>
float result = 0;

// Function declarations
void multiply(float num1, float num2);
void divide(float num1, float num2);
void subtract(float num1, float num2);
void add(float num1, float num2);
void display();

int main() {
    int operation;
    int menu;
    float num1, num2;
    
    do {
        printf("\t\t\t\t SIMPLE CALCULATOR\n");
        printf("=> Open MENU: ");
        scanf("%d",&menu);
        printf(" 1: Multiplication\n");
        printf(" 2: Division\n");
        printf(" 3: Subtraction\n");
        printf(" 4: Addition\n");
        printf(" 5: Previous Answer\n");
        printf(" 6. Exit\n");
        printf("=> Enter your Operation: ");
        scanf("%d", &operation);
        
        switch(operation) {
            case 1:
                printf("Enter Numbers To Multiply:\n");
                printf(" Num 1: ");
                scanf("%f", &num1);
                printf(" Num 2: ");
                scanf("%f", &num2);
                multiply(num1, num2);
                break;
            case 2:
                printf("Enter Numbers To Divide:\n");
                printf(" Num 1: ");
                scanf("%f", &num1);
                printf(" Num 2: ");
                scanf("%f", &num2);
                divide(num1, num2);
                break;
            case 3:
                printf("Enter Numbers To Subtract:\n");
                printf(" Num 1: ");
                scanf("%f", &num1);
                printf(" Num 2: ");
                scanf("%f", &num2);
                subtract(num1, num2);
                break;
            case 4:
                printf("Enter Numbers To Add:\n");
                printf(" Num 1: ");
                scanf("%f", &num1);
                printf(" Num 2: ");
                scanf("%f", &num2);
                add(num1, num2);
                break;
            case 5:
                display();
                break;
            case 6:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (operation != 6);
    
    return 0;
}

// Function definitions
void multiply(float num1, float num2) {
    result = num1 * num2;
    printf("Your Current Answer is : %.2f\n", result);
}

void divide(float num1, float num2) {
    if (num2 == 0) {
        printf("Error! Division by zero.\n");
    }
    else if (num1 == 0) {
        printf("Your Current Answer is INFINITE!\n");
    }
    else {
        result = num1 / num2;
        printf("Your Current Answer is : %.2f\n", result);
    }
}

void subtract(float num1, float num2) {
    result = num1 - num2;
    printf("Your Current Answer is : %.2f\n", result);
}

void add(float num1, float num2) {
    result = num1 + num2;
    printf("Your Current Answer is : %.2f\n", result);
}

void display() {
    printf("Your Previous Answer is %.2f\n", result);
}