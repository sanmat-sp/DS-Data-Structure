#include<string.h>
#include<stdio.h>
#include<ctype.h>
int findSubString(char* mainString,char* subString,int mainLength,int subLength,int position,int subPosition)
{
	
	if(position >= mainLength || subPosition >= subLength)
	{
		return 1;
	}

	
	if(isspace(subString[subPosition]))
	{
		return 1;
	}

	
	if(mainString[position] == subString[subPosition])
	{
		return findSubString(mainString,subString,mainLength,subLength,position + 1,subPosition + 1);
	}

	
	return 0;
}



int main()
{
	
	char mainString[100];
	char subString[100];


	int mainLength;
	int subLength;
	int i;


	int found = 0;


	printf("Enter main string : ");
	fgets(mainString, 100, stdin); 


	printf("Enter sub string : ");
	fgets(subString, 100, stdin);


	mainLength = strlen(mainString);
	subLength = strlen(subString);

	for(i = 0; i < mainLength - 1 ; i++)
	{
		if(mainString[i] ==  subString[0])
		{
			
			if(findSubString(mainString,subString,mainLength,subLength,i,0))
			{
				printf("Input substring is found on position %d ",i+1);
				found = 1;
				break;
			}
		}
	}

	
	if(found == 0)
	{
		printf("Input substring is not found in the string...");
	}
}





















