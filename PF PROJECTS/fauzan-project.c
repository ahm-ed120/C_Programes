#include <stdio.h>
#include <string.h>
#define SIZE 100

struct client
{
    int clientId;
    char clientName[50];
    char clientNumber[50];
    char clientAddress[50];
};

struct employee
{
    int employeeId;
    char employeeName[50];
    char employeeNumber[50];
    float employeeSalary;
};

struct service
{
    int serviceId;
    char serviceName[50];
    float servicePrice;
};

struct appointment
{
    int appointmentId;
    char clientName[50];
    char employeeName[50];
    char serviceName[50];
    char appointmentDate[50];
    char appointmentTime[50];
};

void addClient(struct client c[SIZE], int clientCount);
int modifyClient(struct client c[SIZE], int clientCount);
void displayClient(struct client c[SIZE], int clientCount);
int deleteClient(struct client c[SIZE], int clientCount);

void addEmployee(struct employee e[SIZE], int employeeCount);
int modifyEmployee(struct employee e[SIZE], int employeeCount);
void displayEmployee(struct employee e[SIZE], int employeeCount);
int deleteEmployee(struct employee e[SIZE], int employeeCount);

void addService(struct service s[SIZE], int serviceCount);
int modifyService(struct service s[SIZE], int serviceCount);
void displayService(struct service s[SIZE], int serviceCount);
int deleteService(struct service s[SIZE], int serviceCount);

int addAppointment(struct appointment a[SIZE], struct client c[SIZE], struct employee e[SIZE], struct service s[SIZE], int appointmentCount, int clientCount, int serviceCount, int employeeCount);
int modifyAppointment(struct appointment a[SIZE], int appointmentCount);
void displayAppointment(struct appointment a[SIZE], int appointmentCount);
int deleteAppointment(struct appointment a[SIZE], int appointmentCount);

void searchAppointmentByDate(struct appointment a[SIZE], int appointmentCount);
void searchAppointmentById(struct appointment a[SIZE], int appointmentCount);

void employeeSearchById(struct employee e[SIZE], int employeeCount);
void employeeSearchByName(struct employee e[SIZE], int employeeCount);

void clientSearchById(struct client c[SIZE], int clientCount);
void clientSearchByName(struct client c[SIZE], int clientCount);

void serviceSearchById(struct service s[SIZE], int serviceCount);
void serviceSearchByName(struct service s[SIZE], int serviceCount);

void displayClientReport(struct client c[SIZE], int clientCount);
void displayEmployeeReport(struct employee e[SIZE], int employeeCount);
void displayServiceReport(struct service s[SIZE], int serviceCount);
void displayAppointmentReport(struct appointment a[SIZE], int appointmentCount);

