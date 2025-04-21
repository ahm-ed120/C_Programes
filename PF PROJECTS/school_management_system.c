#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure definitions
struct Date
{
    int day;
    int month;
    int year;
};

struct Student
{
    int id;
    char name[50];
    struct Date dob;
    char address[100];
    float fees_paid;
};

struct Teacher
{
    int id;
    char name[50];
    char subject[50];
    float salary;
};

struct Worker
{
    int id;
    char name[50];
    char department[50];
    float salary;
};

struct Fee
{
    int student_id;
    float total_fees;
};

// Function prototypes
void addStudent(struct Student students[], int studentCount);
void updateStudent(struct Student students[], int studentCount);
int deleteStudent(struct Student students[], int studentCount);
void displayStudents(struct Student students[], int studentCount);
void searchStudentById(struct Student students[], int studentCount, int id);

void addTeacher(struct Teacher teachers[], int teacherCount);
void updateTeacher(struct Teacher teachers[], int teacherCount);
int deleteTeacher(struct Teacher teachers[], int teacherCount);
void displayTeachers(struct Teacher teachers[], int teacherCount);
void searchTeacherById(struct Teacher teachers[], int teacherCount, int id);

void addWorker(struct Worker workers[], int workerCount);
void updateWorker(struct Worker workers[], int workerCount);
int deleteWorker(struct Worker workers[], int workerCount);
void displayWorkers(struct Worker workers[], int workerCount);
void searchWorkerById(struct Worker workers[], int workerCount, int id);

void addFee(struct Fee fees[], int feeCount, struct Student students[], int studentCount);
void updateFee(struct Fee fees[], int feeCount, struct Student students[], int studentCount);
int deleteFee(struct Fee fees[], int feeCount, struct Student students[], int studentCount);
void displayFees(struct Fee fees[], int feeCount, struct Student students[], int studentCount);
void searchFeeByStudentId(struct Fee fees[], int feeCount, struct Student students[], int studentCount, int studentId);

