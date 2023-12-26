#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};

void display(struct node *p);
void insert_front(struct node **p, int x);
void insert_end(struct node **p, int x);
void del_front(struct node **p);
void del_end(struct node **p);
void pos_ins(struct node **p, int x, int pos);
void pos_del(struct node **p,int pos);
void rev(struct node **p);
void alt_1(struct node **p);
void alt_2(struct node **p);
int main()
{
      int ch, x, pos;
      struct node *first;
      first=NULL;
      while(1)
	  {
		 display(first);
	     printf("\n1:Insert a node from the front of the list\n");
         printf("2:Insert a node from the end of the list\n");
         printf("3:Delete a node from the front of the list\n");
         printf("4:Delete a node from the end of the list\n");
         printf("5:Insert a node at a position in the list\n");
	     printf("6:Delete a node from a position the list\n");
	     printf("7:Reverse the given list\n");
	     printf("8:Alternative value from the first value\n");
	     printf("9:Alternative value from the second value\n");
		 printf("Enter your choice : ");
         scanf("%d", &ch);
         switch(ch)
         { case 1: printf("Enter the value\n");
                scanf("%d",&x);
                insert_front(&first,  x);
             break;
           case 2: printf("Enter the value\n");
                scanf("%d",&x);
                insert_end(&first,  x);
             break;
           case 3: del_front(&first);
             break;
           case 4: del_end(&first);
             break;
           case 5: printf("Enter the value and pos\n");
                scanf("%d%d",&x,&pos);
                pos_ins(&first, x, pos);
             break;
		   case 6: printf("Enter the pos\n");
                scanf("%d",&pos);
                pos_del(&first,  pos);			
             break;	 
		   case 7: rev(&first);
             break;	
           case 8: alt_1(&first);
             break;		
		   case 9: alt_2(&first);
		     break;
           case 10: exit(0);
         } 
	  }
     
}

void display(struct node *p)
{
    if(p==NULL)
            printf("List is empty\n");
    else
        { printf("list is : ");
          while(p!=NULL)
           {
              printf("%d->",p->data);
              p=p->next;
           }
        }

}

void insert_front(struct node **p, int x)
{
    struct node *temp;
    temp=(struct node *)malloc(sizeof (struct node));
    temp->data=x;
    temp->next=NULL;
    if(*p==NULL)
          *p=temp;
    else 
	{
		temp->next=*p;
        *p=temp;      
	}
}

void insert_end(struct node **p, int x)
{
    struct node *temp,*q;
    temp=(struct node *)malloc(sizeof (struct node));
    temp->data=x;
    temp->next=NULL;
    if(*p==NULL)
          *p=temp;
    else
    {
        q=*p;
        while(q->next!=NULL)
        {
			q=q->next;
	    }
        q->next=temp;
    }
}

void del_front(struct node **p)
{
    struct node *pres;
    if (*p == NULL)
        printf("List is empty\n");
    else{ 
           pres=*p;
           *p=(*p)->next;
           printf("Deleted node value id %d\n: ", pres->data);  
           free(pres);		   
         }
}

void del_end(struct node **p)
{
	struct node *prev, *pres;
	pres = *p;
	prev = NULL;
    if(*p==NULL)
      printf("List is empty");
    else if((*p)->next==NULL)
	{
	    *p=NULL;
        printf("Deleted node value is %d\n",pres->data);
        free(pres);
	}		
	else
	{
		while(pres->next!=NULL)
			
		   {
			   prev = pres;
		       pres = pres->next;
		   }
		prev->next=NULL;
        printf("Deleted node value is %d\n",pres->next);
        free(pres);		
	}
}

void pos_ins(struct node **p, int x, int pos)
{
	struct node *pres, *temp, *prev;
        temp = (struct node*) malloc(sizeof (struct node));
	temp->data = x;
	temp->next = NULL;
	pres = *p;
	prev = NULL;
	int i=1;
	while(pres!=NULL && i<pos)
	{  
            prev = pres;
	    pres = pres->next;
		i++;
	}	
        if(pres!=NULL)
	{
		if(prev == NULL)
		{
			temp->next = pres;
			*p=temp;
		}
		else
		{
			prev->next = temp;
			temp->next = pres;
		}
	}
    else
	{
		if(pos==i)
		{
			if(prev==NULL)
			{
				temp->next=*p;
				*p=temp;
			}
			else
			{
				prev->next=temp;
			}
		}
		else
		{
			printf("Invalid pos\n");
		}
	}		
}

void pos_del(struct node **p, int pos)
{
	struct node *pres, *prev;
	pres=*p;
	prev=NULL;
	int i=1;
	while(pres!=NULL && i<pos)
        {
		prev=pres;
	    pres=pres->next;
		i++;
        }
	if(pres==NULL)
	  printf("Invalid pos\n");
    else if(prev==NULL)
	{
		*p=pres->next;
		printf("Deleted node value is %d\n",pres->data);
                
	}
	else
	{
		prev->next=pres->next;
		printf("Deleted node value is %d\n",pres->data);
		
	}
}    

void rev(struct node **p)
{
	struct node *pres, *prev, *temp;
	prev=NULL;
	pres=*p;
	while(pres!=NULL)
	{
		temp=pres->next;
		pres->next=prev;
		prev=pres;
		pres=temp;
	}
        *p=prev;
}


void alt_1(struct node **p)
{
	struct node *pres, *req, *temp;
	pres=*p;
	while(pres->next!=NULL || pres!=NULL)
	{   printf("%d", pres->data);
	    temp=pres->next;
		req=temp->next;
		pres=req;
	}	
}

void alt_2(struct node **p)
{
	struct node *pres, *req, *temp, *prev;
	pres=*p;
	while(pres->next!=NULL || pres||NULL)
	{
		req=pres->next;
		printf("%d",req->data);
		pres=req->next;
	}
}