int main()
{
    int loopMain = 1;
    int choice, choice11;
    int clientCount = 0;
    int employeeCount = 0;
    int serviceCount = 0;
    int appointmentCount = 0;
    struct client c[SIZE];
    struct employee e[SIZE];
    struct service s[SIZE];
    struct appointment a[SIZE];
    int f;

    FILE *fclient;
    fclient = fopen("client.txt", "r");
    fscanf(fclient, "%d\n", &clientCount);
    for (int i = 0; i < clientCount; i++)
    {
        fscanf(fclient, "%d,%20[^,],%f\n", &c[i].clientId, &c[i].clientName, &c[i].clientNumber, &c[i].clientAddress);
    }
    fclose(fclient);

    FILE *fservices;
    fservices = fopen("services.txt", "r");
    fscanf(fservices, "%d\n", &serviceCount);
    for (int i = 0; i < serviceCount; i++)
    {
        fscanf(fservices, "%d, %s, %f\n", &s[i].serviceId, &s[i].serviceName, &s[i].servicePrice);
    }
    fclose(fservices);

    FILE *femployee;
    femployee = fopen("employee.txt", "r");
    fscanf(femployee, "%d\n", &employeeCount);
    for (int i = 0; i < employeeCount; i++)
    {
        fscanf(femployee, "%d, %s, %s, %f\n", &e[i].employeeId, &e[i].employeeName, &e[i].employeeNumber, &e[i].employeeSalary);
    }
    fclose(femployee);

    FILE *fappointment;
    fappointment = fopen("appointments.txt", "r");
    fscanf(fappointment, "%d\n", &appointmentCount);
    for (int i = 0; i < appointmentCount; i++)
    {
        fscanf(fappointment, "%d, %s, %s, %s, %s, %s", &a[i].appointmentId, &a[i].employeeName, &a[i].clientName, &a[i].serviceName, &a[i].appointmentDate, &a[i].appointmentTime);
    }
    fclose(fappointment);

    while (loopMain)
    {
        printf("\t\t--------------------------------------\n\n");
        printf("\t\t--- Beauty Salon Management System ---\n\n");
        printf("\t\t--------------------------------------\n\n");
        printf("\n");
        printf("Select Choice:\n"
               "1. Client Management\n"
               "2. Services Management\n"
               "3. Staff Management\n"
               "4. Appointments Management\n"
               "5. Search\n"
               "6. Report\n"
               "7. Exit\n");

        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
        {
            int loopClient = 1;
            while (loopClient)
            {
                printf("Client Management\n");
                printf("1. Add Clients\n"
                       "2. Remove Clients\n"
                       "3. Modify Clients\n"
                       "4. Display Clients\n"
                       "5. Back to main menu\n");

                int choice2;
                scanf("%d", &choice2);

                switch (choice2)
                {
                case 1:
                    addClient(c, clientCount);
                    clientCount++;
                    break;
                case 2:
                    if (deleteClient(c, clientCount))
                    {
                        clientCount--;
                    }
                    else
                    {
                        printf("Client not found !!!\n");
                    }
                    break;
                case 3:
                    modifyClient(c, clientCount);
                    break;
                case 4:
                    displayClient(c, clientCount);
                    break;
                case 5:
                    loopClient = 0;
                    break;
                default:
                    printf("Invalid Input\n");
                    break;
                }
            }
            break;
        }
        case 2:
        {
            int loopService = 1;
            while (loopService)
            {
                printf("Services Management\n");
                printf("1. Add Service\n"
                       "2. Remove Service\n"
                       "3. Modify Service\n"
                       "4. Display All Services\n"
                       "5. Back to main menu\n");

                int choice3;
                scanf("%d", &choice3);

                switch (choice3)
                {
                case 1:
                    addService(s, serviceCount);
                    serviceCount++;
                    break;
                case 2:
                    if (deleteService(s, serviceCount))
                    {
                        serviceCount--;
                    }
                    else
                    {
                        printf("Service not found !!!\n");
                    }
                    break;
                case 3:
                    modifyService(s, serviceCount);
                    break;
                case 4:
                    displayService(s, serviceCount);
                    break;
                case 5:
                    loopService = 0;
                    break;
                default:
                    printf("Invalid Input\n");
                    break;
                }
            }
            break;
        }
        case 3:
        {
            int loopEmployee = 1;
            while (loopEmployee)
            {
                printf("Employee Management\n"
                       "1. Add Staff\n"
                       "2. Remove Staff\n"
                       "3. Modify Staff\n"
                       "4. Display All Staff\n"
                       "5. Back to main menu\n");

                int choice4;
                scanf("%d", &choice4);

                switch (choice4)
                {
                case 1:
                    addEmployee(e, employeeCount);
                    employeeCount++;
                    break;
                case 2:
                    if (deleteEmployee(e, employeeCount))
                    {
                        employeeCount--;
                    }
                    else
                    {
                        printf("Employee not found !!!\n");
                    }
                    break;
                case 3:
                    modifyEmployee(e, employeeCount);
                    break;
                case 4:
                    displayEmployee(e, employeeCount);
                    break;
                case 5:
                    loopEmployee = 0;
                    break;
                default:
                    printf("Invalid Input\n");
                    break;
                }
            }
            break;
        }
        case 4:
        {
            int loopAppointment = 1;
            while (loopAppointment)
            {
                printf("Appointments Management\n");
                printf("1. Add Appointment\n"
                       "2. Remove Appointment\n"
                       "3. Modify Appointment\n"
                       "4. Display All Appointments\n"
                       "5. Back to main menu\n");

                int choice5;
                scanf("%d", &choice5);

                switch (choice5)
                {
                case 1:
                    f = addAppointment(a, c, e, s, appointmentCount, clientCount, serviceCount, employeeCount);
                    if (f == 1)
                    {
                        appointmentCount++;
                    }
                    else
                    {
                        printf("Appointment not added!");
                    }

                    break;
                case 2:
                    if (deleteAppointment(a, appointmentCount))
                    {
                        appointmentCount--;
                    }
                    else
                    {
                        printf("Appointment not found !!!\n");
                    }
                    break;
                case 3:
                    modifyAppointment(a, appointmentCount);
                    break;
                case 4:
                    displayAppointment(a, appointmentCount);
                    break;
                case 5:
                    loopAppointment = 0;
                    break;
                default:
                    printf("Invalid Input\n");
                    break;
                }
            }
            break;
        }
        case 5:
        {
            int loopSearch = 1;
            while (loopSearch)
            {
                printf("Search!\n");
                printf("1. Search Client\n"
                       "2. Search Service\n"
                       "3. Search Employee\n"
                       "4. Search Appointment\n"
                       "5. Back to main menu\n");

                int choice6;
                scanf("%d", &choice6);

                switch (choice6)
                {
                case 1:
                {
                    int loopClientSearch = 1;
                    while (loopClientSearch)
                    {
                        printf("Client Search!\n");
                        printf("1. Search by ID\n"
                               "2. Search by Name\n"
                               "3. Back\n");

                        int choice7;
                        scanf("%d", &choice7);

                        switch (choice7)
                        {
                        case 1:
                            clientSearchById(c, clientCount);
                            break;
                        case 2:
                            clientSearchByName(c, clientCount);
                            break;
                        case 3:
                            loopClientSearch = 0;
                            break;
                        default:
                            printf("Invalid Input\n");
                            break;
                        }
                    }
                    break;
                }
                case 2:
                {
                    int loopServiceSearch = 1;
                    while (loopServiceSearch)
                    {
                        printf("Service Search!\n");
                        printf("1. Search by ID\n"
                               "2. Search by Name\n"
                               "3. Back\n");

                        int choice8;
                        scanf("%d", &choice8);

                        switch (choice8)
                        {
                        case 1:
                            serviceSearchById(s, serviceCount);
                            break;
                        case 2:
                            serviceSearchByName(s, serviceCount);
                            break;
                        case 3:
                            loopServiceSearch = 0;
                            break;
                        default:
                            printf("Invalid Input\n");
                            break;
                        }
                    }
                    break;
                }
                case 3:
                {
                    int loopEmployeeSearch = 1;
                    while (loopEmployeeSearch)
                    {
                        printf("Search Employee!\n");
                        printf("1. Search by ID\n"
                               "2. Search by Name\n"
                               "3. Back\n");

                        int choice9;
                        scanf("%d", &choice9);

                        switch (choice9)
                        {
                        case 1:
                            employeeSearchById(e, employeeCount);
                            break;
                        case 2:
                            employeeSearchByName(e, employeeCount);
                            break;
                        case 3:
                            loopEmployeeSearch = 0;
                            break;
                        default:
                            printf("Invalid Input\n");
                            break;
                        }
                    }
                    break;
                }
                case 4:
                {
                    int loopAppointmentSearch = 1;
                    while (loopAppointmentSearch)
                    {
                        printf("Search Appointment!\n");
                        printf("1. Search by Date\n"
                               "2. Search by ID\n"
                               "3. Back\n");

                        int choice10;
                        scanf("%d", &choice10);

                        switch (choice10)
                        {
                        case 1:
                            searchAppointmentByDate(a, appointmentCount);
                            break;
                        case 2:
                            searchAppointmentById(a, appointmentCount);
                            break;
                        case 3:
                            loopAppointmentSearch = 0;
                            break;
                        default:
                            printf("Invalid Input\n");
                            break;
                        }
                    }
                    break;
                }
                case 5:
                    loopSearch = 0;
                    break;
                default:
                    printf("Invalid Input\n");
                    break;
                }
            }
            break;
        }
        case 6:
            do
            {
                printf("\nREPORT\n\n");
                printf("1. DISPLAY REPORT FOR CLIENT\n");
                printf("2. DISPLAY REPORT FOR SERVICES\n");
                printf("3. DISPLAY REPORT FOR EMPLOYEE\n");
                printf("4. DISPLAY REPORT FOR APPOINTMENT\n");
                printf("5. EXIT\n");

                scanf("%d", &choice11);

                switch (choice11)
                {
                case 1:
                    displayClientReport(c, clientCount);
                    break;
                case 2:
                    displayServiceReport(s, serviceCount);
                    break;
                case 3:
                    displayEmployeeReport(e, employeeCount);
                    break;
                case 4:
                    displayAppointmentReport(a,appointmentCount);
                    break;
                case 5:
                    break;
                default:
                    printf("Invalid input!!!\n");
                    break;
                }

            } while (choice11 != 5);
            break;
        case 7:
            loopMain = 0;
            break;
        default:
            printf("Invalid Input\n");
            break;
        }
    }

    FILE *fclient1;
    fclient1 = fopen("client.txt", "w");
    fprintf(fclient1, "Total Clients: %d\n", clientCount);
    for (int i = 0; i < clientCount; i++)
    {
        fprintf(fclient1, "Client Details \nID: %d, Name: %s, Number: %s, Address: %s \n", c[i].clientId, c[i].clientName, c[i].clientNumber, c[i].clientAddress);
    }
    fclose(fclient1);

    FILE *fservices1;
    fservices1 = fopen("services.txt", "w");
    fprintf(fservices1, "Total Services: %d\n", serviceCount);
    for (int i = 0; i < serviceCount; i++)
    {
        fprintf(fservices1, "Service Details \nID: %d, Name: %s, Price: %.2f\n", s[i].serviceId, s[i].serviceName, s[i].servicePrice);
    }
    fclose(fservices1);

    FILE *femployee1;
    femployee1 = fopen("employee.txt", "w");
    fprintf(femployee1, "Total Employees: %d\n", employeeCount);
    for (int i = 0; i < employeeCount; i++)
    {
        fprintf(femployee1, "Employee Details \nID: %d, Name: %s, Number: %s, Salary: %.2f\n", e[i].employeeId, e[i].employeeName, e[i].employeeNumber, e[i].employeeSalary);
    }
    fclose(femployee1);

    FILE *fappointment1;
    fappointment1 = fopen("appointments.txt", "w");
    fprintf(fappointment1, "Total Appointments: %d\n", appointmentCount);
    for (int i = 0; i < appointmentCount; i++)
    {
        fprintf(fappointment1, "Appointment Details\nAppointment ID: %d, Employee Name: %s, Client Name: %s, Service ID: %s, Appointment Date: %s, Appointment Time: %s", a[i].appointmentId, a[i].employeeName, a[i].clientName, a[i].serviceName, a[i].appointmentDate, a[i].appointmentTime);
    }
    fclose(fappointment1);

    return 0;
}

