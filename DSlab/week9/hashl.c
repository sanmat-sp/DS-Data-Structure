#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct element
{
	int ph_no;
	char name[10];
	int mark;
};

void insert(struct element *ht, int size, int ph_no, char *name, int *count);
int delete(struct element *ht, int size, int ph_no, int *count);
void display(struct element *ht, int size, int *count);
void search(struct element *ht, int size, int ph_no);
int main()
{
	struct element *ht;
	int ch, sz, i, num, no_elements;
	char name[10];
	printf("Enter the table size : ");
	scanf("%d", &sz);
	ht=(struct element *)malloc(sz*(sizeof(struct element)));
	for(i=0;i<sz;i++)
	{
		ht[i].mark=0;
	}
	no_elements=0;
	while(1)
        {
                printf("\n1:Insert a PHONE NUMBER\n2:Delete a PHONE NUMBER\n3:Search a PHONE NUMBER\n4:Display\n");
                printf("Enter your choice : ");
                scanf("%d", &ch);
                switch(ch)
                {
                        case 1: printf("Enter the PHONE NUMBER : ");
                                scanf("%d", &num);
                                printf("\nEnter the name : ");
                                scanf("%s", name);
                                insert(ht, sz, num, name, &no_elements);
                                break;
                        case 2: printf("Enter the PHONE NUMBER to be deleted : ");
                                scanf("%d", &num);
                                delete(ht, sz, num, &no_elements);
                                break;
                        case 3: printf("Enter the PHONE NUMBER to be searched : ");
                                scanf("%d", &num);
                                search(ht, sz, num);
                                break;
                        case 4: display(ht, sz, &no_elements);
                                break;  
                }
        }
}

void insert(struct element *ht, int size, int ph_no, char *name, int *count)
{
	int index;
	if(*count==size)
	{
		printf("Table is full\n");
	}
	index=ph_no%size;
	while(ht[index].mark==1)
	{
		index=(index+1)%size;
	}
	ht[index].ph_no=ph_no;
	strcpy(ht[index].name, name);
	ht[index].mark=1;
	(*count)++;
}

int delete(struct element *ht, int size, int ph_no, int *count)
{
	int index, i=0;
	if(*count==0)
		printf("Table is empty\n");
	index=ph_no%size;
	while(ht[index].ph_no!=ph_no && i<=*count)
	{
		index=(index+1)%size;
		i++;
	}
	if(ht[index].ph_no==ph_no)
	{
		ht[index].mark=0;
		(*count)--;
	}
	else
	{
		printf("Not found in the table\n");
	}
}

void display(struct element *ht, int size, int *count)
{
	int i, index;
	for(i=0;i<size;i++)
	{
		printf("\n%d : ", i);
		if(ht[i].mark!=0)
			printf("PHONE NUMBER - %d, NAME - %s, MARK - %d -> ", ht[i].ph_no, ht[i].name, ht[i].mark);
	}
	printf("\nNumber of elements : %d", *count);
}

void search(struct element *ht, int size, int ph_no)
{
        int index;
        index=ph_no%size;
        while(ht[index].ph_no!=ph_no)
                 index=(index+1)%size;
        if(ht[index].ph_no==ph_no)
        {
                printf("\nFound with\n");
                printf("PHONE NUMBER - %d, NAME - %s\n", ht[index].ph_no, ht[index].name);   
        }
        else
                printf("Record not found\n");
}