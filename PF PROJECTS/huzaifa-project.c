#include <stdio.h>
#include <string.h>

#define MAX_RECORD 100

typedef struct PetrolStation
{
    int stationId;
    char stationName[50];
    char location[100];
} PetrolStation;

typedef struct FuelType
{
    int fuelId;
    char fuelName[50];
    float pricePerLitre;
} FuelType;

typedef struct Customer
{
    int customerId;
    char customerName[50];
    char phone[15];
    char address[100];
} Customer;

typedef struct Transaction
{
    int transactionId;
    int customerId;
    int stationId;
    int fuelId;
    float quantity;
    float totalPrice;
} Transaction;

void addStation(PetrolStation stations[MAX_RECORD], int stationCount);
void updateStation(PetrolStation stations[MAX_RECORD], int stationCount);
int deleteStation(PetrolStation stations[MAX_RECORD], int stationCount);
void displayStations(PetrolStation stations[MAX_RECORD], int stationCount);

void addFuel(FuelType fuels[MAX_RECORD], int fuelCount);
void updateFuel(FuelType fuels[MAX_RECORD], int fuelCount);
int deleteFuel(FuelType fuels[MAX_RECORD], int fuelCount);
void displayFuels(FuelType fuels[MAX_RECORD], int fuelCount);

void addCustomer(Customer customers[MAX_RECORD], int customerCount);
void updateCustomer(Customer customers[MAX_RECORD], int customerCount);
int deleteCustomer(Customer customers[MAX_RECORD], int customerCount);
void displayCustomers(Customer customers[MAX_RECORD], int customerCount);

int addTransaction(PetrolStation stations[MAX_RECORD], FuelType fuels[MAX_RECORD], Customer customers[MAX_RECORD], Transaction transactions[MAX_RECORD], int stationCount, int fuelCount, int customerCount, int transactionCount);
void updateTransaction(PetrolStation stations[MAX_RECORD], FuelType fuels[MAX_RECORD], Customer customers[MAX_RECORD], Transaction transactions[MAX_RECORD], int stationCount, int fuelCount, int customerCount, int transactionCount);
int deleteTransaction(Transaction transactions[MAX_RECORD], int transactionCount);
void displayTransactions(Transaction transactions[MAX_RECORD], int transactionCount);

void search(PetrolStation stations[MAX_RECORD], FuelType fuels[MAX_RECORD], Customer customers[MAX_RECORD], Transaction transactions[MAX_RECORD], int stationCount, int fuelCount, int customerCount, int transactionCount);

void searchStations(PetrolStation stations[MAX_RECORD], int stationCount);
void searchStationByName(PetrolStation stations[MAX_RECORD], int stationCount);
void searchStationById(PetrolStation stations[MAX_RECORD], int stationCount);

void searchFuels(FuelType fuels[MAX_RECORD], int fuelCount);
void searchFuelByName(FuelType fuels[MAX_RECORD], int fuelCount);
void searchFuelById(FuelType fuels[MAX_RECORD], int fuelCount);

void searchCustomers(Customer customers[MAX_RECORD], int customerCount);
void searchCustomerByName(Customer customers[MAX_RECORD], int customerCount);
void searchCustomerById(Customer customers[MAX_RECORD], int customerCount);

void searchTransactions(Transaction transactions[MAX_RECORD], int transactionCount);
void searchTransactionByCustomerId(Transaction transactions[MAX_RECORD], int transactionCount);
void searchTransactionById(Transaction transactions[MAX_RECORD], int transactionCount);

void displayReport(PetrolStation stations[MAX_RECORD], FuelType fuels[MAX_RECORD], Customer customers[MAX_RECORD], Transaction transactions[MAX_RECORD], int stationCount, int fuelCount, int customerCount, int transactionCount);
void displayStationReport(PetrolStation stations[MAX_RECORD], Transaction transactions[MAX_RECORD], int stationCount, int transactionCount);
void displayFuelReport(FuelType fuels[MAX_RECORD], Transaction transactions[MAX_RECORD], int fuelCount, int transactionCount);
void displayCustomerReport(Customer customers[MAX_RECORD], int customerCount);
void displayTransactionReport(Transaction transactions[MAX_RECORD], int transactionCount);