void addClient(struct client c[SIZE], int clientCount)
{
    c[clientCount].clientId = clientCount + 1;
    printf("Enter Client Name: ");
    scanf(" %[^\n]s", c[clientCount].clientName);
    printf("Enter Client Number: ");
    scanf(" %[^\n]s", c[clientCount].clientNumber);
    printf("Enter Client Address: ");
    scanf(" %[^\n]s", c[clientCount].clientAddress);
}

int modifyClient(struct client c[SIZE], int clientCount)
{
    int id, i;
    printf("Enter Client ID to modify: ");
    scanf("%d", &id);
    for (i = 0; i < clientCount; i++)
    {
        if (c[i].clientId == id)
        {
            printf("Enter New Client Name: ");
            scanf(" %[^\n]s", c[i].clientName);
            printf("Enter New Client Number: ");
            scanf(" %[^\n]s", c[i].clientNumber);
            printf("Enter New Client Address: ");
            scanf(" %[^\n]s", c[i].clientAddress);
            return 1;
        }
    }
    return 0;
}

void displayClient(struct client c[SIZE], int clientCount)
{
    int i;
    for (i = 0; i < clientCount; i++)
    {
        printf("Client ID: %d\n", c[i].clientId);
        printf("Client Name: %s\n", c[i].clientName);
        printf("Client Number: %s\n", c[i].clientNumber);
        printf("Client Address: %s\n", c[i].clientAddress);
        printf("\n");
    }
}

