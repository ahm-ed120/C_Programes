#include <stdio.h>
#include <string.h>

#define MAX_RECORD 1000

typedef struct
{
    int test_id;
    char test_name[50];
    float test_price;
} test_inventory;

typedef struct
{
    int id;
    char name[50];
    char phone[15];
    char address[100];
    char email[50];
    char designation[50];
    int salary;
    int days_off;
} employee;

typedef struct
{
    int invoice_number;
    char name[100];
    char phone[20];
    char email[100];
    char address[100];
    char blood_type[10];
    char test[100];
    int payment;
} patient;

typedef struct medical_report
{
    int report_id;
    char patient_name[101];
    char test_name[101];
    char report_date[11];
    int report_status;
} medical_report;

// Test Inventory Management Functions
void add_test_inventory(test_inventory t[MAX_RECORD], int testCount);
void update_test_inventory(test_inventory t[MAX_RECORD], int testCount);
int delete_test_inventory(test_inventory t[MAX_RECORD], int testCount);
void display_test_inventory(test_inventory t[MAX_RECORD], int testCount);
void search_test_inventory(test_inventory t[MAX_RECORD], int testcount);
void search_test_name(test_inventory t[MAX_RECORD], int testcount);
void search_test_id(test_inventory t[MAX_RECORD], int testcount);
void displayRecord_in(int testCount);
void displayReport_in(test_inventory t[MAX_RECORD], int testCount);

// Employee Management Functions
void add_employee(employee emp[MAX_RECORD], int employeeCount);
void update_employee(employee emp[MAX_RECORD], int employeeCount);
int delete_employee(employee emp[MAX_RECORD], int employeeCount);
void display_employee(employee emp[MAX_RECORD], int employeeCount);
void search_employee(employee emp[MAX_RECORD], int employeeCount);
void search_employee_name(employee emp[MAX_RECORD], int employeeCount);
void search_employee_id(employee emp[MAX_RECORD], int employeeCount);
void displayRecord_e(int employeeCount);
void displayReport_e(employee emp[MAX_RECORD], int employeeCount);

// Patient Management Functions
void add_patient(patient pat[MAX_RECORD], int patientCount);
void update_patient(patient pat[MAX_RECORD], int patientCount);
int delete_patient(patient pat[MAX_RECORD], int patientCount);
void display_patient(patient pat[MAX_RECORD], int patientCount);
void search_patient(patient pat[MAX_RECORD], int patientCount);
void search_patient_name(patient pat[MAX_RECORD], int patientCount);
void search_patient_id(patient pat[MAX_RECORD], int patientCount);
void displayRecord_p(int patientCount);
void displayReport_p(patient pat[MAX_RECORD], int patientCount);

// Medical Report functions
int add_medical_report(medical_report med[MAX_RECORD], int medicalCount, patient pat[MAX_RECORD], test_inventory t[MAX_RECORD], int patientCount, int testCount);
void update_medical_report(medical_report med[MAX_RECORD], int medicalCount, patient pat[MAX_RECORD], test_inventory t[MAX_RECORD], int patientCount, int testCoun);
int delete_medical_report(medical_report med[MAX_RECORD], int medicalCount);
void display_medical_reports(medical_report med[MAX_RECORD], int medicalCount);
void search_medical_report(medical_report med[MAX_RECORD], int medicalCount);
void search_medical_report_name(medical_report med[MAX_RECORD], int medicalCount);
void search_medical_report_id(medical_report med[MAX_RECORD], int medicalCount);
void displayRecord_m(int medicalCount);
void displayReport_m(medical_report med[MAX_RECORD], int medicalCount, test_inventory t[MAX_RECORD]);

