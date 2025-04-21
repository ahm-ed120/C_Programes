#include <stdio.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_ORDERS 100

typedef struct product
{
    int pid;
    char pname[50];
    float price;
    int quantity;
} product;

typedef struct customer
{
    int cid;
    char cname[50];
    char address[100];
    char phone[15];
} customer;

typedef struct order
{
    int oid;
    int cid;
    int pid;
    int quantity;
    float totalCost;
} order;

void addProduct(product p[MAX_PRODUCTS], int productCount);
void updateProduct(product p[MAX_PRODUCTS], int productCount);
int deleteProduct(product p[MAX_PRODUCTS], int productCount);
void displayProducts(product p[MAX_PRODUCTS], int productCount);

void addCustomer(customer c[MAX_ORDERS], int customerCount);
void updateCustomer(customer c[MAX_ORDERS], int customerCount);
int deleteCustomer(customer c[MAX_ORDERS], int customerCount);
void displayCustomers(customer c[MAX_ORDERS], int customerCount);

int placeOrder(customer c[MAX_ORDERS], product p[MAX_PRODUCTS], order o[MAX_ORDERS], int customerCount, int productCount, int orderCount);
void updateOrder(customer c[MAX_ORDERS], product p[MAX_PRODUCTS], order o[MAX_ORDERS], int customerCount, int productCount, int orderCount);
int cancelOrder(order o[MAX_ORDERS], int orderCount);
void displayOrders(order o[MAX_ORDERS], int orderCount);

void searchProduct(product p[MAX_PRODUCTS], int productCount);
void searchProductByName(product p[MAX_PRODUCTS], int productCount);
void searchProductById(product p[MAX_PRODUCTS], int productCount);

void searchCustomer(customer c[MAX_ORDERS], int customerCount);
void searchCustomerByName(customer c[MAX_ORDERS], int customerCount);
void searchCustomerById(customer c[MAX_ORDERS], int customerCount);

void searchOrder(order o[MAX_ORDERS], int orderCount);
void searchOrderByOrderId(order o[MAX_ORDERS], int orderCount);
void searchOrderByCustomerId(order o[MAX_ORDERS], int orderCount);

void displaySalesReport(product p[MAX_PRODUCTS], order o[MAX_ORDERS], int productCount, int orderCount);
void displayProductReport(product p[MAX_PRODUCTS], int productCount);
void displayCustomerReport(customer c[MAX_ORDERS], int customerCount);
void displayOrderReport(order o[MAX_ORDERS], int orderCount);

