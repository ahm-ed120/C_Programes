#include<stdio.h>
#include<conio.h>
int main()
{
	
	char txt[100],ch;
	int k;
	
	printf("Enter the text \n");
	gets(txt);
	printf("Text: %s\n",txt);
	printf("Enter the Key: ");
	scanf("%d",&k);
	
	

	for(int i=0; txt[i]; i++){
		if(txt[i]==' '){
			continue;
		}
		else if(txt[i]>='a' && txt[i]<='z' ) //this is to check for lowercase letters.
		{
			txt[i] = (txt[i]-'a'+k)%26 +'a';
		}
		
		else if // this is to check for upper case letters.
		(txt[i]>='A' && txt[i]<='Z' ){
			txt [i]=(txt[i] -'A'+k)%26 +'A';
		}
		
		else if(txt[i]>='0'&&txt[i]<='9') // to check for digits.
		{
			
			txt[i]=(txt[i]-'0'+k )%10 + '0';
		}
		
	}
	printf("Encypted text is: %s",txt);
	
	
	
	
	
	
}