int main()
{
    test_inventory t[MAX_RECORD];
    int testCount = 0;

    employee emp[MAX_RECORD];
    int employeeCount = 0;

    patient pat[MAX_RECORD];
    int patientCount = 0;

    medical_report med[MAX_RECORD];
    int medicalCount = 0;

    int choice, choice_t, choice1, choice_e, choice2, choice_p, choice3, choice_m, choice4;
    int w, x, y, z, f;

    FILE *te1, *emp1, *pat1, *me1;

    printf("Welcome To Shaukat Khanum Lab Management System\n");

    do
    {
        printf("\n1. Test Inventory Management\n");
        printf("2. Employee Management\n");
        printf("3. Patient Management\n");
        printf("4. Medical Report Management\n");
        printf("0. Exit Shaukat Khanum Lab Management System\n\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:

            te1 = fopen("Manage Shaukat Khanum Lab Test Inventory.txt", "r");

            fscanf(te1, "%d\n", &testCount);

            for (int i = 0; i < testCount; i++)
            {
                fscanf(te1, "%d,%100[^,],%f\n", &t[i].test_id, t[i].test_name, &t[i].test_price);
            }
            fclose(te1);

            do
            {
                printf("\n1. MANAGE TEST INVENTORY\n");
                printf("2. Search Test Inventory\n");
                printf("3. DISPLAY TOTAL NUMBER OF RECORDS\n");
                printf("4. DISPLAY MEANINGFUL REPORT\n");
                printf("0. Exit Test Inventory Management\n\n");
                scanf("%d", &choice_t);

                switch (choice_t)
                {
                case 1:
                    do
                    {
                        printf("\nMANAGE TEST INVENTORY : \n");
                        printf("1. ADD TEST\n");
                        printf("2. UPDATE TEST\n");
                        printf("3. DISPLAY TEST\n");
                        printf("4. DELETE TEST\n");
                        printf("5. EXIT\n");

                        scanf("%d", &choice1);

                        switch (choice1)
                        {
                        case 1:
                            add_test_inventory(t, testCount);
                            testCount++;
                            break;

                        case 2:
                            update_test_inventory(t, testCount);
                            break;

                        case 3:
                            display_test_inventory(t, testCount);
                            break;

                        case 4:
                            w = delete_test_inventory(t, testCount);
                            if (w == 1)
                            {
                                testCount--;
                            }
                            else
                            {
                                printf("Test Inventory not found !!!\n");
                            }
                            break;

                        case 5:
                            break;
                        default:
                            printf("Invalid choice!\n");
                        }

                        FILE *TEST;

                        TEST = fopen("Manage Shaukat Khanum Lab Test Inventory.txt", "w");

                        fprintf(TEST, "%d\n", testCount);

                        for (int i = 0; i < testCount; i++)
                        {
                            fprintf(TEST, "%d,%s,%.2f\n", t[i].test_id, t[i].test_name, t[i].test_price);
                        }

                    } while (choice1 != 5);
                    break;

                case 2:
                    search_test_inventory(t, testCount);
                    break;

                case 3:
                    displayRecord_in(testCount);
                    break;

                case 4:
                    displayReport_in(t, testCount);
                    break;

                case 0:
                    printf("Successfully exiting Test Inventory Management\n");
                    break;

                default:
                    printf("Invalid Input!!!!!\n");
                }
            } while (choice_t != 0);
            break;

        case 2:

            emp1 = fopen("Manage Shaukat khanum Lab Employee.txt", "r");

            fscanf(emp1, "%d\n", &employeeCount);

            for (int i = 0; i < employeeCount; i++)
            {
                fscanf(emp1, "%d,%50[^,],%20[^,],%100[^,],%50[^,],%50[^,],%d,%d\n",
                       &emp[i].id, emp[i].name, emp[i].phone, emp[i].address,
                       emp[i].email, emp[i].designation, &emp[i].salary, &emp[i].days_off);
            }
            fclose(emp1);

            do
            {
                printf("\n1. MANAGE EMPLOYEE DATA\n");
                printf("2. Search Employee\n");
                printf("3. DISPLAY TOTAL NUMBER OF RECORDS\n");
                printf("4. DISPLAY MEANINGFUL REPORT\n");
                printf("0. Exit Employee Management\n\n");
                scanf("%d", &choice_e);

                switch (choice_e)
                {
                case 1:
                    do
                    {
                        printf("\nMANAGE EMPLOYEE : \n");
                        printf("1. ADD Employee\n");
                        printf("2. UPDATE Employee\n");
                        printf("3. DISPLAY Employee\n");
                        printf("4. DELETE Employee\n");
                        printf("5. EXIT\n");

                        scanf("%d", &choice2);

                        switch (choice2)
                        {
                        case 1:
                            add_employee(emp, employeeCount);
                            employeeCount++;
                            break;

                        case 2:
                            update_employee(emp, employeeCount);
                            break;

                        case 3:
                            display_employee(emp, employeeCount);
                            break;

                        case 4:
                            x = delete_employee(emp, employeeCount);
                            if (x == 1)
                            {
                                employeeCount--;
                            }
                            else
                            {
                                printf("Employee not found !!!\n");
                            }
                            break;

                        case 5:
                            break;

                        default:
                            printf("Invalid choice!\n");
                        }

                        FILE *employee;
                        employee = fopen("Manage Shaukat khanum Lab Employee.txt", "w");

                        fprintf(employee, "%d\n", employeeCount);

                        for (int i = 0; i < employeeCount; i++)
                        {
                            fprintf(employee, "%d,%s,%s,%s,%s,%s,%d,%d\n", emp[i].id, emp[i].name, emp[i].phone,
                                    emp[i].address, emp[i].email, emp[i].designation, emp[i].salary, emp[i].days_off);
                        }

                        fclose(employee);

                    } while (choice2 != 5);
                    break;

                case 2:
                    search_employee(emp, employeeCount);
                    break;

                case 3:
                    displayRecord_e(employeeCount);
                    break;
                case 4:
                    displayReport_e(emp, employeeCount);
                    break;
                case 0:
                    printf("Successfully exiting Employee Management\n");
                    break;
                default:
                    printf("Invalid Input!!!!!\n");
                }
            } while (choice_e != 0);
            break;

        case 3:

            pat1 = fopen("Manage Shaukat khanum Lab Patient.txt", "r");

            fscanf(pat1, "%d\n", &patientCount);

            for (int i = 0; i < patientCount; i++)
            {
                fscanf(pat1, "%d,%100[^,],%20[^,],%100[^,],%100[^,],%10[^,],%100[^,],%d\n",
                       &pat[i].invoice_number, pat[i].name, pat[i].phone,
                       pat[i].email, pat[i].address, pat[i].blood_type,
                       pat[i].test, &pat[i].payment);
            }
            fclose(pat1);

            do
            {
                printf("\n1. MANAGE PATIENTS DATA\n");
                printf("2. Search Patient\n");
                printf("3. DISPLAY TOTAL NUMBER OF RECORDS\n");
                printf("4. DISPLAY MEANINGFUL REPORT\n");
                printf("0. Exit Patient Management\n\n");
                scanf("%d", &choice_p);

                switch (choice_p)
                {
                case 1:
                    do
                    {
                        printf("\nMANAGE PATIENT : \n");
                        printf("1. ADD Patient\n");
                        printf("2. UPDATE Patient\n");
                        printf("3. DISPLAY Patient\n");
                        printf("4. DELETE Patient\n");
                        printf("5. EXIT\n");

                        scanf("%d", &choice3);

                        switch (choice3)
                        {
                        case 1:
                            add_patient(pat, patientCount);
                            patientCount++;
                            break;

                        case 2:
                            update_patient(pat, patientCount);
                            break;

                        case 3:
                            display_patient(pat, patientCount);
                            break;

                        case 4:
                            y = delete_patient(pat, patientCount);
                            if (y == 1)
                            {
                                patientCount--;
                            }
                            else
                            {
                                printf("Patient not found !!!\n");
                            }
                            break;

                        case 5:
                            break;
                        default:
                            printf("Invalid choice!\n");
                        }

                        FILE *patient;
                        patient = fopen("Manage Shaukat khanum Lab Patient.txt", "w");

                        fprintf(patient, "%d\n", patientCount);

                        for (int i = 0; i < patientCount; i++)
                        {
                            fprintf(patient, "%d,%s,%s,%s,%s,%s,%s,%d\n", pat[i].invoice_number, pat[i].name, pat[i].phone,
                                    pat[i].email, pat[i].address, pat[i].blood_type,
                                    pat[i].test, pat[i].payment);
                        }

                        fclose(patient);

                    } while (choice3 != 5);
                    break;

                case 2:
                    search_patient(pat, patientCount);
                    break;

                case 3:
                    displayRecord_p(patientCount);
                    break;
                case 4:
                    displayReport_p(pat, patientCount);
                    break;
                case 0:
                    printf("Successfully exiting Patients Management\n");
                    break;
                default:
                    printf("Invalid Input!!!!!\n");
                }
            } while (choice_p != 0);

            break;

        case 4:

            me1 = fopen("Manage_Shaukat_khanum_Lab_MEDICAL_REPORT.txt", "r");

            fscanf(me1, "%d\n", &medicalCount);

            for (int i = 0; i < medicalCount; i++)
            {
                fscanf(me1, "%d,%100[^,],%100[^,],%100[^,],%d\n", &med[i].report_id, med[i].patient_name, med[i].test_name,
                       med[i].report_date, &med[i].report_status);
            }
            fclose(me1);

            do
            {
                printf("\n1. MANAGE MEDICAL REPORT\n");
                printf("2. SEARCH MEDICAL REPORT\n");
                printf("3. DISPLAY TOTAL NUMBER OF REPORTS\n");
                printf("4. DISPLAY MEANINGFUL REPORT\n");
                printf("0. Exit MEDICAL REPORT Management\n\n");
                scanf("%d", &choice_m);

                switch (choice_m)
                {
                case 1:
                    do
                    {
                        printf("\nMANAGE MEDICAL REPORT: \n");
                        printf("1. ADD MEDICAL REPORT\n");
                        printf("2. UPDATE MEDICAL REPORT\n");
                        printf("3. DISPLAY MEDICAL REPORT\n");
                        printf("4. DELETE MEDICAL REPORT\n");
                        printf("5. EXIT\n");

                        scanf("%d", &choice4);

                        switch (choice4)
                        {
                        case 1:
                            f = add_medical_report(med, medicalCount, pat, t, patientCount, testCount);
                            if (f == 1)
                            {
                                medicalCount++;
                            }
                            break;

                        case 2:
                            update_medical_report(med, medicalCount, pat, t, patientCount, testCount);
                            break;

                        case 3:
                            display_medical_reports(med, medicalCount);
                            break;

                        case 4:
                            z = delete_medical_report(med, medicalCount);
                            if (z == 1)
                            {
                                medicalCount--;
                            }
                            else
                            {
                                printf("Medical report not found !!!\n");
                            }
                            break;

                        case 5:
                            break;

                        default:
                            printf("Invalid choice!\n");
                        }

                        FILE *medical;

                        medical = fopen("Manage_Shaukat_khanum_Lab_MEDICAL_REPORT.txt", "w");

                        fprintf(medical, "%d\n", medicalCount);

                        for (int i = 0; i < medicalCount; i++)
                        {
                            fprintf(medical, "%d,%s,%s,%s,%d\n", med[i].report_id, med[i].patient_name,
                                    med[i].test_name, med[i].report_date, med[i].report_status);
                        }

                    } while (choice4 != 5);
                    break;

                case 2:
                    search_medical_report(med, medicalCount);
                    break;

                case 3:
                    displayRecord_m(medicalCount);
                    break;
                case 4:
                    displayReport_m(med, medicalCount, t);
                    break;
                case 0:
                    printf("Successfully exiting Medical Report Management\n");
                    break;
                default:
                    printf("Invalid Input!!!!!\n");
                }
            } while (choice_m != 0);
            break;

        case 0:
            printf("Exiting Shaukat Khanum Lab Managment System\n");
            break;
        default:
            printf("Invalid Input!!!!!\n");
        }
    } while (choice != 0);

    return 0;
}