int deleteClient(struct client c[SIZE], int clientCount)
{
    int id, i, j;
    printf("Enter Client ID to delete: ");
    scanf("%d", &id);
    for (i = 0; i < clientCount; i++)
    {
        if (c[i].clientId == id)
        {
            for (j = i; j < clientCount - 1; j++)
            {
                c[j] = c[j + 1];
            }
            return 1;
        }
    }
    return 0;
}

void addEmployee(struct employee e[SIZE], int employeeCount)
{
    e[employeeCount].employeeId = employeeCount + 1;
    printf("Enter Employee Name: ");
    scanf(" %[^\n]s", e[employeeCount].employeeName);
    printf("Enter Employee Number: ");
    scanf(" %[^\n]s", e[employeeCount].employeeNumber);
    printf("Enter Employee Salary: ");
    scanf("%f", &e[employeeCount].employeeSalary);
}

int modifyEmployee(struct employee e[SIZE], int employeeCount)
{
    int id, i;
    printf("Enter Employee ID to modify: ");
    scanf("%d", &id);
    for (i = 0; i < employeeCount; i++)
    {
        if (e[i].employeeId == id)
        {
            printf("Enter New Employee Name: ");
            scanf(" %[^\n]s", e[i].employeeName);
            printf("Enter New Employee Number: ");
            scanf(" %[^\n]s", e[i].employeeNumber);
            printf("Enter New Employee Salary: ");
            scanf("%f", &e[i].employeeSalary);
            return 1;
        }
    }
    return 0;
}