int main()
{

    PetrolStation stations[MAX_RECORD];
    FuelType fuels[MAX_RECORD];
    Customer customers[MAX_RECORD];
    Transaction transactions[MAX_RECORD];

    int stationCount = 0;
    int fuelCount = 0;
    int customerCount = 0;
    int transactionCount = 0;

    int choice, choice1, choice2, choice3, choice4, choice5;
    int w, x, y, z, f;

    FILE *fstation1;
    fstation1 = fopen("station.txt", "r");

    fscanf(fstation1, "%d\n", &stationCount);

    for (int i = 0; i < stationCount; i++)
    {
        fscanf(fstation1, "%d;%50[^;];%100[^\n]\n", &stations[i].stationId, stations[i].stationName, stations[i].location);
    }

    fclose(fstation1);

    FILE *ffuel1;
    ffuel1 = fopen("fuel.txt", "r");

    fscanf(ffuel1, "%d\n", &fuelCount);

    for (int i = 0; i < fuelCount; i++)
    {
        fscanf(ffuel1, "%d;%50[^;];%f", &fuels[i].fuelId, fuels[i].fuelName, &fuels[i].pricePerLitre);
    }

    fclose(ffuel1);

    FILE *fcustomer1;
    fcustomer1 = fopen("customer.txt", "r");

    fscanf(fcustomer1, "%d\n", &customerCount);

    for (int i = 0; i < customerCount; i++)
    {
        fscanf(fcustomer1, "%d;%50[^;];%15[^;];%100[^\n]\n", &customers[i].customerId, customers[i].customerName, customers[i].phone, customers[i].address);
    }

    fclose(fcustomer1);

    FILE *ftransaction1;
    ftransaction1 = fopen("transaction.txt", "r");

    fscanf(ftransaction1, "%d\n", &transactionCount);

    for (int i = 0; i < transactionCount; i++)
    {
        fscanf(ftransaction1, "%d;%d;%d;%d;%f;%f\n", &transactions[i].transactionId, &transactions[i].customerId, &transactions[i].stationId, &transactions[i].fuelId, &transactions[i].quantity, &transactions[i].totalPrice);
    }

    fclose(ftransaction1);

    printf("***********Petrol Management System***********\n\n");
    do
    {
        printf("1. MANAGE DATA\n");
        printf("2. SEARCH\n");
        printf("3. REPORT\n");
        printf("0. EXIT\n");

        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            do
            {
                printf("\n******MANAGE DATA******\n\n");
                printf("1. MANAGE PETROL STATIONS\n");
                printf("2. MANAGE FUEL TYPES\n");
                printf("3. MANAGE CUSTOMERS\n");
                printf("4. MANAGE TRANSACTIONS\n");
                printf("0. EXIT\n");
                scanf("%d", &choice1);

                switch (choice1)
                {
                case 1:
                    do
                    {
                        printf("\nMANAGE PETROL STATIONS:\n");
                        printf("1. ADD STATION\n");
                        printf("2. UPDATE STATION\n");
                        printf("3. DISPLAY STATIONS\n");
                        printf("4. DELETE STATION\n");
                        printf("5. EXIT\n");

                        scanf("%d", &choice2);

                        switch (choice2)
                        {
                        case 1:
                            addStation(stations, stationCount);
                            stationCount++;
                            break;

                        case 2:
                            updateStation(stations, stationCount);
                            break;

                        case 3:
                            displayStations(stations, stationCount);
                            break;

                        case 4:
                            w = deleteStation(stations, stationCount);

                            if (w == 1)
                            {
                                stationCount--;
                            }
                            else
                            {
                                printf("Station not found !!!\n");
                            }
                            break;

                        case 5:
                            break;

                        default:
                            printf("Invalid input!!!\n");
                            break;
                        }

                        FILE *fstation;
                        fstation = fopen("station.txt", "w");

                        fprintf(fstation, "%d\n", stationCount);
                        for (int i = 0; i < stationCount; i++)
                        {
                            fprintf(fstation, "%d;%s;%s\n", stations[i].stationId, stations[i].stationName, stations[i].location);
                        }

                        fclose(fstation);

                    } while (choice2 != 5);
                    break;

                case 2:
                    do
                    {
                        printf("\nMANAGE FUEL TYPES:\n");
                        printf("1. ADD FUEL\n");
                        printf("2. UPDATE FUEL\n");
                        printf("3. DISPLAY FUELS\n");
                        printf("4. DELETE FUEL\n");
                        printf("5. EXIT\n");

                        scanf("%d", &choice3);

                        switch (choice3)
                        {
                        case 1:
                            addFuel(fuels, fuelCount);
                            fuelCount++;
                            break;

                        case 2:
                            updateFuel(fuels, fuelCount);
                            break;

                        case 3:
                            displayFuels(fuels, fuelCount);
                            break;

                        case 4:
                            x = deleteFuel(fuels, fuelCount);
                            if (x == 1)
                            {
                                fuelCount--;
                            }
                            else
                            {
                                printf("Fuel not found !!!\n");
                            }
                            break;

                        case 5:
                            break;

                        default:
                            printf("Invalid input!!!\n");
                            break;
                        }

                        FILE *ffuel;
                        ffuel = fopen("fuel.txt", "w");

                        fprintf(ffuel, "%d\n", fuelCount);

                        for (int i = 0; i < fuelCount; i++)
                        {
                            fprintf(ffuel, "%d;%s;%.2f", fuels[i].fuelId, fuels[i].fuelName, fuels[i].pricePerLitre);
                        }

                        fclose(ffuel);

                    } while (choice3 != 5);
                    break;

                case 3:
                    do
                    {
                        printf("\nMANAGE CUSTOMERS:\n");
                        printf("1. ADD CUSTOMER\n");
                        printf("2. UPDATE CUSTOMER\n");
                        printf("3. DISPLAY CUSTOMERS\n");
                        printf("4. DELETE CUSTOMER\n");
                        printf("5. EXIT\n");

                        scanf("%d", &choice4);

                        switch (choice4)
                        {
                        case 1:
                            addCustomer(customers, customerCount);
                            customerCount++;
                            break;

                        case 2:
                            updateCustomer(customers, customerCount);
                            break;

                        case 3:
                            displayCustomers(customers, customerCount);
                            break;

                        case 4:
                            y = deleteCustomer(customers, customerCount);
                            if (y == 1)
                            {
                                customerCount--;
                            }
                            else
                            {
                                printf("Customer not found !!!\n");
                            }
                            break;

                        case 5:
                            break;

                        default:
                            printf("Invalid input!!!\n");
                            break;
                        }

                        FILE *fcustomer;
                        fcustomer = fopen("customer.txt", "w");

                        fprintf(fcustomer, "%d\n", customerCount);

                        for (int i = 0; i < customerCount; i++)
                        {
                            fprintf(fcustomer, "%d;%s;%s;%s\n", customers[i].customerId, customers[i].customerName, customers[i].phone, customers[i].address);
                        }

                        fclose(fcustomer);

                    } while (choice4 != 5);
                    break;

                case 4:
                    do
                    {
                        printf("\nMANAGE TRANSACTIONS:\n");
                        printf("1. ADD TRANSACTION\n");
                        printf("2. UPDATE TRANSACTION\n");
                        printf("3. DISPLAY TRANSACTIONS\n");
                        printf("4. DELETE TRANSACTION\n");
                        printf("5. EXIT\n");

                        scanf("%d", &choice5);

                        switch (choice5)
                        {
                        case 1:
                            f = addTransaction(stations, fuels, customers, transactions, stationCount, fuelCount, customerCount, transactionCount);
                            if (f == 1)
                            {
                                transactionCount++;
                            }
                            break;

                        case 2:
                            updateTransaction(stations, fuels, customers, transactions, stationCount, fuelCount, customerCount, transactionCount);
                            break;

                        case 3:
                            displayTransactions(transactions, transactionCount);
                            break;

                        case 4:
                            z = deleteTransaction(transactions, transactionCount);
                            if (z == 1)
                            {
                                transactionCount--;
                            }
                            else
                            {
                                printf("Transaction not found !!!\n");
                            }
                            break;

                        case 5:
                            break;

                        default:
                            printf("Invalid input!!!\n");
                            break;
                        }

                        FILE *ftransaction;
                        ftransaction = fopen("transaction.txt", "w");

                        fprintf(ftransaction, "%d\n", transactionCount);

                        for (int i = 0; i < transactionCount; i++)
                        {
                            fprintf(ftransaction, "%d;%d;%d;%d;%.2f;%.2f\n", transactions[i].transactionId, transactions[i].customerId, transactions[i].stationId, transactions[i].fuelId, transactions[i].quantity, transactions[i].totalPrice);
                        }

                        fclose(ftransaction);

                    } while (choice5 != 5);
                    break;

                case 0:
                    break;

                default:
                    printf("Invalid input!!!\n");
                    break;
                }
            } while (choice1 != 0);
            break;

        case 2:
            search(stations, fuels, customers, transactions, stationCount, fuelCount, customerCount, transactionCount);
            break;

        case 3:
            displayReport(stations, fuels, customers, transactions, stationCount, fuelCount, customerCount, transactionCount);
            break;

        case 0:
            printf("Exiting program .......\n");
            break;

        default:
            printf("Invalid input. Please try again!!!\n");
            break;
        }
    } while (choice != 0);
    return 0;
}