// Test Inventory Management Functions
void add_test_inventory(test_inventory t[MAX_RECORD], int testCount)
{
    if (testCount >= MAX_RECORD)
    {
        printf("Cannot add more Tests. Inventory is full.\n");
        return;
    }

    printf("\nEnter Test Id:\n");
    scanf("%d", &t[testCount].test_id);

    printf("Enter Test Name:\n");
    scanf(" %[^\n]s", t[testCount].test_name);

    printf("Enter Test Price:\n");
    scanf(" %f", &t[testCount].test_price);

    printf("Test added successfully into the Inventory!\n");
}

void update_test_inventory(test_inventory t[MAX_RECORD], int testCount)
{
    int id;
    printf("\nEnter Test id to update: \n");
    scanf("%d", &id);

    for (int i = 0; i < testCount; i++)
    {
        if (t[i].test_id == id)
        {
            int choice;
            do
            {
                printf("\nChoose attribute to update:\n");
                printf("1. Test Name\n");
                printf("2. Test Price\n");
                printf("3. Update both\n");
                printf("4. Exit\n");
                printf("Enter your choice:\n ");
                scanf("%d", &choice);

                switch (choice)
                {
                case 1:
                    printf("Enter Test new Name:\n");
                    scanf(" %[^\n]s", t[i].test_name);
                    break;
                case 2:
                    printf("Enter Test New Price:\n");
                    scanf(" %f", &t[i].test_price);
                    break;
                case 3:
                    printf("Enter Patient new Name:\n");
                    scanf(" %[^\n]s", t[i].test_name);

                    printf("Enter Patient new Phone number:\n");
                    scanf(" %f", &t[i].test_price);
                    break;
                case 4:
                    printf("Exiting update menu.\n");
                    break;
                default:
                    printf("Invalid choice, please try again.\n");
                }
            } while (choice != 4);

            printf("Test Inventory updated successfully!\n");
            return;
        }
    }
    printf("\nTest ID not found!\n");
}

int delete_test_inventory(test_inventory t[MAX_RECORD], int testCount)
{
    int id, found = -1;
    printf("\nEnter the Test ID Number to delete : ");
    scanf("%d", &id);

    for (int i = 0; i < testCount; i++)
    {
        if (t[i].test_id == id)
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
        for (int j = found; j < testCount - 1; j++)
        {
            t[j] = t[j + 1];
        }
        return 1;
    }
}

