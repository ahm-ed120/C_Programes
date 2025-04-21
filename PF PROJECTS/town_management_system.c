#include <stdio.h>
#include <string.h>

#define MAX_RECORD 100

typedef struct
{
    int bid;
    char bname[50];
    char baddress[100];
} building;

typedef struct
{
    int cid;
    char cname[50];
    char caddress[100];
    char cphone[15];
} citizen;

typedef struct
{
    int sid;
    char sname[50];
    float sprice;
} service;

typedef struct
{
    int usageId;
    int citizenId;
    int serviceId;
    float totalCost;
} usage;

void addBuilding(building b[MAX_RECORD], int buildingCount);
void updateBuilding(building b[MAX_RECORD], int buildingCount);
int deleteBuilding(building b[MAX_RECORD], int buildingCount);
void displayBuilding(building b[MAX_RECORD], int buildingCount);

void addCitizen(citizen c[MAX_RECORD], int citizenCount);
void updateCitizen(citizen c[MAX_RECORD], int citizenCount);
int deleteCitizen(citizen c[MAX_RECORD], int citizenCount);
void displayCitizen(citizen c[MAX_RECORD], int citizenCount);

void addService(service s[MAX_RECORD], int serviceCount);
void updateService(service s[MAX_RECORD], int serviceCount);
int deleteService(service s[MAX_RECORD], int serviceCount);
void displayService(service s[MAX_RECORD], int serviceCount);

int addUsage(citizen c[MAX_RECORD], service s[MAX_RECORD], usage u[MAX_RECORD], int citizenCount, int serviceCount, int usageCount);
void updateUsage(citizen c[MAX_RECORD], service s[MAX_RECORD], usage u[MAX_RECORD], int citizenCount, int serviceCount, int usageCount);
int deleteUsage(usage u[MAX_RECORD], int usageCount);
void displayUsage(usage u[MAX_RECORD], int usageCount);

void search(building b[MAX_RECORD], citizen c[MAX_RECORD], service s[MAX_RECORD], usage u[MAX_RECORD], int buildingCount, int citizenCount, int servieCount, int usageCount);

void searchBuilding(building b[MAX_RECORD], int buildingCount);
void searchBuildingByName(building b[MAX_RECORD], int buildingCount);
void searchBuildingById(building b[MAX_RECORD], int buildingCount);

void searchCitizen(citizen c[MAX_RECORD], int citizenCount);
void searchCitizenByName(citizen c[MAX_RECORD], int citizenCount);
void searchCitizenById(citizen c[MAX_RECORD], int citizenCount);

void searchService(service s[MAX_RECORD], int serviceCount);
void searchServiceByName(service s[MAX_RECORD], int serviceCount);
void searchServiceById(service s[MAX_RECORD], int serviceCount);

void searchUsage(usage u[MAX_RECORD], int usageCount);
void searchUsageByServiceId(usage u[MAX_RECORD], int usageCount);
void searchUsageByCitizenId(usage u[MAX_RECORD], int usageCount);

void displayReport(building b[MAX_RECORD], citizen c[MAX_RECORD], service s[MAX_RECORD], usage u[MAX_RECORD], int buildingCount, int citizenCount, int servieCount, int usageCount);

void displayBuildingReport(building b[MAX_RECORD], int buildingCount);
void displayCitizenReport(citizen c[MAX_RECORD], int citizenCount);
void displayServiceReport(service s[MAX_RECORD], int serviceCount);
void displayUsageReport(usage u[MAX_RECORD], int usageCount);

