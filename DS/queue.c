//Normal queue
#include<stdio.h>
#include<stdlib.h>
int insert_rear(int *q, int *f, int *r, int size, int x);
int delete_front(int *q, int *f, int *r, int size);
void display(int *q, int f, int r, int size);
int main()
{
        int *q;
		
        int f, r, size, ch, k, x;
        f=-1;
        r=-1;
        printf("Enter the size of Q\n");
        scanf("%d", &size);
        q=(int *)malloc(size*(sizeof(int)));
        while(1)
        {
                display(q, f, r, size);
                printf("\n1:Insert rear\n");
                printf("2:Delete front\n");
                printf("Enter your choice");
                scanf("%d", &ch);
                switch(ch)
                {
                        case 1:printf("Enter the value of x\n");
                               scanf("%d", &x);
                               insert_rear(q, &f, &r, size, x);
                               break;
                        case 2:delete_front(q, &f, &r, size);
                               break;
                        case 3:exit(0);
                }
        }
}

int insert_rear(int *q, int *f, int *r, int size, int x)
{
    if(*r==size-1)
    {
        printf("Q is full\n");
        return -1;
    }
    (*r)++;
    q[*r]=x;
         if(*f==-1)
            *f=0;
    return 1;
}

int delete_front(int *q, int *f, int *r, int size)
{
        int x;
        if(*f==-1)
        {
                printf("Q is empty\n");
                return -1;
        }
        x=q[*f];
        if(*f==*r)
            *f=*r=-1;
        else
           (*f)++;
        return x;
}

void display(int *q, int f, int r, int size)
{
    int i;
    if(f==-1)
        printf("Q is empty\n");
    else
    {
        for(i=f; i<=r; i++)
        {
                printf("%d - ", q[i]);
        }
    }
}







//circular queue
//queue using linked list
struct node 
{
	int data;
	struct node *next;
};

void display(struct node *f, struct node *r);
void insert_rear(int x, struct node **f, struct node **r);
int delete_front(struct node **f, struct node **r);
int main()
{
	struct node *f, *r;
	int ch, x, k;
	f=NULL;
	r=NULL;
	while(1)
	{
		display(f, r);
		printf("\n1:Insert rear\n2:Delete front\n");
		printf("Enter your choice : ");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1:printf("Enter the value : \n");
			       scanf("%d", &x);
				   insert_rear(x, &f, &r);
				   break;
		    case 2:delete_front(&f, &r);
			       break;
		}
	}
}

void insert_rear(int x, struct node **f, struct node **r)
{
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=x;
	temp->next=temp;
	if(*f==NULL)
		*f=*r=temp;
	else
	{
		(*r)->next=temp;
		temp->next=*f;
		*r=temp;
	}
}

void display(struct node *f, struct node *r)
{
	if(f==NULL)
		printf("List is empty\n");
	else
	{
		while(f!=r)
		{
			printf("%d - ", f->data);
			f=f->next;
		}
		printf("%d", f->data);
		printf("\n%d", r);
		printf("\n%d", f);
	}
	
}

int delete_front(struct node **f, struct node **r)
{
	struct node *q;
	int x;
	q=*f;
	if(q==NULL)
		printf("List is empty\n");
	else
	{
		x=q->data;
		if(*f==*r)
			*f=*r=NULL;
		(*f)=q->next;
	}
	free(q);
	return x;
}









//priority queue
struct pqueue
{
	int pty;
	int data;
};

void pqinsert(int pty, int x, struct pqueue *pq, int *count);
void display(struct pqueue *pq, int count);
struct pqueue pqdelete(struct pqueue *pq, int *count);
int main()
{
	struct pqueue pq[100];
	struct pqueue temp;
	int count=0;
	int ch, x, pty;
	while(1)
	{
		display(pq, count);
		printf("\n1:Insert\n2:Delte\n");
		printf("Enter your choice\n");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1:printf("Enter the priority : \n");
				   scanf("%d", &pty);
				   printf("Enter the value : \n");
				   scanf("%d", &x);
				   pqinsert(pty, x, pq, &count);
				   break;
			case 2:temp=pqdelete(pq, &count);
			        break;
		}
	}
}

void pqinsert(int pty, int x, struct pqueue *pq, int *count)
{
	struct pqueue temp;
	temp.pty=pty;
	temp.data=x;
	int j;
	j=(*count)-1;
	while((j>=0) && (pq[j].pty>temp.pty))
	{
		pq[j+1]=pq[j];
		j--;
	}
	pq[j+1]=temp;
	(*count)++;
}

void display(struct pqueue *pq, int count)
{
	int i;
	if(count==0)
	{
		printf("List is empty\n");
	}
	else
	{
		for(i=0;i<count;i++)
		{
			printf("Data: %d ", pq[i].data);
			printf("Priority: %d", pq[i].pty);
			printf("\n");
		}
	}
}

struct pqueue pqdelete(struct pqueue *pq, int *count)
{
	int j;
	struct pqueue temp;
	if(*count==0)
	{
		printf("Queue is empty\n");
		temp.pty=0;
		temp.data=-1;
	}
	else
	{
		temp=pq[0];
		for(j=1;j<*count;j++)
			pq[j-1]=pq[j];
		(*count)--;
	}
	return temp;
}



