#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *prev;
	struct node *next;
};

void display(struct node *p);
void insert_front(struct node **p, int x);
void insert_end(struct node **p, int x);
void del_front(struct node **p);
void del_end(struct node **p);
void pos_ins(struct node **p, int x, int pos);
void pos_del(struct node **p, int pos);
void key_del(struct node **p, int key);
void rev(struct node **p);
int numofnode(struct node **p);
void alt_1(struct node **p);
void alt_2(struct node **p);
int main()
{
      int ch, x, pos, key;
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
	     printf("6:Delete a node from a position in the list\n");
		 printf("7:Delete a node based on key data in the list\n");
	     printf("8:Reverse the given list\n");
	     printf("9:Alternative value from the first value\n");
	     printf("10:Alternative value from the second value\n");
             printf("11:Count the number of nodes\n");
		 printf("Enter your choice : ");
         scanf("%d", &ch);
         switch(ch)
         { case 1: printf("Enter the value\n");
                scanf("%d",&x);
                insert_front(&first,  x);
             break;
           case 2: printf("Enter the value : ");
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
           case 7: printf("Enter the key\n");
                scanf("%d",&key);
                key_del(&first,  key);				
             break;			 
           case 8: rev(&first);
             break;	
           case 9: alt_1(&first);
             break;		
           case 10: alt_2(&first);
		     break;    
           case 11:numofnode(&first);
                     break;                          
           case 12: exit(0);
         } 
	  }
     
}

void display(struct node *p)
{
    if(p==NULL) //why can't we use "if(*p==NULL)" here
            printf("List is empty\n");
    else
        { 
	      printf("\nlist is : ");
          while(p!=NULL)
           {
              printf("%d <-> ",p->data);
              p=p->next;
           }
        }

}

void insert_front(struct node **p, int x)
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

void insert_end(struct node **p, int x)
{
	struct node *temp, *pres;
	temp=(struct node *) malloc(sizeof(struct node));
	temp->data=x;
	temp->next=temp->prev=NULL;
	pres=*p;
	if(pres==NULL)
		*p=temp;
	else
	{
		while(pres->next!=NULL)
		   pres=pres->next;
	   
	    pres->next=temp;
		temp->prev=pres;
	}
}

void del_front(struct node **p)
{
	struct node *pres;
	pres=*p;
	if(pres==NULL)
		printf("List is empty\n");
	else if(pres->next==NULL && pres->prev==NULL)
	{
		*p=NULL;
		free(pres);
	}
	else
	{
		(*p)=(*p)->next;
		(*p)->prev=NULL;
		free(pres);
	}
}

void del_end(struct node **p)
{
	struct node *pres, *last;
	pres=*p;
	last=NULL;
	while(pres->next!=NULL)
	{	
	    last=pres;
		pres=pres->next;
	}	
	if(pres==NULL)
		printf("List is empty");
	else if(pres->next==NULL && pres->prev==NULL)
	{	
	     *p=NULL;
	     free(pres);
	}
    else
	{
		last->next=NULL;
		pres->prev=NULL;
		free(pres);
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
	while(pres!=NULL && i<pos)
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
        else if(pos>i)
       {
         printf("Invalid pos\n");
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
   printf("\nNumber of node = %d\n\n",i);
}

void rev(struct node **p)
{
	struct node *pres, *last, *temp;
	pres=*p;
	last=NULL;
	int x, i=1;
	while(pres!=NULL)
	{  
           temp=pres->next;
	   pres->prev=temp;
	   pres->next=last;
	   last=pres;
	   pres=temp;
	}
        *p=last;
}

void alt_1(struct node **p)
{
	struct node *pres, *last;
	pres=*p;
	last=NULL;
	while(pres!=NULL)
	{
		printf("%d ", pres->data);
		pres=pres->next->next;
	}
}

void alt_2(struct node **p)
{
	struct node *pres, *last;
	pres=*p;
	last=NULL;
	while(pres->next!=NULL)
	{
		printf("%d ", pres->next->data);
		pres=pres->next->next;
	}
}