void displayEmployee(struct employee e[SIZE], int employeeCount)
{
    int i;
    for (i = 0; i < employeeCount; i++)
    {
        printf("Employee ID: %d\n", e[i].employeeId);
        printf("Employee Name: %s\n", e[i].employeeName);
        printf("Employee Number: %s\n", e[i].employeeNumber);
        printf("Employee Salary: %.2f\n", e[i].employeeSalary);
        printf("\n");
    }
}

int deleteEmployee(struct employee e[SIZE], int employeeCount)
{
    int id, i, j;
    printf("Enter Employee ID to delete: ");
    scanf("%d", &id);
    for (i = 0; i < employeeCount; i++)
    {
        if (e[i].employeeId == id)
        {
            for (j = i; j < employeeCount - 1; j++)
            {
                e[j] = e[j + 1];
            }
            return 1;
        }
    }
    return 0;
}

void addService(struct service s[SIZE], int serviceCount)
{
    s[serviceCount].serviceId = serviceCount + 1;
    printf("Enter Service Name: ");
    scanf(" %[^\n]s", s[serviceCount].serviceName);
    printf("Enter Service Price: ");
    scanf("%f", &s[serviceCount].servicePrice);
}

int modifyService(struct service s[SIZE], int serviceCount)
{
    int id, i;
    printf("Enter Service ID to modify: ");
    scanf("%d", &id);
    for (i = 0; i < serviceCount; i++)
    {
        if (s[i].serviceId == id)
        {
            printf("Enter New Service Name: ");
            scanf(" %[^\n]s", s[i].serviceName);
            printf("Enter New Service Price: ");
            scanf("%f", &s[i].servicePrice);
            return 1;
        }
    }
    return 0;
}

void displayService(struct service s[SIZE], int serviceCount)
{
    int i;
    for (i = 0; i < serviceCount; i++)
    {
        printf("Service ID: %d\n", s[i].serviceId);
        printf("Service Name: %s\n", s[i].serviceName);
        printf("Service Price: %.2f\n", s[i].servicePrice);
        printf("\n");
    }
}

int deleteService(struct service s[SIZE], int serviceCount)
{
    int id, i, j;
    printf("Enter Service ID to delete: ");
    scanf("%d", &id);
    for (i = 0; i < serviceCount; i++)
    {
        if (s[i].serviceId == id)
        {
            for (j = i; j < serviceCount - 1; j++)
            {
                s[j] = s[j + 1];
            }
            return 1;
        }
    }
    return 0;
}

