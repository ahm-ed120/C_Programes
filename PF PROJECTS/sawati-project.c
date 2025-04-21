#include <stdio.h>
#include <string.h>
#include <unistd.h>

struct Candidate 
{
    int id;
    char name[50];
    int votes;
};

struct Voter 
{
    int id;
    char name[50];
    int age;
    char sex[10];
    char city[50];
    int hasVoted;
};

struct Election 
{
    struct Candidate candidates[4];
    struct Voter voters[100];
    int numVoters;
    int totalVotes;
};

struct Election election;

void initializeElection() 
{
    election.candidates[0].id = 1;
    strcpy(election.candidates[0].name, "PPP");
    election.candidates[0].votes = 0;

    election.candidates[1].id = 2;
    strcpy(election.candidates[1].name, "PTI");
    election.candidates[1].votes = 0;

    election.candidates[2].id = 3;
    strcpy(election.candidates[2].name, "PMLN");
    election.candidates[2].votes = 0;

    election.candidates[3].id = 4;
    strcpy(election.candidates[3].name, "JUI");
    election.candidates[3].votes = 0;

    election.numVoters = 0;
    election.totalVotes = 0;
}

void addVoter() 
{
    system("cls");
    if (election.numVoters > 100) 
    {
        printf("Max voters reached.\n");
        return;
    }

    struct Voter voter;
    voter.id = election.numVoters + 1;

    printf("Enter name for voter %d: ", voter.id);
    scanf("%s", voter.name);
    
    printf("Age: ");
    scanf("%d", &voter.age);
    if (voter.age < 18) 
    {
        printf("Voter must be at least 18 years old.\n");
        return;
    }

    printf("City: ");
    scanf("%s", voter.city);

    int sexChoice;
    do 
    {
        printf("Sex (1 for Male, 2 for Female): ");
        scanf("%d", &sexChoice);
        if (sexChoice == 1) 
        {
            strcpy(voter.sex, "Male");
        } 
        else if (sexChoice == 2) 
        {
            strcpy(voter.sex, "Female");
        } 
        else 
        {
            printf("Invalid choice. Please enter 1 for Male or 2 for Female.\n");
        }
    } while (sexChoice != 1 && sexChoice != 2);

    voter.hasVoted = 0;

    election.voters[election.numVoters] = voter;
    election.numVoters++;
}

void modifyVoterInfo() 
{
    system("cls");
    int voterId;
    printf("Enter voter ID to modify: ");
    scanf("%d", &voterId);

    if (voterId < 1 || voterId > election.numVoters) 
    {
        printf("Invalid voter ID.\n");
        return;
    }

    int index = voterId - 1;
    
    printf("Modify name for voter %d (current: %s): ", election.voters[index].id, election.voters[index].name);
    scanf("%s", election.voters[index].name);
    printf("Modify age (current: %d): ", election.voters[index].age);
    scanf("%d", &election.voters[index].age);
    printf("Modify city (current: %s): ", election.voters[index].city);
    scanf("%s", election.voters[index].city);

    int sexChoice;
    do 
    {
        printf("Modify sex (current: %s, 1 for Male, 2 for Female): ", election.voters[index].sex);
        scanf("%d", &sexChoice);
        if (sexChoice == 1) 
        {
            strcpy(election.voters[index].sex, "Male");
        } 
        else if (sexChoice == 2) 
        {
            strcpy(election.voters[index].sex, "Female");
        } 
        else 
        {
            printf("Invalid choice. Please enter 1 for Male or 2 for Female.\n");
        }
    } while (sexChoice != 1 && sexChoice != 2);

    printf("Voter information updated.\n");
}

void castVote() 
{
    system("cls");
    int voterId, candidateId;

    printf("Enter your voter ID: ");
    scanf("%d", &voterId);

    if (voterId < 1 || voterId > election.numVoters || election.voters[voterId - 1].hasVoted) 
    {
        printf("Invalid or already used voter ID.\n");
        return;
    }

    printf("\n\n ### Please choose your Candidate ####\n\n");
    for (int i = 0; i < 4; i++) 
    {
        printf("\n %d. %s", election.candidates[i].id, election.candidates[i].name);
    }
    printf("\n 5. %s", "None of These");

    printf("\n\n Input your choice (1 - 5) : ");
    scanf("%d", &candidateId);

    switch (candidateId) 
    {
        case 1: election.candidates[0].votes++; break;
        case 2: election.candidates[1].votes++; break;
        case 3: election.candidates[2].votes++; break;
        case 4: election.candidates[3].votes++; break;
        case 5: election.totalVotes++; break;
        default: printf("\n Error: Wrong Choice !! Please retry\n"); return;
    }

    election.voters[voterId - 1].hasVoted = 1;
    election.totalVotes++;
    printf("\nThanks for voting!\n");
}