void addStation(PetrolStation stations[MAX_RECORD], int stationCount)
{
    printf("Enter Station ID:\n");
    scanf("%d", &stations[stationCount].stationId);

    printf("Enter Station Name:\n");
    scanf(" %[^\n]s", stations[stationCount].stationName);

    printf("Enter Location:\n");
    scanf(" %[^\n]s", stations[stationCount].location);

    printf("Station added successfully!!\n");
}

void updateStation(PetrolStation stations[MAX_RECORD], int stationCount)
{
    int id;
    printf("Enter Station ID to update:\n");
    scanf("%d", &id);

    for (int i = 0; i < stationCount; i++)
    {
        if (stations[i].stationId == id)
        {
            printf("Enter new Station Name:\n");
            scanf(" %[^\n]s", stations[i].stationName);

            printf("Enter new Location:\n");
            scanf(" %[^\n]s", stations[i].location);

            printf("Station updated successfully!!\n");
            return;
        }
    }
    printf("Station ID not found!!\n");
}

int deleteStation(PetrolStation stations[MAX_RECORD], int stationCount)
{
    int id, found = -1;
    printf("Enter Station ID to delete:\n");
    scanf("%d", &id);

    for (int i = 0; i < stationCount; i++)
    {
        if (stations[i].stationId == id)
        {
            found = i;
            break;
        }
    }

    if (found == -1)
    {
        return 0;
    }

    else
    {
        for (int j = found; j < stationCount - 1; j++)
        {
            stations[j] = stations[j + 1];
        }

        printf("Station deleted successfully!!\n");
        return 1;
    }
}