int addAppointment(struct appointment a[SIZE], struct client c[SIZE], struct employee e[SIZE], struct service s[SIZE],
                   int appointmentCount, int clientCount, int serviceCount, int employeeCount)
{

    int clientId;
    int employeeId;
    int serviceId;
    int foundClient = -1;
    int foundEmployee = -1;
    int foundService = -1;

    a[appointmentCount].appointmentId = appointmentCount + 1;

    printf("Enter Client ID: ");
    scanf("%d", &clientId);

    for (int i = 0; i < clientCount; ++i)
    {
        if (c[i].clientId == clientId)
        {
            foundClient = i;
            break;
        }
    }

    if (foundClient == -1)
    {
        printf("Client does not exist!\n");
        return 0;
    }

    strcpy(a[appointmentCount].clientName, c[foundClient].clientName);

    printf("Enter Employee ID: ");
    scanf("%d", &employeeId);

    for (int i = 0; i < employeeCount; ++i)
    {
        if (e[i].employeeId == employeeId)
        {
            foundEmployee = i;
            break;
        }
    }

    if (foundEmployee == -1)
    {
        printf("Employee does not exist!\n");
        return 0;
    }

    strcpy(a[appointmentCount].employeeName, e[foundEmployee].employeeName);

    printf("Enter Service ID: ");
    scanf("%d", &serviceId);

    for (int i = 0; i < serviceCount; ++i)
    {
        if (s[i].serviceId == serviceId)
        {
            foundService = i;
            break;
        }
    }

    if (foundService == -1)
    {
        printf("Service does not exist!\n");
        return 0;
    }

    strcpy(a[appointmentCount].serviceName, s[foundService].serviceName);

    printf("Enter Appointment Date: ");
    scanf(" %[^\n]s", a[appointmentCount].appointmentDate);
    printf("Enter Appointment Time: ");
    scanf(" %[^\n]s", a[appointmentCount].appointmentTime);

    return 1;
}

int modifyAppointment(struct appointment a[SIZE], int appointmentCount)
{
    int id, i;
    printf("Enter Appointment ID to modify: ");
    scanf("%d", &id);
    for (i = 0; i < appointmentCount; i++)
    {
        if (a[i].appointmentId == id)
        {
            printf("Enter Client Name: ");
            scanf(" %[^\n]s", &a[appointmentCount].clientName);
            printf("Enter Employee Name: ");
            scanf(" %[^\n]s", &a[appointmentCount].employeeName);
            printf("Enter Service Name: ");
            scanf(" %[^\n]s", &a[appointmentCount].serviceName);
            printf("Enter Appointment Date: ");
            scanf(" %[^\n]s", a[appointmentCount].appointmentDate);
            printf("Enter Appointment Time: ");
            scanf(" %[^\n]s", a[appointmentCount].appointmentTime);
            return 1;
        }
    }
    return 0;
}

void displayAppointment(struct appointment a[SIZE], int appointmentCount)
{
    int i;
    for (i = 0; i < appointmentCount; i++)
    {
        printf("Appointment ID: %d\n", a[i].appointmentId);
        printf("Client Name: %s\n", a[i].clientName);
        printf("Employee Name: %s\n", a[i].employeeName);
        printf("Service Name: %s\n", a[i].serviceName);
        printf("Appointment Date: %s\n", a[i].appointmentDate);
        printf("Appointment Time: %s\n", a[i].appointmentTime);
        printf("\n");
    }
}

int deleteAppointment(struct appointment a[SIZE], int appointmentCount)
{
    int id, i, j;
    printf("Enter Appointment ID to delete: ");
    scanf("%d", &id);
    for (i = 0; i < appointmentCount; i++)
    {
        if (a[i].appointmentId == id)
        {
            for (j = i; j < appointmentCount - 1; j++)
            {
                a[j] = a[j + 1];
            }
            return 1;
        }
    }
    return 0;
}

