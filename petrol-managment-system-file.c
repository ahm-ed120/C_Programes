#include <stdio.h>
#include <stdlib.h>

typedef struct petrol
{
    int transactionId;
    char date[12];
    float petrolAmount;
    float pricePerLiter;
    float totalPrice;
} petrol;

void addData()
{
    int n;
    petrol *p;

    FILE *fdata;

    printf("How many transactions you want to enter : ");
    scanf("%d", &n);

    p = (petrol *)calloc(n, sizeof(petrol));

    fdata = fopen("petrol-managment.txt", "w");

    for (int i = 0; i < n; i++)
    {
        printf("Enter the transaction ID : ");
        scanf("%d", &p[i].transactionId);
        fflush(stdin);

        printf("Enter the date (dd-mm-yyyy) : ");
        scanf("%s", p[i].date);

        printf("Enter the amount of petrol (liters) : ");
        scanf("%f", &p[i].petrolAmount);

        printf("Enter the price per liter : ");
        scanf("%f", &p[i].pricePerLiter);

        p[i].totalPrice = p[i].petrolAmount * p[i].pricePerLiter;
        fwrite(&p[i], sizeof(petrol), 1, fdata);
    }
    fclose(fdata);
}

void displayData()
{
    printf("\n");
    petrol p1;
    FILE *fdata;

    fdata = fopen("petrol-managment.txt", "r");

    printf("TRANSACTION ID     DATE          PETROL AMOUNT(L)    PRICE/LITER    TOTAL PRICE\n");

    while (fread(&p1, sizeof(petrol), 1, fdata))
    {
        printf("%-17d%-14s%-20.2f%-15.2f%.2f\n", p1.transactionId, p1.date, p1.petrolAmount, p1.pricePerLiter, p1.totalPrice);
    }

    fclose(fdata);
}

void appendData()
{
    int n;
    petrol *p;

    FILE *fdata;

    printf("How many transactions you want to enter : ");
    scanf("%d", &n);

    p = (petrol *)calloc(n, sizeof(petrol));

    fdata = fopen("petrol-managment.txt", "a");

    for (int i = 0; i < n; i++)
    {
        printf("Enter the transaction ID : ");
        scanf("%d", &p[i].transactionId);
        fflush(stdin);

        printf("Enter the date (dd-mm-yyyy) : ");
        scanf("%s", p[i].date);

        printf("Enter the amount of petrol (liters) : ");
        scanf("%f", &p[i].petrolAmount);

        printf("Enter the price per liter : ");
        scanf("%f", &p[i].pricePerLiter);

        p[i].totalPrice = p[i].petrolAmount * p[i].pricePerLiter;
        fwrite(&p[i], sizeof(petrol), 1, fdata);
    }
    fclose(fdata);
}

void noOfRec()
{
    petrol p1;
    FILE *fdata;
    fdata = fopen("petrol-managment.txt", "r");
    fseek(fdata, 0, SEEK_END);
    int n = ftell(fdata) / sizeof(petrol);
    printf("\n\nNO OF RECORDS = %d", n);
    fclose(fdata);
}

void search()
{
    printf("\n");

    int tid;
    int found = 0;
    petrol p1;

    FILE *fdata;

    fdata = fopen("petrol-managment.txt", "r");

    printf("Enter transaction ID you want to search\n");
    scanf("%d", &tid);

    while (fread(&p1, sizeof(petrol), 1, fdata))
    {
        if (p1.transactionId == tid)
        {
            found = 1;

            printf("TRANSACTION ID     DATE          PETROL AMOUNT(L)    PRICE/LITER    TOTAL PRICE\n");
            printf("%-17d%-14s%-20.2f%-15.2f%.2f\n", p1.transactionId, p1.date, p1.petrolAmount, p1.pricePerLiter, p1.totalPrice);
        }
    }
    if (found == 0)
    {
        printf("\nRecord not found\n");
    }
    fclose(fdata);
}

void update()
{
    printf("\n");

    int tid;
    int found = 0;
    petrol p1;

    FILE *fdata, *ftemp;

    fdata = fopen("petrol-managment.txt", "r");
    ftemp = fopen("temp.txt", "w");

    printf("Enter transaction ID you want to update\n");
    scanf("%d", &tid);

    while (fread(&p1, sizeof(petrol), 1, fdata))
    {
        if (p1.transactionId == tid)
        {
            found = 1;

            printf("Enter the date (dd-mm-yyyy) : ");
            scanf("%s", p1.date);

            printf("Enter the amount of petrol (liters) : ");
            scanf("%f", &p1.petrolAmount);

            printf("Enter the price per liter : ");
            scanf("%f", &p1.pricePerLiter);

            p1.totalPrice = p1.petrolAmount * p1.pricePerLiter;
        }
        fwrite(&p1, sizeof(petrol), 1, ftemp);
    }

    fclose(fdata);
    fclose(ftemp);

    if (found == 1)
    {
        ftemp = fopen("temp.txt", "r");
        fdata = fopen("petrol-managment.txt", "w");

        while (fread(&p1, sizeof(petrol), 1, ftemp))
        {
            fwrite(&p1, sizeof(petrol), 1, fdata);
        }

        fclose(fdata);
        fclose(ftemp);
    }
    else
    {
        printf("\nRecord not found\n");
    }
}

void delete()
{
    printf("\n");

    int tid;
    int found = 0;
    petrol p1;

    FILE *fdata, *ftemp;

    fdata = fopen("petrol-managment.txt", "r");
    ftemp = fopen("temp.txt", "w");

    printf("Enter transaction ID you want to delete\n");
    scanf("%d", &tid);

    while (fread(&p1, sizeof(petrol), 1, fdata))
    {
        if (p1.transactionId == tid)
        {
            found = 1;
        }
        else
        {
            fwrite(&p1, sizeof(petrol), 1, ftemp);
        }
    }

    fclose(fdata);
    fclose(ftemp);

    if (found == 1)
    {
        ftemp = fopen("temp.txt", "r");
        fdata = fopen("petrol-managment.txt", "w");

        while (fread(&p1, sizeof(petrol), 1, ftemp))
        {
            fwrite(&p1, sizeof(petrol), 1, fdata);
        }

        fclose(fdata);
        fclose(ftemp);
    }
    else
    {
        printf("\nRecord not found\n");
    }
}

int main()
{
    int choice;
    do
    {
        printf("\n\n1. ADD");
        printf("\n2. DISPLAY");
        printf("\n3. APPEND");
        printf("\n4. NO. OF RECORDS");
        printf("\n5. SEARCH");
        printf("\n6. UPDATE");
        printf("\n7. DELETE");
        printf("\n0. EXIT");

        printf("\n\nEnter your choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addData();
            break;

        case 2:
            displayData();
            break;

        case 3:
            appendData();
            break;

        case 4:
            noOfRec();
            break;

        case 5:
            search();
            break;

        case 6:
            update();
            break;

        case 7:
            delete ();
            break;

        case 0:
            printf("\nExiting the program...\n");
            break;

        default:
            printf("\nInvalid input!!!\n");
        }

    } while (choice != 0);

    return 0;
}