void display_test_inventory(test_inventory t[MAX_RECORD], int testCount)
{
    if (testCount == 0)
    {
        printf("\nNo Tests available!\n");
        return;
    }
    printf("\nTEST INVENTORY\n");
    printf("-------------------------------------\n");
    for (int i = 0; i < testCount; i++)
    {
        printf("\ntest %d : \n", i + 1);
        printf("TEST ID: %d\nTEST NAME: %s\nTEST PRICE: %.2f Rs\n",
               t[i].test_id, t[i].test_name, t[i].test_price);
    }
}

void search_test_inventory(test_inventory t[MAX_RECORD], int testcount)
{
    int choice;
    do
    {
        printf("\n*SEARCH TEST INVENTORY*\n");
        printf("1.SEARCH BY TEST NAME\n");
        printf("2.SEARCH BY TEST ID\n");
        printf("3.EXIT\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            search_test_name(t, testcount);
            break;

        case 2:
            search_test_id(t, testcount);
            break;

        case 3:
            break;

        default:
            printf("\nInvalid input\n");
            break;
        }
    } while (choice != 3);
}

void search_test_name(test_inventory t[MAX_RECORD], int testcount)
{
    int found = 0;
    char name[100];

    printf("\nEnter the name of test:\n");
    scanf(" %[^\n]s", name);

    for (int i = 0; i < testcount; i++)
    {
        if (stricmp(t[i].test_name, name) == 0)
        {
            printf("Test found:\n");
            printf("ID: %d, NAME: %s, PRICE: %.2f\n", t[i].test_id, t[i].test_name, t[i].test_price);

            found = 1;
            break;
        }
    }

    if (found == 0)
    {
        printf("Test  with name %s not found!!!\n", name);
    }
}

void search_test_id(test_inventory t[MAX_RECORD], int testcount)
{
    int found = 0;
    int id;

    printf("\nEnter the id of test\n");
    scanf("%d", &id);

    for (int i = 0; i < testcount; i++)
    {
        if (t[i].test_id == id)
        {
            printf("Test found:\n");
            printf("ID: %d, NAME: %s, PRICE: %.2f\n", t[i].test_id, t[i].test_name, t[i].test_price);
            found = 1;
        }
    }

    if (found == 0)
    {
        printf("\nTest with id %d not found!!!\n", id);
    }
}

void displayRecord_in(int testCount)
{
    printf("Total number of tests added in the inventory: %d\n", testCount);
}

void displayReport_in(test_inventory t[MAX_RECORD], int testCount)
{
    if (testCount == 0)
    {
        printf("\nNo test records available to display the report!\n");
        return;
    }

    float totalCost = 0;
    float maxPrice = t[0].test_price;
    float minPrice = t[0].test_price;
    char maxPriceTest[100];
    char minPriceTest[100];

    strcpy(maxPriceTest, t[0].test_name);
    strcpy(minPriceTest, t[0].test_name);

    for (int i = 0; i < testCount; i++)
    {
        totalCost += t[i].test_price;

        if (t[i].test_price > maxPrice)
        {
            maxPrice = t[i].test_price;
            strcpy(maxPriceTest, t[i].test_name);
        }

        if (t[i].test_price < minPrice)
        {
            minPrice = t[i].test_price;
            strcpy(minPriceTest, t[i].test_name);
        }
    }

    float avgCost = totalCost / testCount;

    printf("\n--- Test Inventory Report ---\n");

    printf("Total number of tests: %d\n", testCount);

    printf("Total costs of tests: %.2f Rs\n", totalCost);

    printf("Average test cost: %.2f Rs\n", avgCost);

    printf("Most expensive test: %s (%.2f Rs)\n", maxPriceTest, maxPrice);

    printf("Least expensive test: %s (%.2f Rs)\n", minPriceTest, minPrice);
}

// Employee Management Functions
void add_employee(employee emp[MAX_RECORD], int employeeCount)
{
    if (employeeCount >= MAX_RECORD)
    {
        printf("Cannot add more employees. Max limit reached.\n");
        return;
    }

    printf("\nEnter Employee ID:\n");
    scanf("%d", &emp[employeeCount].id);

    printf("Enter Employee Name:\n");
    scanf(" %[^\n]s", emp[employeeCount].name);

    printf("Enter Employee Phone number:\n");
    scanf(" %[^\n]s", emp[employeeCount].phone);

    printf("Enter Employee House Address:\n");
    scanf(" %[^\n]s", emp[employeeCount].address);

    printf("Enter Employee email:\n");
    scanf(" %[^\n]s", emp[employeeCount].email);

    printf("Enter Employee designation:\n");
    scanf(" %[^\n]s", emp[employeeCount].designation);

    printf("Enter Employee Salary:\n");
    scanf("%d", &emp[employeeCount].salary);

    printf("Enter for how many days employee was absent:\n");
    scanf("%d", &emp[employeeCount].days_off);

    printf("Employee added successfully!\n");
}

void update_employee(employee emp[MAX_RECORD], int employeeCount)
{
    int id;
    printf("\nEnter Employee ID to update: \n");
    scanf("%d", &id);

    for (int i = 0; i < employeeCount; i++)
    {
        if (emp[i].id == id)
        {
            int choice;
            do
            {
                printf("\nChoose attribute to update:\n");
                printf("1. Name\n");
                printf("2. Phone\n");
                printf("3. Address\n");
                printf("4. Designation\n");
                printf("5. Email\n");
                printf("6. Salary\n");
                printf("7. Days Off\n");
                printf("8. Update All\n");
                printf("9. Exit\n");
                printf("Enter your choice: ");
                scanf("%d", &choice);

                switch (choice)
                {
                case 1:
                    printf("Enter new name:\n");
                    scanf(" %[^\n]s", emp[i].name);
                    break;
                case 2:
                    printf("Enter new phone:\n");
                    scanf(" %[^\n]s", emp[i].phone);
                    break;
                case 3:
                    printf("Enter new address:\n");
                    scanf(" %[^\n]s", emp[i].address);
                    break;
                case 4:
                    printf("Enter new designation:\n");
                    scanf(" %[^\n]s", emp[i].designation);
                    break;
                case 5:
                    printf("Enter new email:\n");
                    scanf(" %[^\n]s", emp[i].email);
                    break;
                case 6:
                    printf("Enter Employee Salary:\n");
                    scanf("%d", &emp[i].salary);
                    break;
                case 7:
                    printf("Enter for how many days employee was absent:\n");
                    scanf("%d", &emp[i].days_off);
                    break;
                case 8:
                    printf("Enter new name:\n");
                    scanf(" %[^\n]s", emp[i].name);
                    printf("Enter new phone:\n");
                    scanf(" %[^\n]s", emp[i].phone);
                    printf("Enter new address:\n");
                    scanf(" %[^\n]s", emp[i].address);
                    printf("Enter new designation:\n");
                    scanf(" %[^\n]s", emp[i].designation);
                    printf("Enter new email:\n");
                    scanf(" %[^\n]s", emp[i].email);
                    printf("Enter Employee Salary:\n");
                    scanf("%d", &emp[i].salary);
                    printf("Enter for how many days employee was absent:\n");
                    scanf("%d", &emp[i].days_off);
                    break;
                case 9:
                    printf("Exiting update menu.\n");
                    break;
                default:
                    printf("Invalid choice, please try again.\n");
                }
            } while (choice != 9);

            printf("Employee updated successfully!\n");
            return;
        }
    }
    printf("\nEmployee ID not found!\n");
}

