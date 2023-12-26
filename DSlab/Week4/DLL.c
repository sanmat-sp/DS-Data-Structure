#include<stdio.h>
#include<stdlib.h>
struct node
{
   int data;
   struct node *prev;
   struct node *next;
};

void display(struct node *p);
void creat_list(struct node **p, int x);
void pos_ins(struct node **p, int x, int pos);
void pos_del(struct node **p, int pos);
void key_del(struct node **p, int key);
int numofnode(struct node **p);
int main()
{
      int ch, x, pos, key;
      struct node *first;
      first=NULL;
      while(1)
	  {
              display(first);
	      printf("\n1:Insert a node to the list\n");
          printf("2:Insert a node at a position in the list\n");
	      printf("3:Delete a node from a position the list\n");
	      printf("4:Delete nodes with data key\n");
	      printf("5:Count the number nodes\n");
	      printf("Enter your choice : ");
              scanf("%d", &ch);
                 switch(ch)
                 { 
                   case 1: printf("Enter the value\n");
                        scanf("%d",&x);
                        creat_list(&first,  x);
                     break;
                   case 2: printf("Enter the value and pos\n");
                        scanf("%d%d",&x,&pos);
                        pos_ins(&first, x, pos);
                     break;
                   case 3: printf("Enter the pos\n");
                           scanf("%d",&pos);
                           pos_del(&first, pos);
                     break;
                   case 4: printf("Enter the key\n");
                           scanf("%d",&key);
                           key_del(&first, key);
                     break;
                   case 5: numofnode(&first);
                     break;
                   case 10: exit(0);
                 } 
	  }
     
}

void display(struct node *p)
{
    if(p==NULL) //why can't we use "if(*p==NULL)" here
            printf("List is empty\n");
    else
        { 
	      printf("list is : ");
          while(p!=NULL)
           {
              printf("%d <-> ",p->data);
              p=p->next;
           }
        }

}

int numofnode(struct node **p)
{
   struct node *pres;
   pres=*p;
   int i=1;
   while(pres->next!=NULL)
   {
      pres=pres->next;
      i++;
   }
   printf("Number of node = %d\n\n",i);
}

void creat_list(struct node **p, int x)
{
	struct node *temp;
	temp=(struct node *) malloc(sizeof(struct node));
	temp->data=x;
	temp->next=temp->prev=NULL;
	if(*p==NULL)
		*p=temp;
	else
	{
		temp->next=(*p);
		(*p)->prev=temp;
		*p=temp;
	}
}

void pos_ins(struct node **p, int x, int pos)
{
	struct node *pres, *last, *temp;
	temp=(struct node *) malloc(sizeof(struct node));
	temp->data=x;
	temp->next=temp->prev=NULL;
	pres=*p;
	last=NULL;
	int i=1;
	while(pres->next!=NULL && i<pos)
	{
		last=pres;
		pres=pres->next;
		i++;
	}
	if(pres!=NULL)
	{
		if(last!=NULL)
		{
			last->next=temp;
			temp->prev=last;
			pres->prev=temp;
			temp->next=pres;
			
		}
		else
		{
			temp->next=pres;
			pres->prev=temp;
			*p=temp;
			
		}
	}
	else
	{
		if(i==pos)
		{	
			last->next=temp;
		    temp->prev=last;
			free(pres);
		}
        else
        {
			printf("Invalid pos\n");
		}			
	}	
}

void pos_del(struct node **p, int pos)
{
    struct node *pres, *last;
    last=NULL;
    pres=*p;
    int i=1;
    while(pres->next!=NULL && i<pos)
    {
       last=pres;
       pres=pres->next;
       i++;
    }
    if(p==NULL)
       printf("list is empty");
    else if(pres->next==NULL)
    {
       if(last==NULL)
       {
          *p=pres->next;
          pres->prev=NULL;
       }
       else
       {
          last->next=NULL;
          pres->prev=NULL;
          printf("deleted value is ");
       }
    }
    else 
    { 
       if(last==NULL)
       {
          *p=pres->next;
          pres->prev=NULL;
       }
       else
       {
           last->next=pres->next;
           pres->next->prev=last;
       }
    }
}

void key_del(struct node **p, int key)
{
    struct node *pres, *last;
    pres=*p;
    last=NULL;
    while(pres->next!=NULL)
    {
        while(pres->data!=key)
        {
          last=pres;
          pres=pres->next;
        }
        if(p==NULL)
            printf("list is empty");
        else if(pres->next==NULL)
        {
          if(last==NULL)
          {
             *p=pres->next;
             pres->prev=NULL;
          }
          else
          {
             last->next=NULL;
             pres->prev=NULL;
             printf("deleted value is %d\n", pres->data);
          }
        }
        else 
        { 
          if(last==NULL)
          {
             *p=pres->next;
             pres->next->prev=NULL;
			 pres->next=NULL;
          }
          else
          {
              last->next=pres->next;
              pres->next->prev=last;
          }
       }
      pres=pres->next;
    }
}

