int main()
{
    struct Student students[100];
    struct Teacher teachers[50];
    struct Worker workers[50];
    struct Fee fees[100];

    int studentCount = 0;
    int teacherCount = 0;
    int workerCount = 0;
    int feeCount = 0;

    int choice, choice1, choice2, choice3, choice4, choice5, choice6;
    int w, x, y, z;

    FILE *fstudent1 = fopen("student.txt", "r");

    fscanf(fstudent1, "%d\n", &studentCount);

    for (int i = 0; i < studentCount; i++)
    {
        fscanf(fstudent1, "%d;%50[^;];%d;%d;%d;%100[^;];%f\n", &students[i].id, students[i].name, &students[i].dob.day, &students[i].dob.month, &students[i].dob.year, students[i].address, &students[i].fees_paid);
    }

    fclose(fstudent1);

    FILE *fteacher1 = fopen("teacher.txt", "r");

    fscanf(fteacher1, "%d\n", &teacherCount);

    for (int i = 0; i < teacherCount; i++)
    {
        fscanf(fteacher1, "%d;%50[^;];%50[^;];%f", &teachers[i].id, teachers[i].name, teachers[i].subject, &teachers[i].salary);
    }

    fclose(fteacher1);

    FILE *fworker1 = fopen("worker.txt", "r");

    fscanf(fworker1, "%d\n", &workerCount);

    for (int i = 0; i < workerCount; i++)
    {
        fscanf(fworker1, "%d;%50[^;];%50[^;];%f", &workers[i].id, workers[i].name, workers[i].department, &workers[i].salary);
    }

    fclose(fworker1);

    FILE *ffee1 = fopen("fee.txt", "r");

    fscanf(ffee1, "%d\n", &feeCount);

    for (int i = 0; i < feeCount; i++)
    {
        fscanf(ffee1, "%d;%f", &fees[i].student_id, &fees[i].total_fees);
    }

    fclose(ffee1);

    do
    {
        printf("\nMain Menu\n");
        printf("1. Manage Data\n");
        printf("2. Search\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            do
            {
                printf("\nManage Data:\n");
                printf("1. Student\n");
                printf("2. Teacher\n");
                printf("3. Worker\n");
                printf("4. Fees\n");
                printf("0. Exit\n");
                printf("Enter your choice: ");
                scanf("%d", &choice1);
                switch (choice1)
                {
                case 1:
                    do
                    {
                        printf("\nStudent Management:\n");
                        printf("1. Add Student\n");
                        printf("2. Update Student\n");
                        printf("3. Delete Student\n");
                        printf("4. Display Students\n");
                        printf("0. Exit\n");
                        printf("Enter your choice: ");
                        scanf("%d", &choice2);
                        switch (choice2)
                        {
                        case 1:
                            addStudent(students, studentCount);
                            studentCount++;
                            break;
                        case 2:
                            updateStudent(students, studentCount);
                            break;
                        case 3:
                            w = deleteStudent(students, studentCount);
                            if (w == 1)
                                ;
                            {
                                studentCount--;
                            }

                            break;
                        case 4:
                            displayStudents(students, studentCount);
                            break;
                        default:
                            printf("Invalid choice.\n");
                            break;
                        }

                        FILE *fstudent = fopen("student.txt", "w");

                        fprintf(fstudent, "%d\n", studentCount);

                        for (int i = 0; i < studentCount; i++)
                        {
                            fprintf(fstudent, "%d;%s;%d;%d;%d;%s;%f\n", students[i].id, students[i].name, students[i].dob.day, students[i].dob.month, students[i].dob.year, students[i].address, students[i].fees_paid);
                        }

                        fclose(fstudent);
                    } while (choice2 != 0);
                    break;

                case 2:
                    do
                    {
                        printf("\nTeacher Management:\n");
                        printf("1. Add Teacher\n");
                        printf("2. Update Teacher\n");
                        printf("3. Delete Teacher\n");
                        printf("4. Display Teachers\n");
                        printf("Enter your choice: ");
                        scanf("%d", &choice3);
                        switch (choice3)
                        {
                        case 1:
                            addTeacher(teachers, teacherCount);
                            teacherCount++;
                            break;
                        case 2:
                            updateTeacher(teachers, teacherCount);
                            break;
                        case 3:
                            x = deleteTeacher(teachers, teacherCount);
                            if (x == 1)
                            {
                                teacherCount--;
                            }
                            break;

                        case 4:
                            displayTeachers(teachers, teacherCount);

                        default:
                            printf("Invalid choice.\n");
                            break;
                        }

                        FILE *fteacher = fopen("teacher.txt", "w");

                        fprintf(fteacher, "%d\n", teacherCount);

                        for (int i = 0; i < teacherCount; i++)
                        {
                            fprintf(fteacher, "%d;%s;%s;%f", teachers[i].id, teachers[i].name, teachers[i].subject, teachers[i].salary);
                        }

                        fclose(fteacher);
                    } while (choice3 != 0);
                    break;
                case 3:
                    do
                    {
                        printf("\nWorker Management:\n");
                        printf("1. Add Worker\n");
                        printf("2. Update Worker\n");
                        printf("3. Delete Worker\n");
                        printf("4. Display Workers\n");
                        printf("0. Exit\n");
                        printf("Enter your choice: ");
                        scanf("%d", &choice4);
                        switch (choice4)
                        {
                        case 1:
                            addWorker(workers, workerCount);
                            workerCount++;
                            break;
                        case 2:
                            updateWorker(workers, workerCount);
                            break;
                        case 3:
                            y = deleteWorker(workers, workerCount);
                            if (y == 1)
                            {
                                workerCount--;
                            }
                            break;
                        case 4:
                            displayWorkers(workers, workerCount);
                            break;
                        default:
                            printf("Invalid choice.\n");
                            break;
                        }

                        FILE *fworker = fopen("worker.txt", "w");

                        fprintf(fworker, "%d\n", workerCount);

                        for (int i = 0; i < workerCount; i++)
                        {
                            fprintf(fworker, "%d;%s;%s;%f", workers[i].id, workers[i].name, workers[i].department, workers[i].salary);
                        }

                        fclose(fworker);
                    } while (choice4 != 0);
                    break;

                case 4:
                    do
                    {
                        printf("\nFees Management:\n");
                        printf("1. Add Fee\n");
                        printf("2. Update Fee\n");
                        printf("3. Delete Fee\n");
                        printf("4. Display Fees\n");
                        printf("4. Exit\n");
                        printf("Enter your choice: ");
                        scanf("%d", &choice5);
                        switch (choice5)
                        {
                        case 1:
                            addFee(fees, feeCount, students, studentCount);
                            feeCount++;
                            break;
                        case 2:
                            updateFee(fees, feeCount, students, studentCount);
                            break;
                        case 3:
                            z = deleteFee(fees, feeCount, students, studentCount);
                            if (z == 1)
                            {
                                feeCount--;
                            }
                            break;
                        case 4:
                            displayFees(fees, feeCount, students, studentCount);
                            break;
                        default:
                            printf("Invalid choice.\n");
                            break;
                        }

                        FILE *ffee = fopen("fee.txt", "w");

                        fprintf(ffee, "%d\n", feeCount);

                        for (int i = 0; i < feeCount; i++)
                        {
                            fprintf(ffee, "%d;%f", fees[i].student_id, fees[i].total_fees);
                        }

                        fclose(ffee);
                    } while (choice5 != 0);
                    break;
                default:
                    printf("Invalid choice.\n");
                    break;
                }
            } while (choice1 != 0);

            break;

        case 2:
            do
            {
                printf("\nSearch Menu:\n");
                printf("1. Search Student by ID\n");
                printf("2. Search Teacher by ID\n");
                printf("3. Search Worker by ID\n");
                printf("4. Search Fee by Student ID\n");
                printf("Enter your choice: ");
                scanf("%d", &choice6);
                switch (choice6)
                {
                case 1:
                    if (studentCount > 0)
                    {
                        int studentId;
                        printf("Enter student ID to search: ");
                        scanf("%d", &studentId);
                        searchStudentById(students, studentCount, studentId);
                    }
                    else
                    {
                        printf("No students to search.\n");
                    }
                    break;
                case 2:
                    if (teacherCount > 0)
                    {
                        int teacherId;
                        printf("Enter teacher ID to search: ");
                        scanf("%d", &teacherId);
                        searchTeacherById(teachers, teacherCount, teacherId);
                    }
                    else
                    {
                        printf("No teachers to search.\n");
                    }
                    break;
                case 3:
                    if (workerCount > 0)
                    {
                        int workerId;
                        printf("Enter worker ID to search: ");
                        scanf("%d", &workerId);
                        searchWorkerById(workers, workerCount, workerId);
                    }
                    else
                    {
                        printf("No workers to search.\n");
                    }

                    break;
                case 4:
                    if (feeCount > 0)
                    {
                        int studentId;
                        printf("Enter student ID to search fees: ");
                        scanf("%d", &studentId);
                        searchFeeByStudentId(fees, feeCount, students, studentCount, studentId);
                    }
                    else
                    {
                        printf("No fee records to search.\n");
                    }
                    break;
                default:
                    printf("Invalid choice.\n");
                    break;
                }
            } while (choice6 != 0);
            break;
        case 0:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice.\n");
            break;
        }
    } while (choice != 0);

    return 0;
}

