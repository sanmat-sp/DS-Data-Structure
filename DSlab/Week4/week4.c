#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node
{
        int data;
        struct node *next, *prev;
};

void insert_front(struct node **p, int x);
void display(struct node* node);
int countNodes(struct node *p);
void del_key(struct node **p,int pos);
int del_value(struct node **p,int x);
void insert_pos(struct node **p, int x, int pos);

int main()
{
        struct node *first = NULL;
        int x, ch, pos;
        while(1)
        {
                display(first);
                printf("\n1. Insert node from front.");
                printf("\n2. Number of nodes.");
                printf("\n3. insert based on position.");
                printf("\n4. delete based on position.");
                printf("\n5. delete based on value.");
                printf("\nEnter choice : ");
                scanf("%d", &ch);
                switch(ch)
                {
                        case 1 : printf("\nEnter value : ");
                        scanf("%d", &x);
                        insert_front(&first, x);
                        break;
                        
                        case 2 : printf("\nThere are %d nodes\n\n",countNodes(first));
                        break;
                        
                        case 3 : printf("\nEnter value : ");
                        scanf("%d", &x);
                        printf("\nEnter position : ");
                        scanf("%d", &pos);
                        insert_pos(&first, x, pos);
                        break;
                        case 4 : printf("Enter position to delete:");
		        scanf("%d", &pos);
		        del_key(&first, pos);
		        break;
		        
		        case 5 : printf("Enter value to delete:");
		        scanf("%d",&x);
		        del_value(&first, x);
		        break;
                        
                        default : break;
                        
                }
        }
}

void insert_front(struct node **p, int x)
{
        struct node *temp;
        temp = (struct node*)malloc(sizeof(struct node));
        temp -> data = x;
        temp -> next = NULL;
        temp -> prev = NULL;
        
        if(*p == NULL)
                *p = temp;
        else
        {
                temp -> next = *p;
                (*p) -> prev = temp;
                *p = temp;
        }
}



void display(struct node* node)
{
    struct node* last;
    if (node == NULL)
        printf("\nEmpty \n");
    else 
    {
        while (node != NULL) 
        {
                printf("%d <->", node->data);
                last = node;
                node = node->next;
        }
    }
}

int countNodes(struct node *p)
{
        int count = 0;
         while(p!=NULL)
         {
                count++;
                p = p -> next;
         }
         return count;
}

void insert_pos(struct node **p, int x, int pos)
{
        struct node *temp, *pres;
        temp = (struct node*) malloc (sizeof(struct node));
        temp -> data = x;
        temp -> prev = temp -> next = NULL;
        int i = 1;
        pres = *p;
        
        if (*p == NULL && pos == 1)
        {
                *p = temp;
        }        
        else
        {
                while(pres -> next != NULL && i < pos)
                {
                        pres = pres -> next;
                        i++;
                }
                if (pos == i)
                {
                        if(pres -> prev == NULL)
                        {
                                temp -> next = pres;
                                pres -> prev = temp;
                                *p = temp;
                        }
                        else 
                        {
                                pres -> prev -> next = temp;
                                temp -> prev = pres -> prev;
                                temp -> next = pres;
                                pres -> prev = temp;
                        }
                }
                else if(pos == i + 1)
                {
                        pres -> next = temp;
                        temp -> prev = pres;
                }
                else
                {
                        printf("\nInvalid position\n");
                }
        }
        
   
        
}
  
void del_key(struct node **p,int pos)
{
	if(*p==NULL) 
	        printf("Empty\n");
	struct node *prev1=NULL,*pres=*p;
	int i=1;
	while(pres->next!=NULL && i!=pos)
	{	
		prev1=pres;
		pres=pres->next;
		i++;
	}
	if (i==pos)
	{
		if(prev1!=NULL && pres->next==NULL)
		{
			prev1->next=NULL;
			free(pres);
		}
		else if(prev1==NULL && pres->next!=NULL)
		{
			*p=pres->next;
			pres=pres->next;
			pres->prev=NULL;
			free(prev1);
		}
		else if(prev1==NULL && pres->next==NULL)
		{
			*p=NULL;
			free(pres);
			printf("\nEmpty\n");
			}
		else
		{
			prev1->next=pres->next;
			pres->next->prev=prev1;
			free(pres);
		}
	}
	else printf("\nInvalid position\n");
}      
    
int del_value(struct node **p,int x)
{
	struct node *temp=(struct node *)malloc(sizeof(struct node));
	temp->data=x;
	temp->prev=temp->next=NULL;
	struct node *prev1=NULL,*pres=*p;
	if(*p==NULL) 
	{
		printf("\nEmpty\n");
		return 0;
		}
	else{
		while(pres->next!=NULL && pres->data !=x)
		{
			prev1=pres;
			pres=pres->next;
		}
		if (pres->data==x)
		{
			if(prev1!=NULL && pres->next==NULL)
			{
				prev1->next=NULL;
				free(pres);
			}
			else if(prev1==NULL && pres->next!=NULL)
			{
				*p=pres->next;
				pres=pres->next;
				pres->prev=NULL;
				free(prev1);
			}
			else if(prev1==NULL && pres->next==NULL)
			{
				*p=NULL;
				free(pres);
				//printf("\nEmpty\n");
				}
			else
			{
				prev1->next=pres->next;
				pres->next->prev=prev1;
				free(pres);
			}
		return 1;
		}
		else 
		{
			printf("\nNot found\n");
			return 0;
		}
		}
}    
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        






































