#include<stdio.h>
#include<stdlib.h>
struct node 
{
	int data;
    struct node *next;	
};

void o_list(struct node **p, int x);
void display(struct node *p);
int main()
{
	struct node *first;
	first=NULL;
	int x;
	while(1)
	{
		printf("\nEnter the value for x : \n");
		scanf("%d", &x);
		o_list(&first, x);
		display(first);
	}
}

void o_list(struct node **p, int x)
{
	struct node *pres, *prev, *temp;
	temp=(struct node *) malloc(sizeof(struct node));
	temp->data=x;
	temp->next=NULL;
	prev=NULL;
	pres=*p;
	while(pres!=NULL && x>pres->data)
	{
	    prev=pres;
	    pres=pres->next;
    }		
	if(pres!=NULL)
	{
		if(prev==NULL)
		{
			temp->next=pres;
			*p=temp;
		}
		else
		{
			prev->next=temp;
			temp->next=pres;
		}
	}
	else
	{
		if(prev==NULL)
		{
			*p=temp;
		}
		else
		{
			prev->next=temp;
		}
	}
}

void display(struct node *p)
{
	printf("List is......\n");
	while(p!=NULL)
	{   
        printf("%d->", p->data);
	    p=p->next;
    }
}