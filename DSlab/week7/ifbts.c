#include<stdio.h>
#include<stdlib.h>
void insert(int *t, int key);
void preorder(int *t, int i);
int ifBTS(int *t, int i);
int main()
{
	 int i, ch, num;
	 int t[100];
	 for(i=0;i<100;i++)
	  t[i]=-1;
	 while(1)
 {
	  printf("\n1:Insert\n2:Preorder\n3:Check for Binary search tree\n");
	  printf("Enter your choice : \n");
	  scanf("%d", &ch);
	  switch(ch)
	  {
		   case 1:printf("Enter the value : ");
			scanf("%d", &num);
			insert(t, num);
			break;
		   case 2:preorder(t,0);
			break;
		   case 3:if(ifBTS(t,0))
		   {
				printf("The above tree is a Binary search tree\n");
		   }
		   else
		   {
				printf("The given tree is not a Binary search tree\n");
		   }
				break;
	  }
 }
}

void insert(int *t, int key)
{
	 int i=0;
	 while(t[i]!=-1)
	  i++;
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
}

int ifBTS(int *t, int i)
{
	 if(t[i]!=-1)
	 {
		  if(t[i]<t[2*i+2] && t[i]>t[2*i+1])
		  {
			   ifBTS(t, 2*i+1);
			   ifBTS(t, 2*i+2);
			   return 1;
		  }
		  else
			return 0;
 }
 
}