void displayStations(PetrolStation stations[MAX_RECORD], int stationCount)
{
    for (int i = 0; i < stationCount; i++)
    {
        printf("\nStation %d:\n", i + 1);
        printf("ID: %d, Name: %s, Location: %s\n", stations[i].stationId, stations[i].stationName, stations[i].location);
    }
    if (stationCount == 0)
    {
        printf("No stations available!!!\n");
    }
}

void addFuel(FuelType fuels[MAX_RECORD], int fuelCount)
{
    printf("Enter Fuel ID:\n");
    scanf("%d", &fuels[fuelCount].fuelId);

    printf("Enter Fuel Type:\n");
    scanf(" %[^\n]s", fuels[fuelCount].fuelName);

    printf("Enter Price Per Litre:\n");
    scanf("%f", &fuels[fuelCount].pricePerLitre);

    printf("Fuel added successfully!!\n");
}

void updateFuel(FuelType fuels[MAX_RECORD], int fuelCount)
{
    int id;
    printf("Enter Fuel ID to update:\n");
    scanf("%d", &id);

    for (int i = 0; i < fuelCount; i++)
    {
        if (fuels[i].fuelId == id)
        {
            printf("Enter new Fuel Type:\n");
            scanf(" %[^\n]s", fuels[i].fuelName);

            printf("Enter new Price Per Litre:\n");
            scanf("%f", &fuels[i].pricePerLitre);

            printf("Fuel updated successfully!!\n");
            return;
        }
    }
    printf("Fuel ID not found!!\n");
}

int deleteFuel(FuelType fuels[MAX_RECORD], int fuelCount)
{
    int id, found = -1;
    printf("Enter Fuel ID to delete:\n");
    scanf("%d", &id);

    for (int i = 0; i < fuelCount; i++)
    {
        if (fuels[i].fuelId == id)
        {
            found = i;
            break;
        }
    }

    if (found == -1)
    {
        return 0;
    }

    else
    {
        for (int j = found; j < fuelCount - 1; j++)
        {
            fuels[j] = fuels[j + 1];
        }

        printf("Fuel deleted successfully!!\n");
        return 1;
    }
}

void displayFuels(FuelType fuels[MAX_RECORD], int fuelCount)
{
    for (int i = 0; i < fuelCount; i++)
    {
        printf("\nFuel %d:\n", i + 1);
        printf("ID: %d, Fuel Type: %s, Price Per Litre: %.2f\n", fuels[i].fuelId, fuels[i].fuelName, fuels[i].pricePerLitre);
    }
    if (fuelCount == 0)
    {
        printf("No fuels available!!!\n");
    }
}

void addCustomer(Customer customers[MAX_RECORD], int customerCount)
{
    printf("Enter Customer ID:\n");
    scanf("%d", &customers[customerCount].customerId);

    printf("Enter Customer Name:\n");
    scanf(" %[^\n]s", customers[customerCount].customerName);

    printf("Enter Phone:\n");
    scanf(" %[^\n]s", customers[customerCount].phone);

    printf("Enter Address:\n");
    scanf(" %[^\n]s", customers[customerCount].address);

    printf("Customer added successfully!!\n");
}

void updateCustomer(Customer customers[MAX_RECORD], int customerCount)
{
    int id;
    printf("Enter Customer ID to update:\n");
    scanf("%d", &id);

    for (int i = 0; i < customerCount; i++)
    {
        if (customers[i].customerId == id)
        {
            printf("Enter new Customer Name:\n");
            scanf(" %[^\n]s", customers[i].customerName);

            printf("Enter new Phone:\n");
            scanf(" %[^\n]s", customers[i].phone);

            printf("Enter new Address:\n");
            scanf(" %[^\n]s", customers[i].address);

            printf("Customer updated successfully!!\n");
            return;
        }
    }
    printf("Customer ID not found!!\n");
}