void clientSearchById(struct client c[SIZE], int clientCount)
{
    int id, i;
    printf("Enter Client ID to search: ");
    scanf("%d", &id);
    for (i = 0; i < clientCount; i++)
    {
        if (c[i].clientId == id)
        {
            printf("Client ID: %d\n", c[i].clientId);
            printf("Client Name: %s\n", c[i].clientName);
            printf("Client Number: %s\n", c[i].clientNumber);
            printf("Client Address: %s\n", c[i].clientAddress);
            printf("\n");
            return;
        }
    }
    printf("Client not found\n");
}

void clientSearchByName(struct client c[SIZE], int clientCount)
{
    char name[100];
    int i;
    printf("Enter Client Name to search: ");
    scanf(" %[^\n]s", name);
    for (i = 0; i < clientCount; i++)
    {
        if (strcmp(c[i].clientName, name) == 0)
        {
            printf("Client ID: %d\n", c[i].clientId);
            printf("Client Name: %s\n", c[i].clientName);
            printf("Client Number: %s\n", c[i].clientNumber);
            printf("Client Address: %s\n", c[i].clientAddress);
            printf("\n");
            return;
        }
    }
    printf("Client not found\n");
}

void employeeSearchById(struct employee e[SIZE], int employeeCount)
{
    int id, i;
    printf("Enter Employee ID to search: ");
    scanf("%d", &id);
    for (i = 0; i < employeeCount; i++)
    {
        if (e[i].employeeId == id)
        {
            printf("Employee ID: %d\n", e[i].employeeId);
            printf("Employee Name: %s\n", e[i].employeeName);
            printf("Employee Number: %s\n", e[i].employeeNumber);
            printf("Employee Salary: %.2f\n", e[i].employeeSalary);
            printf("\n");
            return;
        }
    }
    printf("Employee not found\n");
}

void employeeSearchByName(struct employee e[SIZE], int employeeCount)
{
    char name[100];
    int i;
    printf("Enter Employee Name to search: ");
    scanf(" %[^\n]s", name);
    for (i = 0; i < employeeCount; i++)
    {
        if (strcmp(e[i].employeeName, name) == 0)
        {
            printf("Employee ID: %d\n", e[i].employeeId);
            printf("Employee Name: %s\n", e[i].employeeName);
            printf("Employee Number: %s\n", e[i].employeeNumber);
            printf("Employee Salary: %.2f\n", e[i].employeeSalary);
            printf("\n");
            return;
        }
    }
    printf("Employee not found\n");
}

void searchAppointmentByDate(struct appointment a[SIZE], int appointmentCount)
{
    char date[11];
    int i;
    printf("Enter Appointment Date to search (yyyy-mm-dd): ");
    scanf(" %[^\n]s", date);
    for (i = 0; i < appointmentCount; i++)
    {
        if (strcmp(a[i].appointmentDate, date) == 0)
        {
            printf("Appointment ID: %d\n", a[i].appointmentId);
            printf("Client Name: %s\n", a[i].clientName);
            printf("Employee Name: %s\n", a[i].employeeName);
            printf("Service ID: %s\n", a[i].serviceName);
            printf("Appointment Date: %s\n", a[i].appointmentDate);
            printf("Appointment Time: %s\n", a[i].appointmentTime);
            printf("\n");
            return;
        }
    }
    printf("Appointment not found\n");
}

void searchAppointmentById(struct appointment a[SIZE], int appointmentCount)
{
    int id, i;
    printf("Enter Appointment ID to search: ");
    scanf("%d", &id);
    for (i = 0; i < appointmentCount; i++)
    {
        if (a[i].appointmentId == id)
        {
            printf("Appointment ID: %d\n", a[i].appointmentId);
            printf("Client ID: %s\n", a[i].clientName);
            printf("Employee ID: %s\n", a[i].employeeName);
            printf("Service ID: %s\n", a[i].serviceName);
            printf("Appointment Date: %s\n", a[i].appointmentDate);
            printf("Appointment Time: %s\n", a[i].appointmentTime);
            printf("\n");
            return;
        }
    }
    printf("Appointment not found\n");
}

