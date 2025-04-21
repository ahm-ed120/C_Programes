
#include <stdio.h>
#include <string.h>

int main()
{
    char txt[100], originalText[100];
    int key = 2, k, choice;
    char outputOption;

    printf("********************************************\n");
    printf("*             Caesar Cipher Program        *\n");
    printf("********************************************\n");

    printf("Do you want to input text manually or from a file? (M/F): ");
    char inputOption;
    scanf(" %c", &inputOption);

    if (inputOption == 'M' || inputOption == 'm')
    {
        // Input text manually
        printf("Enter the text \n");
        getchar(); // Consume the newline character left in the buffer
        fgets(txt, sizeof(txt), stdin);
    }
    else if (inputOption == 'F' || inputOption == 'f')
    {
        // Input from file
        FILE *inputFile;
        char inputFileName[50];

        printf("Enter the input file name: ");
        scanf("%s", inputFileName);

        inputFile = fopen(inputFileName, "r");
        if (inputFile == NULL)
        {
            printf("Error opening input file.\n");
            return 1;
        }

        // Read content from the file
        fgets(txt, sizeof(txt), inputFile);
        fclose(inputFile);
    }
    else
    {
        printf("Invalid option. Exiting program.\n");
        return 1;
    }

    // Backup the original text for brute force decryption
    strcpy(originalText, txt);

    printf("Text: %s\n", txt);

    // Prompt the user to enter the encryption/decryption key
    printf("Enter the Key: ");
    scanf("%d", &k);

    // Key adjustments
    if (k > 26 && k % 26 != 0)
    {
        key = k % 26;
    }
    else if (k % 26 == 0)
    {
        key = k / 26;
    }
    // else, key remains unchanged

    // Display the menu for the user to choose between encryption, decryption, or brute force
    printf("Choose operation:\n");
    printf("1. Encrypt\n");
    printf("2. Decrypt\n");
    printf("3. Brute Force Decryption\n");
    printf("Enter your choice (1, 2, or 3): ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        // Encryption logic (unchanged)
        for (int i = 0; txt[i]; i++)
        {
            if (txt[i] == ' ')
            {
                continue;
            }
            else if (txt[i] >= 'a' && txt[i] <= 'z')
            {
                if (txt[i] + key > 'z')
                {
                    txt[i] = txt[i] + key - 26;
                }
                else
                    txt[i] = txt[i] + key;
            }
            else if (txt[i] >= 'A' && txt[i] <= 'Z')
            {
                if (txt[i] + key > 'Z')
                {
                    txt[i] = txt[i] + key - 26;
                }
                else
                    txt[i] = txt[i] + key;
            }
            else if (txt[i] >= '0' && txt[i] <= '9')
            {
                // Key adjustments for digits
                int tempKey = key % 10;
                if (txt[i] + tempKey > '9')
                {
                    txt[i] = txt[i] + tempKey - 10;
                }
                else
                    txt[i] = txt[i] + tempKey;
            }
        }

        printf("Encrypted text is: %s", txt);

        // Prompt the user for the output option
        printf("\nDo you want to output the result as an encrypted text file? (Y/N): ");
        scanf(" %c", &outputOption);

        if (outputOption == 'Y' || outputOption == 'y')
        {
            FILE *outputFile;
            char outputFileName[50];

            printf("Enter the output file name: ");
            scanf("%s", outputFileName);

            outputFile = fopen(outputFileName, "w");
            if (outputFile == NULL)
            {
                printf("Error opening output file.\n");
                return 1;
            }

            // Write the encrypted text to the file
            fprintf(outputFile, "%s", txt);
            fclose(outputFile);

            printf("Encrypted text has been written to %s\n", outputFileName);
        }
        break;

    case 2:
        // Decryption logic 
        for (int i = 0; txt[i]; i++)
        {
            if (txt[i] == ' ')
                continue;
            else if (txt[i] >= 'a' && txt[i] < 'z')
            {
                if (txt[i] - key < 'a')
                {
                    txt[i] = txt[i] - key + 26;
                }
                else
                    txt[i] = txt[i] - key;
            }
            else if (txt[i] >= 'A' && txt[i] < 'Z')
            {
                if (txt[i] - key < 'A')
                {
                    txt[i] = txt[i] - key + 26;
                }
                else
                    txt[i] = txt[i] - key;
            }
            else if (txt[i] >= '0' && txt[i] <= '9')
            {
                // Key adjustments for digits during decryption
                int tempKey = key % 10;
                if (txt[i] - tempKey < '0')
                {
                    txt[i] = txt[i] - tempKey + 10;
                }
                else
                    txt[i] = txt[i] - tempKey;
            }
        }

        printf("\nThe Decrypted text is: %s", txt);

        // Prompt the user for the output option
        printf("\nDo you want to output the result as a decrypted text file? (Y/N): ");
        scanf(" %c", &outputOption);

        if (outputOption == 'Y' || outputOption == 'y')
        {
            FILE *outputFile;
            char outputFileName[50];

            printf("Enter the output file name: ");
            scanf("%s", outputFileName);

            outputFile = fopen(outputFileName, "w");
            if (outputFile == NULL)
            {
                printf("Error opening output file.\n");
                return 1;
            }

            // Write the decrypted text to the file
            fprintf(outputFile, "%s", txt);
            fclose(outputFile);

            printf("Decrypted text has been written to %s\n", outputFileName);
        }
        break;

    case 3:
        // Brute force decryption
        printf("\nBrute Force Decryption Results:\n");

        for (int bruteKey = 1; bruteKey <= 26; bruteKey++)
        {
            // Decryption logic with brute force
            for (int i = 0; originalText[i]; i++)
            {
                if (originalText[i] == ' ')
                    continue;
                else if (originalText[i] >= 'a' && originalText[i] < 'z')
                {
                    if (originalText[i] - bruteKey < 'a')
                    {
                        txt[i] = originalText[i] - bruteKey + 26;
                    }
                    else
                        txt[i] = originalText[i] - bruteKey;
                }
                else if (originalText[i] >= 'A' && originalText[i] < 'Z')
                {
                    if (originalText[i] - bruteKey < 'A')
                    {
                        txt[i] = originalText[i] - bruteKey + 26;
                    }
                    else
                        txt[i] = originalText[i] - bruteKey;
                }
                else if (originalText[i] >= '0' && originalText[i] <= '9')
                {
                    // Key adjustments for digits during brute force decryption
                    int tempKey = bruteKey % 10;
                    if (originalText[i] - tempKey < '0')
                    {
                        txt[i] = originalText[i] - tempKey + 10;
                    }
                    else
                        txt[i] = originalText[i] - tempKey;
                }
            }

            // Print the result for each brute force attempt
            printf("Key %d: %s\n", bruteKey, txt);
        }

        break;

    default:
        printf("Invalid choice!\n");
        return 1;
    }

    return 0;
}