int deleteCustomer(Customer customers[MAX_RECORD], int customerCount)
{
    int id, found = -1;
    printf("Enter Customer ID to delete:\n");
    scanf("%d", &id);

    for (int i = 0; i < customerCount; i++)
    {
        if (customers[i].customerId == id)
        {
            found = i;
            break;
        }
    }

    if (found == -1)
    {
        return 0;
    }

    else
    {
        for (int j = found; j < customerCount - 1; j++)
        {
            customers[j] = customers[j + 1];
        }

        printf("Customer deleted successfully!!\n");
        return 1;
    }
}

void displayCustomers(Customer customers[MAX_RECORD], int customerCount)
{
    for (int i = 0; i < customerCount; i++)
    {
        printf("\nCustomer %d:\n", i + 1);
        printf("ID: %d, Name: %s, Phone: %s, Address: %s\n", customers[i].customerId, customers[i].customerName, customers[i].phone, customers[i].address);
    }
    if (customerCount == 0)
    {
        printf("No customers available!!!\n");
    }
}

int addTransaction(PetrolStation stations[MAX_RECORD], FuelType fuels[MAX_RECORD], Customer customers[MAX_RECORD], Transaction transactions[MAX_RECORD], int stationCount, int fuelCount, int customerCount, int transactionCount)
{
    int customerID, stationID, fuelID;
    printf("Enter Transaction ID:\n");
    scanf("%d", &transactions[transactionCount].transactionId);

    printf("Enter Customer ID:\n");
    scanf("%d", &customerID);

    int customerExists = 0;
    for (int i = 0; i < customerCount; i++)
    {
        if (customers[i].customerId == customerID)
        {
            customerExists = 1;
            break;
        }
    }

    if (customerExists == 0)
    {
        printf("Customer ID not found!\n");
        return 0;
    }

    printf("Enter Station ID:\n");
    scanf("%d", &stationID);

    int stationExists = 0;
    for (int i = 0; i < stationCount; i++)
    {
        if (stations[i].stationId == stationID)
        {
            stationExists = 1;
            break;
        }
    }

    if (stationExists == 0)
    {
        printf("Station ID not found!\n");
        return 0;
    }

    printf("Enter Fuel ID:\n");
    scanf("%d", &fuelID);

    int fuelExists = 0;
    for (int i = 0; i < fuelCount; i++)
    {
        if (fuels[i].fuelId == fuelID)
        {
            fuelExists = 1;
            break;
        }
    }

    if (fuelExists == 0)
    {
        printf("Fuel ID not found!\n");
        return 0;
    }

    transactions[transactionCount].customerId = customerID;
    transactions[transactionCount].stationId = stationID;
    transactions[transactionCount].fuelId = fuelID;

    printf("Enter Quantity (in litres):\n");
    scanf("%f", &transactions[transactionCount].quantity);

    for (int i = 0; i < fuelCount; i++)
    {
        if (fuels[i].fuelId == transactions[transactionCount].fuelId)
        {
            transactions[transactionCount].totalPrice = transactions[transactionCount].quantity * fuels[i].pricePerLitre;
            break;
        }
    }

    printf("Transaction added successfully!!\n");
    return 1;
}

void updateTransaction(PetrolStation stations[MAX_RECORD], FuelType fuels[MAX_RECORD], Customer customers[MAX_RECORD], Transaction transactions[MAX_RECORD], int stationCount, int fuelCount, int customerCount, int transactionCount)
{
    int id, customerID, stationID, fuelID;
    printf("Enter Transaction ID to update:\n");
    scanf("%d", &id);

    for (int i = 0; i < transactionCount; i++)
    {
        if (transactions[i].transactionId == id)
        {
            printf("Enter new Customer ID:\n");
            scanf("%d", &customerID);

            int customerExists = 0;
            for (int i = 0; i < customerCount; i++)
            {
                if (customers[i].customerId == customerID)
                {
                    customerExists = 1;
                    break;
                }
            }

            if (customerExists == 0)
            {
                printf("Customer ID not found!\n");
                return;
            }

            printf("Enter new Station ID:\n");
            scanf("%d", &stationID);

            int stationExists = 0;
            for (int i = 0; i < stationCount; i++)
            {
                if (stations[i].stationId == stationID)
                {
                    stationExists = 1;
                    break;
                }
            }

            if (stationExists == 0)
            {
                printf("Station ID not found!\n");
                return;
            }

            printf("Enter new Fuel ID:\n");
            scanf("%d", &fuelID);

            int fuelExists = 0;
            for (int i = 0; i < fuelCount; i++)
            {
                if (fuels[i].fuelId == fuelID)
                {
                    fuelExists = 1;
                    break;
                }
            }

            if (fuelExists == 0)
            {
                printf("Fuel ID not found!\n");
                return;
            }

            transactions[i].customerId = customerID;
            transactions[i].stationId = stationID;
            transactions[i].fuelId = fuelID;

            printf("Enter new Quantity (in litres):\n");
            scanf("%f", &transactions[i].quantity);

            for (int j = 0; j < fuelCount; j++)
            {
                if (fuels[j].fuelId == transactions[i].fuelId)
                {
                    transactions[i].totalPrice = transactions[i].quantity * fuels[j].pricePerLitre;
                    break;
                }
            }

            printf("Transaction updated successfully!!\n");
            return;
        }
    }
    printf("Transaction ID not found!!\n");
}