void serviceSearchById(struct service s[SIZE], int serviceCount)
{
    int id, i;
    printf("Enter Service ID to search: ");
    scanf("%d", &id);
    for (i = 0; i < serviceCount; i++)
    {
        if (s[i].serviceId == id)
        {
            printf("Service ID: %d\n", s[i].serviceId);
            printf("Service Name: %s\n", s[i].serviceName);
            printf("Service Price: %.2f\n", s[i].servicePrice);
            printf("\n");
            return;
        }
    }
    printf("Service not found\n");
}

void serviceSearchByName(struct service s[SIZE], int serviceCount)
{
    char name[100];
    int i;
    printf("Enter Service Name to search: ");
    scanf(" %[^\n]s", name);
    for (i = 0; i < serviceCount; i++)
    {
        if (strcmp(s[i].serviceName, name) == 0)
        {
            printf("Service ID: %d\n", s[i].serviceId);
            printf("Service Name: %s\n", s[i].serviceName);
            printf("Service Price: %.2f\n", s[i].servicePrice);
            printf("\n");
            return;
        }
    }
    printf("Service not found\n");
}

void displayClientReport(struct client c[SIZE], int clientCount)
{
    printf("Client Report\n");
    printf("===========================================================\n");
    printf("| %-10s | %-20s | %-15s | %-25s |\n", "Client ID", "Client Name", "Client Number", "Client Address");
    printf("===========================================================\n");

    for (int i = 0; i < clientCount; i++)
    {
        printf("| %-10d | %-20s | %-15s | %-25s |\n", c[i].clientId, c[i].clientName, c[i].clientNumber, c[i].clientAddress);
    }

    printf("===========================================================\n");
}

void displayEmployeeReport(struct employee e[SIZE], int employeeCount)
{
    printf("\n===============================\n");
    printf("         Employee Report\n");
    printf("===============================\n\n");

    for (int i = 0; i < employeeCount; i++)
    {
        printf("Employee ID: %d\n", e[i].employeeId);
        printf("Name: %s\n", e[i].employeeName);
        printf("Phone Number: %s\n", e[i].employeeNumber);
        printf("Salary: $%.2f\n", e[i].employeeSalary);
        printf("-------------------------------\n");
    }

    float totalSalary = 0.0;
    for (int i = 0; i < employeeCount; i++)
    {
        totalSalary += e[i].employeeSalary;
    }

    float averageSalary = totalSalary / employeeCount;

    printf("Total Employees: %d\n", employeeCount);
    printf("Total Salary: $%.2f\n", totalSalary);
    printf("Average Salary: $%.2f\n", averageSalary);
    printf("\n===============================\n");
}

void displayServiceReport(struct service s[SIZE], int serviceCount)
{
    printf("\n===============================\n");
    printf("         Service Report\n");
    printf("===============================\n\n");

    for (int i = 0; i < serviceCount; i++)
    {
        printf("Service ID: %d\n", s[i].serviceId);
        printf("Service Name: %s\n", s[i].serviceName);
        printf("Price: $%.2f\n", s[i].servicePrice);
        printf("-------------------------------\n");
    }

    float totalRevenue = 0.0;
    for (int i = 0; i < serviceCount; i++)
    {
        totalRevenue += s[i].servicePrice;
    }

    printf("Total Services: %d\n", serviceCount);
    printf("Total Revenue: $%.2f\n", totalRevenue);
    printf("\n===============================\n");
}

void displayAppointmentReport(struct appointment a[SIZE], int appointmentCount)
{
    printf("\n--- Beauty Salon Appointment Report ---\n\n");

    if (appointmentCount == 0)
    {
        printf("No appointments scheduled.\n");
    }
    else
    {
        printf("%-15s %-20s %-20s %-20s %-15s %-15s\n",
               "Appointment ID", "Client Name", "Employee Name",
               "Service Name", "Appointment Date", "Appointment Time");
        printf("------------------------------------------------------------------------------------------\n");

        for (int i = 0; i < appointmentCount; ++i)
        {
            printf("%-15d %-20s %-20s %-20s %-15s %-15s\n",
                   a[i].appointmentId, a[i].clientName, a[i].employeeName,
                   a[i].serviceName, a[i].appointmentDate, a[i].appointmentTime);
        }
    }
}