#include <stdio.h>
#include <stdlib.h>

typedef struct student
{
    int rollNo;
    char name[34];
    struct subject
    {
        int Smarks;
    } sub[3];
    int total;
    float per;
} student;

void addData()
{
    int n;
    student *s;
    
    FILE *fdata;

    printf("How many students you want to enter : ");
    scanf("%d", &n);

    s = (student *)calloc(n, sizeof(student));

    fdata = fopen("school-managment.txt", "w");

    for (int i = 0; i < n; i++)
    {
        s[i].total = 0;
        s[i].per = 0;

        printf("Enter the roll number : ");
        scanf("%d", &s[i].rollNo);
        fflush(stdin); // clear internal buffer

        printf("Enter the name of student : ");
        scanf(" %[^\n]s", s[i].name);

        for (int j = 0; j < 3; j++)
        {

            printf("Enter the marks of subject %d : ", j + 1);
            scanf("%d", &s[i].sub[j].Smarks);

            s[i].total += s[i].sub[j].Smarks;
        }
        s[i].per = s[i].total / 3.0;
        fwrite(&s[i], sizeof(student), 1, fdata);
    }
    fclose(fdata);
}

void displayData()
{
    printf("\n");
    int j;
    student s1;
    FILE *fdata;

    fdata = fopen("school-managment.txt", "r");

    printf("ROLL NO.     NAME                               SUBJECT 1           SUBJECT 2           SUBJECT 3         TOTAL           PERCENTAGE\n");

    while (fread(&s1, sizeof(student), 1, fdata))
    {
        printf("%-13d%-20s", s1.rollNo, s1.name);
        for (j = 0; j < 3; j++)
        {
            printf("%20d", s1.sub[j].Smarks);
        }
        printf("%17d%20.2f\n", s1.total, s1.per);
    }

    fclose(fdata);
}

void appendData()
{
    int n;
    student *s;

    FILE *fdata;

    printf("How many students you want to enter : ");
    scanf("%d", &n);

    s = (student *)calloc(n, sizeof(student));

    fdata = fopen("school-managment.txt", "a");

    for (int i = 0; i < n; i++)
    {
        s[i].total = 0;
        s[i].per = 0;

        printf("Enter the roll number : ");
        scanf("%d", &s[i].rollNo);
        fflush(stdin); // clear internal buffer

        printf("Enter the name of student : ");
        scanf("%[^\n]s", s[i].name);

        for (int j = 0; j < 3; j++)
        {

            printf("Enter the marks of subject %d : ", j + 1);
            scanf("%d", &s[i].sub[j].Smarks);

            s[i].total += s[i].sub[j].Smarks;
        }
        s[i].per = s[i].total / 3.0;
        fwrite(&s[i], sizeof(student), 1, fdata);
    }
    fclose(fdata);
}

void noOfRec()
{
    student s1;
    FILE *fdata;
    fdata = fopen("school-managment.txt", "r");
    fseek(fdata, 0, SEEK_END);
    int n = ftell(fdata) / sizeof(student);
    printf("\n\nNO OF RECORDS = %d", n);
    fclose(fdata);
}

void search()
{
    printf("\n");

    int j, rno;
    int found = 0;
    student s1;

    FILE *fdata;

    fdata = fopen("school-managment.txt", "r");

    printf("Enter roll no. you want to search\n");
    scanf("%d", &rno);

    while (fread(&s1, sizeof(student), 1, fdata))
    {
        if (s1.rollNo == rno)
        {
            found = 1;

            printf("ROLL NO.     NAME                               SUBJECT 1           SUBJECT 2           SUBJECT 3         TOTAL           PERCENTAGE\n");
            printf("%-13d%-20s", s1.rollNo, s1.name);

            for (j = 0; j < 3; j++)
            {
                printf("%20d", s1.sub[j].Smarks);
            }
            printf("%17d%20.2f\n", s1.total, s1.per);
        }
    }
    if (found = 0)
    {
        printf("\nRecord not found\n");
    }
    fclose(fdata);
}

void update()
{
    printf("\n");

    int j, rno;
    int found = 0;
    student s1;

    FILE *fdata, *ftemp;

    fdata = fopen("school-managment.txt", "r");
    ftemp = fopen("temp.txt", "w");

    printf("Enter roll no. you want to update\n");
    scanf("%d", &rno);

    while (fread(&s1, sizeof(student), 1, fdata))
    {
        if (s1.rollNo == rno)
        {
            found = 1;
            s1.total = 0;
            s1.per = 0;

            fflush(stdin);
            printf("Enter the name of student : ");
            scanf("%[^\n]s", s1.name);

            for (int j = 0; j < 3; j++)
            {

                printf("Enter the marks of subject %d : ", j + 1);
                scanf("%d", &s1.sub[j].Smarks);

                s1.total += s1.sub[j].Smarks;
            }
            s1.per = s1.total / 3.0;
        }
        fwrite(&s1, sizeof(student), 1, ftemp);
    }

    fclose(fdata);
    fclose(ftemp);

    if (found = 1)
    {
        ftemp = fopen("temp.txt", "r");
        fdata = fopen("school-managment.txt", "w");

        while (fread(&s1, sizeof(student), 1, ftemp))
        {
            fwrite(&s1, sizeof(student), 1, fdata);
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

    int j, rno;
    int found = 0;
    student s1;

    FILE *fdata, *ftemp;

    fdata = fopen("school-managment.txt", "r");
    ftemp = fopen("temp.txt", "w");

    printf("Enter roll no. you want to delete\n");
    scanf("%d", &rno);

    while (fread(&s1, sizeof(student), 1, fdata))
    {
        if (s1.rollNo == rno)
        {
            found = 1;
        }
        else
        {
            fwrite(&s1, sizeof(student), 1, ftemp);
        }
    }

    fclose(fdata);
    fclose(ftemp);

    if (found == 1)
    {
        ftemp = fopen("temp.txt", "r");
        fdata = fopen("school-managment.txt", "w");

        while (fread(&s1, sizeof(student), 1, ftemp))
        {
            fwrite(&s1, sizeof(student), 1, fdata);
        }

        fclose(fdata);
        fclose(ftemp);
    }
    else if (found == 0)
    {
        printf("\nRecord not found\n");
    }
}

int main()
{
    int choice;
    do
    {
        printf("\n\n1. CREAT");
        printf("\n2. DISPLAY");
        printf("\n3. APPEND");
        printf("\n4. NO. OF RECORDS");
        printf("\n5. SEARCH");
        printf("\n6. UPDATE");
        printf("\n7. DELETE");
        printf("\n0. EXITE");

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
            printf("\nExiting the programe........");
            break;

        default:
            printf("\nInvalid input!!!\n");
        }

    } while (choice != 0);

    return 0;
}