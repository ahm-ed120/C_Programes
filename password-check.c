#include<stdio.h>
#include <string.h>
#include <ctype.h>
#include<conio.h>

void password_check(char password []);
int password_read(char password []);
int main ()
{
    char password [100];
    password_check(password);
    int sum =password_read(password);
    if(sum)
    {
        printf("your password is True\n");
    }
    else{
        printf("your password is not true \n");
    }
}

void password_check(char password[]){
    char ch;
    int i;
    printf ("Enter password\n");
    
    for ( i = 0 ; i< 20;i++)
    {
        ch = getch();

        password[i]=ch;

        if (ch!=13)
        {
            printf ("*");
        }
        else if (ch == 13)
        {
            break;
        }
    }
    password[i]='\0';
    printf ("\n");

    printf ("your password is : %s\n",password);
}

int password_read (char password[])
{
    int upper=0;
    int digit =0;
    int dollar=0;
    int i ;
    for (i = 0 ; i<strlen(password);i++ )
    {
        if (isupper(password[i])){
            upper=1;

        }
        else if(isdigit(password[i])){
            digit=1;
        }
        else if(password[i]=='$'){
            dollar=1;
        }
    }
    return (upper && digit && dollar);
}