int deleteTransaction(Transaction transactions[MAX_RECORD], int transactionCount)
{
    int id, found = -1;
    printf("Enter Transaction ID to delete:\n");
    scanf("%d", &id);

    for (int i = 0; i < transactionCount; i++)
    {
        if (transactions[i].transactionId == id)
        {
            found = i;
            break;
        }
    }

    if (found == -1)
    {
        return 0;
    }

    else
    {
        for (int j = found; j < transactionCount - 1; j++)
        {
            transactions[j] = transactions[j + 1];
        }

        return 1;
    }
}

void displayTransactions(Transaction transactions[MAX_RECORD], int transactionCount)
{
    for (int i = 0; i < transactionCount; i++)
    {
        printf("\nTransaction %d:\n", i + 1);
        printf("ID: %d, Customer ID: %d, Station ID: %d, Fuel ID: %d, Quantity: %.2f, Total Price: %.2f\n", transactions[i].transactionId, transactions[i].customerId, transactions[i].stationId, transactions[i].fuelId, transactions[i].quantity, transactions[i].totalPrice);
    }
    if (transactionCount == 0)
    {
        printf("No transactions available!!!\n");
    }
}

void search(PetrolStation stations[MAX_RECORD], FuelType fuels[MAX_RECORD], Customer customers[MAX_RECORD], Transaction transactions[MAX_RECORD], int stationCount, int fuelCount, int customerCount, int transactionCount)
{
    int choice;
    do
    {
        printf("\n******SEARCH******\n\n");
        printf("1. SEARCH PETROL STATIONS\n");
        printf("2. SEARCH FUEL TYPES\n");
        printf("3. SEARCH CUSTOMERS\n");
        printf("4. SEARCH TRANSACTIONS\n");
        printf("0. EXIT\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            searchStations(stations, stationCount);
            break;

        case 2:
            searchFuels(fuels, fuelCount);
            break;

        case 3:
            searchCustomers(customers, customerCount);
            break;

        case 4:
            searchTransactions(transactions, transactionCount);
            break;

        case 0:
            break;

        default:
            printf("Invalid input!!!\n");
            break;
        }
    } while (choice != 0);
}

void searchStations(PetrolStation stations[MAX_RECORD], int stationCount)
{
    int choice;
    do
    {
        printf("\nSEARCH PETROL STATIONS:\n");
        printf("1. SEARCH BY NAME\n");
        printf("2. SEARCH BY ID\n");
        printf("3. EXIT\n");

        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            searchStationByName(stations, stationCount);
            break;

        case 2:
            searchStationById(stations, stationCount);
            break;

        case 3:
            break;

        default:
            printf("Invalid input!!!\n");
            break;
        }
    } while (choice != 3);
}

void searchStationByName(PetrolStation stations[MAX_RECORD], int stationCount)
{
    char name[50];
    printf("Enter Station Name to search:\n");
    scanf(" %[^\n]s", name);

    for (int i = 0; i < stationCount; i++)
    {
        if (strcmp(stations[i].stationName, name) == 0)
        {
            printf("ID: %d, Name: %s, Location: %s\n", stations[i].stationId, stations[i].stationName, stations[i].location);
            return;
        }
    }
    printf("Station not found!!\n");
}

void searchStationById(PetrolStation stations[MAX_RECORD], int stationCount)
{
    int id;
    printf("Enter Station ID to search:\n");
    scanf("%d", &id);

    for (int i = 0; i < stationCount; i++)
    {
        if (stations[i].stationId == id)
        {
            printf("ID: %d, Name: %s, Location: %s\n", stations[i].stationId, stations[i].stationName, stations[i].location);
            return;
        }
    }
    printf("Station not found!!\n");
}

void searchFuels(FuelType fuels[MAX_RECORD], int fuelCount)
{
    int choice;
    do
    {
        printf("\nSEARCH FUEL TYPES:\n");
        printf("1. SEARCH BY NAME\n");
        printf("2. SEARCH BY ID\n");
        printf("3. EXIT\n");

        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            searchFuelByName(fuels, fuelCount);
            break;
        case 2:
            searchFuelById(fuels, fuelCount);
            break;

        case 3:
            break;

        default:
            printf("Invalid input!!!\n");
            break;
        }
    } while (choice != 3);
}

