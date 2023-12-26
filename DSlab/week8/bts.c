#include<stdio.h>
#include<stdlib.h>
struct node
{
        int data;
        struct node *left;
        struct node *right; 
};


void subtree_del(struct node **t, int num);
void leaf_del(struct node **t, int num);
void inorder(struct node *t);
void insert(struct node **t, int x);
int main()
{
        struct node *root;
        root=NULL;  
        int ch, num;
        while(1)
        {       
                inorder(root);
                printf("\n1:Insert\n2:Leaf delete\n3:Sub tree delete\n4:Root delete\n");
                printf("Enter your choice : ");
                scanf("%d", &ch);
                switch(ch)
                {
                        case 1:printf("Enter the value : ");
                                scanf("%d", &num);
                                insert(&root, num);
                                break;
                        case 2:printf("Enter the num to be deleted : ");
                                scanf("%d", &num);
                                leaf_del(&root, num);
                                break;
                        case 3:printf("Enter the num to be deleted : ");
                                scanf("%d", &num);
						        subtree_del(&root, num);
                                break;
                      /*  case 4:root_del(t);
                                break;*/
                }
                
        }
}



void insert(struct node **t, int x)
{
        struct node *temp, *prev, *curr;
        temp=(struct node *)malloc(sizeof(struct node));
        temp->data=x;
        temp->right=temp->left=NULL;
        if(*t==NULL)
                *t=temp;
        else
        {
                prev=NULL;
                curr=*t;
                while(curr!=NULL)
                {
                        prev=curr;
                        if(x<curr->data)
                                curr=curr->left;
                        else
                                curr=curr->right;
                }
                if(x<prev->data)
                                prev->left=temp;
                else
                                prev->right=temp;
        }
}

/*

void rinsert(struct node **t, int num)
{
        if(*t==NULL)
        {
                struct node *temp;
                temp=(struct node *)malloc(sizeof(struct node));
                temp->data=num;
                temp->right=temp->left=NULL;
        }
        if(num<(*t)->data)
                (*t)->left=rinsert(t->left, num);
        else
                (*t)->right=rinsert(t->right, num);
}
*/


void inorder(struct node *t)
{
        if(t!=NULL)
        {
                inorder(t->left);
                printf("%d ", t->data);
                inorder(t->right);
        }
}

void leaf_del(struct node **t, int num)
{
        struct node *p, *q, *r, *l;
        p=*t;
        while(p->data!=num && p!=NULL)
        {
                q=p;
                if(num<p->data)
				{
                        p=p->left;
				}
                else if(num>p->data)
				{
                        p=p->right;
				}
        }
		l=q->left;
		r=q->right;
        if(p==NULL)
                printf("Number is not in the given tree\n");
		if(p->left==NULL && p->right==NULL)
		{
			if(l->data==num)
					q->left=NULL;
			else if(r->data==num)
					r=NULL;
		}
		else
			printf("Given number is not at leaf level\n");
}

void subtree_del(struct node **t, int num)
{
	struct node *p, *q, *l, *r;
	p=*t;
	while(p->data!=num && p!=NULL)
    {
                q=p;
                if(num<p->data)
				{
                        p=p->left;
				}
                else if(num>p->data)
				{
                        p=p->right;
						printf("sanmat");
				}
    }
	l=q->left;
	r=q->right;
    if(p==NULL)
            printf("Number is not in the given tree\n");
	if(p->left==NULL && p->right!=NULL)
	{
		if(l->data==num)
		{
			l=p->right;
		}
		else if(r->data==num)
		{
			r=p->right;
		}
	}
	if(p->left!=NULL && p->right==NULL)
	{
		if(l->data==num)
		{
			l=p->right;
		}
		else if(r->data==num)
		{
			r=p->right;
		}
	}
}