//Binary tree search(BTS) uring array
#include<stdio.h>
#include<stdlib.h>
/*
void insert(int *t, int key);
void preorder(int *t, int x);
void inorder(int *t, int x);
void postorder(int *t, int x);
int max(int *t);
int min(int *t);
int main()
{
	int t[100];
	int i, ch, num, k;
	for(i=0;i<100;i++)
		t[i]=-1;
	while(1)
	{
		printf("\n1:Insert\n2:Preorder\n3:Inorder\n4:Postorder\n5:Max term\n6:Min term\n");
		printf("Enter your choice\n");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1:printf("Enter the value : \n");
				scanf("%d", &num);
				insert(t, num);
				break;
			case 2:preorder(t, 0);
				break;
			case 3:inorder(t, 0);
				break;
			case 4:postorder(t, 0);
				break;
			case 5:k=max(t);
				printf("Max term is %d\n", k);
				break;
			case 6:k=min(t);
				printf("Min term is %d\n", k);
				break;
			case 10:exit(0);
		}
	}
}

void insert(int *t, int key)
{
	int i=0;
	while(t[i]!=-1)
	{
		if(key<t[i])
			i=2*i+1;
		else
			i=2*i+2;
	}
	t[i]=key;
}

void preorder(int *t, int i)
{
	if(t[i]!=-1)
	{
		printf("%d ", t[i]);
		preorder(t, 2*i+1);
		preorder(t, 2*i+2);
	}
	else
		printf("Array is empty");
}

void inorder(int *t, int i)
{
	if(t[i]!=-1)
	{
		inorder(t, 2*i+1);
		printf("%d ", t[i]);
		inorder(t, 2*i+2);
	}
	else
		printf("Array is empty");
}

void postorder(int *t, int i)
{
	if(t[i]!=-1)
	{
		postorder(t, 2*i+1);
		postorder(t, 2*i+2);
		printf("%d ", t[i]);
	}
	else
		printf("Array is empty");
}

int max(int *t)
{
	int i=0;
	while(t[2*i+2]!=-1)
		i=2*i+2;
	return t[i];
}

int min(int *t)
{
	int i=0;
	while(t[2*i+1]!=-1)
		i=2*i+1;
	return t[i];
}

*/


//BTS using linked list
struct node
{
	int data;
	struct node *left;
	struct node *right;
};

void rinsert(struct node **t, int num);
void preorder(struct node *t);
void inorder(struct node *t);
void postorder(struct node *t);
int main()
{
	struct node *root;
	root=NULL;
	int ch, num;
	while(1)
	{
		printf("\n1:Insert\n2:Preorder\n3:Inorder\n4:Postorder\n");
		printf("Enter your choice : \n");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1:printf("Enter the value : \n");
				scanf("%d", &num);
				rinsert(&root, num);
				break;
		}
	}
}

void rinsert(struct node **t, int num)
{
	if(*t==NULL)
	{
		struct node *temp;
		temp=(struct node *)malloc(sizeof(struct node));
		temp->data=num;
		temp->left=temp->right=NULL;
	}
	if(num<(*t)->data)
		rinsert((t)->left, num);
	else
		rinsert((t)->right, num);
}

void preorder(struct node *t)
{
	if(t!=NULL)
	{
		printf("%d->", t->data);
		preorder(t->left);
		preorder(t->right);
	}
}

void inorder(struct node *t)
{
	if(t!=NULL)
	{
		inorder(t->left);
		printf("%d->", t->data);
		inorder(t->right);
	}
}

void postorder(struct node *t)
{
	if(t!=NULL)
	{
		postorder(t->left);
		postorder(t->right);
		printf("%d->", t->data);
	}
}