int main()
{

    building b[MAX_RECORD];
    citizen c[MAX_RECORD];
    service s[MAX_RECORD];
    usage u[MAX_RECORD];

    int buildingCount = 0;
    int citizenCount = 0;
    int serviceCount = 0;
    int usageCount = 0;

    FILE *fbuilding1;

    fbuilding1 = fopen("building.txt", "r");

    fscanf(fbuilding1, "%d\n", &buildingCount);

    for (int i = 0; i < buildingCount; i++)
    {
        fscanf(fbuilding1, "%d;%50[^;];%100[^\n]\n", &b[i].bid, b[i].bname, b[i].baddress);
    }

    fclose(fbuilding1);

    FILE *fcitizen1;

    fcitizen1 = fopen("citizen.txt", "r");

    fscanf(fcitizen1, "%d\n", &citizenCount);

    for (int i = 0; i < citizenCount; i++)
    {
        fscanf(fcitizen1, "%d;%50[^;];%100[^;];%15[^\n]\n", &c[i].cid, c[i].cname, c[i].caddress, c[i].cphone);
    }

    fclose(fcitizen1);

    FILE *fservice1;

    fservice1 = fopen("service.txt", "r");

    fscanf(fservice1, "%d\n", &serviceCount);

    for (int i = 0; i < serviceCount; i++)
    {
        fscanf(fservice1, "%d;%50[^;];%f\n", &s[i].sid, s[i].sname, &s[i].sprice);
    }

    fclose(fservice1);

    FILE *fusage1;

    fusage1 = fopen("usage.txt", "r");

    fscanf(fusage1, "%d\n", &usageCount);

    for (int i = 0; i < usageCount; i++)
    {
        fscanf(fusage1, "%d;%d;%d;%f\n", &u[i].usageId, &u[i].citizenId, &u[i].serviceId, &u[i].totalCost);
    }

    fclose(fusage1);

    int choice, choice1, choice2, choice3, choice4, choice5;
    int w, x, y, z, a;

    printf("***********Town Management System***********\n\n");
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
                printf("1. MANAGE BUILDINGS\n");
                printf("2. MANAGE CITIZENS\n");
                printf("3. MANAGE SERVICES\n");
                printf("4. MANAGE USAGE\n");
                printf("0. EXIT\n");
                scanf("%d", &choice1);

                switch (choice1)
                {
                case 1:

                    do
                    {
                        printf("\nMANAGE BUILDINGS: \n");
                        printf("1. ADD BUILDING\n");
                        printf("2. UPDATE BUILDING\n");
                        printf("3. DISPLAY BUILDINGS\n");
                        printf("4. DELETE BUILDING\n");
                        printf("5. EXIT\n");

                        scanf("%d", &choice2);

                        switch (choice2)
                        {
                        case 1:
                            addBuilding(b, buildingCount);
                            buildingCount++;
                            break;
                        case 2:
                            updateBuilding(b, buildingCount);
                            break;
                        case 3:
                            displayBuilding(b, buildingCount);
                            break;
                        case 4:
                            w = deleteBuilding(b, buildingCount);
                            if (w == 1)
                            {
                                buildingCount--;
                            }
                            else
                            {
                                printf("Building not found!!!\n");
                            }
                            break;
                        case 5:
                            break;
                        default:
                            printf("Invalid input!!!\n");
                            break;
                        }

                        FILE *fbuilding;

                        fbuilding = fopen("building.txt", "w");

                        fprintf(fbuilding, "%d\n", buildingCount);

                        for (int i = 0; i < buildingCount; i++)
                        {
                            fprintf(fbuilding, "%d;%s;%s\n", b[i].bid, b[i].bname, b[i].baddress);
                        }

                        fclose(fbuilding);

                    } while (choice2 != 5);
                    break;

                case 2:

                    do
                    {
                        printf("\nMANAGE CITIZENS: \n");
                        printf("1. ADD CITIZEN\n");
                        printf("2. UPDATE CITIZEN\n");
                        printf("3. DISPLAY CITIZENS\n");
                        printf("4. DELETE CITIZEN\n");
                        printf("5. EXIT\n");

                        scanf("%d", &choice3);

                        switch (choice3)
                        {
                        case 1:
                            addCitizen(c, citizenCount);
                            citizenCount++;
                            break;
                        case 2:
                            updateCitizen(c, citizenCount);
                            break;
                        case 3:
                            displayCitizen(c, citizenCount);
                            break;
                        case 4:
                            x = deleteCitizen(c, citizenCount);
                            if (x == 1)
                            {
                                citizenCount--;
                            }
                            else
                            {
                                printf("Citizen not found!!!\n");
                            }
                            break;
                        case 5:
                            break;
                        default:
                            printf("Invalid input!!!\n");
                            break;
                        }

                        FILE *fcitizen;

                        fcitizen = fopen("citizen.txt", "w");

                        fprintf(fcitizen, "%d\n", citizenCount);

                        for (int i = 0; i < citizenCount; i++)
                        {
                            fprintf(fcitizen, "%d;%s;%s;%s\n", c[i].cid, c[i].cname, c[i].caddress, c[i].cphone);
                        }

                        fclose(fcitizen);

                    } while (choice3 != 5);

                    break;

                case 3:
                    do
                    {
                        printf("\nMANAGE SERVICES: \n");
                        printf("1. ADD SERVICE\n");
                        printf("2. UPDATE SERVICE\n");
                        printf("3. DISPLAY SERVICES\n");
                        printf("4. DELETE SERVICE\n");
                        printf("5. EXIT\n");

                        scanf("%d", &choice4);

                        switch (choice4)
                        {
                        case 1:
                            addService(s, serviceCount);
                            serviceCount++;
                            break;
                        case 2:
                            updateService(s, serviceCount);
                            break;
                        case 3:
                            displayService(s, serviceCount);
                            break;
                        case 4:
                            y = deleteService(s, serviceCount);
                            if (y == 1)
                            {
                                serviceCount--;
                            }
                            else
                            {
                                printf("Services not found!!!\n");
                            }
                            break;
                        case 5:
                            break;
                        default:
                            printf("Invalid input!!!\n");
                            break;
                        }

                        FILE *fservice;

                        fservice = fopen("service.txt", "w");

                        fprintf(fservice, "%d\n", serviceCount);

                        for (int i = 0; i < serviceCount; i++)
                        {
                            fprintf(fservice, "%d;%s;%.2f\n", s[i].sid, s[i].sname, s[i].sprice);
                        }

                        fclose(fservice);

                    } while (choice4 != 5);
                    break;

                case 4:
                    do
                    {
                        printf("\nMANAGE USAGE: \n");
                        printf("1. ADD USAGE\n");
                        printf("2. UPDATE USAGE\n");
                        printf("3. DISPLAY USAGE\n");
                        printf("4. DELETE USAGE\n");
                        printf("5. EXIT\n");

                        scanf("%d", &choice5);

                        switch (choice5)
                        {
                        case 1:
                            a = addUsage(c, s, u, citizenCount, serviceCount, usageCount);
                            if (a == 1)
                            {
                                usageCount++;
                            }
                            break;
                        case 2:
                            updateUsage(c, s, u, citizenCount, serviceCount, usageCount);

                            break;
                        case 3:
                            displayUsage(u, usageCount);
                            break;
                        case 4:
                            z = deleteUsage(u, usageCount);
                            if (z == 1)
                            {
                                usageCount--;
                            }
                            else
                            {
                                printf("Usage not found!!!\n");
                            }
                            break;
                        case 5:
                            break;
                        default:
                            printf("Invalid input!!!\n");
                            break;
                        }

                        FILE *fusage;

                        fusage = fopen("usage.txt", "w");

                        fprintf(fusage, "%d\n", usageCount);

                        for (int i = 0; i < usageCount; i++)
                        {
                            fprintf(fusage, "%d;%d;%d;%.2f\n", u[i].usageId, u[i].citizenId, u[i].serviceId, u[i].totalCost);
                        }

                        fclose(fusage);

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
            search(b, c, s, u, buildingCount, citizenCount, serviceCount, usageCount);
            break;

        case 3:
            displayReport(b, c, s, u, buildingCount, citizenCount, serviceCount, usageCount);
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

void addBuilding(building b[MAX_RECORD], int buildingCount)
{
    printf("\nEnter Building ID: ");
    scanf("%d", &b[buildingCount].bid);

    printf("Enter the name of the building: ");
    scanf(" %[^\n]s", b[buildingCount].bname);

    printf("Enter the address of the building: ");
    scanf(" %[^\n]s", b[buildingCount].baddress);

    printf("Building added successfully!!\n");
}

void updateBuilding(building b[MAX_RECORD], int buildingCount)
{
    int id;
    printf("\nEnter Building ID to update: ");
    scanf("%d", &id);

    for (int i = 0; i < buildingCount; i++)
    {
        if (b[i].bid == id)
        {
            printf("Enter new name: ");
            scanf(" %[^\n]s", b[i].bname);

            printf("Enter new address: ");
            scanf(" %[^\n]s", b[i].baddress);

            printf("Building updated successfully!!!\n");
            return;
        }
    }
    printf("Building ID not found!!!\n");
}

int deleteBuilding(building b[MAX_RECORD], int buildingCount)
{
    int id, found = -1;
    printf("\nEnter the ID number of the building you want to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < buildingCount; i++)
    {
        if (b[i].bid == id)
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
        for (int j = found; j < buildingCount - 1; j++)
        {
            b[j] = b[j + 1];
        }
        printf("Building deleted successfully!!!\n");
        return 1;
    }
}

void displayBuilding(building b[MAX_RECORD], int buildingCount)
{
    for (int i = 0; i < buildingCount; i++)
    {
        printf("\nBuilding %d: \n", i + 1);
        printf("ID: %d, NAME: %s, ADDRESS: %s\n", b[i].bid, b[i].bname, b[i].baddress);
    }
    if (buildingCount == 0)
    {
        printf("\nNo buildings available!!!\n");
    }
}

void addCitizen(citizen c[MAX_RECORD], int citizenCount)
{
    printf("\nEnter Citizen ID: ");
    scanf("%d", &c[citizenCount].cid);

    printf("Enter the name of the citizen: ");
    scanf(" %[^\n]s", c[citizenCount].cname);

    printf("Enter the address of the citizen: ");
    scanf(" %[^\n]s", c[citizenCount].caddress);

    printf("Enter the phone number of the citizen: ");
    scanf(" %[^\n]s", c[citizenCount].cphone);

    printf("Citizen added successfully!!\n");
}

void updateCitizen(citizen c[MAX_RECORD], int citizenCount)
{
    int id;
    printf("\nEnter Citizen ID to update: ");
    scanf("%d", &id);

    for (int i = 0; i < citizenCount; i++)
    {
        if (c[i].cid == id)
        {
            printf("Enter new name: ");
            scanf(" %[^\n]s", c[i].cname);

            printf("Enter new address: ");
            scanf(" %[^\n]s", c[i].caddress);

            printf("Enter new phone number: ");
            scanf(" %[^\n]s", c[i].cphone);

            printf("Citizen updated successfully!!!\n");
            return;
        }
    }
    printf("Citizen ID not found!!!\n");
}

int deleteCitizen(citizen c[MAX_RECORD], int citizenCount)
{
    int id, found = -1;
    printf("\nEnter the ID number of the citizen you want to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < citizenCount; i++)
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
        for (int j = found; j < citizenCount - 1; j++)
        {
            c[j] = c[j + 1];
        }
        printf("Citizen deleted successfully!!!\n");
        return 1;
    }
}

void displayCitizen(citizen c[MAX_RECORD], int citizenCount)
{
    for (int i = 0; i < citizenCount; i++)
    {
        printf("\nCitizen %d: \n", i + 1);
        printf("ID: %d, NAME: %s, ADDRESS: %s, PHONE: %s\n", c[i].cid, c[i].cname, c[i].caddress, c[i].cphone);
    }
    if (citizenCount == 0)
    {
        printf("\nNo citizens available!!!\n");
    }
}

void addService(service s[MAX_RECORD], int serviceCount)
{

    printf("\nEnter Service ID: ");
    scanf("%d", &s[serviceCount].sid);

    printf("Enter the name of the service: ");
    scanf(" %[^\n]s", s[serviceCount].sname);

    printf("Enter the price of the service: ");
    scanf("%f", &s[serviceCount].sprice);

    printf("Service added successfully!!\n");
}

void updateService(service s[MAX_RECORD], int serviceCount)
{
    int id;
    printf("\nEnter Service ID to update: ");
    scanf("%d", &id);

    for (int i = 0; i < serviceCount; i++)
    {
        if (s[i].sid == id)
        {
            printf("Enter new name: ");
            scanf(" %[^\n]s", s[i].sname);

            printf("Enter new price: ");
            scanf("%f", &s[i].sprice);

            printf("Service updated successfully!!!\n");
            return;
        }
    }
    printf("Service ID not found!!!\n");
}

int deleteService(service s[MAX_RECORD], int serviceCount)
{
    int id, found = -1;
    printf("\nEnter the ID number of the service you want to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < serviceCount; i++)
    {
        if (s[i].sid == id)
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
        for (int j = found; j < serviceCount - 1; j++)
        {
            s[j] = s[j + 1];
        }
        printf("Service deleted successfully!!!\n");
        return 1;
    }
}

void displayService(service s[MAX_RECORD], int serviceCount)
{
    for (int i = 0; i < serviceCount; i++)
    {
        printf("\nService %d: \n", i + 1);
        printf("ID: %d, NAME: %s, PRICE: %.2f\n", s[i].sid, s[i].sname, s[i].sprice);
    }
    if (serviceCount == 0)
    {
        printf("\nNo services available!!!\n");
    }
}

int addUsage(citizen c[MAX_RECORD], service s[MAX_RECORD], usage u[MAX_RECORD], int citizenCount, int serviceCount, int usageCount)
{
    
    return 1;
}

void updateUsage(citizen c[MAX_RECORD], service s[MAX_RECORD], usage u[MAX_RECORD], int citizenCount, int serviceCount, int usageCount)
{
    int id, citizenID, serviceID;
    printf("\nEnter Usage ID to update: ");
    scanf("%d", &id);

    for (int i = 0; i < usageCount; i++)
    {
        if (u[i].usageId == id)
        {
            printf("Enter new Citizen ID: ");
            scanf("%d", &citizenID);

            int citizenExist = 0;
            for (int i = 0; i < citizenCount; i++)
            {
                if (c[i].cid == citizenID)
                {
                    citizenExist = 1;
                    break;
                }
            }
            if (citizenExist == 0)
            {
                printf("Citizen id not found!!!\n");
                return;
            }

            printf("Enter new Service ID: ");
            scanf("%d", &serviceID);

            int serviceExist = 0;
            for (int i = 0; i < serviceCount; i++)
            {
                if (s[i].sid == serviceID)
                {
                    serviceExist = 1;
                    break;
                }
            }

            if (serviceExist == 0)
            {
                printf("service id not found!!!\n");
                return;
            }

            u[i].citizenId = citizenID;
            u[i].serviceId = serviceID;

            // Update total cost based on new service price
            for (int j = 0; j < serviceCount; j++)
            {
                if (s[j].sid == u[i].serviceId)
                {
                    u[i].totalCost = s[j].sprice;
                    break;
                }
            }

            printf("Usage updated successfully!!!\n");
        }
    }
    if (usageCount = 0)
    {
        printf("Usage ID not found!!!\n");
    }
}

int deleteUsage(usage u[MAX_RECORD], int usageCount)
{
    int id, found = -1;
    printf("\nEnter the ID number of the usage you want to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < usageCount; i++)
    {
        if (u[i].usageId == id)
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
        for (int j = found; j < usageCount - 1; j++)
        {
            u[j] = u[j + 1];
        }
        printf("Usage deleted successfully!!!\n");
        return 1;
    }
}

void displayUsage(usage u[MAX_RECORD], int usageCount)
{
    for (int i = 0; i < usageCount; i++)
    {
        printf("\nUsage %d: \n", i + 1);
        printf("Usage ID: %d, Citizen ID: %d, Service ID: %d, Total Cost: %.2f\n", u[i].usageId, u[i].citizenId, u[i].serviceId, u[i].totalCost);
    }
    if (usageCount == 0)
    {
        printf("\nNo usages available!!!\n");
    }
}

void search(building b[MAX_RECORD], citizen c[MAX_RECORD], service s[MAX_RECORD], usage u[MAX_RECORD], int buildingCount, int citizenCount, int servieCount, int usageCount)
{
    int choice;
    do
    {
        printf("\nSEARCH: \n");
        printf("1. SEARCH BUILDING\n");
        printf("2. SEARCH CITIZEN\n");
        printf("3. SEARCH SERVICE\n");
        printf("4. SEARCH USAGE\n");
        printf("5. EXIT\n");

        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            searchBuilding(b, buildingCount);
            break;
        case 2:
            searchCitizen(c, citizenCount);
            break;
        case 3:
            searchService(s, servieCount);
            break;
        case 4:
            searchUsage(u, usageCount);
            break;
        case 5:
            break;
        default:
            printf("Invalid input!!!\n");
            break;
        }
    } while (choice != 5);
}

void searchBuilding(building b[MAX_RECORD], int buildingCount)
{
    int choice;
    do
    {
        printf("\nSEARCH BUILDING: \n");
        printf("1. SEARCH BY NAME\n");
        printf("2. SEARCH BY ID\n");
        printf("3. EXIT\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            searchBuildingByName(b, buildingCount);
            break;
        case 2:
            searchBuildingById(b, buildingCount);
            break;
        case 3:
            break;
        default:
            printf("Invalid input!!!\n");
            break;
        }
    } while (choice != 3);
}

void searchBuildingByName(building b[MAX_RECORD], int buildingCount)
{
    char name[50];
    printf("Enter building name to search: ");
    scanf(" %[^\n]s", name);

    for (int i = 0; i < buildingCount; i++)
    {
        if (strcmp(b[i].bname, name) == 0)
        {
            printf("\nBuilding found: ID: %d, NAME: %s, ADDRESS: %s\n", b[i].bid, b[i].bname, b[i].baddress);
            return;
        }
    }
    printf("Building not found!!!\n");
}

void searchBuildingById(building b[MAX_RECORD], int buildingCount)
{
    int id;
    printf("Enter building ID to search: ");
    scanf("%d", &id);

    for (int i = 0; i < buildingCount; i++)
    {
        if (b[i].bid == id)
        {
            printf("\nBuilding found: ID: %d, NAME: %s, ADDRESS: %s\n", b[i].bid, b[i].bname, b[i].baddress);
            return;
        }
    }
    printf("Building not found!!!\n");
}

void searchCitizen(citizen c[MAX_RECORD], int citizenCount)
{
    int choice;
    do
    {
        printf("\nSEARCH CITIZEN: \n");
        printf("1. SEARCH BY NAME\n");
        printf("2. SEARCH BY ID\n");
        printf("3. EXIT\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            searchCitizenByName(c, citizenCount);
            break;
        case 2:
            searchCitizenById(c, citizenCount);
            break;
        case 3:
            break;
        default:
            printf("Invalid input!!!\n");
            break;
        }
    } while (choice != 3);
}

void searchCitizenByName(citizen c[MAX_RECORD], int citizenCount)
{
    char name[50];
    printf("Enter citizen name to search: ");
    scanf(" %[^\n]s", name);

    for (int i = 0; i < citizenCount; i++)
    {
        if (strcmp(c[i].cname, name) == 0)
        {
            printf("\nCitizen found: ID: %d, NAME: %s, ADDRESS: %s, PHONE: %s\n", c[i].cid, c[i].cname, c[i].caddress, c[i].cphone);
            return;
        }
    }
    printf("Citizen not found!!!\n");
}

void searchCitizenById(citizen c[MAX_RECORD], int citizenCount)
{
    int id;
    printf("Enter citizen ID to search: ");
    scanf("%d", &id);

    for (int i = 0; i < citizenCount; i++)
    {
        if (c[i].cid == id)
        {
            printf("\nCitizen found: ID: %d, NAME: %s, ADDRESS: %s, PHONE: %s\n", c[i].cid, c[i].cname, c[i].caddress, c[i].cphone);
            return;
        }
    }
    printf("Citizen not found!!!\n");
}

void searchService(service s[MAX_RECORD], int serviceCount)
{
    int choice;
    do
    {
        printf("\nSEARCH SERVICE: \n");
        printf("1. SEARCH BY NAME\n");
        printf("2. SEARCH BY ID\n");
        printf("3. EXIT\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            searchServiceByName(s, serviceCount);
            break;
        case 2:
            searchServiceById(s, serviceCount);
            break;
        case 3:
            break;
        default:
            printf("Invalid input!!!\n");
            break;
        }
    } while (choice != 3);
}

void searchServiceByName(service s[MAX_RECORD], int serviceCount)
{
    char name[50];
    printf("Enter service name to search: ");
    scanf(" %[^\n]s", name);

    for (int i = 0; i < serviceCount; i++)
    {
        if (strcmp(s[i].sname, name) == 0)
        {
            printf("\nService found: ID: %d, NAME: %s, PRICE: %.2f\n", s[i].sid, s[i].sname, s[i].sprice);
            return;
        }
    }
    printf("Service not found!!!\n");
}

void searchServiceById(service s[MAX_RECORD], int serviceCount)
{
    int id;
    printf("Enter service ID to search: ");
    scanf("%d", &id);

    for (int i = 0; i < serviceCount; i++)
    {
        if (s[i].sid == id)
        {
            printf("\nService found: ID: %d, NAME: %s, PRICE: %.2f\n", s[i].sid, s[i].sname, s[i].sprice);
            return;
        }
    }
    printf("Service not found!!!\n");
}

void searchUsage(usage u[MAX_RECORD], int usageCount)
{
    int choice;
    do
    {
        printf("\nSEARCH USAGE: \n");
        printf("1. SEARCH BY CITIZEN ID\n");
        printf("2. SEARCH BY SERVICE ID\n");
        printf("3. EXIT\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            searchUsageByCitizenId(u, usageCount);
            break;
        case 2:
            searchUsageByServiceId(u, usageCount);
            break;
        case 3:
            break;
        default:
            printf("Invalid input!!!\n");
            break;
        }
    } while (choice != 3);
}

void searchUsageByCitizenId(usage u[MAX_RECORD], int usageCount)
{
    int id;
    printf("Enter citizen ID to search usage: ");
    scanf("%d", &id);

    for (int i = 0; i < usageCount; i++)
    {
        if (u[i].citizenId == id)
        {
            printf("\nUsage found: Usage ID: %d, Citizen ID: %d, Service ID: %d, Total Cost: %.2f\n", u[i].usageId, u[i].citizenId, u[i].serviceId, u[i].totalCost);
            return;
        }
    }
    printf("Usage not found!!!\n");
}

void searchUsageByServiceId(usage u[MAX_RECORD], int usageCount)
{
    int id;
    printf("Enter service ID to search usage: ");
    scanf("%d", &id);

    for (int i = 0; i < usageCount; i++)
    {
        if (u[i].serviceId == id)
        {
            printf("\nUsage found: Usage ID: %d, Citizen ID: %d, Service ID: %d, Total Cost: %.2f\n", u[i].usageId, u[i].citizenId, u[i].serviceId, u[i].totalCost);
            return;
        }
    }
    printf("Usage not found!!!\n");
}
void displayReport(building b[MAX_RECORD], citizen c[MAX_RECORD], service s[MAX_RECORD], usage u[MAX_RECORD], int buildingCount, int citizenCount, int servieCount, int usageCount)
{
    int choice;
    do
    {
        printf("\n********REPORT********\n\n");
        printf("1. DISPLAY REPORT FOR BUILDING\n");
        printf("2. DISPLAY REPORT FOR CITIZEN\n");
        printf("3. DISPLAY REPORT FOR SERVICES\n");
        printf("4. DISPLAY REPORT FOR USAGE\n");
        printf("0. EXIT\n");

        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            displayBuildingReport(b, buildingCount);
            break;
        case 2:
            displayCitizenReport(c, citizenCount);
            break;
        case 3:
            displayServiceReport(s, servieCount);
            break;
        case 4:
            displayUsageReport(u, usageCount);
            break;
        case 0:
            break;
        default:
            printf("Invalid input!!!\n");
        }
    } while (choice != 0);
}

void displayBuildingReport(building b[MAX_RECORD], int buildingCount)
{
    printf("\n***********Building Report***********\n\n");
    for (int i = 0; i < buildingCount; i++)
    {
        printf("Building ID: %d\n", b[i].bid);
        printf("Building Name: %s\n", b[i].bname);
        printf("Building Address: %s\n", b[i].baddress);
        printf("-------------------------------------\n");
    }
    if (buildingCount == 0)
    {
        printf("No buildings available!!!\n");
    }
}

void displayCitizenReport(citizen c[MAX_RECORD], int citizenCount)
{
    printf("\n***********Citizen Report***********\n\n");
    for (int i = 0; i < citizenCount; i++)
    {
        printf("Citizen ID: %d\n", c[i].cid);
        printf("Citizen Name: %s\n", c[i].cname);
        printf("Citizen Address: %s\n", c[i].caddress);
        printf("Citizen Phone: %s\n", c[i].cphone);
        printf("-------------------------------------\n");
    }
    if (citizenCount == 0)
    {
        printf("No citizens available!!!\n");
    }
}

void displayServiceReport(service s[MAX_RECORD], int serviceCount)
{
    printf("\n***********Service Report***********\n");
    for (int i = 0; i < serviceCount; i++)
    {
        printf("Service ID: %d\n", s[i].sid);
        printf("Service Name: %s\n", s[i].sname);
        printf("Service Price: %.2f\n", s[i].sprice);
        printf("-------------------------------------\n");
    }
    if (serviceCount == 0)
    {
        printf("No services available!!!\n");
    }
}

void displayUsageReport(usage u[MAX_RECORD], int usageCount)
{
    printf("\n***********Usage Report***********\n");
    for (int i = 0; i < usageCount; i++)
    {
        printf("Usage ID: %d\n", u[i].usageId);
        printf("Citizen ID: %d\n", u[i].citizenId);
        printf("Service ID: %d\n", u[i].serviceId);
        printf("Total Cost: %.2f\n", u[i].totalCost);
        printf("-------------------------------------\n");
    }
    if (usageCount == 0)
    {
        printf("No usages available!!!\n");
    }
}