void deleteVote() 
{
    system("cls");
    int voterId;
    printf("Enter voter ID to delete vote: ");
    scanf("%d", &voterId);

    if (voterId < 1 || voterId > election.numVoters || !election.voters[voterId - 1].hasVoted) 
    {
        printf("Invalid or not used voter ID.\n");
        return;
    }

    int candidateId;
    printf("Enter the candidate ID for whom the vote is to be deleted: ");
    scanf("%d", &candidateId);

    if (candidateId < 1 || candidateId > 4) 
    {
        printf("Invalid candidate ID.\n");
        return;
    }

    election.candidates[candidateId - 1].votes--;
    election.voters[voterId - 1].hasVoted = 0;
    election.totalVotes--;
    printf("Vote deleted successfully.\n");
}

void votesCount() 
{
    system("cls");
    printf("\n\n ##### Voting Statistics ####\n");
    for (int i = 0; i < 4; i++) 
    {
        printf("\n %s - %d ", election.candidates[i].name, election.candidates[i].votes);
    }
    printf("\n Spoiled Votes - %d \n", election.totalVotes);
}

void getLeadingCandidate() 
{
    system("cls");
    printf("\n\n  #### Leading Candidate ####\n\n");
    int maxVotes = 0;
    int leadingCandidate = -1;
    int tie = 0;

    for (int i = 0; i < 4; i++) 
    {
        if (election.candidates[i].votes > maxVotes) 
        {
            maxVotes = election.candidates[i].votes;
            leadingCandidate = i;
            tie = 0;
        } 
        else if (election.candidates[i].votes == maxVotes) 
        {
            tie = 1;
        }
    }

    if (leadingCandidate != -1) 
    {
        if (tie) 
        {
            printf("There is a tie between candidates with %d votes each.\n", maxVotes);
        } 
        else 
        {
            printf("Leading Candidate: %s with %d votes\n", election.candidates[leadingCandidate].name, election.candidates[leadingCandidate].votes);
        }
    } 
    else 
    {
        printf("----- Warning !!! No-win situation ----\n");
    }
}

void findVoterInfo() 
{
    system("cls");
    int voterId;
    printf("Enter voter ID to find information: ");
    scanf("%d", &voterId);

    if (voterId < 1 || voterId > election.numVoters) 
    {
        printf("Invalid voter ID.\n");
    } 
    else 
    {
        struct Voter voter = election.voters[voterId - 1];
        printf("\nVoter ID: %d\n", voter.id);
        printf("Name: %s\n", voter.name);
        printf("Age: %d\n", voter.age);
        printf("City: %s\n", voter.city);
        printf("Sex: %s\n", voter.sex);
        printf("Has Voted: %s\n", voter.hasVoted ? "Yes" : "No");
    }
}

void displayCandidates() 
{
    system("cls");
    printf("\n\n ##### Candidate Information ####\n");
    for (int i = 0; i < 4; i++) 
    {
        printf("\n Candidate ID: %d\n", election.candidates[i].id);
        printf("Name: %s\n", election.candidates[i].name);
        printf("Votes: %d\n", election.candidates[i].votes);
    }
}

void displayVoters() 
{
    system("cls");
    printf("\n\n ##### Voter Information ####\n");
    for (int i = 0; i < election.numVoters; i++) 
    {
        printf("\n Voter ID: %d\n", election.voters[i].id);
        printf("Name: %s\n", election.voters[i].name);
        printf("Age: %d\n", election.voters[i].age);
        printf("City: %s\n", election.voters[i].city);
        printf("Sex: %s\n", election.voters[i].sex);
        printf("Has Voted: %s\n", election.voters[i].hasVoted ? "Yes" : "No");
    }
}

void deleteVoter() 
{
    system("cls");
    int voterId;
    printf("Enter voter ID to delete: ");
    scanf("%d", &voterId);

    if (voterId < 1 || voterId > election.numVoters) 
    {
        printf("Invalid voter ID.\n");
        return;
    }

    for (int i = voterId - 1; i < election.numVoters - 1; i++) 
    {
        election.voters[i] = election.voters[i + 1];
        election.voters[i].id--;
    }

    election.numVoters--;
    printf("Voter ID %d has been deleted.\n", voterId);
}