int main()
{
    product p[MAX_PRODUCTS];
    customer c[MAX_ORDERS];
    order o[MAX_ORDERS];

    int productCount = 0;
    int customerCount = 0;
    int orderCount = 0;

    int choice, choice1, choice2, choice3, choice4, choice5;
    int w, x, y,f;

    FILE *fproduct1;

    fproduct1 = fopen("product.txt", "r");

    fscanf(fproduct1, "%d\n", &productCount);

    for (int i = 0; i < productCount; i++)
    {
        fscanf(fproduct1, "%d;%50[^;];%f;%d\n", &p[i].pid, p[i].pname, &p[i].price, &p[i].quantity);
    }

    fclose(fproduct1);

    FILE *fcustomer1;

    fcustomer1 = fopen("customer.txt", "r");

    fscanf(fcustomer1, "%d\n", &customerCount);

    for (int i = 0; i < customerCount; i++)
    {
        fscanf(fcustomer1, "%d;%50[^;];%100[^;];%15[^\n]\n", &c[i].cid, c[i].cname, c[i].address, c[i].phone);
    }

    fclose(fcustomer1);

    FILE *forder1;

    forder1 = fopen("order.txt", "r");

    fscanf(forder1, "%d\n", &orderCount);

    for (int i = 0; i < orderCount; i++)
    {
        fscanf(forder1, "%d;%d;%d;%d;%f\n", &o[i].oid, &o[i].cid, &o[i].pid, &o[i].quantity, &o[i].totalCost);
    }

    fclose(forder1);

    printf("eCommerce Store Management System\n\n");

    do
    {
        printf("\n*MAIN MENU*\n\n");
        printf("1. MANAGE PRODUCTS\n");
        printf("2. MANAGE CUSTOMERS\n");
        printf("3. MANAGE ORDERS\n");
        printf("4. SEARCH\n");
        printf("5. REPORT\n");
        printf("0. EXIT\n");

        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            do
            {
                printf("\n*MANAGE PRODUCTS*\n\n");
                printf("1. ADD PRODUCT\n");
                printf("2. UPDATE PRODUCT\n");
                printf("3. DISPLAY PRODUCTS\n");
                printf("4. DELETE PRODUCT\n");
                printf("0. EXIT\n");

                scanf("%d", &choice1);

                switch (choice1)
                {
                case 1:
                    addProduct(p, productCount);
                    productCount++;
                    break;
                case 2:
                    updateProduct(p, productCount);
                    break;
                case 3:
                    displayProducts(p, productCount);
                    break;
                case 4:
                    w = deleteProduct(p, productCount);
                    if (w == 1)
                    {
                        productCount--;
                    }
                    else
                    {
                        printf("Product not found!!!\n");
                    }
                    break;
                case 0:
                    break;
                default:
                    printf("Invalid input!!!\n");
                    break;
                }

                FILE *fproduct;

                fproduct = fopen("product.txt", "w");

                fprintf(fproduct, "%d\n", productCount);

                for (int i = 0; i < productCount; i++)
                {
                    fprintf(fproduct, "%d;%s;%.2f;%d\n", p[i].pid, p[i].pname, p[i].price, p[i].quantity);
                }

                fclose(fproduct);

            } while (choice1 != 0);
            break;

        case 2:
            do
            {
                printf("\n*MANAGE CUSTOMERS*\n\n");
                printf("1. ADD CUSTOMER\n");
                printf("2. UPDATE CUSTOMER\n");
                printf("3. DISPLAY CUSTOMERS\n");
                printf("4. DELETE CUSTOMER\n");
                printf("0. EXIT\n");

                scanf("%d", &choice2);

                switch (choice2)
                {
                case 1:
                    addCustomer(c, customerCount);
                    customerCount++;
                    break;
                case 2:
                    updateCustomer(c, customerCount);
                    break;
                case 3:
                    displayCustomers(c, customerCount);
                    break;
                case 4:
                    x = deleteCustomer(c, customerCount);
                    if (x == 1)
                    {
                        customerCount--;
                    }
                    else
                    {
                        printf("Customer not found!!!\n");
                    }
                    break;
                case 0:
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
                    fprintf(fcustomer, "%d;%s;%s;%s\n", c[i].cid, c[i].cname, c[i].address, c[i].phone);
                }

                fclose(fcustomer);

            } while (choice2 != 0);
            break;

        case 3:
            do
            {
                printf("\n*MANAGE ORDERS*\n");
                printf("1. PLACE ORDER\n");
                printf("2. UPDATE ORDER\n");
                printf("3. CANCEL ORDER\n");
                printf("4. DISPLAY ORDER\n");
                printf("0. EXIT\n");

                scanf("%d", &choice3);

                switch (choice3)
                {
                case 1:
                    f = placeOrder(c, p, o, customerCount, productCount, orderCount);
                    if (f == 1)
                    {
                        orderCount++;
                    }
                    break;
                case 2:
                    updateOrder(c, p, o, customerCount, productCount, orderCount);
                    break;
                case 3:
                    y = cancelOrder(o, orderCount);
                    if (y == 1)
                    {
                        orderCount--;
                    }
                    else
                    {
                        printf("order not found!!!\n");
                    }
                case 4:
                    displayOrders(o, orderCount);
                    break;
                case 0:
                    break;
                }

                FILE *forder;

                forder = fopen("order.txt", "w");

                fprintf(forder, "%d\n", orderCount);

                for (int i = 0; i < orderCount; i++)
                {
                    fprintf(forder, "%d;%d;%d;%d;%.2f\n", o[i].oid, o[i].cid, o[i].pid, o[i].quantity, o[i].totalCost);
                }

                fclose(forder);

            } while (choice3 != 0);
            break;

        case 4:
            do
            {
                printf("\n*SEARCH*\n\n");
                printf("1. SEARCH PRODUCT\n");
                printf("2. SEARCH CUSTOMER\n");
                printf("3. SEARCH ORDER\n");
                printf("0. EXIT\n");

                scanf("%d", &choice4);

                switch (choice4)
                {
                case 1:
                    searchProduct(p, productCount);
                    break;
                case 2:
                    searchCustomer(c, customerCount);
                    break;
                case 3:
                    searchOrder(o, orderCount);
                    break;
                case 0:
                    break;
                default:
                    printf("Invalid input!!!\n");
                    break;
                }
            } while (choice4 != 0);
            break;

        case 5:
            do
            {
                printf("\n*REPORT*\n\n");
                printf("1. PRODUCT REPORT\n");
                printf("2. CUSTOMER REPORT\n");
                printf("3. ORDER REPORT\n");
                printf("4. SALES REPORT\n");
                printf("0. EXIT\n");

                scanf("%d", &choice5);

                switch (choice5)
                {
                case 1:
                    displayProductReport(p, productCount);
                    break;
                case 2:
                    displayCustomerReport(c, customerCount);
                    break;
                case 3:
                    displayOrderReport(o, orderCount);
                    break;
                case 4:
                    displaySalesReport(p, o, productCount, orderCount);
                    break;
                case 0:
                    break;
                default:
                    printf("Invalid input!!!\n");
                    break;
                }
            } while (choice5 != 0);
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

void addProduct(product p[MAX_PRODUCTS], int productCount)
{
    printf("\nEnter Product ID: ");
    scanf("%d", &p[productCount].pid);

    printf("Enter the name of the product: ");
    scanf(" %[^\n]s", p[productCount].pname);

    printf("Enter the price of the product: ");
    scanf("%f", &p[productCount].price);

    printf("Enter the quantity of the product: ");
    scanf("%d", &p[productCount].quantity);

    printf("Product added successfully!!\n");
}

void updateProduct(product p[MAX_PRODUCTS], int productCount)
{
    int id;
    printf("\nEnter Product ID to update: ");
    scanf("%d", &id);

    for (int i = 0; i < productCount; i++)
    {
        if (p[i].pid == id)
        {
            printf("Enter new name: ");
            scanf(" %[^\n]s", p[i].pname);

            printf("Enter new price: ");
            scanf("%f", &p[i].price);

            printf("Enter new quantity: ");
            scanf("%d", &p[i].quantity);

            printf("Product updated successfully!!!\n");
            return;
        }
    }
    printf("Product ID not found!!!\n");
}

int deleteProduct(product p[MAX_PRODUCTS], int productCount)
{
    int id, found = -1;
    printf("\nEnter the ID number of the product you want to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < productCount; i++)
    {
        if (p[i].pid == id)
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
        for (int j = found; j < productCount - 1; j++)
        {
            p[j] = p[j + 1];
        }
        printf("Product deleted successfully!!!\n");
        return 1;
    }
}

void displayProducts(product p[MAX_PRODUCTS], int productCount)
{
    for (int i = 0; i < productCount; i++)
    {
        printf("\nProduct %d: \n", i + 1);
        printf("ID: %d, NAME: %s, PRICE: %.2f, QUANTITY: %d\n", p[i].pid, p[i].pname, p[i].price, p[i].quantity);
    }
    if (productCount == 0)
    {
        printf("No product available!!!\n");
    }
}

void addCustomer(customer c[MAX_ORDERS], int customerCount)
{
    printf("\nEnter Customer ID: ");
    scanf("%d", &c[customerCount].cid);

    printf("Enter the name of the customer: ");
    scanf(" %[^\n]s", c[customerCount].cname);

    printf("Enter the address of the customer: ");
    scanf(" %[^\n]s", c[customerCount].address);

    printf("Enter the phone number of the customer: ");
    scanf(" %[^\n]s", c[customerCount].phone);

    printf("Customer added successfully!!\n");
}

void updateCustomer(customer c[MAX_ORDERS], int customerCount)
{
    int id;
    printf("\nEnter Customer ID to update: ");
    scanf("%d", &id);

    for (int i = 0; i < customerCount; i++)
    {
        if (c[i].cid == id)
        {
            printf("Enter new name: ");
            scanf(" %[^\n]s", c[i].cname);

            printf("Enter new address: ");
            scanf(" %[^\n]s", c[i].address);

            printf("Enter new phone number: ");
            scanf(" %[^\n]s", c[i].phone);

            printf("Customer updated successfully!!!\n");
            return;
        }
    }
    printf("Customer ID not found!!!\n");
}

int deleteCustomer(customer c[MAX_ORDERS], int customerCount)
{
    int id, found = -1;
    printf("\nEnter the ID number of the customer you want to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < customerCount; i++)
    {
        if (c[i].cid == id)
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
            c[j] = c[j + 1];
        }
        printf("Customer deleted successfully!!!\n");
        return 1;
    }
}

void displayCustomers(customer c[MAX_ORDERS], int customerCount)
{
    for (int i = 0; i < customerCount; i++)
    {
        printf("\nCustomer %d: \n", i + 1);
        printf("ID: %d, NAME: %s, ADDRESS: %s, PHONE: %s\n", c[i].cid, c[i].cname, c[i].address, c[i].phone);
    }
    printf("\n");
}

int placeOrder(customer c[MAX_ORDERS], product p[MAX_PRODUCTS], order o[MAX_ORDERS], int customerCount, int productCount, int orderCount)
{
    int cid, pid, qty;
    float totalCost;

    printf("\nEnter Customer ID: ");
    scanf("%d", &cid);

    int customerIndex = -1;
    for (int i = 0; i < customerCount; i++)
    {
        if (c[i].cid == cid)
        {
            customerIndex = i;
            break;
        }
    }

    if (customerIndex == -1)
    {
        printf("Customer not found. Please add the customer first.\n");
        return 0;
    }

    printf("Products available:\n");
    displayProducts(p, productCount);

    printf("Enter Product ID: ");
    scanf("%d", &pid);

    int productIndex = -1;
    for (int i = 0; i < productCount; i++)
    {
        if (p[i].pid == pid)
        {
            productIndex = i;
            break;
        }
    }

    if (productIndex == -1)
    {
        printf("Product not found. Please add the product first.\n");
        return 0;
    }

    printf("Enter Quantity: ");
    scanf("%d", &qty);

    if (qty > p[productIndex].quantity)
    {
        printf("Insufficient quantity available.\n");
        return 0;
    }

    totalCost = p[productIndex].price * qty;

    // Reduce the quantity in memory
    p[productIndex].quantity -= qty;

    // Save the updated product quantity to the file
    FILE *fproduct = fopen("product.txt", "w");

    fprintf(fproduct, "%d\n", productCount);
    for (int i = 0; i < productCount; i++)
    {
        fprintf(fproduct, "%d;%s;%.2f;%d\n", p[i].pid, p[i].pname, p[i].price, p[i].quantity);
    }
    fclose(fproduct);

    // Save the order details in memory
    o[orderCount].cid = cid;
    o[orderCount].oid = orderCount + 1;
    o[orderCount].pid = pid;
    o[orderCount].quantity = qty;
    o[orderCount].totalCost = totalCost;

    printf("Order placed successfully!!\n");
    return 1;
}

void updateOrder(customer c[MAX_ORDERS], product p[MAX_PRODUCTS], order o[MAX_ORDERS], int customerCount, int productCount, int orderCount)
{
    int oid, qty;
    float totalCost;

    printf("\nEnter Order ID to update: ");
    scanf("%d", &oid);

    int orderIndex = -1;
    for (int i = 0; i < orderCount; i++)
    {
        if (o[i].oid == oid)
        {
            orderIndex = i;
            break;
        }
    }

    if (orderIndex == -1)
    {
        printf("Order not found!!!\n");
        return;
    }

    printf("Enter new Quantity: ");
    scanf("%d", &qty);

    int productIndex = -1;
    for (int i = 0; i < productCount; i++)
    {
        if (p[i].pid == o[orderIndex].pid)
        {
            productIndex = i;
            break;
        }
    }

    if (productIndex == -1)
    {
        printf("Product associated with the order not found!!!\n");
        return;
    }

    if (qty > (p[productIndex].quantity + o[orderIndex].quantity))
    {
        printf("Insufficient quantity available!!!\n");
        return;
    }

    totalCost = p[productIndex].price * qty;

    p[productIndex].quantity += o[orderIndex].quantity - qty;

    o[orderIndex].quantity = qty;
    o[orderIndex].totalCost = totalCost;

    printf("Order updated successfully!!!\n");
}

int cancelOrder(order o[MAX_ORDERS], int orderCount)
{
    int id, found = -1;
    printf("\nEnter the ID number of the order you want to cancel: ");
    scanf("%d", &id);

    for (int i = 0; i < orderCount; i++)
    {
        if (o[i].oid == id)
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
        for (int j = found; j < orderCount - 1; j++)
        {
            o[j] = o[j + 1];
        }
        printf("Order canceled successfully!!!\n");
        return 1;
    }
}

void displayOrders(order o[MAX_ORDERS], int orderCount)
{
    for (int i = 0; i < orderCount; i++)
    {
        printf("\nOrder %d: \n", i + 1);
        printf("ID: %d, CUSTOMER ID: %d, PRODUCT ID: %d, QUANTITY: %d, TOTAL COST: %.2f\n", o[i].oid, o[i].cid, o[i].pid, o[i].quantity, o[i].totalCost);
    }
    printf("\n");
}

void searchProduct(product p[MAX_PRODUCTS], int productCount)
{
    int choice;
    printf("\n*SEARCH PRODUCT*\n\n");
    printf("1. SEARCH BY NAME\n");
    printf("2. SEARCH BY ID\n");
    printf("0. EXIT\n");

    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        searchProductByName(p, productCount);
        break;
    case 2:
        searchProductById(p, productCount);
        break;
    case 0:
        break;
    default:
        printf("Invalid input!!!\n");
        break;
    }
}

void searchProductByName(product p[MAX_PRODUCTS], int productCount)
{
    char name[50];
    printf("\nEnter the name of the product: ");
    scanf(" %[^\n]s", name);

    int found = 0;
    for (int i = 0; i < productCount; i++)
    {
        if (strcmp(p[i].pname, name) == 0)
        {
            printf("ID: %d, NAME: %s, PRICE: %.2f, QUANTITY: %d\n", p[i].pid, p[i].pname, p[i].price, p[i].quantity);
            found = 1;
        }
    }

    if (!found)
    {
        printf("Product not found!!!\n");
    }
}

void searchProductById(product p[MAX_PRODUCTS], int productCount)
{
    int id;
    printf("\nEnter the ID number of the product: ");
    scanf("%d", &id);

    int found = 0;
    for (int i = 0; i < productCount; i++)
    {
        if (p[i].pid == id)
        {
            printf("ID: %d, NAME: %s, PRICE: %.2f, QUANTITY: %d\n", p[i].pid, p[i].pname, p[i].price, p[i].quantity);
            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("Product not found!!!\n");
    }
}

void searchCustomer(customer c[MAX_PRODUCTS], int customerCount)
{
    int choice;
    do
    {
        printf("\n*SEARCH CUSTOMER*\n");
        printf("1. SEARCH BY NAME\n");
        printf("2. SEARCH BY CUSTOMER ID\n");
        printf("3. EXIT\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            searchCustomerByName(c, customerCount);
            break;

        case 2:
            searchCustomerById(c, customerCount);
            break;

        case 3:
            break;

        default:
            printf("\nInvalid input\n");
            break;
        }
    } while (choice != 3);
}

void searchCustomerByName(customer c[MAX_PRODUCTS], int customerCount)
{
    char name[50];
    printf("\nEnter the name of the customer to search: ");
    scanf(" %[^\n]s", name);

    int found = 0;
    for (int i = 0; i < customerCount; i++)
    {
        if (strcmp(c[i].cname, name) == 0)
        {
            printf("Customer found:\n");
            printf("ID: %d, Name: %s, Phone: %s, Address: %s\n", c[i].cid, c[i].cname, c[i].phone, c[i].address);
            found = 1;
            break;
        }
    }

    if (found == 0)
    {
        printf("Customer with name '%s' not found.\n", name);
    }
}

void searchCustomerById(customer c[MAX_PRODUCTS], int customerCount)
{
    int id;
    printf("\nEnter the ID of the customer to search: ");
    scanf("%d", &id);

    int found = 0;
    for (int i = 0; i < customerCount; i++)
    {
        if (c[i].cid == id)
        {
            printf("Customer found:\n");
            printf("ID: %d, Name: %s, Phone: %s, Address: %s\n", c[i].cid, c[i].cname, c[i].phone, c[i].address);
            found = 1;
            break;
        }
    }

    if (found == 0)
    {
        printf("Customer with ID '%d' not found.\n", id);
    }
}

void searchOrder(order o[MAX_ORDERS], int orderCount)
{
    int choice;
    printf("\n****** SEARCH ORDER ******\n\n");
    printf("1. Search by Order ID\n");
    printf("2. Search by Customer ID\n");
    printf("0. Exit\n");

    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        searchOrderByOrderId(o, orderCount);
        break;
    case 2:
        searchOrderByCustomerId(o, orderCount);
        break;

    case 0:
        break;
    default:
        printf("Invalid input!!!\n");
        break;
    }
}

void searchOrderByOrderId(order o[MAX_ORDERS], int orderCount)
{
    int id;
    printf("\nEnter the Order ID: ");
    scanf("%d", &id);

    int found = 0;
    for (int i = 0; i < orderCount; i++)
    {
        if (o[i].oid == id)
        {
            printf("\nOrder found:\n");
            printf("ID: %d, Customer ID: %d, Product ID: %d, Quantity: %d, Total Cost: %.2f\n", o[i].oid, o[i].cid, o[i].pid, o[i].quantity, o[i].totalCost);
            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("Order with ID '%d' not found.\n", id);
    }
}

void searchOrderByCustomerId(order o[MAX_ORDERS], int orderCount)
{
    int id;
    printf("\nEnter the Customer ID: ");
    scanf("%d", &id);

    int found = 0;
    for (int i = 0; i < orderCount; i++)
    {
        if (o[i].cid == id)
        {
            printf("\nOrder found:\n");
            printf("ID: %d, Customer ID: %d, Product ID: %d, Quantity: %d, Total Cost: %.2f\n", o[i].oid, o[i].cid, o[i].pid, o[i].quantity, o[i].totalCost);
            found = 1;
        }
    }

    if (!found)
    {
        printf("No orders found for Customer ID '%d'.\n", id);
    }
}

void displayProductReport(product p[MAX_PRODUCTS], int productCount)
{
    printf("\n********** PRODUCT REPORT **********\n\n");

    if (productCount == 0)
    {
        printf("No products available to display.\n");
        return;
    }

    printf("-------------------------------------------------\n");
    printf("| %-5s | %-20s | %-10s | %-8s |\n", "ID", "Name", "Price", "Quantity");
    printf("-------------------------------------------------\n");

    int minPriceIndex = 0, maxPriceIndex = 0;
    int lowQuantityCount = 0;
    int threshold = 10; // Define a threshold for low quantity

    for (int i = 0; i < productCount; i++)
    {
        if (p[i].price < p[minPriceIndex].price)
        {
            minPriceIndex = i;
        }
        if (p[i].price > p[maxPriceIndex].price)
        {
            maxPriceIndex = i;
        }
        if (p[i].quantity < threshold)
        {
            lowQuantityCount++;
        }
        printf("| %-5d | %-20s | %-10.2f | %-8d |\n", p[i].pid, p[i].pname, p[i].price, p[i].quantity);
    }

    printf("-------------------------------------------------\n");

    printf("\nMaximum Priced Product:\n");
    printf("| %-5d | %-20s | %-10.2f | %-8d |\n", p[maxPriceIndex].pid, p[maxPriceIndex].pname, p[maxPriceIndex].price, p[maxPriceIndex].quantity);

    printf("\nMinimum Priced Product:\n");
    printf("| %-5d | %-20s | %-10.2f | %-8d |\n", p[minPriceIndex].pid, p[minPriceIndex].pname, p[minPriceIndex].price, p[minPriceIndex].quantity);

    printf("\nProducts with Low Quantity (Threshold: %d):\n", threshold);
    if (lowQuantityCount == 0)
    {
        printf("No products with low quantity.\n");
    }
    else
    {
        for (int i = 0; i < productCount; i++)
        {
            if (p[i].quantity < threshold)
            {
                printf("| %-5d | %-20s | %-10.2f | %-8d |\n", p[i].pid, p[i].pname, p[i].price, p[i].quantity);
            }
        }
    }
}

void displayCustomerReport(customer c[MAX_ORDERS], int customerCount)
{
    printf("\n********** CUSTOMER REPORT **********\n\n");

    if (customerCount == 0)
    {
        printf("No customers available to display.\n");
        return;
    }

    printf("---------------------------------------------------------------------\n");
    printf("| %-5s | %-20s | %-30s | %-15s |\n", "ID", "Name", "Address", "Phone");
    printf("---------------------------------------------------------------------\n");

    for (int i = 0; i < customerCount; i++)
    {
        printf("| %-5d | %-20s | %-30s | %-15s |\n", c[i].cid, c[i].cname, c[i].address, c[i].phone);
    }

    printf("--------------------------------------------------------------------\n");
}

void displayOrderReport(order o[MAX_ORDERS], int orderCount)
{
    printf("\n********** ORDER REPORT **********\n\n");

    if (orderCount == 0)
    {
        printf("No orders available to display.\n");
        return;
    }

    printf("---------------------------------------------------------------------------\n");
    printf("| %-5s | %-10s | %-10s | %-10s | %-8s | %-15s |\n", "ID", "Customer", "Product", "Quantity", "Total", "Total Cost");
    printf("---------------------------------------------------------------------------\n");

    for (int i = 0; i < orderCount; i++)
    {
        printf("| %-5d | %-10d | %-10d | %-10d | %-8.2f | %-15.2f |\n", o[i].oid, o[i].cid, o[i].pid, o[i].quantity, o[i].totalCost / o[i].quantity, o[i].totalCost);
    }

    printf("---------------------------------------------------------------------------\n");
}

void displaySalesReport(product p[MAX_PRODUCTS], order o[MAX_ORDERS], int productCount, int orderCount)
{
    printf("\n********** SALES REPORT **********\n\n");

    if (orderCount == 0)
    {
        printf("No sales available to display.\n");
        return;
    }

    float totalSales = 0.0;

    printf("------------------------------------------------------------------------\n");
    printf("| %-10s | %-20s | %-10s | %-10s |\n", "Product ID", "Product Name", "Quantity", "Total Sales");
    printf("------------------------------------------------------------------------\n");

    for (int i = 0; i < orderCount; i++)
    {
        int productId = o[i].pid;
        int quantity = o[i].quantity;
        float totalCost = o[i].totalCost;

        char productName[50];
        float productPrice = 0.0;
        for (int j = 0; j < productCount; j++)
        {
            if (p[j].pid == productId)
            {
                strcpy(productName, p[j].pname);
                productPrice = p[j].price;
                break;
            }
        }

        float sales = productPrice * quantity;
        totalSales += sales;

        printf("| %-10d | %-20s | %-10d | %-10.2f |\n", productId, productName, quantity, sales);
    }

    printf("------------------------------------------------------------------------\n");
    printf("\nTotal Sales: %.2f\n", totalSales);
}