int delete_employee(employee emp[MAX_RECORD], int employeeCount)
{
    int id, found = -1;
    printf("\nEnter the Employee ID to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < employeeCount; i++)
    {
        if (emp[i].id == id)
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
        for (int j = found; j < employeeCount - 1; j++)
        {
            emp[j] = emp[j + 1];
        }

        printf("Employee deleted successfully!\n");
        return 1;
    }
}

void display_employee(employee emp[MAX_RECORD], int employeeCount)
{
    if (employeeCount == 0)
    {
        printf("\nNo employees available!\n");
        return;
    }

    for (int i = 0; i < employeeCount; i++)
    {
        printf("\nEmployee %d : \n", i + 1);
        printf("ID: %d\nNAME: %s\nPHONE: %s\nADDRESS: %s\nEMAIL: %s\nDESIGNATION: %s\nSALARY: %d\nAbsents: %d\n", emp[i].id,
               emp[i].name, emp[i].phone, emp[i].address, emp[i].email, emp[i].designation,
               emp[i].salary, emp[i].days_off);
    }
}

void search_employee(employee emp[MAX_RECORD], int employeeCount)
{
    int choice;
    do
    {
        printf("\n*SEARCH EMPLOYEE*\n");
        printf("1.SEARCH Employee BY NAME\n");
        printf("2.SEARCH EMPLOYEE By ID\n");
        printf("3.EXIT\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            search_employee_name(emp, employeeCount);
            break;

        case 2:
            search_employee_id(emp, employeeCount);
            break;

        case 3:
            break;

        default:
            printf("\nInvalid input\n");
            break;
        }
    } while (choice != 3);
}

void search_employee_name(employee emp[MAX_RECORD], int employeeCount)
{
    int found = 0;
    char name[100];

    printf("\nEnter the name of Employee\n");
    scanf(" %[^\n]", name);

    for (int i = 0; i < employeeCount; i++)
    {
        if (stricmp(emp[i].name, name) == 0)
        {
            printf("Employee found:\n");
            printf("ID: %d\nNAME: %s\nPHONE: %s\nADDRESS: %s\nEMAIL: %s\nDESIGNATION: %s\nSALARY: %d\nAbsents: %d\n", emp[i].id,
                   emp[i].name, emp[i].phone, emp[i].address, emp[i].email, emp[i].designation,
                   emp[i].salary, emp[i].days_off);

            found = 1;
            break;
        }
    }

    if (found == 0)
    {
        printf("Employee  with name %s not found!!!\n", name);
    }
}

void search_employee_id(employee emp[MAX_RECORD], int employeeCount)
{
    int found = 0;
    int id;

    printf("\nEnter employee id \n");
    scanf("%d", &id);

    for (int i = 0; i < employeeCount; i++)
    {
        if (emp[i].id == id)
        {
            printf("Employee found:\n");
            printf("ID: %d\nNAME: %s\nPHONE: %s\nADDRESS: %s\nEMAIL: %s\nDESIGNATION: %s\nSALARY: %d\nAbsents: %d\n", emp[i].id,
                   emp[i].name, emp[i].phone, emp[i].address, emp[i].email, emp[i].designation,
                   emp[i].salary, emp[i].days_off);

            found = 1;
            break;
        }
    }

    if (found == 0)
    {
        printf("\nEmployee with id %d not found!!!\n", id);
    }
}

void displayRecord_e(int employeeCount)
{
    printf("Total Record Added: %d\n", employeeCount);
}

void displayReport_e(employee emp[MAX_RECORD], int employeeCount)
{
    if (employeeCount == 0)
    {
        printf("No employee records available!\n");
        return;
    }

    int totalSalary = 0;
    for (int i = 0; i < employeeCount; i++)
    {
        totalSalary += emp[i].salary;
    }
    double averageSalary = (double)totalSalary / employeeCount;

    printf("\n--- Employee Report ---\n");
    printf("Total number of employees: %d\n", employeeCount);
    printf("Average salary: %.2f\n", averageSalary);

    int index = 0;
    int index1 = 0;
    int found = 0;
    int max = emp[0].salary;
    int min = emp[0].salary;

    for (int i = 1; i < employeeCount; i++)
    {
        if (emp[i].salary > max)
        {
            max = emp[i].salary;
            index = i;
        }
        if (emp[i].salary < min)
        {
            min = emp[i].salary;
            index1 = i;
        }
    }
    printf("\nEmployee with maximum salary is:\n");
    printf("ID: %d\nNAME: %s\nPHONE: %s\nADDRESS: %s\nEMAIL: %s\nDESIGNATION: %s\nSALARY: %d\nAbsents: %d\n", emp[index].id, emp[index].name, emp[index].phone, emp[index].address, emp[index].email, emp[index].designation, emp[index].salary, emp[index].days_off);
    printf("\nEmployee with minimum salary is:\n");
    printf("ID: %d\n NAME: %s\n PHONE: %s\n ADDRESS: %s\n EMAIL: %s\n DESIGNATION: %s\n SALARY: %d\nAbsents: %d\n", emp[index1].id, emp[index1].name, emp[index1].phone, emp[index1].address, emp[index1].email, emp[index1].designation, emp[index1].salary, emp[index1].days_off);

    printf("\nEmployees who cannot apply for a leave (more than or equal to 6 days off):\n");
    for (int i = 0; i < employeeCount; i++)
    {
        if (emp[i].days_off >= 6)
        {
            printf("NAME: %s\nID: %d\n", emp[i].name, emp[i].id);
            found = 1;
        }
    }

    if (!found)
    {
        printf("No employees exceed the leave limit.\n");
    }
}

// Patient Management Functions
void add_patient(patient pat[MAX_RECORD], int patientCount)
{
    if (patientCount >= MAX_RECORD)
    {
        printf("Cannot add more patients. Max limit reached.\n");
        return;
    }

    printf("\nEnter Patient Invoice number:\n");
    scanf("%d", &pat[patientCount].invoice_number);

    printf("Enter Patient Name:\n");
    scanf(" %[^\n]s", pat[patientCount].name);

    printf("Enter Patient Phone number:\n");
    scanf(" %[^\n]s", pat[patientCount].phone);

    printf("Enter Patient email:\n");
    scanf(" %[^\n]s", pat[patientCount].email);

    printf("Enter Patient Address:\n");
    scanf(" %[^\n]s", pat[patientCount].address);

    printf("Enter Patient Blood group:\n");
    scanf(" %[^\n]s", pat[patientCount].blood_type);

    printf("Enter the test Patient wants:\n");
    scanf(" %[^\n]s", &pat[patientCount].test);

    printf("Enter the Patient payment status '1' for payed '0' for due payments:\n");
    scanf("%d", &pat[patientCount].payment);

    printf("Patient added successfully!\n");
}

void update_patient(patient pat[MAX_RECORD], int patientCount)
{
    int invoice;
    printf("\nEnter Patient invoice to update: \n");
    scanf("%d", &invoice);

    for (int i = 0; i < patientCount; i++)
    {
        if (pat[i].invoice_number == invoice)
        {
            int choice;
            do
            {
                printf("\nChoose attribute to update:\n");
                printf("1. Name\n");
                printf("2. Phone number\n");
                printf("3. Email\n");
                printf("4. Address\n");
                printf("5. Blood group\n");
                printf("6. Test\n");
                printf("7. Update Payment status\n");
                printf("8. Update all\n");
                printf("9. Exit\n");
                printf("Enter your choice:\n ");
                scanf("%d", &choice);

                switch (choice)
                {
                case 1:
                    printf("Enter Patient new Name:\n");
                    scanf(" %[^\n]s", pat[i].name);
                    break;
                case 2:
                    printf("Enter Patient new Phone number:\n");
                    scanf(" %[^\n]s", pat[i].phone);
                    break;
                case 3:
                    printf("Enter Patient new Email:\n");
                    scanf(" %[^\n]s", pat[i].email);
                    break;
                case 4:
                    printf("Enter Patient new Address:\n");
                    scanf(" %[^\n]s", pat[i].address);
                    break;
                case 5:
                    printf("Enter Patient new Blood group:\n");
                    scanf(" %[^\n]s", pat[i].blood_type);
                    break;
                case 6:
                    printf("Enter the test Patient wants:\n");
                    scanf(" %[^\n]s", &pat[i].test);
                    break;
                case 7:
                    printf("Enter the Patient payment status '1' for payed '0' for due payments:\n");
                    scanf("%d", &pat[i].payment);
                    break;
                case 8:
                    printf("Enter Patient new Name:\n");
                    scanf(" %[^\n]s", pat[i].name);
                    printf("Enter Patient new Phone number:\n");
                    scanf(" %[^\n]s", pat[i].phone);
                    printf("Enter Patient new Email:\n");
                    scanf(" %[^\n]s", pat[i].email);
                    printf("Enter Patient new Address:\n");
                    scanf(" %[^\n]s", pat[i].address);
                    printf("Enter Patient new Blood group:\n");
                    scanf(" %[^\n]s", pat[i].blood_type);
                    printf("Enter the test Patient wants:\n");
                    scanf(" %[^\n]s", &pat[i].test);
                    printf("Enter the Patient payment status '1' for payed '0' for due payments:\n");
                    scanf("%d", &pat[i].payment);
                    break;
                case 9:
                    printf("Exiting update menu.\n");
                    break;
                default:
                    printf("Invalid choice, please try again.\n");
                }
            } while (choice != 9);

            printf("Patient updated successfully!\n");
            return;
        }
    }
    printf("\nInvoice Number not found!\n");
}

int delete_patient(patient pat[MAX_RECORD], int patientCount)
{
    int invoice, found = -1;
    printf("\nEnter the Patients Invoice number to delete: ");
    scanf("%d", &invoice);

    for (int i = 0; i < patientCount; i++)
    {
        if (pat[i].invoice_number == invoice)
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
        for (int j = found; j < patientCount - 1; j++)
        {
            pat[j] = pat[j + 1];
        }
        printf("Patient deleted successfully!\n");
        return 1;
    }
}

void display_patient(patient pat[MAX_RECORD], int patientCount)
{
    if (patientCount == 0)
    {
        printf("\nNo Invoices available!\n");
        return;
    }

    for (int i = 0; i < patientCount; i++)
    {
        printf("\nPatient %d : \n", i + 1);
        printf("Invoice Number: %d\nNAME: %s\nPHONE: %s\nEMAIL: %s\nADDRESS: %s\nBLOOD GROUP: %s\nTEST NAME: %s\nPayment Status:%d\n",
               pat[i].invoice_number, pat[i].name, pat[i].phone,
               pat[i].email, pat[i].address, pat[i].blood_type,
               pat[i].test, pat[i].payment);
    }
}

void search_patient(patient pat[MAX_RECORD], int patientCount)
{
    int choice;
    do
    {
        printf("\n*Search Patient*\n");
        printf("1. Search Patient By NAME\n");
        printf("2. SEARCH Patient By ID\n");
        printf("3. EXIT\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            search_patient_name(pat, patientCount);
            break;

        case 2:
            search_patient_id(pat, patientCount);
            break;

        case 3:
            break;

        default:
            printf("\nInvalid input\n");
            break;
        }
    } while (choice != 3);
}

void search_patient_name(patient pat[MAX_RECORD], int patientCount)
{
    char name[100];
    int found = 0;
    printf("\nEnter the name of the Patient to search: ");
    scanf(" %[^\n]s", name);

    for (int i = 0; i < patientCount; i++)
    {
        if (stricmp(pat[i].name, name) == 0)
        {
            printf("Patient found:\n");
            printf("Invoice Number: %d\nNAME: %s\nPHONE: %s\nEMAIL: %s\nADDRESS: %s\nBLOOD GROUP: %s\nTEST NAME: %s\nPayment Status:%d\n",
                   pat[i].invoice_number, pat[i].name, pat[i].phone,
                   pat[i].email, pat[i].address, pat[i].blood_type,
                   pat[i].test, pat[i].payment);
            found = 1;
            break;
        }
    }

    if (found == 0)
    {
        printf("Patient with name '%s' not found.\n", name);
    }
}

void search_patient_id(patient pat[MAX_RECORD], int patientCount)
{
    int id;
    printf("\nEnter the Invoice number of the Patient to search: ");
    scanf("%d", &id);

    int found = 0;
    for (int i = 0; i < patientCount; i++)
    {
        if (pat[i].invoice_number == id)
        {
            printf("Patient found:\n");
            printf("Invoice Number: %d\nNAME: %s\nPHONE: %s\nEMAIL: %s\nADDRESS: %s\nBLOOD GROUP: %s\nTEST NAME: %s\nPayment Status:%d\n",
                   pat[i].invoice_number, pat[i].name, pat[i].phone,
                   pat[i].email, pat[i].address, pat[i].blood_type,
                   pat[i].test, pat[i].payment);
            found = 1;
            break;
        }
    }

    if (found == 0)
    {
        printf("Patient with Invoice Number '%d' not found.\n", id);
    }
}

void displayRecord_p(int patientCount)
{
    printf("Total Record Added: %d\n", patientCount);
}

void displayReport_p(patient pat[MAX_RECORD], int patientCount)
{
    if (patientCount == 0)
    {
        printf("\nNo patient records available to display the report!\n");
        return;
    }

    printf("\n--- Patient Report ---\n");
    printf("Total number of invoices: %d\n", patientCount);

    printf("\nPatients with dues:\n");
    int payCount = 0;
    for (int i = 0; i < patientCount; i++)
    {
        if (pat[i].payment == 0)
        {
            printf("Invoice Number: %d, Name: %s\n", pat[i].invoice_number, pat[i].name);
            payCount++;
        }
    }
    if (payCount == 0)
    {
        printf("All patients have payed their dues.\n");
    }
}

// Medical Report functions
int add_medical_report(medical_report med[MAX_RECORD], int medicalCount, patient pat[MAX_RECORD], test_inventory t[MAX_RECORD], int patientCount, int testCount)
{
    if (medicalCount >= MAX_RECORD)
    {
        printf("Cannot add more patients. Max limit reached.\n");
        return 0;
    }
    char patientName[100], testName[100];

    printf("Enter report id:\n");
    scanf("%d", &med[medicalCount].report_id);

    printf("Enter patient name :\n");
    scanf(" %[^\n]s", patientName);

    int found = 0;
    for (int i = 0; i < patientCount; i++)
    {
        if (stricmp(pat[i].name, patientName) == 0)
        {
            found = 1;
            break;
        }
    }
    if (found == 0)
    {
        printf("Patient not fount!!\n");
        return 0;
    }

    printf("Enter test name:\n");
    scanf(" %[^\n]s", testName);

    int found1 = 0;
    for (int i = 0; i < testCount; i++)
    {
        if (stricmp(t[i].test_name, testName) == 0)
        {
            found1 = 1;
            break;
        }
    }
    if (found1 == 0)
    {
        printf("Test not found!!\n");
        return 0;
    }

    strcpy(med[medicalCount].test_name, testName);
    strcpy(med[medicalCount].patient_name, patientName);

    printf("Enter report date (DD-MM-YYYY): \n");
    scanf(" %[^\n]s", med[medicalCount].report_date);

    printf("Enter report status (Pending = 0 or Ready = 1):\n");
    scanf(" %d", &med[medicalCount].report_status);

    printf("%d\n", medicalCount);
    printf("Medical Report added successfully!\n");
    return 1;
}

void update_medical_report(medical_report med[MAX_RECORD], int medicalCount, patient pat[MAX_RECORD], test_inventory t[MAX_RECORD], int patientCount, int testCount)
{
    int id;
    printf("\nEnter Report ID to update: \n");
    scanf("%d", &id);

    for (int i = 0; i < medicalCount; i++)
    {
        if (med[i].report_id == id)
        {
            int choice;
            do
            {
                printf("\nChoose attribute to update:\n");
                printf("1. Patient Name\n");
                printf("2. Test Name\n");
                printf("3. Report date\n");
                printf("4. Report status\n");
                printf("5. Update All\n");
                printf("6. Exit\n");
                printf("Enter your choice:\n ");
                scanf("%d", &choice);

                char patientName[100];
                char testName[100];
                int patientExists;
                int testExist;

                switch (choice)
                {
                case 1:
                    printf("Enter New patient name :\n");
                    scanf(" %[^\n]s", patientName);

                    patientExists = 0;
                    for (int i = 0; i < patientCount; i++)
                    {
                        if (stricmp(pat[i].name, patientName) == 0)
                        {
                            patientExists = 1;
                            break;
                        }
                    }

                    if (patientExists == 0)
                    {
                        printf("Patient not fount!!\n");
                        return;
                    }
                    strcpy(med[i].patient_name, patientName);
                    break;

                case 2:
                    printf("Enter New test name:\n");
                    scanf(" %[^\n]s", testName);

                    testExist = 0;
                    for (int i = 0; i < testCount; i++)
                    {
                        if (stricmp(t[i].test_name, testName) == 0)
                        {
                            testExist = 1;
                            break;
                        }
                    }

                    if (testExist == 0)
                    {
                        printf("Test not found!!\n");
                        return;
                    }

                    strcpy(med[i].test_name, testName);
                    break;

                case 3:
                    printf("Enter New Report Date(DD-MM-YYYY): \n");
                    scanf(" %[^\n]s", med[i].report_date);
                    break;

                case 4:
                    printf("Enter New Report Status (Pending = 0 or Ready = 1):\n");
                    scanf(" %d", &med[i].report_status);
                    break;

                case 5:
                    printf("Enter New patient name :\n");
                    scanf(" %[^\n]s", patientName);

                    patientExists = 0;
                    for (int i = 0; i < patientCount; i++)
                    {
                        if (stricmp(pat[i].name, patientName) == 0)
                        {
                            patientExists = 1;
                            break;
                        }
                    }

                    if (patientExists == 0)
                    {
                        printf("Patient not fount!!\n");
                        return;
                    }
                    strcpy(med[i].patient_name, patientName);

                    printf("Enter New test name:\n");
                    scanf(" %[^\n]s", testName);

                    testExist = 0;
                    for (int i = 0; i < testCount; i++)
                    {
                        if (stricmp(t[i].test_name, testName) == 0)
                        {
                            testExist = 1;
                            break;
                        }
                    }

                    if (testExist == 0)
                    {
                        printf("Test not found!!\n");
                        return;
                    }

                    strcpy(med[i].test_name, testName);

                    printf("Enter New Report Date(DD-MM-YYYY): \n");
                    scanf(" %[^\n]s", med[i].report_date);

                    printf("Enter New Report Status (Pending = 0 or Ready = 1):\n");
                    scanf(" %d", &med[i].report_status);
                    break;

                case 6:
                    printf("Exiting update menu.\n");
                    break;

                default:
                    printf("Invalid choice, please try again.\n");
                }
            } while (choice != 6);

            printf("Report updated successfully!\n");
            return;
        }
    }
    printf("\nReport ID Number not found!\n");
}

int delete_medical_report(medical_report med[MAX_RECORD], int medicalCount)
{
    int id, found = -1;
    printf("\nEnter the Report ID to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < medicalCount; i++)
    {
        if (med[i].report_id == id)
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
        for (int j = found; j < medicalCount - 1; j++)
        {
            med[j] = med[j + 1];
        }

        printf("Report deleted successfully!\n");
        return 1;
    }
}

void display_medical_reports(medical_report med[MAX_RECORD], int medicalCount)
{
    if (medicalCount == 0)
    {
        printf("\nNo Medical reports are available!\n");
        return;
    }

    for (int i = 0; i < medicalCount; i++)
    {
        printf("\nReport %d : \n", i + 1);
        printf("REPORT ID: %d\nPATIENT NAME: %s\nTEST NAME: %s\nREPORT DATE: %s\nREPORT STATUS: %d\n",
               med[i].report_id, med[i].patient_name, med[i].test_name,
               med[i].report_date, med[i].report_status);
    }
}

void search_medical_report(medical_report med[MAX_RECORD], int medicalCount)
{
    int choice;
    do
    {
        printf("\n*SEARCH MEDICAL REPORT*\n");
        printf("1.SEARCH MEDICAL REPORT WITH PATIENT NAME\n");
        printf("2.SEARCH MEDICAL REPORT WITH REPORT ID\n");
        printf("3.EXIT\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            search_medical_report_name(med, medicalCount);
            break;

        case 2:
            search_medical_report_id(med, medicalCount);
            break;

        case 3:
            break;

        default:
            printf("\nInvalid input\n");
            break;
        }
    } while (choice != 3);
}

void search_medical_report_name(medical_report med[MAX_RECORD], int medicalCount)
{
    char name[101];
    int found = 0;
    printf("\nEnter the name of the Patient to search Report: ");
    scanf(" %[^\n]s", name);

    for (int i = 0; i < medicalCount; i++)
    {
        if (stricmp(med[i].patient_name, name) == 0)
        {
            printf("Medical Report found:\n");
            printf("REPORT ID: %d\nPATIENT NAME: %s\nTEST NAME: %s\nREPORT DATE: %s\nREPORT STATUS: %d\n",
                   med[i].report_id, med[i].patient_name, med[i].test_name,
                   med[i].report_date, med[i].report_status);

            found = 1;
            break;
        }
    }

    if (found == 0)
    {
        printf("Medical Report with Patient name '%s' not found.\n", name);
    }
}

void search_medical_report_id(medical_report med[MAX_RECORD], int medicalCount)
{
    int id;
    printf("\nEnter the Report ID to search: ");
    scanf("%d", &id);

    int found = 0;

    for (int i = 0; i < medicalCount; i++)
    {
        if (med[i].report_id == id)
        {
            printf("Medical Report found:\n");
            printf("REPORT ID: %d\nPATIENT NAME: %s\nTEST NAME: %s\nREPORT DATE: %s\nREPORT STATUS: %d\n",
                   med[i].report_id, med[i].patient_name, med[i].test_name,
                   med[i].report_date, med[i].report_status);

            found = 1;
            break;
        }
    }

    if (found == 0)
    {
        printf("Medical Report with ID '%d' not found.\n", id);
    }
}

void displayRecord_m(int medicalCount)
{
    printf("Total Reports Added: %d\n", medicalCount);
}

void displayReport_m(medical_report med[MAX_RECORD], int medicalCount, test_inventory t[MAX_RECORD])
{
    float total_test_revenue = 0;

    printf("------Medical Report------");
    if (medicalCount == 0)
    {
        printf("\nNo medical reports available!\n");
        return;
    }

    int found = 0;
    printf("\nMedical Reports (Status: Ready):\n");
    for (int i = 0; i < medicalCount; i++)
    {
        if (med[i].report_status == 1)
        {
            printf("\nReport %d:\n", i + 1);
            printf("REPORT ID: %d\nPATIENT NAME: %s\nTEST NAME: %s\nREPORT DATE: %s\n",
                   med[i].report_id, med[i].patient_name, med[i].test_name, med[i].report_date);
            found = 1;
            total_test_revenue += t[i].test_price;
        }
    }

    if (!found)
    {
        printf("No reports with status 'Ready' found.\n");
    }
    printf("Total revenue from Tests: %.2f\n\n", total_test_revenue);
}