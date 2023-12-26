#include<stdio.h>
#include<stdlib.h>
void insert(char *t, char *SRN);
void sort(char *t, int i);
void search(char *t, char *SRN);
int main()
{
	int ch, i;
	char t[100];
	char SRN[10];
	for(i=0;i<100;i++)
		t[i]=-1;
	while(1)
	{
		printf("\n1:Insert\n2:Sort\n3:Search\n");
		printf("Enter your choice : \n");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1:printf("Enter the SRN : \n");
				scanf("%s", SRN);
				insert(t, SRN);
				break;
			case 2:sort(t, 0);
				break;
			case 3:printf("Enter the SRN you want : \n");
				scanf("%s", SRN);
				search(t, SRN);
				break;
		}
		
	}
}

void insert(char *t, char *SRN)
{
	int i=0;
	while(t[i]!=-1)
	{
		if(*SRN<t[i])
			i=2*i+1;
		else
			i=2*i+2;
	}
	t[i]=*SRN;
}

void sort(char *t, int i)
{
	if(t[i]!=-1)
	{
		sort(t, 2*i+1);
		printf("%c ", t[i]);
		sort(t, 2*i+2);
	}
}

void search(char *t, char *SRN)
{
	int i=0;
	while(t[i]!=*SRN)
		i++;
	printf("SRN = %c\n", *SRN);
	printf("Position = %d\n", i);
}