void searchFuelByName(FuelType fuels[MAX_RECORD], int fuelCount)
{
    char name[50];
    printf("Enter Fuel Name to search:\n");
    scanf(" %[^\n]s", name);

    for (int i = 0; i < fuelCount; i++)
    {
        if (strcmp(fuels[i].fuelName, name) == 0)
        {
            printf("ID: %d, Name: %s, Price: %.2f\n", fuels[i].fuelId, fuels[i].fuelName, fuels[i].pricePerLitre);
            return;
        }
    }
    printf("Fuel not found!!\n");
}

void searchFuelById(FuelType fuels[MAX_RECORD], int fuelCount)
{
    int id;
    printf("Enter Fuel ID to search:\n");
    scanf("%d", &id);

    for (int i = 0; i < fuelCount; i++)
    {
        if (fuels[i].fuelId == id)
        {
            printf("ID: %d, Name: %s, Price Per Litre: %.2f\n", fuels[i].fuelId, fuels[i].fuelName, fuels[i].pricePerLitre);
            return;
        }
    }
    printf("Fuel not found!!\n");
}

void searchCustomers(Customer customers[MAX_RECORD], int customerCount)
{
    int choice;
    do
    {
        printf("\nSEARCH CUSTOMERS:\n");
        printf("1. SEARCH BY NAME\n");
        printf("2. SEARCH BY ID\n");
        printf("3. EXIT\n");

        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            searchCustomerByName(customers, customerCount);
            break;

        case 2:
            searchCustomerById(customers, customerCount);
            break;

        case 3:
            break;

        default:
            printf("Invalid input!!!\n");
            break;
        }
    } while (choice != 3);
}

void searchCustomerByName(Customer customers[MAX_RECORD], int customerCount)
{
    char name[50];
    printf("Enter Customer Name to search:\n");
    scanf(" %[^\n]s", name);

    for (int i = 0; i < customerCount; i++)
    {
        if (strcmp(customers[i].customerName, name) == 0)
        {
            printf("ID: %d, Name: %s, Phone: %s, Address: %s\n", customers[i].customerId, customers[i].customerName, customers[i].phone, customers[i].address);
            return;
        }
    }
    printf("Customer not found!!\n");
}

void searchCustomerById(Customer customers[MAX_RECORD], int customerCount)
{
    int id;
    printf("Enter Customer ID to search:\n");
    scanf("%d", &id);

    for (int i = 0; i < customerCount; i++)
    {
        if (customers[i].customerId == id)
        {
            printf("ID: %d, Name: %s, Phone: %s, Address: %s\n", customers[i].customerId, customers[i].customerName, customers[i].phone, customers[i].address);
            return;
        }
    }
    printf("Customer not found!!\n");
}

void searchTransactions(Transaction transactions[MAX_RECORD], int transactionCount)
{
    int choice;
    do
    {
        printf("\nSEARCH TRANSACTIONS:\n");
        printf("1. SEARCH TRANSACTION BY CUSTOMER ID\n");
        printf("1. SEARCH BY ID\n");
        printf("3. EXIT\n");

        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            searchTransactionByCustomerId(transactions, transactionCount);
            break;
        case 2:
            searchTransactionById(transactions, transactionCount);
            break;
        case 3:
            break;

        default:
            printf("Invalid input!!!\n");
            break;
        }
    } while (choice != 3);
}

void searchTransactionByCustomerId(Transaction transactions[MAX_RECORD], int transactionCount)
{
    int id;
    printf("Enter Customer ID to search:\n");
    scanf("%d", &id);

    for (int i = 0; i < transactionCount; i++)
    {
        if (transactions[i].customerId == id)
        {
            printf("Transaction ID: %d, Customer ID: %d, Station ID: %d, Fuel ID: %d, Quantity: %.2f, Total Price: %.2f\n", transactions[i].transactionId, transactions[i].customerId, transactions[i].stationId, transactions[i].fuelId, transactions[i].quantity, transactions[i].totalPrice);
            return;
        }
    }
    printf("Transaction not found!!\n");
}

void searchTransactionById(Transaction transactions[MAX_RECORD], int transactionCount)
{
    int id;
    printf("Enter Transaction ID to search:\n");
    scanf("%d", &id);

    for (int i = 0; i < transactionCount; i++)
    {
        if (transactions[i].transactionId == id)
        {
            printf("Transaction ID: %d, Customer ID: %d, Station ID: %d, Fuel ID: %d, Quantity: %.2f, Total Price: %.2f\n", transactions[i].transactionId, transactions[i].customerId, transactions[i].stationId, transactions[i].fuelId, transactions[i].quantity, transactions[i].totalPrice);
            return;
        }
    }
    printf("Transaction not found!!\n");
}

