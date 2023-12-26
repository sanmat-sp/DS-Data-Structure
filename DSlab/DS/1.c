#include<stdio.h>
#include<stdlib.h>
struct node 
{
	int data;
	struct node *right;
	struct node *down;
	int x;
	int y;
};

int readmatrix(struct node **p, size_t rows, size_t cols, int (*a)[cols], const char* filename);
void display(struct node *p);
void path(struct node *p, int x, int y);
int main()
{
	struct node *p;
	p=NULL;
	int a[10];
	int x; 
	int y;
	readmatrix(&p, 10, 10, &a, "input.txt");
	display(p);
	printf("Enter the value of position x : ");
	scanf("%d", &x);
	printf("Enter the value of position y : ");
	scanf("%d", &y);
	path(p, x, y);
}

int readmatrix(struct node **p, size_t rows, size_t cols, int (*a)[cols], const char* filename)
{
    FILE *pf;
    pf = fopen (filename, "r");
    if (pf == NULL)
	{
        return 0;
	}
	size_t i=0;
	size_t j=0;
	struct node *temp, *left, *up, *first;
	up=NULL;
    while(i < rows)
    {
		j=0;
		left=NULL;
        while(j < cols)
        {
			fscanf(pf, "%d", a[i]+j);
			temp=(struct node *)malloc(sizeof(struct node));
			temp->right=temp->down=NULL;
			temp->data=a[i][j];
			temp->x=j;
			temp->y=i;
			if((*p)==NULL)
			{
				printf("%d %d\n", i, j);
				(*p)=temp;
				first=(*p);
				j++;
			}
			if(left==NULL && up==NULL)
			{
				(*p)->right=temp;
				left=temp;
				j++;
			}
			if(left==NULL && up!=NULL)
			{
				up->down=temp;
				left=temp;
				up=up->right;
				j++;
			}
			if(left!=NULL && up==NULL)
			{
				left->right=temp;
				left=temp;
				j++;
			}
			if(left!=NULL && up!=NULL)
			{
				up->down=temp;
				left->right=temp;
				left=left->right;
				up=up->right;
				j++;
			}
		}
		if(up==NULL && i==0)
		{
			//first=first->down;
			up=first;
			i++;
		}
		if(up==NULL && i!=0)
		{
			first=first->down;
			up=first;
			i++;
		}
    }


    fclose(pf); 
    return 0; 
}

void display(struct node *p)
{
	struct node *first, *curr;
	first=p;
	curr=p;
	while(first->down!=NULL)
	{
		while(curr->right!=NULL)
		{
			printf("%d ", curr->data);
			curr=curr->right;
		}
		first=first->down;
		curr=first->down;
		printf("\n");
	}
}

void path(struct node *p, int x, int y)
{
	struct node *temp;
	p=temp;
	while(temp->x!=x)
	{
		temp=temp->right;
		while(temp->y!=y)
		{
			temp=temp->down;
		}
	}
	if(temp->data==1)
	{
		printf("");
	}
}