void addStudent(struct Student students[], int studentCount)
{
    printf("Enter student details:\n");
    printf("ID: ");
    scanf("%d", &students[studentCount].id);
    printf("Name: ");
    scanf(" %[^\n]s", students[studentCount].name);
    printf("Date of Birth (DD MM YYYY): ");
    scanf("%d %d %d", &students[studentCount].dob.day, &students[studentCount].dob.month, &students[studentCount].dob.year);
    printf("Address: ");
    scanf(" %[^\n]s", students[studentCount].address);
    printf("Fees Paid: ");
    scanf("%f", &students[studentCount].fees_paid);

    printf("Student added successfully.\n");
}

void updateStudent(struct Student students[], int studentCount)
{
    int id, found = 0;
    printf("Enter student ID to update: ");
    scanf("%d", &id);

    for (int i = 0; i < studentCount; ++i)
    {
        if (students[i].id == id)
        {
            printf("Enter new details:\n");
            printf("Name: ");
            scanf(" %[^\n]s", students[i].name);
            printf("Date of Birth (DD MM YYYY): ");
            scanf("%d %d %d", &students[i].dob.day, &students[i].dob.month, &students[i].dob.year);
            printf("Address: ");
            scanf(" %[^\n]s", students[i].address);
            printf("Fees Paid: ");
            scanf("%f", &students[i].fees_paid);
            found = 1;
            printf("Student details updated successfully.\n");
            break;
        }
    }

    if (!found)
    {
        printf("Student not found.\n");
    }
}