void saveElectionData() 
{
    FILE *file = fopen("election_data.txt", "w");
    if (file == NULL) 
    {
        printf("Unable to open file for writing.\n");
        return;
    }

    // Write candidate data
    for (int i = 0; i < 4; i++) 
    {
        fprintf(file, "%d %s %d\n", election.candidates[i].id, election.candidates[i].name, election.candidates[i].votes);
    }

    // Write voter data
    for (int i = 0; i < election.numVoters; i++) 
    {
        fprintf(file, "%d %s %d %s %s %d\n", election.voters[i].id, election.voters[i].name, election.voters[i].age, election.voters[i].sex, election.voters[i].city, election.voters[i].hasVoted);
    }

    fclose(file);
    printf("Election data saved successfully.\n");
}

// Function to load election data from file
void loadElectionData() 
{
    FILE *file = fopen("election_data.txt", "r");
    if (file == NULL) 
    {
        printf("Unable to open file for reading.\n");
        return;
    }

    // Read candidate data
    for (int i = 0; i < 4; i++) 
    {
        fscanf(file, "%d %s %d", &election.candidates[i].id, election.candidates[i].name, &election.candidates[i].votes);
    }

    // Read voter data
    election.numVoters = 0;
    while (fscanf(file, "%d %s %d %s %s %d", &election.voters[election.numVoters].id, election.voters[election.numVoters].name, &election.voters[election.numVoters].age, election.voters[election.numVoters].sex, election.voters[election.numVoters].city, &election.voters[election.numVoters].hasVoted) == 6) 
    {
        election.numVoters++;
    }

    fclose(file);
    printf("Election data loaded successfully.\n");
}

void manageData() 
{
    system("cls");
    int choice;
    do 
    {
        printf("\n\n ###### Manage Data #####\n");
        printf("\n 1. Add Voter");
        printf("\n 2. Modify Voter Information");
        printf("\n 3. Cast the Vote");
        printf("\n 4. Delete Voter");
        printf("\n 5. Delete a Vote");
        printf("\n 6. Save Data");
        printf("\n 7. Load Data");
        printf("\n 0. Back to Main Menu");

        printf("\n\n Please enter your choice : ");
        scanf("%d", &choice);

        switch (choice) 
        {
            case 1: addVoter(); break;
            case 2: modifyVoterInfo(); break;
            case 3: castVote(); break;
            case 4: deleteVoter(); break;
            case 5: deleteVote(); break;
            case 6: saveElectionData(); break;
            case 7: loadElectionData(); break;
            case 0: system("cls"); break;
            default: printf("\n Error: Invalid Choice\n");
        }
    } while (choice != 0);
}

void search() 
{
    system("cls");
    int choice;
    do 
    {
        printf("\n\n ###### Search #####\n");
        printf("\n 1. Find Voter Information");
        printf("\n 2. Find Vote Count");
        printf("\n 3. Find Leading Candidate");
        printf("\n 0. Back to Main Menu");

        printf("\n\n Please enter your choice : ");
        scanf("%d", &choice);

        switch (choice) 
        {
            case 1: findVoterInfo(); break;
            case 2: votesCount(); break;
            case 3: getLeadingCandidate(); break;
            case 0: system("cls"); break;
            default: printf("\n Error: Invalid Choice\n");
        }
    } while (choice != 0);
}

void reports() 
{
    system("cls");
    int choice;
    do 
    {
        printf("\n\n ###### Reports #####\n");
        printf("\n 1. Display All Candidates");
        printf("\n 2. Display All Voters");
        printf("\n 0. Back to Main Menu");

        printf("\n\n Please enter your choice : ");
        scanf("%d", &choice);

        switch (choice) 
        {
            case 1: displayCandidates(); break;
            case 2: displayVoters(); break;
            case 0: system("cls"); break;
            default: printf("\n Error: Invalid Choice\n");
        }
    } while (choice != 0);
}

int main() 
{
    int choice;

    initializeElection();

    do 
    {
        printf("-------------------------------------------------");
        printf("\n------- Welcome to Election/Voting System -------\n");
        printf("-------------------------------------------------");
        printf("\n 1. Manage Data");
        printf("\n 2. Search");
        printf("\n 3. Reports");
        printf("\n 0. Exit");

        printf("\n\n Please enter your choice : ");
        scanf("%d", &choice);

        switch (choice) 
        {
            case 1: manageData(); break;
            case 2: search(); break;
            case 3: reports(); break;
            case 0: break;
            default: printf("\n Error: Invalid Choice\n");
        }
    } while (choice != 0);

    return 0;
}