void displayReport(PetrolStation stations[MAX_RECORD], FuelType fuels[MAX_RECORD], Customer customers[MAX_RECORD], Transaction transactions[MAX_RECORD], int stationCount, int fuelCount, int customerCount, int transactionCount)
{
    int choice;
    do
    {
        printf("1. DISPLAY MEANINGFUL REPORT FOR STATION\n");
        printf("2. DISPLAY MEANINGFUL REPORT FOR FUEL\n");
        printf("3. DISPLAY MEANINGFUL REPORT FOR CUSTOMER\n");
        printf("4. DISPLAY MEANINGFUL REPORT FOR TRANSACTION\n");
        printf("0. EXIT\n");

        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            displayStationReport(stations, transactions, stationCount, transactionCount);
            break;
        case 2:
            displayFuelReport(fuels, transactions, fuelCount, transactionCount);
            break;
        case 3:
            displayCustomerReport(customers, customerCount);
            break;
        case 4:
            displayTransactionReport(transactions, transactionCount);
            break;
        case 0:
            break;
        default:
            printf("Invalid Input!!!\n");
            break;
        }
    } while (choice != 0);
}

void displayStationReport(PetrolStation stations[MAX_RECORD], Transaction transactions[MAX_RECORD], int stationCount, int transactionCount)
{
    printf("\n******STATION REPORT******\n\n");
    if (stationCount == 0)
    {
        printf("No stations available!!!\n");
        return;
    }

    for (int i = 0; i < stationCount; i++)
    {
        printf("Station ID: %d\n", stations[i].stationId);
        printf("Station Name: %s\n", stations[i].stationName);
        printf("Location: %s\n", stations[i].location);

        float totalSales = 0.0;
        int transactionCountForStation = 0;

        for (int j = 0; j < transactionCount; j++)
        {
            if (transactions[j].stationId == stations[i].stationId)
            {
                totalSales += transactions[j].totalPrice;
                transactionCountForStation++;
            }
        }

        printf("Total Sales: %.2f\n", totalSales);
        printf("Total Transactions: %d\n", transactionCountForStation);
        printf("------------------------------\n");
    }
}

void displayFuelReport(FuelType fuels[MAX_RECORD], Transaction transactions[MAX_RECORD], int fuelCount, int transactionCount)
{
    printf("\n******FUEL REPORT******\n\n");
    if (fuelCount == 0)
    {
        printf("No fuels available!!!\n");
        return;
    }

    for (int i = 0; i < fuelCount; i++)
    {
        printf("Fuel ID: %d\n", fuels[i].fuelId);
        printf("Fuel Type: %s\n", fuels[i].fuelName);
        printf("Price per Liter: %.2f\n", fuels[i].pricePerLitre);

        float totalSales = 0.0;
        int transactionCountForFuel = 0;
        float totalLitersSold = 0.0;

        for (int j = 0; j < transactionCount; j++)
        {
            if (transactions[j].fuelId == fuels[i].fuelId)
            {
                totalSales += transactions[j].totalPrice;
                transactionCountForFuel++;
                totalLitersSold += transactions[j].quantity;
            }
        }

        printf("Total Sales: %.2f\n", totalSales);
        printf("Total Transactions: %d\n", transactionCountForFuel);
        printf("Total Liters Sold: %.2f\n", totalLitersSold);
        printf("------------------------------\n");
    }
}

void displayCustomerReport(Customer customers[MAX_RECORD], int customerCount)
{
    if (customerCount == 0)
    {
        printf("\nNo customers available to display the report!\n");
        return;
    }

    printf("\n*********CUSTOMER LIST********\n");
    printf("-----------------------------------------------------------------------------------\n");
    printf("| %-5s | %-20s | %-15s | %-30s |\n", "ID", "NAME", "PHONE", "ADDRESS");
    printf("-----------------------------------------------------------------------------------\n");

    for (int i = 0; i < customerCount; i++)
    {
        printf("| %-5d | %-20s | %-15s | %-30s |\n", customers[i].customerId, customers[i].customerName, customers[i].phone, customers[i].address);
    }

    printf("-----------------------------------------------------------------------------------\n");
}

void displayTransactionReport(Transaction transactions[MAX_RECORD], int transactionCount)
{
    printf("\n******TRANSACTION REPORT******\n\n");
    if (transactionCount == 0)
    {
        printf("No transactions available!!!\n");
        return;
    }

    for (int i = 0; i < transactionCount; i++)
    {
        printf("Transaction ID: %d\n", transactions[i].transactionId);
        printf("Customer ID: %d\n", transactions[i].customerId);
        printf("Fuel ID: %d\n", transactions[i].fuelId);
        printf("Quantity: %.2f liters\n", transactions[i].quantity);
        printf("Total Price: %.2f\n", transactions[i].totalPrice);
        printf("------------------------------\n");
    }
}