int deleteStudent(struct Student students[], int studentCount)
{
    int id, found = -1;
    printf("Enter student ID to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < studentCount; ++i)
    {
        if (students[i].id == id)
        {
            found = i;
            break;
        }
    }

    if (found == -1)
    {
        printf("Student not found.\n");
        return 0;
    }

    else
    {
        for (int j = found; j < studentCount - 1; ++j)
        {
            students[j] = students[j + 1];
        }
        printf("Student deleted successfully.\n");
        return 1;
    }
}

void displayStudents(struct Student students[], int studentCount)
{
    printf("\nStudent Details:\n");
    for (int i = 0; i < studentCount; ++i)
    {
        printf("ID: %d\n", students[i].id);
        printf("Name: %s\n", students[i].name);
        printf("Date of Birth: %d-%d-%d\n", students[i].dob.day, students[i].dob.month, students[i].dob.year);
        printf("Address: %s\n", students[i].address);
        printf("Fees Paid: %.2f\n", students[i].fees_paid);
        printf("\n");
    }
}

void searchStudentById(struct Student students[], int studentCount, int id)
{
    int found = 0;
    for (int i = 0; i < studentCount; ++i)
    {
        if (students[i].id == id)
        {
            printf("\nStudent Found:\n");
            printf("ID: %d\n", students[i].id);
            printf("Name: %s\n", students[i].name);
            printf("Date of Birth: %d-%d-%d\n", students[i].dob.day, students[i].dob.month, students[i].dob.year);
            printf("Address: %s\n", students[i].address);
            printf("Fees Paid: %.2f\n", students[i].fees_paid);
            found = 1;
            break;
        }
    }
    if (!found)
    {
        printf("Student with ID %d not found.\n", id);
    }
}

void addTeacher(struct Teacher teachers[], int teacherCount)
{
    printf("Enter teacher details:\n");
    printf("ID: ");
    scanf("%d", &teachers[teacherCount].id);
    printf("Name: ");
    scanf(" %[^\n]s", teachers[teacherCount].name);
    printf("Subject: ");
    scanf(" %[^\n]s", teachers[teacherCount].subject);
    printf("Salary: ");
    scanf("%f", &teachers[teacherCount].salary);

    printf("Teacher added successfully.\n");
}

void updateTeacher(struct Teacher teachers[], int teacherCount)
{
    int id, found = 0;
    printf("Enter teacher ID to update: ");
    scanf("%d", &id);

    for (int i = 0; i < teacherCount; ++i)
    {
        if (teachers[i].id == id)
        {
            printf("Enter new details:\n");
            printf("Name: ");
            scanf(" %[^\n]s", teachers[i].name);
            printf("Subject: ");
            scanf(" %[^\n]s", teachers[i].subject);
            printf("Salary: ");
            scanf("%f", &teachers[i].salary);
            found = 1;
            printf("Teacher details updated successfully.\n");
            break;
        }
    }

    if (!found)
    {
        printf("Teacher not found.\n");
    }
}

int deleteTeacher(struct Teacher teachers[], int teacherCount)
{
    int id, found = -1;
    printf("Enter teacher ID to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < teacherCount; ++i)
    {
        if (teachers[i].id == id)
        {
            found = -1;
            break;
        }
    }
    if (found == -1)
    {
        printf("Teacher not found.\n");
        return 0;
    }
    else
    {
        for (int j = found; j < teacherCount - 1; ++j)
        {
            teachers[j] = teachers[j + 1];
        }

        printf("Teacher deleted successfully.\n");
        return 1;
    }
}

void displayTeachers(struct Teacher teachers[], int teacherCount)
{
    printf("\nTeacher Details:\n");
    for (int i = 0; i < teacherCount; ++i)
    {
        printf("ID: %d\n", teachers[i].id);
        printf("Name: %s\n", teachers[i].name);
        printf("Subject: %s\n", teachers[i].subject);
        printf("Salary: %.2f\n", teachers[i].salary);
        printf("\n");
    }
}

void searchTeacherById(struct Teacher teachers[], int teacherCount, int id)
{
    int found = 0;
    for (int i = 0; i < teacherCount; ++i)
    {
        if (teachers[i].id == id)
        {
            printf("\nTeacher Found:\n");
            printf("ID: %d\n", teachers[i].id);
            printf("Name: %s\n", teachers[i].name);
            printf("Subject: %s\n", teachers[i].subject);
            printf("Salary: %.2f\n", teachers[i].salary);
            found = 1;
            break;
        }
    }
    if (!found)
    {
        printf("Teacher with ID %d not found.\n", id);
    }
}

void addWorker(struct Worker workers[], int workerCount)
{
    printf("Enter worker details:\n");
    printf("ID: ");
    scanf("%d", &workers[workerCount].id);
    printf("Name: ");
    scanf(" %[^\n]s", workers[workerCount].name);
    printf("Department: ");
    scanf(" %[^\n]s", workers[workerCount].department);
    printf("Salary: ");
    scanf("%f", &workers[workerCount].salary);

    printf("Worker added successfully.\n");
}

void updateWorker(struct Worker workers[], int workerCount)
{
    int id, found = 0;
    printf("Enter worker ID to update: ");
    scanf("%d", &id);

    for (int i = 0; i < workerCount; ++i)
    {
        if (workers[i].id == id)
        {
            printf("Enter new details:\n");
            printf("Name: ");
            scanf(" %[^\n]s", workers[i].name);
            printf("Department: ");
            scanf(" %[^\n]s", workers[i].department);
            printf("Salary: ");
            scanf("%f", &workers[i].salary);
            found = 1;
            printf("Worker details updated successfully.\n");
            break;
        }
    }

    if (!found)
    {
        printf("Worker not found.\n");
    }
}

int deleteWorker(struct Worker workers[], int workerCount)
{
    int id, found = -1;
    printf("Enter worker ID to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < workerCount; ++i)
    {
        if (workers[i].id == id)
        {
            found = i;
            break;
        }
    }

    if (found == -1)
    {
        printf("Worker not found.\n");
        return 0;
    }

    else
    {
        for (int j = found; j < workerCount - 1; ++j)
        {
            workers[j] = workers[j + 1];
        }

        printf("Worker deleted successfully.\n");
        return 1;
    }
}

void displayWorkers(struct Worker workers[], int workerCount)
{
    printf("\nWorker Details:\n");
    for (int i = 0; i < workerCount; ++i)
    {
        printf("ID: %d\n", workers[i].id);
        printf("Name: %s\n", workers[i].name);
        printf("Department: %s\n", workers[i].department);
        printf("Salary: %.2f\n", workers[i].salary);
        printf("\n");
    }
}

void searchWorkerById(struct Worker workers[], int workerCount, int id)
{
    int found = 0;
    for (int i = 0; i < workerCount; ++i)
    {
        if (workers[i].id == id)
        {
            printf("\nWorker Found:\n");
            printf("ID: %d\n", workers[i].id);
            printf("Name: %s\n", workers[i].name);
            printf("Department: %s\n", workers[i].department);
            printf("Salary: %.2f\n", workers[i].salary);
            found = 1;
            break;
        }
    }
    if (!found)
    {
        printf("Worker with ID %d not found.\n", id);
    }
}

void addFee(struct Fee fees[], int feeCount, struct Student students[], int studentCount)
{
    if (studentCount == 0)
    {
        printf("No students available to add fees.\n");
        return;
    }

    printf("Enter fee details:\n");
    printf("Student ID: ");
    scanf("%d", &fees[feeCount].student_id);

    // Validate student ID
    int validStudent = 0;
    for (int i = 0; i < studentCount; ++i)
    {
        if (students[i].id == fees[feeCount].student_id)
        {
            validStudent = 1;
            break;
        }
    }

    if (!validStudent)
    {
        printf("Student with ID %d not found.\n", fees[feeCount].student_id);
        return;
    }

    printf("Total Fees: ");
    scanf("%f", &fees[feeCount].total_fees);

    printf("Fees added successfully.\n");
}

void updateFee(struct Fee fees[], int feeCount, struct Student students[], int studentCount)
{
    if (feeCount == 0)
    {
        printf("No fee records available to update.\n");
        return;
    }

    int studentId, found = 0;
    printf("Enter student ID to update fees: ");
    scanf("%d", &studentId);

    for (int i = 0; i < feeCount; ++i)
    {
        if (fees[i].student_id == studentId)
        {
            printf("Enter new total fees: ");
            scanf("%f", &fees[i].total_fees);
            found = 1;
            printf("Fees updated successfully.\n");
            break;
        }
    }

    if (!found)
    {
        printf("No fee record found for student ID %d.\n", studentId);
    }
}

int deleteFee(struct Fee fees[], int feeCount, struct Student students[], int studentCount)
{
    if (feeCount == 0)
    {
        printf("No fee records available to delete.\n");
        return 0;
    }

    int studentId, found = 0;
    printf("Enter student ID to delete fees: ");
    scanf("%d", &studentId);

    for (int i = 0; i < feeCount; ++i)
    {
        if (fees[i].student_id == studentId)
        {
            found = i;
            break;
        }
    }

    if (found == -1)
    {
        printf("No fee record found for student ID %d.\n", studentId);
        return 0;
    }

    else
    {

        for (int j = found; j < feeCount - 1; ++j)
        {
            fees[j] = fees[j + 1];
        }

        printf("Fees deleted successfully.\n");

        // Also update student's fees_paid to 0
        for (int k = 0; k < studentCount; ++k)
        {
            if (students[k].id == studentId)
            {
                students[k].fees_paid = 0;
                break;
            }
        }
        return 1;
    }
}

void displayFees(struct Fee fees[], int feeCount, struct Student students[], int studentCount)
{
    if (feeCount == 0)
    {
        printf("No fee records available to display.\n");
        return;
    }

    printf("\nFee Records:\n");
    for (int i = 0; i < feeCount; ++i)
    {
        for (int j = 0; j < studentCount; ++j)
        {
            if (fees[i].student_id == students[j].id)
            {
                printf("Student ID: %d, Name: %s, Total Fees: %.2f\n",
                       students[j].id, students[j].name, fees[i].total_fees);
                break;
            }
        }
    }
}

void searchFeeByStudentId(struct Fee fees[], int feeCount, struct Student students[], int studentCount, int studentId)
{
    int found = 0;
    for (int i = 0; i < feeCount; ++i)
    {
        if (fees[i].student_id == studentId)
        {
            for (int j = 0; j < studentCount; ++j)
            {
                if (students[j].id == studentId)
                {
                    printf("\nFee Record Found:\n");
                    printf("Student ID: %d\n", students[j].id);
                    printf("Student Name: %s\n", students[j].name);
                    printf("Total Fees: %.2f\n", fees[i].total_fees);
                    found = 1;
                    break;
                }
            }
        }
    }
    if (!found)
    {
        printf("Fee record for student with ID %d not found.\n", studentId);
    }
}
